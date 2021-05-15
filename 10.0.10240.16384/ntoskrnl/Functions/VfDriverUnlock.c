// VfDriverUnlock 
 
int VfDriverUnlock()
{
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  return KeReleaseMutex((int)&ViDriversLoadLock);
}
