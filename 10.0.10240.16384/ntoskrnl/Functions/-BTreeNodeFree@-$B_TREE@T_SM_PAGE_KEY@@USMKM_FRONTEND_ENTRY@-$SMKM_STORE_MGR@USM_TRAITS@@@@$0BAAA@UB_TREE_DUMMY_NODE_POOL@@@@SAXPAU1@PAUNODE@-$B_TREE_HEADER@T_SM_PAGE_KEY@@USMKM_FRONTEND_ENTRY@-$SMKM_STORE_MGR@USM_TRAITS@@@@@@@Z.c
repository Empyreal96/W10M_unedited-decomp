// -BTreeNodeFree@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAXPAU1@PAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@@@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNodeFree(int a1, unsigned __int16 *a2)
{
  unsigned __int16 *v4; // r6
  unsigned __int16 *v5; // r5
  unsigned int v6; // r7
  unsigned __int16 *v7; // r3

  if ( !*((_BYTE *)a2 + 3) )
  {
    v4 = a2 + 4;
    v5 = a2 + 4;
    v6 = (unsigned int)&a2[4 * *a2 + 4];
    if ( (unsigned int)(a2 + 4) <= v6 )
    {
      do
      {
        if ( v5 <= v4 )
          v7 = a2 + 2;
        else
          v7 = v5 - 2;
        if ( *(_DWORD *)v7 )
          B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNodeFree(a1);
        v5 += 4;
      }
      while ( (unsigned int)v5 <= v6 );
    }
  }
  return ExFreePoolWithTag(a2);
}
