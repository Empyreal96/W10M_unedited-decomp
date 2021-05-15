// ExInitializeTimeRefresh 
 
int ExInitializeTimeRefresh()
{
  int result; // r0
  _DWORD v1[6]; // [sp+18h] [bp-18h] BYREF

  ZwLockProductActivationKeys();
  if ( !ExpSystemSetupInProgress )
  {
    if ( ExGetExpirationDate(&ExpNtExpirationDate) < 0 )
    {
      ExpNtExpirationDate = 0;
      dword_927574 = 0;
    }
    MEMORY[0xFFFF92C8] = ExpNtExpirationDate;
    MEMORY[0xFFFF92CC] = dword_927574;
    ExpShuttingDown = 0;
  }
  ExpTimeRefreshDpc = 19;
  byte_61A341 = 1;
  word_61A342 = 0;
  dword_61A34C = (int)ExpTimeRefreshDpcRoutine;
  dword_61A350 = (int)&ExpOkToTimeRefresh;
  dword_61A35C = 0;
  dword_61A348 = 0;
  dword_61A428 = (int)ExpTimeRefreshWork;
  dword_61A42C = 0;
  ExpTimeRefreshWorkItem = 0;
  KeInitializeTimer2((int)ExpTimeRefreshTimer, (int)ExpTimeRefreshCallback, 0, 8);
  ExpTimeRefreshInterval = -36000000000i64;
  v1[0] = 0;
  v1[1] = 0;
  v1[2] = -1;
  v1[3] = -1;
  KeSetTimer2(ExpTimeRefreshTimer, -36000000000i64, 0i64, (int)v1);
  result = ExInitializeResourceLite((int)&ExpTimeRefreshLock);
  ExpTimerResolutionListHead = (int)&ExpTimerResolutionListHead;
  *(_DWORD *)algn_61A4B4 = &ExpTimerResolutionListHead;
  return result;
}
