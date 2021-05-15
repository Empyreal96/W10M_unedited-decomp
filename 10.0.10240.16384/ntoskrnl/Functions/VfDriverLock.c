// VfDriverLock 
 
int VfDriverLock()
{
  int result; // r0
  int v1; // r3

  result = KeWaitForSingleObject((unsigned int)&ViDriversLoadLock, 18, 0, 0, 0);
  v1 = __mrc(15, 0, 13, 0, 3);
  __dmb(0xBu);
  ViDriversLoadLockOwner = v1 & 0xFFFFFFC0;
  return result;
}
