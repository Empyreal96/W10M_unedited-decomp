// _PnpCtxGetNtPlugPlayRoutine 
 
int __fastcall PnpCtxGetNtPlugPlayRoutine(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  result = 0;
  if ( a2 >= 6 )
    return -1073741811;
  *a3 = *(_DWORD *)(a1 + 4 * a2 + 40);
  return result;
}
