// MmBackSystemImageWithPagefile 
 
int __fastcall MmBackSystemImageWithPagefile(unsigned int a1)
{
  unsigned int v2; // r5
  int *v3; // r4
  int v4; // r0
  __int16 v5; // r3
  int v6; // r6
  int v7; // r5

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v3 = MiLookupDataTableEntry(a1, 1);
  v4 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v5 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    v4 = KiCheckForKernelApcDelivery(v4);
  if ( !v3 )
    sub_80C374(v4);
  v6 = MmAcquireLoadLock();
  if ( (v3[28] & 3) != 0 )
  {
    v7 = 0;
  }
  else
  {
    v7 = MiBackSystemImageWithPagefile(v3, 0);
    if ( v7 >= 0 )
      v3[28] = v3[28] & 0xFFFFFFFC | 2;
  }
  MmReleaseLoadLock(v6);
  return v7;
}
