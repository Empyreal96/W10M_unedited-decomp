// WdipSemLogTimeoutInformation 
 
int __fastcall WdipSemLogTimeoutInformation(int a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r3
  int v8; // r2
  int v9; // r3

  v6 = 0;
  if ( EtwEventEnabled(WdipSemRegHandle, SHIDWORD(WdipSemRegHandle), (int)WDI_SEM_EVENT_SCENARIO_TIMEOUT) )
  {
    v6 = WdipSemWriteTimeoutEvent(a1, a2, a3, v7);
    if ( v6 < 0 )
      v6 = 0;
  }
  if ( WdipSemSqmEnabled() )
  {
    v6 = WdipSemSqmLogTimeoutDataPoints(a1, a2, v8, v9);
    if ( v6 < 0 )
      v6 = 0;
  }
  return v6;
}
