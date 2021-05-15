// -BTreeDescendToSibling@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAUPATH_ENTRY@1@KPAUSEARCH_RESULT@1@@Z 
 
_DWORD *__fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(int *a1, int a2, _DWORD *a3)
{
  int v3; // r0
  int v4; // r4
  _DWORD *v5; // r2
  _DWORD *v6; // r1
  int i; // r4

  v4 = a1[1];
  v3 = *a1;
  if ( a3 )
    v5 = (_DWORD *)(*a3 + 8 * (a3[3] - *(unsigned __int8 *)(v3 + 2)));
  else
    v5 = 0;
  v6 = (_DWORD *)(v4 + 4);
  for ( i = v4 + 8; ; i = v3 + 8 )
  {
    if ( v5 )
    {
      *v5 = v3;
      v5[1] = i;
      v5 += 2;
    }
    if ( *(_BYTE *)(v3 + 2) == 2 )
      break;
    v3 = *v6;
    v6 = (_DWORD *)(*v6 + 4);
  }
  return v6;
}
