// PopDiagTraceEsState 
 
int __fastcall PopDiagTraceEsState(int result, int a2)
{
  int _3C; // [sp+3Ch] [bp+8h]

  _3C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_ENERGY_SAVER_STATE);
    if ( result )
      result = sub_555C54();
  }
  return result;
}
