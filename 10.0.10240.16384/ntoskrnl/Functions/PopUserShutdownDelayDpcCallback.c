// PopUserShutdownDelayDpcCallback 
 
int PopUserShutdownDelayDpcCallback()
{
  int result; // r0
  unsigned int v1; // r1

  result = 1;
  do
    v1 = __ldrex(&PopUserShutdown);
  while ( __strex(1u, &PopUserShutdown) );
  if ( !v1 )
    result = ExQueueWorkItem(&PopUserShutdownDelayWorker, 1);
  return result;
}
