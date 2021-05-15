// PopIrpWatchdog 
 
void __fastcall __noreturn PopIrpWatchdog(int a1, int a2, int a3, int a4)
{
  _DWORD v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[0] = a2;
  v5[1] = a3;
  v5[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)v5);
  PopIrpLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PopIrpWatchdogBugcheck(a2);
}
