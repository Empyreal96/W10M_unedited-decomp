// UnlockShutdown 
 
unsigned int UnlockShutdown()
{
  int v0; // r1
  unsigned int v1; // r0
  unsigned int v2; // r2
  unsigned int result; // r0
  unsigned int v4; // r1
  int v5; // r3

  __pld(&CmpShutdownLock);
  v0 = CmpShutdownLock;
  if ( (CmpShutdownLock & 0xFFFFFFF0) > 0x10 )
    v1 = CmpShutdownLock - 16;
  else
    v1 = 0;
  if ( (CmpShutdownLock & 2) != 0 )
    goto LABEL_11;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&CmpShutdownLock);
  while ( v2 == v0 && __strex(v1, (unsigned int *)&CmpShutdownLock) );
  if ( v2 != v0 )
LABEL_11:
    ExfReleasePushLock(&CmpShutdownLock, v0);
  result = KeAbPostRelease((unsigned int)&CmpShutdownLock);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (__int16)(*(_WORD *)(v4 + 0x134) + 1);
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 )
    result = sub_7D2AF4(result);
  return result;
}
