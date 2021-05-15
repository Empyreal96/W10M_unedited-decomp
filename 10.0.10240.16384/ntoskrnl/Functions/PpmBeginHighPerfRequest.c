// PpmBeginHighPerfRequest 
 
int PpmBeginHighPerfRequest()
{
  return PoSetPowerRequestInternal(PopTransitionHighPerfRequest, 4);
}
