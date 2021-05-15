// MiWriteProtectSystemImages 
 
int __fastcall MiWriteProtectSystemImages(int a1, int a2, int a3)
{
  unsigned int v3; // r5
  int v4; // r3
  int *i; // r4
  int result; // r0
  __int16 v7; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, a3, v4);
  for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
  {
    if ( i[15] )
      return sub_80EAE8();
    MiProtectSystemImage(i);
  }
  result = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v7 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
