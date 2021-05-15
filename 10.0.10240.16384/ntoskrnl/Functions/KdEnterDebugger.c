// KdEnterDebugger 
 
int __fastcall KdEnterDebugger(int a1, int a2, __int64 a3)
{
  _DWORD *v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int result; // r0
  char v10; // r4
  int v11; // r5
  unsigned int v12; // r1
  int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r4
  __int64 v16; // r0
  __int64 v17[3]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a3;
  v5 = (_DWORD *)VfIsVerifierEnabled();
  if ( v5 )
    return sub_903A70();
  if ( a1 )
  {
    v5 = KdpQueryPerformanceCounter(v17, v6, v7, v8);
    KdTimerStop = v17[0];
    KdTimerDifference = v17[0] - KdTimerStart;
  }
  else
  {
    KdTimerStop = 0i64;
  }
  v10 = KeGetCurrentIrql(v5);
  v11 = KeFreezeExecution(a1, a2);
  off_617B0C(v11);
  v12 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v13 = *(_DWORD *)(v12 + 1428);
  if ( (KiBugCheckActive & 3) == 0 || (unsigned int)KiBugCheckActive >> 4 != v13 )
    *(_BYTE *)(v12 + 3737) = v10;
  v14 = (_DWORD *)KdLogBuffer[v13];
  if ( v14 )
  {
    v15 = &v14[4 * *v14 + 4];
    LODWORD(v16) = ReadTimeStampCounter();
    *(_QWORD *)v15 = v16;
    v15[2] = (4 * (KdDebuggerNotPresent & 1)) | 1;
    v15[3] = 0;
  }
  KdEnteredDebugger = 1;
  ++KdDebuggerEnteredCount;
  result = v11;
  KdDebuggerEnteredWithoutLock += KdPortLocked == 0;
  return result;
}
