// PopFxProcessWork 
 
_DWORD *__fastcall PopFxProcessWork(_DWORD *result, int *a2)
{
  int v3; // r2
  _DWORD *v4; // r6
  _DWORD *v5; // r4
  _DWORD *v6; // r4
  unsigned int v7; // r7
  int v8; // r6
  unsigned int *v9; // r10
  int v10; // r3
  int v11; // r0
  unsigned int v12; // r2
  int v13; // r3
  void (__fastcall *v14)(_DWORD, unsigned int); // r3
  unsigned int *v15; // r10
  int v16; // r3
  int v17; // r0
  unsigned int *v18; // r10
  unsigned int v19; // r2
  unsigned int *v20; // lr
  unsigned int v21; // r1
  unsigned int v22; // r1
  unsigned int v23; // r3
  int v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int *v27; // r0
  unsigned int *v28; // lr
  unsigned int v29; // r1
  unsigned int v30; // r1
  unsigned int v31; // r3
  int v32; // r0
  int v33; // r10
  unsigned int v34; // r1
  unsigned int v35; // r3
  _DWORD *v36; // r0
  int v37; // r2
  int v38; // r3
  unsigned int *v39; // r4
  unsigned int v40; // r2
  unsigned int v41; // r2
  unsigned int v42; // r1
  int v43; // r0
  unsigned int v44; // r2
  int v45; // r2
  unsigned int v46; // r1
  unsigned int v47; // r3
  __int64 v48; // r0
  unsigned int v49; // r1
  int v50; // r5
  int v51; // r1
  int v52; // r4
  int v53; // r10
  unsigned int *v54; // r6
  int v55; // r4
  int v56; // r8
  unsigned int v57; // r2
  unsigned int *v58; // r1
  unsigned int v59; // r2
  unsigned int v60; // r2
  unsigned int v61; // r2
  unsigned int *v62; // r2
  unsigned int v63; // r1
  unsigned int v64; // r1
  int v65; // r3
  int v66; // r2
  unsigned int v67; // r2
  int v68; // r3
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned int v71; // r4
  unsigned int v72; // r2
  int v73; // r6
  int v74; // r0
  unsigned int *v75; // r4
  unsigned int v76; // r5
  unsigned int v77; // r1
  unsigned int *v78; // [sp+10h] [bp-48h]
  int v79; // [sp+14h] [bp-44h] BYREF
  unsigned int *v80; // [sp+18h] [bp-40h]
  unsigned int *v81; // [sp+1Ch] [bp-3Ch]
  int v82; // [sp+20h] [bp-38h]
  int var30[13]; // [sp+28h] [bp-30h] BYREF

  v3 = *a2;
  v4 = result;
  if ( *a2 < 0 || v3 >= 9 )
    PopFxBugCheck(1539, result, v3, 0);
  while ( 2 )
  {
    v5 = 0;
    if ( !*a2 )
    {
      v6 = (_DWORD *)a2[1];
      if ( v4 )
        PopFxBugCheck(1539, v4, *a2, 0);
      v7 = a2[2];
      if ( v7 >= v6[97] )
        PopFxBugCheck(1553, 0, v6, v7);
      v8 = *(_DWORD *)(v6[98] + 4 * v7);
      v9 = (unsigned int *)(v8 + 144);
      if ( *(_DWORD *)(v8 + 104) )
        PopFxBugCheck(1557, 0, v7, 0);
      if ( *(int *)(v8 + 52) < 0 )
        PopFxBugCheck(1557, 0, *(_DWORD *)(v6[98] + 4 * v7), 1);
      if ( (*(_DWORD *)(v8 + 52) & 0x3FFFFFFF) == 0 )
        PopFxBugCheck(1557, 0, *(_DWORD *)(v6[98] + 4 * v7), 2);
      v10 = *(_DWORD *)(v8 + 88);
      __dmb(0xBu);
      if ( v10 )
        PopFxBugCheck(1557, 0, v8, 3);
      v11 = KfRaiseIrql(2);
      v82 = v11;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v11 = KiAcquireSpinLockInstrumented(v8 + 144);
      }
      else
      {
        do
          v12 = __ldrex(v9);
        while ( __strex(1u, v9) );
        __dmb(0xBu);
        if ( v12 )
          v11 = KxWaitForSpinLockAndAcquire(v8 + 144);
      }
      v13 = *(_DWORD *)(v8 + 156);
      if ( v13 && v13 >= 0 )
      {
        v48 = KeQueryInterruptTime(v11);
        *(_BYTE *)(v8 + 148) = 1;
        *(_QWORD *)(v8 + 160) = v48;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v8 + 144);
      }
      else
      {
        __dmb(0xBu);
        *v9 = 0;
      }
      KfLowerIrql(v82);
      PopDiagTraceFxComponentLogicalCondition(v6[7], v7, 1);
      v14 = (void (__fastcall *)(_DWORD, unsigned int))v6[15];
      if ( v14 )
        v14(v6[22], v7);
      PopPepProcessEvent(v6[8], v6[8] + 168 * v7 + 128, 2, 3);
      return (_DWORD *)PopFxCompleteComponentActivation(v6, v8, 1);
    }
    switch ( *a2 )
    {
      case 1:
        v33 = a2[1];
        if ( v4 )
          PopFxBugCheck(1539, v4, *a2, 0);
        v34 = a2[2];
        v35 = *(_DWORD *)(v33 + 388);
        v80 = (unsigned int *)v34;
        if ( v34 >= v35 )
          PopFxBugCheck(1553, 0, v33, v34);
        v36 = *(_DWORD **)(*(_DWORD *)(v33 + 392) + 4 * v34);
        if ( (unsigned int)a2[3] >= v36[27] )
          PopFxBugCheck(1558, 0, *(_DWORD *)(*(_DWORD *)(v33 + 392) + 4 * v34), 0);
        v37 = a2[3];
        if ( v37 == v36[26] )
          PopFxBugCheck(1558, 0, *(_DWORD *)(*(_DWORD *)(v33 + 392) + 4 * v34), 1);
        if ( v37 )
        {
          v38 = v36[26];
          __dmb(0xBu);
          if ( v38 )
            PopFxBugCheck(1558, 0, v36, 2);
        }
        v36[26] = a2[3];
        __dmb(0xBu);
        v39 = v36 + 22;
        v36[22] = 2;
        result = (_DWORD *)(*(int (__fastcall **)(_DWORD))(v33 + 68))(*(_DWORD *)(v33 + 88));
        __dmb(0xBu);
        do
        {
          v40 = __ldrex(v39);
          v41 = v40 - 1;
        }
        while ( __strex(v41, v39) );
        __dmb(0xBu);
        if ( !v41 )
        {
          PopDiagTraceFxComponentIdleState(*(_DWORD *)(v33 + 28), v80, a2[3]);
          result = (_DWORD *)PopPluginComponentIdleState(v33, v80);
          v5 = result;
          goto LABEL_60;
        }
        return result;
      case 2:
        v15 = (unsigned int *)a2[1];
        v78 = v15;
        if ( v4 )
          PopFxBugCheck(1539, v4, *a2, 0);
        v16 = *((unsigned __int8 *)a2 + 8);
        v17 = v15[7];
        v80 = (unsigned int *)v16;
        if ( v17 )
          PopDiagTraceFxDevicePowerRequirement(v17, 1, v16, v16);
        v18 = v15 + 46;
        v82 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
          return (_DWORD *)sub_53FED8();
        do
          v19 = __ldrex(v18);
        while ( __strex(1u, v18) );
        __dmb(0xBu);
        if ( v19 )
          KxWaitForSpinLockAndAcquire(v18);
        if ( v80 )
        {
          v27 = v78;
          v80 = v78 + 5;
          v78[5] = 2;
          __dmb(0xBu);
          v28 = v27 + 4;
          do
            v29 = __ldrex(v28);
          while ( __strex(v29 & 0xFFFFFF7F, v28) );
          __dmb(0xBu);
          if ( (v29 & 0x80) == 0 )
            PopFxBugCheck(1545, 0, v78, 0);
          __dmb(0xBu);
          do
            v30 = __ldrex(v28);
          while ( __strex(v30, v28) );
          __dmb(0xBu);
          if ( (v30 & 4) != 0 )
          {
            __dmb(0xBu);
            do
              v42 = __ldrex(v28);
            while ( __strex(v42 & 0xFFFFFFFB, v28) );
            __dmb(0xBu);
            v78[6] = 0;
            v43 = KeCancelTimer((int)(v78 + 48));
            __dmb(0xBu);
            if ( !v43 )
            {
              do
                v57 = __ldrex(v80);
              while ( __strex(v57 - 1, v80) );
              goto LABEL_57;
            }
            do
              v44 = __ldrex(v80);
            while ( __strex(v44 - 1, v80) );
            __dmb(0xBu);
            v32 = PopFxCompleteDevicePowerRequired((int)v78, (int)a2);
          }
          else
          {
            v31 = v78[6];
            __dmb(0xBu);
            if ( v31 )
              goto LABEL_57;
            v32 = PopFxDeliverDevicePowerRequired(v78, (int)a2);
          }
          v5 = (_DWORD *)v32;
          goto LABEL_57;
        }
        __dmb(0xBu);
        v20 = v78 + 4;
        v80 = v78 + 4;
        do
          v21 = __ldrex(v20);
        while ( __strex(v21, v20) );
        __dmb(0xBu);
        if ( (v21 & 0x80) != 0 )
          PopFxBugCheck(1545, 0, v78, 1);
        PopPluginDevicePower((int)v78, 0, 0);
        __dmb(0xBu);
        do
          v22 = __ldrex(v80);
        while ( __strex(v22 | 0x80, v80) );
        __dmb(0xBu);
        if ( !v78[19] )
        {
          PopDiagTraceFxDevicePowerRequirement(v78[7], 0, 0, 0);
          __dmb(0xBu);
          do
            v49 = __ldrex(v80);
          while ( __strex(v49 | 0x40, v80) );
          goto LABEL_47;
        }
        if ( v78[5] || (v23 = v78[6], v81 = v78 + 6, v23) || (*v80 & 4) != 0 )
          PopFxBugCheck(1552, 0, v78, 0);
        __dmb(0xBu);
        v78[6] = 2;
        if ( !PopFxScheduleDeviceIdleTimer((int)v78) )
        {
          PopDiagTraceFxDevicePowerRequirement(v78[7], 0, 0, v24);
          ((void (__fastcall *)(unsigned int))v78[19])(v78[22]);
          __dmb(0xBu);
          do
            v25 = __ldrex(v80);
          while ( __strex(v25 | 0x40, v80) );
          __dmb(0xBu);
          do
            v26 = __ldrex(v81);
          while ( __strex(v26 - 1, v81) );
LABEL_47:
          __dmb(0xBu);
        }
LABEL_57:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v18);
        }
        else
        {
          __dmb(0xBu);
          *v18 = 0;
        }
        result = (_DWORD *)KfLowerIrql(v82);
