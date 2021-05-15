// RtlPcToFilePath 
 
int __fastcall RtlPcToFilePath(unsigned int a1, unsigned __int16 *a2)
{
  unsigned int v4; // r2
  int *v5; // r2
  int v6; // r0
  unsigned int v7; // r1
  __int16 v8; // r3
  int *v10; // r4
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v5 = (int *)PsLoadedModuleList;
  if ( PsLoadedModuleList )
  {
    while ( v5 != &PsLoadedModuleList )
    {
      v10 = v5;
      v11 = v5[6];
      v5 = (int *)*v5;
      if ( a1 >= v11 && a1 < v10[8] + v11 )
      {
        RtlCopyUnicodeString(a2, (unsigned __int16 *)v10 + 18);
        v12 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
        v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v14 = *(_WORD *)(v13 + 0x134) + 1;
        *(_WORD *)(v13 + 308) = v14;
        if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
          KiCheckForKernelApcDelivery(v12);
        return 0;
      }
    }
  }
  v6 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v6);
  return -1073741275;
}
