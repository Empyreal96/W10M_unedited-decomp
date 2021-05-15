// PiDmGetObjectCount 
 
int __fastcall PiDmGetObjectCount(int a1)
{
  void *v1; // r4
  unsigned int v2; // r2
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r1
  __int16 v6; // r3

  v1 = PiDmGetObjectManagerForObjectType(a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  ExAcquireResourceSharedLite((int)v1, 1);
  v3 = RtlNumberGenericTableElementsAvl((int)v1 + 56);
  v4 = ExReleaseResourceLite((int)v1);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    KiCheckForKernelApcDelivery(v4);
  return v3;
}
