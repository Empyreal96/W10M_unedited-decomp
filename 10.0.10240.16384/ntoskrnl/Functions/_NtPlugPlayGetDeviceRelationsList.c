// _NtPlugPlayGetDeviceRelationsList 
 
int __fastcall NtPlugPlayGetDeviceRelationsList(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // r0
  int v11[6]; // [sp+10h] [bp-18h] BYREF

  v11[0] = 0;
  result = PnpCtxGetNtPlugPlayRoutine(a1, 4, v11);
  if ( result >= 0 )
  {
    if ( v11[0] )
    {
      result = ((int (__fastcall *)(int, int, int, int, int, int, _DWORD))v11[0])(a1, a2, a3, a4, a5, a6, 0);
      if ( result == -2147483643 )
        result = -1073741789;
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
