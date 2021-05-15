// ExGetNextWakeTimeForDeepSleep 
 
unsigned __int64 ExGetNextWakeTimeForDeepSleep()
{
  unsigned __int64 v0; // r4
  unsigned __int64 v1; // r0
  int *v2; // r6
  int v3; // r2
  int v4; // r3

  v0 = -1i64;
  v1 = -1i64;
  if ( PoRtcWakeAllowed )
  {
    v2 = (int *)ExpWakeTimerList;
    while ( v2 != &ExpWakeTimerList )
    {
      v3 = (int)(v2 - 38);
      v4 = *(v2 - 1);
      v2 = (int *)*v2;
      if ( v4 )
        v1 = KeQueryTimerDueTime(v3);
      if ( v1 && v1 < v0 )
        v0 = v1;
    }
  }
  return v0;
}
