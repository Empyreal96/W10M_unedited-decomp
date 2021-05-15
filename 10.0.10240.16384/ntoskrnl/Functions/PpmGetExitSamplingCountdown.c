// PpmGetExitSamplingCountdown 
 
int PpmGetExitSamplingCountdown()
{
  int v0; // r0
  int result; // r0

  v0 = PpmExitLatencySamplingPercentage;
  if ( (unsigned int)PpmExitLatencySamplingPercentage > 0x64 )
    v0 = 100;
  if ( v0 )
    result = sub_529A54();
  else
    result = 0;
  return result;
}
