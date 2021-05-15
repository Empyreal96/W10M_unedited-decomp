// MmWaitForCacheManagerPrefetch 
 
int __fastcall MmWaitForCacheManagerPrefetch(_DWORD *a1)
{
  _DWORD *v1; // r6
  int v2; // r5
  BOOL v3; // r4
  _DWORD *v4; // r8
  int v5; // r7
  int v6; // r0
  unsigned int v7; // r1
  __int16 v8; // r3

  v1 = a1;
  v2 = 0;
  v3 = (a1[11] & 1) != 0;
  do
  {
    v4 = (_DWORD *)*v1;
    v5 = MiPfCompletePrefetchIos(v1 + 14, 0, 0);
    MiReleaseReadListResources(v1);
    v6 = ExFreePoolWithTag(v1, 0);
    v1 = v4;
    if ( v5 < 0 )
      v2 = v5;
  }
  while ( v4 );
  if ( v3 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v8 = *(_WORD *)(v7 + 0x136) + 1;
    *(_WORD *)(v7 + 310) = v8;
    if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v6);
  }
  return v2;
}
