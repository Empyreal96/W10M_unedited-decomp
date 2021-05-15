// PpmUpdateIdleDomains 
 
int __fastcall PpmUpdateIdleDomains(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r5
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PpmIdlePolicyLock, v3, (unsigned int)&PpmIdlePolicyLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 && (dword_681D78[0] & *(_DWORD *)(a1 + 16)) == *(_DWORD *)(a1 + 16) )
  {
    v6 = PopExecuteOnTargetProcessors(a1 + 8, (int)PpmInstallNewIdleDomains, a1, a1 + 8);
    if ( v6 >= 0 )
      v6 = 0;
  }
  else
  {
    v6 = -1073741811;
  }
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v7 = PpmIdlePolicyLock;
  v8 = PpmIdlePolicyLock - 16;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v9 != v7 )
LABEL_19:
    ExfReleasePushLock(&PpmIdlePolicyLock, v7);
  v10 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v6;
}
