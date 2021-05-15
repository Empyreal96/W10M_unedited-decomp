// KeTryToAcquireGuardedMutexAtDpc 
 
int __fastcall KeTryToAcquireGuardedMutexAtDpc(unsigned int a1)
{
  int v2; // r0
  unsigned int v3; // r2

  v2 = KeAbPreAcquire(a1, 0, 1);
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    return sub_555850(v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return 1;
}
