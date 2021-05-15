// -BTreeIteratorFromSearchResult@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAXPAU1@PAUITERATOR@1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(int a1, _DWORD *a2, _DWORD *a3)
{
  int result; // r0
  _DWORD *v4; // r2
  int v5; // r3

  result = a3[3];
  *a2 = 0;
  a2[1] = 0;
  if ( result == -1 || !result )
    v4 = a3 + 1;
  else
    v4 = (_DWORD *)(*a3 + 8 * result - 8);
  *a2 = *v4;
  v5 = v4[1];
  a2[1] = v5;
  a2[1] = v5 - 8;
  return result;
}
