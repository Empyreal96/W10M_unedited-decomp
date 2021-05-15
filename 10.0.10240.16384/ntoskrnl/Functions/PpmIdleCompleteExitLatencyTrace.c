// PpmIdleCompleteExitLatencyTrace 
 
int __fastcall PpmIdleCompleteExitLatencyTrace(int a1, int a2, int a3, int a4, unsigned __int64 a5, int a6, int a7, int a8, int a9)
{
  unsigned __int64 v10; // kr00_8
  int v11; // r0
  int result; // r0
  int v13; // r3
  int varg_r0; // [sp+20h] [bp+8h]

  varg_r0 = a1;
  if ( a2 < 0 )
    return PpmCancelExitLatencyTrace(a1);
  if ( a3 && (v10 = *(_QWORD *)(*(_DWORD *)(a1 + 2944) + 40), a5 > v10) )
    v11 = PpmConvertTimeTo(a5 - v10, (a5 - v10) >> 32);
  else
    v11 = a6;
  result = PpmTraceExitLatency(v11, a8, a9, a7);
  if ( !result )
    return PpmCancelExitLatencyTrace(a1);
  v13 = *(_DWORD *)(a1 + 2944);
  *(_BYTE *)(v13 + 3) = 0;
  *(_DWORD *)(v13 + 40) = 0;
  *(_DWORD *)(v13 + 44) = 0;
  return result;
}
