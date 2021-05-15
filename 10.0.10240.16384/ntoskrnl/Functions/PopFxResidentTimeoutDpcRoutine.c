// PopFxResidentTimeoutDpcRoutine 
 
int PopFxResidentTimeoutDpcRoutine()
{
  int result; // r0

  result = ExQueueWorkItemEx(&PopFxResidentWorkItem, 1, -1);
  if ( !result )
    result = sub_5154B4();
  return result;
}
