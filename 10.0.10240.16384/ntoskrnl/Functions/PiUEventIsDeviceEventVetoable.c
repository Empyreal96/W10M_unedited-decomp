// PiUEventIsDeviceEventVetoable 
 
BOOL __fastcall PiUEventIsDeviceEventVetoable(int a1)
{
  return PnpCompareGuid(a1 + 64, &GUID_TARGET_DEVICE_QUERY_REMOVE)
      || PnpCompareGuid(a1 + 64, &GUID_DEVICE_KERNEL_INITIATED_EJECT);
}
