// MmGetSectionRange 
 
int __fastcall MmGetSectionRange(unsigned int a1, _DWORD *a2, unsigned int *a3)
{
  int v3; // r6
  unsigned int v7; // r4
  int *v8; // r0
  int *v9; // r8
  int v10; // r0
  unsigned int v11; // r7
  int v12; // r0
  unsigned int v13; // r2
  _DWORD *v14; // r1
  unsigned int v15; // r5
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r0
  __int16 v20; // r3

  v3 = -1073741275;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v8 = MiLookupDataTableEntry(a1, 1);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8[6];
    v11 = a1 - v10;
    v12 = RtlImageNtHeader(v10);
    v13 = 0;
    v14 = (_DWORD *)(*(unsigned __int16 *)(v12 + 20) + v12 + 24);
    if ( *(_WORD *)(v12 + 6) )
    {
      while ( 1 )
      {
        v15 = v14[4];
        if ( v15 < v14[2] )
          v15 = v14[2];
        v16 = v14[3];
        if ( v11 >= v16 && v11 < v16 + v15 )
          break;
        ++v13;
        v14 += 10;
        if ( v13 >= *(unsigned __int16 *)(v12 + 6) )
          goto LABEL_10;
      }
      v17 = v9[6];
      v18 = v14[3];
      *a3 = v15;
      *a2 = v18 + v17;
      v3 = 0;
    }
  }
LABEL_10:
  v19 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v20 = *(_WORD *)(v7 + 308) + 1;
  *(_WORD *)(v7 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v3;
}
