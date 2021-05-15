// PerfDiagpBootUserProxyCallback 
 
void __fastcall PerfDiagpBootUserProxyCallback(int a1, int a2, int a3)
{
  if ( a2 )
  {
    if ( a3 == 85 )
      PerfDiagpRequestState(3);
  }
  else
  {
    PerfDiagpRequestState(4);
  }
}
