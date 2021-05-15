// NtPowerInformation 
 
int __fastcall NtPowerInformation(unsigned int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r8
  unsigned int v6; // r9
  int v7; // r5
  int *v9; // r10
  int v10; // r1
  int *v11; // r6
  int v12; // r2
  int v13; // r0
  int v14; // r1
  int v15; // r5
  unsigned int v16; // r10
  int v17; // r0
  int v18; // r1
  int v19; // r0
  int v20; // r4
  unsigned int v21; // r0
  int v22; // r8
  int *v23; // r2
  int v24; // r3
  unsigned int v25; // r9
  int v26; // r0
  int v27; // r0
  int v28; // lr
  _DWORD *v29; // r9
  int *v30; // r4
  int v31; // r1
  int v32; // r2
  int v33; // r3
  char *v34; // r0
  int v35; // r1
  int v36; // r0
  int v37; // r0
  int v38; // r0
  unsigned int v39; // r2
  unsigned int v40; // r4
  int v41; // r0
  unsigned int v42; // r2
  int v43; // r1
  int v44; // r3
  int v45; // r0
  int v46; // r0
  int *v47; // r0
  int v48; // r0
  int v49; // r0
  unsigned int *v50; // r9
  int *v51; // r0
  unsigned int v52; // r1
  int v53; // r0
  int v54; // r0
  int v55; // r0
  int v56; // r0
  int v57; // r0
  int v58; // r0
  int v59; // r0
  int v60; // r0
  int v61; // r1
  int v62; // r0
  int v63; // r3
  unsigned int v64; // r1
  int v65; // r0
  int v66; // r0
  int v67; // r3
  int v68; // r0
  int v69; // r0
  int v70; // r0
  int v72; // [sp+14h] [bp-374h]
  int v73; // [sp+18h] [bp-370h]
  int v74; // [sp+1Ch] [bp-36Ch]
  const __int16 *v75; // [sp+24h] [bp-364h] BYREF
  int v76; // [sp+28h] [bp-360h]
  char v77; // [sp+2Ch] [bp-35Ch]
  unsigned int v78; // [sp+30h] [bp-358h] BYREF
  unsigned int v79; // [sp+34h] [bp-354h]
  int v80; // [sp+38h] [bp-350h]
  char v81; // [sp+3Ch] [bp-34Ch]
  char v82[3]; // [sp+3Dh] [bp-34Bh] BYREF
  int *v83; // [sp+40h] [bp-348h]
  int v84; // [sp+44h] [bp-344h]
  int *v85; // [sp+48h] [bp-340h] BYREF
  _DWORD v86[2]; // [sp+50h] [bp-338h] BYREF
  int v87; // [sp+58h] [bp-330h]
  int v88; // [sp+5Ch] [bp-32Ch]
  _BYTE v89[8]; // [sp+60h] [bp-328h] BYREF
  int v90; // [sp+68h] [bp-320h] BYREF
  _DWORD _6C[203]; // [sp+6Ch] [bp-31Ch] BYREF
  int varg_r2; // [sp+398h] [bp+10h]
  int varg_r3; // [sp+39Ch] [bp+14h]

  _6C[202] = a2;
  varg_r3 = a4;
  v5 = a4;
  v6 = a3;
  varg_r2 = a3;
  v7 = a2;
  v83 = (int *)a2;
  _6C[201] = a1;
  v88 = a2;
  v86[0] = a4;
  v90 = 0;
  memset(_6C, 0, 764);
  v9 = 0;
  v75 = 0;
  v10 = 0;
  v76 = 0;
  v78 = 0;
  v11 = 0;
  v87 = 0;
  v74 = 0;
  v85 = 0;
  v73 = 0;
  v77 = 0;
  v72 = 0;
  if ( a1 > 0x59 )
  {
    v15 = -1073741811;
    goto LABEL_118;
  }
  v12 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v84 = v12;
  v81 = v12;
  if ( !v7 )
  {
    v6 = 0;
    varg_r2 = 0;
  }
  if ( !v6 )
  {
    v7 = 0;
    v83 = 0;
    v88 = 0;
  }
  if ( v5 )
    v13 = a5;
  else
    v13 = 0;
  v79 = v13;
  if ( !v13 )
  {
    v5 = 0;
    v86[0] = 0;
  }
  if ( !v12 )
  {
    v11 = (int *)v7;
    v87 = v7;
LABEL_120:
    if ( a1 != 29
      && a1 != 45
      && a1 != 44
      && a1 != 85
      && a1 != 43
      && a1 != 72
      && a1 != 73
      && a1 != 74
      && a1 != 38
      && a1 != 55
      && a1 != 48
      && a1 != 40
      && a1 != 47
      && a1 != 30
      && a1 != 31
      && a1 != 25
      && a1 != 10
      && a1 != 51
      && a1 != 89
      && a1 != 56
      && a1 != 59
      && a1 != 58
      && a1 != 61
      && a1 != 62
      && a1 != 57
      && a1 != 64
      && a1 != 66
      && a1 != 67
      && a1 != 28
      && a1 != 68
      && a1 != 71
      && a1 != 16
      && a1 != 75
      && a1 != 78
      && a1 != 77
      && a1 != 79
      && a1 != 83
      && a1 != 84
      && a1 != 5
      && a1 != 7
      && a1 != 11
      && a1 != 86
      && a1 != 87
      && a1 != 88
      && a1 != 41 )
    {
      v13 = PopAcquirePolicyLock();
      v10 = 1;
      v73 = 1;
      v77 = 1;
    }
    switch ( a1 )
    {
      case 0u:
      case 1u:
        if ( v11 )
        {
          if ( v6 < 0xE8 )
            goto LABEL_177;
          v15 = PopApplyPolicy(0, 0, v11, v6);
          if ( v15 < 0 )
            goto LABEL_174;
        }
        else if ( !v5 )
        {
          goto LABEL_173;
        }
        v9 = (int *)&unk_61EB24;
        goto LABEL_180;
      case 2u:
      case 3u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 < 0xE8 )
          goto LABEL_177;
        v15 = PopVerifySystemPowerPolicy(v11, &v90);
        if ( v15 < 0 )
          goto LABEL_174;
        v9 = &v90;
LABEL_180:
        v75 = (const __int16 *)v9;
        v25 = 232;
        goto LABEL_547;
      case 4u:
        if ( v11 )
        {
          if ( (PopSimulate & 1) == 0 )
            goto LABEL_173;
          if ( v6 < 0x4C )
          {
LABEL_177:
            v15 = -1073741789;
            goto LABEL_174;
          }
          v27 = memmove((int)&PopCapabilities, (int)v11, 0x4Cu);
          v15 = PopResetCurrentPolicies(v27);
          if ( v15 < 0 )
            goto LABEL_174;
        }
        else if ( !v5 )
        {
          goto LABEL_173;
        }
        byte_61EA49 = (PopFullWake & 1) != 0;
        byte_61EA55 = PopDisksRegisteredForIdle();
        PopFilterCapabilities(&PopCapabilities, &v90);
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 76;
        goto LABEL_547;
      case 5u:
        if ( v11 || !v5 )
          goto LABEL_173;
        PopCurrentPowerState(&v90);
        goto LABEL_214;
      case 6u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 0x10 )
          goto LABEL_177;
        v28 = *v11;
        if ( (unsigned int)*v11 >= 7 )
          goto LABEL_173;
        v29 = &PopPowerStateHandlers[4 * v28];
        if ( v29[2] )
        {
          if ( v28 != 4 || (void (__noreturn *)())dword_61EA08 != PopShutdownHandler )
            goto LABEL_173;
        }
        v30 = &PopPowerStateHandlers[4 * v28];
        v31 = v11[1];
        v32 = v11[2];
        v33 = v11[3];
        *v30 = *v11;
        v30[1] = v31;
        v30[2] = v32;
        v30[3] = v33;
        *((_BYTE *)v29 + 5) = 0;
        *((_BYTE *)v29 + 6) = 0;
        *((_BYTE *)v29 + 7) = 0;
        v34 = 0;
        v35 = 0;
        if ( v28 )
        {
          switch ( v28 )
          {
            case 1:
              if ( (PopSimulate & 0x40) == 0 )
                v34 = &byte_61EA44;
              v35 = 3;
              break;
            case 2:
              if ( (PopSimulate & 0x20) == 0 )
                v34 = &byte_61EA45;
LABEL_244:
              v35 = 4;
              break;
            case 3:
              if ( (PopSimulate & 0x2000) == 0 )
                v34 = &byte_61EA46;
              v35 = 5;
              break;
            case 4:
              v34 = &byte_61EA47;
              break;
            case 6:
              if ( (PopSimulate & 0x2000) == 0 )
                v34 = &byte_61EA51;
              goto LABEL_244;
            default:
              break;
          }
        }
        else
        {
          if ( (PopSimulate & 8) == 0 )
            v34 = &byte_61EA43;
          v35 = 2;
        }
        if ( !*((_BYTE *)v29 + 4) )
          v35 = 0;
        if ( v35 > dword_61EA80 )
          dword_61EA80 = v35;
        if ( v34 )
          PopChangeCapability(v34, 1, &PopCapabilities);
LABEL_169:
        v9 = 0;
        goto LABEL_170;
      case 7u:
        if ( v11 || !v5 )
          goto LABEL_173;
        v9 = (int *)L"*";
        v75 = L"*";
        v25 = 92;
        goto LABEL_547;
      case 8u:
        if ( v11 || !v5 )
          goto LABEL_173;
        v9 = (int *)PopPolicy;
        goto LABEL_180;
      case 9u:
        if ( v11 )
        {
          if ( v6 < 0x18 )
            goto LABEL_177;
          v26 = PopApplyAdminPolicy(v13, v11);
          v15 = v26;
          if ( v26 < 0 )
            goto LABEL_174;
          v15 = PopResetCurrentPolicies(v26);
          if ( v15 < 0 )
            goto LABEL_174;
        }
        else if ( !v5 )
        {
          goto LABEL_173;
        }
        v9 = &PopAdminPolicy;
        goto LABEL_189;
      case 0xAu:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( !v6 )
          goto LABEL_177;
        PopAcquireTransitionLock(v13);
        PopAcquirePolicyLock();
        v15 = PopEnableHiberFile(*(unsigned __int8 *)v11, 1);
        v36 = PopReleasePolicyLock();
        PopReleaseTransitionLock(v36);
        goto LABEL_267;
      case 0xBu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v39 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99C);
        goto LABEL_286;
      case 0xCu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v90 = 0;
        _6C[0] = dword_61E804;
        _6C[1] = dword_61E80C - dword_61E808;
        LOBYTE(_6C[2]) = PopCoolingMode;
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 16;
        goto LABEL_547;
      case 0xDu:
      case 0x12u:
      case 0x13u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x20u:
      case 0x21u:
      case 0x22u:
      case 0x31u:
      case 0x34u:
      case 0x35u:
      case 0x36u:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x52u:
        goto LABEL_181;
      case 0xEu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v9 = (int *)&unk_61ECA0;
        goto LABEL_275;
      case 0xFu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v9 = (int *)&unk_61ECA8;
        goto LABEL_275;
      case 0x10u:
        if ( v11 || !v5 )
          goto LABEL_173;
        if ( dword_60E1E8 )
        {
          v42 = v90 | 1;
          v90 |= 1u;
        }
        else
        {
          v42 = v90;
        }
        if ( PopPowerRequestAttributes[0] )
          v90 = v42 | 2;
        goto LABEL_316;
      case 0x11u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 8 )
          goto LABEL_177;
        v23 = &PopPowerStateNotifyHandler;
        if ( PopPowerStateNotifyHandler && *v11 )
          goto LABEL_173;
        PopPowerStateNotifyHandler = *v11;
        v24 = v11[1];
