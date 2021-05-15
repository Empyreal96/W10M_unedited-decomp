// ViInitSystemPhase1 
 
int ViInitSystemPhase1()
{
  int result; // r0
  int v1; // r3
  unsigned int v2; // r4

  if ( ViVerifierEnabled )
    return sub_96F268();
  result = PsSetCreateProcessNotifyRoutine((int)ViCreateProcessCallback, 0);
  if ( (ViImageExecutionOptions & 0xFFFFFFFE) == 0 && (ViImageExecutionOptions & 1) != 0 )
  {
    __dmb(0xBu);
    v1 = ViImageExecutionOptions;
    do
    {
      v2 = __ldrex((unsigned int *)0xFFFF93A0);
      result = v2 | v1;
    }
    while ( __strex(v2 | v1, (unsigned int *)0xFFFF93A0) );
    __dmb(0xBu);
  }
  return result;
}
