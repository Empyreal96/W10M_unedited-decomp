// CmpUnlockHiveList 
 
unsigned int CmpUnlockHiveList()
{
  int v0; // r1
  unsigned int v1; // r0
  unsigned int v2; // r2

  __pld(&CmpHiveListHeadLock);
  v0 = CmpHiveListHeadLock;
  if ( (CmpHiveListHeadLock & 0xFFFFFFF0) > 0x10 )
    v1 = CmpHiveListHeadLock - 16;
  else
    v1 = 0;
  if ( (CmpHiveListHeadLock & 2) != 0 )
    goto LABEL_10;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( v2 == v0 && __strex(v1, (unsigned int *)&CmpHiveListHeadLock) );
  if ( v2 != v0 )
LABEL_10:
    ExfReleasePushLock(&CmpHiveListHeadLock, v0);
  return KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
}
