// PerfDiagpBootSystemProxyCallback 
 
void __fastcall PerfDiagpBootSystemProxyCallback(int a1, int a2, int a3)
{
  if ( a2 )
  {
    if ( a3 == 85 )
      PerfDiagpRequestState(1);
  }
  else
  {
    PerfDiagpRequestState(2);
  }
}
