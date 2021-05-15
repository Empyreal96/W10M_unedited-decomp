// EtwpPsProvTraceJob 
 
int __fastcall EtwpPsProvTraceJob(int result, int a2, int a3, int a4)
{
  int *v4; // r2
  int varg_r0; // [sp+378h] [bp+8h]

  varg_r0 = result;
  if ( a4 == 1824 )
  {
    v4 = JobStart;
  }
  else
  {
    if ( a4 != 1825 )
      return result;
    v4 = JobTerminate;
  }
  return EtwWrite(EtwpPsProvRegHandle, dword_61A934, (int)v4, 0);
}
