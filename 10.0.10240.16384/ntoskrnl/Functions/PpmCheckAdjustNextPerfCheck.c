// PpmCheckAdjustNextPerfCheck 
 
int __fastcall PpmCheckAdjustNextPerfCheck(int a1)
{
  unsigned __int64 v2; // r0
  unsigned __int64 v3; // r2

  if ( PpmCheckCurrentPipelineId == 5 && PpmCheckLastExecutionTime )
  {
    v2 = KeQueryInterruptTime(a1);
    __dmb(0xBu);
    do
      v3 = __ldrexd((unsigned __int64 *)&PpmCheckLastExecutionTime);
    while ( __strexd(v2, (unsigned __int64 *)&PpmCheckLastExecutionTime) );
    __dmb(0xBu);
  }
  return 1;
}
