// PiDmGetObjectManagerForObjectType 
 
void *__fastcall PiDmGetObjectManagerForObjectType(int a1)
{
  void *result; // r0

  result = 0;
  switch ( a1 )
  {
    case 1:
      return &PiDmDeviceManager;
    case 3:
      return &PiDmDeviceInterfaceManager;
    case 4:
      return &PiDmDeviceInterfaceClassManager;
    case 2:
      return &PiDmDeviceInstallerClassManager;
    case 5:
      result = &PiDmDeviceContainerManager;
      break;
  }
  return result;
}
