// PopAcquireWakeSourceSpinLock 
 
int __fastcall PopAcquireWakeSourceSpinLock(unsigned int a1)
{
  int v1; // r4
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3);
  result = KeAcquireInStackQueuedSpinLock((unsigned int *)&PopWakeSourceLock, a1);
  PopWakeSourceLockOwner = v1 & 0xFFFFFFC0;
  return result;
}
