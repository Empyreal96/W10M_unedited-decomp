// PopSessionDisconnected 
 
int __fastcall PopSessionDisconnected(int a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r2
  int v7; // r3
  int result; // r0

  PopDiagTraceSessionStates((int)POP_ETW_ADPM_SESSION_DISCONNECTED, a1, 0, a4);
  if ( PopConsoleContext == a1 && a1 != -1 )
  {
    memset(&PopConsoleContext, 0, 40);
    dword_61DE60 = 3;
    PopConsoleContext = -1;
  }
  PopSetSessionDisplayStatus(a1, 0, 0);
  result = PopSetSessionUserStatus(a1, 2, v6, v7);
  *a2 = 0;
  a2[1] = 0;
  return result;
}
