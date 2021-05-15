// PopDiagTraceIrpFinish 
 
int __fastcall PopDiagTraceIrpFinish(int result, int a2)
{
  int vars8; // [sp+CCh] [bp+8h]

  vars8 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_IRPFINISH);
    if ( result )
      result = sub_54AE9C();
  }
  return result;
}
