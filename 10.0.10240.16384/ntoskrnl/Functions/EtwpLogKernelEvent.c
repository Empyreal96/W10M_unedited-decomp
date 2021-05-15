// EtwpLogKernelEvent 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpLogKernelEvent(int *a1, int a2, int a3, int a4, int a5)
{
  int *v8; // r6
  int result; // r0
  _DWORD *v10; // r8
  int v11; // r1
  int *v12; // r2
  int v13; // r0
  int v14; // r3
  int v15; // r3
  int v16; // r3
  unsigned int v17; // r4 OVERLAPPED
  int v18; // r0
  int v19; // r2
  _DWORD *v20; // r1
  int v21; // r3
  _DWORD *v22; // r9
  unsigned int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r10
  unsigned int v26; // r5
  int (*v27)(); // r3
  unsigned int v28; // lr
  unsigned int *v29; // r1
  unsigned int v30; // r4
  unsigned int v31; // r1
  int v32; // r5
  __int16 v33; // r3
  unsigned int v34; // r4
  int v35; // t1
  unsigned int v36; // r1
  unsigned int v37; // r0
  unsigned int v38; // r4
  unsigned int v39; // r1
  int v40; // r3
  __int16 v41; // r5
  _DWORD *v42; // r4
  __int64 v43; // r2
  __int16 v44; // r5
  int v45; // r4
  __int64 v46; // r2
  unsigned int v47; // r2
  int v48; // r3
  int v49; // r0
  unsigned int v50; // r3
  unsigned int *v51; // r4
  unsigned int v52; // r1
  int v53; // r1
  unsigned int v54; // r1
  unsigned int v55; // r4
  unsigned int *v56; // r2
  unsigned int v57; // r1
  unsigned int v58; // r2
  int v59; // lr
  unsigned int v60; // r10
  int v61; // r2
  int v62; // r3
  unsigned __int8 *v63; // r4
  char v64; // r5
  unsigned int v65; // r0
  unsigned int v66; // r2
  unsigned int v67; // r1
  unsigned int v68; // r3
  unsigned int v69; // r5
  int v70; // r3
  int v71; // r3
  __int16 v72; // r3
  unsigned __int8 *v73; // r3
  unsigned int v74; // r2
  int v75; // r2
  int v76; // r1
  unsigned int v77; // r2
  unsigned int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r2
  unsigned int v81; // r1
  unsigned int *v82; // r2
  unsigned int v83; // r1
  unsigned int *v84; // r2
  unsigned int v85; // r1
  int v86; // [sp+8h] [bp-70h]
  unsigned int v87; // [sp+Ch] [bp-6Ch]
  unsigned __int64 v88; // [sp+10h] [bp-68h] BYREF
  unsigned int v89; // [sp+18h] [bp-60h] BYREF
  _DWORD *v90; // [sp+1Ch] [bp-5Ch]
  unsigned int v91; // [sp+20h] [bp-58h]
  _DWORD *v92; // [sp+24h] [bp-54h]
  int v93; // [sp+28h] [bp-50h]
  int v94; // [sp+2Ch] [bp-4Ch]
  int v95; // [sp+30h] [bp-48h]
  unsigned int v96; // [sp+34h] [bp-44h]
  _DWORD *v97; // [sp+38h] [bp-40h]
  int v98; // [sp+3Ch] [bp-3Ch]
  int v99; // [sp+40h] [bp-38h]
  int v100; // [sp+44h] [bp-34h]
  int v101; // [sp+48h] [bp-30h]
  _DWORD var28[11]; // [sp+50h] [bp-28h] BYREF

  v95 = a4;
  v101 = a2;
  v8 = a1;
  v93 = 0;
  result = KeGetCurrentIrql(a1);
  if ( (unsigned int)result < 2 )
  {
    v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v38 + 308);
    result = ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[a2], 1);
    if ( !result )
      JUMPOUT(0x52EC24);
    v93 = 1;
  }
  v10 = (_DWORD *)WmipLoggerContext[a2];
  if ( ((unsigned __int8)v10 & 1) != 0 )
    return sub_52EC14();
  if ( v10 )
  {
    v11 = 0;
    if ( a3 )
    {
      v12 = v8;
      v13 = a3;
      do
      {
        v14 = v12[2];
        v12 += 4;
        v11 += v14;
        --v13;
      }
      while ( v13 );
    }
    result = 7;
    if ( (a5 & 0x100) != 0 )
    {
      if ( (a5 & 0x10000000) != 0 )
      {
        v44 = v11 + 24;
        result = EtwpReserveTraceBuffer(v10, v11 + 24, &v89, (__int64 *)&v88, a5);
        v45 = result;
        if ( result )
        {
          *(_WORD *)(result + 4) = v44;
          HIDWORD(v46) = HIDWORD(v88);
          *(_DWORD *)result = (unsigned __int8)a5 | 0xC0030000;
          LODWORD(v46) = v88;
          *(_QWORD *)(result + 16) = v46;
          *(_WORD *)(result + 6) = a4;
          *(_DWORD *)(result + 8) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
          result = __mrc(15, 0, 13, 0, 3);
          v32 = v45 + 24;
          *(_DWORD *)(v45 + 12) = *(_DWORD *)(*(_DWORD *)((result & 0xFFFFFFC0) + 0x74) + 176);
        }
        else
        {
          v32 = 0;
        }
        v25 = v89;
        v22 = v90;
      }
      else
      {
        v41 = v11 + 32;
        v42 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        result = EtwpReserveTraceBuffer(v10, v11 + 32, &v89, (__int64 *)&v88, a5);
        if ( result )
        {
          *(_WORD *)(result + 4) = v41;
          HIDWORD(v43) = HIDWORD(v88);
          *(_DWORD *)result = (unsigned __int8)a5 | 0xC0010000;
          LODWORD(v43) = v88;
          *(_QWORD *)(result + 16) = v43;
          *(_WORD *)(result + 6) = a4;
          v32 = result + 32;
          *(_DWORD *)(result + 8) = v42[220];
          *(_DWORD *)(result + 12) = v42[219];
          *(_DWORD *)(result + 24) = v42[101];
          *(_DWORD *)(result + 28) = v42[112];
        }
        else
        {
          v32 = 0;
        }
        v25 = v89;
        v22 = v90;
      }
      goto LABEL_34;
    }
    v15 = v10[152];
    if ( (v15 & 0xC00) != 0 && (v15 & 0x800) != 0 )
    {
      v47 = 0;
      v48 = *(_DWORD *)(v10[157] + 16);
      __dmb(0xBu);
      if ( v48 )
      {
        do
        {
          v49 = v10[157];
          if ( *(unsigned __int16 *)(v49 + 2 * v47 + 20) == a4 )
          {
            result = EtwpReserveWithPmcCounters(v10, a4, v11, &v89, &v88, a5);
            v25 = v89;
            v22 = v90;
            v32 = result;
            goto LABEL_34;
          }
          v50 = *(_DWORD *)(v49 + 16);
          ++v47;
          __dmb(0xBu);
        }
        while ( v47 < v50 );
        result = 7;
      }
    }
    v16 = v10[4];
    v98 = v11 + 16;
    if ( v16 < 0 || (unsigned int)(v11 + 16) > v10[2] )
    {
LABEL_159:
      __dmb(0xBu);
      v82 = v10 + 42;
      do
        v83 = __ldrex(v82);
      while ( __strex(v83 + 1, v82) );
      __dmb(0xBu);
      v25 = v89;
      v22 = v90;
      if ( (v10[152] & 8) != 0 )
        v10[88] = 1;
LABEL_163:
      v32 = 0;
      goto LABEL_34;
    }
    v96 = (v11 + 23) & 0xFFFFFFF8;
    *(_QWORD *)(&v17 - 1) = *(_QWORD *)v10;
    v18 = *v10 + 32;
    v19 = 2147483644;
    v99 = *v10;
    v100 = v18;
    v87 = v17;
    v94 = 2147483644;
    while ( 1 )
    {
      v20 = *(_DWORD **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
      v21 = v10[3];
      v92 = v20;
      if ( (v21 & 0x10000000) != 0 )
        v22 = v10 + 22;
      else
        v22 = &v20[v18];
      result = 0;
      __pld(v22);
      v86 = 0;
      v23 = *v22;
      if ( (*v22 & 7) != 0 )
      {
        do
        {
          do
            v24 = __ldrex(v22);
          while ( v24 == v23 && __strex(v23 - 1, v22) );
          __dmb(0xBu);
          if ( v24 == v23 )
            break;
          v23 = v24;
        }
        while ( (v24 & 7) != 0 );
        result = 0;
        v19 = v94;
      }
      if ( !v23 )
      {
        v25 = 0;
        goto LABEL_69;
      }
      if ( (v23 & 7) == 0 )
        break;
      v25 = v23 & 0xFFFFFFF8;
      if ( (v23 & 7) == 1 )
      {
        __dmb(0xBu);
        v51 = (unsigned int *)(v25 + 12);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 + 7, v51) );
        __dmb(0xBu);
        __pld(v22);
        v53 = *v22;
        if ( (*v22 & 7) == 0 )
        {
          while ( v25 == (v53 & 0xFFFFFFF8) )
          {
            do
              result = __ldrex(v22);
            while ( result == v53 && __strex(v53 + 7, v22) );
            __dmb(0xBu);
            if ( result == v53 )
              goto LABEL_156;
            v53 = result;
            if ( (result & 7) != 0 )
              break;
          }
        }
        __dmb(0xBu);
        do
          v54 = __ldrex(v51);
        while ( __strex(v54 - 7, v51) );
        __dmb(0xBu);
        goto LABEL_156;
      }
LABEL_23:
      if ( v25 )
      {
        v26 = *(_DWORD *)(v25 + 8);
        __dmb(0xBu);
        if ( v26 <= v17 )
        {
          while ( 1 )
          {
            v27 = (int (*)())v10[8];
            if ( v27 == EtwpGetPerfCounter )
            {
              KeQueryPerformanceCounter(var28, 0);
              result = var28[0];
              v28 = var28[1];
            }
            else
            {
              result = ((int (__fastcall *)(int))v27)(result);
              v28 = v81;
            }
            v88 = __PAIR64__(v28, result);
            __dmb(0xBu);
            v29 = (unsigned int *)(v25 + 8);
            do
              v30 = __ldrex(v29);
            while ( v30 == v26 && __strex(v26 + v96, v29) );
            __dmb(0xBu);
            if ( v26 == v30 )
              break;
            v26 = v30;
            if ( v30 > v87 )
              goto LABEL_68;
          }
          if ( v96 + v30 > v87 )
          {
            *(_DWORD *)(v25 + 4) = v30;
LABEL_68:
            v17 = v87;
            goto LABEL_69;
          }
          v89 = v25;
          v90 = v22;
          v91 = v30;
          ++*(_QWORD *)&v92[2 * v99 + 96];
          v31 = v25 + v30;
          if ( !(v25 + v30) )
            goto LABEL_163;
          *(_DWORD *)(v31 + 8) = result;
          *(_DWORD *)(v31 + 12) = v28;
          v32 = v31 + 16;
          v33 = v98;
          *(_DWORD *)v31 = (unsigned __int8)a5 | 0xC0100000;
          *(_WORD *)(v31 + 4) = v33;
          *(_WORD *)(v31 + 6) = v95;
LABEL_34:
          if ( v32 )
          {
            for ( ; a3; --a3 )
            {
              v34 = v8[2];
              v35 = *v8;
              v8 += 4;
              memmove(v32, v35, v34);
              v32 += v34;
            }
            if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (v10[3] & 0x80000) != 0 )
              EtwpSendTraceEvent(v10, &v89);
            __pld(v22);
            v36 = *v22;
            if ( (v25 ^ *v22) >= 7 )
            {
LABEL_165:
              __dmb(0xBu);
              v84 = (unsigned int *)(v25 + 12);
              do
                v85 = __ldrex(v84);
              while ( __strex(v85 - 1, v84) );
              __dmb(0xBu);
            }
            else
            {
              while ( 1 )
              {
                __dmb(0xBu);
                do
                  v37 = __ldrex(v22);
                while ( v37 == v36 && __strex(v36 + 1, v22) );
                if ( v37 == v36 )
                  break;
                v36 = v37;
                if ( (v25 ^ v37) >= 7 )
                  goto LABEL_165;
              }
            }
            result = v10[152];
            if ( (result & 0x80) != 0
              && ((*(char *)(((unsigned __int16)(v95 & 0x1FFF) >> 3) + v10[155]) >> (v95 & 7)) & 1) != 0 )
            {
              result = EtwpStackTraceDispatcher(result & 0xFFFF0000 | *v10, &v88, 0, a5);
            }
          }
          if ( v93 )
          {
            result = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v101], 1);
            v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v40 = (__int16)(*(_WORD *)(v39 + 0x134) + 1);
            *(_WORD *)(v39 + 308) = v40;
            if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
              result = KiCheckForKernelApcDelivery(result);
          }
          return result;
        }
      }
