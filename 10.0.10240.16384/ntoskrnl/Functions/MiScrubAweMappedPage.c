// MiScrubAweMappedPage 
 
int __fastcall MiScrubAweMappedPage(int *a1, int a2, int a3, int a4)
{
  int v5; // r8
  unsigned int *v6; // r4
  int v7; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r7
  int v13; // r2
  int v14; // r3
  int v15; // r5
  int v16; // r0
  int v19; // [sp+8h] [bp-28h]
  int v20; // [sp+Ch] [bp-24h]

  v5 = MmPfnDatabase + 24 * a2;
  v6 = (unsigned int *)(a4 + 492);
  v19 = *a1;
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v6);
  }
  else
  {
    v8 = (unsigned __int8 *)v6 + 3;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v6);
    while ( 1 )
    {
      v10 = *v6;
      if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex(v6);
        while ( v11 == v10 && __strex(v10 | 0x40000000, v6) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( *(_WORD *)(v5 + 16) == 2 )
  {
    if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
    {
      *a1 = 0;
    }
    else
    {
      __dmb(0xBu);
      *a1 = 0;
      if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
      {
        v7 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v7, (_DWORD *)(v7 + 4 * ((unsigned __int16)a1 & 0xFFF)), 0);
      }
    }
    KeFlushSingleTb((_DWORD)a1 << 10, 0);
    v12 = MiScrubPage(a3, *(_DWORD *)(a3 + 16), v5);
    v13 = v19 | 0x10;
    if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
    {
      *a1 = v13;
    }
    else
    {
      v14 = *a1;
      v15 = 0;
      __dmb(0xBu);
      *a1 = v13;
      if ( (v14 & 2) == 0 && (v13 & 2) != 0 )
        v15 = 1;
      if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
      {
        v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * ((unsigned __int16)a1 & 0xFFF)), v13);
      }
      if ( v15 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  else
  {
    v12 = 0;
  }
  MiUnlockWorkingSetExclusive((int)v6, v20);
  return v12;
}
