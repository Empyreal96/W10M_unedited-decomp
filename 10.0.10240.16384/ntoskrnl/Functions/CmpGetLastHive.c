// CmpGetLastHive 
 
int CmpGetLastHive()
{
  void **v0; // r7
  int v1; // r0
  unsigned int v2; // r2
  void **i; // r4
  int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r2

  v0 = 0;
  v1 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( v2 )
    return sub_7E9438(v1, 17);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  for ( i = (void **)off_92078C; i != &CmpHiveListHead; i = (void **)i[1] )
  {
    if ( CmpReferenceHive((int)(i - 452)) )
    {
      v0 = i - 452;
      break;
    }
  }
  __pld(&CmpHiveListHeadLock);
  v5 = CmpHiveListHeadLock;
  if ( (CmpHiveListHeadLock & 0xFFFFFFF0) > 0x10 )
    v6 = CmpHiveListHeadLock - 16;
  else
    v6 = 0;
  if ( (CmpHiveListHeadLock & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&CmpHiveListHeadLock) );
  if ( v7 != v5 )
LABEL_22:
    ExfReleasePushLock(&CmpHiveListHeadLock, v5);
  KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
  return (int)v0;
}
