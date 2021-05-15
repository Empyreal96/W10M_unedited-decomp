// PopDiagTracePowerTransitionStart 
 
int __fastcall PopDiagTracePowerTransitionStart(int result, int a2)
{
  int v2; // [sp+8h] [bp-58h] BYREF
  _DWORD v3[19]; // [sp+10h] [bp-50h] BYREF
  int v4; // [sp+5Ch] [bp-4h] BYREF

  v3[18] = result;
  v4 = a2;
  if ( PopDiagHandleRegistered )
  {
    v2 = result;
    KeQuerySystemTime(v3);
    v3[2] = &v2;
    v3[3] = 0;
    v3[4] = 4;
    v3[5] = 0;
    v3[6] = &v4;
    v3[7] = 0;
    v3[8] = 4;
    v3[9] = 0;
    v3[10] = v3;
    v3[11] = 0;
    v3[12] = 8;
    v3[13] = 0;
    result = EtwWriteStartScenario(
               PopDiagHandle,
               dword_61E154,
               (int)POP_ETW_EVENT_POWERTRANSITION_START,
               (int)&PopDiagActivityId);
  }
  return result;
}
