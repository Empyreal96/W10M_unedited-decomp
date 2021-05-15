// PopDiagTraceFxPerfRequestProgress 
 
int __fastcall PopDiagTraceFxPerfRequestProgress(int result, int a2)
{
  __int64 v2; // kr00_8
  int _50; // [sp+50h] [bp+8h]

  _50 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_PROCESSING);
    if ( result )
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_PROCESSING, 0);
  }
  return result;
}
