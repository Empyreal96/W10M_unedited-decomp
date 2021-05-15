// PsGetCurrentSilo 
 
int PsGetCurrentSilo()
{
  unsigned int v0; // r5
  int v1; // r7
  unsigned int *v2; // r6
  int v3; // r0
  int v4; // r4
  int v5; // r1
  unsigned int v6; // r2
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  __int16 v10; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_DWORD *)(v0 + 0x150);
  --*(_WORD *)(v0 + 0x134);
  v2 = (unsigned int *)(v1 + 168);
  v3 = KeAbPreAcquire(v1 + 168, 0, 0);
  v4 = v3;
  v5 = 17;
  do
    v6 = __ldrex(v2);
  while ( !v6 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v6 )
    v3 = ExfAcquirePushLockSharedEx((_DWORD *)(v1 + 168), v3, v1 + 168);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v7 = *(_DWORD *)(v0 + 1096);
  if ( v7 == -3 )
    v7 = *(_DWORD *)(v1 + 804);
  if ( v7 )
    return sub_7C5584(v3, v5);
  __dmb(0xBu);
  do
    v8 = __ldrex(v2);
  while ( v8 == 17 && __strex(0, v2) );
  if ( v8 != 17 )
    ExfReleasePushLockShared((_DWORD *)(v1 + 168));
  v9 = KeAbPostRelease(v1 + 168);
  v10 = *(_WORD *)(v0 + 308) + 1;
  *(_WORD *)(v0 + 308) = v10;
  if ( v10 )
    return 0;
  if ( *(_DWORD *)(v0 + 100) != v0 + 100 && !*(_WORD *)(v0 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return 0;
}