LABEL_168:
        v23[1] = v24;
        goto LABEL_169;
      case 0x17u:
        if ( v11 || !v5 )
          goto LABEL_173;
        v15 = PopLoggingInformation(&v85, v86);
        if ( v15 >= 0 )
        {
          v74 = (int)v85;
          v9 = v85;
          v75 = (const __int16 *)v85;
          v25 = v86[0];
          goto LABEL_547;
        }
        v21 = (unsigned int)v85;
        v9 = 0;
        v22 = v73;
        goto LABEL_558;
      case 0x18u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 8 )
          goto LABEL_177;
        v41 = PopLogSleepDisabled(*v11, v11[1], 0, 0);
        goto LABEL_302;
      case 0x19u:
        if ( !v11 )
          goto LABEL_173;
        if ( v5 )
          goto LABEL_173;
        if ( v79 )
          goto LABEL_173;
        if ( v6 < 0x1C )
          goto LABEL_173;
        v43 = v11[6];
        if ( !v43 )
          goto LABEL_173;
        v44 = v11[5];
        if ( v44 >= 3 || v44 < 0 )
          goto LABEL_173;
        if ( *v11 != 1 )
        {
          v15 = -1073741736;
          goto LABEL_174;
        }
        v45 = RtlULongAdd(0x1Cu, v43, &v78);
        v15 = v45;
        if ( v45 < 0 )
          goto LABEL_174;
        v76 = v78;
        if ( v6 < v78 )
          goto LABEL_173;
        v46 = PopGetSessionId(v45);
        v41 = PopSetPowerSettingValue(v11 + 1, v46, v11[5], v11[6], (int)(v11 + 7));
        goto LABEL_302;
      case 0x1Cu:
        PopSuspendResumePdc(1);
        PopHiberBootForceMonitorOff = 1;
        v69 = PoPowerOffMonitor();
        goto LABEL_471;
      case 0x1Du:
        if ( v11 || !v5 )
          goto LABEL_173;
        v25 = 4;
        v47 = (int *)ExAllocatePoolWithTag(1, 4, 544040269);
        v9 = v47;
        v75 = (const __int16 *)v47;
        if ( !v47 )
          goto LABEL_338;
        v72 = 1;
        *v47 = PopConsoleDisplayState;
        goto LABEL_547;
      case 0x1Eu:
      case 0x1Fu:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 4 )
          goto LABEL_177;
        if ( a1 == 30 )
          PopDiagTraceAppPowerMessage(v11);
        else
          PopDiagTraceAppPowerMessageEnd(v11);
        goto LABEL_169;
      case 0x23u:
        if ( v11 || !v5 )
          goto LABEL_173;
        if ( v10 )
        {
          PopReleasePolicyLock();
          v73 = 0;
          v77 = 0;
        }
        v78 = 0;
        v15 = PopGetWakeSource(0, &v78);
        if ( v15 == -1073741789 )
        {
          v48 = ExAllocatePoolWithTag(512, v78, 544040269);
          v9 = (int *)v48;
          v75 = (const __int16 *)v48;
          if ( !v48 )
          {
LABEL_338:
            v15 = -1073741670;
            goto LABEL_556;
          }
          v72 = 1;
          v15 = PopGetWakeSource(v48, &v78);
        }
        else
        {
          v9 = 0;
        }
        if ( v15 < 0 )
          goto LABEL_556;
        v25 = v78;
        goto LABEL_547;
      case 0x24u:
        if ( !v5 )
          goto LABEL_173;
        if ( !dword_61EEB4 || !dword_61EEB0 )
        {
          v15 = -1073741275;
          goto LABEL_174;
        }
        v76 = dword_61EEB4 + 8;
        v49 = ExAllocatePoolWithTag(1, dword_61EEB4 + 8, 544040269);
        v50 = (unsigned int *)v49;
        if ( !v49 )
        {
LABEL_360:
          v15 = -1073741670;
          goto LABEL_174;
        }
        v9 = (int *)v49;
        v75 = (const __int16 *)v49;
        v72 = 1;
        memmove(v49 + 8, dword_61EEB0, dword_61EEB4);
        *v50 = (unsigned int)dword_61EEB4 >> 4;
        goto LABEL_170;
      case 0x25u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v84 != 1 )
          goto LABEL_332;
        v15 = PopValidateServiceNotification(v11, v6);
        if ( v15 < 0 )
          goto LABEL_174;
        PopDiagTraceServiceNotification(v11);
        goto LABEL_169;
      case 0x26u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 == 6 )
        {
          v41 = PpmSetSimulatedLoad((int)v11);
          goto LABEL_302;
        }
        if ( v6 != 4 )
          goto LABEL_369;
        v41 = PpmClearSimulatedLoad((int)v11);
        goto LABEL_302;
      case 0x27u:
        if ( !v11 || v5 || v6 != 8 )
          goto LABEL_173;
        v51 = (int *)ExAllocatePoolWithTag(512, 8, 544040269);
        if ( !v51 )
          goto LABEL_360;
        *v51 = *v11;
        v51[1] = v11[1];
        __dmb(0xBu);
        do
          v52 = __ldrex((unsigned int *)&PopShutdownNotificationCallback);
        while ( !v52 && __strex((unsigned int)v51, (unsigned int *)&PopShutdownNotificationCallback) );
        __dmb(0xBu);
        if ( !v52 )
          goto LABEL_169;
        ExFreePoolWithTag((unsigned int)v51);
        goto LABEL_386;
      case 0x28u:
        if ( !v11 || v6 != 4 || v5 )
          goto LABEL_173;
        v86[0] = *v11 != 0;
        PopSetPowerSettingValueAcDc((int *)&GUID_VIDEO_BRIGHTNESS_CAPABLE, 4u, (int)v86);
        goto LABEL_169;
      case 0x29u:
        if ( v11 || !v5 || v79 != 48 )
          goto LABEL_173;
        LOBYTE(_6C[9]) = PopEsGetState(v13) == 1;
        v59 = PopAcquirePolicyLock();
        _6C[1] = 0;
        v90 = (int)&PopNoMoreInput;
        _6C[0] = &PopHiberBootForceMonitorOff;
        _6C[3] = byte_61EC11 != 0;
        _6C[4] = dword_61EC0C;
        _6C[2] = dword_61EC2C;
        _6C[5] = dword_61EC30;
        _6C[6] = dword_61EC34;
        _6C[7] = dword_61EC38;
        _6C[10] = dword_61EC3C;
        _6C[8] = dword_61EC40;
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 48;
        v60 = PopGetSessionId(v59);
        PopSessionCreated(v60);
        PopReleasePolicyLock();
        goto LABEL_547;
      case 0x2Au:
        if ( !v11 || v6 != 16 || v5 )
          goto LABEL_173;
        if ( *((_BYTE *)v11 + 13) && *((_BYTE *)v11 + 12) )
        {
          PopSetDisplayStatus(v11[1]);
          PopUpdateConsoleDisplayState(v11[1], v61);
        }
        if ( *((_BYTE *)v11 + 14) )
          PopDiagTraceSessionDisplayStateChange(v11[1] == 0, *v11, *((unsigned __int8 *)v11 + 12), v11[2]);
        goto LABEL_169;
      case 0x2Bu:
      case 0x48u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 != 28 || v79 != 4 )
          goto LABEL_177;
        v62 = PopPowerRequestCreateInfo(v11, a1 == 72, &v90);
        goto LABEL_431;
      case 0x2Cu:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 != 16 )
          goto LABEL_177;
        v41 = PopPowerRequestActionInfo(v11);
        goto LABEL_302;
      case 0x2Du:
        if ( v11 || !v5 )
          goto LABEL_173;
        v66 = PopGetPowerRequestListInfo(&v75, &v78);
        goto LABEL_443;
      case 0x2Eu:
        if ( !v11 )
          goto LABEL_173;
        if ( v6 < 2 )
          goto LABEL_173;
        if ( !v5 )
          goto LABEL_173;
        v40 = *(unsigned __int16 *)v11;
        if ( v40 >= KeQueryActiveGroupCount() )
          goto LABEL_173;
        v39 = v40;
