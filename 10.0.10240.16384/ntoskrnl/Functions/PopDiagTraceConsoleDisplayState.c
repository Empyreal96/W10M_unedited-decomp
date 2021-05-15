// PopDiagTraceConsoleDisplayState 
 
int __fastcall PopDiagTraceConsoleDisplayState(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CONSOLE_DISPLAY_STATE);
    if ( result )
      result = sub_7F2558();
  }
  return result;
}
