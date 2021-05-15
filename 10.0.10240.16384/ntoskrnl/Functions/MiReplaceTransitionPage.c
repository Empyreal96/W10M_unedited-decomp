// MiReplaceTransitionPage 
 
int __fastcall MiReplaceTransitionPage(int *a1, _DWORD *a2, int a3)
{
  int v3; // r10
  int v6; // r7
  int v7; // r4
  int *v8; // r6
  unsigned int v9; // r4
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  int result; // r0
  int v13; // r2
  int v14; // r2
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r3
  int v18; // r1
  int v19; // r5
  int v20; // r4
  int v21; // r1
  int v22; // r10
  int *v23; // r1
  int v24; // r0
  unsigned int *v25; // r1
  int *v26; // r0
  char v27; // r3
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r4
  int v31; // r1
  int v32; // r2
  unsigned int *v33; // r2
  int v34; // r3
  int v35; // r3
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int v38; // r1
  unsigned int *v39; // r5
  int v40; // r2
  int v41; // r2
  unsigned int v42; // r0
  int v43; // r4
  int v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r3
  unsigned int v47; // r0
  int v48; // r5
  int v49; // r0
  int v50; // [sp+0h] [bp-38h]
  int v51; // [sp+4h] [bp-34h]
  unsigned int v52; // [sp+8h] [bp-30h]
  int var28[12]; // [sp+10h] [bp-28h] BYREF

  v3 = 0xFFFFFF;
  v50 = 0xFFFFFF;
  v52 = ((int)a1 - MmPfnDatabase) / 24;
  v6 = ((int)a2 - MmPfnDatabase) / 24;
  v7 = *((_BYTE *)a1 + 18) & 7;
  v8 = *(int **)&MiSystemPartition[2 * v7 + 1226];
  if ( v7 == 3 && (a1[2] & 0x400) != 0 )
  {
    v9 = (unsigned int)a1[5] >> 28;
    a1[5] = a1[5] & 0xFFFFFFF | (MiPageToNode(((int)a1 - MmPfnDatabase) / 24, 1) << 28);
  }
  else
  {
    v9 = a2[5] >> 28;
  }
  v10 = (unsigned __int8 *)a2 + 15;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    return sub_5134F4();
  MiFinalizePageAttribute(a2, *((unsigned __int8 *)a1 + 18) >> 6, 1);
  MiCopyPfnEntry(a2, a1);
  v13 = a2[5] & 0xFFFFFFF | (v9 << 28);
  a2[5] = v13;
  if ( (a1[5] & 0xFFFFF) == v52 )
    a2[5] = v13 & 0xFFF00000 | v6 & 0xFFFFF;
  MiCopyPage(v6, v52, a3, 6);
  __dmb(0xFu);
  v14 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v15 = (a2[3] ^ (v14 << 20)) & 0xF00000;
  a2[3] ^= v15;
  v51 = 0;
  v16 = v8[1];
  if ( v16 == 2 )
  {
    v17 = *((unsigned __int8 *)a1 + 19);
    v18 = (v17 >> 3) & 1;
    if ( v18 == 1 )
      v3 = 5;
    else
      v3 = v17 & 7;
    v15 = 5 * v3;
    v16 = (int)dword_63FD00;
    v8 = &dword_63FD00[5 * v3];
    v50 = v3;
    if ( v18 == 1 )
    {
      v16 = 1;
      v51 = 1;
    }
  }
  else if ( v16 == 3 )
  {
    v35 = a2[2];
    if ( (v35 & 0x400) != 0 )
    {
      v8 = (int *)((char *)&unk_63FF00 + 20 * v9);
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v8 + 4, var28, 5 * v9, &unk_63FF00);
    }
    else
    {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v8 + 4, var28, v15, v35);
      v8 = (int *)MiDetermineModifiedPageListHead(a2, MiSystemPartition);
    }
    goto LABEL_52;
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(v8 + 4, var28, v15, v16);
  if ( v3 != 0xFFFFFF )
  {
    v19 = *a1;
    v20 = a1[3] & 0xFFFFF;
    a2[3] = a2[3] & 0xFFF00000 | v20;
    *a2 = v19;
    goto LABEL_16;
  }
LABEL_52:
  v19 = *a1;
  v20 = a1[3] & 0xFFFFF;
  *a2 = *a1;
  MiSetPfnBlink(a2, v20, 0);
