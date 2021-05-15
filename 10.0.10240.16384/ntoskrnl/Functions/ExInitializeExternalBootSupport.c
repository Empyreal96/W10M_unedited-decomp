// ExInitializeExternalBootSupport 
 
int ExInitializeExternalBootSupport()
{
  ExNumMissingBootDevices = 0;
  ExBootDeviceRemovalHandler = 0;
  ExBootDeviceList = &ExBootDeviceList;
  dword_61A204 = (int)&ExBootDeviceList;
  ExBootDeviceListSpinLock = 0;
  ExBootDevicesRemovedEvent = 1;
  byte_61A221 = 0;
  byte_61A222 = 4;
  dword_61A224 = 0;
  dword_61A22C = (int)&dword_61A228;
  dword_61A228 = (int)&dword_61A228;
  ExExternalBootSupportInitializationEvent = 1;
  byte_61A231 = 0;
  byte_61A232 = 4;
  dword_61A234 = 1;
  dword_61A23C = (int)&dword_61A238;
  dword_61A238 = (int)&dword_61A238;
  return 0;
}
