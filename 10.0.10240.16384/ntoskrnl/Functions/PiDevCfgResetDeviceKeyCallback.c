// PiDevCfgResetDeviceKeyCallback 
 
int __fastcall PiDevCfgResetDeviceKeyCallback(int a1, int a2, int *a3, int a4, int a5)
{
  int result; // r0

  if ( a3[3] != 16 || wcsicmp(*a3, L"Properties") )
    result = PiDevCfgCopyDeviceKeys(a4, a5, 0, 0);
  else
    result = PiDevCfgCopyDeviceKey(a4, a5, *(_DWORD *)(a2 + 4), 1, 0, 0, 0);
  return result;
}
