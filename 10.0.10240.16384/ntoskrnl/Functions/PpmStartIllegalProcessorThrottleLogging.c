// PpmStartIllegalProcessorThrottleLogging 
 
int __fastcall PpmStartIllegalProcessorThrottleLogging(int a1)
{
  *(_BYTE *)(a1 + 3128) = 1;
  *(_BYTE *)(a1 + 3136) = 0;
  return 0;
}
