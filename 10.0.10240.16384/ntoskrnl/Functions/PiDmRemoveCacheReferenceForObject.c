// PiDmRemoveCacheReferenceForObject 
 
int __fastcall PiDmRemoveCacheReferenceForObject(int a1, int a2)
{
  int v3; // r5
  void *v4; // r6
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v3 = 0;
  v4 = PiDmGetObjectManagerForObjectType(a1);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  ExAcquireResourceExclusiveLite((int)v4, 1, v5, v6);
  v7 = PiDmLookupObject((int)v4, a2);
  if ( v7 )
  {
    if ( !--*(_DWORD *)(v7 + 8) )
      return sub_7C8E68();
  }
  else
  {
    v3 = -1073741772;
  }
  v9 = ExReleaseResourceLite((int)v4);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v3;
}
