// PiUEventShouldQueueEvent 
 
int __fastcall PiUEventShouldQueueEvent(int a1)
{
  int result; // r0
  int v3; // r3
  int *v4; // r3

  result = 1;
  if ( !PiUEventBroadcastSubscriberPresent )
  {
    v3 = *(_DWORD *)(a1 + 80);
    switch ( v3 )
    {
      case 2:
        v4 = &PiUEventDevInterfaceClientCount;
        return *v4 != 0;
      case 4:
        goto LABEL_9;
      case 1:
      case 3:
        v4 = &PiUEventDevHandleClientCount;
        return *v4 != 0;
      case 9:
        v4 = &PiUEventDevInstancePropertyClientCount;
        return *v4 != 0;
    }
    if ( v3 > 9 && v3 <= 11 )
    {
LABEL_9:
      v4 = &PiUEventDevInstanceClientCount;
      return *v4 != 0;
    }
  }
  return result;
}
