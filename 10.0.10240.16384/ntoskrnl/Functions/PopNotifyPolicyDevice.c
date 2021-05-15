// PopNotifyPolicyDevice 
 
int __fastcall PopNotifyPolicyDevice(int a1, int a2)
{
  BOOL v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r1
  int v12; // r4
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3

  v4 = memcmp(a1 + 4, (unsigned int)&GUID_DEVICE_INTERFACE_REMOVAL, 16) == 0;
  if ( a2 == 8 )
  {
    v9 = PopAcquirePolicyLock();
    if ( v4 )
      return sub_7F1890(v9, v10, &PopCapabilities, (unsigned __int8)byte_61EA53);
    if ( byte_61EA53 != 1 )
    {
      byte_61EA53 = 1;
      PopResetCurrentPolicies(v9);
    }
    PopReleasePolicyLock();
  }
  else if ( a2 == 3 )
  {
    KeWaitForSingleObject((unsigned int)&PopTransitionLock, 7, 0, 0, 0);
    PopAcquirePolicyLock();
    v12 = (unsigned __int8)PopHiberEnabled;
    PopEnableHiberFile(0);
    if ( v12 )
      PopEnableHiberFile(1);
    PopReleasePolicyLock();
    KeSetEvent((int)&PopTransitionLock, 0, 0);
  }
  else if ( !v4 )
  {
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
    PopConnectToPolicyDevice(a2, *(_DWORD *)(a1 + 36));
    dword_61E614 = 0;
    __pld(&PopPolicyDeviceLock);
    v13 = PopPolicyDeviceLock;
    if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
      v14 = 0;
    else
      v14 = PopPolicyDeviceLock - 16;
    if ( (PopPolicyDeviceLock & 2) != 0 )
      goto LABEL_28;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
    while ( v15 == v13 && __strex(v14, (unsigned int *)&PopPolicyDeviceLock) );
    if ( v15 != v13 )
LABEL_28:
      ExfReleasePushLock(&PopPolicyDeviceLock, v13);
    v16 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  return 0;
}
