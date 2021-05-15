// ExpLockResource 
 
int __fastcall ExpLockResource(int a1, unsigned int a2)
{
  return KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 52), a2);
}
