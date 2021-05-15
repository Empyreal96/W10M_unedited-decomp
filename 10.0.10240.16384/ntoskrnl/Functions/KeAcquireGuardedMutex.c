// KeAcquireGuardedMutex 
 
int __fastcall KeAcquireGuardedMutex(unsigned int a1)
{
  int v2; // r4
  int result; // r0
  int v4; // r6
  unsigned int v5; // r2

  v2 = KeAbPreAcquire(a1, 0, 0);
  result = KfRaiseIrql(1);
  v4 = result;
  do
    v5 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    result = ExpAcquireFastMutexContended(a1, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1 + 28) = v4;
  return result;
}
