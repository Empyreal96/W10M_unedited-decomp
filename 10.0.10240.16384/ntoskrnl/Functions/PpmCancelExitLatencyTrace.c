// PpmCancelExitLatencyTrace 
 
int __fastcall PpmCancelExitLatencyTrace(int result)
{
  int v1; // r2
  int v2; // r3

  v1 = *(_DWORD *)(result + 2944);
  if ( v1 && *(_BYTE *)(v1 + 3) )
  {
    if ( PpmExitLatencySamplingPercentage )
      *(_DWORD *)(v1 + 8) = 1;
    else
      *(_DWORD *)(v1 + 8) = 0;
    v2 = *(_DWORD *)(result + 2944);
    *(_BYTE *)(v2 + 3) = 0;
    *(_DWORD *)(v2 + 40) = 0;
    *(_DWORD *)(v2 + 44) = 0;
  }
  return result;
}
