// PopDiagTraceHibernateErrorStatus 
 
int __fastcall PopDiagTraceHibernateErrorStatus(int result, int a2)
{
  __int64 v2; // kr00_8
  int vars8; // [sp+30h] [bp+8h]

  vars8 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_HIBERNATE_STATUS);
    if ( result )
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_HIBERNATE_STATUS, 0);
  }
  return result;
}
