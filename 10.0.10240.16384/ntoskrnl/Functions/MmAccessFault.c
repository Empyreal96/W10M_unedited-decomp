// MmAccessFault 
 
int __fastcall MmAccessFault(int a1, unsigned int a2, char a3, int a4)
{
  int v4; // r9
  unsigned int v6; // r7
  unsigned int v7; // r3
  int v8; // r8
  unsigned int i; // r0
  int *v10; // r5
  unsigned int v11; // r3
  unsigned int v12; // r9
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r3
  int v17; // r4
  unsigned int v18; // r8
  unsigned int v19; // r1
  int v20; // r0
  int *v21; // r9
  int v22; // r10
  int result; // r0
  int v24; // r4
  int v25; // r2
  int v26; // r3
  char v27; // r6
  int v28; // r8
  int v29; // r2
  int v30; // r3
  int v31; // r0
  unsigned int v32; // r1
  char v33; // r3
  int v34; // r2
  unsigned int v35; // r4
  int v36; // r3
  int v37; // r6
  int v38; // r8
  int v39; // r0
  int v40; // r2
  char v41; // r2
  int *v42; // r1
  int v43; // r3
  int v44; // r2
  char v45; // r6
  _DWORD *v46; // r5
  unsigned int *v47; // r6
  int v48; // r8
  unsigned __int8 *v49; // r3
  unsigned int v50; // r1
  unsigned int v51; // r0
  int v52; // r2
  _DWORD *v53; // r1
  int v54; // r3
  int *v55; // r2
  int v56; // r6
  int v57; // r0
  unsigned int v58; // r4
  int v59; // r3
  int v60; // r10
  int v61; // r0
  unsigned int *v62; // r2
  unsigned int v63; // r0
  int v64; // r0
  _BYTE *v65; // r2
  int v66; // r2
  unsigned int v67; // r1
  unsigned int v68; // r2
  int v69; // r1
  int v70; // [sp+18h] [bp-70h]
  char v71[4]; // [sp+1Ch] [bp-6Ch] BYREF
  int v72; // [sp+20h] [bp-68h]
  int v73; // [sp+24h] [bp-64h] BYREF
  unsigned int v74; // [sp+28h] [bp-60h]
  int v75; // [sp+2Ch] [bp-5Ch]
  int v76; // [sp+30h] [bp-58h] BYREF
  int v77; // [sp+34h] [bp-54h]
  char v78[4]; // [sp+38h] [bp-50h] BYREF
  int v79; // [sp+3Ch] [bp-4Ch]
  int v80; // [sp+40h] [bp-48h] BYREF
  int v81; // [sp+44h] [bp-44h]
  int *v82; // [sp+48h] [bp-40h] BYREF
  int v83; // [sp+4Ch] [bp-3Ch]
  int *v84; // [sp+50h] [bp-38h] BYREF
  unsigned int v85; // [sp+54h] [bp-34h]
  unsigned int v86; // [sp+58h] [bp-30h]
  int *v87; // [sp+5Ch] [bp-2Ch]
  int *v88; // [sp+60h] [bp-28h] BYREF
  int v89; // [sp+64h] [bp-24h]
  unsigned __int8 v90; // [sp+68h] [bp-20h]
  unsigned __int8 v91; // [sp+69h] [bp-1Fh]

  v77 = a3;
  v4 = a4;
  v70 = a4;
  v85 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v84 = (int *)(((v85 >> 10) & 0x3FFFFC) - 0x40000000);
  v6 = a2;
  v75 = a1;
  if ( (unsigned int)KeGetCurrentIrql(a1) > 1 )
    return MiRaisedIrqlFault(a1, v6, v4, &v84);
  v87 = 0;
  v81 = 0;
  v82 = 0;
  v74 = 0;
  v80 = 0;
  v86 = 4096;
  v79 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_DWORD *)(v7 + 116);
  v83 = v7;
  for ( i = v6; i >= 0xC0000000; i <<= 10 )
  {
    if ( i > 0xC03FFFFF )
      break;
  }
  if ( v6 >= dword_63389C )
  {
    if ( v77 == 1 )
      return sub_53446C(i, MiSystemPartition);
    v90 = 17;
    v89 = 0;
    v88 = 0;
    v91 = 0;
    v31 = MiSystemFault(a1, v6, v4, i, &v84, &v88);
    v10 = v88;
    v12 = v90;
    v17 = v31;
    v74 = v89;
    v80 = v89;
    v71[0] = v90;
    v79 = v91;
    if ( v31 != 192 )
    {
      if ( v31 != -1073741802 )
      {
        v22 = v83;
        goto LABEL_35;
      }
      v72 = 0;
LABEL_58:
      v17 = MiDispatchFault(v75, v6, v74);
      if ( v17 != -1073741802 )
      {
        v27 = v75;
        v28 = v70;
        goto LABEL_60;
      }
      v40 = v70;
      if ( (v70 & 1) != 0 )
      {
        v65 = (_BYTE *)(v70 & 0xFFFFFFFE);
        if ( *(_BYTE *)(v70 & 0xFFFFFFFE) == 1 )
          goto LABEL_197;
        v40 = v70;
      }
      if ( (v70 & 1) == 0 )
      {
        v41 = v79;
LABEL_128:
        if ( v10 != &dword_634E80 )
        {
          v17 = MiProtoFault((int)v10, v71, v6, v74, v72, v41, &v82);
          if ( v17 != -1073741802 )
          {
            v21 = v82;
            goto LABEL_30;
          }
          v12 = (unsigned __int8)v71[0];
          v10 = &dword_634E80;
          v87 = v82;
        }
        v42 = (int *)(((v74 >> 10) & 0x3FFFFC) - 0x40000000);
        v43 = *v42;
        v6 = v74;
        if ( (*v42 & 2) != 0 )
        {
          if ( (v43 & 0x100) != 0 )
            MiCopyOnWriteEx(v74, v42, -1, v12, 0);
          v17 = 0;
          goto LABEL_22;
        }
        v44 = 0;
        if ( (v43 & 0x400) != 0 )
          v44 = (*v42 & 0x1FC | ((unsigned int)*v42 >> 2) & 0x3FFFFE00) - 0x40000000;
        v45 = v75;
        v28 = v70;
        v17 = MiDispatchFault(v75, v74, v44);
        v27 = v45 | 1;
LABEL_60:
        v29 = v73;
        if ( v73 )
        {
          v30 = *(_DWORD *)(v73 + 144);
          v86 = *(_DWORD *)(v73 + 172);
          if ( v30 )
            v86 = *(_DWORD *)(v30 + 20);
          if ( v77 == 1 )
            *(_BYTE *)(v73 + 115) |= 2u;
          if ( (v27 & 1) != 0 )
            v20 = MiIssueHardFault(v10, v12, v6, v29, v28, 1);
          else
            v20 = MiIssueHardFault(v10, v12, v6, v29, v28, 0);
          goto LABEL_21;
        }
LABEL_22:
        if ( (v70 & 1) != 0 && *(_BYTE *)(v70 & 0xFFFFFFFE) == 3 )
          MiProcessWsInSwapFault(&v84);
        if ( (*((_BYTE *)v10 + 115) & 0x10) != 0 )
        {
          *((_BYTE *)v10 + 115) &= 0xEFu;
          MiAgeWorkingSet(v10, v12, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
        }
        if ( (*((_BYTE *)v10 + 115) & 0x20) != 0 )
        {
          v66 = v10[17];
          *((_BYTE *)v10 + 115) &= 0xDFu;
          MiReduceWs(v10, v12, v66);
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
        }
        else
        {
          __dmb(0xBu);
          *v10 = 0;
        }
        KfLowerIrql(v12);
        v21 = v87;
        goto LABEL_30;
      }
      v65 = (_BYTE *)(v40 & 0xFFFFFFFE);
      if ( *v65 != 2 )
      {
        v41 = v79;
        if ( *(_BYTE *)(v70 & 0xFFFFFFFE) == 5 )
          v70 = 0;
        goto LABEL_128;
      }
LABEL_197:
      v65[1] = 1;
      if ( *v65 == 1 )
        v41 = 1;
      else
        v41 = v79;
      v70 = 0;
      goto LABEL_128;
    }
  }
  v72 = 0;
  v76 = 0;
  v10 = (int *)(v8 + 492);
  if ( *(_DWORD *)(v8 + 628) <= 0x10u )
  {
    if ( !dword_6348E0 )
      goto LABEL_9;
    goto LABEL_162;
  }
  if ( (unsigned __int16)KeNumberNodes <= 1u )
  {
    v11 = dword_640580;
    goto LABEL_7;
  }
  v53 = (_DWORD *)(dword_63F718
                 + 104 * *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266));
  v11 = v53[14] + v53[15] + ((v53[1] + *v53) << 10);
  if ( v11 < 0x100 )
  {
    if ( dword_640680 >= v11 >> 4 )
      v11 = dword_640580;
LABEL_7:
    if ( v11 < 0x100 && ((unsigned int)dword_640680 >= 0x4000 || dword_640680 >= v11 >> 4) )
    {
      v54 = *(char *)(v8 + 104);
      *(_DWORD *)(v8 + 628) = 0;
      if ( v54 >= 9 )
        v55 = Mi30Milliseconds;
      else
        v55 = MiHalfSecond;
      goto LABEL_163;
    }
  }
  if ( !dword_6348E0 )
    goto LABEL_9;
