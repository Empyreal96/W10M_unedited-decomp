// LdrpKrnGetDataTableEntry 
 
int __fastcall LdrpKrnGetDataTableEntry(unsigned int a1)
{
  int *v2; // r5
  int v3; // r3
  unsigned int v4; // r4
  int *v5; // r2
  unsigned int v6; // r1
  int v7; // r0
  int v8; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = v3 & 0xFFFFFFC0;
  if ( (v3 & 0xFFFFFFC0) == 0 )
    return 0;
  --*(_WORD *)((v3 & 0xFFFFFFC0) + 0x134);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v5 = (int *)PsLoadedModuleList;
  while ( 1 )
  {
    v6 = v5[6];
    if ( a1 >= v6 && a1 < v5[8] + v6 )
      break;
    v5 = (int *)*v5;
    if ( v5 == &PsLoadedModuleList )
      goto LABEL_6;
  }
  v2 = v5;
LABEL_6:
  v7 = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v8 = (__int16)(*(_WORD *)(v4 + 308) + 1);
  *(_WORD *)(v4 + 308) = v8;
  if ( !v8 )
    return sub_54DC60(v7);
  return (int)v2;
}
