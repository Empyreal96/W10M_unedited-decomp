// PnpInsertEventInQueue 
 
int __fastcall PnpInsertEventInQueue(_DWORD *a1)
{
  int v2; // r9
  _DWORD *v3; // r6
  int v4; // r1
  int v5; // r2
  int v6; // r3
  _DWORD *v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r5
  int v17; // r4
  int v18; // r1
  unsigned int v19; // r2
  int v20; // r5
  int v21; // r1
  unsigned int v22; // r2
  int v23; // r2
  _DWORD *v24; // r1
  unsigned __int8 v25; // r5
  unsigned int v26; // r1
  unsigned int *v27; // r4
  unsigned int v28; // r5
  unsigned int v29; // r1
  int v31; // [sp+8h] [bp-40h]
  int v32; // [sp+8h] [bp-40h]
  _DWORD v33[3]; // [sp+Ch] [bp-3Ch] BYREF
  int v34; // [sp+18h] [bp-30h]
  int v35; // [sp+1Ch] [bp-2Ch]
  int v36; // [sp+20h] [bp-28h]
  int v37; // [sp+24h] [bp-24h]

  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v33[0] = 0;
  v2 = 0;
  v33[2] = 0;
  v3 = 0;
  v33[1] = 0;
  EtwActivityIdControlKernel(1, v33);
  if ( v33[0] )
  {
    v4 = *(_DWORD *)(v33[0] + 4);
    v5 = *(_DWORD *)(v33[0] + 8);
    v6 = *(_DWORD *)(v33[0] + 12);
    v34 = *(_DWORD *)v33[0];
    v35 = v4;
    v36 = v5;
    v37 = v6;
  }
  else if ( PnpIsSafeToExamineUserModeTeb() && PsGetCurrentThreadTeb() )
  {
    v7 = (_DWORD *)PsGetCurrentThreadTeb();
    v8 = v7[981];
    v9 = v7[982];
    v10 = v7[983];
    v34 = v7[980];
    v35 = v8;
    v36 = v9;
    v37 = v10;
  }
  v11 = v35;
  v12 = v36;
  v13 = v37;
  a1[12] = v34;
  a1[13] = v11;
  a1[14] = v12;
  a1[15] = v13;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0
    && (PnpCompareGuid(a1 + 16, &GUID_DEVICE_QUERY_AND_REMOVE) || PnpCompareGuid(a1 + 16, &GUID_DEVICE_EJECT)) )
  {
    v14 = a1[24];
    if ( v14 )
      v15 = *(_DWORD *)(*(_DWORD *)(v14 + 176) + 20);
    else
      v15 = 0;
    Template_z(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_DeviceRemoval_Queue,
      (int)&Microsoft_Windows_Kernel_PnPHandle,
      *(unsigned __int16 **)(v15 + 24));
  }
  v16 = PnpDeviceEventList + 36;
  v17 = KeAbPreAcquire(PnpDeviceEventList + 36, 0, 0);
  v18 = KfRaiseIrql(1);
  v31 = v18;
  do
    v19 = __ldrex((unsigned __int8 *)v16);
  while ( __strex(v19 & 0xFE, (unsigned __int8 *)v16) );
  __dmb(0xBu);
  if ( (v19 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v16, v17);
    v18 = v31;
  }
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  *(_DWORD *)(v16 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v16 + 28) = v18;
  v20 = KeAbPreAcquire((unsigned int)&PnpNotificationInProgressLock, 0, 0);
  v21 = KfRaiseIrql(1);
  v32 = v21;
  do
    v22 = __ldrex((unsigned __int8 *)&PnpNotificationInProgressLock);
  while ( __strex(v22 & 0xFE, (unsigned __int8 *)&PnpNotificationInProgressLock) );
  __dmb(0xBu);
  if ( (v22 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&PnpNotificationInProgressLock, v20);
    v21 = v32;
  }
  if ( v20 )
    *(_BYTE *)(v20 + 14) |= 1u;
  dword_62FB04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_62FB1C = v21;
  if ( !PnpNotificationInProgress )
  {
    v3 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1282436688);
    if ( v3 )
    {
      PnpNotificationInProgress = 1;
      KeResetEvent((int)&PnpEventQueueEmpty);
    }
    else
    {
      v2 = -1073741670;
    }
  }
  v23 = PnpDeviceEventList + 68;
  v24 = *(_DWORD **)(PnpDeviceEventList + 72);
  *a1 = PnpDeviceEventList + 68;
  a1[1] = v24;
  if ( *v24 != v23 )
    __fastfail(3u);
  *v24 = a1;
  *(_DWORD *)(v23 + 4) = a1;
  dword_62FB04 = 0;
  v25 = dword_62FB1C;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)&PnpNotificationInProgressLock);
  while ( !v26 && __strex(1u, (unsigned int *)&PnpNotificationInProgressLock) );
  if ( v26 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpNotificationInProgressLock, v26);
  KfLowerIrql(v25);
  KeAbPostRelease((unsigned int)&PnpNotificationInProgressLock);
  v27 = (unsigned int *)(PnpDeviceEventList + 36);
  *(_DWORD *)(PnpDeviceEventList + 40) = 0;
  v28 = v27[7];
  __dmb(0xBu);
  do
    v29 = __ldrex(v27);
  while ( !v29 && __strex(1u, v27) );
  if ( v29 )
    ExpReleaseFastMutexContended(v27, v29);
  KfLowerIrql((unsigned __int8)v28);
  KeAbPostRelease((unsigned int)v27);
  if ( v3 )
  {
    v3[2] = PnpDeviceEventWorker;
    v3[3] = v3;
    *v3 = 0;
    ExQueueWorkItem(v3, 1);
  }
  return v2;
}
