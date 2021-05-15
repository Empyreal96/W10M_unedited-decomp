// PspExitThread 
 
void __fastcall PspExitThread(int a1)
{
  int v1; // r5
  int v2; // r9
  unsigned int *v3; // r6
  int v4; // r2
  int v5; // r2
  int v6; // r3
  unsigned int *v7; // r0
  int v8; // r2
  unsigned int v9; // r1
  int v10; // r4
  char v11; // r3
  char v12; // r3
  _DWORD *v13; // r5
  int v14; // r6
  int v15; // r0
  unsigned int v16; // r8
  void (__fastcall *v17)(_DWORD, _DWORD, _DWORD); // r0
  unsigned __int8 *v18; // r10
  int v19; // r0
  int v20; // r4
  unsigned int v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  unsigned int *v24; // r4
  unsigned int v25; // r0
  unsigned int *v26; // r5
  unsigned int *v27; // r8
  unsigned int v28; // r1
  int v29; // r0
  __int16 v30; // r3
  int v31; // r0
  int v32; // r6
  unsigned int v33; // r2
  unsigned int v34; // r1
  int v35; // r0
  __int16 v36; // r3
  int v37; // r4
  int v38; // r3
  int v39; // r8
  _DWORD *v40; // r6
  int v41; // r0
  _DWORD *v42; // r4
  unsigned int *v43; // r6
  int v44; // r4
  int v45; // r0
  int v46; // r3
  int v47; // r1
  unsigned int *v48; // r0
  unsigned int v49; // r4
  int v50; // r3
  int v51; // r6
  __int16 v52; // r3
  unsigned int v53; // r3
  int v54; // r0
  bool v55; // zf
  __int64 *v56; // r0
  int v57; // r4
  int v58; // r1
  int v59; // r2
  int v60; // r3
  unsigned int v61; // r0
  unsigned int v62; // r0
  int v63; // [sp+Ch] [bp-74h]
  int v64; // [sp+10h] [bp-70h]
  int v65; // [sp+14h] [bp-6Ch]
  _DWORD v67[2]; // [sp+30h] [bp-50h] BYREF
  _DWORD v68[2]; // [sp+38h] [bp-48h] BYREF
  __int16 v69; // [sp+40h] [bp-40h] BYREF
  __int16 v70; // [sp+42h] [bp-3Eh]
  __int16 v71; // [sp+44h] [bp-3Ch]
  __int16 v72; // [sp+46h] [bp-3Ah]
  int v73; // [sp+58h] [bp-28h]
  int v74; // [sp+5Ch] [bp-24h]

  v1 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(unsigned int **)(v2 + 0x150);
  v63 = (int)v3;
  PspClearProcessThreadCidRefs(v2, *(_DWORD *)(v2 + 0x370), v2);
  v4 = *(_DWORD *)(v2 + 116);
  if ( v3 != (unsigned int *)v4 )
    KeBugCheckEx(5, (int)v3, v4, *(unsigned __int8 *)(v2 + 362), v2);
  KfLowerIrql(0);
  if ( (*(_DWORD *)(v2 + 964) & 1) != 0 )
    KeBugCheckEx(233, v2, 0, 0, 0);
  v5 = *(_DWORD *)(v2 + 308);
  if ( v5 )
    KeBugCheckEx(32, 0, v5, 0, 1);
  if ( *(_DWORD *)(v2 + 848) )
  {
    KeSetThreadChargeOnlySchedulingGroup(v2, 0);
    ObfDereferenceObjectWithTag(*(_DWORD *)(v2 + 848));
    *(_DWORD *)(v2 + 848) = 0;
  }
  PspEmptyPropertySet((_DWORD *)(v2 + 1060));
  v6 = *(_DWORD *)(v2 + 1056);
  if ( v6 )
  {
    ObfDereferenceObjectWithTag(v6 & 0xFFFFFFFE);
    *(_DWORD *)(v2 + 1056) = 0;
  }
  v7 = (unsigned int *)(v2 + 940);
  v8 = 1;
  do
  {
    v9 = __ldrex(v7);
    if ( v9 )
      break;
    v6 = __strex(1u, v7);
  }
  while ( v6 );
  __dmb(0xBu);
  if ( v9 && v9 != 1 )
    ExfWaitForRundownProtectionRelease(v7, v9);
  v10 = *(_DWORD *)(v2 + 928);
  if ( v10 )
  {
    PopPowerRequestCleanUp(*(_DWORD *)(v2 + 928), v9, v8, v6);
    ObfDereferenceObject(v10);
    *(_DWORD *)(v2 + 928) = 0;
  }
  v64 = 0;
  v65 = 0;
  *(_DWORD *)(v2 + 984) = v1;
  if ( (v3[184] & 1) == 0 && (PerfGlobalGroupMask & 2) != 0 )
    EtwTraceThread(v2, 0, 0);
  --*(_WORD *)(v2 + 308);
  if ( (v3[184] & 1) == 0 )
  {
    v11 = PspNotifyEnableMask;
    __dmb(0xBu);
    if ( (v11 & 0x10) != 0 || (v12 = PspNotifyEnableMask, __dmb(0xBu), (v12 & 8) != 0) )
    {
      v13 = &PspCreateThreadNotifyRoutine;
      v14 = 64;
      do
      {
        v15 = ExReferenceCallBackBlock(v13);
        v16 = v15;
        if ( v15 )
        {
          v17 = (void (__fastcall *)(_DWORD, _DWORD, _DWORD))KeReadStateSemaphore(v15);
          v17(*(_DWORD *)(*(_DWORD *)(v2 + 336) + 176), *(_DWORD *)(v2 + 880), 0);
          ExDereferenceCallBackBlock(v13, v16);
        }
        ++v13;
        --v14;
      }
      while ( v14 );
      v3 = (unsigned int *)v63;
      v1 = a1;
    }
  }
  v18 = (unsigned __int8 *)(v3 + 42);
  v19 = KeAbPreAcquire((unsigned int)(v3 + 42), 0, 0);
  v20 = v19;
  do
    v21 = __ldrex(v18);
  while ( __strex(v21 | 1, v18) );
  __dmb(0xBu);
  if ( (v21 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3 + 42, v19, (unsigned int)(v3 + 42));
  if ( v20 )
    *(_BYTE *)(v20 + 14) |= 1u;
  v22 = v3[101] - 1;
  __dmb(0xBu);
  v3[101] = v22;
  v23 = v3[101];
  __dmb(0xBu);
  if ( v23 )
  {
    if ( v1 != -1073741749 )
      v3[104] = v1;
  }
  else
  {
    __dmb(0xBu);
    v24 = v3 + 48;
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 | 0x2000008, v24) );
    __dmb(0xBu);
    KeForceResumeProcess(v3);
    v64 = 1;
    if ( v3[158] == 259 )
    {
      if ( v1 == -1073741749 )
        v3[158] = v3[104];
      else
        v3[158] = v1;
    }
    v26 = (unsigned int *)v3[99];
    v27 = v3 + 99;
    if ( v26 != v3 + 99 )
    {
      do
      {
        if ( v26 - 233 != (unsigned int *)v2 && !*((_BYTE *)v26 - 928) && ObReferenceObjectSafe((int)(v26 - 233)) )
        {
          __dmb(0xBu);
          do
            v28 = __ldrex((unsigned int *)v18);
          while ( __strex(v28 - 1, (unsigned int *)v18) );
          if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v18);
          v29 = KeAbPostRelease((unsigned int)v18);
          v30 = *(_WORD *)(v2 + 308) + 1;
          *(_WORD *)(v2 + 308) = v30;
          if ( !v30 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
            KiCheckForKernelApcDelivery(v29);
          KeWaitForSingleObject((unsigned int)(v26 - 233), 0, 0, 0, 0);
          if ( v65 )
            ObfDereferenceObject(v65);
          v65 = (int)(v26 - 233);
          --*(_WORD *)(v2 + 308);
          v31 = KeAbPreAcquire((unsigned int)v18, 0, 0);
          v32 = v31;
          do
            v33 = __ldrex(v18);
          while ( __strex(v33 | 1, v18) );
          __dmb(0xBu);
          if ( (v33 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v18, v31, (unsigned int)v18);
          if ( v32 )
            *(_BYTE *)(v32 + 14) |= 1u;
        }
        v26 = (unsigned int *)*v26;
      }
      while ( v26 != v27 );
      v3 = (unsigned int *)v63;
    }
  }
  __dmb(0xBu);
  do
    v34 = __ldrex((unsigned int *)v18);
  while ( __strex(v34 - 1, (unsigned int *)v18) );
  if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v18);
  v35 = KeAbPostRelease((unsigned int)v18);
  v36 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v36;
  if ( !v36 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v35);
  if ( v65 )
    ObfDereferenceObject(v65);
  if ( v3[85] && (*(_DWORD *)(v2 + 76) & 0x400) == 0 )
  {
    if ( v64 )
      DbgkExitProcess(v3[158]);
    else
      DbgkExitThread(a1);
  }
  v37 = 0;
  if ( KdDebuggerEnabled && (*(_DWORD *)(v2 + 960) & 0x20) != 0 )
  {
    v38 = *(_DWORD *)(*(_DWORD *)(v2 + 336) + 192);
    __dmb(0xBu);
    v39 = v63;
    if ( (v38 & 0x40000008) == 0 )
    {
      v37 = PsGetProcessServerSilo(v63);
      if ( PsGetServerSiloState(v37) != 2 )
        PspCatchCriticalBreak("Critical thread 0x%p (in %s) exited\n", (const void *)v2, (const char *)(v63 + 360));
    }
  }
  else
  {
    v39 = v63;
  }
  if ( v64 && (*(_DWORD *)(v39 + 192) & 0x2000) != 0 )
  {
    if ( !v37 )
      v37 = PsGetProcessServerSilo(v39);
    if ( KdDebuggerEnabled )
    {
      if ( PsGetServerSiloState(v37) != 2 )
        PspCatchCriticalBreak("Critical process 0x%p (%s) exited\n", (const void *)v39, (const char *)(v39 + 360));
      if ( !v37 )
      {
LABEL_104:
        v40 = *(_DWORD **)(v2 + 860);
        if ( v40 )
        {
          v69 = 8;
          v70 = 32;
          v71 = 6;
          v72 = 0;
          v73 = *(_DWORD *)(v2 + 832);
          v74 = *(_DWORD *)(v2 + 836);
          do
          {
            while ( 1 )
            {
              v41 = LpcRequestPort(v40[1], (int)&v69);
              if ( v41 != -1073741801 && v41 != -1073741670 )
                break;
              KeDelayExecutionThread(0, 0, (unsigned int *)PspShortTime);
            }
            ObfDereferenceObject(v40[1]);
            v42 = (_DWORD *)*v40;
            ExFreePoolWithTag((unsigned int)v40);
            v40 = v42;
          }
          while ( v42 );
        }
        v43 = (unsigned int *)v63;
        if ( (*(_DWORD *)(v2 + 960) & 2) != 0 )
        {
          v44 = PsCaptureExceptionPort(v63);
          if ( v44 )
          {
            v69 = 8;
            v70 = 32;
            v71 = 6;
            v72 = 0;
            v73 = *(_DWORD *)(v2 + 832);
            v74 = *(_DWORD *)(v2 + 836);
            while ( 1 )
            {
              v45 = LpcRequestPort(v44, (int)&v69);
              if ( v45 != -1073741801 && v45 != -1073741670 )
                break;
              KeDelayExecutionThread(0, 0, (unsigned int *)PspShortTime);
            }
            ObfDereferenceObject(v44);
          }
        }
        v46 = *(_DWORD *)(v2 + 284);
        __dmb(0xBu);
        if ( v46 )
        {
          v67[0] = v2;
          v67[1] = 1;
          PsInvokeWin32Callout(1, v67, 0, 0);
        }
        if ( v64 && *(_DWORD *)(v63 + 284) )
        {
          v68[0] = v63;
          v68[1] = 0;
          PsInvokeWin32Callout(0, v68, 0, 0);
        }
        if ( (*(_DWORD *)(v2 + 80) & 0x20) == 0 )
          KeBugCheckEx(148, 0, v2, 0, 0);
        IoCancelThreadIo();
        ExTimerRundown();
        CmNotifyRunDown(v2, v47);
        v48 = (unsigned int *)KiRundownMutants(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        v49 = *(_DWORD *)(v2 + 156);
        if ( v49 )
        {
          *(_DWORD *)(v2 + 156) = 0;
          --*(_WORD *)(v2 + 308);
          __dmb(0xFu);
          v50 = *(_DWORD *)(v2 + 944);
          __dmb(0xBu);
          if ( (v50 & 1) != 0 )
          {
            v51 = KeAbPreAcquire(v2 + 944, 0, 0);
            ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 944), v51, v2 + 944);
            if ( v51 )
              *(_BYTE *)(v51 + 14) |= 1u;
            v48 = ExfReleasePushLockExclusive((unsigned int *)(v2 + 944));
            if ( v51 )
              v48 = (unsigned int *)KeAbPostRelease(v2 + 944);
            v43 = (unsigned int *)v63;
          }
          v52 = *(_WORD *)(v2 + 308) + 1;
          *(_WORD *)(v2 + 308) = v52;
          if ( !v52 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
            KiCheckForKernelApcDelivery((int)v48);
          if ( (*(_DWORD *)(v2 + 76) & 0x400) == 0 )
          {
            v53 = v43[48];
            __dmb(0xBu);
            if ( (v53 & 0x40000008) == 0 )
            {
              if ( (*(_DWORD *)(v2 + 960) & 2) != 0 )
                ZwFreeVirtualMemory();
              v54 = *(_DWORD *)(v49 + 3876);
              if ( v54 )
                ObCloseHandle(v54);
              MmDeleteTeb((int)v43, v49);
            }
          }
        }
        v55 = KeQuerySystemTimeUnsafe() == 0;
        v56 = (__int64 *)(v2 + 840);
        if ( v55 )
          KeQuerySystemTime(v56);
        else
          KeQuerySystemTimePrecise(v56);
        if ( v64 )
        {
          v43[174] = *(_DWORD *)(v2 + 840);
          v43[175] = *(_DWORD *)(v2 + 844);
          PspExitProcess(1, (int)v43);
          v57 = PsReferencePrimaryToken((int)v43);
          if ( SeAuditingWithTokenForSubcategory(134) )
            SeAuditProcessExit(v43, v43[158]);
          ObFastDereferenceObject(v43 + 61, v57);
          ExWnfExitProcess((int)v43, 0);
          PspRundownSingleProcess(v43, 1);
          v61 = v43[201];
          if ( v61 )
            PspRemoveProcessFromSilo(v61, v43);
          LpcExitProcess((int)v43, v58, v59, v60);
          v62 = v43[176];
          if ( v62 )
          {
            ExFreePoolWithTag(v62);
            v43[176] = 0;
          }
        }
        KeRundownApcQueues(v2);
        if ( *(_DWORD *)(v2 + 440) )
        {
          if ( PspLegoNotifyRoutine )
            PspLegoNotifyRoutine(v2);
        }
        KeTerminateThread(v2);
        __debugbreak();
      }
    }
    else if ( !v37 )
    {
      KeBugCheckEx(239, v39, 0, 0, 0);
    }
    if ( PsGetServerSiloState(v37) != 2 )
      PsTerminateServerSilo(v37, a1);
  }
  if ( v37 )
    PspDereferenceSiloObject(v37);
  goto LABEL_104;
}
