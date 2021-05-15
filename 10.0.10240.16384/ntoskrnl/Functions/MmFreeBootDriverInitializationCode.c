// MmFreeBootDriverInitializationCode 
 
int MmFreeBootDriverInitializationCode()
{
  int v0; // r4
  int v1; // r3
  int v2; // r2
  int *i; // r5
  int v4; // r0
  __int16 v5; // r3

  v0 = MmAcquireLoadLock();
  v1 = *(__int16 *)(v0 + 308) - 1;
  *(_WORD *)(v0 + 308) = v1;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v2, v1);
  for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
  {
    if ( (i[13] & 0x40000000) == 0 )
      MiFreeDriverInitialization((int)i);
  }
  v4 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v5 = *(_WORD *)(v0 + 308) + 1;
  *(_WORD *)(v0 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v0 + 100) != v0 + 100 && !*(_WORD *)(v0 + 310) )
    KiCheckForKernelApcDelivery(v4);
  return MmReleaseLoadLock(v0);
}
