// -BTreeIteratorAttachEx@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAUITERATOR@1@PAU1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorAttachEx(int *a1, int a2)
{
  int result; // r0

  result = *(_DWORD *)a2;
  *a1 = 0;
  a1[1] = 0;
  if ( result )
  {
    while ( !*(_BYTE *)(result + 3) )
    {
      if ( **(_DWORD **)(a2 + 8) == -1 || *(_BYTE *)(result + 2) != 2 )
      {
        result = *(_DWORD *)(result + 4);
      }
      else
      {
        result = (int)NP_CONTEXT::NpLeafRefInternal((struct NP_CONTEXT::NP_CTX *)(a2 + 8), (void **)(result + 4), 2u);
        if ( !result )
          return -1;
      }
    }
    *a1 = result;
    a1[1] = result - 8;
  }
  return result;
}
