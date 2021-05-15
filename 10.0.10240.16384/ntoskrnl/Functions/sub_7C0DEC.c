// sub_7C0DEC 
 
// positive sp value has been detected, the output may be wrong!
unsigned int sub_7C0DEC()
{
  int *v1; // r6
  int v2; // r7
  int *v3; // r8
  unsigned int v4; // r9
  int *v5; // r10
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r7
  unsigned int v10; // r1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r3
  bool v16; // zf
  _BYTE *v17; // r0
  _BYTE *v18; // r4
  int v19; // r1
  _BYTE *v20; // r0
  _BYTE *v21; // r0
  _BYTE *v22; // r0
  _DWORD *v23; // r8
  int v24; // r2
  int v25; // r3
  int v26; // r4
  _BYTE *v27; // r0
  _DWORD *v28; // r8
  int v29; // r2
  int v30; // r3
  int v31; // r4
  int v32; // r4
  int v33; // r5
  unsigned int v34; // r2
  int v35; // r3
  int v36; // r1
  __int64 v37; // r2
  int v38; // r5
  int v39; // r4
  unsigned int v40; // r1
  int v41; // [sp-68h] [bp-68h]
  int v42; // [sp-64h] [bp-64h]
  int v43; // [sp-60h] [bp-60h]
  int v44; // [sp-5Ch] [bp-5Ch]
  int v45; // [sp-58h] [bp-58h]
  int v46; // [sp-48h] [bp-48h] BYREF
  int v47; // [sp-44h] [bp-44h] BYREF
  int v48; // [sp-40h] [bp-40h] BYREF
  int v49; // [sp-3Ch] [bp-3Ch] BYREF
  int v50; // [sp-38h] [bp-38h]
  unsigned int v51; // [sp-34h] [bp-34h]
  _BYTE v52[48]; // [sp-30h] [bp-30h] BYREF

  do
  {
    v6 = KeAbPreAcquire(v4, 0, 0);
    v7 = KfRaiseIrql(1);
    do
      v8 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v8 & 0xFE, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v8 & v2) == 0 )
      ExpAcquireFastMutexContended(v4, v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= v2;
    __mrc(15, 0, 13, 0, 3);
    v9 = *v5;
    *(_DWORD *)(v4 + 28) = v7;
    *(_DWORD *)(v4 + 4) = 0;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)v4);
    while ( !v10 && __strex(1u, (unsigned int *)v4) );
    if ( v10 )
      ExpReleaseFastMutexContended((unsigned int *)v4, v10);
    KfLowerIrql((unsigned __int8)v7);
    KeAbPostRelease(v4);
    v13 = *(_DWORD *)(v9 + 60);
    switch ( v13 )
    {
      case 1:
        goto LABEL_22;
      case 2:
        v14 = PiUEventNotifyDeviceInterfaceChange(v9);
        break;
      case 3:
LABEL_22:
        v14 = PiUEventNotifyTargetDeviceChange(v9, v11, v12, v13, v41, v42, v43, v44, v45);
        break;
      case 4:
        goto LABEL_19;
      case 9:
        v14 = ((int (__fastcall *)(int))PiUEventNotifyDeviceInstancePropertyChange)(v9);
        break;
      default:
        if ( v13 <= 9 || v13 > 11 )
          goto LABEL_24;
LABEL_19:
        v14 = ((int (__fastcall *)(int))PiUEventNotifyDeviceInstanceChange)(v9);
        break;
    }
    if ( v14 < 0 )
      goto LABEL_66;
