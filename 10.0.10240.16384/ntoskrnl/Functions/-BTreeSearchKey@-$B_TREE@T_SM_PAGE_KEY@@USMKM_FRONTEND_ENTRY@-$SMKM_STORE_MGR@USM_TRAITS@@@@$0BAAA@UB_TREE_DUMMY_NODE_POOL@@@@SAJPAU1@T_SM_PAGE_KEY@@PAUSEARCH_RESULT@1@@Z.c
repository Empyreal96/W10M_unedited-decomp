// -BTreeSearchKey@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAJPAU1@T_SM_PAGE_KEY@@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(unsigned __int16 **a1, int a2, int a3, int a4)
{
  int v6; // r7
  _DWORD *v7; // r4
  unsigned __int16 *v9; // r5
  int v10; // r8
  unsigned int v11; // r0
  unsigned __int16 *v12; // r3
  unsigned __int16 *v13; // r2
  unsigned __int16 **varg_r0; // [sp+20h] [bp+8h]
  int varg_r2; // [sp+28h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref();
  if ( *(_DWORD *)(a3 + 12) == -1 )
  {
    v6 = 0;
    v7 = (_DWORD *)(a3 + 4);
  }
  else
  {
    v6 = 1;
    if ( *a1 && *(_DWORD *)(a3 + 16) < (unsigned int)*((unsigned __int8 *)*a1 + 2) && !SmArrayGrow() )
      return -1073741670;
    v7 = *(_DWORD **)a3;
  }
  v9 = *a1;
  if ( !v9 )
  {
    if ( !v6 )
    {
      *v7 = 0;
      v7[1] = 0;
    }
    return -1073741275;
  }
  v10 = a2;
  while ( 1 )
  {
    v11 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNodeFindKey(
            v9,
            v10);
    if ( *((_BYTE *)v9 + 3) )
      break;
    if ( v6 )
    {
      *v7 = v9;
      v7[1] = &v9[4 * v11 + 4];
      v10 = a2;
      v7 += 2;
    }
    if ( v11 )
      v12 = &v9[4 * v11 + 2];
    else
      v12 = v9 + 2;
    v9 = *(unsigned __int16 **)v12;
  }
  v13 = &v9[4 * v11 + 4];
  *v7 = v9;
  v7[1] = v13;
  if ( v6 )
    *(_DWORD *)(a3 + 12) = (((int)v7 - *(_DWORD *)a3) >> 3) + 1;
  if ( v11 >= *v9 || *(_DWORD *)v13 != a2 )
    return -1073741275;
  return 0;
}
