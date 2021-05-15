// MiCancelPhase0Locking 
 
int __fastcall MiCancelPhase0Locking(int result, int a2, int a3)
{
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r3
  int v6; // r3

  v3 = result;
  if ( (*(_DWORD *)(result + 52) & 0x400000) != 0 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = *(__int16 *)(v4 + 0x134) - 1;
    *(_WORD *)(v4 + 308) = v5;
    ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, a3, v5);
    if ( (*(_DWORD *)(v3 + 52) & 0x400000) != 0 )
    {
      MiLockPagableSections(v3, 0);
      *(_DWORD *)(v3 + 52) &= 0xFFBFFFFF;
    }
    result = ExReleaseResourceLite((int)&PsLoadedModuleResource);
    v6 = (__int16)(*(_WORD *)(v4 + 308) + 1);
    *(_WORD *)(v4 + 308) = v6;
    if ( !v6 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
