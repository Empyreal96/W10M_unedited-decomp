// -BTreeFindNextEntry@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAU_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@PAU1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindNextEntry(int a1, _DWORD *a2)
{
  int v2; // r2
  int v4; // r4
  __int64 v5; // r2
  int result; // r0
  int v7; // r6
  int v8; // r3

  v2 = a2[3];
  if ( !v2 )
    return 0;
  v4 = *a2 + 8 * v2;
  v5 = *(_QWORD *)(v4 - 8);
  result = HIDWORD(v5) + 16;
  *(_DWORD *)(v4 - 4) = HIDWORD(v5) + 16;
  v7 = *(unsigned __int16 *)v5;
  if ( HIDWORD(v5) + 16 < (unsigned int)(v5 + 16 * v7 + 8) )
    return result;
  HIDWORD(v5) = *(_WORD *)v5 ? v5 + 16 * v7 - 8 : (int)v5 + 8;
  *(_DWORD *)(v4 - 4) = HIDWORD(v5);
  v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSiblingEx(
         a1,
         a2,
         v5,
         SHIDWORD(v5));
  if ( !v8 )
    return 0;
  result = -1;
  if ( v8 != -1 )
  {
    result = v8 + 8;
    *(_DWORD *)(v4 - 4) = v8 + 8;
  }
  return result;
}
