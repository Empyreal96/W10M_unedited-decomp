// PopDiagTracePreSleepCallbacks 
 
int __fastcall PopDiagTracePreSleepCallbacks(int a1)
{
  int result; // r0

  if ( a1 )
    result = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_PRESLEEP_CALLBACKS_START);
  else
    result = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_PRESLEEP_CALLBACKS_STOP);
  return result;
}
