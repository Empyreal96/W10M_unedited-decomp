// -BTreeSearchKey@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@KPAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(unsigned __int16 **a1, unsigned int a2, int a3)
{
  int v6; // r7
  _DWORD *v7; // r5
  unsigned __int16 *v9; // r4
  unsigned int v10; // r0
  void **v11; // r1
  unsigned int v12; // r2
  unsigned __int16 *v13; // r2

  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a3);
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
  while ( 1 )
  {
    v10 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFindKey(v9, a2);
    if ( *((_BYTE *)v9 + 3) )
      break;
    if ( v6 )
    {
      *v7 = v9;
      v7[1] = &v9[4 * v10 + 4];
      v7 += 2;
    }
    if ( v10 )
      v11 = (void **)&v9[4 * v10 + 2];
    else
      v11 = (void **)(v9 + 2);
    if ( *(_DWORD *)a1[2] == -1 || *((_BYTE *)v9 + 2) != 2 )
    {
      v9 = (unsigned __int16 *)*v11;
    }
    else
    {
      if ( (*(_DWORD *)(a3 + 20) & 1) != 0 )
        v12 = 2;
      else
        v12 = 0;
      v9 = (unsigned __int16 *)NP_CONTEXT::NpLeafRefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 2), v11, v12);
      if ( !v9 )
        return -1073741818;
    }
  }
  v13 = &v9[4 * v10 + 4];
  *v7 = v9;
  v7[1] = v13;
  if ( v6 )
    *(_DWORD *)(a3 + 12) = (((int)v7 - *(_DWORD *)a3) >> 3) + 1;
  if ( v10 >= *v9 || *(_DWORD *)v13 != a2 )
    return -1073741275;
  return 0;
}
