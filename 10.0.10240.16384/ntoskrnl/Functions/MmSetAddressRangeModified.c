// MmSetAddressRangeModified 
 
int __fastcall MmSetAddressRangeModified(unsigned int a1, int a2)
{
  unsigned int v2; // r8
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r2
  unsigned int v7; // r3
  unsigned int v8; // r7
  int v9; // r9
  int v10; // r4
  int v11; // r10
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int *v14; // r2
  unsigned int v15; // r4
  int v16; // r4
  unsigned int v17; // r3
  int v18; // r7
  int v19; // r4
  unsigned int v20; // r0
  unsigned __int8 *v21; // r1
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // [sp+0h] [bp-C8h]
  unsigned int v26; // [sp+4h] [bp-C4h]
  int v27; // [sp+Ch] [bp-BCh]
  int v28; // [sp+10h] [bp-B8h] BYREF
  char v29; // [sp+14h] [bp-B4h]
  char v30; // [sp+15h] [bp-B3h]
  int v31; // [sp+18h] [bp-B0h]
  int v32; // [sp+1Ch] [bp-ACh]
  int v33; // [sp+20h] [bp-A8h]
  int v34; // [sp+24h] [bp-A4h]

  v32 = 0;
  v33 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 33;
  v34 = 0;
  v2 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v26 = (((a1 + a2 - 1) >> 10) & 0x3FFFFC) - 0x40000000;
  v25 = a1 & 0xFFFFF000;
  v27 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_520884();
  do
    v4 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
  while ( 1 )
  {
    v5 = dword_634E00;
    if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634E00 & 0x40000000) == 0 )
    {
      do
        v20 = __ldrex((unsigned int *)&dword_634E00);
      while ( v20 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_634E00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v7 = v25;
  v6 = v26;
  do
  {
    v8 = *(_DWORD *)v2;
    if ( (*(_DWORD *)v2 & 2) != 0 )
    {
      v9 = 0;
      v10 = MmPfnDatabase + 24 * (v8 >> 12);
      v11 = KfRaiseIrql(2);
      v12 = (unsigned __int8 *)(v10 + 15);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 | 0x80, v12) );
      __dmb(0xBu);
      if ( v13 >> 7 )
      {
        v21 = (unsigned __int8 *)(v10 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v22 = *(_DWORD *)(v10 + 12);
            __dmb(0xBu);
          }
          while ( (v22 & 0x80000000) != 0 );
          do
            v23 = __ldrex(v21);
          while ( __strex(v23 | 0x80, v21) );
          __dmb(0xBu);
        }
        while ( v23 >> 7 );
      }
      if ( (*(_BYTE *)(v10 + 18) & 0x10) == 0 || (*(_DWORD *)(v10 + 8) & 0x400) == 0 )
        v9 = MiCaptureDirtyBitToPfn(v10);
      __dmb(0xBu);
      v14 = (unsigned int *)(v10 + 12);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 & 0x7FFFFFFF, v14) );
      KfLowerIrql(v11);
      if ( v9 )
        MiReleasePageFileInfo(MiSystemPartition, v9, 0);
      if ( (v8 & 0x200) == 0 )
      {
        v16 = v8 | 0x200;
        if ( v2 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v2 = v16;
        }
        else
        {
          v17 = *(_DWORD *)v2;
          v18 = 0;
          __dmb(0xBu);
          *(_DWORD *)v2 = v16;
          if ( (v17 & 2) == 0 && (v16 & 2) != 0 )
            v18 = 1;
          if ( v2 + 1070596096 <= 0xFFF )
          {
            v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v24, v24 + 4 * (v2 & 0xFFF), v16);
          }
          if ( v18 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        MiInsertTbFlushEntry(&v28, v25, 1);
      }
      v7 = v25;
      v6 = v26;
    }
    v2 += 4;
    v7 += 4096;
    v25 = v7;
  }
  while ( v2 <= v6 );
  v19 = v32;
  MiFlushTbList(&v28);
  MiUnlockWorkingSetExclusive(&dword_634E00, v27);
  return v19 != 0;
}
