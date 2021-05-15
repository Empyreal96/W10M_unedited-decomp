// _CmIsDeviceInterfaceEnabled 
 
int __fastcall CmIsDeviceInterfaceEnabled(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int result; // r0
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  result = RtlInitUnicodeStringEx((int)v7, a2);
  if ( result >= 0 )
    result = NtPlugPlayGetDeviceInterfaceEnabled(a1, v7, a4);
  return result;
}
