// PiUEventSendDeviceInterfaceArrivalETWEvent 
 
_BYTE *PiUEventSendDeviceInterfaceArrivalETWEvent()
{
  _BYTE *result; // r0
  char v1[56]; // [sp+44h] [bp-A8h] BYREF

  result = memset(v1, 0, sizeof(v1));
  if ( (Microsoft_Windows_PnPMgrTriggerProviderEnableBits & 1) != 0 )
    result = (_BYTE *)sub_7EF850(result);
  return result;
}
