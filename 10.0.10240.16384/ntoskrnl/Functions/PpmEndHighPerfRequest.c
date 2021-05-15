// PpmEndHighPerfRequest 
 
int __fastcall PpmEndHighPerfRequest(int a1, int a2)
{
  return PoClearPowerRequestInternalDeferred(PopTransitionHighPerfRequest, a2, PpmHighPerfDuration[a1]);
}
