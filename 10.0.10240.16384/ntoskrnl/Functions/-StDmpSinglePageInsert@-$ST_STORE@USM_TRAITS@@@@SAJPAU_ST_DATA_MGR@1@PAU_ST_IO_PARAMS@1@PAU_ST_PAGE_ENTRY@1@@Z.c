// -StDmpSinglePageInsert@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_IO_PARAMS@1@PAU_ST_PAGE_ENTRY@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmpSinglePageInsert(int a1, int a2, unsigned int *a3)
{
  char v4; // r7
  int v6; // r3
  _DWORD *v7; // r2
  int v8; // r5
  int v9; // r3
  int v10; // r3
  int v11; // r1
  unsigned int v12; // r5
  int v13; // r8
  int v14; // r2
  unsigned int v15; // lr
  int v16; // r0
  int v17; // r2
  int v18; // r3
  int v19; // r0
  unsigned int v21; // [sp+10h] [bp-40h] BYREF
  unsigned int v22; // [sp+14h] [bp-3Ch]
  int v23[14]; // [sp+18h] [bp-38h] BYREF

  v4 = 0;
  if ( (*(_DWORD *)(a1 + 32) & 1) != 0 )
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
  *(_DWORD *)(a1 + 32) &= 0xFFFFFFFE;
  if ( (*(_DWORD *)(a1 + 68) & 1) != 0 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
      a1 + 36,
      a1 + 48);
  v6 = *(_DWORD *)(a1 + 68) & 0xFFFFFFFE;
  *(_DWORD *)(a1 + 68) = v6;
  v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
         (unsigned __int16 **)a1,
         *a3,
         a1 + 12,
         v6);
  if ( v8 >= 0 )
  {
    memset(v23, 0, 24);
    v23[2] = 1;
    v23[1] = *a3;
    v23[3] |= 1u;
    ST_STORE<SM_TRAITS>::StDmPageRemove(a1, (int)v23);
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
           (unsigned __int16 **)a1,
           *a3,
           a1 + 12,
           v9);
  }
  v10 = -1073741275;
  if ( v8 == -1073741275 )
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(a1, a1 + 12, a3);
  if ( v8 < 0
    || (v21 = 0,
        v22 = 0,
        v21 = a3[1],
        v4 = 1,
        v22 = *a3,
        v8 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsert(
               a1 + 36,
               &v21,
               a1 + 48),
        v8 < 0) )
  {
    if ( (v4 & 1) != 0 )
    {
      v19 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(
              a1,
              (_DWORD *)(a1 + 12),
              v7,
              v10);
      if ( v19 < 0 )
        v8 = v19;
    }
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 304);
    v4 = 3;
    v12 = a3[1] >> *(_DWORD *)(a1 + 100);
    if ( *(_BYTE *)(a1 + 72) )
      v13 = 0;
    else
      v13 = *(unsigned __int16 *)(v11 + 2 * v12) >> 13;
    v14 = a3[2] & 0xFFF;
    if ( !v14 )
      v14 = 4096;
    v15 = *(_DWORD *)(a1 + 112) + v14 + 15;
    if ( *(_BYTE *)(a1 + 72) )
      v16 = 0;
    else
      v16 = *(unsigned __int16 *)(v11 + 2 * v12) >> 13;
    *(_WORD *)(v11 + 2 * v12) += v15 >> 4;
    *(_DWORD *)(a1 + 8 * v16 + 688) += v15 >> 4;
    *(_DWORD *)(a1 + 12 * v16 + 396) += v15 >> 4;
    if ( (dword_636E9C & 0x10) != 0 )
      SmEtwLogStoreOp(&unk_636E90, 0);
    if ( *(_BYTE *)(a1 + 72) == 1 )
    {
      v17 = a1 + 12 * v13;
      if ( *(_DWORD *)(v17 + 392) == -1
        || (unsigned int)(*(_DWORD *)(v17 + 396) + *(_DWORD *)(a1 + 108)) > *(_DWORD *)(a1 + 104) )
      {
        v4 = 7;
      }
      v18 = *(_DWORD *)(a1 + 316) + 1;
      *(_DWORD *)(a1 + 316) = v18;
      if ( v18 == 0x1000000 )
        ST_STORE<SM_TRAITS>::StRegionLATRebase(a1, 0x400000);
      *(_BYTE *)(*(_DWORD *)(a1 + 312) + v12) = *(_WORD *)(a1 + 318);
    }
    v8 = 0;
  }
  if ( (v4 & 4) != 0 )
    ST_STORE<SM_TRAITS>::StDmpCurrentRegionWrite((_DWORD *)a1);
  return v8;
}
