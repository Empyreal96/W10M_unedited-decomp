// PiDcGenerateConfigNotificationIfContainerRequiresConfiguration 
 
int __fastcall PiDcGenerateConfigNotificationIfContainerRequiresConfiguration(int a1)
{
  int v2; // r4
  int result; // r0
  char v4[4]; // [sp+20h] [bp-28h] BYREF
  int v5; // [sp+24h] [bp-24h] BYREF
  char v6[4]; // [sp+28h] [bp-20h] BYREF
  int v7[7]; // [sp+2Ch] [bp-1Ch] BYREF

  v5 = 0;
  v4[0] = 0;
  v2 = PnpGetObjectProperty(
         PiPnpRtlCtx,
         a1,
         5,
         0,
         0,
         (int)DEVPKEY_DeviceContainer_IsConnected,
         (int)&v5,
         (int)v4,
         1,
         (int)v6,
         0);
  if ( v2 < 0 || v5 != 17 || !v4[0] )
    goto LABEL_8;
  v2 = PnpGetObjectProperty(
         PiPnpRtlCtx,
         a1,
         5,
         0,
         0,
         (int)DEVPKEY_DeviceContainer_ConfigFlags,
         (int)&v5,
         (int)v7,
         4,
         (int)v6,
         0);
  if ( v2 < 0 )
    goto LABEL_5;
  if ( v5 != 7 )
    JUMPOUT(0x7EFF5E);
  if ( v7[0] )
LABEL_5:
    result = sub_7EFF58();
  else
LABEL_8:
    result = v2;
  return result;
}
