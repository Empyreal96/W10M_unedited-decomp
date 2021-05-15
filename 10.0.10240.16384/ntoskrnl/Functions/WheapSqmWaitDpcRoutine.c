// WheapSqmWaitDpcRoutine 
 
int WheapSqmWaitDpcRoutine()
{
  return ExQueueWorkItem(&WheapSqmWaitWorkQueueItem, 1);
}
