// -SmFeAddFirstPass@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAT_SM_PAGE_KEY@@KPAUSEARCH_RESULT@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeAddFirstPass(int a1, unsigned int *a2, unsigned __int16 *a3, _DWORD *a4, char a5)
{
  unsigned int v5; // r4
  unsigned int v6; // r5
  unsigned int *v8; // r2
  int v9; // r3
  unsigned __int16 *v10; // [sp+0h] [bp-10h] BYREF
  _DWORD *v11; // [sp+4h] [bp-Ch]

  v10 = a3;
  v11 = a4;
  v5 = *a2;
  v6 = (unsigned int)a3 + *a2 - 1;
  if ( ((1 << a5) & *(_DWORD *)(a1 + 3204)) != 0 )
    return -1072103354;
  B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
    a1,
    &v10,
    a4);
  if ( !v10 )
    return 0;
  v8 = v11 + 2;
  if ( v11 + 2 >= (_DWORD *)&v10[4 * *v10 + 4] )
  {
    v9 = *((_DWORD *)v10 + 1);
    v8 = (unsigned int *)(v9 + 8);
    if ( !v9 )
      v8 = 0;
  }
  if ( !v8 || v5 < *v8 && v6 < *v8 )
    return 0;
  if ( (*((_BYTE *)v8 + 7) & 1) != 0 )
    return -1073740747;
  return -1073740682;
}
