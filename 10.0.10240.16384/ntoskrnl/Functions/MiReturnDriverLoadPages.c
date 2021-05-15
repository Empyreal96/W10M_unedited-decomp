// MiReturnDriverLoadPages 
 
unsigned int __fastcall MiReturnDriverLoadPages(_DWORD *a1, unsigned int a2)
{
  _DWORD *v2; // r6
  unsigned int v3; // r9
  unsigned int v5; // r8
  int v6; // r2
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r4
  unsigned int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // r1
  int v15; // [sp+0h] [bp-C0h]
  int v16; // [sp+4h] [bp-BCh]
  int v17; // [sp+8h] [bp-B8h] BYREF
  char v18; // [sp+Ch] [bp-B4h]
  char v19; // [sp+Dh] [bp-B3h]
  int v20; // [sp+10h] [bp-B0h]
  int v21; // [sp+14h] [bp-ACh]
  int v22; // [sp+18h] [bp-A8h]
  int v23; // [sp+1Ch] [bp-A4h]

  v21 = 0;
  v22 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 33;
  v23 = 0;
  v2 = a1;
  v3 = (_DWORD)a1 << 10;
  v15 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v5 = 2336;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(dword_634F00);
  }
  else
  {
    do
      v8 = __ldrex((unsigned __int8 *)dword_634F00 + 3);
    while ( __strex(v8 | 0x80, (unsigned __int8 *)dword_634F00 + 3) );
    __dmb(0xBu);
    v5 = 0x920u;
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(dword_634F00);
    while ( 1 )
    {
      v9 = dword_634F00[0];
      if ( (dword_634F00[0] & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_634F00[0] & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(dword_634F00);
        while ( v10 == v9 && __strex(v9 | 0x40000000, dword_634F00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  for ( ; (unsigned int)v2 <= a2; v3 += 4096 )
  {
    if ( (*v2 & 2) != 0 )
    {
      v6 = MmPfnDatabase + 24 * (*v2 >> 12);
      v16 = v6;
      if ( (unsigned int)(v2 + 0x10000000) > 0x3FFFFF )
      {
        *v2 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v2 = 0;
        if ( (unsigned int)(v2 + 267649024) <= 0xFFF )
        {
          v7 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v7, (_DWORD *)(v7 + 4 * ((unsigned __int16)v2 & 0xFFF)), 0);
          v6 = v16;
        }
      }
      v11 = MmPfnDatabase;
      v12 = 3 * (*(_DWORD *)(v6 + 20) & 0xFFFFF);
      MiLockAndDecrementShareCount(v6, 1);
      MiLockAndDecrementShareCount(v11 + 8 * v12, 0);
      MiInsertTbFlushEntry((int)&v17, v3, 1, 0);
    }
    ++v2;
  }
  MiUnlockWorkingSetExclusive((int)&MiState[v5], v15);
  return MiFlushTbList((unsigned int)&v17, v13);
}
