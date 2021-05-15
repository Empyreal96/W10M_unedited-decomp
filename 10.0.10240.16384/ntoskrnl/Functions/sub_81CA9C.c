// sub_81CA9C 
 
void sub_81CA9C()
{
  unsigned int v0; // r4
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r5
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v0 = dword_681D78[0];
  while ( v0 )
  {
    v1 = __clz(__rbit(v0));
    v0 &= ~(1 << v1);
    if ( v1 >= KeNumberProcessors_0 )
      v2 = 0;
    else
      v2 = (int)*(&KiProcessorBlock + v1);
    PpmEventTraceProcessorPerformance(v2);
  }
  v3 = 0;
  if ( PpmParkNumNodes )
  {
    v4 = 0;
    do
    {
      PpmEventTraceParkNodeRundown(v4 + PpmParkNodes);
      ++v3;
      v4 += 88;
    }
    while ( v3 < PpmParkNumNodes );
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    v6 = ExfAcquirePushLockExclusiveEx(&PpmIdlePolicyLock, v6, (unsigned int)&PpmIdlePolicyLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PpmEventTracePpmProfileStatusRundown(v6);
  PpmEventTraceProfiles();
  if ( PpmEtwRegistered )
  {
    v9 = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PROCESSOR_PROFILE_SETTING_RUNDOWN);
    if ( v9 )
      PpmInfoTraceProfileSettings(v9);
  }
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v10 = PpmIdlePolicyLock;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) <= 0x10 )
    v11 = 0;
  else
    v11 = PpmIdlePolicyLock - 16;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_27;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v12 == v10 && __strex(v11, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v12 != v10 )
LABEL_27:
    ExfReleasePushLock(&PpmIdlePolicyLock, v10);
  v13 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  PpmReleaseLock(&PpmPerfPolicyLock);
  JUMPOUT(0x7BD1AC);
}
