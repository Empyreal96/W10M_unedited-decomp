// PerfDiagpShutdownProxyCallback 
 
int __fastcall PerfDiagpShutdownProxyCallback(int a1, int a2, int a3)
{
  int result; // r0

  if ( a2 )
  {
    if ( a3 == 85 )
      result = PerfDiagpRequestState(7);
  }
  return result;
}