LABEL_286:
        v15 = PopProcessorInformation(&v90, v10, v39, &v78);
        if ( v15 < 0 )
          goto LABEL_174;
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        goto LABEL_546;
      case 0x2Fu:
        if ( !v11 || v6 != 20 )
          goto LABEL_173;
        v68 = PopUmpoSendLegacyEvent(v11);
        v15 = v68;
        if ( v68 >= 0 )
          goto LABEL_169;
        v9 = 0;
        if ( v68 == -1073741536 )
          goto LABEL_170;
        goto LABEL_556;
      case 0x30u:
        if ( !KdDebuggerEnabled )
          goto LABEL_332;
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 == 12 )
        {
          v41 = PpmParkApplyForcedMask(v11);
          goto LABEL_302;
        }
        if ( v6 != 2 )
          goto LABEL_369;
        v41 = PpmParkClearForcedMask(v11);
        goto LABEL_302;
      case 0x32u:
        if ( v11 || !v5 )
          goto LABEL_173;
        v66 = ExGetWakeTimerList(&v75, (int)&v78);
LABEL_443:
        v15 = v66;
        if ( v66 >= 0 )
        {
          v67 = 1;
          goto LABEL_545;
        }
        v9 = (int *)v75;
        goto LABEL_556;
      case 0x33u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 < 4 )
          goto LABEL_177;
        PopAcquireTransitionLock(v13);
        PopAcquirePolicyLock();
        v37 = PopSetHiberFileSize(*v11, v89);
        goto LABEL_273;
      case 0x37u:
        if ( !KdDebuggerEnabled )
          goto LABEL_332;
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 == 8 )
        {
          v41 = PpmSetSimulatedIdle(v11);
        }
        else
        {
          if ( v6 != 4 )
          {
LABEL_369:
            v15 = -1073741811;
LABEL_267:
            v9 = 0;
            if ( v15 < 0 )
              goto LABEL_556;
LABEL_170:
            v25 = v76;
LABEL_547:
            if ( v9 && v5 )
            {
              if ( v79 < v25 )
              {
                v15 = -1073741789;
                goto LABEL_556;
              }
              memmove(v5, (int)v9, v25);
              v22 = v73;
            }
            else
            {
              v22 = v73;
            }
            v15 = 0;
            goto LABEL_557;
          }
          v41 = PpmClearSimulatedIdle((int)v11);
        }
