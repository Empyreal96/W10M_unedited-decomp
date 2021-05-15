// PopFxTraceDeviceRegistration 
 
void __fastcall PopFxTraceDeviceRegistration(int a1, int a2)
{
  int *v2; // r6

  if ( a2 )
    v2 = POP_ETW_EVENT_DEVICE_REGISTRATION_RUNDOWN;
  else
    v2 = POP_ETW_EVENT_DEVICE_REGISTRATION;
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v2) )
      sub_8125D8();
  }
}
