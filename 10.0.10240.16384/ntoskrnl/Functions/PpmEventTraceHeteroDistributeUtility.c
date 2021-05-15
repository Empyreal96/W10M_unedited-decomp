// PpmEventTraceHeteroDistributeUtility 
 
int __fastcall PpmEventTraceHeteroDistributeUtility(int result, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  int varg_r0; // [sp+60h] [bp+8h]

  varg_r0 = result;
  if ( PpmEtwRegistered )
  {
    v4 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_HETERO_DISTRIBUTE_UTILITY);
    if ( result )
      result = EtwWrite(v4, SHIDWORD(v4), (int)PPM_ETW_HETERO_DISTRIBUTE_UTILITY, 0);
  }
  return result;
}
