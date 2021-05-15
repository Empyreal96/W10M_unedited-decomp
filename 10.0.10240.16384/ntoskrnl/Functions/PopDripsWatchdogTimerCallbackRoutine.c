// PopDripsWatchdogTimerCallbackRoutine 
 
int __fastcall PopDripsWatchdogTimerCallbackRoutine(int a1, int a2)
{
  __int64 v3; // r0

  PopCalculateIdleInformation(a2 + 64);
  LODWORD(v3) = KeQueryInterruptTime();
  *(_QWORD *)(a2 + 40) = v3;
  return PopQueueWorkItem((_DWORD *)(a2 + 232));
}
