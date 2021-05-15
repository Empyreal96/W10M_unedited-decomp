// EtwpRegTraceEnableCallback 
 
void __fastcall __spoils<R2,R3,R12> EtwpRegTraceEnableCallback(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  char v9; // r3
  _DWORD v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  if ( a9 && *(_DWORD *)(a9 + 8) == 4 )
  {
    EtwpRegTraceOptions = **(_DWORD **)a9;
    dword_92025C = 0;
  }
  if ( !a2 )
  {
    if ( !EtwpRegTracingEnabled )
      return;
    CmUnRegisterCallback(EtwpRegTraceCookie, unk_920264);
    v9 = 0;
    goto LABEL_11;
  }
  if ( a2 == 1 && !EtwpRegTracingEnabled )
  {
    RtlInitUnicodeString((unsigned int)v10, L"425500");
    if ( CmRegisterCallbackEx((int)EtwpRegTraceCallback, (int)v10, (int)v10, 0, (int)&EtwpRegTraceCookie, 0) >= 0 )
    {
      v9 = 1;
LABEL_11:
      EtwpRegTracingEnabled = v9;
      return;
    }
  }
}
