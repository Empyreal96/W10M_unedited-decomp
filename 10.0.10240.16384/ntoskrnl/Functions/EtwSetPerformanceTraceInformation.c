// EtwSetPerformanceTraceInformation 
 
int __fastcall EtwSetPerformanceTraceInformation(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  int v7; // r6
  int v8; // r9
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r2
  int *v17; // r0
  int *v18; // r5
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r4
  int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r5
  int *v30; // r3
  unsigned int v31; // r9
  unsigned int v32; // r8
  _DWORD *v33; // r10
  int v34; // r2
  unsigned int v35; // r0
  unsigned int v36; // r4
  unsigned int v37; // r8
  unsigned int v38; // r0
  unsigned int v39; // r2
  unsigned __int16 *v40; // r3
  int v41; // r8
  int v42; // r9
  int v43; // r0
  unsigned int v44; // r4
  int v45; // r8
  int v46; // r9
  unsigned int v47; // r0
  unsigned int v48; // r4
  int v50; // [sp+8h] [bp-88h]
  int v51; // [sp+8h] [bp-88h]
  int v52; // [sp+8h] [bp-88h]
  int v53; // [sp+8h] [bp-88h]
  unsigned int v54; // [sp+14h] [bp-7Ch]
  int v55; // [sp+50h] [bp-40h] BYREF
  int v56; // [sp+54h] [bp-3Ch]
  int v57; // [sp+58h] [bp-38h]
  int v58; // [sp+5Ch] [bp-34h]
  int v59; // [sp+60h] [bp-30h]
  int v60; // [sp+64h] [bp-2Ch]
  int v61; // [sp+68h] [bp-28h]
  int v62; // [sp+6Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+98h] [bp+8h]
  unsigned int varg_r1; // [sp+9Ch] [bp+Ch]
  int varg_r2; // [sp+A0h] [bp+10h]
  int varg_r3; // [sp+A4h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (char)a3;
  LOBYTE(varg_r2) = a3;
  varg_r1 = a2;
  if ( a2 < 4 )
    return -1073741811;
  v8 = *a1;
  switch ( *a1 )
  {
    case 1:
      if ( a2 != 48 )
        goto LABEL_5;
      v50 = a1[2];
      v9 = a1[5];
      v10 = a1[6];
      v11 = a1[7];
      v55 = a1[4];
      v56 = v9;
      v57 = v10;
      v58 = v11;
      v12 = a1[9];
      v13 = a1[10];
      v14 = a1[11];
      v59 = a1[8];
      v60 = v12;
      v61 = v13;
      v62 = v14;
      v15 = (unsigned __int16)v50;
      if ( (unsigned __int16)v50 == 0xFFFF )
        v15 = (unsigned __int16)EtwpSystemLogger[0];
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v16 + 308);
      v17 = (int *)EtwpAcquireLoggerContextByLoggerId(v15, 1);
      v18 = v17;
      if ( !v17 )
        goto LABEL_9;
      if ( (v17[3] & 0x2000000) == 0 )
        goto LABEL_15;
      v24 = EtwpCheckSystemTraceAccess(v17, 128);
      if ( v24 < 0 )
        goto LABEL_22;
      v25 = EtwpUpdateGroupMasks(v18, (int)&v55);
      goto LABEL_21;
    case 3:
      if ( a2 != 8 )
        goto LABEL_5;
      v29 = a1[1];
      KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
      v24 = NtSetIntervalProfile(v29, 0);
      if ( v24 < 0 )
        goto LABEL_31;
      v30 = &EtwpProfileInterval;
      goto LABEL_30;
    case 5:
      if ( a2 != 16 && a2 != 20 )
        goto LABEL_5;
      v24 = EtwpCheckCurrentUserGuidAccess(SystemTraceControlGuid, 128);
      if ( v24 < 0 )
        goto LABEL_35;
      v51 = a1[1];
      if ( !v51 )
        return -1073741811;
      v54 = a1[2];
      if ( v54 < 0x3E8 )
        return -1073741811;
      v55 = a1[3];
      if ( !v55 )
        return -1073741811;
      v31 = EtwpSpinLockHoldThreshold;
      if ( a2 == 20 )
      {
        v31 = a1[4];
        if ( v31 < 0xF4240 )
        {
          if ( v31 )
            return -1073741811;
        }
      }
      KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
      EtwpSpinLockHoldThreshold = v31;
      EtwpSpinLockSpinThreshold = v51;
      EtwpSpinLockAcquireSampleRate = v54;
      EtwpSpinLockContentionSampleRate = v55;
LABEL_31:
      KeReleaseMutex((int)&EtwpGroupMaskMutex);
      goto LABEL_35;
    case 6:
    case 0xE:
    case 0xF:
      if ( a2 < 0x10 )
        goto LABEL_5;
      if ( ((a2 - 16) & 3) != 0 )
        return -1073741811;
      v32 = (a2 - 16) >> 2;
      v33 = a1 + 4;
      v34 = a1[3];
      v55 = a1[2];
      v56 = v34;
      v35 = (unsigned __int16)v55;
      if ( (unsigned __int16)v55 == 0xFFFF )
        v35 = (unsigned __int16)EtwpSystemLogger[0];
      v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v36 + 308);
      v26 = EtwpAcquireLoggerContextByLoggerId(v35, 1);
      v18 = (int *)v26;
      if ( !v26 )
        goto LABEL_58;
      v24 = EtwpCheckLoggerControlAccess(128, v26);
      if ( v24 < 0 )
        goto LABEL_22;
      if ( v8 == 6 )
      {
        v25 = EtwpUpdateStackTracing(v18, v33, v32);
      }
      else if ( v8 == 15 )
      {
        v25 = EtwpUpdatePmcCounters(v18, v33, v32);
      }
      else
      {
        v25 = EtwpUpdatePmcEvents(v18, v33, v32);
      }
      goto LABEL_21;
    case 7:
      if ( a2 != 16 )
        goto LABEL_5;
      v24 = EtwpCheckCurrentUserGuidAccess(SystemTraceControlGuid, 128);
      if ( v24 < 0 )
        goto LABEL_35;
      v41 = a1[1];
      v42 = a1[2];
      v29 = a1[3];
      KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
      EtwpExecutiveResourceReleaseSampleRate = v41;
      EtwpExecutiveResourceContentionSampleRate = v42;
      v30 = &EtwpExecutiveResourceTimeout;
