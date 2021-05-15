// sub_802030 
 
void sub_802030()
{
  int v0; // r5
  unsigned int v1; // r9
  int v2; // r7
  unsigned int v3; // r1
  unsigned int v4; // r0
  int v5; // r0
  int v6; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 310);
  v2 = KeAbPreAcquire((unsigned int)&dword_632E10, 0, 0);
  do
    v3 = __ldrex((unsigned __int8 *)&dword_632E10);
  while ( __strex(v3 | 1, (unsigned __int8 *)&dword_632E10) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_632E10, v2, (unsigned int)&dword_632E10);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  RtlAvlRemoveNode((int)&dword_632E0C, v0);
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_632E10);
  while ( __strex(v4 - 1, (unsigned int *)&dword_632E10) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_632E10);
  v5 = KeAbPostRelease((unsigned int)&dword_632E10);
  v6 = (__int16)(*(_WORD *)(v1 + 310) + 1);
  *(_WORD *)(v1 + 310) = v6;
  if ( !v6 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(v5);
  JUMPOUT(0x74030C);
}
