// PiDcContainerRequiresConfiguration 
 
int __fastcall PiDcContainerRequiresConfiguration(char *a1)
{
  int v2; // r4
  int v4; // [sp+20h] [bp-28h] BYREF
  int v5; // [sp+24h] [bp-24h] BYREF
  char v6[32]; // [sp+28h] [bp-20h] BYREF

  v4 = 0;
  v2 = 0;
  if ( !PnpIsNullGuidString(a1) )
  {
    v2 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           (int)a1,
           5,
           0,
           0,
           (int)DEVPKEY_DeviceContainer_ConfigFlags,
           (int)&v4,
           (int)&v5,
           4,
           (int)v6,
           0);
    if ( v2 < 0 || v4 != 7 || v5 != -1 )
    {
      v2 = PnpSetObjectProperty(
             PiPnpRtlCtx,
             (int)a1,
             5,
             0,
             0,
             (int)DEVPKEY_DeviceContainer_ConfigFlags,
             7,
             (int)&unconfiguredConfigFlags,
             4,
             0);
      if ( v2 >= 0 )
        ZwUpdateWnfStateData();
    }
  }
  return v2;
}
