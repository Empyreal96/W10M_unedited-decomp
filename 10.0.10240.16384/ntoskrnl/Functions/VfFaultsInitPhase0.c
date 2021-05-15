// VfFaultsInitPhase0 
 
int VfFaultsInitPhase0()
{
  int v0; // r0
  int v1; // r0
  int result; // r0

  ViFaultInjectionLock = 0;
  ViRequiredTimeSinceBootInMsecs = 60000i64 * (unsigned int)VfFaultInjectionBootMinutes;
  v0 = ViFaultsTracesInitialize();
  v1 = ViFaultsInitializeTagsList(v0);
  result = ViFaultsInitializeAppsList(v1);
  ViFaultsInitialized = 1;
  return result;
}
