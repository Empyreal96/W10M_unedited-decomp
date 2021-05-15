// PiUEventNotifyUserMode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiUEventNotifyUserMode(_DWORD *a1)
{
  char v1; // r5
  int v2; // r7
  BOOL v5; // r10
  _BYTE *v6; // r0
  _DWORD *v7; // r4
  int v8; // r0
  _DWORD *v9; // r3
  int v10; // r3
  int v11; // r9
  int v12; // r1
  unsigned int v13; // r2
  BOOL v14; // r9
  int **v15; // r1
  unsigned int v16; // r1
  _DWORD *v17; // r0
  int v18; // r7
  int v19; // r6
  int v20; // r9
  unsigned int v21; // r2
  unsigned __int8 v22; // r6
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r3
  int v26; // r6
  int v27; // r8
  unsigned int v28; // r2
  int v29; // r1 OVERLAPPED
  _DWORD *v30; // r2 OVERLAPPED
  unsigned __int8 v31; // r6
  unsigned int v32; // r1
  char v33[4]; // [sp+10h] [bp-38h] BYREF
  int v34; // [sp+14h] [bp-34h] BYREF
  unsigned int v35[2]; // [sp+18h] [bp-30h] BYREF
  int v36[10]; // [sp+20h] [bp-28h] BYREF

  v34 = 0;
  v33[0] = 0;
  v1 = 0;
  v2 = 0;
  v35[0] = 0;
  if ( dword_630874 )
    return sub_7C9434();
  if ( a1[20] == 4 && PiUEventDeviceNeedsInstall(a1 + 25, v33) >= 0 && v33[0] )
  {
    PiUEventSendDeviceInstallNotification(a1 + 25);
  }
  else if ( a1[20] == 2 && !memcmp((unsigned int)(a1 + 16), (unsigned int)&GUID_DEVICE_INTERFACE_ARRIVAL, 16) )
  {
    PiUEventSendDeviceInterfaceArrivalETWEvent(a1 + 25, a1 + 29);
  }
  if ( PiUEventShouldQueueEvent((int)a1) )
  {
    v5 = PiUEventIsDeviceEventVetoable((int)a1);
    v34 = a1[23] + 44;
    v6 = (_BYTE *)ExAllocatePoolWithTag(1, v34, 1500540496);
    v7 = v6;
    if ( !v6 )
      return -1073741670;
    memset(v6, 0, v34);
    v8 = ExAllocatePoolWithTag(512, 32, 1500540496);
    v7[2] = v8;
    if ( v8 )
    {
      KeInitializeGuardedMutex(v8);
      v7[7] = 1;
      *((_BYTE *)v7 + 41) = v5;
      if ( v5 )
      {
        v7[4] = a1[6];
        v25 = a1[7];
        v7[5] = v25;
        **(_WORD **)(v25 + 4) = 0;
        *(_WORD *)v7[5] = 0;
        *(_DWORD *)v7[4] = 0;
      }
      else
      {
        v9 = (_DWORD *)a1[6];
        if ( v9 )
          *v9 = 0;
        v10 = a1[7];
        if ( v10 )
        {
          **(_WORD **)(v10 + 4) = 0;
          *(_WORD *)a1[7] = 0;
        }
      }
      if ( a1[3] || v5 )
      {
        v1 = 1;
        v35[0] = 1;
        v24 = ExAllocatePoolWithTag(512, 16, 1500540496);
        v7[3] = v24;
        if ( !v24 )
        {
          v2 = -1073741670;
LABEL_75:
          if ( v7[3] )
            PiUEventDereferenceEventEntry((int)v7);
          goto LABEL_77;
        }
        KeInitializeEvent(v24, 0, 0);
        PiUEventReferenceEventEntry(v7);
      }
      *((_BYTE *)v7 + 40) = v1;
      v7[9] = a1[23] + 8;
      memmove((int)(v7 + 11), (int)(a1 + 16), a1[23]);
      PiUEventCacheObjectProperties(v7);
      v11 = KeAbPreAcquire((unsigned int)&PiUEventUsermodeEventQueueLock, 0, 0);
      v12 = KfRaiseIrql(1);
      v36[0] = v12;
      do
        v13 = __ldrex((unsigned __int8 *)&PiUEventUsermodeEventQueueLock);
      while ( __strex(v13 & 0xFE, (unsigned __int8 *)&PiUEventUsermodeEventQueueLock) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
      {
        ExpAcquireFastMutexContended((int)&PiUEventUsermodeEventQueueLock, v11);
        v12 = v36[0];
      }
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      dword_630B04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_630B1C = v12;
      v14 = PiUEventUsermodeEventQueue == (_DWORD)&PiUEventUsermodeEventQueue;
      v15 = (int **)dword_630B24;
      *v7 = &PiUEventUsermodeEventQueue;
      v7[1] = v15;
      if ( *v15 != &PiUEventUsermodeEventQueue )
        __fastfail(3u);
      *v15 = v7;
      dword_630B04 = 0;
      dword_630B24 = (int)v7;
      v36[0] = dword_630B1C;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&PiUEventUsermodeEventQueueLock);
      while ( !v16 && __strex(1u, (unsigned int *)&PiUEventUsermodeEventQueueLock) );
      if ( v16 )
        ExpReleaseFastMutexContended((unsigned int *)&PiUEventUsermodeEventQueueLock, v16);
      KfLowerIrql(LOBYTE(v36[0]));
      KeAbPostRelease((unsigned int)&PiUEventUsermodeEventQueueLock);
      if ( !v14 )
      {
LABEL_36:
        if ( !v35[0] )
          return v2;
        v35[0] = (unsigned int)&PnpShutdownEvent;
        v35[1] = v7[3];
        v36[0] = -300000000;
        v36[1] = -1;
        v18 = KeWaitForMultipleObjects(2u, v35, 1, 0, 0, 1u, v36, 0);
        v34 = 0;
        PiUEventBroadcastAwaitingResponseEvent(&v34, 4);
        if ( v18 )
        {
          if ( v18 == 1 )
          {
            if ( !v5 || !*(_DWORD *)a1[6] )
              goto LABEL_41;
            v2 = -1073741536;
          }
          else
          {
            if ( v18 == 258 )
            {
LABEL_41:
              v2 = 0;
              goto LABEL_42;
            }
            v2 = -1073741823;
          }
        }
        else
        {
          v2 = -1073741431;
        }
LABEL_42:
        v19 = KeAbPreAcquire((unsigned int)&PiUEventUsermodeEventQueueLock, 0, 0);
        v20 = KfRaiseIrql(1);
        do
          v21 = __ldrex((unsigned __int8 *)&PiUEventUsermodeEventQueueLock);
        while ( __strex(v21 & 0xFE, (unsigned __int8 *)&PiUEventUsermodeEventQueueLock) );
        __dmb(0xBu);
        if ( (v21 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PiUEventUsermodeEventQueueLock, v19);
        if ( v19 )
          *(_BYTE *)(v19 + 14) |= 1u;
        __mrc(15, 0, 13, 0, 3);
        dword_630B1C = v20;
        v7[4] = 0;
        v7[5] = 0;
        dword_630B04 = 0;
        v22 = dword_630B1C;
        __dmb(0xBu);
        do
          v23 = __ldrex((unsigned int *)&PiUEventUsermodeEventQueueLock);
        while ( !v23 && __strex(1u, (unsigned int *)&PiUEventUsermodeEventQueueLock) );
        if ( v23 )
          ExpReleaseFastMutexContended((unsigned int *)&PiUEventUsermodeEventQueueLock, v23);
        KfLowerIrql(v22);
        KeAbPostRelease((unsigned int)&PiUEventUsermodeEventQueueLock);
        PiUEventDereferenceEventEntry((int)v7);
        return v2;
      }
      v17 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1500540496);
      if ( v17 )
      {
        v17[2] = PiUEventProcessEventWorker;
        v17[3] = v17;
        *v17 = 0;
        ExQueueWorkItem(v17, 3);
        goto LABEL_36;
      }
      v2 = -1073741670;
      v26 = KeAbPreAcquire((unsigned int)&PiUEventUsermodeEventQueueLock, 0, 0);
      v27 = KfRaiseIrql(1);
      do
        v28 = __ldrex((unsigned __int8 *)&PiUEventUsermodeEventQueueLock);
      while ( __strex(v28 & 0xFE, (unsigned __int8 *)&PiUEventUsermodeEventQueueLock) );
      __dmb(0xBu);
      if ( (v28 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PiUEventUsermodeEventQueueLock, v26);
      if ( v26 )
        *(_BYTE *)(v26 + 14) |= 1u;
      dword_630B04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_630B1C = v27;
      *(_QWORD *)&v29 = *(_QWORD *)v7;
      if ( *(_DWORD **)(*v7 + 4) != v7 || (_DWORD *)*v30 != v7 )
        __fastfail(3u);
      *v30 = v29;
      *(_DWORD *)(v29 + 4) = v30;
      dword_630B04 = 0;
      v31 = dword_630B1C;
      __dmb(0xBu);
      do
        v32 = __ldrex((unsigned int *)&PiUEventUsermodeEventQueueLock);
      while ( !v32 && __strex(1u, (unsigned int *)&PiUEventUsermodeEventQueueLock) );
      if ( v32 )
        ExpReleaseFastMutexContended((unsigned int *)&PiUEventUsermodeEventQueueLock, v32);
      KfLowerIrql(v31);
      KeAbPostRelease((unsigned int)&PiUEventUsermodeEventQueueLock);
      if ( v35[0] )
        goto LABEL_75;
    }
    else
    {
      v2 = -1073741670;
    }
LABEL_77:
    PiUEventFreeEventEntry(v7);
  }
  return v2;
}
