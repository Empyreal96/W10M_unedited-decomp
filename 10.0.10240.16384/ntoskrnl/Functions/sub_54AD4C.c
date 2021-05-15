// sub_54AD4C 
 
// bad sp value at call has been detected, the output may be wrong!
void __noreturn sub_54AD4C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r5
  va_list va; // [sp+58h] [bp+18h] BYREF

  va_start(va, a10);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)va);
  PopIrpLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PopIrpWatchdogBugcheck(v10);
}
