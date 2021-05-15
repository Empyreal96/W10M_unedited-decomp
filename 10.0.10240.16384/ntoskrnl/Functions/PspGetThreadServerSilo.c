// PspGetThreadServerSilo 
 
int __fastcall PspGetThreadServerSilo(int a1)
{
  int v1; // r7
  unsigned int v3; // r4
  unsigned int *v4; // r6
  int v5; // r0
  int v6; // r5
  int v7; // r1
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v11; // r2
  int v12; // r0
  __int16 v13; // r3

  v1 = *(_DWORD *)(a1 + 336);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 0x134);
  v4 = (unsigned int *)(v1 + 168);
  v5 = KeAbPreAcquire(v1 + 168, 0, 0);
  v6 = v5;
  v7 = 17;
  do
    v8 = __ldrex(v4);
  while ( !v8 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(v1 + 168, v5, v1 + 168);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = *(_DWORD *)(a1 + 1096);
  if ( v9 == -3 )
    v9 = *(_DWORD *)(v1 + 804);
  if ( PspGetServerSiloForSilo(v9, v7) )
    return sub_517440();
  __dmb(0xBu);
  do
    v11 = __ldrex(v4);
  while ( v11 == 17 && __strex(0, v4) );
  if ( v11 != 17 )
    ExfReleasePushLockShared(v1 + 168, 0);
  v12 = KeAbPostRelease(v1 + 168);
  v13 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v13;
  if ( v13 )
    return 0;
  if ( *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return 0;
}
