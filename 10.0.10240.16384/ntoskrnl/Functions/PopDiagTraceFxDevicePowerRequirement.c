// PopDiagTraceFxDevicePowerRequirement 
 
int __fastcall PopDiagTraceFxDevicePowerRequirement(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  int varg_r0; // [sp+64h] [bp+8h]

  varg_r0 = result;
  if ( a2 == 1 )
    v4 = POP_ETW_EVENT_DEVICE_POWER_REQUIREMENT_FROM_PEP;
  else
    v4 = POP_ETW_EVENT_DEVICE_POWER_REQUIREMENT_TO_DEVICE;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, v4);
    if ( result )
      result = sub_53FDB4();
  }
  return result;
}
