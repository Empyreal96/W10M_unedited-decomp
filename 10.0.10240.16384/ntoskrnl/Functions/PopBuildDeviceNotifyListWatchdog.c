// PopBuildDeviceNotifyListWatchdog 
 
void __fastcall __noreturn PopBuildDeviceNotifyListWatchdog(int a1, int a2)
{
  KeSetEvent(a2, 0, 0);
  PnpBugcheckPowerTimeout(PopWatchdogSleepTimeout);
}
