// PopDiagTracePowerTransitionEnd 
 
int __fastcall PopDiagTracePowerTransitionEnd(int result, int a2)
{
  _DWORD v2[13]; // [sp+8h] [bp-40h] BYREF
  _DWORD v3[2]; // [sp+40h] [bp-8h] BYREF

  v3[0] = result;
  v3[1] = a2;
  if ( PopDiagHandleRegistered )
  {
    KeQuerySystemTime(v2);
    v2[2] = v3;
    v2[3] = 0;
    v2[4] = 4;
    v2[5] = 0;
    v2[6] = v2;
    v2[7] = 0;
    v2[8] = 8;
    v2[9] = 0;
    result = EtwWriteEndScenario(
               PopDiagHandle,
               dword_61E154,
               (int)POP_ETW_EVENT_POWERTRANSITION_END,
               (int)&PopDiagActivityId);
  }
  return result;
}
