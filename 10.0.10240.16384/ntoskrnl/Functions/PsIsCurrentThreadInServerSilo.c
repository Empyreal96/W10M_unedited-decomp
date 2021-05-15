// PsIsCurrentThreadInServerSilo 
 
BOOL PsIsCurrentThreadInServerSilo()
{
  return PsEqualCurrentServerSilo(0) == 0;
}
