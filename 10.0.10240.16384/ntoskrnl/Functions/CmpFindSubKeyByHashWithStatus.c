// CmpFindSubKeyByHashWithStatus 
 
int __fastcall CmpFindSubKeyByHashWithStatus(int a1, int a2, int a3, _DWORD *a4)
{
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r6
  int result; // r0

  v7 = CmpComputeHashKey(0, a3);
  v8 = *(unsigned __int16 *)(a2 + 2);
  v9 = 0;
  *a4 = -1;
  if ( !v8 )
    return -1073741772;
  while ( 1 )
  {
    v10 = a2 + 8 * v9;
    if ( v7 == *(_DWORD *)(v10 + 8) )
      break;
    v9 = (unsigned __int16)(v9 + 1);
    if ( v9 >= *(unsigned __int16 *)(a2 + 2) )
      return -1073741772;
  }
  if ( CmpDoCompareKeyName(a1, a3, *(_DWORD *)(v10 + 4)) )
    return sub_7BEFB8();
  result = 0;
  *a4 = *(_DWORD *)(a2 + 8 * v9 + 4);
  return result;
}
