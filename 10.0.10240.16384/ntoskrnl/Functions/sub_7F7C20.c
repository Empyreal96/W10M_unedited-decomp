// sub_7F7C20 
 
void sub_7F7C20()
{
  int v0; // r6
  int v1; // r8
  int v2; // r5
  unsigned int *v3; // r7
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2

  v2 = *(_DWORD *)(v1 + 8);
  v3 = (unsigned int *)(v2 - 4);
  v4 = KeAbPreAcquire(v2 - 4, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( !v6 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx((_DWORD *)(v2 - 4), v4, v2 - 4);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  if ( v1 != v0 )
    JUMPOUT(0x7210DE);
  JUMPOUT(0x72109E);
}
