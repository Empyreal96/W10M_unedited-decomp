// WdipTimeoutDpcRoutine 
 
int WdipTimeoutDpcRoutine()
{
  return ExQueueWorkItem(&WdipTimeoutWorkItem, 1);
}
