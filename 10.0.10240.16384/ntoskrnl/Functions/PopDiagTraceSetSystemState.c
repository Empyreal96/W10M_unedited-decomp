// PopDiagTraceSetSystemState 
 
int __fastcall PopDiagTraceSetSystemState(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_SETSYSTEMSTATE);
    if ( result )
      result = sub_529728();
  }
  return result;
}
