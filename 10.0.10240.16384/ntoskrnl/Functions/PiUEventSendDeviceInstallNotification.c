// PiUEventSendDeviceInstallNotification 
 
int PiUEventSendDeviceInstallNotification()
{
  int result; // r0

  result = ZwUpdateWnfStateData();
  if ( result >= 0 && (Microsoft_Windows_Kernel_PnPEnableBits & 0x80000) != 0 )
    result = sub_81C054();
  return result;
}
