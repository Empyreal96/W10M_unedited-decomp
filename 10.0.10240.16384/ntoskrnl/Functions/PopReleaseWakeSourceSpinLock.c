// PopReleaseWakeSourceSpinLock 
 
int __fastcall PopReleaseWakeSourceSpinLock(int a1)
{
  PopWakeSourceLockOwner = 0;
  return KeReleaseInStackQueuedSpinLock(a1);
}
