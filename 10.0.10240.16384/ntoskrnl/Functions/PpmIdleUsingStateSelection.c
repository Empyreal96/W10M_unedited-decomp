// PpmIdleUsingStateSelection 
 
int PpmIdleUsingStateSelection()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  unsigned __int8 *v4; // r3
  BOOL v5; // r5
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire(&PpmIdlePolicyLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( v2 )
    return sub_5299E0(v1, 17);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = *(unsigned __int8 **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1100);
  if ( v4 )
    v5 = *v4 == 1;
  else
    v5 = 0;
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v6 = PpmIdlePolicyLock;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
    v7 = PpmIdlePolicyLock - 16;
  else
    v7 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v8 != v6 )
LABEL_24:
    ExfReleasePushLock(&PpmIdlePolicyLock);
  v9 = KeAbPostRelease(&PpmIdlePolicyLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v5;
}
