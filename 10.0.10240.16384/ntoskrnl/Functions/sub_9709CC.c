// sub_9709CC 
 
void sub_9709CC()
{
  int v0; // r4
  unsigned int v1; // r6
  unsigned int *v2; // r7
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = (unsigned int *)(v0 - 4);
  v3 = KeAbPreAcquire(v0 - 4, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex(v2);
  while ( !v5 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx((_DWORD *)(v0 - 4), v3, v0 - 4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  ObFastReferenceObjectLocked((_DWORD *)(v0 - 8));
  __dmb(0xBu);
  do
    v6 = __ldrex(v2);
  while ( v6 == 17 && __strex(0, v2) );
  if ( v6 != 17 )
    ExfReleasePushLockShared((_DWORD *)(v0 - 4));
  v7 = KeAbPostRelease(v0 - 4);
  v8 = (__int16)(*(_WORD *)(v1 + 308) + 1);
  *(_WORD *)(v1 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v7);
  JUMPOUT(0x964754);
}
