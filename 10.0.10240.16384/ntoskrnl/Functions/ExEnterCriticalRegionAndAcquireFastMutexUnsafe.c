// ExEnterCriticalRegionAndAcquireFastMutexUnsafe 
 
int __fastcall ExEnterCriticalRegionAndAcquireFastMutexUnsafe(int a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r6
  int result; // r0
  unsigned int v5; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire(a1, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_524F3C(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = v3;
  return result;
}
