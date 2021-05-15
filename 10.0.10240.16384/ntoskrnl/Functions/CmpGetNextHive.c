// CmpGetNextHive 
 
int __fastcall CmpGetNextHive(int a1)
{
  void **v2; // r7
  void ***v3; // r9
  int v4; // r0
  unsigned int v5; // r2
  void **v6; // r5
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2

  v2 = 0;
  if ( a1 )
    v3 = (void ***)(a1 + 1808);
  else
    v3 = (void ***)&CmpHiveListHead;
  v4 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  do
    v5 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( v5 )
    return sub_7C3378(v4, 17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = *v3;
  while ( v6 != &CmpHiveListHead )
  {
    v2 = v6 - 452;
    if ( CmpReferenceHive((int)(v6 - 452)) )
      break;
    v6 = (void **)*v6;
    v2 = 0;
  }
  __pld(&CmpHiveListHeadLock);
  v7 = CmpHiveListHeadLock;
  if ( (CmpHiveListHeadLock & 0xFFFFFFF0) > 0x10 )
    v8 = CmpHiveListHeadLock - 16;
  else
    v8 = 0;
  if ( (CmpHiveListHeadLock & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpHiveListHeadLock) );
  if ( v9 != v7 )
LABEL_24:
    ExfReleasePushLock(&CmpHiveListHeadLock, v7);
  KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
  if ( a1 )
    CmpDereferenceHive(a1);
  return (int)v2;
}
