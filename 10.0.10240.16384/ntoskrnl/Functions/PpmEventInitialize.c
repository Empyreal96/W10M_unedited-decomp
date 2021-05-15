// PpmEventInitialize 
 
int PpmEventInitialize()
{
  int result; // r0

  result = EtwRegister((int)PPM_ETW_PROVIDER, (int)PpmEventTraceControlCallback, 0);
  if ( result >= 0 )
  {
    result = 0;
    PpmEtwRegistered = 1;
  }
  return result;
}
