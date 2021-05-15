// KiInvokeInterruptServiceRoutine 
 
int __fastcall KiInvokeInterruptServiceRoutine(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r7
  int v5; // r6
  int v7; // r9
  int v8; // r10
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v12; // r1
  __int64 v13; // r0
  int v14; // r0
  int v15; // r8
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  int v19; // r3
  char v20[4]; // [sp+10h] [bp-98h] BYREF
  int v21; // [sp+14h] [bp-94h]
  int v22[3]; // [sp+18h] [bp-90h] BYREF
  int v23; // [sp+24h] [bp-84h]
  char v24[2]; // [sp+28h] [bp-80h] BYREF
  __int16 v25; // [sp+2Ah] [bp-7Eh]
  int v26; // [sp+30h] [bp-78h]
  void (__noreturn *v27)(); // [sp+34h] [bp-74h]
  char *v28; // [sp+38h] [bp-70h]
  int v29; // [sp+44h] [bp-64h]
  _DWORD v30[12]; // [sp+48h] [bp-60h] BYREF
  _DWORD v31[12]; // [sp+78h] [bp-30h] BYREF

  v3 = *(unsigned __int8 *)(a1 + 49);
  v4 = 0;
  v23 = a3;
  v5 = a2;
  v31[0] = 0;
  v31[1] = 0;
  v31[2] = 0;
  v31[3] = 0;
  v7 = 1;
  v8 = 0;
  if ( v3 )
  {
    if ( a2 != v3 )
      v5 = KfRaiseIrql(v3);
    v19 = *(_DWORD *)(a1 + 36);
    if ( v19 == -3 || v19 == -1 )
      v7 = 0;
  }
  else
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeWaitForSingleObject(*(_DWORD *)(a1 + 80), 0, 0, 0, 0);
    if ( (dword_682604 & 0x4000) == 0 )
      return sub_553B88(v10);
    v4 = 1;
    if ( KdDebuggerEnabled && KiPassiveWatchdogTimeout )
    {
      v20[0] = 1;
      v20[1] = 0;
      v20[2] = 4;
      v21 = 0;
      v22[1] = (int)v22;
      v22[2] = a1;
      v22[0] = (int)v22;
      KeInitializeTimerEx(v30, 0);
      v24[0] = 19;
      v24[1] = 1;
      v25 = 0;
      v27 = KiPassiveIsrWatchdog;
      v28 = v20;
      v29 = 0;
      v26 = 0;
      KiSetTimerEx((int)v30, v12, -10000000i64 * KiPassiveWatchdogTimeout, 0, 0, (int)v24);
      v8 = 1;
    }
  }
  *(_DWORD *)(a1 + 92) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v4 )
  {
    HIDWORD(v13) = 536887296;
    LODWORD(v13) = v31;
    EtwGetKernelTraceTimestamp(v13);
  }
  v14 = KiCallInterruptServiceRoutine(a1, v7);
  v15 = v14;
  if ( v4 )
    PerfInfoLogInterrupt(a1, v14 | (v23 << 8), (int)v31);
  if ( v8 && !KeCancelTimer((int)v30) )
    KeWaitForSingleObject((unsigned int)v20, 0, 0, 0, 0);
  *(_DWORD *)(a1 + 92) = 0;
  if ( v3 )
  {
    if ( v5 != v3 )
      KfLowerIrql(v5);
  }
  else
  {
    v16 = KeSetEvent(*(_DWORD *)(a1 + 80), 0, 0);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  return v15 == 1;
}
