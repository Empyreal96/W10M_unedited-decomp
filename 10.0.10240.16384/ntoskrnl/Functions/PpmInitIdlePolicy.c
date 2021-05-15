// PpmInitIdlePolicy 
 
int PpmInitIdlePolicy()
{
  __int64 *v0; // r4
  int v1; // r5
  __int64 v2; // r0

  byte_61DC1D = 0;
  byte_61DCCD = 0;
  byte_61DC1C = 0;
  byte_61DCCC = 0;
  dword_61DC20 = 50000;
  dword_61DCD0 = 50000;
  byte_61DC24 = 40;
  byte_61DCD4 = 40;
  byte_61DC25 = 60;
  byte_61DCD5 = 60;
  PopIdleTransitionTimeout = 2 * PopQpcFrequency;
  if ( KdPitchDebugger )
    PopCoordinatedIdleExitTimeout = 2 * PopQpcFrequency;
  else
    PopCoordinatedIdleExitTimeout = 90 * PopQpcFrequency;
  v0 = (__int64 *)&PpmIdleIntervalLimits;
  v1 = 26;
  do
  {
    v2 = v0[1];
    if ( ((unsigned int)v2 & HIDWORD(v2)) != -1 )
    {
      LODWORD(v2) = PpmConvertTimeFrom(v2, (unsigned int)dword_989680);
      *v0 = v2;
    }
    v0 += 3;
    --v1;
  }
  while ( v1 );
  return v2;
}
