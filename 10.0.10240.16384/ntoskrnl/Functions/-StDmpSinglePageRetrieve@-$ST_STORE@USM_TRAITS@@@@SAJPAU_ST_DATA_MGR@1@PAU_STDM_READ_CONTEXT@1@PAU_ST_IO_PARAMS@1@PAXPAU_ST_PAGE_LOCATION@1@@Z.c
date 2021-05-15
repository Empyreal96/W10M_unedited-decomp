// -StDmpSinglePageRetrieve@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_STDM_READ_CONTEXT@1@PAU_ST_IO_PARAMS@1@PAXPAU_ST_PAGE_LOCATION@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmpSinglePageRetrieve(int a1, int *a2, _DWORD *a3, int a4, int a5)
{
  int *v6; // r5
  _DWORD *v7; // r7
  char v9; // r9
  _DWORD *v10; // r0
  int v11; // r5
  int v12; // r4
  int v13; // r7
  char v14; // r3
  BOOL v15; // r4
  int v16; // r3
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  int v20; // r10
  unsigned int v21; // r8
  int v22; // r3
  int v23; // r1
  int v24; // r4
  int v25; // r3
  int v26; // r2
  int v27; // r2
  int v28; // r0
  int v29; // r2
  unsigned int v30; // r0
  unsigned int v31; // r2
  int v32; // r3
  _DWORD *v33; // r4
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r3
  int v38; // r0
  int v39; // r0
  unsigned __int8 *v40; // r2
  unsigned int v41; // r0
  char v42; // r3
  int v43; // r2
  int v44; // r1
  int v46; // [sp+0h] [bp-40h]
  unsigned int v47; // [sp+10h] [bp-30h]
  _DWORD *v49; // [sp+18h] [bp-28h]
  int v51[8]; // [sp+20h] [bp-20h] BYREF

  v49 = a3;
  v6 = a2;
  v7 = (_DWORD *)a2[2];
  v47 = 0;
  v9 = 0;
  if ( !*(_BYTE *)a3 )
  {
LABEL_10:
    if ( (*(_DWORD *)(a1 + 116) & 1) != 0 )
      v14 = 0;
    else
      v14 = 2;
    v15 = (v14 & 2) != 0;
    if ( v15 != (v7[5] & 1) )
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, v7);
    v16 = v7[5] & 0xFFFFFFFE | v15;
    v7[5] = v16;
    v12 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
            (unsigned __int16 **)a1,
            a3[2],
            (int)v7,
            v16);
    if ( v12 < 0 )
    {
      v11 = v51[0];
      goto LABEL_5;
    }
    v6[4] = *(_DWORD *)(*(_DWORD *)(a1 + 92) + 3528);
    v17 = v7[3];
    if ( v17 == -1 || !v17 )
      v18 = (int)(v7 + 1);
    else
      v18 = *v7 + 8 * v17 - 8;
    v11 = *(_DWORD *)(v18 + 4);
    goto LABEL_21;
  }
  if ( a2[4] != *(_DWORD *)(*(_DWORD *)(a1 + 92) + 3528) )
  {
    v6 = a2;
    goto LABEL_10;
  }
  v10 = (_DWORD *)B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindNextEntry(a1, v7);
  v11 = (int)v10;
  if ( v10 == (_DWORD *)-1 )
  {
    v12 = -1073741818;
LABEL_5:
    v13 = 0;
    goto LABEL_61;
  }
  if ( !v10 || *v10 != a3[2] )
  {
LABEL_8:
    v12 = -1073741275;
    goto LABEL_5;
  }
