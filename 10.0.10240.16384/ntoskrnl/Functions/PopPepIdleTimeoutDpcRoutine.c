// PopPepIdleTimeoutDpcRoutine 
 
int PopPepIdleTimeoutDpcRoutine()
{
  int result; // r0

  result = ExQueueWorkItemEx(&PopPepIdleWorkItem, 1, -1);
  if ( !result )
    result = sub_527234();
  return result;
}
