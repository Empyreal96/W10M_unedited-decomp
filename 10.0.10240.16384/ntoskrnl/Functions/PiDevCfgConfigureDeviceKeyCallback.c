// PiDevCfgConfigureDeviceKeyCallback 
 
int __fastcall PiDevCfgConfigureDeviceKeyCallback(int a1, int a2, int *a3, int a4, int a5, int a6)
{
  int result; // r0
  int v11; // [sp+Ch] [bp-Ch]

  v11 = a4;
  if ( a3[3] != 16 || wcsicmp(*a3, L"Properties") )
    result = PiDevCfgCopyDeviceKeys(a4, a5, 1, a6, a1, a2, a3, v11);
  else
    result = sub_7E4944();
  return result;
}
