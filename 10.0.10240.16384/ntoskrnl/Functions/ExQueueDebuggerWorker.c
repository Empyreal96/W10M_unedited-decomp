// ExQueueDebuggerWorker 
 
int ExQueueDebuggerWorker()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 2;
  do
    v1 = __ldrex((unsigned int *)&ExpDebuggerWork);
  while ( v1 == 1 && __strex(2u, (unsigned int *)&ExpDebuggerWork) );
  __dmb(0xBu);
  if ( v1 == 1 )
    result = sub_50A930(2, 1, &ExpDebuggerWork);
  return result;
}
