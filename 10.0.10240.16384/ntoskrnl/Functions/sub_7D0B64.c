// sub_7D0B64 
 
void __fastcall sub_7D0B64(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int *a7, BOOL a8, int a9, int a10, BOOL *a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, __int16 a26, int a27, int a28, int a29, int *a30)
{
  int *i; // r4
  int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  int v37; // r0
  int v38; // r4
  unsigned int v39; // r5
  unsigned int v40; // r7
  unsigned int v41; // r6
  unsigned int v42; // r9
  char *v43; // r8
  int v44; // r4
  unsigned int v45; // r1
  unsigned int v46; // r1
  int v47; // r0
  int v48; // r0
  int v49; // r0

  if ( a30 == &dword_6163C8 )
  {
    if ( (a26 & 0x8000) != 0 )
      PopTransitionTelemetryOsState();
  }
  else
  {
    ExTraceTimerResolution();
    PopDiagTraceSystemLatencyUpdate(1, PopFxSystemLatencyLimit);
    PopAcquirePowerRequestPushLock(0);
    for ( i = (int *)PopPowerRequestObjectList; i != &PopPowerRequestObjectList; i = (int *)*i )
      PopDiagTracePowerRequestCreate(1);
    dword_61F834 = 0;
    __pld(&PopPowerRequestLock);
    v31 = PopPowerRequestLock;
    if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
      v32 = 0;
    else
      v32 = PopPowerRequestLock - 16;
    if ( (PopPowerRequestLock & 2) != 0 )
      goto LABEL_15;
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)&PopPowerRequestLock);
    while ( v33 == v31 && __strex(v32, (unsigned int *)&PopPowerRequestLock) );
    if ( v33 != v31 )
LABEL_15:
      ExfReleasePushLock(&PopPowerRequestLock, v31);
    v34 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v36 = *(_WORD *)(v35 + 0x134) + 1;
    *(_WORD *)(v35 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
      KiCheckForKernelApcDelivery(v34);
    a8 = dword_61EC0C == 0;
    a11 = &a8;
    a12 = 0;
    a13 = 4;
    a14 = 0;
    v37 = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_ACDC_STATE_RUNDOWN, 0);
    PopRundownPowerSettings(v37);
    PopThermalTraceRundownEvents();
    PopAcquirePolicyLock();
    v38 = PopLoggingInformation(&a7, &a9);
    PopReleasePolicyLock();
    v39 = (unsigned int)a7;
    if ( v38 >= 0 )
    {
      v40 = *a7;
      v41 = (unsigned int)(a7 + 1);
      v42 = 0;
      if ( *a7 )
      {
        v43 = (char *)a7 + a9;
        do
        {
          if ( v41 >= (unsigned int)v43 )
            break;
          v44 = *(_DWORD *)(v41 + 12) + 16;
          a11 = (BOOL *)v41;
          a12 = 0;
          a13 = v44;
          a14 = 0;
          EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SLEEP_DISABLE_REASON_RUNDOWN, 0);
          ++v42;
          v41 += v44;
        }
        while ( v42 < v40 );
        v39 = (unsigned int)a7;
      }
    }
    if ( v39 )
      ExFreePoolWithTag(v39);
    __dmb(0xBu);
    do
    {
      v45 = __ldrex(&PopDiagDeviceRundownRequests);
      v46 = v45 + 1;
    }
    while ( __strex(v46, &PopDiagDeviceRundownRequests) );
    __dmb(0xBu);
    if ( v46 == 1 )
      ExQueueWorkItem(&PopDiagDeviceRundownWorkItem, 1);
    v47 = PopDiagTraceFxRundown();
    v48 = PopDiagTracePlatformRoleRundown(v47);
    v49 = PopRundownThermalRequests(v48);
    PopDiagTraceDynamicTickStatusRundown(v49);
  }
  JUMPOUT(0x78AE44);
}
