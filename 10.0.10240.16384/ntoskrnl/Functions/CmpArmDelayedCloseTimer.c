// CmpArmDelayedCloseTimer 
 
int CmpArmDelayedCloseTimer()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 1;
  do
    v1 = __ldrex(&CmpDelayCloseWorkItemActive);
  while ( __strex(1u, &CmpDelayCloseWorkItemActive) );
  __dmb(0xBu);
  if ( !v1 )
    result = ExQueueWorkItem(&CmpDelayCloseWorkItem, 1);
  return result;
}
