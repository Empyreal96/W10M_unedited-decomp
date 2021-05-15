// -BTreeSearchKey@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@T_SM_PAGE_KEY@@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(unsigned __int16 **a1, unsigned int a2, int a3, int a4)
{
  int v6; // r7
  _DWORD *v7; // r5
  unsigned __int16 *v9; // r4
  unsigned int v10; // r9
  unsigned int v11; // r0
  void **v12; // r1
  unsigned int v13; // r2
  unsigned __int16 *v14; // r2
  unsigned __int16 **varg_r0; // [sp+20h] [bp+8h]
  int varg_r2; // [sp+28h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a3);
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
  if ( !*a1 )
  {
    if ( !v6 )
    {
      *v7 = 0;
      v7[1] = 0;
    }
    return -1073741275;
  }
LABEL_12:
  v10 = a2;
  while ( 1 )
  {
    v11 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNodeFindKey(v9, v10);
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
      v12 = (void **)&v9[4 * v11 + 2];
    else
      v12 = (void **)(v9 + 2);
    if ( *(_DWORD *)a1[2] != -1 && *((_BYTE *)v9 + 2) == 2 )
    {
      if ( (*(_DWORD *)(a3 + 20) & 1) != 0 )
        v13 = 2;
      else
        v13 = 0;
      v9 = (unsigned __int16 *)NP_CONTEXT::NpLeafRefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 2), v12, v13);
      if ( !v9 )
        return -1073741818;
      goto LABEL_12;
    }
    v9 = (unsigned __int16 *)*v12;
  }
  v14 = &v9[8 * v11 + 4];
  *v7 = v9;
  v7[1] = v14;
  if ( v6 )
    *(_DWORD *)(a3 + 12) = (((int)v7 - *(_DWORD *)a3) >> 3) + 1;
  if ( v11 >= *v9 || *(_DWORD *)v14 != a2 )
    return -1073741275;
  return 0;
}
