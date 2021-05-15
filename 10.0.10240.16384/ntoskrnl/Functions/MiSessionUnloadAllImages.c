// MiSessionUnloadAllImages 
 
int MiSessionUnloadAllImages()
{
  int v0; // r6
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r0

  v0 = MmAcquireLoadLock();
  v1 = PsLoadedModuleList;
  if ( (int *)PsLoadedModuleList != &PsLoadedModuleList )
  {
    do
    {
      if ( *(_DWORD *)(v1 + 24) >= (unsigned int)dword_63389C
        && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(*(_DWORD *)(v1 + 24))) == 1
         || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v2)) == 11)
        && MmIsDriverLoadedCurrentSession(v2) )
      {
        MmReleaseLoadLock(v0);
        MmUnloadSystemImage(v1);
        v3 = MmAcquireLoadLock();
        v1 = PsLoadedModuleList;
        v0 = v3;
      }
      else
      {
        v1 = *(_DWORD *)v1;
      }
    }
    while ( (int *)v1 != &PsLoadedModuleList );
  }
  return MmReleaseLoadLock(v0);
}
