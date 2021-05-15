// KeBugCheck2 
 
void __fastcall __noreturn KeBugCheck2(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6)
{
  int v6; // r8
  int v8; // r0
  unsigned int v9; // r0
  char v10; // r7
  int v11; // r3
  unsigned int v12; // r4
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r2
  int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r4
  unsigned int v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r1
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r6
  int v26; // r0
  int v27; // r5
  int v28; // r4
  int v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r2
  int v32; // r3
  int v33; // r0
  int v34; // r0
  int v35; // r1
  unsigned int v36; // r2
  int v37; // r3
  unsigned int v38; // r8
  int v39; // r3
  int v40; // r3
  int v41; // r6
  int v42; // r4
  int v43; // r3
  int v44; // r3
  int v45; // r3
  int v46; // r1
  unsigned int v47; // r4
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r0
  int *v52; // r0
  unsigned int v53; // r4
  unsigned int v54; // r2
  int v55; // r0
  char v56[4]; // [sp+18h] [bp-2B0h] BYREF
  int v57; // [sp+1Ch] [bp-2ACh] BYREF
  int v58; // [sp+20h] [bp-2A8h] BYREF
  int v59; // [sp+24h] [bp-2A4h]
  int v60; // [sp+28h] [bp-2A0h] BYREF
  unsigned int v61; // [sp+2Ch] [bp-29Ch]
  int v62; // [sp+30h] [bp-298h]
  unsigned int v63; // [sp+34h] [bp-294h] BYREF
  BOOL v64; // [sp+38h] [bp-290h]
  int v65; // [sp+3Ch] [bp-28Ch]
  BOOL v66; // [sp+40h] [bp-288h]
  int v67; // [sp+44h] [bp-284h]
  BOOL v68; // [sp+48h] [bp-280h]
  unsigned int v69; // [sp+4Ch] [bp-27Ch]
  unsigned int v70; // [sp+50h] [bp-278h] BYREF
  int v71; // [sp+54h] [bp-274h]
  int v72; // [sp+58h] [bp-270h]
  int v73; // [sp+5Ch] [bp-26Ch]
  int (*v74)(); // [sp+60h] [bp-268h]
  int v75; // [sp+68h] [bp-260h]
  int v76; // [sp+6Ch] [bp-25Ch]
  int v77; // [sp+70h] [bp-258h]
  int v78; // [sp+74h] [bp-254h]
  _DWORD v79[2]; // [sp+78h] [bp-250h] BYREF
  int v80; // [sp+80h] [bp-248h]
  char v81[416]; // [sp+88h] [bp-240h] BYREF
  char v82[160]; // [sp+228h] [bp-A0h] BYREF

  v6 = a4;
  v61 = a4;
  v62 = a1;
  v60 = a6;
  v69 = a3;
  IoInitializeBugCheckProgress(a1, a2);
  v8 = IoSaveBugCheckProgress(1);
  v59 = 0;
  v72 = 0;
  v73 = 0;
  v71 = 0;
  v63 = 0;
  v82[0] = 0;
  v67 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v64 = IopAutoReboot != 0;
  v74 = KiBugCheckProgress;
  v66 = 1;
  v68 = 1;
  v65 = 0;
  v9 = KeGetCurrentIrql(v8);
  v10 = v9;
  if ( v9 < 2 )
    KfRaiseIrql(2);
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x20);
  if ( v11 )
  {
    v26 = KeQueryCurrentStackInformation(&v58, (unsigned int *)&v57, &v70, v11);
    v27 = (v69 & 0xF0 | 3) & 0xF | (16 * *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594));
    v28 = KiBugCheckActive;
    while ( (v28 & 3) != 3 )
    {
      v29 = v28;
      __dmb(0xBu);
      do
        v30 = __ldrex((unsigned int *)&KiBugCheckActive);
      while ( v30 == v28 && __strex(v27, (unsigned int *)&KiBugCheckActive) );
      v28 = v30;
      __dmb(0xBu);
      v6 = v61;
      if ( v30 == v29 )
      {
        if ( v26 && v58 && v58 != 5 )
        {
          v31 = 12288;
          if ( v70 - v57 <= 0x3000 )
            v31 = v70 - v57;
          memmove((int)&KiPreBugcheckStackSaveArea, v57, v31);
        }
        v57 = 1;
LABEL_12:
        v17 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v18 = v17 + 1408;
        v19 = *(_DWORD *)(v17 + 1428);
        v61 = v18;
        *(_BYTE *)(v18 + 2329) = v10;
        v70 = v19;
        __dmb(0xBu);
        do
        {
          v20 = __ldrex((unsigned int *)&KiHardwareTrigger);
          v21 = v20 + 1;
        }
        while ( __strex(v21, (unsigned int *)&KiHardwareTrigger) );
        __dmb(0xBu);
        RtlCaptureContext(*(_DWORD **)(v18 + 1304), v21, (int)&KiHardwareTrigger, 0);
        KiSaveProcessorControlState((_DWORD *)(v18 + 32), v22, v23, v24);
        if ( !dword_61EC98 )
          goto LABEL_15;
        if ( PopSimulateHiberBugcheck )
          PoPowerDownActionInProgress = 0;
        if ( *(_BYTE *)(dword_61EC98 + 4) )
        {
          DbgPrintEx(
            101,
            0,
            (int)"\n"
                 "A bugcheck occurred during the late stages of hibernate suspend or resume.\n"
                 "Due to verification temporarily enabled by Po during this time,\n"
                 "regular bugcheck processing may not work.\n"
                 "\n",
            *(unsigned __int8 *)(dword_61EC98 + 4));
          v25 = v62;
          if ( v62 == 10 )
            DbgPrintEx(
              101,
              0,
              (int)"Memory was accessed during this time that was not properly marked\n"
                   "for the boot phase of hibernate! Check the callstack and parameters\n"
                   "to find the pages that need to be marked.\n"
                   "\n",
              v32);
          v58 = 1;
          v74 = 0;
        }
        else
        {
LABEL_15:
          v25 = v62;
          v58 = 0;
        }
        memmove((int)v81, *(_DWORD *)(v18 + 1304), 0x1A0u);
        if ( v57 )
        {
          ((void (__cdecl *)())off_617B0C)();
          IoSaveBugCheckProgress(96);
          ((void (__cdecl *)())off_6179F4)();
          if ( ViVerifierEnabled )
            v33 = VfNotifyVerifierOfEvent(2);
          if ( !v58 )
            KiSaveCurrentEtwTraceBuffer(v33);
          v34 = IoAddTriageDumpDataBlock((int)&KseEngine, 52);
          if ( v25 == 229 )
          {
            KiScanBugCheckCallbackList(v34);
            off_617AFC(0);
            HalReturnToFirmware(3);
          }
          if ( v25 == -1073741103 )
          {
            v25 = 195;
            v62 = 195;
          }
          v36 = v69;
          KiBugCheckData = v25;
          dword_624904 = a2;
          dword_624908 = v69;
          dword_62490C = v6;
          dword_624910 = a5;
          if ( v25 <= 0xCB )
          {
            if ( v25 == 203 )
            {
              v38 = a2;
              v63 = a2;
              goto LABEL_121;
            }
            if ( v25 != 10 )
            {
              if ( v25 == 76 )
              {
                v35 = 1;
                v72 = v6;
                v73 = 1;
                KiBugCheckData = a2;
                v44 = *(_DWORD *)v69;
                v59 = 1;
                v71 = a5;
                dword_624904 = v44;
                dword_624908 = *(_DWORD *)(v69 + 4);
                dword_62490C = *(_DWORD *)(v69 + 8);
                dword_624910 = *(_DWORD *)(v69 + 12);
                goto LABEL_120;
              }
              if ( v25 != 80 )
              {
                if ( v25 == 123 )
                {
                  v66 = (v6 & 1) == 0;
                  v68 = (v6 & 2) == 0;
                }
                else if ( v25 == 142 || v25 == 190 )
                {
LABEL_54:
                  v37 = v60;
                  if ( v60 )
                    goto LABEL_58;
                  if ( v6 && (v6 & 3) == 0 )
                  {
                    v37 = v6;
LABEL_58:
                    if ( v25 != 142 )
                    {
                      v38 = *(_DWORD *)(v37 + 128);
                      v63 = v38;
                      if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
                      {
                        v34 = MmIsSessionAddress(v38);
                        if ( v34 )
                        {
                          v39 = __mrc(15, 0, 13, 0, 3);
                          goto LABEL_62;
                        }
                      }
                      goto LABEL_121;
                    }
                  }
                }
                goto LABEL_120;
              }
              v40 = v60;
              v41 = 0;
              if ( v60 )
              {
LABEL_69:
                v38 = *(_DWORD *)(v40 + 128);
                v63 = v38;
                dword_62490C = v38;
                v41 = KiPcToFileHeader(v38, &v60, 0, v56);
                if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
                {
                  if ( MmIsSessionAddress(v38) )
                  {
                    v36 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
                    if ( v36 != PsInitialSystemProcess )
                      v59 = 1;
                  }
                }
                v42 = (unsigned __int8)v56[0];
              }
              else
              {
                if ( v6 && (v6 & 3) == 0 )
                {
                  v40 = v6;
                  goto LABEL_69;
                }
                v42 = 1;
                v38 = 0;
              }
              v34 = MmIsSpecialPoolAddress(a2, v35, v36);
              if ( v34 == 1 )
              {
                if ( (a2 & 0x1000) != 0 )
                {
                  if ( v42 == 1 )
                    v43 = 205;
                  else
                    v43 = 214;
                }
                else if ( v42 == 1 )
                {
                  v43 = 204;
                }
                else
                {
                  v43 = 213;
                }
                goto LABEL_91;
              }
              if ( v38 == a2 )
              {
                v34 = MmIsSessionAddress(a2);
                if ( v34 == 1 )
                {
                  v36 = *(_DWORD *)(v67 + 156);
                  if ( !v36 || v36 >= MmSystemRangeStart )
                  {
                    v43 = 207;
LABEL_91:
                    KiBugCheckData = v43;
                    goto LABEL_121;
                  }
                }
              }
              if ( v41 )
                goto LABEL_121;
              v34 = MmLocateUnloadedDriver(a2);
              KiBugCheckDriver = v34;
              if ( v34 )
              {
                v43 = 206;
                goto LABEL_91;
              }
LABEL_123:
              if ( v38 )
                v34 = KiDumpParameterImages(v82, &v63, 1, KeBugCheckUnicodeToAnsi);
              goto LABEL_125;
            }
            if ( a5 >= ExPoolCodeStart && a5 < ExPoolCodeEnd )
            {
              v45 = 197;
              goto LABEL_102;
            }
            v34 = KiPcToFileHeader(a5, &v60, 0, v56);
            if ( v56[0] == 1 )
            {
              v34 = KiPcToFileHeader(a2, &v60, 1, v56);
              if ( v34 )
              {
                KiBugCheckDriver = v60 + 44;
                v45 = 211;
                goto LABEL_102;
              }
              v34 = MmLocateUnloadedDriver(a2);
              KiBugCheckDriver = v34;
              if ( v34 )
              {
                v45 = 212;
                goto LABEL_102;
              }
            }
            else
            {
              v45 = 209;
LABEL_102:
              KiBugCheckData = v45;
            }
            v38 = 0;
            v63 = 0;
            goto LABEL_121;
          }
          switch ( v25 )
          {
            case 0xD8u:
              KiBugCheckDriver = a2 + 44;
              goto LABEL_120;
            case 0xEAu:
              KiBugCheckDriver = v6;
              goto LABEL_120;
            case 0xEFu:
              v59 = 1;
              goto LABEL_120;
            case 0xFCu:
              goto LABEL_54;
            case 0x13Du:
              v65 = 8;
              goto LABEL_120;
          }
          if ( v25 != 335 )
          {
LABEL_120:
            v38 = 0;
            goto LABEL_121;
          }
          if ( v69 < 0x100 && a5 && *(_DWORD *)(a5 + 4) )
            v67 = *(_DWORD *)(a5 + 4);
          v39 = __mrc(15, 0, 13, 0, 3);
          v38 = 0;
LABEL_62:
          v36 = *(_DWORD *)((v39 & 0xFFFFFFC0) + 0x74);
          if ( v36 != PsInitialSystemProcess )
          {
            v36 = 1;
            v59 = 1;
          }
LABEL_121:
          if ( !KiBugCheckDriver )
            goto LABEL_123;
          v34 = KeBugCheckUnicodeToAnsi(KiBugCheckDriver, v82, 128);
LABEL_125:
          if ( !KdPitchDebugger )
          {
            dword_60E368 = (int)v81;
            dword_60E36C = 0;
          }
          v25 = v62;
          if ( v62 != 226
            && (KdDebuggerEnabled || KdEventLoggingEnabled)
            && !KiHypervisorInitiatedCrashDump
            && (!KdRefreshDebuggerNotPresent(
                   v34,
                   v35,
                   v36,
                   (const char *)(unsigned __int8)KiHypervisorInitiatedCrashDump)
             || KdEventLoggingPresent) )
          {
            DbgPrintEx(
              101,
              0,
              (int)"\n*** Fatal System Error: 0x%08lx\n                       (0x%p,0x%p,0x%p,0x%p)\n\n",
              KiBugCheckData);
            if ( KiBugCheckDriver )
              DbgPrintEx(101, 0, (int)"Driver at fault: %s.\n", (int)v82);
            if ( v73 )
            {
              if ( v72 )
                DbgPrintEx(101, 0, v72, v72);
              if ( v71 )
                DbgPrintEx(101, 0, v71, v71);
            }
            if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
              KiBugCheckDebugBreak(3);
          }
        }
        __disable_irq();
        KfRaiseIrql(15);
        if ( v57 )
        {
          if ( (unsigned int)KeNumberProcessors_0 <= 1 || KiHypervisorInitiatedCrashDump )
          {
            v47 = v61;
          }
          else
          {
            KiSetDebuggerOwner(v61);
            v79[0] = *(_DWORD *)&KeActiveProcessors;
            v79[1] = dword_681D74;
            v80 = dword_681D78[0];
            v47 = v61;
            v80 = dword_681D78[0] & ~(1 << *(_DWORD *)(v61 + 20));
            KiSendFreeze((int)v79, 0);
            KeStallExecutionProcessor(1000000);
            KiSetSafeToPowerDownFrozenProcessors(1, v48, v49);
          }
          if ( !v58 )
          {
            if ( CrashdmpDumpBlock && v68 )
              v50 = v65;
            else
              v50 = v65 | 4;
            if ( !v64 )
              v50 |= 2u;
            if ( !v66 )
              v50 |= 1u;
            v51 = KiDisplayBlueScreen(v50);
            KiInvokeBugCheckEntryCallbacks(v51);
            IoSaveBugCheckProgress(2);
          }
          if ( !KdDebuggerEnabled && !KdPitchDebugger )
            KdEnableDebuggerWithLock(0, v46);
          v52 = (int *)memmove(*(_DWORD *)(v47 + 1304), (int)v81, 0x1A0u);
          if ( v68 )
          {
            if ( v25 == 265 )
              v52 = KiMarkBugCheckRegions(dword_624904, dword_624908, dword_62490C, dword_624910);
            if ( KdpDataBlockEncoded )
            {
              v52 = (int *)KdCopyDataBlock((int)&KdDebuggerDataBlock);
              KdpDataBlockEncoded = 0;
            }
            KiMarkTrapFrameLog(v52);
            if ( v25 == 239 )
              PopInternalAddToDumpFile(0, 0, 0);
            IoWriteCrashDump(
              KiBugCheckData,
              dword_624904,
              dword_624908,
              dword_62490C,
              dword_624910,
              (int)v81,
              v67,
              (int)v74,
              v59);
            v52 = (int *)IoSaveBugCheckProgress(3);
          }
        }
        else
        {
          if ( v70 != (unsigned int)KiBugCheckActive >> 4 )
          {
            while ( 1 )
              KiPollFreezeExecution();
          }
          if ( KiHypervisorInitiatedCrashDump || (v53 = ((unsigned int)KiBugCheckActive >> 2) & 3, v53 >= 2) )
            ((void (__cdecl *)())off_617994)();
          v52 = (int *)IoSaveBugCheckProgress(5);
          __dmb(0xBu);
          do
            v54 = __ldrex((unsigned int *)&KiBugCheckActive);
          while ( __strex(v54 + 4, (unsigned int *)&KiBugCheckActive) );
          __dmb(0xBu);
          if ( v53 )
            KiBugCheckDebugBreak(4);
        }
        if ( !v58 )
          KiScanBugCheckCallbackList(v52);
        ((void (__cdecl *)())off_617B04)();
        IoSaveBugCheckProgress(4);
        if ( v64 )
        {
          if ( !KiHypervisorInitiatedCrashDump )
          {
            v75 = -1;
            v76 = 0;
            v77 = 0;
            v78 = 0;
            DebugService2();
          }
          off_617AFC(0);
          if ( PoPowerDownActionInProgress || !v66 )
            v55 = 1;
          else
            v55 = 3;
          HalReturnToFirmware(v55);
        }
        KiBugCheckDebugBreak(4);
      }
    }
LABEL_10:
    v16 = 0;
  }
  else
  {
    v12 = (v69 & 0xFFFFFFF0 | 3) & 0xF | (16 * *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594));
    v13 = KiBugCheckActive;
    do
    {
      if ( (v13 & 3) == 3 )
        goto LABEL_10;
      v14 = v13;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&KiBugCheckActive);
      while ( v15 == v13 && __strex(v12, (unsigned int *)&KiBugCheckActive) );
      v13 = v15;
      __dmb(0xBu);
    }
    while ( v15 != v14 );
    v16 = 1;
  }
  v57 = v16;
  goto LABEL_12;
}
