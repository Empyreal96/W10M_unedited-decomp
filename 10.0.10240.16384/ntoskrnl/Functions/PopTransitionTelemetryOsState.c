// PopTransitionTelemetryOsState 
 
int PopTransitionTelemetryOsState()
{
  int result; // r0

  result = TraceLoggingProviderEnabled(&dword_6163C8);
  if ( result )
  {
    if ( byte_61E23C )
      result = sub_7F233C();
  }
  return result;
}
