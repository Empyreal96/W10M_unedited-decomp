// EtwUnregisterCounters 
 
_DWORD *EtwUnregisterCounters()
{
  _DWORD *result; // r0

  if ( PcwpEventTracingSessionCounterSet )
  {
    PcwUnregister(PcwpEventTracingSessionCounterSet);
    PcwpEventTracingSessionCounterSet = 0;
  }
  result = (_DWORD *)PcwpEventTracingCounterSet;
  if ( PcwpEventTracingCounterSet )
  {
    result = PcwUnregister(PcwpEventTracingCounterSet);
    PcwpEventTracingCounterSet = 0;
  }
  return result;
}
