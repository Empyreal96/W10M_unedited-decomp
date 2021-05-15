// CmpDelayFreeRMDpcRoutine 
 
int CmpDelayFreeRMDpcRoutine()
{
  return ExQueueWorkItem(&CmpDelayFreeRMWorkItem, 1);
}
