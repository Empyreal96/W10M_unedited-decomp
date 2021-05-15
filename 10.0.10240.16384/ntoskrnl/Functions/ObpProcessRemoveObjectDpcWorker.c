// ObpProcessRemoveObjectDpcWorker 
 
__int64 ObpProcessRemoveObjectDpcWorker()
{
  return (unsigned int)ExQueueWorkItem(&ObpRemoveObjectWorkItem, 0);
}
