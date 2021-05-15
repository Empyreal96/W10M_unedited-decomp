// PopEnableIrpWatchdog 
 
__int64 __fastcall PopEnableIrpWatchdog(__int64 a1)
{
  int v1; // r5
  unsigned int v2; // r6
  int v3; // r0

  v1 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  v2 = PopComputeWatchdogTimeout(v1, HIDWORD(a1));
  if ( v2 )
  {
    *(_BYTE *)(v1 + 124) = 1;
    *(_BYTE *)(v1 + 80) = 19;
    *(_DWORD *)(v1 + 92) = PopIrpWatchdog;
    *(_DWORD *)(v1 + 96) = v1;
    *(_BYTE *)(v1 + 81) = 1;
    *(_WORD *)(v1 + 82) = 0;
    *(_DWORD *)(v1 + 108) = 0;
    *(_DWORD *)(v1 + 88) = 0;
    KeInitializeTimerEx(v1 + 32, 0);
    v3 = KiSetTimerEx(v1 + 32, -v2, -10000000 * v2, (-10000000i64 * (unsigned __int64)v2) >> 32, 0, 0, v1 + 80);
    *(_QWORD *)(v1 + 24) = KeQueryInterruptTime(v3);
  }
  return a1;
}
