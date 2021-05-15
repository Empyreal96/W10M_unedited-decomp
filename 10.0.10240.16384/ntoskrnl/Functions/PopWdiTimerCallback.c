// PopWdiTimerCallback 
 
int PopWdiTimerCallback()
{
  return ExQueueWorkItem(&PopWdiTimerWorker, 1);
}
