// CcUnmapAndPurge 
 
unsigned int __fastcall CcUnmapAndPurge(int a1, int a2)
{
  int *v2; // r5
  int v5; // r4
  int v6; // r1
  unsigned int result; // r0

  v2 = (int *)(a1 + 68);
  v5 = ObFastReferenceObject((_DWORD *)(a1 + 68));
  if ( !v5 )
    v5 = CcSlowReferenceSharedCacheMapFileObject(a1);
  CcUnmapVacbArray(a1, 0, 0, a2, 1u);
  if ( (*(_DWORD *)(a1 + 96) & 0x10) != 0 )
    CcPurgeCacheSection(*(_DWORD *)(v5 + 20), 0, 0, 2);
  __pld(v2);
  v6 = *v2;
  if ( (*v2 ^ (unsigned int)v5) >= 7 )
    return ObDereferenceObjectDeferDeleteWithTag(v5);
  __dmb(0xBu);
  do
    result = __ldrex((unsigned int *)v2);
  while ( result == v6 && __strex(v6 + 1, (unsigned int *)v2) );
  if ( result != v6 )
    result = sub_53E564();
  return result;
}
