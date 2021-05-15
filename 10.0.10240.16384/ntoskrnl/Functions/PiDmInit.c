// PiDmInit 
 
int PiDmInit()
{
  int result; // r0
  unsigned int i; // r4

  PiDmObjectManagerInit((int)&PiDmDeviceManager, 1);
  PiDmObjectManagerInit((int)&PiDmDeviceInterfaceManager, 3);
  PiDmObjectManagerInit((int)&PiDmDeviceInterfaceClassManager, 4);
  PiDmObjectManagerInit((int)&PiDmDeviceContainerManager, 5);
  PiDmObjectManagerInit((int)&PiDmDeviceInstallerClassManager, 2);
  result = PiDmObjectManagerPopulate((int)&PiDmDeviceManager);
  if ( result >= 0 )
  {
    result = PiDmObjectManagerPopulate((int)&PiDmDeviceInterfaceManager);
    if ( result >= 0 )
    {
      result = PiDmObjectManagerPopulate((int)&PiDmDeviceInterfaceClassManager);
      if ( result >= 0 )
      {
        result = PiDmObjectManagerPopulate((int)&PiDmDeviceContainerManager);
        if ( result >= 0 )
        {
          result = PiDmObjectManagerPopulate((int)&PiDmDeviceInstallerClassManager);
          if ( result >= 0 )
          {
            for ( i = 0; i < 5; ++i )
            {
              result = PiDmListInit(i);
              if ( result < 0 )
                break;
            }
          }
        }
      }
    }
  }
  return result;
}
