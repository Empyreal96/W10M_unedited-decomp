// KiSetClockIntervalToMinimumRequested 
 
int KiSetClockIntervalToMinimumRequested()
{
  int v0; // r2
  int result; // r0

  v0 = *(_DWORD *)(dword_649EA8 + 16);
  result = KeTimeIncrement;
  if ( v0 != KiLastRequestedTimeIncrement && v0 != KeTimeIncrement )
    result = KiSetClockTickRate(v0);
  return result;
}
