// PiCMHandleIoctl 
 
int __fastcall PiCMHandleIoctl(int a1, int a2, int a3, int a4, _DWORD *a5, unsigned int a6)
{
  *a5 = 0;
  if ( a6 > 0x47083F )
  {
    if ( a6 > 0x47085F )
    {
      switch ( a6 )
      {
        case 0x470863u:
          return PiCMOpenClassKey(a1, a2, a3, a4);
        case 0x470867u:
          return PiCMDeleteClassKey(a1, a2, a3, a4);
        case 0x47086Bu:
          return PiCMOpenObjectKey(a1, a2, a3, a4);
        case 0x47086Fu:
          return PiCMCreateObject(a1, a2, a3, a4);
        case 0x470873u:
          return PiCMDeleteObject(a1, a2, a3, a4);
        case 0x470877u:
          return PiCMGetObjectList(a1, a2, a3, a4);
      }
    }
    else
    {
      switch ( a6 )
      {
        case 0x47085Fu:
          return PiCMDeleteDeviceKey(a1, a2, a3, a4);
        case 0x470843u:
          return PiCMValidateDeviceInstance(a1, a2, a3, a4);
        case 0x470847u:
          return PiCMCreateDevice(a1, a2, a3, a4);
        case 0x47084Bu:
          return PiCMDeleteDevice(a1, a2, a3, a4);
        case 0x47084Fu:
          return PiCMDeviceAction(a1, a2, a3, a4);
        case 0x470853u:
          return PiCMOpenDeviceInterfaceKey(a1, a2, a3, a4);
        case 0x470857u:
          return PiCMDeleteDeviceInterfaceKey(a1, a2, a3, a4);
        case 0x47085Bu:
          return PiCMOpenDeviceKey(a1, a2, a3, a4);
      }
    }
    return -1073741637;
  }
  if ( a6 == 4655167 )
    return PiCMGetDeviceInterfaceAlias(a1, a2, a3, a4);
  if ( a6 > 0x47081F )
  {
    switch ( a6 )
    {
      case 0x470823u:
        return PiCMGetRelatedDeviceInstance(a1, a2, a3, a4);
      case 0x470827u:
        return PiCMGetDeviceStatus(a1, a2, a3, a4);
      case 0x47082Bu:
        return PiCMGetDeviceDepth(a1, a2, a3, a4);
      case 0x47082Fu:
        return PiCMSetDeviceProblem(a1, a2, a3, a4);
      case 0x470833u:
        return PiCMQueryRemove(a1, a2, a3, a4);
      case 0x470837u:
        return PiCMRegisterDeviceInterface(a1, a2, a3, a4);
      case 0x47083Bu:
        return PiCMUnregisterDeviceInterface(a1, a2, a3, a4);
    }
    return -1073741637;
  }
  switch ( a6 )
  {
    case 0x47081Fu:
      return PiCMSetRegistryProperty(a1, a2, a3, a4);
    case 0x470803u:
      return PiCMGetDeviceIdList(a1, a2, a3, a4);
    case 0x470807u:
      return PiCMGetDeviceInterfaceList(a1, a2, a3, a4);
  }
  if ( a6 != 4655115 )
  {
    switch ( a6 )
    {
      case 0x47080Fu:
        return sub_7C6E4C();
      case 0x470813u:
        return PiCMGetObjectProperty(a1, a2, a3, a4, a2, a5);
      case 0x470817u:
        return PiCMSetObjectProperty(a1, a2, a3, a4);
      case 0x47081Bu:
        return PiCMGetRegistryProperty(a1, a2, a3, a4);
    }
    return -1073741637;
  }
  return PiCMEnumerateSubKeys(a1, a2, a3, a4);
}
