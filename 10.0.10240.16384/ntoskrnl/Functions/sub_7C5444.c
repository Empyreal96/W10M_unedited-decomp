// sub_7C5444 
 
void sub_7C5444()
{
  int v0; // r4
  int v1; // r6
  int v2; // r3
  int v3; // r5

  __dmb(0xFu);
  v2 = *(_DWORD *)(v0 + 168);
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
  {
    v3 = KeAbPreAcquire(v0 + 168, 0, 0);
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v0 + 168), v3, v0 + 168);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    ExfReleasePushLockExclusive((unsigned int *)(v0 + 168));
    if ( v3 )
      KeAbPostRelease(v0 + 168);
  }
  if ( (*(_DWORD *)(v0 + 192) & 0x4000000) == 0 || !PsIsProcessInSilo(v0, v1) )
    ObfDereferenceObjectWithTag(v0);
  JUMPOUT(0x6C29F4);
}
