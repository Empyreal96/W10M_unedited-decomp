// PopDiagTraceSkipTick 
 
int __fastcall PopDiagTraceSkipTick(int result, int a2)
{
  int v3; // r7
  __int64 v4; // kr00_8
  int v5; // [sp+8h] [bp-40h] BYREF
  _DWORD v6[15]; // [sp+Ch] [bp-3Ch] BYREF

  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SKIP_TICK);
    if ( result )
    {
      v6[0] = v3;
      v6[1] = v6;
      v6[2] = 0;
      v6[3] = 4;
      v6[4] = 0;
      v6[5] = &v5;
      v6[6] = 0;
      v6[7] = 4;
      v6[8] = 0;
      v5 = a2;
      result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_SKIP_TICK, 0);
    }
  }
  return result;
}
