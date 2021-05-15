// sub_7D68A4 
 
void sub_7D68A4()
{
  int v0; // r6
  int v1; // r8
  unsigned int v2; // r4
  unsigned __int8 *v3; // r5
  int v4; // r0
  int v5; // r7
  unsigned int v6; // r2
  unsigned int v7; // r1
  int v8; // r0
  int v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(v0 + 168);
  v4 = KeAbPreAcquire(v0 + 168, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & v1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v0 + 168), v4, v0 + 168);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= v1;
  if ( *(unsigned __int8 *)(v0 + 735) != 255 )
    ++*(_BYTE *)(v0 + 735);
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v3);
  while ( __strex(v7 - 1, (unsigned int *)v3) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v0 + 168));
  v8 = KeAbPostRelease(v0 + 168);
  v9 = (__int16)(*(_WORD *)(v2 + 308) + 1);
  *(_WORD *)(v2 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v8);
  JUMPOUT(0x6DE5F4);
}
