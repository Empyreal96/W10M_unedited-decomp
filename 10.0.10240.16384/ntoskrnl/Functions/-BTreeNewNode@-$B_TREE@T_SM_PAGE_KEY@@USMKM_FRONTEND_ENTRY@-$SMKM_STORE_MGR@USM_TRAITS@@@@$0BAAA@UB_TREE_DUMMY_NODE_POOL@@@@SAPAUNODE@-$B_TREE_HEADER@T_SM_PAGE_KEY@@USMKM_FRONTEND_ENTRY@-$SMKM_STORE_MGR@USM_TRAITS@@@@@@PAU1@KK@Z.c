// -BTreeNewNode@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@@@PAU1@KK@Z 
 
_BYTE *__fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNewNode(int a1, char a2, char a3)
{
  _BYTE *v5; // r0
  _BYTE *v6; // r4

  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 4096);
  v6 = v5;
  if ( v5 )
  {
    memset(v5, 0, 4096);
    v6[2] = a3;
    v6[3] = a2;
  }
  return v6;
}
