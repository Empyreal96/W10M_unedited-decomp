// PspScheduleEnforcementWorker 
 
int __fastcall PspScheduleEnforcementWorker(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r0
  int result; // r0

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 744);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x100000, v1) );
  __dmb(0xBu);
  do
    result = __ldrex(PspJobTimeLimitsWorkItemFlags);
  while ( __strex(result | 6, PspJobTimeLimitsWorkItemFlags) );
  __dmb(0xBu);
  if ( (result & 4) == 0 )
    result = ExQueueWorkItem(&PspJobTimeLimitsWorkItem, 1);
  return result;
}
