// PopResumeServices 
 
int __fastcall PopResumeServices(int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-18h] BYREF
  int v7; // [sp+8h] [bp-10h] BYREF
  int v8; // [sp+Ch] [bp-Ch]

  v7 = a3;
  v8 = a4;
  v6 = 0;
  *(_DWORD *)(a1 + 16) = 6;
  KeQueryPerformanceCounter(&v7, 0);
  dword_61EF90 = v7;
  dword_61EF94 = v8;
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_RESUMESERVICES);
  PopDispatchStateCallout(a1, (int)&v6);
  KeQueryPerformanceCounter(&v7, 0);
  dword_61EF98 = v7;
  dword_61EF9C = v8;
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_RESUMESERVICES_END);
  return v6;
}
