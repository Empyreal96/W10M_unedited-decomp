// KiPlayInterrupt 
 
int __fastcall KiPlayInterrupt(__int64 a1, int a2, char a3)
{
  unsigned int v3; // r5
  int v4; // r1
  unsigned int v5; // r4
  unsigned int v6; // r8
  int *v7; // r3
  int v8; // r2
  int v9; // r9
  int v10; // r6
  BOOL v11; // r2
  BOOL v12; // r4
  int v13; // r2
  int v14; // r0
  int v15; // r3
  int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r2
  __int64 v20; // r0
  _DWORD *v21; // r3
  int v22; // r0
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r4
  unsigned int *v26; // r0
  unsigned int v27; // r2
  _DWORD *v28; // r0
  __int64 v29; // r0
  __int64 v30; // kr08_8
  int v31; // r4
  BOOL v32; // r3
  int v33; // r5
  int v34; // r0
  int v35; // r3
  __int64 v36; // r0
  int v37; // r4
  int v38; // r0
  unsigned int v39; // r3
  int v40; // r0
  unsigned int v41; // r1
  unsigned int *v42; // r0
  unsigned int v43; // r2
  int (*v44)(); // r2
  __int64 v45; // r0
  unsigned int v46; // r3
  int v47; // r1
  unsigned int *v48; // r2
  unsigned int v49; // r4
  unsigned int v50; // r0
  unsigned int v51; // r4
  int v52; // lr
  _DWORD *v53; // r0
  __int64 v54; // r0
  __int64 v55; // kr10_8
  int v56; // r3
  int v57; // r9
  int v58; // lr
  int v59; // r10
  __int64 v60; // kr18_8
  unsigned __int64 *v61; // r3
  unsigned __int64 v62; // kr20_8
  unsigned int v63; // r4
  unsigned int v64; // r6
  int v65; // r2
  int v66; // r3
  unsigned int v67; // r1
  unsigned int v68; // r3
  unsigned int v69; // r5
  unsigned __int64 v70; // kr40_8
  char v71; // r3
  int v73; // [sp+Ch] [bp-B4h]
  int v74; // [sp+Ch] [bp-B4h]
  int v75; // [sp+Ch] [bp-B4h]
  int v76; // [sp+10h] [bp-B0h]
  int v77; // [sp+10h] [bp-B0h]
  int v78; // [sp+10h] [bp-B0h]
  unsigned int v79; // [sp+18h] [bp-A8h]
  int v80; // [sp+1Ch] [bp-A4h]
  unsigned int v81; // [sp+1Ch] [bp-A4h]
  unsigned int v82; // [sp+20h] [bp-A0h]
  unsigned int v83; // [sp+20h] [bp-A0h]
  BOOL v84; // [sp+24h] [bp-9Ch]
  int v85; // [sp+28h] [bp-98h]
  int v86; // [sp+28h] [bp-98h]
  BOOL v87; // [sp+2Ch] [bp-94h]
  int v88; // [sp+30h] [bp-90h]
  unsigned int v89; // [sp+30h] [bp-90h]
  int v90; // [sp+34h] [bp-8Ch]
  int v91; // [sp+3Ch] [bp-84h]
  unsigned int v92; // [sp+40h] [bp-80h]
  int v94; // [sp+48h] [bp-78h]
  int v95; // [sp+50h] [bp-70h]
  unsigned int v96; // [sp+58h] [bp-68h]
  int v97; // [sp+5Ch] [bp-64h]
  unsigned int v98; // [sp+60h] [bp-60h]
  unsigned int v99; // [sp+64h] [bp-5Ch]
  _QWORD v100[2]; // [sp+70h] [bp-50h] BYREF
  _BYTE v101[16]; // [sp+80h] [bp-40h] BYREF
  _BYTE v102[48]; // [sp+90h] [bp-30h] BYREF

  v3 = HIDWORD(a1);
  v79 = HIDWORD(a1);
  v91 = a1;
  v4 = 0;
  v80 = 0;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = v5 + 1408;
  __enable_irq();
  v90 = 0;
  *(_BYTE *)(a1 + 19) = a3;
  if ( (v3 & 0xF0) != 0 )
  {
    if ( v3 - 2048 >= 0x400 )
      goto LABEL_134;
    v8 = *(_DWORD *)(v5 + 1324);
    if ( !v8 )
      goto LABEL_134;
    v7 = (int *)(v8 + 4 * (v3 - 2048));
  }
  else
  {
    v7 = (int *)(v5 + 4 * ((v3 & 0xF | (v3 >> 4) & 0xF0) + 75));
  }
  if ( v7 )
  {
    v9 = *v7;
    if ( *v7 )
    {
      v10 = *v7;
      v11 = *(_DWORD *)(v9 + 4) == v9 + 4;
      v84 = v11;
      v12 = 0;
      v87 = 0;
      if ( !*(_DWORD *)(v9 + 64) )
      {
        while ( 1 )
        {
          if ( !v11 )
          {
            v12 = (*(_DWORD *)(v10 + 60) & 1) != 0;
            v87 = v12;
          }
          if ( v12 )
            goto LABEL_60;
          v90 = 1;
          if ( !*(_BYTE *)(v10 + 49) )
          {
            LODWORD(a1) = IoProcessPassiveInterrupts(*(_DWORD *)(v10 + 44), &KiProcessorBlock);
            goto LABEL_134;
          }
          v76 = a2;
          v13 = 1;
          v73 = 1;
          *(_DWORD *)(v10 + 84) = a1;
          v14 = *(unsigned __int8 *)(v10 + 49);
          if ( a2 != v14 )
          {
            v76 = KfRaiseIrql(v14);
            v13 = 1;
          }
          v15 = *(_DWORD *)(v10 + 36);
          if ( v15 == -3 || v15 == -1 )
          {
            v13 = 0;
            v73 = 0;
          }
          if ( v15 == -3 || (dword_682604 & 0x4000) == 0 )
          {
            v31 = KiCallInterruptServiceRoutine(v10, v13);
            goto LABEL_56;
          }
          v16 = 0;
          v17 = EtwpActiveSystemLoggers;
          while ( 1 )
          {
            v18 = __clz(__rbit(v17));
            if ( 1 == (unsigned __int8)(v18 >> 5) )
              break;
            v17 &= v17 - 1;
            if ( &EtwpGroupMasks[8 * v18] && (EtwpGroupMasks[8 * v18 + 1] & 0x4000) != 0 )
              v16 |= 1 << EtwpSystemLogger[2 * v18 + 1];
          }
          v19 = 0;
          v81 = 0;
          while ( v19 < 2 )
          {
            if ( ((1 << v19) & v16) != 0 )
            {
              v20 = ((__int64 (*)(void))*(&EtwpSystemTimeStamp + v19))();
              v19 = v81;
              v100[v81] = v20;
            }
            else
            {
              v21 = &v100[v19];
              *v21 = 0;
              v21[1] = 0;
            }
            v81 = ++v19;
          }
          if ( *(_BYTE *)(v10 + 49) )
          {
            v82 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
            v85 = *(_DWORD *)(v82 + 3276);
            *(_BYTE *)(v10 + 152) = 1;
            *(_DWORD *)(v82 + 3276) = v10 + 104;
            v23 = ReadTimeStampCounter();
            v92 = v24;
            v88 = v23;
            *(_DWORD *)(v10 + 112) = v23;
            *(_DWORD *)(v10 + 116) = v24;
            v25 = v73;
            if ( v73 )
            {
              v26 = *(unsigned int **)(v10 + 36);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v26);
              }
              else
              {
                do
                  v27 = __ldrex(v26);
                while ( __strex(1u, v26) );
                __dmb(0xBu);
                if ( v27 )
                  KxWaitForSpinLockAndAcquire(v26);
              }
            }
            v74 = (*(int (__fastcall **)(int, _DWORD))(v10 + 12))(v10, *(_DWORD *)(v10 + 24));
            if ( v25 )
            {
              v28 = *(_DWORD **)(v10 + 36);
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented(v28);
              }
              else
              {
                __dmb(0xBu);
                *v28 = 0;
              }
            }
            LODWORD(v29) = ReadTimeStampCounter();
            *(_QWORD *)(v10 + 104) += v29 - *(_QWORD *)(v10 + 112);
            if ( v85 != 1 )
            {
              v30 = v29 - __PAIR64__(v92, v88);
              if ( *(_BYTE *)(v85 + 48) )
                *(_QWORD *)(v85 + 8) += v30;
              else
                *(_QWORD *)(v85 + 32) += v30;
            }
            *(_DWORD *)(v82 + 3276) = v85;
            *(_BYTE *)(v10 + 152) = 0;
            v22 = v74;
            v3 = v79;
            if ( !v74 )
            {
LABEL_53:
              v31 = 0;
              goto LABEL_54;
            }
            ++*(_QWORD *)(v10 + 120);
          }
          else
          {
            v22 = (*(int (__fastcall **)(int, _DWORD))(v10 + 12))(v10, *(_DWORD *)(v10 + 24));
          }
          if ( !v22 )
            goto LABEL_53;
          v31 = 1;
LABEL_54:
          PerfInfoLogInterrupt(v10, v31 | (v3 << 8), v100);
LABEL_56:
          LODWORD(a1) = v76;
          if ( v76 != *(unsigned __int8 *)(v10 + 49) )
            LODWORD(a1) = KfLowerIrql(v76);
          if ( v31 == 1 )
            goto LABEL_134;
          v11 = v84;
          LODWORD(a1) = v91;
          v12 = v87;
LABEL_60:
          v10 = *(_DWORD *)(v10 + 4) - 4;
          if ( v10 == v9 )
            goto LABEL_134;
        }
      }
      while ( 1 )
      {
        if ( v11 )
        {
          v32 = v87;
        }
        else
        {
          v32 = (*(_DWORD *)(v10 + 60) & 1) != 0;
          v87 = v32;
        }
        if ( !v32 )
          break;
        v3 = v79;
LABEL_129:
        v10 = *(_DWORD *)(v10 + 4) - 4;
        if ( v10 == v9 )
        {
          if ( !v4 || v11 )
            goto LABEL_134;
          v4 = 0;
          v80 = 0;
        }
      }
      v90 = 1;
      if ( !*(_BYTE *)(v10 + 49) )
      {
        LODWORD(a1) = IoProcessPassiveInterrupts(*(_DWORD *)(v10 + 44), v4);
        v3 = v79;
        goto LABEL_134;
      }
      v86 = a2;
      v33 = 1;
      *(_DWORD *)(v10 + 84) = a1;
      v34 = *(unsigned __int8 *)(v10 + 49);
      if ( a2 != v34 )
        v86 = KfRaiseIrql(v34);
      v35 = *(_DWORD *)(v10 + 36);
      if ( v35 == -3 || v35 == -1 )
        v33 = 0;
      if ( v35 != -3 && (dword_682604 & 0x4000) != 0 )
      {
        LODWORD(v36) = v101;
        HIDWORD(v36) = 536887296;
        EtwGetKernelTraceTimestamp(v36);
        v37 = KiCallInterruptServiceRoutine(v10, v33);
        v3 = v79;
        PerfInfoLogInterrupt(v10, v37 | (v79 << 8), v101);
LABEL_122:
        if ( v86 != *(unsigned __int8 *)(v10 + 49) )
          KfLowerIrql(v86);
        LODWORD(a1) = v91;
        if ( v37 == 1 )
        {
          v4 = 1;
          v80 = 1;
        }
        else
        {
          v4 = v80;
        }
        v11 = v84;
        goto LABEL_129;
      }
      if ( *(_BYTE *)(v10 + 49) )
      {
        v39 = (unsigned int)KeGetPcr();
        v98 = (v39 & 0xFFFFF000) + 1408;
        v97 = *(_DWORD *)((v39 & 0xFFFFF000) + 0x124C);
        *(_BYTE *)(v10 + 152) = 1;
        *(_DWORD *)((v39 & 0xFFFFF000) + 0x124C) = v10 + 104;
        v40 = ReadTimeStampCounter();
        v99 = v41;
        v94 = v40;
        *(_DWORD *)(v10 + 112) = v40;
        *(_DWORD *)(v10 + 116) = v41;
        if ( v33 )
        {
          v42 = *(unsigned int **)(v10 + 36);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v42);
          }
          else
          {
            do
              v43 = __ldrex(v42);
            while ( __strex(1u, v42) );
            __dmb(0xBu);
            if ( v43 )
              KxWaitForSpinLockAndAcquire(v42);
          }
        }
        v44 = *(int (**)())(v10 + 12);
        if ( v44 == KiIpiServiceRoutine )
        {
          v95 = *(_DWORD *)(v10 + 84);
          v77 = 0;
          if ( (dword_682608 & 0x400000) != 0 )
          {
            v77 = 1;
            LODWORD(v45) = v102;
            HIDWORD(v45) = 1077936128;
            EtwGetKernelTraceTimestamp(v45);
          }
          v46 = (unsigned int)KeGetPcr() & 0xFFFFF000;
          v47 = v46 + 1408;
          v75 = v46 + 1408;
          __dmb(0xBu);
          v48 = (unsigned int *)(v46 + 3084);
          do
            v49 = __ldrex(v48);
          while ( __strex(0, v48) );
          v96 = v49;
          __dmb(0xBu);
          if ( *(_DWORD *)(v46 + 3072) )
          {
            while ( 1 )
            {
              __dmb(0xBu);
              v48 = (unsigned int *)(v47 + 1664);
              do
                v50 = __ldrex(v48);
              while ( __strex(0, v48) );
              __dmb(0xBu);
              if ( !v50 )
                break;
              do
              {
                v51 = v50;
                v83 = v50;
                v52 = (int)*(&KiProcessorBlock + ((int)(v50 - v47 - 18432) >> 5));
                v89 = *(_DWORD *)v50;
                if ( (*(_DWORD *)(v50 + 4) & 0xF) == 6 )
                {
                  (*(void (__fastcall **)(int, _DWORD, _DWORD, _DWORD))(v50 + 20))(
                    v52,
                    *(_DWORD *)(v50 + 8),
                    *(_DWORD *)(v50 + 12),
                    *(_DWORD *)(v50 + 16));
                  v51 = v83;
                }
                KiIpiCompleteIpiRequest(v51, v52);
                v50 = v89;
                v47 = v75;
              }
              while ( v89 );
            }
            v49 = v96;
          }
          if ( (v49 & 1) != 0 )
          {
            HalRequestSoftwareInterrupt(1);
            v47 = v75;
          }
          if ( (v49 & 2) != 0 )
          {
            HalRequestSoftwareInterrupt(2);
            v47 = v75;
          }
          if ( (*(_DWORD *)(v47 + 1672) & 0xF) == 5 )
            KiFreezeCurrentProcessor(v95, v47, (int)v48, 5);
          if ( v77 )
            PerfInfoLogIpi(v102, v49);
          v78 = 1;
        }
        else
        {
          v78 = ((int (__fastcall *)(int, _DWORD))v44)(v10, *(_DWORD *)(v10 + 24));
        }
        if ( v33 )
        {
          v53 = *(_DWORD **)(v10 + 36);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v53);
          }
          else
          {
            __dmb(0xBu);
            *v53 = 0;
          }
        }
        LODWORD(v54) = ReadTimeStampCounter();
        *(_QWORD *)(v10 + 104) += v54 - *(_QWORD *)(v10 + 112);
        if ( v97 != 1 )
        {
          v55 = v54 - __PAIR64__(v99, v94);
          if ( *(_BYTE *)(v97 + 48) )
            *(_QWORD *)(v97 + 8) += v55;
          else
            *(_QWORD *)(v97 + 32) += v55;
        }
        *(_DWORD *)(v98 + 3276) = v97;
        *(_BYTE *)(v10 + 152) = 0;
        v38 = v78;
        if ( !v78 )
          goto LABEL_120;
        ++*(_QWORD *)(v10 + 120);
      }
      else
      {
        v38 = (*(int (__fastcall **)(int, _DWORD))(v10 + 12))(v10, *(_DWORD *)(v10 + 24));
      }
      if ( v38 )
      {
        v37 = 1;
LABEL_121:
        v3 = v79;
        goto LABEL_122;
      }
