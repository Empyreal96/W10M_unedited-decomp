// -BTreeNodeFindKey@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAKPAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@K@Z 
 
unsigned int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFindKey(unsigned __int16 *a1, unsigned int a2)
{
  int v3; // r3
  unsigned int result; // r0
  unsigned int v5; // r2
  unsigned __int16 *v6; // r4

  v3 = *((unsigned __int8 *)a1 + 3);
  result = *a1;
  v5 = -1;
  if ( v3 )
  {
    if ( result )
    {
      do
      {
        if ( *(_DWORD *)&a1[4 * ((result + v5) >> 1) + 4] >= a2 )
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
