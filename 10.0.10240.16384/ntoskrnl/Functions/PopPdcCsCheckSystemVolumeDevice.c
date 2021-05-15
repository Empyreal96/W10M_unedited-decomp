// PopPdcCsCheckSystemVolumeDevice 
 
void PopPdcCsCheckSystemVolumeDevice()
{
  bool v0; // r2

  if ( PopPlatformAoAc )
  {
    if ( ZwOpenFile() >= 0 )
      ZwDeviceIoControlFile();
    PopPdcCsDeviceNotification();
    PopAcquirePolicyLock();
    v0 = !PopEnforceDisconnectedStandby && PopConnectedStandbyComplianceChecks();
    byte_61EA57 = v0;
    PopReleasePolicyLock();
  }
}
