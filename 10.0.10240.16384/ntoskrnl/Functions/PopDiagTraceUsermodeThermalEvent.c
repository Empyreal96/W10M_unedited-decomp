// PopDiagTraceUsermodeThermalEvent 
 
int PopDiagTraceUsermodeThermalEvent()
{
  __int64 v0; // kr00_8
  int result; // r0

  if ( PopDiagHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_EVENT);
    if ( result )
      result = EtwWrite(v0, SHIDWORD(v0), (int)POP_ETW_EVENT_THERMAL_EVENT, 0);
  }
  return result;
}
