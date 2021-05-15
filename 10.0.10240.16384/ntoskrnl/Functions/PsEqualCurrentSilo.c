// PsEqualCurrentSilo 
 
BOOL __fastcall PsEqualCurrentSilo(int a1)
{
  unsigned int v2; // r4
  char v3; // r3
  BOOL v4; // r5
  int v5; // r8
  unsigned int *v6; // r6
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  int v10; // r3
  unsigned int v11; // r2
  int v12; // r0
  __int16 v13; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    v5 = *(_DWORD *)(v2 + 336);
    --*(_WORD *)(v2 + 308);
    v6 = (unsigned int *)(v5 + 168);
    v7 = KeAbPreAcquire(v5 + 168, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v6);
    while ( !v9 && __strex(0x11u, v6) );
    __dmb(0xBu);
    if ( v9 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v5 + 168), v7, v5 + 168);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    v10 = *(_DWORD *)(v2 + 1096);
    if ( v10 == -3 )
      v10 = *(_DWORD *)(v5 + 804);
    v4 = v10 == a1;
    __dmb(0xBu);
    do
      v11 = __ldrex(v6);
    while ( v11 == 17 && __strex(0, v6) );
    if ( v11 != 17 )
      ExfReleasePushLockShared((_DWORD *)(v5 + 168));
    v12 = KeAbPostRelease(v5 + 168);
    v13 = *(_WORD *)(v2 + 308) + 1;
    *(_WORD *)(v2 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
      KiCheckForKernelApcDelivery(v12);
  }
  else
  {
    __dmb(0xBu);
    v3 = PspDebugFlags;
    __dmb(0xBu);
    if ( (v3 & 2) != 0 )
      __debugbreak();
    v4 = a1 == 0;
  }
  return v4;
}
