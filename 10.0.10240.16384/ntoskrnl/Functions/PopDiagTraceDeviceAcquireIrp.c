// PopDiagTraceDeviceAcquireIrp 
 
int __fastcall PopDiagTraceDeviceAcquireIrp(int result, int a2)
{
  int _8C; // [sp+8Ch] [bp+8h]

  _8C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_IRP_DRIVERACQUIRE);
    if ( result )
      result = sub_54B104();
  }
  return result;
}
