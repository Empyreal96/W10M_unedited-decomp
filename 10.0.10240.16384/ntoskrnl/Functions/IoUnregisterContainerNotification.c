// IoUnregisterContainerNotification 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoUnregisterContainerNotification(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int *v6; // r2
  int *v7; // r5
  int v8; // r3
  int v9; // r1
  unsigned int v10; // r0
  int *v11; // r1 OVERLAPPED
  int **v12; // r2 OVERLAPPED
  unsigned int v13; // r2
  int result; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&IopSessionNotificationLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&IopSessionNotificationLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&IopSessionNotificationLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&IopSessionNotificationLock, v3, (unsigned int)&IopSessionNotificationLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = (int *)IopSessionNotificationQueueHead;
  while ( v6 != &IopSessionNotificationQueueHead )
  {
    v7 = v6;
    v8 = v6[4];
    v6 = (int *)*v6;
    if ( v8 == a1 )
    {
      ObfDereferenceObject(v7[2]);
      ExUnregisterCallback(a1);
      *(_QWORD *)&v11 = *(_QWORD *)v7;
      if ( *(int **)(*v7 + 4) != v7 || *v12 != v7 )
        __fastfail(3u);
      *v12 = v11;
      v11[1] = (int)v12;
      ExFreePoolWithTag((unsigned int)v7);
      break;
    }
  }
  __pld(&IopSessionNotificationLock);
  v9 = IopSessionNotificationLock;
  if ( (IopSessionNotificationLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  else
    v10 = IopSessionNotificationLock - 16;
  if ( (IopSessionNotificationLock & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&IopSessionNotificationLock);
  while ( v13 == v9 && __strex(v10, (unsigned int *)&IopSessionNotificationLock) );
  if ( v13 != v9 )
LABEL_22:
    ExfReleasePushLock(&IopSessionNotificationLock, v9);
  result = KeAbPostRelease((unsigned int)&IopSessionNotificationLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
