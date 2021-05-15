// PoTraceDynamicTickDisabled 
 
void PoTraceDynamicTickDisabled()
{
  __int64 v0; // kr00_8
  char v1; // [sp+20h] [bp-28h] BYREF
  int v2[8]; // [sp+28h] [bp-20h] BYREF

  v1 = KiDynamicTickDisableReason;
  if ( PopDiagHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagHandle;
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DYNAMIC_TICK_DISABLED) )
    {
      v2[0] = (int)&v1;
      v2[1] = 0;
      v2[2] = 1;
      v2[3] = 0;
      EtwWriteEx(v0, SHIDWORD(v0), (int)POP_ETW_EVENT_DYNAMIC_TICK_DISABLED, 1, 0, 0, 1, 0, 0, 1, (int)v2);
    }
  }
}