LABEL_120:
      v37 = 0;
      goto LABEL_121;
    }
  }
LABEL_134:
  if ( !v90 )
  {
    LODWORD(a1) = PerfInfoLogUnexpectedInterrupt(v3);
    if ( KiBugCheckUnexpectedInterrupts )
      KeBugCheckEx(18, 1, v3);
  }
  __disable_irq();
  v56 = *(unsigned __int8 *)(v6 + 16);
  if ( v56 == 1 )
  {
    v57 = *(_DWORD *)(v6 + 4);
    LODWORD(a1) = ReadTimeStampCounter();
    v58 = HIDWORD(a1);
    v59 = a1;
    v60 = a1 - *(_QWORD *)(v6 + 2376);
    __dmb(0xBu);
    v61 = (unsigned __int64 *)(v6 + 2744);
    do
      v62 = __ldrexd(v61);
    while ( __strexd(v62 + v60, v61) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v57 + 2) & 0x20) != 0 )
    {
      v64 = (unsigned __int64)(a1 - *(_QWORD *)(v6 + 2376)) >> 32;
      v63 = a1 - *(_DWORD *)(v6 + 2376);
      v65 = *(_DWORD *)(v6 + 3200);
      v66 = *(_DWORD *)(v6 + 3204);
      if ( v65 && v66 )
      {
        v67 = *(_DWORD *)(v66 + 44);
        if ( v67 >= *(_DWORD *)(v65 + 148) )
          v67 = *(_DWORD *)(v65 + 148);
      }
      else
      {
        v67 = 100;
      }
      v68 = v67 / 0x19;
      if ( v67 / 0x19 >= 3 )
        v68 = 3;
      v69 = v6 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * (v68 + 1144));
      LODWORD(a1) = *(_DWORD *)(v69 + 4);
      HIDWORD(a1) = *(_DWORD *)v69;
      __dmb(0xBu);
      do
        v70 = __ldrexd((unsigned __int64 *)v69);
      while ( __strexd(__PAIR64__(v64, HIDWORD(a1)) + __PAIR64__(a1, v63), (unsigned __int64 *)v69) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v6 + 2376) = v59;
    *(_DWORD *)(v6 + 2380) = v58;
    if ( (*(_BYTE *)(v57 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v6 + 2384) = v59;
      *(_DWORD *)(v6 + 2388) = v58;
    }
    if ( (*(_BYTE *)(v57 + 2) & 2) != 0 )
      LODWORD(a1) = KiBeginCounterAccumulation(v57, 0);
    v71 = 0;
  }
  else
  {
    v71 = v56 - 1;
  }
  *(_BYTE *)(v6 + 16) = v71;
  return a1;
}
