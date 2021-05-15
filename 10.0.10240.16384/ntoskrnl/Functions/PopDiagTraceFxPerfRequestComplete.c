// PopDiagTraceFxPerfRequestComplete 
 
int __fastcall PopDiagTraceFxPerfRequestComplete(int result, int a2)
{
  int *v3; // r4
  __int64 v4; // kr00_8
  int v5; // r4
  int v6; // r3
  int v7[20]; // [sp+8h] [bp-50h] BYREF

  v3 = (int *)result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_COMPLETED);
    if ( result )
    {
      v5 = *v3;
      v6 = *(_DWORD *)(v5 + 48);
      v7[0] = a2;
      v7[2] = v6 + 28;
      v7[3] = 0;
      v7[4] = 4;
      v7[5] = 0;
      v7[6] = v5 + 16;
      v7[7] = 0;
      v7[8] = 4;
      v7[9] = 0;
      v7[10] = (int)v7;
      v7[11] = 0;
      v7[12] = 4;
      v7[13] = 0;
      result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_COMPLETED, 0);
    }
  }
  return result;
}
