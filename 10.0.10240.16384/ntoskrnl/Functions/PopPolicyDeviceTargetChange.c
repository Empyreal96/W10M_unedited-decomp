// PopPolicyDeviceTargetChange 
 
int __fastcall PopPolicyDeviceTargetChange(int a1, unsigned int a2)
{
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&PopPolicyDeviceLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopPolicyDeviceLock, v6, (unsigned int)&PopPolicyDeviceLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_61E614 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16) )
  {
    PopPolicyDeviceRemove((_DWORD *)a2);
    goto LABEL_14;
  }
  if ( !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16) )
  {
    PopPolicyDeviceRemove((_DWORD *)a2);
  }
  else
  {
    if ( memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_CANCELLED, 16) )
      goto LABEL_14;
    PopConnectToPolicyDevice(*(_DWORD *)(a2 + 8), (unsigned __int16 *)(a2 + 16));
  }
  v4 = 1;
LABEL_14:
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v9 = PopPolicyDeviceLock;
  v10 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v11 != v9 )
LABEL_21:
    ExfReleasePushLock(&PopPolicyDeviceLock, v9);
  v12 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( v4 )
  {
    PnpUnregisterPlugPlayNotification(*(_DWORD *)(a2 + 12), 1);
    ExFreePoolWithTag(a2);
  }
  return 0;
}
