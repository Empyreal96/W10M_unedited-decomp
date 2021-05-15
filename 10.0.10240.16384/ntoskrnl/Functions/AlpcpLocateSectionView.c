// AlpcpLocateSectionView 
 
int __fastcall AlpcpLocateSectionView(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned int *v5; // r6
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r2

  *a4 = 0;
  v5 = (unsigned int *)(a2 + 208);
  do
  {
    v6 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v5);
    while ( !v8 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v8 )
      ExfAcquirePushLockSharedEx(v5, v6, (unsigned int)v5);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = AlpcpEnumerateResourcesPort(a2);
    __dmb(0xBu);
    do
      v10 = __ldrex(v5);
    while ( v10 == 17 && __strex(0, v5) );
    if ( v10 != 17 )
      ExfReleasePushLockShared(v5);
    KeAbPostRelease((unsigned int)v5);
  }
  while ( v9 == -1073741267 );
  return -1073741503;
}
