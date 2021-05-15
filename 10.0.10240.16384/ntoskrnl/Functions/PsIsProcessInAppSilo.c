// PsIsProcessInAppSilo 
 
BOOL __fastcall PsIsProcessInAppSilo(int a1)
{
  unsigned int v2; // r5
  unsigned int *v3; // r6
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r0
  BOOL v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  __int16 v11; // r3

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
  v7 = PsGetProcessSilo(a1);
  v8 = v7 && !*(_DWORD *)(v7 + 144);
  __dmb(0xBu);
  do
    v9 = __ldrex(v3);
  while ( v9 == 17 && __strex(0, v3) );
  if ( v9 != 17 )
    ExfReleasePushLockShared(v3);
  v10 = KeAbPostRelease((unsigned int)v3);
  v11 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v8;
}
