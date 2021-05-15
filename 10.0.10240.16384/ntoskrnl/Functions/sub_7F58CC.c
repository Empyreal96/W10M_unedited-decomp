// sub_7F58CC 
 
void sub_7F58CC()
{
  _DWORD *v0; // r6
  unsigned int v1; // r8
  unsigned int *v2; // r7
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r4
  unsigned int v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  __int16 v9; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = v0 + 1;
  v3 = KeAbPreAcquire((unsigned int)(v0 + 1), 0, 0);
  v4 = v3;
  do
    v5 = __ldrex(v2);
  while ( !v5 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(v0 + 1, v3, (unsigned int)(v0 + 1));
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = ObFastReferenceObjectLocked(v0);
  __dmb(0xBu);
  do
    v7 = __ldrex(v2);
  while ( v7 == 17 && __strex(0, v2) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(v0 + 1);
  v8 = KeAbPostRelease((unsigned int)(v0 + 1));
  v9 = *(_WORD *)(v1 + 308) + 1;
  *(_WORD *)(v1 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v8);
  if ( !v6 )
    JUMPOUT(0x716CAA);
  JUMPOUT(0x716C38);
}
