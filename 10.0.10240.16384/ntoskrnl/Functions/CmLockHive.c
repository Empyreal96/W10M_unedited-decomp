// CmLockHive 
 
int __fastcall CmLockHive(int a1)
{
  unsigned int v1; // r5
  unsigned int v2; // r6
  int result; // r0
  int v4; // r4
  unsigned int v5; // r2

  v1 = *(_DWORD *)(a1 + 1864);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire(v1, 0, 0);
  v4 = result;
  do
    v5 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    result = ExpAcquireFastMutexContended(v1, result);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = v2;
  return result;
}
