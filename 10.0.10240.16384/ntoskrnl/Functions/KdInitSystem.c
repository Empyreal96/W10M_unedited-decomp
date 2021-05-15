// KdInitSystem 
 
int __fastcall KdInitSystem(int a1, _DWORD *a2)
{
  unsigned int v3; // r5
  int *v4; // r4
  _BYTE *v5; // r0
  _BYTE *v6; // r6
  int v8; // r0
  int *v9; // r0
  int v10; // r1
  char *v11; // r1
  int **v12; // r4
  unsigned int j; // r5
  __int16 *v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r2
  __int16 v17; // t1
  _BYTE *v18; // r4
  int v19; // r3
  int v20; // r3
  int v21; // r7
  _BYTE *v22; // r0
  _BYTE *v23; // r0
  _BYTE *i; // r0
  unsigned int v25; // r3
  int v26; // r3
  char *v27; // r5
  unsigned int v28; // r3
  char v29; // r2
  char v30; // r3
  char v31; // [sp+0h] [bp-130h]
  int v32; // [sp+4h] [bp-12Ch]
  int v33[2]; // [sp+8h] [bp-128h] BYREF
  char v34[288]; // [sp+10h] [bp-120h] BYREF

  v31 = 0;
  v32 = 0;
  if ( a1 )
  {
    KeQueryPerformanceCounter(v33, &KdPerformanceCounterRate);
    if ( !KdPitchDebugger )
    {
      v3 = 0;
      if ( KeNumberProcessors_0 )
      {
        v4 = KdLogBuffer;
        do
        {
          v5 = (_BYTE *)ExAllocatePoolWithTag(512, 4096, 1867080779);
          v6 = v5;
          if ( v5 )
          {
            memset(v5, 0, 4096);
            __dmb(0xFu);
            *v4 = (int)v6;
          }
          ++v3;
          ++v4;
        }
        while ( v3 < KeNumberProcessors_0 );
      }
    }
    KdpLoaderDebuggerBlock = 0;
    return 1;
  }
  if ( KdDebuggerEnabled )
    return 1;
  KiDebugRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))KdpStub;
  KdBreakAfterSymbolLoad = 0;
  if ( !KdPitchDebugger || !KdLocalDebugEnabled )
  {
    v33[0] = 0;
    if ( KdDebugDevice && *(_DWORD *)(KdDebugDevice + 152) == 3 )
      KdTransportMaxPacketSize = 1408;
    v8 = (int)&KdpContext;
    if ( !KdpDebuggerDataListHead )
    {
      dword_62F978 = KdDebugDevice;
      v9 = MmGetPagedPoolCommitPointer();
      *(_QWORD *)(v10 + 368) = (int)v9;
      KdpDebuggerDataListHead = (int)&KdpDebuggerDataListHead;
      dword_62786C = (int)&KdpDebuggerDataListHead;
      KdpPowerSpinLock = 0;
      KdpPowerListHead = (int)&KdpPowerListHead;
      dword_627874 = (int)&KdpPowerListHead;
      v8 = KdRegisterDebuggerDataBlock();
      word_60EA42 = 10240;
      KdVersionBlock = 15;
      byte_60EA4B = 3;
      byte_60EA4C = 51;
      qword_60EA58 = (int)&PsLoadedModuleList;
      qword_60EA60 = (int)&KdpDebuggerDataListHead;
      word_60EA46 |= 1u;
    }
    v25 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( !*(_DWORD *)(v25 + 2712) )
    {
      *(_DWORD *)(v25 + 2712) = v25 + 1952;
      *(_DWORD *)(v25 + 2716) = 2097159;
    }
    if ( !a2 )
    {
      qword_60EA50 = PsNtosImageBase;
      goto LABEL_85;
    }
    v26 = *(_DWORD *)(a2[4] + 24);
    off_60E618 = (void **)&KdpLoaderDebuggerBlock;
    qword_60EA50 = v26;
    KdpLoaderDebuggerBlock = (int)(a2 + 4);
    dword_60E61C = (int)&KdpLoaderDebuggerBlock >> 31;
    v27 = (char *)a2[30];
    KdpCpuBuffer = a2[35];
    if ( !v27 )
    {
      KdPitchDebugger = 1;
      v21 = 0;
      KdPageDebuggerSection = 1;
      goto LABEL_47;
    }
    strupr(v27);
    KdPrintBufferAllocateSize = 0;
    v21 = 0;
    v22 = strstr(v27, "DBGPRINT_LOG_SIZE=");
    if ( v22 )
    {
      v28 = (atol((int)(v22 + 18)) + 4095) & 0xFFFFF000;
      KdPrintBufferAllocateSize = v28;
      if ( v28 > 0x1000000 )
      {
        v28 = 0x1000000;
        KdPrintBufferAllocateSize = 0x1000000;
      }
      if ( v28 <= 0x1000 )
        KdPrintBufferAllocateSize = 0;
    }
    if ( strstr(v27, "CRASHDEBUG") )
    {
      KdPitchDebugger = 0;
      v29 = 0;
    }
    else
    {
      if ( !strstr(v27, "NODEBUG") )
      {
        if ( strstr(v27, "DEBUGPORT=LOCAL") )
        {
          KdPitchDebugger = 1;
          KdPageDebuggerSection = 1;
          KdDebuggerNotPresent = 1;
          KdLocalDebugEnabled = 1;
          KdpBootedNodebug = 0;
          v33[0] = 1;
        }
        else
        {
          v23 = strstr(v27, "DEBUG=");
          if ( v23 || (v23 = strstr(v27, "DEBUG")) != 0 )
          {
            v21 = 1;
            KdpBootedNodebug = 0;
            if ( v23[5] == 61 )
            {
              for ( i = v23 + 6; ; i = v18 + 1 )
              {
                v19 = (char)*i;
                v18 = i;
                while ( v19 && v19 != 32 && v19 != 44 && v19 != 9 )
                  v19 = (char)*++v18;
                v20 = v18 - i;
                if ( v18 == i )
                  goto LABEL_45;
                if ( v20 == 10 )
                  break;
                if ( v20 == 7 )
                {
                  if ( strncmp(i, "DISABLE", 7u) )
                    goto LABEL_44;
                  v31 = 1;
                  v32 = 1;
                  v30 = 0;
                  goto LABEL_81;
                }
                if ( v20 == 6 && !strncmp(i, "NOUMEX", 6u) )
                  KdIgnoreUmExceptions = 1;
LABEL_44:
                if ( *v18 != 44 )
                  goto LABEL_45;
              }
              if ( strncmp(i, "AUTOENABLE", 0xAu) )
                goto LABEL_44;
              v31 = 0;
              v32 = 1;
              v30 = 1;
LABEL_81:
              KdAutoEnableOnEvent = v30;
              goto LABEL_44;
            }
          }
        }
        goto LABEL_45;
      }
      KdPitchDebugger = 1;
      KdPageDebuggerSection = 1;
      v29 = 1;
    }
    KdpBootedNodebug = v29;
LABEL_45:
    v8 = (int)strstr(v27, "NOEVENT");
    if ( v8 )
    {
      KdEventLoggingEnabled = 0;
      goto LABEL_47;
    }
    v8 = (int)strstr(v27, "EVENT");
    if ( !v8 )
    {
LABEL_47:
      dword_60E358 = qword_60EA50;
      dword_60E35C = 0;
      if ( !v33[0] )
      {
        if ( !v21 )
        {
          KdDebuggerNotPresent = 1;
          return 1;
        }
        v8 = KdInitialize_0();
        if ( v8 < 0 )
        {
          KdPitchDebugger = 0;
          KdDebuggerNotPresent = 1;
          KdLocalDebugEnabled = 1;
          LOBYTE(v21) = 0;
        }
        else
        {
          KiDebugRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))KdpTrap;
        }
      }
      if ( !KdpDebuggerStructuresInitialized )
      {
        byte_62F974 = 0;
        KdpContext = 20;
        KiDebugSwitchRoutine = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))KdpSwitchProcessor;
        KeInitializeDpc((int)&KdpTimeSlipDpc, (int)KdpTimeSlipDpcRoutine, 0);
        v8 = (int)KeInitializeTimerEx(KdpTimeSlipTimer, 0);
        dword_646328 = (int)KdpTimeSlipWork;
        dword_64632C = 0;
        KdpTimeSlipWorkItem = 0;
        KdpDebuggerStructuresInitialized = 1;
      }
      KdTimerStart = 0i64;
      if ( KdEventLoggingEnabled && KdpBootedNodebug )
      {
        KdPitchDebugger = 1;
        v11 = &KdDebuggerEnabled;
        KdEventLoggingPresent = v21;
        KdDebuggerNotPresent = 1;
        KdLocalDebugEnabled = 0;
        goto LABEL_20;
      }
      v11 = &KdDebuggerEnabled;
      v8 = 1;
      KdDebuggerEnabled = 1;
      MEMORY[0xFFFF92D4] = 1;
      if ( !KdLocalDebugEnabled )
      {
LABEL_20:
        if ( !KdEventLoggingEnabled || KdDebuggerEnabled )
        {
          KdPitchDebugger = 0;
          if ( v32 )
          {
            KdDisableDebuggerWithLock();
            KdBlockEnable = v31;
          }
          else
          {
            if ( a2 )
            {
              v12 = (int **)a2[4];
              for ( j = 0; v12 != a2 + 4; ++j )
              {
                if ( j >= 3 )
                  break;
                v14 = (__int16 *)v12[10];
                v15 = *((unsigned __int16 *)v12 + 18) >> 1;
                if ( v15 >= 0x100 )
                  v15 = 255;
                v16 = 0;
                do
                {
                  v17 = *v14++;
                  v34[v16++] = v17;
                }
                while ( v16 < v15 );
                if ( v16 >= 0x100 )
                  _report_rangecheckfailure();
                v34[v16] = 0;
                RtlInitAnsiString((unsigned int)v33, (unsigned int)v34);
                v8 = DbgLoadImageSymbols((int)v33, (int)v12[6]);
                v12 = (int **)*v12;
              }
            }
            else
            {
              v8 = DbgLoadImageSymbols(0, dword_60E358);
            }
            if ( a2 )
              KdBreakAfterSymbolLoad = KdPollBreakIn(v8, (int)v11);
          }
        }
      }
      return 1;
    }
    KdEventLoggingEnabled = 1;
    KdPageDebuggerSection = 0;
LABEL_85:
    v21 = 1;
    goto LABEL_47;
  }
  return sub_903C14();
}
