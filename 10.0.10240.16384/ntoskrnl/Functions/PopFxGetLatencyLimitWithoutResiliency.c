// PopFxGetLatencyLimitWithoutResiliency 
 
int PopFxGetLatencyLimitWithoutResiliency()
{
  if ( byte_61EC4F )
    return sub_5299D4();
  if ( PpmDisableVsyncLatencyUpdate || !PopFxVSyncEnabled )
    return PpmLatencyToleranceLimit;
  return dword_681564;
}
