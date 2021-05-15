// sub_7C9190 
 
void sub_7C9190()
{
  int v0; // r8
  _DWORD *v1; // r9
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  unsigned __int8 v5; // r5
  unsigned int v6; // r1

  v2 = KeAbPreAcquire((unsigned int)&PnpNotificationInProgressLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PnpNotificationInProgressLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PnpNotificationInProgressLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PnpNotificationInProgressLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_62FB04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_62FB1C = v3;
  KeSetEvent((int)&PnpEventQueueEmpty, 0, 0);
  dword_62FB04 = 0;
  v5 = dword_62FB1C;
  *(_BYTE *)(v0 - 189) = 0;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&PnpNotificationInProgressLock);
  while ( !v6 && __strex(1u, (unsigned int *)&PnpNotificationInProgressLock) );
  if ( v6 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpNotificationInProgressLock, v6);
  KfLowerIrql(v5);
  KeAbPostRelease((unsigned int)&PnpNotificationInProgressLock);
  __dmb(0xBu);
  *v1 = 0;
  JUMPOUT(0x6CEE62);
}
