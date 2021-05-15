// VfFreeMemoryNotification 
 
int __fastcall VfFreeMemoryNotification(int a1, int a2)
{
  VfDeadlockDeleteMemoryRange();
  return VfRemLockDeleteMemoryRange(a1, a2);
}
