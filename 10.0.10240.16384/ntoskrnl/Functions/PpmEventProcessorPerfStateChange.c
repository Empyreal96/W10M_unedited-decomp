// PpmEventProcessorPerfStateChange 
 
int __fastcall PpmEventProcessorPerfStateChange(int a1, int a2)
{
  _DWORD *v2; // r4
  int v4; // r8
  int v5; // r7
  int v8; // r1
  int v9[18]; // [sp+8h] [bp-48h] BYREF

  v2 = *(_DWORD **)(a1 + 3204);
  v4 = v2[16];
  v5 = v2[12];
  if ( (dword_682610 & 0x8000) != 0 )
    return sub_53FD04();
  if ( WmiPerfStateEventEnabled )
  {
    memset(v9, 0, 20);
    v9[0] = v4;
    v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    v9[3] = v5;
    v9[4] = v8;
    PpmFireWmiEvent(a1 + 3120, PPM_PERFSTATE_CHANGE_GUID, 20, v9);
  }
  return PpmEventPerfState(
           PPM_ETW_PROCESSOR_PERF_STATE_CHANGE,
           *(_DWORD *)(a1 + 20),
           v4,
           v5,
           v2[11],
           *(_DWORD *)(a2 + 152));
}
