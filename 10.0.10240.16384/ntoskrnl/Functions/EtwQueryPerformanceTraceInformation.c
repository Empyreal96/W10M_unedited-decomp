// EtwQueryPerformanceTraceInformation 
 
int __fastcall EtwQueryPerformanceTraceInformation(unsigned int *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v7; // r8
  int v8; // r4
  int v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  _DWORD *v13; // r9
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  _DWORD *v17; // r6
  int *v18; // r5
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  _DWORD *v26; // r0
  unsigned int v27; // r0
  unsigned int v28; // r6
  unsigned int v29; // r1
  void **v30; // lr
  unsigned __int64 v31; // kr00_8
  int v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r2
  int v35; // r10
  int v36; // r4
  int v37; // r1
  unsigned int v38; // r10
  int v39; // r2
  unsigned int v40; // r0
  unsigned int v41; // r2
  _DWORD *v42; // r5
  unsigned int v43; // r1
  __int16 v44; // r3
  unsigned int v45; // r1
  __int16 v46; // r3
  unsigned int v47; // r3
  unsigned int i; // r4
  int v49; // r2
  unsigned int v50; // r0
  unsigned int v51; // r2
  int v52; // r4
  int v53; // r1
  unsigned int v54; // r3
  unsigned int v55; // r10
  int j; // r0
  int *v57; // r0
  int v58; // r6
  int v59; // r0
  int v60; // r5
  unsigned int v62; // [sp+8h] [bp-50h]
  unsigned int *v63; // [sp+10h] [bp-48h]
  unsigned int v64; // [sp+14h] [bp-44h]
  int v65; // [sp+18h] [bp-40h] BYREF
  int *v66; // [sp+1Ch] [bp-3Ch] BYREF
  int v67[4]; // [sp+20h] [bp-38h] BYREF
  unsigned int *v68; // [sp+30h] [bp-28h] BYREF
  int v69; // [sp+34h] [bp-24h]
  unsigned int *varg_r0; // [sp+60h] [bp+8h]
  unsigned int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  unsigned int *varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  LOBYTE(varg_r2) = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v7 = 0;
  if ( a2 < 4 )
    return -1073741811;
  v65 = *a1;
  v67[2] = v65;
  switch ( v65 )
  {
    case 0:
      *a4 = 8;
      if ( a2 != 8 )
        goto LABEL_5;
      a1[1] = 60;
      goto LABEL_54;
    case 1:
      *a4 = 48;
      if ( a2 != 48 )
        goto LABEL_5;
      v9 = a1[3];
      v68 = (unsigned int *)a1[2];
      v69 = v9;
      v10 = (unsigned __int16)v68;
      if ( (unsigned __int16)v68 == 0xFFFF )
        v10 = (unsigned __int16)EtwpSystemLogger[0];
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v11 + 308);
      v12 = EtwpAcquireLoggerContextByLoggerId(v10, 1);
      v13 = (_DWORD *)v12;
      v67[0] = v12;
      if ( !v12 )
        goto LABEL_17;
      if ( (*(_DWORD *)(v12 + 12) & 0x2000000) == 0 )
        goto LABEL_12;
      v17 = a1 + 4;
      v18 = &EtwpGroupMasks[8 * *(unsigned __int8 *)(v12 + 610)];
      v19 = *v18;
      v20 = v18[1];
      v21 = v18[2];
      v22 = v18[3];
      v18 += 4;
      *v17 = v19;
      v17[1] = v20;
      v17[2] = v21;
      v17[3] = v22;
      v23 = v18[1];
      v24 = v18[2];
      v25 = v18[3];
      v17[4] = *v18;
      v17[5] = v23;
      v17[6] = v24;
      v17[7] = v25;
      EtwpMapEnableFlags((int)v17, 0);
      v26 = v13;
      goto LABEL_48;
    case 2:
      *a4 = 16;
      if ( a2 != 16 )
        goto LABEL_5;
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v30 = &KiProcessorBlock;
      while ( v29 < KeNumberProcessors_0 )
      {
        v31 = __PAIR64__(v28, v27) + *(_QWORD *)(*((_DWORD *)*v30 + 899) + 1872);
        v28 = HIDWORD(v31);
        v27 = v31;
        ++v29;
        ++v30;
      }
      a1[2] = v27;
      a1[3] = v28;
      goto LABEL_54;
    case 3:
      *a4 = 8;
      if ( a2 != 8 )
        goto LABEL_5;
      a1[1] = EtwpProfileInterval;
      goto LABEL_54;
    case 4:
      *a4 = 24;
      if ( a2 < 0x18 )
        goto LABEL_5;
      v32 = a1[3];
      v68 = (unsigned int *)a1[2];
      v69 = v32;
      v66 = (int *)a1[1];
      v33 = (unsigned __int16)v68;
      if ( (unsigned __int16)v68 == 0xFFFF )
        v33 = (unsigned __int16)EtwpSystemLogger[0];
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v34 + 308);
      v12 = EtwpAcquireLoggerContextByLoggerId(v33, 0);
      v35 = v12;
      if ( !v12 )
      {
LABEL_17:
        v7 = -1073741162;
        goto LABEL_50;
      }
      v36 = EtwpReferenceLoggerSecurityDescriptor(v12);
      v67[0] = v36;
      v65 = a2 - 16;
      v7 = SeQuerySecurityDescriptorInfo((int *)&v66, (int)(a1 + 4), (unsigned int *)&v65, v67);
      *a4 = v65 + 16;
      EtwpDereferenceLoggerSecurityDescriptor(v35, v36);
      v37 = 0;
      v26 = (_DWORD *)v35;
      goto LABEL_49;
    case 5:
      *a4 = 20;
      if ( a2 != 16 && a2 != 20 )
        goto LABEL_5;
      a1[1] = EtwpSpinLockSpinThreshold;
      a1[2] = EtwpSpinLockAcquireSampleRate;
      a1[3] = EtwpSpinLockContentionSampleRate;
      if ( a2 == 20 )
        a1[4] = EtwpSpinLockHoldThreshold;
      goto LABEL_54;
    case 6:
      v38 = 0;
      v62 = 0;
      v65 = 0;
      v63 = a1 + 4;
      v66 = (int *)(a1 + 4);
      if ( a2 < 0x10 )
        goto LABEL_5;
      v39 = a1[3];
      v68 = (unsigned int *)a1[2];
      v69 = v39;
      v40 = (unsigned __int16)v68;
      if ( (unsigned __int16)v68 == 0xFFFF )
        v40 = (unsigned __int16)EtwpSystemLogger[0];
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v41 + 308);
      v12 = EtwpAcquireLoggerContextByLoggerId(v40, 1);
      v42 = (_DWORD *)v12;
      v68 = (unsigned int *)v12;
      if ( !v12 )
        goto LABEL_41;
      v7 = EtwpCheckLoggerControlAccess(1, v12);
      if ( v7 >= 0 )
      {
        if ( (v42[152] & 0x80) != 0 )
          v38 = RtlNumberOfSetBits(v42 + 154);
        v47 = 4 * (v38 + 4);
        *a4 = v47;
        if ( v47 > a2 )
        {
          v7 = -1073741789;
        }
        else
        {
          for ( i = 0; ; ++i )
          {
            v67[0] = i;
            if ( i >= v38 )
              break;
            v62 = RtlFindSetBits(v42 + 154, 1u, v62 + 1);
            v65 = v62;
            v63[i] = v62;
          }
        }
      }
      v26 = v42;
      goto LABEL_48;
    case 7:
      *a4 = 16;
      if ( a2 != 16 )
        goto LABEL_5;
      a1[1] = EtwpExecutiveResourceReleaseSampleRate;
      a1[2] = EtwpExecutiveResourceContentionSampleRate;
      a1[3] = EtwpExecutiveResourceTimeout;
      goto LABEL_54;
    case 8:
    case 9:
      v55 = 0;
      v67[0] = 0;
      if ( a2 < 8 )
        goto LABEL_5;
      v68 = a1;
      v64 = (a2 - 4) >> 2;
      for ( j = 0; ; j = v58 )
      {
        v57 = PsGetNextProcess(j);
        v58 = (int)v57;
        v66 = v57;
        if ( !v57 )
          break;
        if ( !PsIsSystemProcess((int)v57) && (v65 == 9 || EtwpUMGLEnabled(v58)) )
        {
          v59 = PsGetProcessId(v58);
          if ( v55 < v64 )
            a1[v55 + 1] = v59;
          v67[0] = ++v55;
        }
      }
      *a4 = 4 * (v55 + 1);
      if ( v55 > v64 )
        v7 = -1073741789;
      goto LABEL_54;
    case 10:
      v68 = a1 + 4;
      if ( a2 < 0x10 )
        goto LABEL_5;
      v49 = a1[3];
      v67[0] = a1[2];
      v67[1] = v49;
      v50 = LOWORD(v67[0]);
      if ( LOWORD(v67[0]) == 0xFFFF )
        v50 = (unsigned __int16)EtwpSystemLogger[0];
      v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v51 + 308);
      v12 = EtwpAcquireLoggerContextByLoggerId(v50, 1);
      v52 = v12;
      v68 = (unsigned int *)v12;
      if ( !v12 )
      {
LABEL_41:
        v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v44 = *(_WORD *)(v43 + 0x134) + 1;
        *(_WORD *)(v43 + 308) = v44;
        if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
          KiCheckForKernelApcDelivery(v12);
        return -1073741162;
      }
      if ( (*(_DWORD *)(v12 + 12) & 0x2000000) == 0 )
      {
LABEL_12:
        v14 = EtwpReleaseLoggerContext((_DWORD *)v12, 1);
        v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
        *(_WORD *)(v15 + 308) = v16;
        if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
          KiCheckForKernelApcDelivery(v14);
        return -1073741811;
      }
      v7 = EtwpCheckSystemTraceAccess(v12, 1);
      if ( v7 >= 0 )
      {
        v53 = 5 * *(unsigned __int8 *)(v52 + 610);
        v54 = 4 * (EtwpPoolTagFilter[10 * *(unsigned __int8 *)(v52 + 610)] + 4);
        *a4 = v54;
        if ( v54 > a2 )
          v7 = -1073741789;
        else
          memmove((int)(a1 + 4), (int)&EtwpPoolTagFilter[2 * v53 + 2], 4 * EtwpPoolTagFilter[2 * v53]);
      }
      v26 = (_DWORD *)v52;
LABEL_48:
      v37 = 1;
LABEL_49:
      v12 = EtwpReleaseLoggerContext(v26, v37);
LABEL_50:
      v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v46 = *(_WORD *)(v45 + 0x134) + 1;
      *(_WORD *)(v45 + 308) = v46;
      if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
        KiCheckForKernelApcDelivery(v12);
      goto LABEL_54;
    case 13:
      if ( a2 < 0x28 )
      {
LABEL_5:
        v8 = -1073741820;
      }
      else
      {
        v8 = ExLockUserBuffer((int)(a1 + 2), a2 - 8, (char)a3, 1, (int *)&v68, v67);
        if ( v8 >= 0 )
        {
          v60 = (int)v68;
          v7 = off_617B54(20, a2 - 8, v68, a4);
          if ( v60 )
            ExUnlockUserBuffer(v67[0]);
LABEL_54:
          v8 = v7;
        }
      }
      break;
    default:
      v7 = -1073741822;
      goto LABEL_54;
  }
  return v8;
}
