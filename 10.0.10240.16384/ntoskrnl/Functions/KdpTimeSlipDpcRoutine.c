// KdpTimeSlipDpcRoutine 
 
int KdpTimeSlipDpcRoutine()
{
  unsigned int v0; // r1
  signed int v1; // r1
  int result; // r0

  __dmb(0xBu);
  do
  {
    v0 = __ldrex((unsigned int *)&KdpTimeSlipPending);
    v1 = v0 - 1;
  }
  while ( __strex(v1, (unsigned int *)&KdpTimeSlipPending) );
  __dmb(0xBu);
  if ( v1 > 0 )
    result = ExQueueWorkItem(&KdpTimeSlipWorkItem, 1);
  return result;
}
