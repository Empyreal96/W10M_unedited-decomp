// PiCreateDriverSwDevices 
 
int __fastcall PiCreateDriverSwDevices(int a1)
{
  int v1; // r4
  int v2; // r0

  v1 = PnpDeviceObjectToDeviceInstance(*(_DWORD *)(a1 + 16));
  if ( v1 >= 0 )
  {
    v2 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, (int)L"Devices", 0);
    v1 = v2;
    if ( v2 >= 0 )
      return sub_7CBE44();
    if ( v2 == -1073741772 )
      v1 = 0;
  }
  return v1;
}
