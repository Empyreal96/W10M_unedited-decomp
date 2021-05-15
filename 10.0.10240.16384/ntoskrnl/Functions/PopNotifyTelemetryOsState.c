// PopNotifyTelemetryOsState 
 
int __fastcall PopNotifyTelemetryOsState(int a1)
{
  int result; // r0

  result = TraceLoggingProviderEnabled(&dword_6163C8);
  if ( result && (a1 == 4 || a1 == 5 || a1 == 6 || a1 == 2 || a1 == 3) )
    result = PopTransitionTelemetryOsState();
  return result;
}
