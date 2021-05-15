// PnpProcessTargetDeviceEvent 
 
int __fastcall PnpProcessTargetDeviceEvent(int *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  int v6; // r5
  int v8; // r6
  int v10[8]; // [sp+8h] [bp-20h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = *a1;
  v10[0] = 0;
  v5 = *(_DWORD *)(v4 + 96);
  v6 = 0;
  if ( v5 )
  {
    v5 = *(_DWORD *)(v5 + 176);
    v8 = *(_DWORD *)(v5 + 20);
  }
  else
  {
    v8 = 0;
  }
  PiPnpRtlBeginOperation(v10, a2, a3, v5);
  if ( PnpCompareGuid((unsigned __int8 *)(v4 + 64), (int)&GUID_DEVICE_QUERY_AND_REMOVE)
    || PnpCompareGuid((unsigned __int8 *)(v4 + 64), (int)&GUID_DEVICE_EJECT) )
  {
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
      return sub_7CBE18();
    v6 = PnpProcessQueryRemoveAndEject(a1);
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
      Template_z(
        Microsoft_Windows_Kernel_PnPHandle,
        MEMORY[0x649E54],
        (int)KMPnPEvt_DeviceRemoval_Stop,
        *(_DWORD *)(v8 + 24),
        *(unsigned __int16 **)(v8 + 24));
  }
  else if ( PnpCompareGuid((unsigned __int8 *)(v4 + 64), (int)&GUID_DEVICE_ARRIVAL) )
  {
    PiUEventNotifyUserMode((_DWORD *)v4);
  }
  else if ( PnpCompareGuid((unsigned __int8 *)(v4 + 64), (int)&GUID_DEVICE_NOOP) )
  {
    v6 = 0;
  }
  if ( v10[0] )
    PiPnpRtlEndOperation(v10[0]);
  return v6;
}
