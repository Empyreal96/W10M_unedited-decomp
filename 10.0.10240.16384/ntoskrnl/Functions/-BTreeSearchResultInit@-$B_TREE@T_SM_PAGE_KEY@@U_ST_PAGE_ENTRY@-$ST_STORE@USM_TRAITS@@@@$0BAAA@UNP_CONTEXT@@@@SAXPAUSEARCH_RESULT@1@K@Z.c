// -BTreeSearchResultInit@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAXPAUSEARCH_RESULT@1@K@Z 
 
_BYTE *__fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultInit(int a1, char a2)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 24);
  if ( (a2 & 1) == 0 )
    *(_DWORD *)(a1 + 12) = -1;
  if ( (a2 & 2) != 0 )
    result = (_BYTE *)sub_509D58();
  return result;
}
