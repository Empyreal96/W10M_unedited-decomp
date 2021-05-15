// ExReleaseFastMutexUnsafeAndLeaveCriticalRegion 
 
int __fastcall ExReleaseFastMutexUnsafeAndLeaveCriticalRegion(unsigned int *a1)
{
  unsigned int v1; // r1
  int result; // r0
  unsigned int v3; // r1
  __int16 v4; // r3

  a1[1] = 0;
  __dmb(0xBu);
  do
    v1 = __ldrex(a1);
  while ( !v1 && __strex(1u, a1) );
  if ( v1 )
    return sub_5257F0(a1, v1, 1);
  result = KeAbPostRelease(a1);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_WORD *)(v3 + 0x134) + 1;
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
