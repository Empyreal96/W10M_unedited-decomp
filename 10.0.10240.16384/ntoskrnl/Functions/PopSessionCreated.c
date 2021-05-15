// PopSessionCreated 
 
int __fastcall PopSessionCreated(int a1)
{
  int v2; // r3

  PopPrintEx(3);
  return PopDiagTraceSessionStates((int)POP_ETW_ADPM_SESSION_CREATED, a1, 0, v2);
}
