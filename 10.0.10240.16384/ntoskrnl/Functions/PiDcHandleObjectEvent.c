// PiDcHandleObjectEvent 
 
int __fastcall PiDcHandleObjectEvent(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r3

  v2 = *(_DWORD *)(a1 + 4);
  result = 0;
  if ( (v2 & 2) == 0 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 20);
    switch ( v4 )
    {
      case 1:
        result = PiDcHandleDeviceEvent(a1);
        break;
      case 3:
        result = PiDcHandleInterfaceEvent(a1);
        break;
      case 5:
        result = PiDcHandleContainerEvent(a1);
        break;
    }
  }
  return result;
}
