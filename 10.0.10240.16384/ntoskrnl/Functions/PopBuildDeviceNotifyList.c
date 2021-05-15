// PopBuildDeviceNotifyList 
 
int __fastcall PopBuildDeviceNotifyList(int a1)
{
  int v2; // r1
  int result; // r0
  char v4[16]; // [sp+10h] [bp-70h] BYREF
  char v5[32]; // [sp+20h] [bp-60h] BYREF
  _DWORD v6[16]; // [sp+40h] [bp-40h] BYREF

  KeInitializeEvent((int)v4, 1, 0);
  KeInitializeTimerEx(v6, 0);
  KeInitializeDpc((int)v5, (int)PopBuildDeviceNotifyListWatchdog, (int)v4);
  if ( PopWatchdogSleepTimeout )
    KiSetTimerEx((int)v6, (unsigned int)v5, -10000000i64 * PopWatchdogSleepTimeout, 0, 0, (int)v5);
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_BUILDNOTIFYLIST);
  IoBuildPoDeviceNotifyList(a1, v2);
  result = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_BUILDNOTIFYLIST_END);
  if ( PopWatchdogSleepTimeout )
  {
    result = KeCancelTimer((int)v6);
    if ( !result )
      result = KeWaitForSingleObject((unsigned int)v4, 0, 0, 0, 0);
  }
  return result;
}
