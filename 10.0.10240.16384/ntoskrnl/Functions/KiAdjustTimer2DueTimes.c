// KiAdjustTimer2DueTimes 
 
int KiAdjustTimer2DueTimes()
{
  int v0; // r7
  int result; // r0
  unsigned __int64 v2; // kr00_8
  __int64 v3; // r0
  _DWORD v4[10]; // [sp+10h] [bp-28h] BYREF

  v0 = 0;
  v4[0] = v4;
  v4[1] = v4;
  do
  {
    if ( HIDWORD(KiTimer2Collections[2 * v0]) )
      return sub_519B0C();
    ++v0;
  }
  while ( v0 < 5 );
  v2 = KiTimer2Collections[5];
  LODWORD(v3) = KeQueryInterruptTime();
  result = KiShouldSetClockIntervalForHighResolutionTimers(v3, v2);
  if ( result )
    result = KiSendClockInterruptToClockOwner(result);
  return result;
}
