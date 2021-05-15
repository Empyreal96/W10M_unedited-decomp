// PopBatteryQueueWork 
 
int __fastcall PopBatteryQueueWork(int result)
{
  unsigned int v1; // r4

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&PopBatteryWorkRequests);
  while ( __strex(v1 | result, (unsigned int *)&PopBatteryWorkRequests) );
  __dmb(0xBu);
  if ( !v1 )
    result = ExQueueWorkItem(&PopBatteryWorkItem, 1);
  return result;
}
