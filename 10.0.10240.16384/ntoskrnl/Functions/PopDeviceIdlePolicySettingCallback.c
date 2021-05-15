// PopDeviceIdlePolicySettingCallback 
 
int __fastcall PopDeviceIdlePolicySettingCallback(unsigned int a1, int *a2, int a3)
{
  int result; // r0

  if ( memcmp((unsigned int)&GUID_DEVICE_IDLE_POLICY, a1, 16) || a3 != 4 || !a2 || (unsigned int)*a2 > 1 )
    return -1073741811;
  result = 0;
  dword_61EC28 = *a2;
  return result;
}
