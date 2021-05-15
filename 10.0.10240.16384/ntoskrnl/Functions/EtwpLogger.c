// EtwpLogger 
 
int __fastcall EtwpLogger(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0
  int v4; // r9
  int v5; // r3
  unsigned int v6; // r8
  unsigned int *v7; // r6
  unsigned int v8; // r0
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r3
  int v12; // r8
  unsigned int v13; // r3
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r3
  int v19; // r0
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r5
  int v23; // r3
  int v24; // r2
  int v25; // r3
  int v26; // r1
  unsigned int v28; // r3
  unsigned __int8 *v29; // r1
  unsigned int v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r3
  unsigned __int8 *v33; // r3
  unsigned int v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r3
  int v37; // r8
  unsigned int v38; // r1
  unsigned int v39; // r1
  __int64 v40; // kr00_8
  __int64 v41; // kr08_8
  __int64 v42; // kr10_8
  int v43; // [sp+18h] [bp-38h]
  int v44; // [sp+1Ch] [bp-34h]
  unsigned int v45[10]; // [sp+28h] [bp-28h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = a1[163];
  a1[9] = v2 & 0xFFFFFFC0;
  v4 = PsAttachSiloToCurrentThread(v3);
  KeSetActualBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 15);
  KeSetEvent((int)(a1 + 89), 0, 0);
  v45[1] = (unsigned int)(a1 + 98);
  v5 = a1[62];
  v6 = (unsigned int)(a1 + 93);
  v45[0] = (unsigned int)(a1 + 93);
  if ( v5 )
  {
    v7 = a1 + 153;
    while ( 1 )
    {
      v8 = 1;
      if ( a1[33] )
        v8 = 2;
      v9 = 0;
      v43 = 0;
      if ( KeWaitForMultipleObjects(v8, v45, 1, 0, 0, 0, 0, 0) == 1 )
      {
        v28 = *v7;
        __dmb(0xBu);
        if ( (v28 & 0x400) != 0 )
        {
          __dmb(0xBu);
          v29 = (unsigned __int8 *)a1 + 613;
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 & 0xFB, v29) );
          __dmb(0xBu);
        }
        KeResetEvent(v6);
        v9 = 1;
        v43 = 1;
      }
      if ( EtwpFileSystemReady )
        a1[152] |= 4u;
      v10 = EtwpAdjustFreeBuffers(a1);
      v11 = *v7;
      __dmb(0xBu);
      v12 = v11 & 4;
      v44 = v12;
      if ( (v11 & 4) != 0 )
      {
        if ( a1[33] )
        {
          v32 = *v7;
          __dmb(0xBu);
          if ( (v32 & 0x400) != 0 )
          {
            v10 = KeCancelTimer((int)(a1 + 98));
            __dmb(0xBu);
            v33 = (unsigned __int8 *)a1 + 613;
            do
              v34 = __ldrex(v33);
            while ( __strex(v34 & 0xFB, v33) );
            __dmb(0xBu);
          }
        }
        v9 = 1;
        v43 = 1;
      }
      if ( (a1[152] & 4) != 0 )
        break;
      EtwpFlushActiveBuffers(a1, v9);
