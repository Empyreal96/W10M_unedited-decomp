// _NtPlugPlayGetDeviceStatus 
 
int __fastcall NtPlugPlayGetDeviceStatus(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = 0;
  result = PnpCtxGetNtPlugPlayRoutine(a1, 2, v9);
  if ( result >= 0 )
  {
    if ( v9[0] )
    {
      result = ((int (__fastcall *)(int, int, int, int))v9[0])(a1, a2, a3, a4);
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
