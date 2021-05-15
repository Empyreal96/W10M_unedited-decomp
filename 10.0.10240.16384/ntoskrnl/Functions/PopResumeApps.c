// PopResumeApps 
 
int __fastcall PopResumeApps(int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]

  v6 = a3;
  v7 = a4;
  PopHiberBootForceMonitorOff = 0;
  *(_DWORD *)(a1 + 16) = 5;
  KeQueryPerformanceCounter(&v6, 0);
  dword_61EF80 = v6;
  dword_61EF84 = v7;
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_RESUMEAPPS);
  PopDispatchStateCallout(a1, 0);
  KeQueryPerformanceCounter(&v6, 0);
  dword_61EF88 = v6;
  dword_61EF8C = v7;
  return PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_RESUMEAPPS_END);
}
