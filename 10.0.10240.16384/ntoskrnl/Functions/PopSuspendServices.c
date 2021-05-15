// PopSuspendServices 
 
int __fastcall PopSuspendServices(int a1)
{
  int v3; // [sp+0h] [bp-8h] BYREF

  v3 = 0;
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUSPENDSERVICES);
  *(_DWORD *)(a1 + 16) = 3;
  PopDispatchStateCallout(a1, (int)&v3);
  return PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_SUSPENDSERVICES_END);
}
