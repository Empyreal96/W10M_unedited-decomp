// PpmPerfApplyProcessorState 
 
int __fastcall PpmPerfApplyProcessorState(int a1, int a2)
{
  int v2; // r6
  _DWORD *v4; // r4
  int v7; // r1
  int v8; // r7
  _DWORD v9[8]; // [sp+18h] [bp-20h] BYREF

  v2 = *(_DWORD *)(a1 + 3200);
  v4 = *(_DWORD **)(a1 + 3204);
  if ( a1 != *(_DWORD *)(v2 + 8) && *(unsigned __int8 *)(v2 + 112) == 253 )
    return sub_53FC04();
  if ( a1 != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408
    && (a1 == *(_DWORD *)(v2 + 8) || !a2 && (dword_682610 & 0x8000) != 0 || *(_BYTE *)(v2 + 114)) )
  {
    return 0;
  }
  KeQueryPerformanceCounter(v9, 0);
  v8 = PpmContinueTimeAccumulation(a1, v7, v9[0], v9[1]);
  if ( v8 )
  {
    (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, bool, int, int))(v2 + 72))(
      v4[1],
      *(_DWORD *)(v2 + 144),
      v4[16],
      v4[17],
      *(_DWORD *)(v2 + 144),
      *(_DWORD *)(v2 + 140),
      *(_DWORD *)(v2 + 152),
      *(_BYTE *)(v2 + 181) == 0,
      1,
      a2);
    if ( !a2 )
    {
      *(_BYTE *)(a1 + 3220) = *(_DWORD *)(v2 + 148);
      PpmEventPerfState(
        PPM_ETW_PROCESSOR_PERF_STATE_CHANGE_INITIATED,
        *(_DWORD *)(a1 + 20),
        *(_DWORD *)(*(_DWORD *)(a1 + 3204) + 64),
        *(_DWORD *)(*(_DWORD *)(a1 + 3204) + 48),
        *(_DWORD *)(*(_DWORD *)(a1 + 3204) + 44),
        *(_DWORD *)(*(_DWORD *)(a1 + 3200) + 152));
      PpmScaleIdleStateValues(a1 + 2944);
      PpmEventProcessorPerfStateChange(a1, v2);
      PpmEventTraceExpectedUtility(a1);
    }
  }
  return v8;
}
