// PpmResetPerfTimes 
 
int __fastcall PpmResetPerfTimes(int result)
{
  _DWORD *v1; // r5
  int v2; // r6

  v1 = *(_DWORD **)(result + 3196);
  v2 = result;
  if ( v1 )
  {
    PpmResetPerformanceAccumulation(result);
    result = PpmSnapPerformanceAccumulation(v2, 1, 0, 0, (int)(v1 + 6));
    v1[2] = v1[6];
    v1[3] = v1[7];
    *v1 = v1[8];
    v1[1] = v1[9];
    v1[4] = v1[10];
    v1[5] = v1[11];
  }
  return result;
}
