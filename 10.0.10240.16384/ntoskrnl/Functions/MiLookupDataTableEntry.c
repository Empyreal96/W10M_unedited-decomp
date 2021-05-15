// MiLookupDataTableEntry 
 
int *__fastcall MiLookupDataTableEntry(unsigned int a1, int a2)
{
  int *v2; // r5
  unsigned int v4; // r6
  int *v5; // r2
  unsigned int v6; // r1
  int v8; // r0
  int v9; // r3

  v2 = 0;
  if ( a2 )
  {
    v4 = 0;
  }
  else
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 308);
    ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  }
  v5 = (int *)PsLoadedModuleList;
  while ( 1 )
  {
    v6 = v5[6];
    if ( a1 >= v6 && a1 < v5[8] + v6 )
      break;
    v5 = (int *)*v5;
    if ( v5 == &PsLoadedModuleList )
      goto LABEL_9;
  }
  v2 = v5;
LABEL_9:
  if ( v4 )
  {
    v8 = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v9 = (__int16)(*(_WORD *)(v4 + 308) + 1);
    *(_WORD *)(v4 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  return v2;
}
