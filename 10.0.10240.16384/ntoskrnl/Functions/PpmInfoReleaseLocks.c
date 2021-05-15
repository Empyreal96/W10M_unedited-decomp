// PpmInfoReleaseLocks 
 
int __fastcall PpmInfoReleaseLocks(int a1)
{
  int result; // r0
  int v2; // r1
  unsigned int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r1
  int v6; // r3

  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 )
    return PpmReleaseLock(&PpmPerfPolicyLock);
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v2 = PpmIdlePolicyLock;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
    v3 = PpmIdlePolicyLock - 16;
  else
    v3 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_16;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v4 == v2 && __strex(v3, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v4 != v2 )
LABEL_16:
    ExfReleasePushLock(&PpmIdlePolicyLock, v2);
  result = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
