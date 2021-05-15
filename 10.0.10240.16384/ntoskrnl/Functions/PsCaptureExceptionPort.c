// PsCaptureExceptionPort 
 
int __fastcall PsCaptureExceptionPort(int a1)
{
  unsigned int v2; // r4
  unsigned int *v3; // r6
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r0
  __int16 v10; // r3

  if ( !*(_DWORD *)(a1 + 240) )
    return 0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned int *)(a1 + 168);
  v4 = KeAbPreAcquire(a1 + 168, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( !v6 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *(_DWORD *)(a1 + 240) & 0xFFFFFFF8;
  ObfReferenceObject(v7);
  __dmb(0xBu);
  do
    v8 = __ldrex(v3);
  while ( v8 == 17 && __strex(0, v3) );
  if ( v8 != 17 )
    ExfReleasePushLockShared(v3);
  v9 = KeAbPostRelease((unsigned int)v3);
  v10 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v7;
}
