// IopCleanupNotifications 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopCleanupNotifications(int a1, int a2)
{
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r2
  int result; // r0
  int *v8; // r5
  int *v9; // r6
  int v10; // r0
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r3
  int *v16; // r1 OVERLAPPED
  int **v17; // r2 OVERLAPPED

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&IopSessionNotificationLock, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)&IopSessionNotificationLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&IopSessionNotificationLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    return sub_528294(v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v8 = (int *)IopSessionNotificationQueueHead;
  while ( v8 != &IopSessionNotificationQueueHead )
  {
    v9 = v8;
    v10 = v8[2];
    v8 = (int *)*v8;
    if ( v10 == a1 && (!a2 || v9[5] == a2) )
    {
      ObfDereferenceObjectWithTag(v10);
      ExUnregisterCallback(v9[4]);
      *(_QWORD *)&v16 = *(_QWORD *)v9;
      if ( *(int **)(*v9 + 4) != v9 || *v17 != v9 )
        __fastfail(3u);
      *v17 = v16;
      v16[1] = (int)v17;
      ExFreePoolWithTag(v9, 0);
    }
  }
  __pld(&IopSessionNotificationLock);
  v11 = IopSessionNotificationLock;
  if ( (IopSessionNotificationLock & 0xFFFFFFF0) > 0x10 )
    v12 = IopSessionNotificationLock - 16;
  else
    v12 = 0;
  if ( (IopSessionNotificationLock & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&IopSessionNotificationLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&IopSessionNotificationLock) );
  if ( v13 != v11 )
LABEL_21:
    ExfReleasePushLock(&IopSessionNotificationLock, v11);
  result = KeAbPostRelease((unsigned int)&IopSessionNotificationLock);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