LABEL_302:
        v15 = v41;
        goto LABEL_267;
      case 0x38u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 != 8 || v79 != 4 )
          goto LABEL_177;
        v62 = PpmParkSetLpiCap(*v11, v11[1], (unsigned int *)&v90);
LABEL_431:
        v15 = v62;
        if ( v62 >= 0 )
          goto LABEL_316;
        goto LABEL_174;
      case 0x39u:
        if ( !ExVerifySuite(16) )
        {
LABEL_181:
          v15 = -1073741822;
          goto LABEL_174;
        }
        if ( !v11 || v6 != 1 || v5 )
          goto LABEL_173;
        v15 = PopUserPresentOverride(*(unsigned __int8 *)v11);
        if ( v15 < 0 )
          goto LABEL_174;
        goto LABEL_169;
      case 0x3Au:
        if ( !v5 )
          goto LABEL_173;
        if ( v83 && v6 != 20 || v79 != 8 )
          goto LABEL_177;
        v69 = PopGetSettingNotificationName(v11, v5);
        goto LABEL_471;
      case 0x3Bu:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 != 16 || v79 < 4 )
          goto LABEL_177;
        v69 = PopGetSettingValue(v11, v5, v79);
        goto LABEL_471;
      case 0x3Cu:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 8 )
          goto LABEL_177;
        PopEnforceResiliencyScenarios((int)v11);
        goto LABEL_169;
      case 0x3Du:
        if ( !v11 || v6 != 8 || !v5 || v79 != 8 )
          goto LABEL_173;
        v54 = PopGetSessionId(v13);
        PopSessionInputChange(v54, (unsigned __int8 *)v11, v5);
        goto LABEL_169;
      case 0x3Eu:
        if ( !v11 || v6 != 2 || !v5 || v79 != 8 )
          goto LABEL_173;
        v55 = PopGetSessionId(v13);
        v56 = PopSessionConnectionChange(v55, v11, v5);
        v57 = PopGetSessionId(v56);
        PopSessionConnectionInvocation(v57, v11);
        goto LABEL_169;
      case 0x3Fu:
        if ( v11 || v5 )
          goto LABEL_173;
        v53 = PopGetSessionId(v13);
        PopSessionClosed(v53);
        goto LABEL_169;
      case 0x40u:
        if ( !v11 || v6 != 8 || v5 )
          goto LABEL_173;
        v58 = PopGetSessionId(v13);
        PopSessionWinlogonNotification(v58, v11);
        goto LABEL_169;
      case 0x41u:
        if ( v11 || !v5 )
          goto LABEL_173;
        PopFilterCapabilities(&PopCapabilities, &v90);
        if ( BYTE2(_6C[3]) )
          PopReadHiberbootPolicy((char *)&_6C[3] + 2);
        v9 = (_DWORD *)((char *)&_6C[3] + 2);
        goto LABEL_210;
      case 0x42u:
        if ( v11 || !v5 )
          goto LABEL_173;
        LOBYTE(v90) = PopPlatformAoAc;
        v9 = &v90;
