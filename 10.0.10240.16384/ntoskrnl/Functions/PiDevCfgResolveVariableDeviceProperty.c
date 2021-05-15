// PiDevCfgResolveVariableDeviceProperty 
 
int __fastcall PiDevCfgResolveVariableDeviceProperty(int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r9
  unsigned int v5; // [sp+24h] [bp-50h] BYREF
  _DWORD v6[18]; // [sp+2Ch] [bp-48h] BYREF

  v5 = 0;
  v6[0] = 0;
  v6[1] = 0;
  v2 = IopGetRegistryValue(a2, L"PropertyGuid", 0, &v5);
  if ( v2 >= 0 )
    return sub_7EB5F0();
  v4 = v5;
  RtlFreeAnsiString(v6);
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v2;
}
