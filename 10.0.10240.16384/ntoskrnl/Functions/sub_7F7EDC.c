// sub_7F7EDC 
 
void sub_7F7EDC()
{
  int v0; // r4
  int v1; // r9
  int v2; // r3
  int v3; // r5

  __dmb(0xFu);
  v2 = *(_DWORD *)(v0 - 4);
  __dmb(0xBu);
  if ( (v2 & v1) != 0 )
  {
    v3 = KeAbPreAcquire(v0 - 4, 0, 0);
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v0 - 4), v3, v0 - 4);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= v1;
    ExfReleasePushLockExclusive((unsigned int *)(v0 - 4));
    if ( v3 )
      KeAbPostRelease(v0 - 4);
  }
  JUMPOUT(0x72190E);
}
