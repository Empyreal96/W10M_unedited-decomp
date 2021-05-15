// PopDiagTracePlatformRoleRundown 
 
void PopDiagTracePlatformRoleRundown()
{
  __int64 v0; // kr00_8

  if ( PopDiagHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagHandle;
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_PLATFORMROLE_RUNDOWN) )
      EtwWrite(v0, SHIDWORD(v0), (int)POP_ETW_EVENT_PLATFORMROLE_RUNDOWN, 0);
  }
}
