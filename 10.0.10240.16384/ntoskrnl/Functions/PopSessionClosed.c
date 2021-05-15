// PopSessionClosed 
 
unsigned int __fastcall PopSessionClosed(int a1)
{
  int v2; // r3

  PopPrintEx(3);
  PopDiagTraceSessionStates((int)POP_ETW_ADPM_SESSION_CLOSED, a1, 0, v2);
  return PopFreeSessionState(a1);
}
