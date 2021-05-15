// PopThermalSxExit 
 
int __fastcall PopThermalSxExit(int a1, int a2)
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
  __int64 v13; // r0
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int result; // r0
  unsigned int v24; // r1
  __int16 v25; // r3

  if ( a1 )
  {
    v2 = PopAcquirePolicyLock(a1, a2);
    if ( PopThermalHibernateInitiated )
    {
      PopThermalHibernateInitiated = 0;
      v2 = ZwUpdateWnfStateData();
    }
    PopReleasePolicyLock(v2);
  }
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
    LODWORD(v13) = KeQueryInterruptTime();
    *(_QWORD *)(i + 376) = v13;
    *(_BYTE *)(i + 368) = 0;
    if ( *(_DWORD *)(i + 324) )
      *(_DWORD *)(i + 324) = 0;
    __pld(v8);
    v14 = *(_DWORD *)v8;
    v15 = *(_DWORD *)v8 - 16;
    if ( (*(_DWORD *)v8 & 0xFFFFFFF0) <= 0x10 )
      v15 = 0;
    if ( (v14 & 2) != 0 )
      goto LABEL_28;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v8);
    while ( v16 == v14 && __strex(v15, (unsigned int *)v8) );
    if ( v16 != v14 )
LABEL_28:
      ExfReleasePushLock((_DWORD *)(i + 320), v14);
    v17 = KeAbPostRelease(i + 320);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
  }
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v20 = PopPolicyDeviceLock;
  v21 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v21 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_41;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v22 == v20 && __strex(v21, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v22 != v20 )
LABEL_41:
    ExfReleasePushLock(&PopPolicyDeviceLock, v20);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x134) + 1;
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