LABEL_210:
        v75 = (const __int16 *)v9;
        v25 = 1;
        goto LABEL_547;
      case 0x43u:
        if ( !v11 || v6 != 56 || v5 && v79 != 80 )
          goto LABEL_173;
        v69 = PopPdcInvocation(v11, v5);
        goto LABEL_471;
      case 0x44u:
        if ( !v11 || v6 != 8 || v5 || v79 )
          goto LABEL_173;
        v69 = PopMonitorInvocation(v11);
        goto LABEL_471;
      case 0x45u:
        if ( v11 || v5 )
          goto LABEL_173;
        v15 = PopInitPlatformSettings(v13);
        byte_61EA54 = PopPlatformAoAc;
        goto LABEL_174;
      case 0x46u:
        KeQueryPerformanceCounter(v86, 0);
        v23 = &PopShutdownButtonPressTime;
        PopShutdownButtonPressTime = v86[0];
        v24 = v86[1];
        goto LABEL_168;
      case 0x47u:
        if ( !v11 || v6 != 8 || v5 && v79 )
          goto LABEL_173;
        v69 = PopSuspendResumeInvocation(v11);
        goto LABEL_471;
      case 0x49u:
      case 0x58u:
        if ( v11 || v5 )
          goto LABEL_173;
        if ( a1 == 88 )
          v70 = 23;
        else
          v70 = 11;
        v69 = PopPdcScreenOff(v70);
        goto LABEL_471;
      case 0x4Au:
        if ( v84 )
          goto LABEL_332;
        if ( !v11 || v6 != 12 || v5 || v79 )
          goto LABEL_173;
        v69 = PopPdcCsDeviceNotification(v11);
