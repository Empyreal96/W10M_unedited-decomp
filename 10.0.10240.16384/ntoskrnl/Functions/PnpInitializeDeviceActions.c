// PnpInitializeDeviceActions 
 
int PnpInitializeDeviceActions()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 0;
  do
    v1 = __ldrex((unsigned int *)&PnpDeviceActionThread);
  while ( __strex(0, (unsigned int *)&PnpDeviceActionThread) );
  __dmb(0xBu);
  PnpEnumerationInProgress = 0;
  PnpEnumerationLock = 0;
  byte_62FB91 = 0;
  byte_62FB92 = 4;
  dword_62FB94 = 1;
  dword_62FB9C = (int)&dword_62FB98;
  dword_62FB98 = (int)&dword_62FB98;
  PnpEnumerationRequestList = (int)&PnpEnumerationRequestList;
  dword_62FB84 = (int)&PnpEnumerationRequestList;
  return result;
}
