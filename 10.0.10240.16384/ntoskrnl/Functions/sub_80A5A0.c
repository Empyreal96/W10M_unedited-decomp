// sub_80A5A0 
 
void sub_80A5A0()
{
  int v0; // r7
  unsigned int v1; // r4
  int v2; // r2
  unsigned int *v3; // r5
  int v4; // r0
  int v5; // r6
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(v1 + 336);
  --*(_WORD *)(v1 + 308);
  v3 = (unsigned int *)(v2 + 168);
  v4 = KeAbPreAcquire(v2 + 168, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( !v6 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_DWORD *)(v1 + 1096) = v0;
  __dmb(0xBu);
  do
    v7 = __ldrex(v3);
  while ( v7 == 17 && __strex(0, v3) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(v3);
  v8 = KeAbPostRelease((unsigned int)v3);
  v9 = (__int16)(*(_WORD *)(v1 + 308) + 1);
  *(_WORD *)(v1 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v8);
  JUMPOUT(0x75FE02);
}
