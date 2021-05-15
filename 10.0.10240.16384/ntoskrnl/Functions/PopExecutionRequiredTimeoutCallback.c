// PopExecutionRequiredTimeoutCallback 
 
int PopExecutionRequiredTimeoutCallback()
{
  unsigned int v0; // r1
  unsigned int v1; // r1
  int result; // r0

  __dmb(0xBu);
  do
  {
    v0 = __ldrex(PopExecutionRequiredWorkRequested);
    v1 = v0 + 1;
  }
  while ( __strex(v1, PopExecutionRequiredWorkRequested) );
  __dmb(0xBu);
  if ( v1 == 1 )
    result = ExQueueWorkItem(&PopCheckExecutionRequiredWorker, 1);
  return result;
}
