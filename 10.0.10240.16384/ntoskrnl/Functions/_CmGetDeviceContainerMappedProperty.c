// _CmGetDeviceContainerMappedProperty 
 
int __fastcall CmGetDeviceContainerMappedProperty(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6, _BYTE *a7, int a8, _DWORD *a9)
{
  int v10; // r4
  int v13; // r5

  v10 = -1073741802;
  *a9 = 0;
  if ( a4 )
    return v10;
  v13 = *(_DWORD *)(a5 + 16);
  if ( v13 != 70 || memcmp(a5, (unsigned int)DEVPKEY_DeviceContainer_IsLocalMachine, 16) )
  {
    if ( v13 == 83 && !memcmp(a5, (unsigned int)DEVPKEY_DeviceContainer_HasProblem, 16) )
      return CmGetContainerBooleanProperty(a1, a2, a3, DEVPKEY_Device_HasProblem, a6, a7, a8, a9);
    if ( v13 == 55 && !memcmp(a5, (unsigned int)DEVPKEY_DeviceContainer_IsConnected, 16) )
      return CmGetContainerBooleanProperty(a1, a2, a3, DEVPKEY_Device_IsConnected, a6, a7, a8, a9);
    if ( v13 != 108 || memcmp(a5, (unsigned int)DEVPKEY_DeviceContainer_IsRebootRequired, 16) )
      return v10;
    return CmGetContainerBooleanProperty(a1, a2, a3, DEVPKEY_Device_IsRebootRequired, a6, a7, a8, a9);
  }
  *a6 = 17;
  *a9 = 1;
  if ( !a8 )
    return -1073741789;
  if ( CmIsLocalMachineContainer(a1, a2) )
  {
    *a7 = -1;
    return 0;
  }
  return sub_7EEAB4();
}
