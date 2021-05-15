// sub_7E76FC 
 
void sub_7E76FC()
{
  int v0; // r3
  unsigned int *v1; // r2
  int v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r8
  unsigned __int8 *v5; // r7
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  __int16 v11; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = 0x2000000;
  --*(_WORD *)(v3 + 308);
  v5 = (unsigned __int8 *)(v2 + 168);
  v6 = KeAbPreAcquire(v2 + 168, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( __strex(v8 | 1, v5) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 168), v6, v2 + 168);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v0 = *(_DWORD *)(v2 + 404);
  __dmb(0xBu);
  if ( !v0 )
  {
    __dmb(0xBu);
    v1 = (unsigned int *)(v2 + 192);
    do
      v4 = __ldrex(v1);
    while ( __strex(v4 | 8, v1) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)v5);
  while ( __strex(v9 - 1, (unsigned int *)v5) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v2 + 168));
  v10 = KeAbPostRelease(v2 + 168);
  v11 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    KiCheckForKernelApcDelivery(v10);
  if ( (v4 & 0x2000000) == 0 )
    PspRundownProcess(v2);
  JUMPOUT(0x6F5284);
}
