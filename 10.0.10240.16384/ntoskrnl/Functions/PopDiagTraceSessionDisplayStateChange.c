// PopDiagTraceSessionDisplayStateChange 
 
void __fastcall PopDiagTraceSessionDisplayStateChange(int result, int a2, int a3, int a4)
{
  int *v4; // r4

  if ( result )
    v4 = POP_ETW_EVENT_SESSION_DISPLAY_OFF;
  else
    v4 = POP_ETW_EVENT_SESSION_DISPLAY_ON;
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v4) )
      sub_50FF28();
  }
}
