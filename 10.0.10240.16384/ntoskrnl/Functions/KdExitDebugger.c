// KdExitDebugger 
 
int __fastcall KdExitDebugger(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int *v6; // r2
  int v7; // r9
  int *v8; // r5
  __int64 v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r3
  int result; // r0
  int v19; // [sp+0h] [bp-20h] BYREF
  int v20; // [sp+4h] [bp-1Ch]

  v19 = a3;
  v20 = a4;
  KdEnteredDebugger = 0;
  v5 = KeGetCurrentProcessorNumberEx(0);
  v6 = (int *)KdLogBuffer[v5];
  if ( v6 )
  {
    v7 = *v6;
    v8 = &v6[4 * *v6 + 4];
    LODWORD(v9) = ReadTimeStampCounter();
    v10 = (2 * (KdDebuggerNotPresent & 1)) | 1 | (v9 - *v8) & 0xFFFFFFF1;
    v11 = v8[2];
    v8[3] = (unsigned __int64)(v9 - *(_QWORD *)v8) >> 32;
    v8[2] = v11 & 4 | v10;
    if ( v7 == 254 )
      v12 = 0;
    else
      v12 = v7 + 1;
    *(_DWORD *)KdLogBuffer[v5] = v12;
  }
  off_617B04();
  v16 = KeThawExecution(a1, v13, v14, v15);
  if ( KdTimerStop )
  {
    v16 = KeQueryPerformanceCounter(&v19, 0);
    KdTimerStart = v19;
    v17 = v20;
  }
  else
  {
    v17 = HIDWORD(KdTimerStop);
    KdTimerStart = KdTimerStop;
  }
  MEMORY[0x62784C] = v17;
  if ( !PoHiberInProgress )
    return sub_903A50(v16);
  result = VfIsVerifierEnabled();
  if ( result )
    result = VfNotifyVerifierOfEvent(4);
  return result;
}
