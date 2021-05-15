// ExpUnlockResource 
 
int __fastcall ExpUnlockResource(int a1, int a2)
{
  return KeReleaseInStackQueuedSpinLock(a2);
}
