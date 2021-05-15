// -BTreeInsert@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsert(int a1, _DWORD *a2, int a3)
{
  int result; // r0

  result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(a1, *a2);
  if ( result == -1073741275 )
    return B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(a1, a3, a2);
  if ( result >= 0 )
    result = -1073741484;
  return result;
}
