// CmpCmdInit 
 
int __fastcall CmpCmdInit(char a1)
{
  int v2; // r0
  int v3; // r4
  int v4; // r3
  int v5; // r2
  int result; // r0

  CmpInitializeLazyWriters();
  dword_6320E8 = (int)CmpForceFlushWorker;
  dword_6320EC = 0;
  CmpForceFlushWorkItem = 0;
  KeInitializeDpc((int)&CmpEnableLazyFlushDpc, (int)CmpEnableLazyFlushDpcRoutine, (int)&CmpHoldLazyFlush);
  KeInitializeTimerEx(CmpEnableLazyFlushTimer, 0);
  KiSetTimerEx((int)CmpEnableLazyFlushTimer, 0, -6000000000i64, 0, 0, (int)&CmpEnableLazyFlushDpc);
  v2 = ExAllocatePoolWithTag(512, 4, 1482911812);
  v3 = v2;
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    ExGenRandom(0);
    if ( (ExGenRandom(0) & 1) != 0 )
      v4 = 1;
    else
      v4 = 2;
    v5 = v4 | v3;
  }
  else
  {
    v5 = 0;
  }
  KeInitializeDpc((int)&CmpFreezeThawDpc, (int)CmpFreezeThawDpcRoutine, v5);
  KeInitializeTimerEx(CmpFreezeThawTimer, 0);
  dword_6322C8 = (int)CmpFreezeThawWorker;
  dword_6322CC = 0;
  CmpFreezeThawWorkItem = 0;
  __dmb(0xBu);
  CmpWorkerDataInitialized = 1;
  CmpNoWrite = CmpMiniNTBoot;
  CmpWasSetupBoot = a1;
  CmpEnableLazyFlushTimerInitialized = 1;
  result = PoRegisterCoalescingCallback(CmpCoalescingCallback, 1, &CmpCoalescingRegistration, 0);
  if ( result >= 0 )
    CmpCoalescingCallbackActive = 1;
  return result;
}