LABEL_69:
      result = EtwpSwitchBuffer(v10, v25, v22, *v92, a5);
      if ( result < 0 )
        goto LABEL_159;
      v19 = v94;
      v18 = v100;
    }
    if ( v10[56] != 1 )
    {
      result = KfRaiseIrql(15);
      v86 = result;
      v55 = (unsigned int)(v10 + 127);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v10 + 127);
      }
      else
      {
        do
          v58 = __ldrex((unsigned int *)v55);
        while ( __strex(1u, (unsigned int *)v55) );
        __dmb(0xBu);
        if ( !v58 )
          goto LABEL_97;
        KxWaitForSpinLockAndAcquire(v10 + 127);
      }
      result = v86;
LABEL_97:
      v25 = *v22 & 0xFFFFFFF8;
      if ( v25 )
      {
        __dmb(0xBu);
        v56 = (unsigned int *)(v25 + 12);
        do
          v57 = __ldrex(v56);
        while ( __strex(v57 + 1, v56) );
        __dmb(0xBu);
      }
      if ( v10[56] == 1 )
      {
        __pld((void *)v55);
        v78 = *(_DWORD *)v55;
        if ( (*(_DWORD *)v55 & 0xFFFFFFF0) <= 0x10 )
          v79 = 0;
        else
          v79 = v78 - 16;
        if ( (v78 & 2) != 0 )
          goto LABEL_154;
        __dmb(0xBu);
        do
          v80 = __ldrex((unsigned int *)v55);
        while ( v80 == v78 && __strex(v79, (unsigned int *)v55) );
        if ( v80 != v78 )
LABEL_154:
          ExfReleasePushLock(v55);
        result = KeAbPostRelease(v55);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v55);
          result = v86;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v55 = 0;
        }
        result = KfLowerIrql(result);
      }
