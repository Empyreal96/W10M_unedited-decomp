// PerfDiagpSecondaryLogonProxyCallback 
 
void __fastcall PerfDiagpSecondaryLogonProxyCallback(int a1, int a2, int a3)
{
  if ( a2 )
  {
    if ( a3 == 85 )
      PerfDiagpRequestState(5);
  }
  else
  {
    PerfDiagpRequestState(6);
  }
}
