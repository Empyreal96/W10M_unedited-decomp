// PiDqGetObjectManagerForPnpObjectType 
 
void *__fastcall PiDqGetObjectManagerForPnpObjectType(int a1)
{
  void *result; // r0

  result = 0;
  switch ( a1 )
  {
    case 1:
      return &PiDqDeviceManager;
    case 3:
      return &PiDqDeviceInterfaceManager;
    case 2:
      return &PiDqDeviceInstallerClassManager;
    case 4:
      return &PiDqDeviceInterfaceClassManager;
    case 5:
      result = &PiDqDeviceContainerManager;
      break;
  }
  return result;
}
