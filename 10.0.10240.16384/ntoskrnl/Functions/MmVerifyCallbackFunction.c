// MmVerifyCallbackFunction 
 
int __fastcall MmVerifyCallbackFunction(unsigned int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r0
  int v5; // r1
  unsigned int v6; // r4
  int v7; // r5
  int *v8; // r0
  int v9; // r0
  __int16 v10; // r3

  if ( a1 >= dword_63389C )
  {
    v2 = MiGetSystemRegionIndex(a1);
    if ( *(_BYTE *)(v2 + v3 + 9692) == 1 )
      return 0;
    v4 = MiGetSystemRegionIndex(a1);
    if ( *(_BYTE *)(v4 + v5 + 9692) == 11 )
      return 0;
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = 0;
  --*(_WORD *)(v6 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v8 = MiLookupDataTableEntry(a1, 1);
  if ( v8 && (v8[13] & 0x20) != 0 )
    v7 = 1;
  v9 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v10 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v7;
}
