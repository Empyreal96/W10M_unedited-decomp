// ExAcquireFastMutexUnsafe 
 
int __fastcall ExAcquireFastMutexUnsafe(unsigned int a1)
{
  unsigned int v2; // r6
  int result; // r0
  int v4; // r4
  unsigned int v5; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire(a1, 0, 0);
  v4 = result;
  do
    v5 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    result = ExpAcquireFastMutexContended(a1, result);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = v2;
  return result;
}
