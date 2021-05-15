// PopSuspendApps 
 
int __fastcall PopSuspendApps(int a1)
{
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUSPENDAPPS);
  *(_DWORD *)(a1 + 16) = 2;
  PopDispatchStateCallout(a1, 0);
  return PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUSPENDAPPS_END);
}
