// IoRegisterContainerNotification 
 
int __fastcall IoRegisterContainerNotification(int a1, int a2, _DWORD *a3, int a4, int *a5)
{
  int v5; // r4
  _DWORD *v7; // r8
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  int *v12; // r2
  int v13; // r0
  int *v14; // r5
  int v15; // r9
  int v16; // r3
  int v17; // r10
  int v18; // r2
  int **v19; // r2
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  _DWORD *v24; // r3
  int v25; // r1
  unsigned int v26; // r0
  int v27; // r3
  int v28; // r0
  int v29; // r10
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  _DWORD *v34; // [sp+0h] [bp-30h] BYREF
  int v35; // [sp+4h] [bp-2Ch]
  _DWORD *v36; // [sp+8h] [bp-28h]
  int v37; // [sp+Ch] [bp-24h]

  v5 = 0;
  v36 = a3;
  v37 = a2;
  if ( a1 >= 1 )
    return sub_810668();
  if ( a4 == 20 && *a3 == 20 )
  {
    v7 = (_DWORD *)a3[2];
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire((unsigned int)&IopSessionNotificationLock, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned __int8 *)&IopSessionNotificationLock);
    while ( __strex(v11 | 1, (unsigned __int8 *)&IopSessionNotificationLock) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&IopSessionNotificationLock, v9, (unsigned int)&IopSessionNotificationLock);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    v12 = (int *)IopSessionNotificationQueueHead;
    while ( v12 != &IopSessionNotificationQueueHead )
    {
      v24 = (_DWORD *)v12[5];
      v12 = (int *)*v12;
      if ( v24 == v7 )
      {
        v5 = -1073741791;
        goto LABEL_33;
      }
    }
    v13 = ExAllocatePoolWithTag(1, 36, 1850961737);
    v14 = (int *)v13;
    if ( !v13 )
    {
      v5 = -1073741670;
LABEL_33:
      __pld(&IopSessionNotificationLock);
      v25 = IopSessionNotificationLock;
      if ( (IopSessionNotificationLock & 0xFFFFFFF0) <= 0x10 )
        v26 = 0;
      else
        v26 = IopSessionNotificationLock - 16;
      if ( (IopSessionNotificationLock & 2) != 0 )
        goto LABEL_48;
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)&IopSessionNotificationLock);
      while ( v20 == v25 && __strex(v26, (unsigned int *)&IopSessionNotificationLock) );
      if ( v20 != v25 )
LABEL_48:
        ExfReleasePushLock(&IopSessionNotificationLock, v25);
      v21 = KeAbPostRelease((unsigned int)&IopSessionNotificationLock);
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = (__int16)(*(_WORD *)(v22 + 0x134) + 1);
      *(_WORD *)(v22 + 308) = v23;
      if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
        KiCheckForKernelApcDelivery(v21);
      return v5;
    }
    v15 = ExRegisterCallback(IopSessionCallbackObject, (int)IopDispatchSessionNotifications, v13);
    if ( v15 )
    {
      v35 = 0;
      v16 = *(__int16 *)v7;
      switch ( v16 )
      {
        case 4:
          v17 = (int)v7;
LABEL_19:
          ObfReferenceObject(v17);
          v18 = (int)v36;
          v14[4] = v15;
          v14[5] = (int)v7;
          v14[2] = v17;
          v14[8] = *(_DWORD *)(v18 + 16);
          v14[7] = *(_DWORD *)(v18 + 12);
          v14[3] = v37;
          v14[6] = v35;
          *a5 = v15;
          v19 = (int **)dword_63172C;
          *v14 = (int)&IopSessionNotificationQueueHead;
          v14[1] = (int)v19;
          if ( *v19 != &IopSessionNotificationQueueHead )
            __fastfail(3u);
          *v19 = v14;
          dword_63172C = (int)v14;
          goto LABEL_33;
        case 3:
          v17 = v7[2];
          v27 = *(_DWORD *)(v7[44] + 16);
          v34 = (_DWORD *)v17;
          if ( (v27 & 0x400) != 0 )
          {
            v28 = IopGetDevicePDO((int)v7);
            v29 = v28;
            if ( v28 )
            {
              v30 = IopGetSessionIdFromPDO(v28);
              v35 = MmGetSessionObjectById(v30, v31, v32, v33);
              ObfDereferenceObject(v29);
            }
            v17 = (int)v34;
          }
          *(_DWORD *)(v7[44] + 16) |= 0x1000u;
          goto LABEL_19;
        case 5:
          v17 = *(_DWORD *)(v7[1] + 8);
          v5 = IopAllocateFileObjectExtension((int)v7, &v34);
          if ( v5 >= 0 )
          {
            v5 = 0;
            *v34 |= 2u;
            goto LABEL_19;
          }
          break;
        default:
          v5 = -1073741583;
          break;
      }
    }
    else
    {
      v5 = -1073741670;
    }
    ExFreePoolWithTag((unsigned int)v14);
    if ( v15 )
      ExUnregisterCallback(v15);
    goto LABEL_33;
  }
  return -1073741582;
}
