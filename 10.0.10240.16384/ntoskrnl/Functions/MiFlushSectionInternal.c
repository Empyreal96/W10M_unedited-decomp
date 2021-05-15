// MiFlushSectionInternal 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiFlushSectionInternal(int a1, int a2, _DWORD *a3, int a4, int a5, unsigned int a6, _DWORD *a7)
{
  signed int v7; // r9
  int v9; // r4
  int result; // r0
  _DWORD *v11; // r7 OVERLAPPED
  int v12; // r3
  char *v13; // r6
  unsigned int v14; // r8
  unsigned int v15; // r3
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r5
  unsigned int v19; // r9
  int v20; // r4
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int *v23; // r1
  unsigned int v24; // r0
  int v25; // r8
  int v26; // r2
  unsigned int v27; // r7
  int v28; // r8
  int v29; // r3
  int v30; // r2
  unsigned int v31; // r4
  int v32; // r6
  unsigned __int8 *v33; // r1
  unsigned int v34; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r0
  bool v37; // cf
  int v38; // r7
  unsigned __int8 *v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r0
  _DWORD *v42; // r8
  int v43; // r3
  int v44; // r5
  int v45; // r4
  int v46; // r6
  int v47; // r0
  int v48; // r8
  __int16 v49; // r3
  int v50; // r1
  int v51; // r4
  unsigned int v52; // r6
  int v53; // r3
  int v54; // r5
  int v55; // r4
  int v56; // r2
  char v57; // r4
  int v58; // r1
  char v59; // r2
  int v60; // r0
  int v61; // r1
  int v62; // r4
  int v63; // r3
  int v64; // r0
  int v65; // r1
  unsigned int *v66; // r10
  unsigned int v67; // r1
  unsigned int *v68; // r7
  unsigned int v69; // r1
  unsigned __int8 *v70; // r1
  int v71; // r3
  unsigned int v72; // r2
  unsigned int *v73; // r2
  unsigned int v74; // r0
  _DWORD *v75; // r3
  int v76; // r0
  __int16 v77; // r3
  _DWORD *v78; // r3
  int v79; // r0
  int v80; // r1
  int v81; // r0
  unsigned int *v82; // r2
  unsigned int v83; // r0
  unsigned int *v84; // r2
  unsigned int v85; // r0
  int v86; // r4
  int v87; // r3
  int v88; // r3
  int v89; // r0
  int v90; // r2
  unsigned int *v91; // r2
  unsigned int v92; // r0
  int v93; // r0
  char v94[4]; // [sp+10h] [bp-F0h] BYREF
  char *v95; // [sp+14h] [bp-ECh]
  int v96; // [sp+18h] [bp-E8h]
  unsigned int *v97; // [sp+1Ch] [bp-E4h]
  int v98; // [sp+20h] [bp-E0h]
  int v99; // [sp+24h] [bp-DCh]
  int v100; // [sp+28h] [bp-D8h] BYREF
  _DWORD *v101; // [sp+2Ch] [bp-D4h]
  unsigned int v102; // [sp+30h] [bp-D0h]
  _DWORD *v103; // [sp+34h] [bp-CCh]
  _DWORD *v104; // [sp+38h] [bp-C8h]
  int v105; // [sp+3Ch] [bp-C4h]
  int v106; // [sp+40h] [bp-C0h]
  int v107; // [sp+44h] [bp-BCh]
  _DWORD *v108; // [sp+48h] [bp-B8h]
  int v109; // [sp+4Ch] [bp-B4h]
  int v110; // [sp+50h] [bp-B0h]
  int v111; // [sp+54h] [bp-ACh]
  int v112; // [sp+58h] [bp-A8h]
  int v113; // [sp+5Ch] [bp-A4h]
  int v114; // [sp+60h] [bp-A0h]
  _DWORD *v115; // [sp+64h] [bp-9Ch]
  int v116; // [sp+68h] [bp-98h] BYREF
  int v117; // [sp+6Ch] [bp-94h]
  int v118; // [sp+70h] [bp-90h] BYREF
  int v119; // [sp+74h] [bp-8Ch]
  int v120; // [sp+78h] [bp-88h]
  unsigned __int8 *v121; // [sp+7Ch] [bp-84h]
  char var80[132]; // [sp+80h] [bp-80h] BYREF

  v7 = a6;
  v9 = 0;
  if ( (a6 & 2) == 0 )
    v9 = 2;
  v113 = a2;
  v114 = a1;
  v108 = (_DWORD *)a4;
  v115 = a3;
  v110 = a5;
  v101 = a7;
  v102 = a6;
  if ( a5 )
    return sub_5339EC(a1, 4);
  v11 = (_DWORD *)*a3;
  v109 = 0;
  v107 = 0;
  v12 = v11[7];
  v13 = var80;
  v95 = var80;
  v103 = v11;
  if ( (v12 & 0x40000000) != 0 )
  {
    v7 = a6 & 0xFFFFFFFB;
    v102 = a6 & 0xFFFFFFFB;
  }
  if ( (v7 & 4) != 0 )
  {
    v81 = ExAllocatePoolWithTag(512, 1344, 1632005453);
    v109 = v81;
    if ( v81 )
    {
      *(_BYTE *)(v81 + 26) = 4;
      *(_BYTE *)(v81 + 24) = 0;
      *(_BYTE *)(v81 + 25) = 0;
      *(_DWORD *)(v81 + 28) = 0;
      v13 = (char *)(v81 + 44);
      *(_DWORD *)(v81 + 32) = v81 + 32;
      *(_DWORD *)(v81 + 36) = v81 + 32;
      *(_DWORD *)v81 = 0;
      *(_DWORD *)(v81 + 8) = 0;
      *(_QWORD *)(v81 + 16) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 40) = v81 + 44;
      *(_DWORD *)(v81 + 1120) = v81 + 24;
      *(_BYTE *)(v81 + 164) = 0;
      *(_BYTE *)(v81 + 165) = 0;
      *(_BYTE *)(v81 + 166) = 4;
      *(_DWORD *)(v81 + 168) = 0;
      *(_DWORD *)(v81 + 172) = v81 + 172;
      *(_DWORD *)(v81 + 176) = v81 + 172;
      *(_DWORD *)(v81 + 180) = v81 + 184;
      *(_DWORD *)(v81 + 140) = 0;
      *(_DWORD *)(v81 + 148) = 0;
      *(_QWORD *)(v81 + 156) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1124) = v81 + 164;
      *(_BYTE *)(v81 + 304) = 0;
      *(_BYTE *)(v81 + 305) = 0;
      *(_BYTE *)(v81 + 306) = 4;
      *(_DWORD *)(v81 + 308) = 0;
      *(_DWORD *)(v81 + 312) = v81 + 312;
      *(_DWORD *)(v81 + 316) = v81 + 312;
      *(_DWORD *)(v81 + 320) = v81 + 324;
      *(_DWORD *)(v81 + 280) = 0;
      *(_DWORD *)(v81 + 288) = 0;
      *(_QWORD *)(v81 + 296) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1128) = v81 + 304;
      *(_BYTE *)(v81 + 444) = 0;
      *(_BYTE *)(v81 + 445) = 0;
      *(_BYTE *)(v81 + 446) = 4;
      *(_DWORD *)(v81 + 448) = 0;
      *(_DWORD *)(v81 + 452) = v81 + 452;
      *(_DWORD *)(v81 + 456) = v81 + 452;
      *(_DWORD *)(v81 + 460) = v81 + 464;
      *(_DWORD *)(v81 + 420) = 0;
      *(_DWORD *)(v81 + 428) = 0;
      *(_QWORD *)(v81 + 436) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1132) = v81 + 444;
      *(_BYTE *)(v81 + 584) = 0;
      *(_BYTE *)(v81 + 585) = 0;
      *(_BYTE *)(v81 + 586) = 4;
      *(_DWORD *)(v81 + 588) = 0;
      *(_DWORD *)(v81 + 592) = v81 + 592;
      *(_DWORD *)(v81 + 596) = v81 + 592;
      *(_DWORD *)(v81 + 600) = v81 + 604;
      *(_DWORD *)(v81 + 560) = 0;
      *(_DWORD *)(v81 + 568) = 0;
      *(_QWORD *)(v81 + 576) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1136) = v81 + 584;
      *(_BYTE *)(v81 + 724) = 0;
      v107 = v81;
      v95 = (char *)(v81 + 44);
      *(_BYTE *)(v81 + 725) = 0;
      *(_BYTE *)(v81 + 726) = 4;
      *(_DWORD *)(v81 + 728) = 0;
      *(_DWORD *)(v81 + 732) = v81 + 732;
      *(_DWORD *)(v81 + 736) = v81 + 732;
      *(_DWORD *)(v81 + 740) = v81 + 744;
      *(_DWORD *)(v81 + 700) = 0;
      *(_DWORD *)(v81 + 708) = 0;
      *(_QWORD *)(v81 + 716) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1140) = v81 + 724;
      *(_BYTE *)(v81 + 864) = 0;
      *(_BYTE *)(v81 + 865) = 0;
      *(_BYTE *)(v81 + 866) = 4;
      *(_DWORD *)(v81 + 868) = 0;
      *(_DWORD *)(v81 + 872) = v81 + 872;
      *(_DWORD *)(v81 + 876) = v81 + 872;
      *(_DWORD *)(v81 + 880) = v81 + 884;
      *(_DWORD *)(v81 + 840) = 0;
      *(_DWORD *)(v81 + 848) = 0;
      *(_QWORD *)(v81 + 856) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1144) = v81 + 864;
      *(_BYTE *)(v81 + 1004) = 0;
      *(_BYTE *)(v81 + 1005) = 0;
      *(_BYTE *)(v81 + 1006) = 4;
      *(_DWORD *)(v81 + 1008) = 0;
      *(_DWORD *)(v81 + 1012) = v81 + 1012;
      *(_DWORD *)(v81 + 1016) = v81 + 1012;
      *(_DWORD *)(v81 + 1020) = v81 + 1024;
      *(_DWORD *)(v81 + 980) = 0;
      *(_DWORD *)(v81 + 988) = 0;
      *(_QWORD *)(v81 + 996) = *(_QWORD *)(&a5 - 1);
      *(_DWORD *)(v81 + 1148) = v81 + 1004;
    }
  }
  v105 = MI_REFERENCE_CONTROL_AREA_FILE(v11);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_DWORD *)(v14 + 0x3C0);
  v120 = v14;
  v16 = (v15 >> 9) & 7;
  v17 = *(_DWORD *)(v14 + 336);
  v112 = v16;
  if ( (*(_DWORD *)(v17 + 192) & 0x100000) != 0 )
  {
    v16 = 0;
    v112 = 0;
  }
  if ( v16 < 2 && v14 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(v14 + 1000) )
  {
    v16 = 2;
    v112 = 2;
  }
  if ( v16 < 2
    && (*(_DWORD *)(v14 + 76) & 0x400) == 0
    && *(_BYTE *)(v14 + 346) != 1
    && *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) != 2 )
  {
    v112 = 2;
  }
  if ( v7 < 0 )
    v9 |= 0x10u;
  v99 = 16;
  v100 = 16;
  v111 = 1;
  *a7 = 0;
  a7[1] = 0;
  *(_DWORD *)v13 = 0;
  *((_WORD *)v13 + 3) = 0;
  *((_DWORD *)v13 + 4) = 0;
  *((_DWORD *)v13 + 5) = 0;
  *((_DWORD *)v13 + 6) = 0;
  v98 = 0;
  v18 = v114;
  v116 = 0;
  v104 = v115;
  v19 = v9 & 0xFFFFFFF3;
  --*(_WORD *)(v14 + 308);
  v97 = v11 + 9;
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11 + 9);
    v23 = v11 + 9;
  }
  else
  {
    v21 = (unsigned __int8 *)v11 + 39;
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 | 0x80, v21) );
    __dmb(0xBu);
    if ( v22 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v11 + 9);
    v23 = v11 + 9;
    while ( 1 )
    {
      v24 = *v23;
      if ( (*v23 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v24 & 0x40000000) == 0 )
      {
        v66 = v11 + 9;
        do
          v67 = __ldrex(v66);
        while ( v67 == v24 && __strex(v24 | 0x40000000, v66) );
        __dmb(0xBu);
        v23 = v11 + 9;
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( !v11[4] )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v11 + 9);
    }
    else
    {
      __dmb(0xBu);
      *v23 = 0;
    }
    KfLowerIrql(v20);
    if ( v109 )
    {
      ExFreePoolWithTag(v109, 0);
      if ( v110 )
        *(_DWORD *)(v110 + 24) = 0;
    }
    v76 = MI_DEREFERENCE_CONTROL_AREA_FILE(v11, v105);
    v77 = *(_WORD *)(v14 + 308) + 1;
    *(_WORD *)(v14 + 308) = v77;
    if ( !v77 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v76);
    v78 = v101;
    result = 0;
    *v101 = 0;
    v78[1] = 0;
    return result;
  }
  v117 = 0;
  v25 = (int)v104;
  v26 = (int)v108;
  v121 = (unsigned __int8 *)v23 + 3;
  while ( 2 )
  {
    while ( 2 )
    {
      if ( v25 == v26 )
      {
        v27 = v113 + 4;
      }
      else
      {
        v27 = *(_DWORD *)(v25 + 4) + 4 * *(_DWORD *)(v25 + 28);
        v26 = (int)v108;
      }
      if ( !v18 )
        v18 = *(_DWORD *)(v25 + 4);
      if ( *(_DWORD *)(v25 + 64) && *(_DWORD *)(v25 + 4) )
      {
        ++*(_DWORD *)(v25 + 60);
        if ( (*(_WORD *)(v25 + 18) & 8) != 0 )
        {
          MiRemoveUnusedSubsection(v25);
          v23 = v97;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v97);
        }
        else
        {
          __dmb(0xBu);
          *v23 = 0;
        }
        KfLowerIrql(v20);
        v28 = 17;
        v29 = v18;
        v30 = 0;
        v94[0] = 17;
        v106 = v18;
        v96 = 0;
        if ( v18 >= v27 )
          goto LABEL_56;
        while ( 1 )
        {
          if ( v28 == 17 || (v18 & 0xFFF) == 0 )
          {
            if ( v28 != 17 )
              MiUnlockProtoPoolPage(v30, v28);
            v56 = MiCheckProtoPtePageState(v18, v94);
            v28 = (unsigned __int8)v94[0];
            v96 = v56;
            if ( !v56 )
              break;
          }
          while ( 1 )
          {
            do
            {
              v31 = *(_DWORD *)v18;
              if ( (*(_DWORD *)v18 & 2) == 0 && ((v31 & 0x400) != 0 || (v31 & 0x800) == 0) )
                goto LABEL_49;
            }
            while ( !MI_IS_PFN(v31 >> 12) );
            v32 = MmPfnDatabase + 24 * (v31 >> 12);
            v33 = (unsigned __int8 *)(v32 + 15);
            do
              v34 = __ldrex(v33);
            while ( __strex(v34 | 0x80, v33) );
            __dmb(0xBu);
            if ( v34 >> 7 )
            {
              v70 = (unsigned __int8 *)(v32 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v71 = *(_DWORD *)(v32 + 12);
                  __dmb(0xBu);
                }
                while ( (v71 & 0x80000000) != 0 );
                do
                  v72 = __ldrex(v70);
                while ( __strex(v72 | 0x80, v70) );
                __dmb(0xBu);
              }
              while ( v72 >> 7 );
            }
            if ( *(_DWORD *)v18 == v31 )
              break;
            __dmb(0xBu);
            v82 = (unsigned int *)(v32 + 12);
            do
              v83 = __ldrex(v82);
            while ( __strex(v83 & 0x7FFFFFFF, v82) );
          }
          if ( !v32 )
            goto LABEL_49;
          if ( (*(_BYTE *)(v32 + 18) & 8) != 0 )
          {
            if ( *((_DWORD *)v95 + 5) )
            {
              __dmb(0xBu);
              v73 = (unsigned int *)(v32 + 12);
              do
                v74 = __ldrex(v73);
              while ( __strex(v74 & 0x7FFFFFFF, v73) );
              v13 = v95;
              goto LABEL_100;
            }
            if ( (v19 & 2) == 0 )
            {
              __dmb(0xBu);
              v91 = (unsigned int *)(v32 + 12);
              do
                v92 = __ldrex(v91);
              while ( __strex(v92 & 0x7FFFFFFF, v91) );
              v13 = v95;
              v19 |= 8u;
              goto LABEL_209;
            }
            MiWaitForPageWriteCompletion(v32, v103, v96, v28);
            v28 = 17;
            v94[0] = 17;
            goto LABEL_111;
          }
          if ( (*(_BYTE *)(v32 + 18) & 0x10) == 0 )
          {
            __dmb(0xBu);
            v35 = (unsigned int *)(v32 + 12);
            do
              v36 = __ldrex(v35);
            while ( __strex(v36 & 0x7FFFFFFF, v35) );
LABEL_49:
            v13 = v95;
            if ( *((_DWORD *)v95 + 5) )
              v19 |= 4u;
LABEL_51:
            v18 += 4;
            if ( (v19 & 4) != 0 )
              goto LABEL_100;
            v37 = v18 >= v27;
            if ( v18 != v27 )
              goto LABEL_53;
            if ( *((_DWORD *)v13 + 5) )
              goto LABEL_100;
LABEL_111:
            v37 = v18 >= v27;
            goto LABEL_53;
          }
          if ( (*(_BYTE *)(v32 + 18) & 0x20) != 0 )
          {
            if ( *((_DWORD *)v95 + 5) )
            {
              __dmb(0xBu);
              v84 = (unsigned int *)(v32 + 12);
              do
                v85 = __ldrex(v84);
              while ( __strex(v85 & 0x7FFFFFFF, v84) );
              v13 = v95;
              goto LABEL_100;
            }
            v86 = v96;
            v118 = 1;
            MiObtainProtoReference(v96, 1);
            MiWaitForCollidedFaultComplete(v32, v86, 0, 0, 17, v28, &v118);
            v28 = 17;
            v94[0] = 17;
            goto LABEL_111;
          }
          v50 = v32;
          v13 = v95;
          v51 = MiAddPageToFlushMdl(v95, v50, v103, v99, *(_DWORD *)v18);
          if ( v51 < 1 )
            goto LABEL_51;
          MiUnlockProtoPoolPage(v96, v28);
          v28 = 17;
          v94[0] = 17;
          if ( v51 == 3 )
            goto LABEL_100;
          if ( v51 == 2 )
          {
            v18 += 4;
            goto LABEL_100;
          }
          if ( v99 == 1 )
            goto LABEL_126;
          v52 = v18 + 4;
          if ( v18 + 4 >= v27 )
          {
            v13 = v95;
LABEL_126:
            v18 += 4;
LABEL_100:
            v56 = v96;
            goto LABEL_101;
          }
          v53 = v27 - v18;
          v54 = (int)v95;
          v55 = MiExpandFlushMdl((int)v95, v99 + (v53 >> 2) - 1);
          if ( !v55 )
          {
            v87 = *(_DWORD *)(v54 + 24);
            v18 = v52;
            v13 = v95;
            v99 = v87;
            v100 = v87;
            goto LABEL_100;
          }
          if ( (char *)v54 != var80 && (!v107 || v54 != v107 + 44) )
            ExFreePoolWithTag(v54, 0);
          v95 = (char *)v55;
          if ( v107 )
            *(_DWORD *)(v107 + 40) = v55;
          v18 = v52;
          v37 = v52 >= v27;
          v99 = *(_DWORD *)(v55 + 24);
          v100 = v99;
LABEL_53:
          v13 = v95;
          v30 = v96;
          if ( v37 )
            goto LABEL_55;
        }
        v18 = (v18 & 0xFFFFF000) + 4096;
        if ( !*((_DWORD *)v13 + 5) )
          goto LABEL_111;
LABEL_101:
        if ( v28 != 17 )
        {
          MiUnlockProtoPoolPage(v56, v28);
          v28 = 17;
          v94[0] = 17;
        }
        v57 = v102;
        v58 = (int)v104;
        v59 = v102;
        *((_DWORD *)v13 + 5) <<= 12;
        v19 &= 0xFFFFFFFB;
        v60 = MiReadyFlushMdlToWrite((int)v13, v58, v59);
        if ( v107 )
        {
          if ( (v57 & 0x10) != 0 )
            v88 = 4;
          else
            v88 = 0;
          v89 = MiIssueAsynchronousFlush(v105, v107, v109, v110, v60, v61, v88, v112);
          v107 = v89;
          if ( !v89 )
          {
            v111 = 0;
            v19 |= 1u;
LABEL_209:
            v18 = v27;
LABEL_210:
            v30 = v96;
LABEL_55:
            v29 = v106;
LABEL_56:
            if ( v28 != 17 )
            {
              MiUnlockProtoPoolPage(v30, v28);
              v29 = v106;
            }
            v38 = v98 + ((int)(v18 - v29) >> 2 << 12);
            v98 = v38;
            v20 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v97);
              v23 = v97;
            }
            else
            {
              v39 = v121;
              do
                v40 = __ldrex(v39);
              while ( __strex(v40 | 0x80, v39) );
              __dmb(0xBu);
              if ( v40 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire(v97);
              v23 = v97;
              while ( 1 )
              {
                v41 = *v23;
                if ( (*v23 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (v41 & 0x40000000) == 0 )
                {
                  v68 = v97;
                  do
                    v69 = __ldrex(v68);
                  while ( v69 == v41 && __strex(v41 | 0x40000000, v68) );
                  __dmb(0xBu);
                  v23 = v68;
                }
                __dmb(0xAu);
                __yield();
              }
              v38 = v98;
            }
            v42 = v104;
            if ( !v104[2] && v18 == v104[1] + 4 * v104[7] )
            {
              v64 = MiEndingOffset(v104) & 0xFFF;
              v119 = v65;
              v23 = v97;
              if ( v64 )
                v98 = v64 + v38 - 4096;
            }
            v43 = v42[15] - 1;
            v42[15] = v43;
            if ( !v43 && (*((_WORD *)v42 + 9) & 1) == 0 )
            {
              v93 = MiInsertUnusedSubsection(v42, 1);
              v23 = v97;
              v117 += v93;
            }
            if ( (v19 & 8) != 0
              || !v111
              || (v26 = (int)v108, v42 == v108)
              || (v25 = v42[2], (v104 = (_DWORD *)v25) == 0) )
            {
              v44 = v98;
              goto LABEL_72;
            }
            v18 = *(_DWORD *)(v25 + 4);
            continue;
          }
          v13 = *(char **)(v89 + 40);
          v99 = 16;
          v100 = 16;
        }
        else
        {
          v62 = *(_DWORD *)(MmPfnDatabase + 24 * *((_DWORD *)v13 + 7) + 4);
          if ( (v103[7] & 0x40000000) != 0 )
          {
            if ( (v102 & 0x10) != 0 )
              v90 = 4;
            else
              v90 = 0;
            MiFlushFileOnlyMdl(v105, v13, v90, v101);
          }
          else
          {
            if ( (v102 & 0x10) != 0 )
              v63 = 4;
            else
              v63 = 0;
            MiIssueSynchronousFlush(v105, (int)v13, v60, v61, v63, v101);
          }
          MiUnlockFlushMdl((int)v13, (int)v103, (int)v101);
          if ( (int)*v101 < 0 )
          {
            v18 = v62 | 0x80000000;
            v111 = MiHandleSynchronousFlushError(v13, v101, (v19 >> 4) & 1, &v116, &v100);
            if ( v13 == var80 )
            {
              v99 = v100;
            }
            else
            {
              v99 = v100;
              if ( v100 != 1 )
              {
                v99 = 16;
                v100 = 16;
              }
              ExFreePoolWithTag(v13, 0);
              v13 = var80;
              v95 = var80;
            }
            *((_DWORD *)v13 + 5) = 0;
            if ( !v111 )
              goto LABEL_210;
            goto LABEL_111;
          }
          v116 = 0;
          if ( v13 == var80 )
            goto LABEL_110;
          v99 = 16;
          v100 = 16;
          ExFreePoolWithTag(v13, 0);
          v13 = var80;
        }
        v95 = v13;
LABEL_110:
        *((_DWORD *)v13 + 5) = 0;
        goto LABEL_111;
      }
      break;
    }
    v44 = v98 + ((int)(v27 - v18) >> 2 << 12);
    v75 = *(_DWORD **)(v25 + 8);
    v98 = v44;
    if ( v75 )
    {
      if ( v26 == v25 )
        goto LABEL_72;
      v18 = v75[1];
      v25 = (int)v75;
      v104 = v75;
      continue;
    }
    break;
  }
  if ( v27 == *(_DWORD *)(v25 + 4) + 4 * *(_DWORD *)(v25 + 28) )
  {
    v79 = MiEndingOffset(v25) & 0xFFF;
    v119 = v80;
    v23 = v97;
    if ( v79 )
      v44 = v79 + v44 - 4096;
  }
LABEL_72:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v97);
  }
  else
  {
    __dmb(0xBu);
    *v23 = 0;
  }
  KfLowerIrql(v20);
  v45 = v109;
  v46 = v110;
  if ( v109 && !v110 )
  {
    if ( MiWaitForAsynchronousFlushes(v109) < 0 )
      LOBYTE(v19) = v19 | 1;
    ExFreePoolWithTag(v45, 0);
  }
  v47 = MI_DEREFERENCE_CONTROL_AREA_FILE(v103, v105);
  v48 = v120;
  v49 = *(_WORD *)(v120 + 308) + 1;
  *(_WORD *)(v120 + 308) = v49;
  if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
    KiCheckForKernelApcDelivery(v47);
  if ( (v19 & 1) != 0 )
    return MiFlushSectionInternal(v114, v113, v115, v108, v46, v102 & 0xFFFFFFFB, v101);
  if ( (v19 & 8) != 0 )
    *v101 = -1073740749;
  result = *v101;
  v101[1] = v44;
  return result;
}