LABEL_471:
        v15 = v69;
        goto LABEL_174;
      case 0x4Bu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v90 = PopCapturePlatformRole(v13);
LABEL_316:
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 4;
        goto LABEL_547;
      case 0x4Cu:
        if ( v11 || !v5 )
          goto LABEL_173;
        v90 = dword_61EFE8;
        _6C[1] = dword_61F170;
        _6C[2] = dword_61F174;
        _6C[3] = dword_61F178;
        _6C[4] = dword_61F17C;
        if ( !PopSleepStats )
        {
LABEL_386:
          v15 = -1073741823;
          goto LABEL_174;
        }
        v9 = &v90;
LABEL_189:
        v75 = (const __int16 *)v9;
        v25 = 24;
        goto LABEL_547;
      case 0x4Du:
        if ( v11 || v5 )
          goto LABEL_173;
        PopDispatchCallout(12);
        goto LABEL_169;
      case 0x4Eu:
        if ( v84 != 1 )
        {
LABEL_332:
          v15 = -1073741790;
          goto LABEL_174;
        }
        if ( v5 || v79 )
          goto LABEL_173;
        if ( v11 )
        {
          if ( v6 != 4 )
          {
LABEL_173:
            v15 = -1073741811;
            goto LABEL_174;
          }
          PpmSetExitLatencySamplingPercentage(v11);
        }
        else
        {
          PpmClearExitLatencySamplingPercentage();
        }
        goto LABEL_169;
      case 0x53u:
        if ( v11 || !v5 )
          goto LABEL_173;
        PopCurrentPowerStatePrecise((int)&v90);
