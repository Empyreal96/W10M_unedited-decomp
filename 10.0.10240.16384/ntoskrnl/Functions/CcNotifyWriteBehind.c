// CcNotifyWriteBehind 
 
int __fastcall CcNotifyWriteBehind(int result)
{
  char v1; // r4

  v1 = result;
  if ( CcInitializationComplete )
  {
    if ( (result & 1) != 0 )
    {
      result = sub_525138();
    }
    else
    {
      if ( (result & 2) != 0 )
        result = KeSetEvent(&CcPowerEvent, 0, 0);
      if ( (v1 & 4) != 0 )
        result = KeSetEvent(&CcPeriodicEvent, 0, 0);
      if ( (v1 & 8) != 0 )
        result = KeSetEvent(&CcWaitingForTeardownEvent, 0, 0);
      if ( (v1 & 0x10) != 0 )
        result = KeSetEvent(&CcCoalescingFlushEvent, 0, 0);
    }
  }
  return result;
}
