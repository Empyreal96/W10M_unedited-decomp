// PpmStopIllegalProcessorThrottleLogging 
 
int __fastcall PpmStopIllegalProcessorThrottleLogging(int a1)
{
  *(_BYTE *)(a1 + 3128) = 0;
  return 0;
}
