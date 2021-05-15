// PpmContinueActiveTimeAccumulation 
 
int __fastcall PpmContinueActiveTimeAccumulation(int a1)
{
  PpmUpdateTimeAccumulation();
  return PpmUpdatePerformanceFeedback(a1, 0, 0, 0);
}
