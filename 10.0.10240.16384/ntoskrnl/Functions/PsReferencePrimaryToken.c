// PsReferencePrimaryToken 
 
int __fastcall PsReferencePrimaryToken(int a1)
{
  unsigned int v2; // r4
  unsigned int v4; // r6
  unsigned int *v5; // r7
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r3

  v2 = ObFastReferenceObject((_DWORD *)(a1 + 244));
  if ( v2 )
    return v2;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 0x134);
  v5 = (unsigned int *)(a1 + 168);
  v6 = KeAbPreAcquire(a1 + 168, 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( !v7 )
  {
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v2 = ObFastReferenceObjectLocked((_DWORD *)(a1 + 244));
    __dmb(0xBu);
    do
      v8 = __ldrex(v5);
    while ( v8 == 17 && __strex(0, v5) );
    if ( v8 != 17 )
      ExfReleasePushLockShared((_DWORD *)(a1 + 168));
    v9 = KeAbPostRelease(a1 + 168);
    v10 = (__int16)(*(_WORD *)(v4 + 308) + 1);
    *(_WORD *)(v4 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v9);
    return v2;
  }
  return sub_7BE730(v6, 17);
}
