// PopDiagTraceFxComponentIdleState 
 
int __fastcall PopDiagTraceFxComponentIdleState(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+64h] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_IDLE_STATE);
    if ( result )
      result = sub_54B2DC();
  }
  return result;
}