LABEL_60:
        if ( v5 )
          continue;
        return result;
      case 3:
        v50 = a2[1];
        v51 = 0;
        v79 = 0;
        v52 = -1073741822;
        if ( *(_DWORD *)(v50 + 80) )
        {
          __dmb(0xBu);
          v58 = (unsigned int *)(v50 + 112);
          do
            v59 = __ldrex(v58);
          while ( __strex(v59 + 1, v58) );
          __dmb(0xBu);
          if ( *(_BYTE *)(v50 + 108) )
          {
            __dmb(0xBu);
            do
            {
              v60 = __ldrex(v58);
              v61 = v60 - 1;
            }
            while ( __strex(v61, v58) );
            __dmb(0xBu);
            if ( !v61 )
              KeSetEvent(v50 + 116, 0, 0);
            v52 = -1073741738;
          }
          else
          {
            v52 = (*(int (__fastcall **)(_DWORD, int, int, int, int, int, int *))(v50 + 80))(
                    *(_DWORD *)(v50 + 88),
                    a2[2],
                    a2[4],
                    a2[5],
                    a2[6],
                    a2[7],
                    &v79);
            __dmb(0xBu);
            v62 = (unsigned int *)(v50 + 112);
            do
            {
              v63 = __ldrex(v62);
              v64 = v63 - 1;
            }
            while ( __strex(v64, v62) );
            __dmb(0xBu);
            if ( !v64 )
              KeSetEvent(v50 + 116, 0, 0);
          }
          v51 = v79;
        }
        v65 = *(_DWORD *)(v50 + 32);
        var30[3] = v51;
        var30[4] = v52;
        v66 = *(_DWORD *)(v65 + 24);
        var30[0] = *(_DWORD *)(v66 + 40);
        var30[1] = a2[2];
        var30[2] = a2[3];
        return (_DWORD *)(*(int (__fastcall **)(int, int *))(*(_DWORD *)(v66 + 36) + 64))(15, var30);
      case 4:
        v53 = a2[1];
        v54 = (unsigned int *)(v53 + 184);
        v55 = KfRaiseIrql(2);
        v82 = v55;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v53 + 184);
        }
        else
        {
          do
            v67 = __ldrex(v54);
          while ( __strex(1u, v54) );
          __dmb(0xBu);
          if ( v67 )
            KxWaitForSpinLockAndAcquire(v53 + 184);
        }
        v68 = *((unsigned __int8 *)a2 + 8);
        __dmb(0xBu);
        v69 = (unsigned int *)(v53 + 16);
        if ( v68 )
        {
          do
            v70 = __ldrex(v69);
          while ( __strex(v70 | 8, v69) );
          __dmb(0xBu);
        }
        else
        {
          do
            v71 = __ldrex(v69);
          while ( __strex(v71 & 0xFFFFFFF7, v69) );
          __dmb(0xBu);
          v55 = v82;
        }
        PopFxUpdateDeviceIdleTimer(v53);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v53 + 184);
        }
        else
        {
          __dmb(0xBu);
          *v54 = 0;
        }
        return (_DWORD *)KfLowerIrql(v55);
      case 5:
        v45 = a2[1];
        if ( !v4 )
          PopFxBugCheck(1539, 0, *a2, 0);
        v46 = a2[2];
        v47 = *(_DWORD *)(v45 + 388);
        if ( v46 >= v47 )
          PopFxBugCheck(1553, v4, v45, a2[2]);
        return PopPepCompleteComponentIdleState(*(_DWORD *)(v45 + 32), v46, v45, v47);
      case 6:
        v56 = a2[1];
        if ( !v4 )
          PopFxBugCheck(1539, 0, *a2, 0);
        v72 = a2[2];
        if ( v72 >= *(_DWORD *)(v56 + 388) )
          PopFxBugCheck(1553, v4, a2[1], a2[2]);
        v73 = *(_DWORD *)(*(_DWORD *)(v56 + 392) + 4 * v72);
        v74 = *(_DWORD *)(v73 + 184);
        __dmb(0xBu);
        v75 = (unsigned int *)(v74 + 24);
        do
          v76 = __ldrex(v75);
        while ( __strex(v76 - 1, v75) );
        __dmb(0xBu);
        do
          v77 = __ldrex(v75);
        while ( __strex(v77 | 0x20000000, v75) );
        PopDiagTraceFxPerfRequestProgress();
        return (_DWORD *)PopFxCompleteComponentPerfState(
                           v56,
                           *(_DWORD *)(v73 + 16),
                           *(_DWORD *)(v73 + 184),
                           *((unsigned __int8 *)a2 + 12));
      case 7:
        return (_DWORD *)PopFxAcpiForwardPepAcpiNotifyRequest(a2[1], a2);
      case 8:
        return (_DWORD *)PopFxAcpiForwardPepWorkRequest(a2[1], a2);
      default:
        return result;
    }
  }
}
