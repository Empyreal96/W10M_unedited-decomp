// EtwpTraceLoggingProvEnableCallback 
 
int __fastcall EtwpTraceLoggingProvEnableCallback(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int result; // r0

  result = a10;
  if ( a2 == 2 )
    result = sub_7D0B50(a10, 2, a3, PsProvTraceLoggingGuid);
  return result;
}