LABEL_21:
  if ( (*(_BYTE *)(v11 + 11) & 1) != 0 )
    goto LABEL_8;
  v19 = *(_DWORD *)(v11 + 4);
  v20 = *(_DWORD *)(a1 + 96) & v19;
  v21 = v19 >> *(_DWORD *)(a1 + 100);
  v22 = *(_DWORD *)(a1 + 72);
  if ( (*(_DWORD *)(a1 + 116) & 1) != 0 )
    v9 = 1;
  if ( (v22 & 0x40000) != 0 )
  {
    if ( (_BYTE)v22 )
      v23 = 0;
    else
      v23 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * v21) >> 13;
    v51[0] = 0;
    v13 = SmSetThreadSystemPagePriority(v51, v23, 0);
    v9 |= 2u;
  }
  else
  {
    v13 = 0;
  }
  v24 = a5;
  *(_DWORD *)a5 = *(_DWORD *)(v11 + 4);
  v25 = *(_DWORD *)(v11 + 8) & 0xFFF;
  if ( !v25 )
    LOWORD(v25) = 4096;
  *(_WORD *)(a5 + 4) = v25;
  *(_WORD *)(a5 + 6) = (unsigned __int8)*v49;
  *(_DWORD *)(a5 + 8) = *(_DWORD *)(v11 + 12);
  *(_DWORD *)(a5 + 12) = (*(_DWORD *)(v11 + 8) >> 12) & 0xFFF;
  v26 = *(_DWORD *)(a1 + 72);
  if ( !(_BYTE)v26 )
  {
    if ( (v26 & 0x40000) != 0
      || (v27 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * v21) >> 13, v21 != *(_DWORD *)(a1 + 12 * v27 + 392)) )
    {
      v27 = 8;
    }
    if ( v27 == 8 )
    {
      v28 = *(_DWORD *)(a1 + 92);
      v29 = 16 * v20;
      if ( (*(_BYTE *)(v28 + 3517) & 4) != 0 )
        v30 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(v28, v21, v29, 1, 1u);
      else
        v30 = SMKM_STORE<SM_TRAITS>::SmStMapPhysicalRegion(v28, v21, v29, 1, 1);
      v47 = v30;
      if ( v30 <= 3 )
      {
        if ( v30 == 1 )
          v12 = -2147483634;
        else
          v12 = -1073741550;
        goto LABEL_61;
      }
      v31 = v30;
      goto LABEL_55;
    }
    v32 = *(_DWORD *)(a1 + 12 * v27 + 400);
LABEL_54:
    v31 = v32 + 16 * v20;
LABEL_55:
    v12 = ST_STORE<SM_TRAITS>::StDmSinglePageTransfer(a1, a2[1], v31 | 1, a4, v49[1], v24, (int)a2);
    if ( v12 >= 0 )
      v12 = 0;
    goto LABEL_58;
  }
  if ( (a4 & 1) != 0 )
  {
    v33 = (_DWORD *)(a4 & 0xFFFFFFFE);
    v34 = *(_DWORD *)(v11 + 4);
    v35 = *(_DWORD *)(v11 + 8);
    v36 = *(_DWORD *)(v11 + 12);
    *v33 = *(_DWORD *)v11;
    v33[1] = v34;
    v33[2] = v35;
    v33[3] = v36;
    v24 = a5;
  }
  else
  {
    v37 = *(_DWORD *)(a1 + 316) + 1;
    *(_DWORD *)(a1 + 316) = v37;
    if ( v37 == 0x1000000 )
      ST_STORE<SM_TRAITS>::StRegionLATRebase(a1, 0x400000);
    v35 = *(unsigned __int16 *)(a1 + 318);
    *(_BYTE *)(*(_DWORD *)(a1 + 312) + v21) = v35;
  }
  if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v21) & 0x4000) == 0 )
  {
    v38 = ST_STORE<SM_TRAITS>::StStagingRegionFind(a1, v21);
    if ( v38 )
    {
      v32 = *(_DWORD *)(v38 + 4);
      goto LABEL_54;
    }
  }
  v12 = 259;
LABEL_58:
  if ( v47 )
  {
    v39 = *(_DWORD *)(a1 + 92);
    if ( (*(_BYTE *)(v39 + 3517) & 4) != 0 )
    {
      SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion((_DWORD *)v39, v21, v35, 0, v46, 0);
    }
    else
    {
      v43 = *(_DWORD *)(v39 + 3660);
      v44 = *(_DWORD *)(v43 + 4 * v21);
      *(_DWORD *)(v43 + 4 * v21) = v44 & 0xFFFFFFFE;
      if ( (v44 & 2) == 0 )
        SmFpFree(v39 + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v44 & 0xFFFFFFF8);
    }
  }
LABEL_61:
  if ( (v9 & 1) != 0 )
  {
    __dmb(0xBu);
    v40 = (unsigned __int8 *)(v11 + 11);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 | 1, v40) );
    __dmb(0xBu);
    if ( (v41 & 1) != 0 )
    {
      v42 = 0;
    }
    else
    {
      ST_STORE<SM_TRAITS>::StDmLazyRemoveStateUpdate(a1, (unsigned int *)v11, 1);
      v42 = 1;
    }
    v9 = v9 & 0xFE | v42 & 1;
    if ( (v9 & 1) == 0 )
      v12 = -1073741275;
  }
  if ( (v9 & 2) != 0 )
    SmSetThreadSystemPagePriority(v51, v13, 1);
  return v12;
}
