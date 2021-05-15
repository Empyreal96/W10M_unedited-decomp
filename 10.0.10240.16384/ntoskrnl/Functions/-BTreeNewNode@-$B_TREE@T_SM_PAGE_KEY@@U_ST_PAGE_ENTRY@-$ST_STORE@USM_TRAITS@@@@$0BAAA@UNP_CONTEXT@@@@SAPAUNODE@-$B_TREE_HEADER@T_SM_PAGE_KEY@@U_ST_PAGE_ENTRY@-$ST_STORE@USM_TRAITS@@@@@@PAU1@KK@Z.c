// -BTreeNewNode@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@KK@Z 
 
_BYTE *__fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(int a1, char a2, char a3)
{
  struct NP_CONTEXT::NP_CTX *v5; // r0
  _BYTE *v6; // r0
  _BYTE *v7; // r4

  if ( a1 )
    v5 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
  else
    v5 = 0;
  v6 = NP_CONTEXT::NpNodeAllocate(v5, a2, a2);
  v7 = v6;
  if ( v6 )
  {
    memset(v6, 0, 4096);
    v7[2] = a3;
    v7[3] = a2;
  }
  return v7;
}
