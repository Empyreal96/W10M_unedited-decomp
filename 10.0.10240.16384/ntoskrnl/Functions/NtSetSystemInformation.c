// NtSetSystemInformation 
 
int __fastcall NtSetSystemInformation(int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v5; // r8
  int v6; // r1
  int v7; // r3
  int v8; // r9
  unsigned int v9; // r2
  int v10; // r6
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r1
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r4
  int v22; // r5
  int v23; // r0
  int v24; // r3
  int v25; // r4
  int v26; // r6
  unsigned int v27; // r0
  unsigned int v28; // r1
  int v29; // r2
  const __int16 *v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r0
  void **v34; // r1
  int v35; // t1
  int v36; // r3
  int v37; // r0
  int v38; // r0
  unsigned int v39; // r0
  int v40; // r4
  __int16 *v41; // r2
  int v42; // r3
  int v43; // r3
  int v44; // r4
  int v45; // r3
  void (__cdecl *v46)(); // r3
  int v47; // r0
  const __int16 *v48; // lr
  unsigned int v49; // r1
  unsigned int v50; // r0
  const __int16 *v51; // r1
  int v52; // r2
  int v53; // r3
  _DWORD *v54; // r8
  int v55; // r3
  unsigned int v56; // r2
  int v57; // r0
  int v58; // r4
  unsigned int v59; // r2
  unsigned int v60; // r1
  int v61; // r0
  unsigned int v62; // r1
  int v63; // r3
  unsigned int *v64; // r2
  unsigned int v65; // r1
  unsigned int v66; // r4
  int v67; // r10
  int v68; // r8
  char v70; // [sp+8h] [bp-98h] BYREF
  char v71[3]; // [sp+9h] [bp-97h] BYREF
  int v72; // [sp+Ch] [bp-94h]
  int v74[2]; // [sp+18h] [bp-88h] BYREF
  int v75; // [sp+20h] [bp-80h] BYREF
  __int16 *v76; // [sp+24h] [bp-7Ch]
  int v77; // [sp+28h] [bp-78h]
  int v78; // [sp+2Ch] [bp-74h]
  _DWORD v79[2]; // [sp+30h] [bp-70h] BYREF
  int v80; // [sp+38h] [bp-68h] BYREF
  int v81; // [sp+3Ch] [bp-64h]
  int v82; // [sp+40h] [bp-60h]
  int v83; // [sp+44h] [bp-5Ch]
  int v84; // [sp+48h] [bp-58h]
  unsigned int v85; // [sp+4Ch] [bp-54h]
  unsigned int v86; // [sp+50h] [bp-50h]
  int v87; // [sp+54h] [bp-4Ch]
  int v88; // [sp+60h] [bp-40h]
  int v89; // [sp+64h] [bp-3Ch]
  int v90; // [sp+68h] [bp-38h] BYREF
  const __int16 *v91; // [sp+6Ch] [bp-34h]
  int v92; // [sp+70h] [bp-30h] BYREF
  int v93; // [sp+74h] [bp-2Ch]
  _DWORD _78[14]; // [sp+78h] [bp-28h] BYREF
  unsigned int varg_r2; // [sp+B0h] [bp+10h]
  int varg_r3; // [sp+B4h] [bp+14h]

  _78[13] = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v5 = a2;
  v6 = a1;
  v75 = a1;
  _78[12] = a1;
  v74[0] = v5;
  v90 = 1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v70 = *(_BYTE *)(v7 + 346);
  v8 = v70;
  if ( v70 )
  {
    v7 = a1 == 89 ? 2 : 4;
    if ( a3 )
    {
      if ( ((v7 - 1) & v5) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v9 = v5 + a3;
      v7 = MmUserProbeAddress;
      if ( v5 + a3 > MmUserProbeAddress || v9 < v5 )
      {
        v7 = MmUserProbeAddress;
        *(_BYTE *)MmUserProbeAddress = 0;
      }
    }
  }
  v10 = 0;
  v79[0] = 0;
  v11 = a1 - 9;
  switch ( v6 )
  {
    case 9:
      if ( a3 != 4 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      NtGlobalFlag = *(_DWORD *)v5 ^ (*(_DWORD *)v5 ^ NtGlobalFlag) & 0x6DCE640F;
      *(_DWORD *)v5 = NtGlobalFlag;
      return v10;
    case 21:
    case 81:
      if ( a3 < 0x24 )
        return -1073741820;
      if ( v6 == 21 )
      {
        v25 = 0;
        v81 = 0;
        v26 = v75;
      }
      else
      {
        v81 = *(_DWORD *)(v5 + 32);
        v25 = v81;
        v26 = v75;
        if ( (v81 & 0xFFFFFFF0) != 0 || (v81 & 0xC) == 12 || (v81 & 3) == 3 )
          return -1073741584;
      }
      if ( !SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      v27 = *(_DWORD *)(v5 + 12);
      v85 = v27;
      v28 = *(_DWORD *)(v5 + 16);
      v86 = v28;
      v29 = 2;
      if ( v26 == 119 )
      {
        v29 = 3;
      }
      else if ( v26 == 120 )
      {
        v29 = 4;
      }
      v17 = MmAdjustWorkingSetSizeEx(v27, v28, v29, 1, v25, &v70);
      goto LABEL_64;
    case 24:
      if ( a3 != 20 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, v8, (int)&SeLoadDriverPrivilege) )
        return -1073741727;
      v30 = *(const __int16 **)(v5 + 4);
      v31 = *(_DWORD *)(v5 + 8);
      v32 = *(_DWORD *)(v5 + 12);
      v90 = *(_DWORD *)v5;
      v91 = v30;
      v92 = v31;
      v93 = v32;
      _78[0] = *(_DWORD *)(v5 + 16);
      KiMaximumDpcQueueDepth = (int)v30;
      KiMinimumDpcRate = v31;
      KiAdjustDpcThreshold = v32;
      KiIdealDpcRate = _78[0];
      KeSynchronizeWithDynamicProcessors();
      v33 = KeNumberProcessors_0;
      if ( KeNumberProcessors_0 )
      {
        v34 = &KiProcessorBlock;
        do
        {
          v35 = (int)*v34++;
          *(_DWORD *)(v35 + 1736) = KiMaximumDpcQueueDepth;
          *(_DWORD *)(v35 + 1744) = KiMinimumDpcRate;
          --v33;
        }
        while ( v33 );
      }
      return v10;
    case 26:
      goto LABEL_76;
    case 27:
      if ( a3 != 4 )
        return -1073741820;
      if ( v8 )
        return -1073741727;
      v87 = *(_DWORD *)v5;
      ((void (*)(void))MmUnloadSystemImage)();
      return 0;
    case 28:
      if ( a3 != 8 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeSystemtimePrivilege, dword_9229E4, v8, (int)&SeSystemtimePrivilege) )
        return -1073741727;
      v71[0] = *(_BYTE *)(v5 + 4);
      v13 = *(_DWORD *)v5;
      v80 = *(_DWORD *)v5;
      if ( v71[0] )
      {
        v80 = KeMaximumIncrement;
LABEL_26:
        ExAcquireTimeRefreshLock(1);
        v10 = ExpUpdateTimerConfiguration(0, (int)&v80, (int)v71);
        ExReleaseTimeRefreshLock();
        return v10;
      }
      if ( v13 && v13 < (unsigned int)dword_989680 )
        goto LABEL_26;
      return -1073741584;
    case 30:
      return MmCreateMirror();
    case 31:
      return EtwSetPerformanceTraceInformation(v5, a3, v8);
    case 34:
      if ( v8 )
      {
        v11 = SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege);
        if ( !v11 )
          return -1073741727;
      }
      if ( a3 != 4 )
        goto LABEL_119;
      if ( v8 )
      {
        if ( (v5 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v11);
        if ( v5 + 4 > MmUserProbeAddress || v5 + 4 < v5 )
          *(_BYTE *)MmUserProbeAddress = 0;
        v36 = *(_DWORD *)v5;
        v83 = *(_DWORD *)v5;
      }
      else
      {
        v36 = *(_DWORD *)v5;
      }
      if ( v36 )
      {
        if ( v36 != 1 )
        {
          if ( v36 != 2 )
            return -1073741811;
          return WheaCrashDumpInitializationComplete();
        }
LABEL_119:
        v37 = 1;
      }
      else
      {
        v37 = 0;
      }
      return IoConfigureCrashDump(v37, 0);
    case 37:
      if ( a3 != 12 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      return CmSetRegistryQuotaInformation(v5);
    case 38:
      if ( a3 != 8 )
        return -1073741820;
      if ( v8 )
      {
        if ( (*(_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 605) & 1) == 0
          || !SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, 1, (int)&SeLoadDriverPrivilege) )
        {
          return -1073741727;
        }
        if ( v5 >= MmUserProbeAddress )
          v5 = MmUserProbeAddress;
        v75 = *(_DWORD *)v5;
        v76 = *(__int16 **)(v5 + 4);
        if ( (unsigned __int16)v75 == 62 )
        {
          if ( !memcmp((unsigned int)v76, (unsigned int)Win32kFullPath, 62) )
          {
            v76 = Win32kFullPath;
            HIWORD(v75) = 62;
            v17 = ZwSetSystemInformation();
LABEL_64:
            v12 = v17;
          }
          else
          {
            v12 = -1073741727;
            v72 = -1073741727;
          }
        }
        else
        {
          v12 = -1073741727;
          v72 = -1073741727;
        }
        return v12;
      }
      v75 = *(_DWORD *)v5;
      v76 = *(__int16 **)(v5 + 4);
      v18 = MmLoadSystemImage((int)&v75, 0);
      v12 = v18;
      if ( v18 < 0 )
      {
        if ( v18 == -1073741411 )
          v12 = -1073741554;
        return v12;
      }
      v19 = RtlImageNtHeader(v74[0]);
      if ( !v19 )
      {
        MmUnloadSystemImage(v90);
        return -1073741701;
      }
      v10 = ExpInitializeSessionDriver(*(_DWORD *)(v19 + 40) + v74[0], v74[0]);
      if ( v10 < 0 )
        MmUnloadSystemImage(v90);
      return v10;
    case 39:
      if ( a3 != 4 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      v84 = *(_DWORD *)v5;
      PsChangeQuantumTable(1);
      return 0;
    case 40:
    case 41:
      if ( a3 != 8 )
        return -1073741820;
      if ( !v8 )
        goto LABEL_136;
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      v12 = VfProbeAndCaptureUnicodeString(&v90, v5, 1);
      if ( v12 < 0 )
        return v12;
      v5 = (unsigned int)&v90;
      if ( !(_WORD)v90 )
        return -1073741585;
      v6 = v75;
LABEL_136:
      if ( v6 == 40 )
      {
        v38 = VfAddVerifierEntry(v5);
      }
      else
      {
        if ( v6 != 41 )
        {
          v10 = -1073741821;
          goto LABEL_142;
        }
        v38 = VfRemoveVerifierEntry(v5);
      }
      v10 = v38;
LABEL_142:
      if ( !v8 )
        return v10;
      v39 = v5;
      goto LABEL_144;
    case 46:
      if ( a3 != 4 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeSystemtimePrivilege, dword_9229E4, v8, (int)&SeSystemtimePrivilege) )
        return -1073741727;
      v78 = *(_DWORD *)v5;
      if ( v78 )
      {
        v10 = ObReferenceObjectByHandle(v78, 2, ExEventObjectType, v8, &v90);
        v14 = v90;
        if ( v10 < 0 )
          return v10;
      }
      else
      {
        v14 = 0;
        v10 = 0;
      }
      KdUpdateTimeSlipEvent(v14);
      return v10;
    case 47:
    case 48:
    case 74:
      return -1073741822;
    case 51:
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      return VfSetVerifierInformation(v5, a3, 0);
    case 52:
      if ( v8 )
        return -1073741727;
      return MmAddVerifierThunks(v5, a3);
    case 54:
      v90 = 0;
LABEL_76:
      if ( a3 != 28 )
        return -1073741820;
      if ( v8 )
        return -1073741727;
      v79[0] = *(_DWORD *)v5;
      v79[1] = *(_DWORD *)(v5 + 4);
      v20 = MmLoadSystemImage((int)v79, 0);
      v10 = v20;
      if ( v20 < 0 )
      {
        if ( v20 == -1073741411 )
          v10 = -1073741554;
      }
      else
      {
        v21 = v90;
        v22 = RtlImageDirectoryEntryToData(v90, 1, 0, (int)&v75);
        v23 = RtlImageNtHeader(v21);
        *(_DWORD *)(v5 + 20) = v22;
        v24 = *(_DWORD *)(v23 + 40);
        *(_DWORD *)(v5 + 8) = v21;
        *(_DWORD *)(v5 + 12) = v74[0];
        *(_DWORD *)(v5 + 16) = v24 + v21;
        *(_DWORD *)(v5 + 24) = *(_DWORD *)(v23 + 80);
      }
      return v10;
    case 56:
      return PfSnSetPrefetcherInformation();
    case 59:
      if ( a3 != 4 )
        return -1073741820;
      v40 = *(_DWORD *)v5;
      v10 = ExpUpdateComPlusPackage(*(_DWORD *)v5);
      if ( v10 >= 0 )
        MEMORY[0xFFFF92E0] = v40;
      return v10;
    case 69:
    case 159:
      return -1073741637;
    case 71:
      return -1073741637;
    case 72:
      if ( v8 || !v5 || a3 != 8 )
        return -1073741811;
      v45 = *(_DWORD *)v5;
      if ( !*(_DWORD *)v5 )
        return -1073741637;
      switch ( v45 )
      {
        case 1:
          off_617B08(1);
          return 0;
        case 2:
          v46 = (void (__cdecl *)())off_617B0C;
          goto LABEL_179;
        case 3:
          v46 = (void (__cdecl *)())off_617B04;
LABEL_179:
          v46();
          return 0;
        case 4:
          return -1073741637;
      }
      if ( v45 != 6 )
      {
        if ( v45 != 7 )
          return -1073741811;
        if ( (char *)off_617B14 == (char *)xKdEnumerateDebuggingDevices )
          return -1073741822;
        return 0;
      }
      return off_617B14(1);
    case 75:
      return ExpRegisterFirmwareTableInformationHandler(v5, a3, v8);
    case 79:
      return PfSetSuperfetchInformation();
    case 80:
      return MmIssueMemoryListCommand(v5, a3, v8);
    case 82:
      if ( a3 < 0xC )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(SeIncreaseBasePriorityPrivilege, dword_9227C4, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      if ( v8 )
      {
        v41 = *(__int16 **)(v5 + 4);
        v42 = *(_DWORD *)(v5 + 8);
        v75 = *(_DWORD *)v5;
        v76 = v41;
        v77 = v42;
        v5 = (unsigned int)&v75;
      }
      v43 = *(_DWORD *)(v5 + 8);
      if ( v43 > 31 || v43 <= 0 )
        return -1073741811;
      v74[0] = *(_DWORD *)v5;
      v74[1] = *(_DWORD *)(v5 + 4);
      v10 = PsLookupProcessThreadByCid(v74, 0, &v90);
      if ( v10 >= 0 )
      {
        v44 = v90;
        if ( *(_BYTE *)(v90 + 4) )
        {
          v10 = -1073741749;
        }
        else
        {
          KeSetActualBasePriorityThread(v90, *(_DWORD *)(v5 + 8));
          v10 = 259;
        }
        ObfDereferenceObject(v44);
      }
      return v10;
    case 86:
      return ObSetRefTraceInformation(v5, a3);
    case 87:
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      if ( a3 != 8 )
        return -1073741820;
      v90 = *(_DWORD *)v5;
      v91 = *(const __int16 **)(v5 + 4);
      MmSpecialPoolTag = v90;
      MmSpecialPoolCatchOverruns = ((unsigned __int8)v91 & 1) != 0;
      return v10;
    case 89:
      if ( v8 != 1 )
        return -1073741637;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, 1, (int)&SeDebugPrivilege) )
        return -1073741727;
      return DbgkRegisterErrorPort(v5, a3);
    case 91:
      if ( v8 )
        return -1073741790;
      return -1073741637;
    case 92:
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      if ( a3 != 36 )
        return -1073741820;
      return VfSetVerifierInformationEx(v5);
    case 93:
      if ( a3 != 172 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeTimeZonePrivilege, dword_9229AC, v8, (int)&SeTimeZonePrivilege) )
        return -1073741727;
      v15 = 172;
      return ExpSetTimeZoneInformation(v5, v15);
    case 94:
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      if ( a3 != 8 )
        return -1073741820;
      v47 = *(_DWORD *)v5;
      v90 = *(_DWORD *)v5;
      v48 = *(const __int16 **)(v5 + 4);
      v91 = v48;
      __dmb(0xBu);
      do
        v49 = __ldrex((unsigned int *)0xFFFF93A0);
      while ( __strex(v49 | v47, (unsigned int *)0xFFFF93A0) );
      __dmb(0xBu);
      do
        v50 = __ldrex((unsigned int *)0xFFFF93A0);
      while ( __strex(v50 & ~(unsigned int)v48, (unsigned int *)0xFFFF93A0) );
LABEL_200:
      __dmb(0xBu);
      return v10;
    case 95:
      if ( !v8 || !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741790;
      if ( a3 < 0x14 )
        return -1073741820;
      return ExpCovResetInformation(v5, a3);
    case 97:
      if ( a3 != 24 )
        return -1073741820;
      if ( !v8 )
        goto LABEL_212;
      if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      v51 = *(const __int16 **)(v5 + 4);
      v52 = *(_DWORD *)(v5 + 8);
      v53 = *(_DWORD *)(v5 + 12);
      v90 = *(_DWORD *)v5;
      v91 = v51;
      v92 = v52;
      v93 = v53;
      v54 = (_DWORD *)(v5 + 16);
      v55 = v54[1];
      _78[0] = *v54;
      _78[1] = v55;
      v12 = VfProbeAndCaptureUnicodeStringBuffer(&v92, 1);
      if ( v12 < 0 )
        return v12;
      v12 = VfProbeAndCaptureUnicodeStringBuffer(_78, 1);
      if ( v12 < 0 )
      {
        VfFreeCapturedUnicodeString(&v92);
        return v12;
      }
      v5 = (unsigned int)&v90;
LABEL_212:
      v10 = VfFaultsSetParameters(v5);
      if ( v8 )
      {
        VfFreeCapturedUnicodeString(v5 + 8);
        v39 = v5 + 16;
LABEL_144:
        VfFreeCapturedUnicodeString(v39);
      }
      return v10;
    case 102:
      if ( a3 != 432 )
        return -1073741820;
      if ( v8 && !SeSinglePrivilegeCheck(SeTimeZonePrivilege, dword_9229AC, v8, (int)&SeTimeZonePrivilege) )
        return -1073741727;
      v15 = 432;
      return ExpSetTimeZoneInformation(v5, v15);
    case 106:
      return MmSetSystemVaInformation(v5, a3, v8);
    case 109:
      return SmSetStoreInformation();
    case 110:
    case 129:
      return -1073741822;
    case 111:
      if ( a3 != 4 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(
              SeProfileSingleProcessPrivilege,
              dword_922B94,
              v8,
              (int)&SeProfileSingleProcessPrivilege) )
        return -1073741790;
      MEMORY[0xFFFF9248] = *(_DWORD *)v5;
      return 0;
    case 113:
      return PsSetCpuQuotaInformation(v5, a3, v8, v7);
    case 127:
      if ( a3 != 8 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(
              SeProfileSingleProcessPrivilege,
              dword_922B94,
              v8,
              (int)&SeProfileSingleProcessPrivilege) )
        return -1073741727;
      v78 = *(_DWORD *)v5;
      v10 = MmScrubMemory();
      v79[0] = v10;
      *(_DWORD *)(v5 + 4) = v90;
      return v10;
    case 130:
      if ( a3 != 8 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(
              SeProfileSingleProcessPrivilege,
              dword_922B94,
              v8,
              (int)&SeProfileSingleProcessPrivilege) )
        return -1073741727;
      v78 = *(_DWORD *)v5;
      v10 = MmCombineIdenticalPages();
      v79[0] = v10;
      *(_DWORD *)(v5 + 4) = v90;
      return v10;
    case 131:
      if ( v8 )
        return -1073741790;
      if ( a3 != 12 )
        return -1073741820;
      return KeInitializeEntropySystem(*(_DWORD *)v5, *(_DWORD *)(v5 + 4), *(_DWORD *)(v5 + 8));
    case 132:
      if ( a3 != 4 )
        return -1073741820;
      v90 = 7733364;
      v91 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\condrv";
      if ( (*(_DWORD *)v5 & 1) != 0 )
      {
        v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v56 + 308);
        v57 = KeAbPreAcquire((unsigned int)&ExpConDrvLoadLock, 0, 0);
        v58 = v57;
        do
          v59 = __ldrex((unsigned __int8 *)&ExpConDrvLoadLock);
        while ( __strex(v59 | 1, (unsigned __int8 *)&ExpConDrvLoadLock) );
        __dmb(0xBu);
        if ( (v59 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&ExpConDrvLoadLock, v57, (unsigned int)&ExpConDrvLoadLock);
        if ( v58 )
          *(_BYTE *)(v58 + 14) |= 1u;
        v10 = ZwLoadDriver();
        __dmb(0xBu);
        do
          v60 = __ldrex((unsigned int *)&ExpConDrvLoadLock);
        while ( __strex(v60 - 1, (unsigned int *)&ExpConDrvLoadLock) );
        if ( (v60 & 2) != 0 && (v60 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&ExpConDrvLoadLock);
        v61 = KeAbPostRelease((unsigned int)&ExpConDrvLoadLock);
        v62 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v63 = (__int16)(*(_WORD *)(v62 + 0x134) + 1);
        *(_WORD *)(v62 + 308) = v63;
        if ( !v63 && *(_DWORD *)(v62 + 100) != v62 + 100 && !*(_WORD *)(v62 + 310) )
          KiCheckForKernelApcDelivery(v61);
        return v10;
      }
      if ( !SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, v8, (int)&SeLoadDriverPrivilege) )
        return -1073741727;
      return ZwUnloadDriver();
    case 134:
      if ( a3 != 20 )
        return -1073741820;
      return sub_6B4F20(v11, (int *)v5);
    case 150:
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      if ( a3 )
        return -1073741820;
      if ( !ExBootLoaderMetadata )
        return v10;
      __dmb(0xBu);
      v64 = (unsigned int *)ExBootLoaderMetadata;
      do
        v65 = __ldrex(v64);
      while ( __strex(0, v64) );
      goto LABEL_200;
    case 151:
      if ( !SeSinglePrivilegeCheck(19, 0, v8, v7) )
        return -1073741727;
      if ( a3 != 1 )
        return -1073741820;
      if ( *(_BYTE *)v5 && !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      return ExpCompleteSoftReboot();
    case 152:
      if ( a3 != 4 )
        return -1073741820;
      if ( !v8 )
        return -1073741811;
      v82 = 0;
      v82 = *(_DWORD *)v5;
      return ExpQueryElamCertInfo();
    case 155:
      return CmReconcileAndValidateAllHives();
    case 161:
      if ( v8 )
        return -1073741790;
      if ( a3 != 8 )
        return -1073741820;
      return KdInitialize_0();
    case 168:
      if ( (a3 & 7) != 0 || a3 > 8 )
        return -1073741820;
      memmove((int)&v90, v5, a3);
      v12 = ExCpuSetResourceManagerAccessCheck(v8);
      if ( v12 < 0 )
        return v12;
      return KeSetSystemAllowedCpuSets(a3 >> 3, &v90);
    case 170:
      if ( a3 != 16 )
        return -1073741820;
      if ( !SeSinglePrivilegeCheck(SeIncreaseBasePriorityPrivilege, dword_9227C4, v8, (int)&SeDebugPrivilege) )
        return -1073741727;
      v90 = *(_DWORD *)v5;
      v91 = *(const __int16 **)(v5 + 4);
      v92 = *(_DWORD *)(v5 + 8);
      v93 = *(_DWORD *)(v5 + 12);
      return KeIntSteerAssignCpuSetForGsiv(v90, (unsigned __int16)v91, v92);
    case 176:
      if ( a3 < 8 )
        return -1073741820;
      v66 = a3 - 8;
      varg_r2 = v66;
      if ( (v66 & 7) != 0 || v66 > 8 )
        return -1073741820;
      v67 = *(_DWORD *)v5;
      v90 = *(_DWORD *)(v5 + 4);
      v88 = v67;
      v89 = v90;
      memmove((int)v74, v5 + 8, v66);
      v68 = v90;
      v10 = ExCpuSetResourceManagerAccessCheck(v8);
      if ( v10 < 0 )
        return v10;
      return KeSetTagCpuSets(v66 >> 3, (int)v74, v67, v68);
    default:
      return -1073741821;
  }
}
