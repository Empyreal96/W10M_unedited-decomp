// PopThermalSxEntry 
 
int __fastcall PopThermalSxEntry(int a1, int a2)
{
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  int i; // r6
  unsigned __int8 *v8; // r5
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2
  int result; // r0
  unsigned int v23; // r1
  __int16 v24; // r3

  PopAcquirePolicyLock(a1, a2);
  v2 = PopThermalStandbyEndTracking();
  PopReleasePolicyLock(v2);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v6 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v4, (unsigned int)&PopPolicyDeviceLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  for ( i = PopThermal; (int *)i != &PopThermal; i = *(_DWORD *)i )
  {
    v8 = (unsigned __int8 *)(i + 320);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire(i + 320, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v8);
    while ( __strex(v12 | 1, v8) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(i + 320), v10, i + 320);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(i + 324) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    PopThermalUpdatePassiveTimeTracking(i + 368, (unsigned __int8)*(_DWORD *)(i + 48));
    PopTraceThermalZonePassiveHistogram(i);
    *(_BYTE *)(i + 368) = 1;
    if ( *(_DWORD *)(i + 324) )
      *(_DWORD *)(i + 324) = 0;
    __pld(v8);
    v13 = *(_DWORD *)v8;
    v14 = *(_DWORD *)v8 - 16;
    if ( (*(_DWORD *)v8 & 0xFFFFFFF0) <= 0x10 )
      v14 = 0;
    if ( (v13 & 2) != 0 )
      goto LABEL_24;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)v8);
    while ( v15 == v13 && __strex(v14, (unsigned int *)v8) );
    if ( v15 != v13 )
LABEL_24:
      ExfReleasePushLock((_DWORD *)(i + 320), v13);
    v16 = KeAbPostRelease(i + 320);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v19 = PopPolicyDeviceLock;
  v20 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v20 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_38;
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v21 == v19 && __strex(v20, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v21 != v19 )
LABEL_38:
    ExfReleasePushLock(&PopPolicyDeviceLock, v19);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
