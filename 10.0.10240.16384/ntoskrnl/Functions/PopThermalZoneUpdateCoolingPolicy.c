// PopThermalZoneUpdateCoolingPolicy 
 
int PopThermalZoneUpdateCoolingPolicy()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int result; // r0
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
  unsigned int v19; // r1
  __int16 v20; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v2 )
    return sub_818200(v1, 17);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
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
    IoCancelIrp(i[7]);
    if ( i[81] )
      i[81] = 0;
    __pld(v5);
    v10 = *(_DWORD *)v5;
    if ( (*(_DWORD *)v5 & 0xFFFFFFF0) > 0x10 )
      v11 = v10 - 16;
    else
      v11 = 0;
    if ( (v10 & 2) != 0 )
      goto LABEL_44;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v5);
    while ( v12 == v10 && __strex(v11, (unsigned int *)v5) );
    if ( v12 != v10 )
LABEL_44:
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
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) > 0x10 )
    v17 = PopPolicyDeviceLock - 16;
  else
    v17 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_42;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v18 == v16 && __strex(v17, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v18 != v16 )
LABEL_42:
    ExfReleasePushLock(&PopPolicyDeviceLock, v16);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
