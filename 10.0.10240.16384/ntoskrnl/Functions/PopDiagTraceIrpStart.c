// PopDiagTraceIrpStart 
 
int __fastcall PopDiagTraceIrpStart(int result, int a2)
{
  int _9C; // [sp+9Ch] [bp+8h]

  _9C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_IRPSTART);
    if ( result )
      result = sub_52A634();
  }
  return result;
}
