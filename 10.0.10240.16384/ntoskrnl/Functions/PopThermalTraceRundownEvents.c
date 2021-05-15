// PopThermalTraceRundownEvents 
 
int PopThermalTraceRundownEvents()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r5
  int v3; // r1
  unsigned int v4; // r2
  int i; // r5
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  int result; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v2 = v1;
  v3 = 17;
  do
    v4 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v4 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v4 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v1, (unsigned int)&PopPolicyDeviceLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  for ( i = PopThermal; (int *)i != &PopThermal; i = *(_DWORD *)i )
  {
    if ( (*(_BYTE *)(i + 33) & 2) != 0 )
    {
      if ( (*(_BYTE *)(i + 33) & 4) != 0 )
        v3 = 1;
      if ( (*(_BYTE *)(i + 33) & 4) == 0 )
        v3 = 0;
      PopDiagTraceThermalZoneRundown(
        *(_DWORD *)(i + 24),
        v3,
        *(unsigned __int8 *)(i + 37),
        (*(_BYTE *)(i + 33) & 1) != 0,
        *(_DWORD *)(i + 48),
        *(unsigned __int8 *)(i + 40),
        *(unsigned __int8 *)(i + 41));
    }
  }
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v6 = PopPolicyDeviceLock;
  v7 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v7 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v8 != v6 )
LABEL_24:
    ExfReleasePushLock(&PopPolicyDeviceLock, v6);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
