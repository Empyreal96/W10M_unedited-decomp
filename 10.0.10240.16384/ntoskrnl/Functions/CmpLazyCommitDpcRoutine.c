// CmpLazyCommitDpcRoutine 
 
int CmpLazyCommitDpcRoutine()
{
  int result; // r0

  if ( CmpLazyCommitWorkItemActive )
    result = ExQueueWorkItem(&CmpLazyCommitWorkItem, 1);
  return result;
}
