// PopDiagTraceFxDevicePowered 
 
int __fastcall PopDiagTraceFxDevicePowered(int result, int a2)
{
  int _44; // [sp+44h] [bp+8h]

  _44 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_DEVICE_POWERED);
    if ( result )
      result = sub_53EFDC();
  }
  return result;
}
