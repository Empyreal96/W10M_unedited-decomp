// _PnpCtxGetObjectDispatchCallback 
 
int __fastcall PnpCtxGetObjectDispatchCallback(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  result = 0;
  if ( (unsigned int)(a2 - 1) > 9 )
    return -1073741811;
  *a3 = *(_DWORD *)(a1 + 4 * a2 + 64);
  return result;
}
