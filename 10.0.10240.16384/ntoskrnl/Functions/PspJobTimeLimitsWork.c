// PspJobTimeLimitsWork 
 
int PspJobTimeLimitsWork()
{
  int v0; // r4
  unsigned int v1; // r1
  int v2; // r0
  int result; // r0
  unsigned int v4; // r2

  v0 = 0;
  do
  {
    __dmb(0xBu);
    do
      v1 = __ldrex(PspJobTimeLimitsWorkItemFlags);
    while ( __strex(v1 & 0xFFFFFFFC, PspJobTimeLimitsWorkItemFlags) );
    __dmb(0xBu);
    if ( (v1 & 1) != 0 )
    {
      v0 = 1;
      v2 = 0;
    }
    else
    {
      v2 = 1;
    }
    result = PspEnforceLimits(v2);
    __dmb(0xBu);
    do
      v4 = __ldrex(PspJobTimeLimitsWorkItemFlags);
    while ( v4 == 4 && __strex(0, PspJobTimeLimitsWorkItemFlags) );
    __dmb(0xBu);
  }
  while ( v4 != 4 );
  if ( v0 )
    PspJobTimeLimitsCount = 7;
  return result;
}
