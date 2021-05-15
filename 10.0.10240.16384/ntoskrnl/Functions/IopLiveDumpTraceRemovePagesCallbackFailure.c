// IopLiveDumpTraceRemovePagesCallbackFailure 
 
int __fastcall IopLiveDumpTraceRemovePagesCallbackFailure(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
    result = EtwWrite(
               IopLiveDumpEtwRegHandle,
               SHIDWORD(IopLiveDumpEtwRegHandle),
               (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_REMOVEPAGES_CALLBACK_FAILURE,
               0);
  return result;
}