LABEL_24:
    v49 = 0;
    v47 = 0;
    if ( !PiUEventBroadcastSubscriberPresent )
      goto LABEL_66;
    v15 = *(_DWORD *)(v9 + 60);
    switch ( v15 )
    {
      case 0:
        v27 = (_BYTE *)ExAllocatePoolWithTag(1, 436, 1500540496);
        v28 = v27;
        if ( v27 )
        {
          memset(v27, 0, 436);
          v28[4] = -1;
          v28[3] = 2;
          v29 = *(_DWORD *)(v9 + 48);
          v30 = *(_DWORD *)(v9 + 52);
          v31 = *(_DWORD *)(v9 + 56);
          v28[5] = *(_DWORD *)(v9 + 44);
          v28[6] = v29;
          v28[7] = v30;
          v28[8] = v31;
          ((void (__fastcall *)(_DWORD *))PiUEventQueueBroadcastEventEntry)(v28);
          v1 = &PiPnpRtlCtx;
        }
        goto LABEL_65;
      case 1:
        if ( !memcmp(v9 + 44, (unsigned int)&GUID_DEVICE_ARRIVAL, 16)
          || !memcmp(v9 + 44, (unsigned int)&GUID_DEVICE_REMOVE_PENDING, 16) )
        {
          goto LABEL_32;
        }
        v16 = memcmp(v9 + 44, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16) == 0;
LABEL_30:
        if ( !v16 )
          goto LABEL_66;
LABEL_32:
        v17 = (_BYTE *)ExAllocatePoolWithTag(1, 436, 1500540496);
        v18 = v17;
        if ( v17 )
        {
          memset(v17, 0, 436);
          *((_DWORD *)v18 + 3) = 0;
          v19 = v9 + 80;
LABEL_34:
          if ( PnpGetObjectProperty(*v1, v19, 1, 0, 0, (int)v3, (int)&v46, (int)(v18 + 16), 4, (int)&v47, 0) < 0
            || v47 != 4 )
          {
            *((_DWORD *)v18 + 4) = -1;
          }
LABEL_37:
          ((void (__fastcall *)(_BYTE *))PiUEventQueueBroadcastEventEntry)(v18);
          goto LABEL_66;
        }
        goto LABEL_66;
      case 2:
        if ( !memcmp(v9 + 44, (unsigned int)&GUID_DEVICE_INTERFACE_ARRIVAL, 16)
          || !memcmp(v9 + 44, (unsigned int)&GUID_DEVICE_INTERFACE_REMOVAL, 16) )
        {
          if ( !memcmp(v9 + 80, (unsigned int)&GUID_DEVINTERFACE_VOLUME, 16) )
          {
            v21 = (_BYTE *)ExAllocatePoolWithTag(1, 436, 1500540496);
            v18 = v21;
            if ( !v21 )
              goto LABEL_66;
            memset(v21, 0, 436);
            RtlInitUnicodeString((unsigned int)v52, (unsigned __int16 *)(v9 + 96));
            *((_DWORD *)v18 + 3) = 1;
            *((_DWORD *)v18 + 4) = IopGetSessionIdFromSymbolicName(v52);
            goto LABEL_37;
          }
          if ( !memcmp(v9 + 80, (unsigned int)&GUID_DEVINTERFACE_PARALLEL, 16)
            || !memcmp(v9 + 80, (unsigned int)&GUID_DEVINTERFACE_COMPORT, 16) )
          {
            v22 = (_BYTE *)ExAllocatePoolWithTag(1, 436, 1500540496);
            v23 = v22;
            if ( v22 )
            {
              memset(v22, 0, 436);
              RtlInitUnicodeString((unsigned int)v52, (unsigned __int16 *)(v9 + 96));
              v23[3] = 3;
              v24 = *(_DWORD *)(v9 + 48);
              v25 = *(_DWORD *)(v9 + 52);
              v26 = *(_DWORD *)(v9 + 56);
              v23[5] = *(_DWORD *)(v9 + 44);
              v23[6] = v24;
              v23[7] = v25;
              v23[8] = v26;
              v1 = &PiPnpRtlCtx;
              v48 = 400;
              if ( PnpGetObjectProperty(
                     PiPnpRtlCtx,
                     v9 + 96,
                     3,
                     0,
                     0,
                     (int)DEVPKEY_Device_InstanceId,
                     (int)&v46,
                     (int)(v23 + 9),
                     400,
                     (int)&v48,
                     0) >= 0
                && v46 == 18 )
              {
                v48 = 4;
                if ( PnpGetObjectProperty(
                       PiPnpRtlCtx,
                       (int)(v23 + 9),
                       1,
                       0,
                       0,
                       (int)DEVPKEY_Device_SessionId,
                       (int)&v46,
                       (int)(v23 + 4),
                       4,
                       (int)&v48,
                       0) < 0
                  || v46 != 7 )
                {
                  v23[4] = -1;
                }
                ((void (__fastcall *)(_DWORD *))PiUEventQueueBroadcastEventEntry)(v23);
              }
              else
              {
                ExFreePoolWithTag((unsigned int)v23);
              }
            }
LABEL_65:
            v3 = DEVPKEY_Device_SessionId;
            goto LABEL_66;
          }
        }
        goto LABEL_66;
    }
    if ( v15 != 3 )
    {
      v16 = v15 == 4;
      goto LABEL_30;
    }
    if ( RtlStringCchLengthW((unsigned __int16 *)(v9 + 84), 0xC8u, &v49) >= 0 )
    {
      if ( v49 )
      {
        if ( (unsigned int)(2 * (v49 + 1) + 68) >= 0x44
          && 2 * (v49 + 1) + 71 >= (unsigned int)(2 * (v49 + 1) + 68)
          && !memcmp(((2 * (v49 + 1) + 71) & 0xFFFFFFFC) + v9 + 48, (unsigned int)&GUID_IO_VOLUME_NAME_CHANGE, 16) )
        {
          v20 = (_BYTE *)ExAllocatePoolWithTag(1, 436, 1500540496);
          v18 = v20;
          if ( v20 )
          {
            memset(v20, 0, 436);
            *((_DWORD *)v18 + 3) = 1;
            v19 = v9 + 84;
            goto LABEL_34;
          }
        }
      }
    }
LABEL_66:
    v32 = KeAbPreAcquire(v4, 0, 0);
    v33 = KfRaiseIrql(1);
    do
      v34 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v34 & 0xFE, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v34 & 1) == 0 )
      ExpAcquireFastMutexContended(v4, v32);
    if ( v32 )
      *(_BYTE *)(v32 + 14) |= 1u;
    v35 = __mrc(15, 0, 13, 0, 3);
    v36 = *v5;
    *(_DWORD *)(v4 + 4) = v35 & 0xFFFFFFC0;
    *(_DWORD *)(v4 + 28) = v33;
    v37 = *(_QWORD *)v36;
    if ( *(int **)(v36 + 4) != v5 || *(_DWORD *)(v37 + 4) != v36 )
      __fastfail(3u);
    *v5 = v37;
    *(_DWORD *)(v37 + 4) = v5;
    if ( (int *)*v5 == v5 )
    {
      v38 = 1;
      v50 = 1;
    }
    else
    {
      v38 = v50;
    }
    *(_DWORD *)(v4 + 4) = 0;
    v39 = *(_DWORD *)(v4 + 28);
    __dmb(0xBu);
    do
      v40 = __ldrex((unsigned int *)v4);
    while ( !v40 && __strex(1u, (unsigned int *)v4) );
    if ( v40 )
      ExpReleaseFastMutexContended((unsigned int *)v4, v40);
    KfLowerIrql((unsigned __int8)v39);
    KeAbPostRelease(v4);
    PiUEventDereferenceEventEntry(v9);
    v2 = 1;
  }
  while ( !v38 );
  return ExFreePoolWithTag(v51);
}
