// PopTriggerDiagTraceAoAcCapability 
 
int __fastcall PopTriggerDiagTraceAoAcCapability(int result)
{
  int v1; // r4
  __int64 v2; // kr00_8
  int v3[10]; // [sp+8h] [bp-28h] BYREF

  v1 = result;
  if ( PopTriggerDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopTriggerDiagHandle;
    result = EtwEventEnabled(PopTriggerDiagHandle, unk_61E1EC, (int)POP_TRIGGER_ETW_AOAC_CAPABILITY);
    if ( result )
    {
      v3[2] = (int)v3;
      v3[3] = 0;
      v3[4] = 4;
      v3[5] = 0;
      v3[0] = v1;
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_TRIGGER_ETW_AOAC_CAPABILITY, 0);
    }
  }
  return result;
}