LABEL_16:
  v21 = 0xFFFFF;
  if ( v19 == 0xFFFFF )
  {
    v8[3] = v6;
  }
  else
  {
    v22 = MmPfnDatabase + 24 * v19;
    if ( v50 != 0xFFFFFF && v51 == 1 && MI_IS_DECAY_PFN(v19) == 1 )
    {
      *(_DWORD *)(v22 + 20) = *(_DWORD *)(v22 + 20) & 0xFFF00000 | v6 & 0xFFFFF;
    }
    else
    {
      MiSetPfnBlink(v22, v6, 0);
      v21 = 0xFFFFF;
    }
    v3 = v50;
  }
  if ( v20 == v21 )
  {
    v8[2] = v6;
  }
  else
  {
    v23 = (int *)(MmPfnDatabase + 24 * v20);
    if ( v3 != 0xFFFFFF && v51 == 1 && MI_IS_DECAY_PFN(v20) == 1 )
      v23[2] = v23[2] & 0xFFF | (v6 << 12);
    else
      *v23 = v6;
  }
  *((_BYTE *)a1 + 18) = *((_BYTE *)a1 + 18) & 0xF8 | 5;
  if ( dword_634380 != 1 )
    goto LABEL_26;
  LOBYTE(v38) = 1;
  v39 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * (v52 >> 5));
  v40 = v52 & 0x1F;
  if ( (unsigned int)(v40 + 1) <= 0x20 )
  {
    __dmb(0xBu);
    v41 = 1 << v40;
    do
      v42 = __ldrex(v39);
    while ( __strex(v42 | v41, v39) );
LABEL_79:
    __dmb(0xBu);
    goto LABEL_26;
  }
  if ( (v52 & 0x1F) == 0 )
    goto LABEL_77;
  v43 = 32 - v40;
  __dmb(0xBu);
  v44 = ((1 << (32 - v40)) - 1) << v40;
  do
    v45 = __ldrex(v39);
  while ( __strex(v45 | v44, v39) );
  __dmb(0xBu);
  v38 = 1 - v43;
  ++v39;
  if ( (unsigned int)(1 - v43) >= 0x20 )
  {
    v46 = v38 >> 5;
    do
    {
      v38 -= 32;
      *v39++ = -1;
      --v46;
    }
    while ( v46 );
  }
  if ( v38 )
  {
LABEL_77:
    __dmb(0xBu);
    do
      v47 = __ldrex(v39);
    while ( __strex(v47 | ((1 << v38) - 1), v39) );
    goto LABEL_79;
  }
LABEL_26:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(var28, var28[11]);
  }
  else
  {
    v24 = var28[0];
    if ( !var28[0] )
    {
      v25 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v26 = (int *)__ldrex(v25);
      while ( v26 == var28 && __strex(0, v25) );
      if ( v26 == var28 )
        goto LABEL_32;
      v24 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v36 = (unsigned int *)(v24 + 4);
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 ^ 1, v36) );
  }
LABEL_32:
  __dmb(0xFu);
  v27 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v28 = a1[5] & 0xFFFFF;
  a1[3] = a1[3] & 0xFF000000 | ((v27 & 0xF) << 20);
  if ( v28 == v52 )
  {
    v29 = 0;
    v30 = a1[1] | 0x80000000;
  }
  else
  {
    v29 = 1;
    v30 = MiMapPageInHyperSpaceWorker(v28, 0, 0x80000000) + 4 * (((unsigned int)a1[1] >> 2) & 0x3FF);
  }
  v31 = *(_DWORD *)v30;
  v32 = *(_DWORD *)v30 & 0xFFF | (v6 << 12);
  if ( v30 < 0xC0000000 || v30 > 0xC03FFFFF )
  {
    *(_DWORD *)v30 = v32;
  }
  else
  {
    v48 = 0;
    __dmb(0xBu);
    *(_DWORD *)v30 = v32;
    if ( (v31 & 2) == 0 && (v32 & 2) != 0 )
      v48 = 1;
    if ( v30 + 1070596096 <= 0xFFF )
    {
      v49 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v49, v49 + 4 * (v30 & 0xFFF), v32);
    }
    if ( v48 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( v29 == 1 )
  {
    MiUnmapPageInHyperSpaceWorker(v30, 17, 0x80000000);
    v30 = a1[1] | 0x80000000;
  }
  if ( (a1[5] & 0x8000000) == 0 && v30 >= dword_63389C )
  {
    v34 = *((unsigned __int8 *)&MiState[2423]
          + ((int)(((v30 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v34 == 5 || v34 == 13 )
      MiReinitializeDirectoryTableBase(v30 - 352, v30 - 328, v6);
  }
  __dmb(0xBu);
  v33 = a2 + 3;
  do
    result = __ldrex(v33);
  while ( __strex(result & 0x7FFFFFFF, v33) );
  if ( v51 == 1 )
    *((_BYTE *)a1 + 19) &= 0xF7u;
  a1[5] &= 0xF0FFFFFF;
  *((_BYTE *)a1 + 18) &= 0xC7u;
  *((_BYTE *)a1 + 19) &= 0xDFu;
  return result;
}
