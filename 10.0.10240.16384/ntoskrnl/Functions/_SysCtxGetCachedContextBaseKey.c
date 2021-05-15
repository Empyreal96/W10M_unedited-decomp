// _SysCtxGetCachedContextBaseKey 
 
int __fastcall SysCtxGetCachedContextBaseKey(int a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v5; // r3

  result = 0;
  if ( a2 == 4 )
  {
    v5 = *(_DWORD *)(a1 + 24);
  }
  else
  {
    if ( a2 != 1 )
      return sub_7C6B30(0, a2, a3, a1);
    v5 = *(_DWORD *)(a1 + 12);
  }
  if ( !v5 )
    return -1073741772;
  *a3 = v5;
  return result;
}
