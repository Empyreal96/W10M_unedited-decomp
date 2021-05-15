// PopDiagTraceAppPowerMessage 
 
int __fastcall PopDiagTraceAppPowerMessage(int result)
{
  int *v1; // r7
  int v2; // r5
  unsigned __int16 *v3; // r4
  int v4; // r1
  __int16 v5; // [sp+8h] [bp-58h] BYREF
  int v6; // [sp+Ch] [bp-54h] BYREF
  int v7[20]; // [sp+10h] [bp-50h] BYREF

  v6 = 0;
  v1 = (int *)result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SUSPENDAPP);
    if ( result )
    {
      result = PsLookupProcessByProcessId(*v1, &v6);
      v2 = v6;
      if ( result >= 0 )
      {
        v3 = *(unsigned __int16 **)(v6 + 380);
        v7[0] = *v1;
        v5 = *v3 >> 1;
        v7[2] = (int)v7;
        v7[3] = 0;
        v7[4] = 4;
        v7[5] = 0;
        v7[6] = (int)&v5;
        v7[7] = 0;
        v7[8] = 2;
        v7[9] = 0;
        v4 = *v3;
        v7[10] = *((_DWORD *)v3 + 1);
        v7[11] = 0;
        v7[12] = v4;
        v7[13] = 0;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SUSPENDAPP, 0);
      }
      if ( v2 )
        result = ObfDereferenceObjectWithTag(v2);
    }
  }
  return result;
}
