// PopReleaseTransitionLock 
 
int PopReleaseTransitionLock()
{
  return KeSetEvent((int)&PopTransitionLock, 0, 0);
}
