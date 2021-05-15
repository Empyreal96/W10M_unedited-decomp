// KseResetDeviceCache 
 
int KseResetDeviceCache()
{
  int v0; // r3
  unsigned __int8 *v1; // r6
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned int *v6; // r4
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v0 = dword_6416D4;
  __dmb(0xBu);
  if ( v0 == 2 )
  {
    v1 = (unsigned __int8 *)dword_6416F8;
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v2 + 308);
    v3 = KeAbPreAcquire((unsigned int)v1, 0, 0);
    v4 = v3;
    do
      v5 = __ldrex(v1);
    while ( __strex(v5 | 1, v1) );
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v1, v3, (unsigned int)v1);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    KsepCacheReset(dword_6416F8);
    v6 = (unsigned int *)dword_6416F8;
    __dmb(0xBu);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 - 1, v6) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock(v6);
    v8 = KeAbPostRelease((unsigned int)v6);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  return 0;
}