LABEL_214:
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 32;
        goto LABEL_547;
      case 0x54u:
        if ( !v11 || v5 )
          goto LABEL_173;
        if ( v6 < 0x10 || v6 < 2 * ((unsigned int)*((unsigned __int16 *)v11 + 6) + 7) )
          goto LABEL_177;
        v41 = PopThermalProcessUsermodeEvent(v11);
        goto LABEL_302;
      case 0x55u:
        v63 = *((unsigned __int8 *)v11 + 8);
        v64 = v11[1];
        v65 = *v11;
        if ( *((_BYTE *)v11 + 8) )
          PoSetPowerRequestInternal(v65, v64, v12, v63);
        else
          PoClearPowerRequestInternal(v65, v64, v12, v63);
        goto LABEL_169;
      case 0x56u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        v15 = RtlStringCbLengthW((int)v11, v6, 0);
        if ( v15 < 0 )
          goto LABEL_174;
        v15 = PopBatteryDeviceState(v11, &v90);
        if ( v15 < 0 )
          goto LABEL_174;
        v9 = &v90;
        v75 = (const __int16 *)&v90;
        v25 = 52;
        goto LABEL_547;
      case 0x57u:
        if ( !v11 || v6 < 8 || *v11 >= 3 )
          goto LABEL_173;
        v15 = PopPowerInformationInternal(*v11, v11, v6);
        if ( v15 < 0 )
        {
          v9 = (int *)v75;
          v20 = 0;
          v21 = 0;
          v22 = v73;
          goto LABEL_559;
        }
        v67 = 0;
LABEL_545:
        v9 = (int *)v75;
        v72 = v67;
LABEL_546:
        v25 = v78;
        goto LABEL_547;
      case 0x59u:
        if ( !v11 || !v5 )
          goto LABEL_173;
        if ( v6 < 4 )
          goto LABEL_177;
        PopAcquireTransitionLock(v13);
        PopAcquirePolicyLock();
        v37 = PopSetHiberFileType(*v11, v89);
LABEL_273:
        v15 = v37;
        v38 = PopReleasePolicyLock();
        PopReleaseTransitionLock(v38);
        if ( v15 < 0 )
          goto LABEL_174;
        v9 = (int *)v89;
