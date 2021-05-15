// PpmCompareAndApplyPolicySettings 
 
int __fastcall PpmCompareAndApplyPolicySettings(_DWORD *a1)
{
  int v2; // r1
  unsigned int v3; // r0
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  if ( *a1 & 0xD8030FC0 | a1[1] & 0x3FF )
    return sub_804F50();
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
  v5 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return PpmReleaseLock(&PpmPerfPolicyLock);
}
