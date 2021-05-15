// MiMapLockedPagesInUserSpaceHelper 
 
int __fastcall MiMapLockedPagesInUserSpaceHelper(unsigned int a1, int *a2, _DWORD *a3, int a4, int a5, int a6, int a7)
{
  int v7; // r7
  int v9; // r9
  int v10; // r10
  unsigned int *v11; // r8
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r7
  int v16; // r4
  int v17; // r5
  int v18; // r6
  int v19; // r5
  int v20; // r2
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r4
  int v24; // r0
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r4
  unsigned int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r0
  unsigned __int16 v33; // r3
  int v34; // r3
  int v35; // r0
  unsigned __int8 *v36; // r1
  int v37; // r3
  unsigned int v38; // r2
  unsigned int v40; // [sp+10h] [bp-40h]
  unsigned int v42; // [sp+18h] [bp-38h]
  int v43; // [sp+1Ch] [bp-34h]
  int v45; // [sp+24h] [bp-2Ch]

  v40 = a1;
  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v43 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( a7 < 0 )
    return sub_521374();
  v9 = 4;
  v10 = MiPlatformCacheAttributes[a4];
  if ( v10 )
  {
    if ( v10 == 2 )
      v9 = 28;
  }
  else
  {
    v9 = 12;
  }
  v11 = (unsigned int *)(v7 + 492);
  v45 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7 + 492);
  }
  else
  {
    v12 = (unsigned __int8 *)(v7 + 495);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v7 + 492));
    while ( 1 )
    {
      v14 = *v11;
      if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v14 & 0x40000000) == 0 )
      {
        do
          v29 = __ldrex(v11);
        while ( v29 == v14 && __strex(v14 | 0x40000000, v11) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( a6 )
    MiInsertVad(a6, v7);
  v15 = v43;
  v42 = v43 + 0x40000000;
  do
  {
    MiMakeSystemAddressValid(v15, 0);
    MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(2 * ((v40 >> 22) - 534769440), 1, v40);
    v16 = v9;
    v17 = MmPfnDatabase;
    if ( a3 )
    {
      v10 = 1;
      v30 = MmPfnDatabase + 24 * *a3;
      v16 = (*(_DWORD *)(v30 + 8) >> 5) & 0x1F;
      v31 = *(unsigned __int8 *)(v30 + 18) >> 6;
      if ( v31 == 2 )
      {
        v10 = 2;
      }
      else if ( !v31 )
      {
        v10 = 0;
      }
      ++a3;
    }
    v18 = *a2;
    if ( MI_IS_PFN(*a2) )
    {
      v19 = v17 + 24 * v18;
      if ( !*(_WORD *)(v19 + 16) )
        MiShowBadMapper(v18, 2);
      if ( (*(_BYTE *)(v19 + 18) & 0xC0) == 192 )
        MiAssignInitialPageAttribute(v19, v10);
      if ( v10 != *(unsigned __int8 *)(v19 + 18) >> 6 )
        v16 = MiMakeProtectionPfnCompatible(v16, v19);
    }
    else
    {
      v16 &= 7u;
      v32 = MiLookupIoPageNode(v18);
      if ( !v32 )
        KeBugCheckEx(26, 399689, *a2);
      v33 = *(_WORD *)(*(_DWORD *)(v32 + 24) + 2 * (*a2 - *(_DWORD *)(v32 + 20)));
      __dmb(0xBu);
      v34 = v33 >> 14;
      if ( v34 )
      {
        if ( v34 == 2 )
          v16 |= 0x38u;
      }
      else
      {
        v16 |= 0x28u;
      }
    }
    v20 = *a2++;
    v21 = (MmProtectToPteMask[v16] | (v20 << 12)) & 0xFFFFFBFF | 0x832;
    if ( (v21 & 0x80) != 0 )
      v21 &= 0xFFFFFDFF;
    if ( v42 > 0x3FFFFF )
    {
      *(_DWORD *)v15 = v21;
    }
    else
    {
      v22 = *(_DWORD *)v15;
      v23 = 0;
      __dmb(0xBu);
      *(_DWORD *)v15 = v21;
      if ( (v22 & 2) == 0 && (v21 & 2) != 0 )
        v23 = 1;
      if ( v15 >= 0xC0300000 && v15 <= 0xC0300FFF )
      {
        v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v35, v35 + 4 * (v15 & 0xFFF), v21);
      }
      if ( v23 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v24 = MmPfnDatabase + 24 * (*(_DWORD *)(((v15 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
    v25 = (unsigned __int8 *)(v24 + 15);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 | 0x80, v25) );
    __dmb(0xBu);
    if ( v26 >> 7 )
    {
      v36 = (unsigned __int8 *)(v24 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v37 = *(_DWORD *)(v24 + 12);
          __dmb(0xBu);
        }
        while ( (v37 & 0x80000000) != 0 );
        do
          v38 = __ldrex(v36);
        while ( __strex(v38 | 0x80, v36) );
        __dmb(0xBu);
      }
      while ( v38 >> 7 );
    }
    *(_DWORD *)(v24 + 12) = *(_DWORD *)(v24 + 12) & 0xC0000000 | (*(_DWORD *)(v24 + 12) + 1) & 0x3FFFFFFF;
    __dmb(0xBu);
    v27 = (unsigned int *)(v24 + 12);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    v42 += 4;
    v15 += 4;
    --a5;
    v40 += 4096;
  }
  while ( a5 );
  if ( a6 )
    ++MEMORY[0xC0402124];
  return MiUnlockWorkingSetExclusive(v11, v45);
}
