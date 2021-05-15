// PiDcHandleSystemFirmwareUpdate 
 
int PiDcHandleSystemFirmwareUpdate()
{
  return PiDcContainerRequiresConfiguration((char *)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}");
}
