// SmcCacheRemove 
 
int __fastcall SmcCacheRemove(int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  unsigned __int8 *v3; // r6
  int v4; // r7
  unsigned int v5; // r8
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  unsigned int *v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v2 = (_DWORD *)(a1 + 16 * (a2 & 0xF));
  v3 = (unsigned __int8 *)(v2 + 2);
  v4 = 0;
  v5 = a2 >> 4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)(v2 + 2), 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v3);
  while ( __strex(v9 | 1, v3) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v2 + 2, v7, (unsigned int)(v2 + 2));
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( v5 == (v2[3] & 0xFFF) && *v2 )
  {
    v10 = v2 + 1;
    do
      v11 = __ldrex(v10);
    while ( !v11 && __strex(1u, v10) );
    __dmb(0xBu);
    if ( v11 && v11 != 1 )
      ExfWaitForRundownProtectionRelease(v10, v11);
    v4 = *v2;
    *v2 = 0;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v3);
  while ( __strex(v12 - 1, (unsigned int *)v3) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock(v2 + 2);
  v13 = KeAbPostRelease((unsigned int)(v2 + 2));
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v4;
}
