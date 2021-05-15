// -BTreeFindSeperatorIndexEntry@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAKPAUSEARCH_RESULT@1@KPAUPATH_ENTRY@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned __int16 **i; // r4
  int v4; // r3

  for ( i = (unsigned __int16 **)(*a1 + 8 * (a1[3] - 2)); (unsigned int)i >= *a1; i -= 2 )
  {
    if ( a2 )
    {
      if ( i[1] < &(*i)[4 * **i + 4] )
      {
        *a3 = *i;
        v4 = (int)i[1];
LABEL_5:
        a3[1] = v4;
        return 1;
      }
    }
    else if ( i[1] > *i + 4 )
    {
      *a3 = *i;
      v4 = (int)(i[1] - 4);
      goto LABEL_5;
    }
  }
  return 0;
}
