// MiFreePartitionId 
 
int __fastcall MiFreePartitionId(unsigned int a1)
{
  unsigned int v2; // r7
  int v3; // r5
  unsigned int v4; // r1
  unsigned int v5; // r0
  int result; // r0
  __int16 v7; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = KeAbPreAcquire((unsigned int)algn_63431C, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)algn_63431C);
  while ( __strex(v4 | 1, (unsigned __int8 *)algn_63431C) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(algn_63431C, v3, (unsigned int)algn_63431C);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_BYTE *)((a1 >> 3) + *(_DWORD *)(dword_634330 + 4)) &= ~(unsigned __int8)(1 << (a1 & 7));
  *(_DWORD *)(dword_634340 + 4 * a1) = 0;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)algn_63431C);
  while ( __strex(v5 - 1, (unsigned int *)algn_63431C) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)algn_63431C);
  result = KeAbPostRelease((unsigned int)algn_63431C);
  v7 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v7;
  if ( !v7 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
