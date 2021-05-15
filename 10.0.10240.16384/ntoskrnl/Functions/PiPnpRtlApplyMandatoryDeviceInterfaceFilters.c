// PiPnpRtlApplyMandatoryDeviceInterfaceFilters 
 
int __fastcall PiPnpRtlApplyMandatoryDeviceInterfaceFilters(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v7; // r5
  unsigned int v8; // r4
  int v10; // [sp+4h] [bp-3Ch]
  int v11; // [sp+20h] [bp-20h] BYREF
  int v12; // [sp+24h] [bp-1Ch] BYREF
  char v13[24]; // [sp+28h] [bp-18h] BYREF

  v11 = 0;
  v7 = PnpGetObjectProperty(
         1198550608,
         200,
         a2,
         3,
         a3,
         v10,
         (int)DEVPKEY_Device_InstanceId,
         (int)v13,
         (unsigned int *)&v11,
         &v12,
         0);
  v8 = v11;
  if ( v7 >= 0 )
    v7 = PiPnpRtlApplyMandatoryDeviceFilters(a1, v11, 0, a4, a5);
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