LABEL_20:
      v6 = (unsigned int)(a1 + 93);
      if ( !a1[62] )
      {
        v6 = (unsigned int)(a1 + 93);
        goto LABEL_22;
      }
    }
    v13 = *v7;
    __dmb(0xBu);
    if ( (v13 & 0x80) != 0 )
    {
      __dmb(0xBu);
      do
        v38 = __ldrex(v7);
      while ( __strex(v38 & 0xFFFFFF7F, v7) );
      __dmb(0xBu);
      if ( a1[148] )
        return sub_809990(v10);
    }
    v14 = a1[152];
    if ( (a1[3] & 0x100) != 0 )
      v15 = v14 | 8;
    else
      v15 = v14 & 0xFFFFFFF7;
    a1[152] = v15;
    if ( (v15 & 8) != 0 )
    {
      v21 = EtwpRealtimeCreateLogfile(a1);
      if ( v21 < 0 )
        goto LABEL_74;
      EtwpRealtimeUpdateConsumers(a1);
      EtwpRealtimeFlushSavedBuffers(a1);
      if ( a1[66] && a1[82] )
        EtwpRequestFlushTimer((int)a1, 0);
    }
    v16 = *v7;
    __dmb(0xBu);
    if ( (v16 & 0x40) != 0 )
    {
      __dmb(0xBu);
      do
        v31 = __ldrex(v7);
      while ( __strex(v31 & 0xFFFFFFBF, v7) );
      __dmb(0xBu);
      EtwpRealtimeNotifyConsumers(a1);
    }
    v17 = *v7;
    __dmb(0xBu);
    if ( (v17 & 8) != 0 )
    {
      EtwpRealtimeDisconnectAllConsumers(a1);
      __dmb(0xBu);
      do
        v39 = __ldrex(v7);
      while ( __strex(v39 & 0xFFFFFFF7, v7) );
      __dmb(0xBu);
      a1[10] = 0;
      KeSetEvent((int)(a1 + 89), 0, 0);
    }
    v18 = *v7;
    __dmb(0xBu);
    if ( (v18 & 3) == 0 )
    {
LABEL_17:
      v19 = EtwpFlushActiveBuffers(a1, v9);
      v20 = *v7;
      v21 = v19;
      __dmb(0xBu);
      if ( (v20 & 1) != 0 && v19 >= 0 && !v9 )
        v21 = EtwpFlushActiveBuffers(a1, 1);
      if ( v12 )
      {
        __dmb(0xBu);
        do
          v35 = __ldrex(v7);
        while ( __strex(v35 & 0xFFFFFFFB, v7) );
        __dmb(0xBu);
        a1[10] = v21;
        KeSetEvent((int)(a1 + 89), 0, 0);
      }
      if ( v21 >= 0 )
        goto LABEL_20;
      goto LABEL_74;
    }
    v36 = *v7;
    v37 = 1;
    __dmb(0xBu);
    if ( (v36 & 2) != 0 && a1[148] )
      v37 = 0;
    v21 = EtwpCreateLogFile(a1, 1);
    a1[10] = v21;
    if ( v21 < 0 )
    {
      if ( (a1[3] & 8) != 0 )
      {
        v40 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
        if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_SWITCH_TO_NEW_FILE_FAILED) )
          EtwpEventWriteTemplateAdmin(v40, HIDWORD(v40), ETW_EVENT_SWITCH_TO_NEW_FILE_FAILED);
      }
      v9 = v43;
    }
    KeSetEvent((int)(a1 + 89), 0, 0);
    if ( v21 >= 0 || v37 != 1 )
    {
      v12 = v44;
      goto LABEL_17;
    }
LABEL_74:
    v41 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_SESSION_END_FAILED) )
      EtwpEventWriteTemplateSessionEnd(v41, HIDWORD(v41));
    a1[10] = v21;
    EtwpStopLoggerInstance(a1);
    goto LABEL_20;
  }
LABEL_22:
  v22 = EtwpFlushActiveBuffers(a1, 1);
  if ( v22 >= 0 )
  {
    while ( v22 != 259 )
    {
      v23 = a1[40];
      __dmb(0xBu);
      if ( v23 > 0 )
      {
        v24 = a1[40];
        __dmb(0xBu);
        v25 = a1[39];
        __dmb(0xBu);
        if ( v24 > v25 )
        {
          KeWaitForSingleObject(v6, 0, 0, 0, EtwpOneSecond);
          v22 = EtwpFlushActiveBuffers(a1, 1);
          if ( v22 >= 0 )
            continue;
        }
      }
      goto LABEL_26;
    }
    if ( (a1[152] & 8) == 0 || a1[68] )
      v22 = -1073741823;
    else
      v22 = 0;
  }
LABEL_26:
  v26 = a1[148];
  if ( v26 )
  {
    EtwpFinalizeHeader(a1, v26, 0);
    ZwClose();
    a1[148] = 0;
  }
  if ( a1[68] )
  {
    EtwpRealtimeSaveState(a1);
    ZwClose();
    a1[68] = 0;
  }
  a1[10] = v22;
  KeSetEvent((int)(a1 + 89), 0, 0);
  if ( v22 < 0 )
  {
    v42 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_STOP_TRACE) )
      EtwpEventWriteTemplateSession(v42, HIDWORD(v42), ETW_EVENT_STOP_TRACE, a1);
  }
  EtwpFreeLoggerContext(a1);
  PsDetachSiloFromCurrentThread(v4);
  return PsTerminateSystemThread(v22);
}
