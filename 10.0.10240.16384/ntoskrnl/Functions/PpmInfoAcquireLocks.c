// PpmInfoAcquireLocks 
 
int __fastcall PpmInfoAcquireLocks(int a1)
{
  int result; // r0
  unsigned int v2; // r2
  unsigned int v3; // r2

  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 )
    return PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  result = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  do
    v3 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    return sub_7C3660(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}
