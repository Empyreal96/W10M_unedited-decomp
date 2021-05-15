// PspInitPhase0 
 
int PspInitPhase0()
{
  int v0; // r4
  _DWORD *v2; // r3
  int *v3; // r5
  int v4; // r4
  int v5; // r0
  int v6; // r0
  _DWORD *v7; // r3
  int v8[2]; // [sp+10h] [bp-98h] BYREF
  int v9[6]; // [sp+18h] [bp-90h] BYREF
  int v10[22]; // [sp+30h] [bp-78h] BYREF

  v0 = PspSystemMitigationOptions;
  PspMinimumWorkingSet += 30;
  PspMaximumWorkingSet += 300;
  if ( PspValidateMitigationOptions(*(__int64 *)&PspSystemMitigationOptions, 0i64) < 0 )
    return sub_966164();
  if ( (v0 & 0x30000000) != 0 )
    PspSystemMitigationOptions = v0 & 0xCFFFFFFF;
  PspInitializeCallbacks();
  PsChangeQuantumTable(0, PsRawPrioritySeparation);
  PsActiveProcessHead = (int)&PsActiveProcessHead;
  dword_61DAF4 = (int)&PsActiveProcessHead;
  PspActiveProcessLock = 0;
  v2 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v2[42] = 0;
  v2[43] = 0;
  v2[38] = 0;
  PsIdleProcess = (int)v2;
  memset(v10, 0, sizeof(v10));
  LOWORD(v10[0]) = 88;
  BYTE2(v10[0]) |= 8u;
  v10[9] = 512;
  RtlInitUnicodeString((unsigned int)v8, L"Job");
  v10[1] = 2048;
  v10[10] = 0;
  v10[11] = 760;
  v10[15] = (int)PspJobDelete;
  v10[14] = (int)PspJobClose;
  v10[7] = 2031647;
  v10[3] = 131076;
  v10[4] = 131083;
  v10[5] = 1179648;
  v10[6] = 2031647;
  v10[2] = 0;
  BYTE2(v10[0]) &= 0x7Fu;
  if ( ObCreateObjectType() >= 0 && SeRegisterObjectTypeMandatoryPolicy(PsJobType, 1) >= 0 )
  {
    BYTE2(v10[0]) |= 0x42u;
    v10[2] = 176;
    RtlInitUnicodeString((unsigned int)v8, L"Process");
    v10[1] = 32;
    v10[10] = 4096;
    v10[11] = 888;
    v10[15] = (int)PspProcessDelete;
    v10[13] = (int)PspProcessOpen;
    v10[14] = (int)PspProcessClose;
    v10[7] = 0x1FFFFF;
    v10[8] = 1052672;
    v10[3] = 132112;
    v10[4] = 134122;
    v10[5] = 1183745;
    v10[6] = 0x1FFFFF;
    BYTE2(v10[0]) |= 0x80u;
    if ( ObCreateObjectType() >= 0 && SeRegisterObjectTypeMandatoryPolicy(PsProcessType, 3) >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v8, L"Thread");
      v10[1] = 4;
      v10[10] = 0;
      v10[11] = 1104;
      v10[15] = (int)PspThreadDelete;
      v10[7] = 0x1FFFFF;
      v10[13] = (int)PspThreadOpen;
      v10[14] = 0;
      v10[8] = 1054720;
      v10[3] = 131144;
      v10[4] = 132151;
      v10[5] = 1185792;
      v10[6] = 0x1FFFFF;
      BYTE2(v10[0]) |= 0x80u;
      if ( ObCreateObjectType() >= 0 && SeRegisterObjectTypeMandatoryPolicy(PsThreadType, 3) >= 0 )
      {
        memset(v10, 0, sizeof(v10));
        LOWORD(v10[0]) = 88;
        BYTE2(v10[0]) |= 2u;
        v10[2] = 176;
        v10[9] = 512;
        v10[3] = 131073;
        v10[4] = 131074;
        v10[5] = 0x20000;
        v10[6] = 983043;
        v3 = &PspMemoryReserveObjectNames;
        v4 = 0;
        v10[7] = 983043;
        BYTE2(v10[0]) &= 0x7Fu;
        while ( 1 )
        {
          v10[11] = PspMemoryReserveObjectSizes[v4];
          if ( ObCreateObjectType() < 0 )
            break;
          ++v4;
          v3 += 2;
          if ( v4 >= 2 )
          {
            v5 = PspInitializeJobStructures();
            if ( PspInitializeSiloStructures(v5) )
            {
              PspWorkingSetChangeHead = &PspWorkingSetChangeHead;
              off_618E24 = &PspWorkingSetChangeHead;
              dword_618E28 = 0;
              PspAffinityUpdateLock = 0;
              PspCidTable = ExCreateHandleTable(0, 0);
              if ( PspCidTable )
              {
                SmRegistrationCtxInitialize(&PsWin32CallBack);
                *(_BYTE *)(PspCidTable + 28) |= 1u;
                PsReaperListHead = 0;
                dword_61DAE8 = (int)PspReaper;
                dword_61DAEC = 0;
                PsReaperWorkItem = 0;
                dword_61DB08 = (int)PspProcessRundownWorker;
                dword_61DB0C = 0;
                PspProcessRundownWorkItem = 0;
                dword_61DB28 = (int)PspProcessRundownWorkerSingle;
                dword_61DB2C = 0;
                PspProcessRundownCacheWorkItem = 0;
                PspBootAccessToken = *(_DWORD *)(PsIdleProcess + 244) & 0xFFFFFFF8;
                v9[0] = 24;
                v9[1] = 0;
                v9[2] = 0;
                v9[3] = 0;
                v9[4] = 0;
                v9[5] = 0;
                if ( PspCreateProcess(&PspInitialSystemProcessHandle, 0x1FFFFF, (int)v9, 0, 0, 0, 0, 0) >= 0 )
                {
                  v6 = ObReferenceObjectByHandle(PspInitialSystemProcessHandle, 0, PsProcessType, 0, (int)v8, 0);
                  PsInitialSystemProcess = v8[0];
                  if ( v6 >= 0 )
                  {
                    strcpy_s((_BYTE *)(PsIdleProcess + 360), 15, "Idle");
                    strcpy_s((_BYTE *)(PsInitialSystemProcess + 360), 15, "System");
                    *(_DWORD *)(PsInitialSystemProcess + 380) = ExAllocatePoolWithTag(512, 8, 1632658771);
                    v7 = *(_DWORD **)(PsInitialSystemProcess + 380);
                    if ( v7 )
                    {
                      *v7 = 0;
                      v7[1] = 0;
                      if ( PsCreateSystemThread((int)v8, 0x1FFFFF, (int)v9) >= 0 )
                      {
                        ObCloseHandle(v8[0]);
                        return 1;
                      }
                    }
                  }
                }
              }
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
