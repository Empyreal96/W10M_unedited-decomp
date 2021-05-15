// PopDiagTracePolicyChange 
 
int __fastcall PopDiagTracePolicyChange(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+84h] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_ADPM_POLICY_CHANGE);
    if ( result )
      result = sub_7F1624();
  }
  return result;
}