LABEL_156:
      v17 = v87;
      goto LABEL_23;
    }
    v55 = (unsigned int)(v10 + 127);
    v97 = v10 + 127;
    if ( !KiAbEnabled || (v59 = v55 & v19, (v55 & v19) == 0) )
    {
      v69 = 0;
      do
LABEL_138:
        v77 = __ldrex((unsigned __int8 *)v55);
      while ( __strex(v77 | 1, (unsigned __int8 *)v55) );
      __dmb(0xBu);
      if ( (v77 & 1) != 0 )
      {
        ExfAcquirePushLockExclusiveEx(v55, v69, v55);
        result = 0;
      }
      if ( v69 )
        *(_BYTE *)(v69 + 14) |= 1u;
      goto LABEL_97;
    }
    v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v61 = 0;
    }
    else
    {
      __disable_irq();
      v61 = 1;
    }
    v62 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v61 )
      __enable_irq();
    if ( (v62 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(0);
      KeBugCheckEx(402, v60, v10 + 127);
    }
    --*(_WORD *)(v60 + 310);
    if ( !*(_BYTE *)(v60 + 484) )
    {
      if ( !*(_BYTE *)(v60 + 810) )
      {
        v69 = 0;
        if ( (dword_682604 & 0x200) != 0 )
        {
          EtwTraceAutoBoostEntryExhaustion(v60, v10 + 127);
          result = 0;
        }
        goto LABEL_131;
      }
      v63 = (unsigned __int8 *)(v60 + 810);
      v64 = *(_BYTE *)(v60 + 810);
      __dmb(0xBu);
      do
        v65 = __ldrex(v63);
      while ( __strex(v65 & ~v64, v63) );
      __dmb(0xBu);
      v55 = (unsigned int)v97;
      result = 0;
      *(_BYTE *)(v60 + 484) |= v64;
    }
    v66 = *(unsigned __int8 *)(v60 + 484);
    v67 = __clz(__rbit(v66));
    var28[2] = v67;
    *(_BYTE *)(v60 + 484) = v66 & ~(unsigned __int8)(1 << v67);
    v68 = v60 + 48 * v67;
    v69 = v68 + 488;
    if ( v68 != -488 )
    {
      if ( v55 >= dword_63389C
        && ((v70 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v55 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v70 == 1)
         || v70 == 11)
        && (v75 = *(_DWORD *)(v60 + 116), (v76 = *(_DWORD *)(v75 + 324)) != 0)
        && v75 != PsInitialSystemProcess )
      {
        v71 = *(_DWORD *)(v76 + 8);
      }
      else
      {
        v71 = -1;
      }
      *(_DWORD *)(v69 + 20) = v71;
      *(_DWORD *)(v69 + 16) = v59;
LABEL_126:
      v72 = *(_WORD *)(v60 + 310) + 1;
      *(_WORD *)(v60 + 310) = v72;
      if ( !v72 && *(_DWORD *)(v60 + 100) != v60 + 100 )
      {
        KiCheckForKernelApcDelivery(0);
        result = 0;
      }
      goto LABEL_138;
    }
LABEL_131:
    v73 = (unsigned __int8 *)(v60 + 81);
    do
      v74 = __ldrex(v73);
    while ( __strex(v74 | 0x80, v73) );
    goto LABEL_126;
  }
  return result;
}
