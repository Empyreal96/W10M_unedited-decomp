// PnpDeferNotification 
 
int __fastcall PnpDeferNotification(int a1)
{
  int v2; // r8
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  int v9; // r0
  void **v10; // r7
  int v11; // r6
  int v12; // r9
  unsigned int v13; // r2
  void ***v14; // r1
  unsigned __int8 v15; // r6
  unsigned int v16; // r1

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&PnpNotificationInProgressLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)&PnpNotificationInProgressLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PnpNotificationInProgressLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_7F1C60(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_62FB04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_62FB1C = v4;
  if ( PnpNotificationInProgress )
  {
    v9 = ExAllocatePoolWithTag(1, 12, 930115152);
    v10 = (void **)v9;
    if ( v9 )
    {
      *(_DWORD *)(v9 + 8) = a1;
      ++*(_WORD *)(a1 + 32);
      *(_BYTE *)(a1 + 34) = 1;
      v11 = KeAbPreAcquire((unsigned int)&PnpDeferredRegistrationLock, 0, 0);
      v12 = KfRaiseIrql(1);
      do
        v13 = __ldrex((unsigned __int8 *)&PnpDeferredRegistrationLock);
      while ( __strex(v13 & 0xFE, (unsigned __int8 *)&PnpDeferredRegistrationLock) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PnpDeferredRegistrationLock, v11);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      dword_630D64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = (void ***)off_9209F4;
      dword_630D7C = v12;
      *v10 = &PnpDeferredRegistrationList;
      v10[1] = v14;
      if ( *v14 != &PnpDeferredRegistrationList )
        __fastfail(3u);
      *v14 = v10;
      dword_630D64 = 0;
      v15 = dword_630D7C;
      off_9209F4 = v10;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&PnpDeferredRegistrationLock);
      while ( !v16 && __strex(1u, (unsigned int *)&PnpDeferredRegistrationLock) );
      if ( v16 )
        ExpReleaseFastMutexContended((unsigned int *)&PnpDeferredRegistrationLock, v16);
      KfLowerIrql(v15);
      KeAbPostRelease((unsigned int)&PnpDeferredRegistrationLock);
    }
    else
    {
      v2 = -1073741670;
    }
  }
  dword_62FB04 = 0;
  v7 = dword_62FB1C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PnpNotificationInProgressLock);
  while ( !v8 && __strex(1u, (unsigned int *)&PnpNotificationInProgressLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpNotificationInProgressLock, v8);
  KfLowerIrql(v7);
  KeAbPostRelease((unsigned int)&PnpNotificationInProgressLock);
  return v2;
}
