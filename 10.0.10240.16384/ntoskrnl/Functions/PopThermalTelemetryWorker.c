// PopThermalTelemetryWorker 
 
int PopThermalTelemetryWorker()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r2
  int *i; // r6
  unsigned __int8 *v5; // r5
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r7
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

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v1, (unsigned int)&PopPolicyDeviceLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  for ( i = (int *)PopThermal; i != &PopThermal; i = (int *)*i )
  {
    v5 = (unsigned __int8 *)(i + 80);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire((unsigned int)(i + 80), 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v5);
    while ( __strex(v9 | 1, v5) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(i + 80, v7, (unsigned int)(i + 80));
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    i[81] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    PopThermalUpdatePassiveTimeTracking(i + 92, (unsigned __int8)i[12]);
    PopTraceThermalZonePassiveHistogram(i);
    if ( i[81] )
      i[81] = 0;
    __pld(v5);
    v10 = *(_DWORD *)v5;
    v11 = *(_DWORD *)v5 - 16;
    if ( (*(_DWORD *)v5 & 0xFFFFFFF0) <= 0x10 )
      v11 = 0;
    if ( (v10 & 2) != 0 )
      goto LABEL_24;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v5);
    while ( v12 == v10 && __strex(v11, (unsigned int *)v5) );
    if ( v12 != v10 )
LABEL_24:
      ExfReleasePushLock(i + 80, v10);
    v13 = KeAbPostRelease((unsigned int)(i + 80));
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(_WORD *)(v14 + 0x134) + 1;
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v13);
  }
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v16 = PopPolicyDeviceLock;
  v17 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v17 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_38;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v18 == v16 && __strex(v17, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v18 != v16 )
LABEL_38:
    ExfReleasePushLock(&PopPolicyDeviceLock, v16);
  v19 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  PopCoolingTelemetryWorker();
  return PopOkayToQueueNextWorkItem(&PopThermalTelemetryTimer[22]);
}