LABEL_162:
  v55 = Mi10Milliseconds;
LABEL_163:
  KeDelayExecutionThread(0, 0, (unsigned int *)v55);
LABEL_9:
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8 + 492);
  }
  else
  {
    v13 = (unsigned __int8 *)(v8 + 495);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v8 + 492));
    while ( 1 )
    {
      v15 = *v10;
      if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v32 = __ldrex((unsigned int *)v10);
        while ( v32 == v15 && __strex(v15 | 0x40000000, (unsigned int *)v10) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v16 = *(unsigned __int8 *)(v8 + 607);
  v71[0] = v12;
  if ( (v16 & 0xFFFFFFC0) == 192 && *(_DWORD *)(v8 + 616) && v6 < dword_63389C )
  {
    v39 = MiLocateAddress(v6);
    v72 = v39;
    if ( !v39 || MiIsVadEligibleForCommitRelease(v39) )
    {
      v17 = -1073741819;
      goto LABEL_22;
    }
    v72 = 0;
    v76 = 0;
  }
  if ( *(_DWORD *)(v8 + 260) && MiWaitForRotateToComplete(v6, v12) == 1 )
  {
    v17 = 0;
    goto LABEL_22;
  }
  v17 = MiResolvePageTablePage(v75, v6, &v84, v70, v12, v77);
  if ( v17 != -1073741802 )
    goto LABEL_22;
  if ( (*v84 & 0x400) != 0 )
  {
    v20 = MiLargePageFault(v75, v6, v70, v77);
    goto LABEL_21;
  }
  v18 = v85;
  v19 = *(_DWORD *)v85;
  v73 = v19;
  if ( (v19 & 2) != 0 )
  {
    v20 = MiValidFault(v75, v6, &v73, v70, v12, v77);
LABEL_21:
    v17 = v20;
    goto LABEL_22;
  }
  if ( v19 == 128 )
  {
    v17 = MiResolveDemandZeroFault(v75 & 1, v6, v70, v85, v10, v12, 0);
    goto LABEL_22;
  }
  if ( v19 )
  {
    v24 = (v19 >> 5) & 0x1F;
    if ( (v19 & 0x400) == 0 )
      goto LABEL_51;
    if ( (v19 & 0xFFFFE000) != -8192 )
    {
      v74 = (v19 & 0x1FC | (v19 >> 2) & 0x3FFFFE00) - 0x40000000;
      if ( (v19 & 0x200) == 0 )
        goto LABEL_58;
      v24 = 1;
      goto LABEL_52;
    }
    v74 = MiCheckVirtualAddress(v6, &v73, &v76);
    if ( !v74 )
    {
      v17 = -1073741819;
      v72 = v76;
      goto LABEL_22;
    }
    v25 = 0;
    goto LABEL_50;
  }
  result = MiZeroFault(v75, v6, v70, v12, v78, &v73, &v80, &v76);
  v17 = result;
  if ( !v78[0] )
  {
    v24 = v73;
    v74 = v80;
    if ( result == -1073741280 )
    {
      v81 = v6;
      v72 = v76;
LABEL_51:
      if ( v24 == 256 )
        goto LABEL_58;
LABEL_52:
      if ( v77 == 1 && (v18 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v18 < 0xC0000000) )
      {
        v38 = -1073741819;
        v17 = -1073741819;
      }
      else
      {
        v26 = *(_DWORD *)v18;
        v73 = v26;
        if ( (v26 & 2) != 0 )
        {
          if ( (v75 & 1) == 0 || (v26 & 0x180) != 0 )
            goto LABEL_58;
          v38 = -1073741819;
          v17 = -1073741819;
        }
        else if ( MiReadWrite[v24 & 7] - ((v75 & 1) != 0) < 10 )
        {
          v38 = -1073741819;
          v17 = -1073741819;
        }
        else
        {
          if ( (v24 & 0xFFFFFFF8) != 16 )
            goto LABEL_58;
          v33 = v70;
          if ( (v70 & 1) != 0 )
          {
            if ( *(_BYTE *)(v70 & 0xFFFFFFFE) == 1 )
              goto LABEL_58;
            v33 = v70;
          }
          if ( MiAllowGuardFault(v33) )
          {
            if ( (v73 & 0x800) == 0 || (v73 & 0x400) != 0 )
            {
              v35 = v73 & 0xFFFFFC1F | (32 * (v24 & 0xF));
              if ( v18 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v18 = v35;
              }
              else
              {
                v36 = *(_DWORD *)v18;
                v37 = 0;
                __dmb(0xBu);
                *(_DWORD *)v18 = v35;
                if ( (v36 & 2) == 0 && (v35 & 2) != 0 )
                  v37 = 1;
                if ( v18 >= 0xC0300000 && v18 <= 0xC0300FFF )
                {
                  v64 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v64, v64 + 4 * (v18 & 0xFFF), v35);
                }
                if ( v37 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
            }
            else
            {
              v56 = MiLockTransitionLeafPage(v18, 0, v34);
              v57 = *(_DWORD *)v18;
              if ( v56 )
                *(_DWORD *)(v56 + 8) = *(_DWORD *)(v56 + 8) & 0xFFFFFC1F | (32 * (v24 & 0xF));
              v58 = v57 & 0xFFFFFC1F | (32 * (v24 & 0xF));
              if ( v18 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v18 = v58;
              }
              else
              {
                v59 = *(_DWORD *)v18;
                v60 = 0;
                __dmb(0xBu);
                *(_DWORD *)v18 = v58;
                if ( (v59 & 2) == 0 && (v58 & 2) != 0 )
                  v60 = 1;
                if ( v18 + 1070596096 <= 0xFFF )
                {
                  v61 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v61, v61 + 4 * (v18 & 0xFFF), v58);
                }
                if ( v60 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              if ( v56 )
              {
                __dmb(0xBu);
                v62 = (unsigned int *)(v56 + 12);
                do
                  v63 = __ldrex(v62);
                while ( __strex(v63 & 0x7FFFFFFF, v62) );
              }
            }
            v38 = -2147483647;
            v17 = -2147483647;
          }
          else
          {
            v38 = -1073741819;
            v17 = -1073741819;
          }
        }
      }
      MiUnlockWorkingSetExclusive(v10, v12);
      if ( v38 == -2147483647 )
        v17 = MiCheckForUserStackOverflow(v6);
      v21 = 0;
LABEL_30:
      v22 = v83;
      if ( v81 )
        MiDeprioritizeVad(v72, v81, v83);
      if ( (v10[28] & 7) != 0 )
      {
        if ( (v10[25] & 0xFFF) == 0 && (unsigned int)dword_640580 < 0x400 )
          goto LABEL_206;
      }
      else if ( *(char *)(v22 + 123) >= 16 && v10[13] - v10[12] > 100 && (unsigned int)dword_640580 < 0x400 )
      {
LABEL_206:
        KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
        goto LABEL_34;
      }
LABEL_34:
      if ( v21 )
      {
        v46 = (_DWORD *)*v21;
        v47 = (unsigned int *)(*v21 + 36);
        v48 = KfRaiseIrql(2);
        v81 = v48;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v47);
        }
        else
        {
          v49 = (unsigned __int8 *)v47 + 3;
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 | 0x80, v49) );
          __dmb(0xBu);
          if ( v50 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v47);
          while ( 1 )
          {
            v51 = *v47;
            if ( (*v47 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v51 & 0x40000000) == 0 )
            {
              do
                v67 = __ldrex(v47);
              while ( v67 == v51 && __strex(v51 | 0x40000000, v47) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
          v48 = v81;
        }
        v52 = v46[7];
        if ( (v52 & 0x20) == 0 && v46[8] && (v52 & 0x400) == 0 )
          MiDecrementSubsections(v21);
        --v46[5];
        MiCheckControlArea(v46, v48);
      }
LABEL_35:
      if ( !v17 )
        return v17;
      if ( v17 != -1073740748 )
      {
        if ( v17 >= 0
          || v17 != -1073741670
          && v17 != -1073741663
          && v17 != -1073741801
          && (v86 <= 0x1000 || FsRtlIsTotalDeviceFailure(v17)) )
        {
          if ( (PerfGlobalGroupMask & 0x1000) != 0 )
          {
            v69 = v70;
            if ( (v70 & 1) != 0 && *(_BYTE *)(v70 & 0xFFFFFFFE) == 1
              || (v70 & 1) != 0
              && (*(_BYTE *)(v70 & 0xFFFFFFFE) == 2
               || *(_BYTE *)(v70 & 0xFFFFFFFE) == 4
               || *(_BYTE *)(v70 & 0xFFFFFFFE) == 3) )
            {
              v69 = 0;
            }
            EtwTracePageFault(v17, v6, v77, v69);
          }
          return v17;
        }
        if ( (*(_BYTE *)(v22 + 968) & 4) != 0 )
          return -1073741801;
        KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
        v68 = dword_640580;
        if ( (unsigned int)dword_640580 < 0x80
          && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v68 < 2) )
        {
          MiWaitForFreePage(MiSystemPartition);
        }
      }
      return 0;
    }
    v25 = v76;
LABEL_50:
    v72 = v25;
    goto LABEL_51;
  }
  if ( v78[0] == 1 )
  {
    v72 = v76;
    goto LABEL_22;
  }
  return result;
}
