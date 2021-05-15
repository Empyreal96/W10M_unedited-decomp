// PopDiagTraceDeviceReleaseIrp 
 
int __fastcall PopDiagTraceDeviceReleaseIrp(int result, int a2)
{
  int _3C; // [sp+3Ch] [bp+8h]

  _3C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_IRP_DRIVERRELEASE);
    if ( result )
      result = sub_54B0C8();
  }
  return result;
}
