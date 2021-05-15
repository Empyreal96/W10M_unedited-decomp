// ExpDebuggerDpcRoutine 
 
int ExpDebuggerDpcRoutine()
{
  return ExQueueWorkItem(&ExpDebuggerWorkItem, 1);
}
