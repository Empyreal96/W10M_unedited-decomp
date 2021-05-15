// IoControlPnpDeviceActionQueue 
 
int __fastcall IoControlPnpDeviceActionQueue(int a1)
{
  int result; // r0

  if ( a1 )
    result = PnpLockDeviceActionQueue();
  else
    result = PnpUnlockDeviceActionQueue();
  return result;
}
