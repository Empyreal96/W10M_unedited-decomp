// PopDiagTraceDynamicTickStatusRundown 
 
void PopDiagTraceDynamicTickStatusRundown()
{
  __int64 v0; // kr00_8
  char v1; // [sp+8h] [bp-28h] BYREF
  char *v2; // [sp+10h] [bp-20h]
  int v3; // [sp+14h] [bp-1Ch]
  int v4; // [sp+18h] [bp-18h]
  int v5; // [sp+1Ch] [bp-14h]

  if ( PopDiagHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagHandle;
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DYNAMIC_TICK_STATUS_RUNDOWN) )
    {
      v2 = &v1;
      v3 = 0;
      v4 = 1;
      v5 = 0;
      v1 = KeGetDynamicTickDisableReason();
      EtwWrite(v0, SHIDWORD(v0), (int)POP_ETW_EVENT_DYNAMIC_TICK_STATUS_RUNDOWN, 0);
    }
  }
}
