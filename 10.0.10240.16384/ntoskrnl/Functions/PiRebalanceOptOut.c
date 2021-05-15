// PiRebalanceOptOut 
 
int __fastcall PiRebalanceOptOut(int a1)
{
  int v2; // r4
  char v4[4]; // [sp+20h] [bp-80h] BYREF
  int v5; // [sp+24h] [bp-7Ch] BYREF
  int v6; // [sp+28h] [bp-78h] BYREF
  int v7[3]; // [sp+2Ch] [bp-74h] BYREF
  char v8[104]; // [sp+38h] [bp-68h] BYREF

  v6 = 0;
  v7[0] = 0;
  v5 = 0;
  v4[0] = 0;
  v2 = 0;
  if ( PnpGetObjectProperty(
         PiPnpRtlCtx,
         *(_DWORD *)(a1 + 24),
         1,
         0,
         0,
         DEVPKEY_Device_DHP_Rebalance_Policy,
         &v5,
         v7,
         4,
         &v6,
         0) < 0
    || v5 != 7 )
  {
    goto LABEL_5;
  }
  if ( v7[0] == 1 )
    return 1;
  if ( v7[0] != 2 )
  {
LABEL_5:
    v7[1] = 0;
    if ( IoGetDeviceProperty(*(_DWORD *)(a1 + 16)) >= 0
      && PnpGetObjectProperty(PiPnpRtlCtx, v8, 2, 0, 0, DEVPKEY_DeviceClass_DHPRebalanceOptOut, &v5, v4, 1, &v6, 0) >= 0
      && v5 == 17
      && v6 == 1
      && v4[0] == -1 )
    {
      return 1;
    }
  }
  return v2;
}
