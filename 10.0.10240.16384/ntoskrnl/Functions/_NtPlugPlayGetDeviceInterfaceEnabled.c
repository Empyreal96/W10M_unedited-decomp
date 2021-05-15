// _NtPlugPlayGetDeviceInterfaceEnabled 
 
int __fastcall NtPlugPlayGetDeviceInterfaceEnabled(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  result = PnpCtxGetNtPlugPlayRoutine(a1, 5, v8);
  if ( result >= 0 )
  {
    if ( v8[0] )
      result = ((int (__fastcall *)(int, int, int, _DWORD))v8[0])(a1, a2, a3, 0);
    else
      result = -1073741822;
  }
  return result;
}
