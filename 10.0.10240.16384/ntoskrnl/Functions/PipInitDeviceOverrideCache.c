// PipInitDeviceOverrideCache 
 
int PipInitDeviceOverrideCache()
{
  int v1[4]; // [sp+4h] [bp-280h] BYREF
  __int16 v2; // [sp+14h] [bp-270h]
  __int16 v3; // [sp+16h] [bp-26Eh]
  const __int16 *v4; // [sp+18h] [bp-26Ch]

  v1[0] = 0;
  v3 = 134;
  v2 = 132;
  v4 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides";
  if ( IopOpenRegistryKeyEx(v1) != -1073741772 )
    return sub_9685C0();
  if ( v1[0] )
    ZwClose();
  return 0;
}
