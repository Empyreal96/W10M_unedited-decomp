// CmpOKToFollowLink 
 
int __fastcall CmpOKToFollowLink(int a1, int a2)
{
  int v5; // r0
  int v6; // r7
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2

  if ( !a1 || a1 == a2 )
    return 1;
  if ( (*(_DWORD *)(a2 + 3228) & 1) == 0 )
    JUMPOUT(0x7FD25E);
  v5 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( !v7 && __strex(0x11u, (unsigned int *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(&CmpHiveListHeadLock, v5, (unsigned int)&CmpHiveListHeadLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = *(_DWORD *)(a2 + 3232);
  if ( v8 == a2 + 3232 )
    JUMPOUT(0x7FD21E);
  if ( v8 - 3232 == a1 )
  {
    __pld(&CmpHiveListHeadLock);
    v9 = CmpHiveListHeadLock;
    if ( (CmpHiveListHeadLock & 0xFFFFFFF0) > 0x10 )
      v10 = CmpHiveListHeadLock - 16;
    else
      v10 = 0;
    if ( (CmpHiveListHeadLock & 2) != 0 )
      goto LABEL_24;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
    while ( v11 == v9 && __strex(v10, (unsigned int *)&CmpHiveListHeadLock) );
    if ( v11 != v9 )
LABEL_24:
      ExfReleasePushLock(&CmpHiveListHeadLock, v9);
    KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
    return 1;
  }
  return sub_7FD214();
}
