// -BTreeSearchResultDeref@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAXPAU1@PAUSEARCH_RESULT@1@@Z 
 
void __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(int a1, int a2)
{
  if ( *(_DWORD *)(a2 + 12) == -1 )
    *(_DWORD *)(a2 + 4) = 0;
  else
    *(_DWORD *)(a2 + 12) = 0;
}
