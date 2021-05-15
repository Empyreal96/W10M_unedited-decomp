// PpmCheckPeriodicStart 
 
int __fastcall PpmCheckPeriodicStart(int a1, int a2, int a3)
{
  int v5[4]; // [sp+8h] [bp-10h] BYREF

  v5[0] = 0;
  v5[1] = 0;
  if ( KeWaitForSingleObject((unsigned int)&byte_61E8A4, 0, 0, 0, v5) )
    return PpmEventTraceFailedPerfCheckStart(PpmCheckLastExecutionTime, SHIDWORD(PpmCheckLastExecutionTime));
  PpmCheckMakeupCount = a3;
  return PpmCheckStart(0);
}
