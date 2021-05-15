// PopDiagTraceSuperfetchNotification 
 
int __fastcall PopDiagTraceSuperfetchNotification(int a1)
{
  int result; // r0

  if ( a1 )
    result = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUPERFETCH_START);
  else
    result = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUPERFETCH_STOP);
  return result;
}
