// PiDrvDbNodeActionCallback 
 
int __fastcall PiDrvDbNodeActionCallback(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int result; // r0

  result = 0;
  if ( (*(_DWORD *)(a6 + 32) & 4) == 0 )
    return -1073741822;
  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
      if ( a4 == 1 )
        result = PiDrvDbUnloadNode(a6, *a5);
      return result;
    }
    return -1073741822;
  }
  if ( a4 == 1 )
    result = PiDrvDbLoadNode(a6, *a5);
  return result;
}