LABEL_30:
      *v30 = v29;
      goto LABEL_31;
    case 0xA:
    case 0x11:
      if ( a2 < 0x10 )
        goto LABEL_5;
      if ( ((a2 - 16) & 3) != 0 )
        return -1073741811;
      v37 = (unsigned __int16)((a2 - 16) >> 2);
      if ( v37 > 4 )
        return -1073741811;
      v52 = a1[2];
      memmove((int)&v55, (int)(a1 + 4), 4 * v37);
      v38 = (unsigned __int16)v52;
      if ( (unsigned __int16)v52 == 0xFFFF )
        v38 = (unsigned __int16)EtwpSystemLogger[0];
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v39 + 308);
      v17 = (int *)EtwpAcquireLoggerContextByLoggerId(v38, 1);
      v18 = v17;
      if ( !v17 )
      {
LABEL_9:
        v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v20 = *(_WORD *)(v19 + 0x134) + 1;
        *(_WORD *)(v19 + 308) = v20;
        if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
          KiCheckForKernelApcDelivery((int)v17);
        return -1073741162;
      }
      if ( (v17[3] & 0x2000000) == 0 )
      {
LABEL_15:
        v21 = EtwpReleaseLoggerContext(v17, 1);
        v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v23 = (__int16)(*(_WORD *)(v22 + 0x134) + 1);
        *(_WORD *)(v22 + 308) = v23;
        if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
          KiCheckForKernelApcDelivery(v21);
        return -1073741811;
      }
      v24 = EtwpCheckSystemTraceAccess(v17, 128);
      if ( v24 >= 0 )
      {
        if ( v8 == 10 )
          v40 = EtwpPoolTagFilter;
        else
          v40 = EtwpObjectTypeFilter;
        EtwpUpdateTagFilter((int)&v55, v37, (int)&v40[10 * *((unsigned __int8 *)v18 + 610)]);
      }
      goto LABEL_22;
    case 0xC:
      if ( a2 < 0x10 )
        goto LABEL_5;
      v43 = EtwpCheckCurrentUserGuidAccess(SystemTraceControlGuid, 128);
      if ( v43 < 0 )
        return v43;
      if ( !SeSinglePrivilegeCheck(SeSystemProfilePrivilege, dword_922A0C, v4, (int)&SeSystemProfilePrivilege) )
        return -1073741727;
      v44 = (a2 - 16) >> 2;
      if ( v44 > 4 )
        return -1073741811;
      memmove((int)&v55, (int)(a1 + 4), 4 * v44);
      v24 = EtwpSetPmcProfileSource((unsigned int *)&v55, (a2 - 16) >> 2);
      goto LABEL_35;
    case 0x10:
      if ( a2 == 32 )
      {
        v53 = a1[2];
        v45 = a1[5];
        v46 = a1[6];
        if ( *((_BYTE *)a1 + 16) )
        {
          v47 = (unsigned __int16)v53;
          if ( (unsigned __int16)v53 == 0xFFFF )
            v47 = (unsigned __int16)EtwpSystemLogger[0];
          v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v48 + 308);
          v26 = EtwpAcquireLoggerContextByLoggerId(v47, 1);
          v18 = (int *)v26;
          if ( v26 )
          {
            v24 = EtwpCheckLoggerControlAccess(128, v26);
            if ( v24 >= 0 )
            {
              v25 = EtwpEnableStackCaching(v18, v45, v46);
LABEL_21:
              v24 = v25;
            }
LABEL_22:
            v26 = EtwpReleaseLoggerContext(v18, 1);
          }
          else
          {
LABEL_58:
            v24 = -1073741162;
          }
          v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v28 = *(_WORD *)(v27 + 0x134) + 1;
          *(_WORD *)(v27 + 308) = v28;
          if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
            KiCheckForKernelApcDelivery(v26);
LABEL_35:
          v7 = v24;
        }
        else
        {
          v7 = -1073741637;
        }
      }
      else
      {
LABEL_5:
        v7 = -1073741820;
      }
      break;
    default:
      v24 = -1073741822;
      goto LABEL_35;
  }
  return v7;
}
