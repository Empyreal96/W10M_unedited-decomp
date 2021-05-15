// sub_7C5368 
 
void sub_7C5368()
{
  int v0; // r4
  int v1; // r6
  int v2; // r3
  int v3; // r5

  __dmb(0xFu);
  v2 = *(_DWORD *)(v0 + 944);
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
  {
    v3 = KeAbPreAcquire(v0 + 944, 0, 0);
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v0 + 944), v3, v0 + 944);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    ExfReleasePushLockExclusive((unsigned int *)(v0 + 944));
    if ( v3 )
      KeAbPostRelease(v0 + 944);
  }
  if ( (*(_DWORD *)(v0 + 960) & 2) == 0 || !PsIsThreadInSilo(v0, v1) )
    ObfDereferenceObject(v0);
  JUMPOUT(0x6C2974);
}
