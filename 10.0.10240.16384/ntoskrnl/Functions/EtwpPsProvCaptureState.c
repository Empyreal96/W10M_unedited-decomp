// EtwpPsProvCaptureState 
 
BOOL __fastcall EtwpPsProvCaptureState(int *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6[2]; // [sp+0h] [bp-18h] BYREF
  int v7; // [sp+8h] [bp-10h]
  int v8; // [sp+Ch] [bp-Ch]

  v6[1] = a4;
  v7 = 0;
  v8 = 0;
  v6[0] = a3;
  *(_WORD *)((char *)&v7 + 1) = a1 == PsProvTraceLoggingGuid;
  v4 = IoSetThreadHardErrorMode(0);
  EtwpPsProvProcessEnumCallback(PsIdleProcess, v6);
  PsEnumProcesses((int (__fastcall *)(int *, int))EtwpPsProvProcessEnumCallback, (int)v6);
  return IoSetThreadHardErrorMode(v4);
}
