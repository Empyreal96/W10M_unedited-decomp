// PopAcquireTransitionLock 
 
int PopAcquireTransitionLock()
{
  return KeWaitForSingleObject((unsigned int)&PopTransitionLock, 7, 0, 0, 0);
}
