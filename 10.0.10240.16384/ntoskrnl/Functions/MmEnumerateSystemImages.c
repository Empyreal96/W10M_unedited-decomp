// MmEnumerateSystemImages 
 
int __fastcall MmEnumerateSystemImages(int (__fastcall *a1)(int, int), int a2)
{
  int v2; // r6
  int v4; // r8
  int v5; // r0
  __int16 v6; // r3
  int v8; // [sp+4h] [bp-44h]

  PsIsSystemProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v8 = MmAcquireLoadLock();
  --*(_WORD *)(v8 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v2 = PsLoadedModuleList;
  do
  {
    if ( MmIsSessionAddress(*(_DWORD *)(v2 + 24)) )
      return sub_7D0140();
    v4 = a1(v2, a2);
    if ( v4 < 0 )
      break;
    v2 = *(_DWORD *)v2;
  }
  while ( (int *)v2 != &PsLoadedModuleList );
  v5 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v6 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v5);
  MmReleaseLoadLock(v8);
  return v4;
}
