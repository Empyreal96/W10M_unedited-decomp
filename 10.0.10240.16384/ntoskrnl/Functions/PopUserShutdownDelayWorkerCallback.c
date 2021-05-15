// PopUserShutdownDelayWorkerCallback 
 
int PopUserShutdownDelayWorkerCallback()
{
  unsigned int v0; // r1

  do
    v0 = __ldrex(&PopUserShutdown);
  while ( __strex(0, &PopUserShutdown) );
  return PopUserShutdownCancelled(0);
}
