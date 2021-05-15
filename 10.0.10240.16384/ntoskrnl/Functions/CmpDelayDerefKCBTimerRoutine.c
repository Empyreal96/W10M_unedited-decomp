// CmpDelayDerefKCBTimerRoutine 
 
int CmpDelayDerefKCBTimerRoutine()
{
  return ExQueueWorkItem(&CmpDelayDerefKCBWorkItem, 1);
}
