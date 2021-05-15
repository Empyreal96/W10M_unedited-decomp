// PopInvokeSystemStateHandler 
 
int __fastcall PopInvokeSystemStateHandler(int a1, int a2)
{
  int v4; // r9
  int result; // r0
  int (__fastcall *v6)(int, int, int, int); // r5
  int v7; // r10
  unsigned int i; // r5
  int v9; // r7
  int v10; // r3
  int *v11; // r7
  unsigned int v12; // r1
  unsigned int v13; // r0
  int v14; // r5
  int v15; // r10
  __int64 v16; // kr08_8
  __int64 v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  __int64 v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // r1
  int v26; // r2
  int v27; // r3
  BOOL v28; // r4
  int v29; // r2
  int v30; // r1
  __int64 v31; // r0
  __int64 v32; // r0
  int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r4
  int v36; // r6
  __int64 v37; // r0
  int v38; // r2
  int v39; // r3
  unsigned __int64 v40; // [sp+8h] [bp-110h]
  int v41; // [sp+10h] [bp-108h]
  unsigned int v42; // [sp+10h] [bp-108h]
  int v43[6]; // [sp+18h] [bp-100h] BYREF
  int v44; // [sp+30h] [bp-E8h]
  unsigned int v45; // [sp+38h] [bp-E0h] BYREF
  unsigned int v46; // [sp+3Ch] [bp-DCh]
  int v47[14]; // [sp+40h] [bp-D8h] BYREF
  int v48[4]; // [sp+78h] [bp-A0h] BYREF
  _DWORD v49[2]; // [sp+88h] [bp-90h] BYREF
  unsigned __int64 v50; // [sp+90h] [bp-88h] BYREF
  char v51[2]; // [sp+98h] [bp-80h] BYREF
  __int16 v52; // [sp+9Ah] [bp-7Eh]
  int v53[4]; // [sp+B8h] [bp-60h] BYREF
  int v54[4]; // [sp+C8h] [bp-50h] BYREF
  _DWORD v55[4]; // [sp+D8h] [bp-40h] BYREF
  _DWORD v56[12]; // [sp+E8h] [bp-30h] BYREF

  v4 = -1073741823;
  v44 = 0;
  v40 = 0i64;
  memset(v47, 0, sizeof(v47));
  v56[0] = 0;
  v56[1] = 0;
  v56[2] = 0;
  v56[3] = 0;
  v47[0] = (int)v56;
  v47[4] = (int)&PopPowerStateNotifyHandler;
  v47[5] = a1;
  if ( a1 != 7 )
  {
    v47[0] = (int)&PopPowerStateHandlers[4 * a1];
    if ( !*(_DWORD *)(v47[0] + 8) )
      return -1073741632;
  }
  v47[7] = KeNumberProcessors_0;
  v47[10] = KeNumberProcessors_0;
  __dmb(0xBu);
  v47[9] = 1;
  if ( (a1 == 3 || a1 == 6) && a2 )
  {
    v6 = PopSaveHiberContextWrapper;
    v7 = a2;
    v47[2] = a2;
    v47[3] = a2;
    v47[1] = (int)PopSaveHiberContextWrapper;
    v41 = a2;
  }
  else
  {
    v7 = v47[3];
    v6 = (int (__fastcall *)(int, int, int, int))v47[1];
    v41 = v47[2];
  }
  memset(v43, 0, sizeof(v43));
  if ( a2 )
  {
    v11 = PopHibernateSystemContext;
    PopHibernateSystemContext[0] = v47[0];
    unk_61F284 = v6;
    unk_61F288 = v41;
    dword_61F28C = v7;
    dword_61F290 = v47[4];
    dword_61F294 = v47[5];
    byte_61F298 = v47[6];
    dword_61F29C = v47[7];
    dword_61F2A8 = v47[10];
    dword_61F2A4 = v47[9];
    RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_61F2B0, &v43[5]);
  }
  else
  {
    v48[1] = 0;
    v48[2] = 0;
    v48[0] = 1;
    KeSetSystemGroupAffinityThread((int)v48, 0);
    v44 = KfRaiseIrql(2);
    KeInitializeDpc((int)v51, (int)PopInvokeStateHandlerTargetProcessor, (int)v47);
    v51[1] = 2;
    for ( i = 0; i < KeNumberProcessors_0; ++i )
    {
      if ( i != *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
      {
        v9 = v47[8];
        __dmb(0xBu);
        v52 = i + 32;
        KeInsertQueueDpc((int)v51);
        while ( 1 )
        {
          v10 = v47[8];
          __dmb(0xBu);
          if ( v9 != v10 )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
    }
    v11 = v47;
  }
  PopIssueNextState(v11, v43, 2);
  if ( dword_61EC80 == 4 )
  {
    v12 = 0;
    v13 = 0;
    v45 = 0;
    v42 = 0;
    v16 = *(_QWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x948);
    v15 = HIDWORD(v16);
    v14 = v16;
  }
  else
  {
    v15 = HIDWORD(PopQpcFrequency);
    v14 = PopQpcFrequency;
    KeQueryPerformanceCounter(&v45, 0);
    v12 = v45;
    v13 = v46;
    v42 = v45;
    v45 = v46;
  }
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v54[0] = (int)v55;
    v54[1] = 0;
    v54[2] = 16;
    v55[0] = v12;
    v55[1] = v13;
    v54[3] = 0;
    v55[2] = v14;
    v55[3] = v15;
    EtwTraceKernelEvent(v54, 1, 0x80008000, 4656, 4200450);
  }
  PopIssueNextState(v11, v43, 3);
  if ( a2 )
  {
    RtlpDebugPrintCallbacksActive = 0;
    if ( VfIsVerifierEnabled() )
      VfNotifyOfHibernate(1);
  }
  PoAllProcIntrDisabled = 1;
  if ( v43[3] >= 0 )
  {
    *((_BYTE *)v11 + 24) = 1;
    PopIssueNextState(v11, v43, 9);
    if ( a1 != 3 && a1 != 6 )
      ((void (__cdecl *)())off_617B0C)();
    if ( a2 )
    {
      PopIssueNextState(v11, v43, 4);
      MiUpdateUserMappings();
      PopIssueNextState(v11, v43, 7);
    }
    v17 = PopIssueNextState(v11, v43, 5);
    v4 = v43[3];
    KeRebaselineInterruptTime(v17, SHIDWORD(v17), v18, v19);
    ((void (__cdecl *)())off_617B04)();
    if ( a2 )
    {
      if ( v4 == 1073742484 )
        PopIssueNextState(v11, v43, 6);
      PopHiberEarlyCleanup(a2);
      PopIssueNextState(v11, v43, 7);
      MiUpdateUserMappings();
      *(_BYTE *)(a2 + 4) = 0;
      PopIssueNextState(v11, v43, 8);
    }
    if ( (PopDebugFlags & 1) != 0 && KdDebuggerEnabled )
      DbgBreakPointWithStatus();
    if ( (PopDebugFlags & 2) != 0 )
      KeBugCheckEx(160, 10, 0, 0, 0);
    __dmb(0xBu);
    PopNoMoreInput = 0;
    if ( v4 >= 0 )
    {
      PopFullWake = 0;
      ++PoPowerSequence;
      dword_61E808 = 1;
      if ( PoResumeFromHibernate )
      {
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)&PopFullWake);
        while ( __strex(v20 | 2, (unsigned int *)&PopFullWake) );
        __dmb(0xBu);
      }
    }
    *((_BYTE *)v11 + 24) = 0;
    PopIssueNextState(v11, v43, 9);
  }
  if ( a2 )
  {
    PopHiberComplete(v4, a2);
    if ( *(_BYTE *)a2 )
    {
      *v11 = (int)&unk_61EA10;
      v11[3] = 0;
      if ( dword_61EA18 )
        PopIssueNextState(v11, v43, 5);
      HalReturnToFirmware(3);
    }
    if ( VfIsVerifierEnabled() )
      VfNotifyOfHibernate(0);
    if ( RtlpDebugPrintCallbackList == &RtlpDebugPrintCallbackList )
      RtlpDebugPrintCallbacksActive = 1;
    *(_DWORD *)(a2 + 120) = 1073742484;
  }
  v21 = PopIssueNextState(v11, v43, 10);
  v24 = KeRebaselineInterruptTime(v21, SHIDWORD(v21), v22, v23);
  KeRebaselineSystemTime(v24, v25, v26, v27);
  PoAllProcIntrDisabled = 0;
  PopIssueNextState(v11, v43, 11);
  if ( v4 >= 0 )
  {
    v28 = dword_61EC80 == 4 && !PoResumeFromHibernate;
    if ( v28 )
    {
      if ( !((int (__cdecl *)())off_6179F8)() )
      {
        v29 = 0;
        v30 = 0;
        v40 = 0i64;
LABEL_67:
        if ( (dword_682610 & 0x8000) != 0 )
        {
          v53[0] = (int)v49;
          v53[1] = 0;
          v53[2] = 8;
          v53[3] = 0;
          v49[0] = v29;
          v49[1] = v30;
          EtwTraceKernelEvent(v53, 1, 0x80008000, 4657, 4200450);
        }
        if ( v28 )
        {
          LODWORD(v31) = _rt_udiv64(1000000i64, *(_QWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x948));
          v32 = 1000 * v31;
          if ( !v32 )
            __brkdiv0();
          v33 = _rt_udiv64(v32, v40);
          v35 = v34;
          v36 = v33;
          LODWORD(v37) = _rt_udiv64(1000i64, PopQpcFrequency);
          qword_61EF78 = __PAIR64__(v35, v36) * v37 - __PAIR64__(v45, v42);
        }
        goto LABEL_73;
      }
    }
    else
    {
      KeQueryPerformanceCounter(&v50, 0);
      v40 = v50;
      ((void (__cdecl *)())off_6179F8)();
    }
    v30 = HIDWORD(v40);
    v29 = v40;
    goto LABEL_67;
  }
LABEL_73:
  PopIssueNextState(v11, v43, 12);
  PopIssueNextState(v11, v43, 13);
  result = v43[3];
  if ( v43[3] >= 0 )
  {
    v38 = *v11;
    result = 0;
    v43[3] = 0;
    v39 = *(unsigned __int8 *)(v38 + 5);
    if ( v39 != 255 )
    {
      *(_BYTE *)(v38 + 5) = v39 + 1;
      result = v43[3];
    }
  }
  if ( !a2 )
  {
    KfLowerIrql(v44);
    goto LABEL_81;
  }
  if ( v4 == 1073742484 && !byte_61EED1 )
  {
    BgkResumeProgressTransition();
LABEL_81:
    result = v43[3];
  }
  return result;
}
