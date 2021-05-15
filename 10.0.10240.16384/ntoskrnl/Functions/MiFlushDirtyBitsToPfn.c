// MiFlushDirtyBitsToPfn 
 
int __fastcall MiFlushDirtyBitsToPfn(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r10
  unsigned int *v7; // r4
  unsigned int v8; // r6
  int v9; // r5
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r7
  int v15; // r0
  unsigned int v16; // r10
  int v17; // r8
  unsigned int v18; // r5
  int v19; // r7
  int v20; // lr
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // r2
  unsigned int v26; // r3
  int v27; // r5
  unsigned int v28; // r1
  unsigned __int8 *v29; // r1
  int v30; // r2
  int v31; // r3
  unsigned int v32; // r2
  int v33; // r0
  unsigned int v34; // [sp+8h] [bp-D0h]
  int v35; // [sp+Ch] [bp-CCh]
  char v36[4]; // [sp+10h] [bp-C8h] BYREF
  int v37; // [sp+14h] [bp-C4h]
  unsigned int *v38; // [sp+18h] [bp-C0h]
  int v39; // [sp+1Ch] [bp-BCh]
  int v40; // [sp+20h] [bp-B8h] BYREF
  char v41; // [sp+24h] [bp-B4h]
  char v42; // [sp+25h] [bp-B3h]
  int v43; // [sp+28h] [bp-B0h]
  int v44; // [sp+2Ch] [bp-ACh]
  int v45; // [sp+30h] [bp-A8h]
  int v46; // [sp+34h] [bp-A4h]

  v4 = a4;
  v35 = a4;
  v44 = 0;
  v45 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 33;
  v46 = 0;
  v34 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v7 = (unsigned int *)(*(_DWORD *)(a3 + 116) + 492);
  v40 = 1;
  v8 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v38 = v7;
  v9 = KfRaiseIrql(2);
  v37 = v9;
  v39 = 0x80000000;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_520570();
  v11 = (unsigned __int8 *)v7 + 3;
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  __dmb(0xBu);
  if ( v12 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v7);
  while ( 1 )
  {
    v13 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v13 & 0x40000000) == 0 )
    {
      do
        v28 = __ldrex(v7);
      while ( v28 == v13 && __strex(v13 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( v4 == 1 && MiAnyAddressLocked(a1, a2) == 1 )
    v35 = 0;
  v14 = v34;
  if ( v8 <= v34 )
  {
    do
    {
      v15 = MiGetNextPageTable(v8, v14, &v40, v9, 1, v36);
      v8 = v15;
      if ( !v15 )
        break;
      v16 = v15 + 0x40000000;
      v17 = v15 << 10;
      do
      {
        v18 = *(_DWORD *)v8;
        if ( (*(_DWORD *)v8 & 2) != 0 && (v18 & 0x200) == 0 )
        {
          v19 = MmPfnDatabase + 24 * (v18 >> 12);
          v20 = KfRaiseIrql(2);
          v21 = (unsigned __int8 *)(v19 + 15);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 | 0x80, v21) );
          __dmb(0xBu);
          if ( v22 >> 7 )
          {
            v29 = (unsigned __int8 *)(v19 + 15);
            do
            {
              v30 = v39;
              do
              {
                __dmb(0xAu);
                __yield();
                v31 = *(_DWORD *)(v19 + 12);
                __dmb(0xBu);
              }
              while ( (v31 & v30) != 0 );
              do
                v32 = __ldrex(v29);
              while ( __strex(v32 | 0x80, v29) );
              __dmb(0xBu);
            }
            while ( v32 >> 7 );
          }
          *(_BYTE *)(v19 + 18) |= 0x10u;
          __dmb(0xBu);
          v23 = (unsigned int *)(v19 + 12);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 & 0x7FFFFFFF, v23) );
          KfLowerIrql(v20);
          v25 = v18 | 0x200;
          if ( v16 > 0x3FFFFF )
          {
            *(_DWORD *)v8 = v25;
          }
          else
          {
            v26 = *(_DWORD *)v8;
            v27 = 0;
            __dmb(0xBu);
            *(_DWORD *)v8 = v25;
            if ( (v26 & 2) == 0 && (v25 & 2) != 0 )
              v27 = 1;
            if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            {
              v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v33, v33 + 4 * (v8 & 0xFFF), v25);
            }
            if ( v27 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          MiInsertTbFlushEntry(&v40, v17, 1);
          v14 = v34;
        }
        v17 += 4096;
        v8 += 4;
        v16 += 4;
      }
      while ( v8 <= v14 && (v17 & 0x3FFFFF) != 0 );
      v9 = v37;
    }
    while ( v8 <= v14 );
    v7 = v38;
  }
  MiFlushTbList(&v40);
  MiUnlockWorkingSetExclusive(v7, v9);
  return v35;
}
