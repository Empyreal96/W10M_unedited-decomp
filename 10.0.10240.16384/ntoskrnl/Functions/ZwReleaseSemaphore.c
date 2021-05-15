// ZwReleaseSemaphore 
 
int ZwReleaseSemaphore()
{
  return KiServiceInternal();
}
