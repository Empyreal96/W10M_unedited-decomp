// PopBatteryEtwCallback 
 
void __fastcall PopBatteryEtwCallback(int a1, int a2)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r2
  int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3

  if ( a2 == 2 )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v2 + 308);
    v3 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
    v4 = v3;
    do
      v5 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
    while ( !v5 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
    __dmb(0xBu);
    if ( v5 )
      ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v3, (unsigned int)&PopPolicyDeviceLock);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire((unsigned int)PopCB, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex((unsigned __int8 *)PopCB);
    while ( __strex(v9 | 1, (unsigned __int8 *)PopCB) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(PopCB, v7, (unsigned int)PopCB);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    dword_61ED64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    PopBatteryTraceSystemBatteryStatus(1);
    dword_61ED64 = 0;
    __pld(PopCB);
    v10 = PopCB[0];
    v11 = PopCB[0] - 16;
    if ( (PopCB[0] & 0xFFFFFFF0) <= 0x10 )
      v11 = 0;
    if ( (PopCB[0] & 2) != 0 )
      goto LABEL_22;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)PopCB);
    while ( v12 == v10 && __strex(v11, (unsigned int *)PopCB) );
    if ( v12 != v10 )
LABEL_22:
      ExfReleasePushLock(PopCB, v10);
    v13 = KeAbPostRelease((unsigned int)PopCB);
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(_WORD *)(v14 + 0x134) + 1;
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v13);
    dword_61E614 = 0;
    __pld(&PopPolicyDeviceLock);
    v16 = PopPolicyDeviceLock;
    v17 = PopPolicyDeviceLock - 16;
    if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
      v17 = 0;
    if ( (PopPolicyDeviceLock & 2) != 0 )
      goto LABEL_34;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
    while ( v18 == v16 && __strex(v17, (unsigned int *)&PopPolicyDeviceLock) );
    if ( v18 != v16 )
LABEL_34:
      ExfReleasePushLock(&PopPolicyDeviceLock, v16);
    v19 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
}
