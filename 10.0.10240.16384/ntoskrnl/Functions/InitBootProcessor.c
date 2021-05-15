// InitBootProcessor 
 
int __fastcall InitBootProcessor(int *a1)
{
  int v2; // r1
  unsigned int *v3; // r0
  unsigned int v4; // r3
  char *v5; // r4
  int result; // r0
  _BYTE *v7; // r0
  _BYTE *v8; // r0
  int v9; // r1
  int *v10; // r4
  unsigned int v11; // r5
  int *v12; // r5
  int v13; // r0
  int v14; // r2
  int v15; // r0
  int v16; // r1
  _BYTE *v17; // r0
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v21; // r0
  int v22; // r0
  int v23; // r2
  int v24; // r3
  int v25; // r0
  int v26; // r0
  void *v27; // r5
  int v28; // r4
  unsigned int v29; // r5
  __int16 *v30; // r1
  __int16 v31; // t1
  unsigned int v32; // r2
  unsigned int v33; // r0
  int v34; // r3
  _DWORD *v35; // r2
  int v36; // r8
  int v37; // r1
  int v38; // r0
  int v39; // r3
  int v40; // r0
  int v41; // r0
  int v42; // r2
  int v43; // r3
  int v44; // r0
  int v45; // r1
  int v46; // r0
  int v47; // r1
  int v48; // r0
  int v49; // r1
  int v50; // r0
  int v51; // r1
  unsigned __int8 *v52; // r3
  unsigned int v53; // r2
  int v54; // r0
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r0
  _BYTE *v59; // r0
  unsigned int v60; // r6
  int v61; // r3
  int v62; // r2
  int v63; // r2
  int v64; // r2
  int v65; // r1
  int v66; // r2
  int v67; // r3
  int v68; // r0
  int v69; // r0
  int v70; // r0
  int v71; // r0
  unsigned int v72; // r0
  unsigned int v73; // r0
  unsigned int v74; // r0
  int v75; // r0
  int v76; // r3
  int v77; // r0
  int v78; // r1
  int v79; // r2
  int v80; // r0
  int v81; // r0
  unsigned int v82; // r5
  int v83[2]; // [sp+0h] [bp-260h] BYREF
  unsigned __int16 v84; // [sp+8h] [bp-258h] BYREF
  int v85; // [sp+Ch] [bp-254h]
  unsigned int v86; // [sp+10h] [bp-250h] BYREF
  int v87; // [sp+14h] [bp-24Ch] BYREF
  void *v88; // [sp+18h] [bp-248h] BYREF
  int v89; // [sp+1Ch] [bp-244h] BYREF
  int *v90; // [sp+20h] [bp-240h] BYREF
  int v91; // [sp+24h] [bp-23Ch] BYREF
  int v92; // [sp+28h] [bp-238h] BYREF
  char v93[8]; // [sp+30h] [bp-230h] BYREF
  char v94[16]; // [sp+38h] [bp-228h] BYREF
  int v95[42]; // [sp+48h] [bp-218h] BYREF
  int v96[4]; // [sp+F0h] [bp-170h] BYREF
  char v97[256]; // [sp+100h] [bp-160h] BYREF
  char v98[96]; // [sp+200h] [bp-60h] BYREF

  v2 = *a1;
  if ( *a1 != 10 || a1[1] || a1[2] != 184 )
  {
    v4 = 0;
LABEL_139:
    KeBugCheck2(256, v2, a1[1], a1[2], v4, 0);
  }
  v3 = (unsigned int *)a1[33];
  v4 = *v3;
  if ( *v3 != 2312 )
    goto LABEL_139;
  MEMORY[0xFFFF92C4] = v3[574];
  v5 = (char *)a1[30];
  InitializationPhase = 0;
  if ( v5 )
  {
    strupr(v5);
    if ( strstr(v5, "PERFMEM") )
      return sub_967114();
    v7 = strstr(v5, "BURNMEMORY");
    if ( v7 )
    {
      v8 = strstr(v7, "=");
      if ( v8 )
      {
        v9 = atol((int)(v8 + 1)) << 8;
        if ( v9 )
          ExBurnMemory(a1, v9, 6, &BurnMemoryDescriptor);
      }
    }
    if ( strstr(v5, "FORCEGROUPAWARE") )
      KeForceGroupAwareness = 1;
  }
  v10 = (int *)a1[6];
  if ( v10 != a1 + 6 )
  {
    v11 = InitNlsTableSize;
    do
    {
      if ( v10[2] == 21 )
      {
        if ( RtlULongLongToULong(v10[4] << 12, (unsigned int)v10[4] >> 20, &v92) < 0 )
          goto LABEL_70;
        v34 = v92 + v11;
        if ( v92 + v11 < v11 )
        {
          InitNlsTableSize = -1;
LABEL_70:
          KeBugCheck(49);
        }
        v11 += v92;
        InitNlsTableSize = v34;
      }
      v10 = (int *)*v10;
    }
    while ( v10 != a1 + 6 );
  }
  v12 = (int *)a1[31];
  v13 = *v12;
  InitAnsiCodePageDataOffset = 0;
  InitNlsTableBase = v13;
  InitOemCodePageDataOffset = v12[1] - *v12;
  v14 = v12[2] - *v12 + v13;
  InitUnicodeCaseTableDataOffset = v12[2] - *v12;
  v15 = RtlInitNlsTables(v13, InitOemCodePageDataOffset + v13, v14);
  v17 = RtlResetRtlTranslations(v15, v16);
  WheaInitializeServices(v17);
  off_617B00(HalIommuDispatch);
  if ( !HalInitSystem(InitializationPhase, a1) )
    KeBugCheck(92);
  KeInitializeClock(InitializationPhase, a1);
  KeExternalCacheInitialize();
  PsInitializeQuotaSystem(1);
  CmGetSystemControlValues(a1[24]);
  if ( !PoEnergyEstimationEnabled() )
  {
    __dmb(0xBu);
    v52 = (unsigned __int8 *)(*((_DWORD *)KiProcessorBlock + 3) + 2);
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 & 0xDF, v52) );
    __dmb(0xBu);
  }
  v18 = KeInitializeTimerTable(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
  if ( v18 < 0 )
    KeBugCheckEx(49, v18, 1, 0, 0);
  v19 = 0;
  MEMORY[0xFFFF923C] = 0;
  v20 = RtlStringCbPrintfA((int)v97, 0x100u, (int)"C:%s", a1[28]);
  if ( v20 < 0 )
    KeBugCheckEx(110, v20, 0, 0, 0);
  RtlInitAnsiString((unsigned int)&v84, (unsigned int)v97);
  *(_BYTE *)(--v84 + v85) = 0;
  dword_63282C = -28624;
  NtSystemRoot = 34078720;
  v21 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&NtSystemRoot, &v84, 0, 0);
  if ( v21 < 0 )
    KeBugCheckEx(110, v21, 1, 0, 0);
  v96[0] = 11;
  v96[1] = 1;
  v96[2] = 0;
  v87 = 0;
  v88 = 0;
  if ( LdrFindResource_U(0x400000, (int)v96, 3u, &v90) >= 0 )
  {
    v22 = LdrAccessResource(0x400000, (unsigned int)v90, (int)&v88, (int)&v87);
    v19 = v87;
    if ( v22 >= 0 )
      KiBugCodeMessages = v88;
  }
  MEMORY[0xFFFF9258] = CmGlobalValidationRunlevel;
  MEMORY[0xFFFF928B] = 1;
  v23 = CmNtSpBuildNumber & 0xFFF;
  CmNtSpBuildNumber = v23;
  HIWORD(CmNtCSDVersion) = 0;
  if ( CmNtCSDReleaseType )
    CmNtCSDVersion |= v23 << 16;
  if ( InitTickRolloverDelayLength == 4 && InitTickRolloverDelayType == 4 )
  {
    v24 = InitTickRolloverDelay;
  }
  else
  {
    v24 = 0;
    InitTickRolloverDelay = 0;
  }
  if ( v24 )
  {
    v54 = KeAdjustInterruptTime(-10000 * v24, (10000 * (unsigned __int64)(unsigned int)-v24) >> 32, 1);
    KeRebaselineSystemTime(v54, v55, v56, v57);
  }
  NtGlobalFlag |= CmNtGlobalFlag;
  MEMORY[0xFFFF93C0] = 1;
  __dmb(0xBu);
  MEMORY[0xFFFF93C4] = 1;
  MEMORY[0xFFFF936A] = 1;
  if ( !ExInitSystem() )
    KeBugCheck(49);
  KeNumaInitialize();
  v25 = VerifierInitSystem(a1);
  InitializeDynamicPartitioningPolicy(v25);
  if ( !MmInitSystem(0, a1) )
    KeBugCheck(49);
  KiHwPolicyDriverImageBase = 0;
  InbvDriverInitialize(0, a1);
  if ( KiBugCodeMessages )
  {
    v26 = ExAllocatePoolWithTag(512, v19, 1665296715);
    v27 = (void *)v26;
    if ( !v26 )
      KeBugCheck(125);
    memmove(v26, (int)KiBugCodeMessages, v19);
    KiBugCodeMessages = v27;
  }
  v28 = a1[4];
  v29 = 0;
  while ( (int *)v28 != a1 + 4 )
  {
    if ( v29 >= 3 )
    {
      v30 = *(__int16 **)(v28 + 40);
      if ( *v30 == 92 )
      {
        v33 = *(unsigned __int16 *)(v28 + 36) >> 1;
        if ( v33 + 1 <= 0x100 )
        {
          v32 = 0;
          do
          {
            v31 = *v30++;
            v97[v32++] = v31;
          }
          while ( v32 < v33 );
          if ( v32 >= 0x100 )
            _report_rangecheckfailure();
          v97[v32] = 0;
LABEL_41:
          RtlInitAnsiString((unsigned int)v93, (unsigned int)v97);
          DbgLoadImageSymbols((int)v93, *(_DWORD *)(v28 + 24));
          goto LABEL_42;
        }
      }
      else if ( ((unsigned __int16)NtSystemRoot >> 1) + (*(unsigned __int16 *)(v28 + 44) >> 1) + 17 <= 0x100u )
      {
        v83[0] = v28 + 44;
        v58 = RtlStringCbPrintfA((int)v97, 0x100u, (int)"%ws\\System32\\Drivers\\%wZ", -28620);
        if ( v58 < 0 )
          KeBugCheckEx(49, v58, 3, 0, 0);
        goto LABEL_41;
      }
    }
LABEL_42:
    v28 = *(_DWORD *)v28;
    ++v29;
  }
  if ( KdBreakAfterSymbolLoad )
    DbgBreakPointWithStatus();
  ExpInitializeBootEnvironment(a1);
  v35 = (_DWORD *)a1[33];
  if ( *v35 >= 0x908u )
  {
    v36 = v35[8];
    if ( v36 )
    {
      if ( *(_DWORD *)(v36 + 8) <= 4u || *(_BYTE *)v36 )
      {
        v59 = (_BYTE *)ExAllocatePoolWithTag(512, 96, 1936483400);
        v60 = (unsigned int)v59;
        if ( v59 )
        {
          memset(v59, 0, 96);
          v61 = *(_DWORD *)(v60 + 24);
          *(_DWORD *)v60 = 0;
          v62 = ((unsigned __int16)v61 ^ (unsigned __int16)(*(_WORD *)(v36 + 8) << 9)) & 0xE00 ^ *(_DWORD *)(v60 + 24);
          *(_DWORD *)(v60 + 24) = v62;
          *(_DWORD *)(v60 + 36) = *(_DWORD *)(v36 + 12);
          *(_DWORD *)(v60 + 28) = *(_DWORD *)(v36 + 4);
          v63 = v62 ^ ((unsigned __int8)v62 ^ (unsigned __int8)(*(_BYTE *)(v36 + 3) << 7)) & 0x80;
          *(_DWORD *)(v60 + 24) = v63;
          v64 = v63 ^ ((unsigned __int16)v63 ^ (unsigned __int16)(*(unsigned __int8 *)(v36 + 2) << 8)) & 0x100;
          *(_DWORD *)(v60 + 24) = v64;
          *(_DWORD *)(v60 + 24) = ((unsigned __int8)v64 ^ (unsigned __int8)(8 * *(_BYTE *)v36)) & 8 ^ v64;
          LOBYTE(v61) = *(_BYTE *)(v36 + 48);
          *(_BYTE *)(v60 + 81) = 0;
          *(_BYTE *)(v60 + 80) = v61;
          *(_BYTE *)(v60 + 52) = *(_BYTE *)(v36 + 49);
          *(_BYTE *)(v60 + 53) = *(_BYTE *)(v36 + 50);
          *(_BYTE *)(v60 + 54) = *(_BYTE *)(v36 + 51);
          v65 = *(_DWORD *)(v36 + 36);
          v66 = *(_DWORD *)(v36 + 40);
          v67 = *(_DWORD *)(v36 + 44);
          *(_DWORD *)(v60 + 64) = *(_DWORD *)(v36 + 32);
          *(_DWORD *)(v60 + 68) = v65;
          *(_DWORD *)(v60 + 72) = v66;
          *(_DWORD *)(v60 + 76) = v67;
          if ( *(_BYTE *)(v60 + 80) )
            *(_DWORD *)(v60 + 24) |= 0x1000u;
          *(_BYTE *)(v60 + 82) = 1;
          *(_BYTE *)(v60 + 83) = (*(_DWORD *)(v36 + 28) & 1) != 0;
          *(_WORD *)(v60 + 84) = *(_WORD *)(v36 + 18);
          *(_WORD *)(v60 + 86) = *(_WORD *)(v36 + 16);
          *(_WORD *)(v60 + 88) = *(_WORD *)(v36 + 22);
          *(_BYTE *)(v60 + 90) = *(_BYTE *)(v36 + 20);
          *(_BYTE *)(v60 + 91) = *(_BYTE *)(v36 + 24);
          *(_BYTE *)(v60 + 92) = *(_BYTE *)(v36 + 25);
          if ( *(unsigned __int16 *)(v36 + 16) != 0xFFFF )
          {
            if ( *(_WORD *)(v36 + 16) )
            {
              if ( *(unsigned __int16 *)(v36 + 18) != 0xFFFF )
              {
                if ( *(_WORD *)(v36 + 18) )
                {
                  *(_DWORD *)(v60 + 24) |= 0x1000u;
                  if ( (*(_DWORD *)(v36 + 28) & 1) == 0 )
                  {
                    memset(v95, 0, sizeof(v95));
                    HIBYTE(v95[4]) = *(_BYTE *)v36;
                    LOWORD(v95[3]) = *(_WORD *)(v36 + 16);
                    HIWORD(v95[2]) = *(_WORD *)(v36 + 18);
                    v95[0] = *(unsigned __int8 *)(v36 + 20);
                    LOWORD(v95[2]) = *(_WORD *)(v36 + 22);
                    v95[1] = *(_BYTE *)(v36 + 24) & 0x1F | (32 * (*(_BYTE *)(v36 + 25) & 7));
                    HIWORD(v95[3]) = -1;
                    LOBYTE(v95[4]) = -1;
                    off_6179A4(a1, v95);
                  }
                }
              }
            }
          }
          v68 = ExAllocatePoolWithTag(512, 14336, 1936483400);
          *(_DWORD *)(v60 + 8) = v68;
          if ( !v68 )
            goto LABEL_106;
          *(_WORD *)(v60 + 60) = -1;
          *(_WORD *)(v60 + 62) = -1;
          v69 = ExAllocatePoolWithTag(512, 80, 1936483400);
          *(_DWORD *)(v60 + 12) = v69;
          if ( !v69 )
            goto LABEL_106;
          v70 = ExAllocatePoolWithTag(512, 80, 1936483400);
          *(_DWORD *)(v60 + 16) = v70;
          if ( v70 && (v71 = MmLockPagableDataSection((unsigned int)HdlspDispatch), (*(_DWORD *)(v60 + 4) = v71) != 0) )
          {
            if ( *(_DWORD *)(v60 + 28) == 9600 )
            {
              *(_DWORD *)(v60 + 48) = 1301;
              *(_DWORD *)(v60 + 44) = -1;
              *(_DWORD *)(v60 + 40) = -13010;
            }
            HeadlessGlobals = v60;
            HdlspEnableTerminal(1);
          }
          else
          {
LABEL_106:
            v72 = *(_DWORD *)(v60 + 8);
            if ( v72 )
              ExFreePoolWithTag(v72);
            v73 = *(_DWORD *)(v60 + 12);
            if ( v73 )
              ExFreePoolWithTag(v73);
            v74 = *(_DWORD *)(v60 + 16);
            if ( v74 )
              ExFreePoolWithTag(v74);
            ExFreePoolWithTag(v60);
          }
        }
      }
    }
  }
  BootApplicationPersistentDataInitialize(a1);
  MEMORY[0xFFFF92B4] = MmHighestUserAddress;
  MEMORY[0xFFFF92B8] = MmSystemRangeStart;
  if ( CmNtCSDVersion )
  {
    v75 = RtlFindMessage(0x400000, 11, 0, 0x40000087u, &v91);
    if ( v75 < 0 )
      KeBugCheckEx(49, v75, 4, 0, 0);
    RtlInitAnsiString((unsigned int)&v84, v91 + 4);
    v84 -= 2;
    if ( (_BYTE)CmNtCSDVersion )
      v76 = (unsigned __int8)CmNtCSDVersion + 64;
    else
      v76 = 0;
    v83[1] = v76;
    v83[0] = BYTE1(CmNtCSDVersion);
    v77 = RtlStringCbPrintfA((int)v97, 0x100u, (int)"%Z %u%c", (int)&v84);
    if ( v77 < 0 )
      KeBugCheckEx(49, v77, 5, 0, 0);
    if ( (CmNtCSDVersion & 0xFFFF0000) != 0 )
    {
      v80 = RtlStringCbCatExA((int)v97, v78, v79, &v89, (int *)&v86);
      if ( v80 < 0 )
        KeBugCheckEx(49, v80, 6, 0, 0);
      v81 = RtlStringCbPrintfA(v89, v86, (int)"v.%u", HIWORD(CmNtCSDVersion));
      if ( v81 < 0 )
        KeBugCheckEx(49, v81, 7, 0, 0);
    }
  }
  else
  {
    v38 = RtlStringCbCopyExA(v97, v37, -27976, (int)&v86, &v86);
    if ( v38 < 0 )
      KeBugCheckEx(49, v38, 8, 0, 0);
    HIWORD(CmCSDVersionString) = 256 - v86;
  }
  RtlInitAnsiString((unsigned int)&v84, (unsigned int)v97);
  v40 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&CmCSDVersionString, &v84, 1, v39);
  if ( v40 < 0 )
    KeBugCheckEx(49, v40, 9, 0, 0);
  v83[0] = 3;
  v41 = RtlStringCbPrintfA((int)v98, 0x40u, (int)"%u.%u", 6);
  if ( v41 < 0 )
    KeBugCheckEx(49, v41, 10, 0, 0);
  v44 = RtlCreateUnicodeStringFromAsciiz((unsigned __int16 *)&CmVersionString, (unsigned int)v98, v42, v43);
  if ( !v44 )
    KeBugCheck(49);
  if ( (NtGlobalFlag & 0x2000) != 0 )
  {
    v44 = ExAllocatePoolWithTag(512, 0x800000, 1667331155);
    v82 = v44;
    if ( v44 )
    {
      if ( v83 == (int *)-56 || (v44 = RtlpInitializeStackTraceDatabase(v44, 0x800000, 0x800000u, (int)v94), v44 < 0) )
        v44 = ExFreePoolWithTag(v82);
    }
  }
  if ( (NtGlobalFlag & 0x800000) != 0 )
    RtlInitializeExceptionLog(v44, v45);
  off_92039C = &HandleTableListHead;
  HandleTableListHead = &HandleTableListHead;
  HandleTableListLock = 0;
  v46 = ObInitSystem();
  if ( !v46 )
    KeBugCheck(94);
  if ( !SeInitSystem(v46, v47) )
    KeBugCheck(95);
  v48 = PspInitPhase0();
  if ( !v48 )
    KeBugCheck(96);
  v50 = DbgkInitialize(v48, v49);
  if ( v50 < 0 )
    KeBugCheck(96);
  if ( !PpInitSystem(v50, v51) )
    KeBugCheck(143);
  ExpTickCountMultiplier = ExComputeTickCountMultiplier(KeMaximumIncrement);
  MEMORY[0xFFFF9004] = ExpTickCountMultiplier;
  result = 0;
  MEMORY[0xFFFF926C] = 10;
  MEMORY[0xFFFF9270] = 0;
  MEMORY[0xFFFF9260] = 10240;
  MEMORY[0xFFFF926A] = KeProcessorArchitecture;
  MEMORY[0xFFFF902C] = 452;
  MEMORY[0xFFFF902E] = 452;
  MEMORY[0xFFFF93A4] = 0;
  return result;
}
