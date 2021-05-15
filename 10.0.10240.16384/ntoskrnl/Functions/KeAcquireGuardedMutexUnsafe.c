// KeAcquireGuardedMutexUnsafe 
 
int __fastcall KeAcquireGuardedMutexUnsafe(int a1)
{
  unsigned int v2; // r6
  int result; // r0
  unsigned int v4; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire(a1, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    return sub_50B888(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = v2;
  return result;
}
