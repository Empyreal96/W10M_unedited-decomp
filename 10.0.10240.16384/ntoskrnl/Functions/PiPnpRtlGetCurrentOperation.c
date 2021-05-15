// PiPnpRtlGetCurrentOperation 
 
int __fastcall PiPnpRtlGetCurrentOperation(int **a1)
{
  int v2; // r3
  unsigned int v3; // r5
  int *v4; // r4
  unsigned int v5; // r3
  int *i; // r2
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3);
  *a1 = 0;
  v3 = v2 & 0xFFFFFFC0;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  ExAcquireResourceSharedLite((int)&PiPnpRtlActiveOperationsLock, 1);
  for ( i = (int *)PiPnpRtlActiveOperations; i != &PiPnpRtlActiveOperations; v4 = 0 )
  {
    v4 = i;
    if ( i[2] == v3 )
      break;
    i = (int *)*i;
  }
  v7 = ExReleaseResourceLite((int)&PiPnpRtlActiveOperationsLock);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    return sub_7C69FC(v7);
  if ( !v4 )
    return -1073741275;
  *a1 = v4;
  return 0;
}
