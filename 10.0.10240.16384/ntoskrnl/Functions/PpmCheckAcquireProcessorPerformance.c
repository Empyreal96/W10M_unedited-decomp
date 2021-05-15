// PpmCheckAcquireProcessorPerformance 
 
int PpmCheckAcquireProcessorPerformance()
{
  int result; // r0

  if ( dword_616308 )
    return PpmPerfControlExecuteAction(PpmPerfControlAcquirePerformance);
  result = 1;
  PpmCheckPipelineIndex += 2;
  return result;
}