LABEL_275:
        v75 = (const __int16 *)v9;
        v25 = 8;
        goto LABEL_547;
      default:
        goto LABEL_173;
    }
  }
  if ( a1 == 6
    || a1 == 17
    || a1 == 7
    || a1 == 32
    || a1 == 34
    || a1 == 33
    || a1 == 80
    || a1 == 81
    || a1 == 82
    || a1 == 24
    || a1 == 30
    || a1 == 31
    || a1 == 39
    || a1 == 40
    || a1 == 41
    || a1 == 63
    || a1 == 42
    || a1 == 49
    || a1 == 47
    || a1 == 25
    || a1 == 61
    || a1 == 62
    || a1 == 56
    || a1 == 71
    || a1 == 67
    || a1 == 68
    || a1 == 69
    || a1 == 79
    || a1 == 85 )
  {
    v15 = -1073741790;
LABEL_118:
    v20 = 0;
    v21 = 0;
    v22 = 0;
    goto LABEL_559;
  }
  if ( a1 != 73
    && a1 != 64
    && a1 != 45
    && a1 != 38
    && a1 != 55
    && a1 != 48
    && a1 != 60
    && a1 != 57
    && a1 != 72
    && a1 != 2
    && a1 != 3
    && a1 != 37
    && a1 != 84
    && a1 != 88 )
  {
LABEL_62:
    if ( a1 == 45 || a1 == 28 || a1 == 50 || a1 == 78 )
    {
      v13 = PopUserIsAdmin();
      if ( !v13 )
      {
        v15 = -1073741790;
        v80 = -1073741790;
        goto LABEL_174;
      }
    }
    v16 = (unsigned int)v83;
    if ( v83 )
    {
      if ( (a1 == 9 || a1 == 38 || a1 == 55 || a1 == 48 || a1 == 51 || a1 == 89 || a1 == 60 || a1 == 64)
        && !PopUserIsAdmin() )
      {
        v15 = -1073741790;
        v80 = -1073741790;
        goto LABEL_174;
      }
      if ( a1 != 2
        && a1 != 3
        && a1 != 37
        && a1 != 43
        && a1 != 72
        && a1 != 44
        && a1 != 73
        && a1 != 45
        && a1 != 11
        && a1 != 46
        && a1 != 38
        && a1 != 55
        && a1 != 48
        && a1 != 59
        && a1 != 60
        && a1 != 58
        && a1 != 64
        && a1 != 57
        && a1 != 66
        && a1 != 75
        && a1 != 86
        && a1 != 88
        && a1 != 87 )
      {
        if ( a1 == 10 )
        {
          v17 = SeCreatePagefilePrivilege;
          v18 = dword_922BAC;
        }
        else
        {
          v17 = SeShutdownPrivilege;
          v18 = dword_922B8C;
        }
        if ( !SeSinglePrivilegeCheck(v17, v18, v84, (int)&SeShutdownPrivilege) )
        {
          v15 = -1073741727;
          v80 = -1073741727;
          goto LABEL_174;
        }
      }
      if ( v6 && (v16 + v6 > MmUserProbeAddress || v16 + v6 < v16) )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v16 = (unsigned int)v83;
      }
      v19 = ExAllocatePoolWithTag(1, v6, 544040269);
      v11 = (int *)v19;
      v87 = v19;
      if ( !v19 )
      {
        v15 = -1073741670;
        v80 = -1073741670;
        goto LABEL_174;
      }
      v13 = memmove(v19, v16, v6);
    }
    if ( v5 )
      v13 = ProbeForWrite(v5, v79, 1);
    v10 = 0;
    goto LABEL_120;
  }
  v13 = SeIsAppContainerOrIdentifyLevelContext(0, v82);
  v15 = v13;
  v80 = v13;
  if ( v13 >= 0 )
  {
    if ( v82[0] )
    {
      if ( a1 != 73 && a1 != 88 )
      {
        v15 = -1073741790;
        v80 = -1073741790;
        goto LABEL_174;
      }
      v13 = PopCapabilityCheck(v13, v14);
      if ( !v13 )
      {
        v15 = -1073741790;
        v80 = -1073741790;
        goto LABEL_174;
      }
    }
    goto LABEL_62;
  }
LABEL_174:
  v9 = 0;
LABEL_556:
  v22 = v73;
LABEL_557:
  v21 = v74;
LABEL_558:
  v20 = v72;
LABEL_559:
  if ( v21 )
    ExFreePoolWithTag(v21);
  if ( v20 )
    ExFreePoolWithTag((unsigned int)v9);
  if ( v22 )
    PopReleasePolicyLock();
  if ( v11 && v11 != v83 )
    ExFreePoolWithTag((unsigned int)v11);
  return v15;
}
