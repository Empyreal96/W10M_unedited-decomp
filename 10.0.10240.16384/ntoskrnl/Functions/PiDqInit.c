// PiDqInit 
 
int PiDqInit()
{
  int result; // r0

  PiDqObjectManagerInit((int)&PiDqDeviceManager, 1);
  PiDqObjectManagerInit((int)&PiDqDeviceInterfaceManager, 3);
  PiDqObjectManagerInit((int)&PiDqDeviceInterfaceClassManager, 4);
  PiDqObjectManagerInit((int)&PiDqDeviceContainerManager, 5);
  PiDqObjectManagerInit((int)&PiDqDeviceInstallerClassManager, 2);
  __dmb(0xBu);
  result = 0;
  PiDqSequenceNumber[0] = 0i64;
  return result;
}
