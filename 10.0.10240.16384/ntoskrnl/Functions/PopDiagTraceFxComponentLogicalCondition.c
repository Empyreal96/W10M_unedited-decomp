// PopDiagTraceFxComponentLogicalCondition 
 
int __fastcall PopDiagTraceFxComponentLogicalCondition(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+6Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_COMPONENT_CONDITION);
    if ( result )
      result = sub_54063C();
  }
  return result;
}
