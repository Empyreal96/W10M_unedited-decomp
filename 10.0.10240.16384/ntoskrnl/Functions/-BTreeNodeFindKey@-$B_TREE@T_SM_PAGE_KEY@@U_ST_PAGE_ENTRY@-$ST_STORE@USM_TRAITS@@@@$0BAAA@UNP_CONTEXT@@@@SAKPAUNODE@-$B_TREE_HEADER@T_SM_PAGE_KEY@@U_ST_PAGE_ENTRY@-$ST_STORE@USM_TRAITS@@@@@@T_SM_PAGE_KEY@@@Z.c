// -BTreeNodeFindKey@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAKPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@T_SM_PAGE_KEY@@@Z 
 
unsigned int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNodeFindKey(unsigned __int16 *a1, unsigned int a2)
{
  int v3; // r3
  unsigned int result; // r0
  unsigned int v5; // r2
  unsigned __int16 *v6; // r4
  unsigned __int16 *_18; // [sp+18h] [bp+8h]

  _18 = a1;
  v3 = *((unsigned __int8 *)a1 + 3);
  result = *a1;
  v5 = -1;
  if ( v3 )
  {
    if ( result )
    {
      do
      {
        if ( *(_DWORD *)&a1[8 * ((result + v5) >> 1) + 4] >= a2 )
          result = (result + v5) >> 1;
        else
          v5 = (result + v5) >> 1;
      }
      while ( v5 + 1 != result );
    }
  }
  else
  {
    v6 = a1 + 4;
    if ( result )
    {
      do
      {
        if ( a2 < *(_DWORD *)&v6[4 * ((result + v5) >> 1)] )
          result = (result + v5) >> 1;
        else
          v5 = (result + v5) >> 1;
      }
      while ( v5 + 1 != result );
    }
  }
  return result;
}
