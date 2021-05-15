// MiDeleteSessionAddressSpace 
 
unsigned int __fastcall MiDeleteSessionAddressSpace(unsigned int a1, _DWORD *a2)
{
  unsigned int *v2; // r5
  int v3; // r7
  unsigned int v6; // t1
  unsigned int *v7; // r5
  unsigned int v8; // r4
  int v9; // r10
  unsigned int v10; // r0
  int v11; // r3
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r4
  int v17; // r7
  int v18; // r6
  int v19; // r0
  int v20; // r1
  int v21; // r1
  int v23; // [sp+8h] [bp-C0h] BYREF
  int v24; // [sp+Ch] [bp-BCh]
  int v25; // [sp+10h] [bp-B8h] BYREF
  char v26; // [sp+14h] [bp-B4h]
  char v27; // [sp+15h] [bp-B3h]
  int v28; // [sp+18h] [bp-B0h]
  int v29; // [sp+1Ch] [bp-ACh]
  int v30; // [sp+20h] [bp-A8h]
  int v31; // [sp+24h] [bp-A4h]

  v2 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v3 = 3;
  do
  {
    v6 = *v2++;
    MiIncrementPfn(MmPfnDatabase + 24 * (v6 >> 12));
    --v3;
  }
  while ( v3 );
  v29 = 0;
  v25 = 2;
  v26 = 0;
  v27 = 0;
  v30 = 0;
  v7 = (unsigned int *)(a1 + 3248);
  v28 = 33;
  v31 = 0;
  v8 = (((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000;
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
  }
  else
  {
    v12 = (unsigned __int8 *)(a1 + 3251);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v7);
    while ( 1 )
    {
      v14 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v14 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex(v7);
        while ( v15 == v14 && __strex(v14 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( *(_DWORD *)(a1 + 3256) )
  {
    MiEmptyPageAccessLog();
    *(_DWORD *)(a1 + 3256) = 0;
  }
  *(_DWORD *)(a1 + 3340) = 0;
  if ( v8 <= 0xC03FEFFC )
  {
    v9 = v24;
    do
    {
      v10 = MiGetNextPageTable(v8, 0xC03FEFFC, 1, v9, 1, &v23);
      v8 = v10;
      if ( !v10 )
        break;
      if ( v10 << 10 >= dword_63389C
        && ((v11 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v10 << 10 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v11 == 1)
         || v11 == 11) )
      {
        do
        {
          v23 = 0;
          MiDeleteSystemPte(v8, &v25, a2, &v23);
          v8 += 4;
          if ( v23 == 1 )
            break;
          if ( v8 > 0xC03FEFFC )
            goto LABEL_29;
        }
        while ( (v8 & 0xFFF) != 0 );
      }
      else
      {
        v8 = (((v10 >> 10) & 0xFFFFFFFC) + 4) << 10;
      }
    }
    while ( v8 <= 0xC03FEFFC );
  }
LABEL_29:
  v16 = (((unsigned int)MmSessionSpace >> 20) & 0xFFC) - 1070596096;
  v17 = MmPfnDatabase;
  v18 = 3 * (*(_DWORD *)v16 >> 12);
  __dmb(0xBu);
  *(_DWORD *)v16 = 0;
  if ( v16 + 1070596096 <= 0xFFF )
  {
    v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * (v16 & 0xFFF)), 0);
  }
  MiLockAndDecrementShareCount(v17 + 8 * v18, 1);
  MiLockAndDecrementShareCount(v17 + 8 * v18, 0);
  MiInsertTbFlushEntry((int)&v25, v16 << 10, 1, 0);
  v20 = v24;
  a2[1] -= 3;
  a2[3] -= 2;
  *a2 -= 2;
  MiUnlockWorkingSetExclusive((int)v7, v20);
  return MiFlushTbList((unsigned int)&v25, v21);
}
