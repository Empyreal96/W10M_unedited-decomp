// NtSetInformationFile 
 
int __fastcall NtSetInformationFile(int a1, _DWORD *a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int v7; // r0
  int v8; // r8
  _DWORD *v9; // r2
  int v10; // r10
  int v11; // r9
  _DWORD *v12; // r5
  _DWORD *v13; // r3
  int v14; // r0
  int v15; // r4
  int v16; // r0
  int v17; // lr
  int v18; // r3
  unsigned int *v19; // r1
  unsigned int v20; // r2
  unsigned int *v21; // r0
  unsigned int v22; // r2
  signed int v23; // r2
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r4
  unsigned int v27; // r2
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  int v31; // r1
  int v32; // r2
  _DWORD *v33; // r6
  unsigned __int64 *v34; // r0
  unsigned __int64 v35; // r2
  unsigned __int64 *v36; // r2
  unsigned __int64 v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r1
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  int v43; // lr
  unsigned __int8 *v44; // r0
  unsigned int v45; // r2
  unsigned int v46; // r2
  unsigned int v47; // r1
  int v48; // r8
  int v49; // r0
  int *v50; // r3
  unsigned int *v51; // r2
  unsigned int v52; // r1
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  int v56; // r0
  int v57; // r6
  int v58; // r2
  int v59; // r3
  unsigned int v60; // r4
  int v61; // r3
  int v62; // r3
  int v63; // r2
  unsigned __int64 *v64; // r0
  unsigned __int64 v65; // r2
  unsigned int *v66; // r1
  unsigned int v67; // r0
  int *v68; // r0
  int v69; // r1
  int v70; // r3
  int v71; // r3
  unsigned int v72; // r3
  unsigned int v73; // r3
  int v74; // r1
  int v75; // r8
  int v76; // r1
  unsigned int v77; // r2
  unsigned int v78; // r3
  _DWORD *v79; // r1
  int v80; // r2
  int v81; // r0
  int v82; // r2
  _WORD *v83; // r3
  _DWORD *v85; // r2
  int v86; // r1
  unsigned int v87; // r2
  unsigned int v88; // r3
  _DWORD *v89; // r2
  int v90; // r1
  int v91; // r0
  int v92; // r2
  int *v93; // r1
  _DWORD *v94; // r4
  unsigned int *v95; // r8
  int v96; // r9
  unsigned int v97; // r2
  _DWORD *v98; // r8
  int v99; // r4
  _DWORD *v100; // r0
  int v101; // r4
  int v102; // r4
  int *v103; // r4
  int v104; // r1
  unsigned int v105; // r2
  unsigned int v106; // r3
  _DWORD *v107; // r2
  int v108; // r1
  int v109; // r0
  int v110; // r2
  int v111; // lr
  unsigned int v112; // r2
  int v113; // r2
  int v114; // r1
  unsigned int v115; // r2
  unsigned int v116; // r3
  _DWORD *v117; // r1
  int v118; // r2
  int v119; // r0
  int v120; // r2
  int v121; // r0
  int v122; // r1
  unsigned int v123; // r2
  unsigned int v124; // r3
  _DWORD *v125; // r1
  int v126; // r2
  int v127; // r0
  int v128; // r2
  _WORD *v129; // r3
  _DWORD *v131; // r2
  BOOL v132; // r4
  char v133; // r3
  int v134; // r0
  int v135; // r0
  unsigned int *v136; // r2
  unsigned int v137; // r1
  int v138; // r0
  unsigned int v139; // r1
  int v140; // r3
  int v141; // r0
  _DWORD *v142; // r2
  int v143; // r3
  int v144; // r4
  unsigned int *v145; // r2
  unsigned int v146; // r1
  unsigned int v147; // r1
  __int16 v148; // r3
  int *v150; // [sp+8h] [bp-B0h] BYREF
  int v151; // [sp+Ch] [bp-ACh]
  int v152; // [sp+10h] [bp-A8h]
  char v153; // [sp+14h] [bp-A4h] BYREF
  char v154; // [sp+15h] [bp-A3h]
  char v155; // [sp+16h] [bp-A2h]
  int v156; // [sp+18h] [bp-A0h]
  int *v157; // [sp+1Ch] [bp-9Ch] BYREF
  int v158; // [sp+20h] [bp-98h]
  char v159; // [sp+24h] [bp-94h]
  unsigned int v160; // [sp+28h] [bp-90h]
  unsigned int v161; // [sp+30h] [bp-88h] BYREF
  unsigned int v162; // [sp+34h] [bp-84h]
  int v163; // [sp+38h] [bp-80h] BYREF
  _DWORD *v164; // [sp+3Ch] [bp-7Ch] BYREF
  _DWORD *v165; // [sp+40h] [bp-78h]
  int v166; // [sp+44h] [bp-74h]
  int v167; // [sp+48h] [bp-70h] BYREF
  int v168; // [sp+4Ch] [bp-6Ch]
  int v169; // [sp+50h] [bp-68h]
  BOOL v170; // [sp+54h] [bp-64h]
  _DWORD *v171; // [sp+58h] [bp-60h]
  _DWORD v172[2]; // [sp+60h] [bp-58h] BYREF
  int v173; // [sp+68h] [bp-50h] BYREF
  int v174; // [sp+6Ch] [bp-4Ch]
  _BYTE v175[4]; // [sp+70h] [bp-48h] BYREF
  int v176; // [sp+74h] [bp-44h]
  _DWORD v177[2]; // [sp+78h] [bp-40h] BYREF
  int v178; // [sp+80h] [bp-38h]
  int v179; // [sp+88h] [bp-30h] BYREF
  int v180; // [sp+8Ch] [bp-2Ch]
  int v181; // [sp+90h] [bp-28h]
  int v182; // [sp+94h] [bp-24h]
  int vars4; // [sp+BCh] [bp+4h]
  int varg_r0; // [sp+C0h] [bp+8h]
  _DWORD *varg_r1; // [sp+C4h] [bp+Ch]
  unsigned int varg_r2; // [sp+C8h] [bp+10h]
  unsigned int varg_r3; // [sp+CCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v162 = a4;
  varg_r3 = a4;
  v178 = a3;
  v165 = a2;
  v163 = a1;
  v170 = a1;
  v171 = a2;
  v164 = (_DWORD *)a3;
  v173 = 0;
  v174 = 0;
  v166 = 0;
  v167 = 0;
  v158 = 0;
  v154 = 0;
  v169 = 0;
  v155 = 0;
  v160 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v161 = v160;
  v7 = *(char *)(v160 + 0x15A);
  v151 = v7;
  v159 = v7;
  v8 = a5;
  if ( !v7 )
  {
    if ( a5 == 56 )
    {
      v8 = 10;
    }
    else
    {
      if ( a5 != 57 )
        goto LABEL_20;
      v8 = 11;
    }
    v155 = 1;
    v169 = 1;
    goto LABEL_20;
  }
  if ( a5 >= 0x40 || !*((_BYTE *)&IopSetOperationLength + a5) )
    return -1073741821;
  if ( a4 < *((unsigned __int8 *)&IopSetOperationLength + a5) )
    return -1073741820;
  v9 = a2;
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    v9 = (_DWORD *)MmUserProbeAddress;
  *v9 = *v9;
  if ( a4 )
  {
    if ( ((*((unsigned __int8 *)IopQuerySetAlignmentRequirement + a5) - 1) & a3) != 0 )
      ExRaiseDatatypeMisalignment();
    if ( a3 + a4 > MmUserProbeAddress || a3 + a4 < a3 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
LABEL_20:
  v11 = ObReferenceObjectByHandle(a1, IopSetOperationAccess[v8], IoFileObjectType, v7, &v164, 0);
  v12 = v164;
  v172[0] = v164;
  if ( v11 >= 0 )
  {
    v13 = (_DWORD *)v164[31];
    if ( v13 )
    {
      if ( (*v13 & 4) != 0 )
      {
        v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v161 = 0;
        v15 = PsReferencePrimaryToken(v14);
        SeQueryInformationToken(v15, 29, &v161);
        ObfDereferenceObjectWithTag(v15, 1953261124);
        if ( v161 )
        {
          ObfDereferenceObjectWithTag(v12, 1953261124);
          v11 = -1073739504;
        }
      }
    }
  }
  v168 = v11;
  if ( v11 < 0 )
    return v11;
  if ( (v12[11] & 0x800) != 0 )
    v16 = IoGetAttachedDevice(v12[1]);
  else
    v16 = IoGetRelatedDeviceObject(v12);
  v17 = v16;
  v161 = v16;
  v156 = v16;
  if ( (v12[11] & 2) != 0 )
  {
    v18 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v18 & 0xFFFFFFC0) + 0x134);
    __dmb(0xBu);
    v19 = v12 + 17;
    do
      v20 = __ldrex(v19);
    while ( __strex(1u, v19) );
    __dmb(0xBu);
    if ( v20 )
    {
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(1);
      v11 = IopAcquireFileObjectLock(v12, v151, (v12[11] & 4) != 0, &v153);
      v168 = v11;
      if ( v153 )
      {
LABEL_75:
        ObfDereferenceObject(v12);
        return v11;
      }
      v19 = v12 + 17;
      v17 = v156;
    }
    else
    {
      v21 = v12 - 6;
      if ( ObpTraceFlags )
      {
        ObpPushStackInfo(v21, 1, 1, 1953261124);
        v21 = v12 - 6;
        v19 = v12 + 17;
        v17 = v156;
      }
      do
      {
        v22 = __ldrex(v21);
        v23 = v22 + 1;
      }
      while ( __strex(v23, v21) );
      __dmb(0xBu);
      if ( v23 <= 1 )
        KeBugCheckEx(24, 0, v21 + 6);
    }
    if ( v8 == 14 )
    {
      v26 = v162;
      if ( v162 < 8 )
      {
        __dmb(0xBu);
        do
          v27 = __ldrex(v19);
        while ( __strex(0, v19) );
        __dmb(0xBu);
        if ( v12[16] )
          KeSetEvent(v12 + 19, 0, 0);
        v28 = ObfDereferenceObject(v12);
        v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v30 = *(_WORD *)(v29 + 0x134) + 1;
        *(_WORD *)(v29 + 308) = v30;
        if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
          KiCheckForKernelApcDelivery(v28);
        ObfDereferenceObject(v12);
        return -1073741820;
      }
      v31 = *(_DWORD *)a3;
      v32 = *(_DWORD *)(a3 + 4);
      v172[0] = *(_DWORD *)a3;
      v172[1] = v32;
      v33 = v165;
      if ( (v12[11] & 8) != 0 && *(_WORD *)(v17 + 172) && ((*(unsigned __int16 *)(v17 + 172) - 1) & v31) != 0 || v32 < 0 )
      {
        v11 = -1073741811;
      }
      else
      {
        v12[14] = v31;
        v12[15] = v32;
        *v33 = 0;
        v33[1] = 0;
      }
      if ( IoCountOperations == 1 )
      {
        v34 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 472);
        do
          v35 = __ldrexd(v34);
        while ( __strexd(v35 + v26, v34) );
        v36 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3056);
        do
          v37 = __ldrexd(v36);
        while ( __strexd(v37 + v26, v36) );
      }
      __dmb(0xBu);
      v38 = v12 + 17;
      do
        v39 = __ldrex(v38);
      while ( __strex(0, v38) );
      __dmb(0xBu);
      if ( v12[16] )
        KeSetEvent(v12 + 19, 0, 0);
      v40 = ObfDereferenceObject(v12);
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v42 = *(_WORD *)(v41 + 0x134) + 1;
      *(_WORD *)(v41 + 308) = v42;
      if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
        KiCheckForKernelApcDelivery(v40);
      goto LABEL_75;
    }
    v152 = 1;
    v153 = 1;
  }
  else
  {
    v175[0] = 1;
    v175[1] = 0;
    v175[2] = 4;
    v176 = 0;
    v177[1] = v177;
    v177[0] = v177;
    v152 = 0;
    v153 = 0;
  }
  if ( (v12[11] & 0x4000000) == 0 )
  {
    v43 = KfRaiseIrql(2);
    v44 = (unsigned __int8 *)(v12 + 23);
    do
      v45 = __ldrex(v44);
    while ( __strex(v45 | 0x80, v44) );
    __dmb(0xBu);
    if ( v45 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v44 & 0x80) != 0 );
        do
          v46 = __ldrex(v44);
        while ( __strex(v46 | 0x80, v44) );
        __dmb(0xBu);
      }
      while ( v46 >> 7 );
    }
    v12[24] = 0;
    __dmb(0xBu);
    do
      v47 = __ldrex((unsigned int *)v44);
    while ( __strex(v47 & 0xFFFFFF7F, (unsigned int *)v44) );
    KfLowerIrql(v43);
    v17 = v156;
  }
  if ( v8 != 36 )
  {
    v56 = pIoAllocateIrp(v17, *(char *)(v17 + 48), v152 == 0, vars4);
    v57 = v56;
    v157 = (int *)v56;
    if ( !v56 )
    {
      IopAllocateIrpCleanup(v12, 0);
      return -1073741670;
    }
    *(_DWORD *)(v56 + 100) = v12;
    *(_DWORD *)(v56 + 80) = v160;
    v58 = v151;
    *(_BYTE *)(v56 + 32) = v151;
    if ( v152 )
    {
      *(_DWORD *)(v56 + 44) = 0;
      *(_DWORD *)(v56 + 40) = v165;
      *(_BYTE *)(v56 + 39) |= 2u;
    }
    else
    {
      if ( v58 == 1 )
      {
        v158 = KeSetKernelStackSwapEnable(0);
        v154 = v158;
      }
      *(_DWORD *)(v57 + 44) = v175;
      *(_DWORD *)(v57 + 40) = &v173;
      *(_DWORD *)(v57 + 8) = 4;
    }
    *(_DWORD *)(v57 + 48) = 0;
    v59 = *(_DWORD *)(v57 + 96) - 40;
    v160 = v59;
    v150 = (int *)v59;
    *(_BYTE *)v59 = 6;
    *(_DWORD *)(v59 + 28) = v12;
    *(_DWORD *)(v57 + 12) = 0;
    *(_DWORD *)(v57 + 4) = 0;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v62 = 40;
      else
        v62 = 32;
      v60 = v162;
      v61 = ExAllocatePoolWithTagPriority(512, v162, 538996553, v62);
      v162 = v61;
      if ( !v61 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v60 = v162;
      v61 = ExAllocatePoolWithQuotaTag(512, v162, 538996553);
      v162 = v61;
    }
    *(_DWORD *)(v57 + 12) = v61;
    memmove(v61, v178, v60);
    if ( (v8 == 20 || v8 == 19 || v8 == 14) && *(int *)(v162 + 4) < 0 )
      RtlRaiseStatus(-1073741811);
    v63 = v160;
    *(_DWORD *)(v57 + 8) |= 0x830u;
    *(_DWORD *)(v63 + 8) = v60;
    *(_DWORD *)(v63 + 12) = v8;
    IopQueueThreadIrp(v57);
    if ( IoCountOperations == 1 )
    {
      v64 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
      do
        v65 = __ldrexd(v64);
      while ( __strexd(v65 + 1, v64) );
      v66 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
      do
        v67 = __ldrex(v66);
      while ( __strex(v67 + 1, v66) );
    }
    switch ( v8 )
    {
      case 16:
        v68 = *(int **)(v57 + 12);
        v69 = *v68;
        if ( (*v68 & 0xFFFFFFC9) != 0
          || (v69 & 0x30) != 0 && (v12[11] & 2) == 0
          || (v69 & 0x30) == 0 && (v12[11] & 2) != 0
          || (*v68 & 0x30) == 48 )
        {
          v11 = -1073741811;
        }
        else
        {
          v70 = v12[11];
          if ( (v70 & 8) == 0 )
          {
            if ( (v69 & 2) != 0 )
              v12[11] = v70 | 0x10;
            else
              v12[11] = v70 & 0xFFFFFFEF;
          }
          v71 = v12[11];
          if ( (*v68 & 4) != 0 )
            v72 = v71 | 0x20;
          else
            v72 = v71 & 0xFFFFFFDF;
          v12[11] = v72;
          if ( (v72 & 2) != 0 )
          {
            if ( (*v68 & 0x10) != 0 )
              v73 = v72 | 4;
            else
              v73 = v72 & 0xFFFFFFFB;
            v12[11] = v73;
          }
          v11 = 0;
        }
        *(_DWORD *)(v57 + 24) = v11;
        *(_DWORD *)(v57 + 28) = 0;
        goto LABEL_337;
      case 10:
      case 11:
      case 31:
        v111 = *(_DWORD *)(v57 + 12);
        v112 = *(_DWORD *)(v111 + 8);
        if ( v112 && (v112 & 1) == 0 && v60 - 12 >= v112 )
        {
          v113 = v160;
          if ( v8 == 31 )
          {
            *(_DWORD *)(v160 + 20) = *(_DWORD *)v111;
          }
          else
          {
            *(_BYTE *)(v160 + 20) = *(_BYTE *)v111;
            if ( v169 )
              *(_BYTE *)(v113 + 2) |= 1u;
          }
          if ( *(_WORD *)(v111 + 12) == 92 || *(_DWORD *)(v111 + 4) )
          {
            v121 = IopOpenLinkOrRenameTarget(&v167, v57, v111, v12);
            v11 = v121;
            v75 = v152;
            if ( v121 >= 0 )
            {
              if ( !v152 )
                ObfReferenceObjectWithTag(v12, 1953261124);
              v122 = v12[31];
              if ( v122 && *(_DWORD *)(v122 + 32) )
              {
                v123 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF;
                *(_DWORD *)(v57 + 8) = v123;
                v124 = v123 | (*(_DWORD *)(v122 + 32) << 17);
              }
              else
              {
                v125 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
                v126 = (v125[240] >> 9) & 7;
                if ( (*(_DWORD *)(v125[84] + 192) & 0x100000) != 0 )
                  v126 = 0;
                if ( v126 < 2 && v125 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v125[250] )
                  v126 = 2;
                v124 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | ((v126 + 1) << 17);
              }
              *(_DWORD *)(v57 + 8) = v124;
              v127 = IoGetIoPriorityHint(v57);
              if ( !*(_BYTE *)(v57 + 32) && v127 < 2 )
              {
                v128 = *(_DWORD *)(v57 + 80);
                if ( !v128 || (*(_DWORD *)(v128 + 76) & 0x400) == 0 && (*(_DWORD *)(v128 + 964) & 0x20) == 0 )
                {
                  ++IoKernelIssuedIoBoostedCount;
                  *(_DWORD *)(v57 + 8) = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | 0x60000;
                }
              }
              if ( (*(_BYTE *)(v57 + 39) & 0x80) == 0 && (v129 = *(_WORD **)(v57 + 104)) != 0 && (*v129 & 2) != 0 )
              {
                EtwActivityIdControlKernel(1, &v157);
                v131 = *(_DWORD **)(v57 + 104);
                v179 = v131[3];
                v180 = v131[4];
                v181 = v131[5];
                v182 = v131[6];
                v150 = &v179;
                EtwActivityIdControlKernel(2, &v150);
                v11 = IofCallDriver(v156, v57);
                v150 = v157;
                EtwActivityIdControlKernel(2, &v150);
              }
              else
              {
                v11 = IofCallDriver(v156, v57);
              }
              if ( !v75 )
                ObDereferenceObjectDeferDeleteWithTag(v12, 1953261124);
              v166 = v167;
            }
            else
            {
              *(_DWORD *)(v57 + 24) = v121;
              v166 = v167;
            }
            goto LABEL_338;
          }
          v75 = v152;
          if ( !v152 )
            ObfReferenceObjectWithTag(v12, 1953261124);
          v114 = v12[31];
          if ( v114 && *(_DWORD *)(v114 + 32) )
          {
            v115 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF;
            *(_DWORD *)(v57 + 8) = v115;
            v116 = v115 | (*(_DWORD *)(v114 + 32) << 17);
          }
          else
          {
            v117 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
            v118 = (v117[240] >> 9) & 7;
            if ( (*(_DWORD *)(v117[84] + 192) & 0x100000) != 0 )
              v118 = 0;
            if ( v118 < 2 && v117 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v117[250] )
              v118 = 2;
            v116 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | ((v118 + 1) << 17);
          }
          *(_DWORD *)(v57 + 8) = v116;
          v119 = IoGetIoPriorityHint(v57);
          if ( *(_BYTE *)(v57 + 32) )
            goto LABEL_175;
          if ( v119 >= 2 )
            goto LABEL_175;
          v120 = *(_DWORD *)(v57 + 80);
          if ( v120 )
          {
            if ( (*(_DWORD *)(v120 + 76) & 0x400) != 0 || (*(_DWORD *)(v120 + 964) & 0x20) != 0 )
              goto LABEL_175;
          }
          goto LABEL_174;
        }
LABEL_336:
        v11 = -1073741811;
        *(_DWORD *)(v57 + 24) = -1073741811;
        goto LABEL_337;
      case 40:
        v74 = *(_DWORD *)(v57 + 12);
        if ( v60 - 4 >= *(_DWORD *)v74 )
        {
          v75 = v152;
          if ( *(_WORD *)(v74 + 4) == 92 )
          {
            v11 = -1073741811;
            *(_DWORD *)(v57 + 24) = -1073741811;
LABEL_338:
            v102 = v151;
            goto LABEL_339;
          }
          if ( !v152 )
            ObfReferenceObjectWithTag(v12, 1953261124);
          v76 = v12[31];
          if ( v76 && *(_DWORD *)(v76 + 32) )
          {
            v77 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF;
            *(_DWORD *)(v57 + 8) = v77;
            v78 = v77 | (*(_DWORD *)(v76 + 32) << 17);
          }
          else
          {
            v79 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
            v80 = (v79[240] >> 9) & 7;
            if ( (*(_DWORD *)(v79[84] + 192) & 0x100000) != 0 )
              v80 = 0;
            if ( v80 < 2 && v79 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v79[250] )
              v80 = 2;
            v78 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | ((v80 + 1) << 17);
          }
          *(_DWORD *)(v57 + 8) = v78;
          v81 = IoGetIoPriorityHint(v57);
          if ( !*(_BYTE *)(v57 + 32) && v81 < 2 )
          {
            v82 = *(_DWORD *)(v57 + 80);
            if ( !v82 || (*(_DWORD *)(v82 + 76) & 0x400) == 0 && (*(_DWORD *)(v82 + 964) & 0x20) == 0 )
            {
LABEL_174:
              ++IoKernelIssuedIoBoostedCount;
              *(_DWORD *)(v57 + 8) = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | 0x60000;
              goto LABEL_175;
            }
          }
LABEL_175:
          if ( (*(_BYTE *)(v57 + 39) & 0x80) == 0 && (v83 = *(_WORD **)(v57 + 104)) != 0 && (*v83 & 2) != 0 )
          {
            EtwActivityIdControlKernel(1, &v157);
            v85 = *(_DWORD **)(v57 + 104);
            v179 = v85[3];
            v180 = v85[4];
            v181 = v85[5];
            v182 = v85[6];
            v150 = &v179;
            EtwActivityIdControlKernel(2, &v150);
            v11 = IofCallDriver(v156, v57);
            v150 = v157;
            EtwActivityIdControlKernel(2, &v150);
          }
          else
          {
            v11 = IofCallDriver(v156, v57);
          }
          if ( !v75 )
            ObDereferenceObjectDeferDeleteWithTag(v12, 1953261124);
          goto LABEL_338;
        }
        goto LABEL_336;
      case 13:
        if ( **(_BYTE **)(v57 + 12) )
          *(_DWORD *)(v160 + 20) = v163;
        v75 = v152;
        if ( !v152 )
          ObfReferenceObjectWithTag(v12, 1953261124);
        v86 = v12[31];
        if ( v86 && *(_DWORD *)(v86 + 32) )
        {
          v87 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF;
          *(_DWORD *)(v57 + 8) = v87;
          v88 = v87 | (*(_DWORD *)(v86 + 32) << 17);
        }
        else
        {
          v89 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          v90 = (v89[240] >> 9) & 7;
          if ( (*(_DWORD *)(v89[84] + 192) & 0x100000) != 0 )
            v90 = 0;
          if ( v90 < 2 && v89 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v89[250] )
            v90 = 2;
          v88 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | ((v90 + 1) << 17);
        }
        *(_DWORD *)(v57 + 8) = v88;
        v91 = IoGetIoPriorityHint(v57);
        if ( *(_BYTE *)(v57 + 32) )
          goto LABEL_175;
        if ( v91 >= 2 )
          goto LABEL_175;
        v92 = *(_DWORD *)(v57 + 80);
        if ( v92 )
        {
          if ( (*(_DWORD *)(v92 + 76) & 0x400) != 0 || (*(_DWORD *)(v92 + 964) & 0x20) != 0 )
            goto LABEL_175;
        }
        goto LABEL_174;
      case 30:
        v93 = *(int **)(v57 + 12);
        v150 = v93;
        if ( !v12[27] && (v12[11] & 2) == 0 )
        {
          v11 = ObReferenceObjectByHandle(*v93, 2, IoCompletionObjectType, v151, &v163, 0);
          if ( v11 >= 0 )
          {
            v94 = (_DWORD *)ExAllocatePoolWithTag(512, 8, 1665363785);
            if ( v94 )
            {
              v95 = v12 + 28;
              v96 = KfRaiseIrql(2);
              v157 = (int *)v96;
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v12 + 28);
              }
              else
              {
                do
                  v97 = __ldrex(v95);
                while ( __strex(1u, v95) );
                __dmb(0xBu);
                if ( v97 )
                  KxWaitForSpinLockAndAcquire(v12 + 28);
              }
              if ( v12[27] )
              {
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  KiReleaseSpinLockInstrumented(v12 + 28);
                }
                else
                {
                  __dmb(0xBu);
                  *v95 = 0;
                }
                KfLowerIrql(v96);
                ExFreePoolWithTag(v94, 0);
                ObfDereferenceObject(v163);
                v11 = -1073741752;
              }
              else
              {
                v12[11] &= 0xFFFFFBFF;
                *v94 = v163;
                v94[1] = v150[1];
                v12[27] = v94;
                v11 = 0;
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  KiReleaseSpinLockInstrumented(v12 + 28);
                }
                else
                {
                  __dmb(0xBu);
                  *v95 = 0;
                }
                KfLowerIrql(v157);
              }
            }
            else
            {
              ObfDereferenceObject(v163);
              v11 = -1073741670;
            }
          }
          goto LABEL_228;
        }
        break;
      case 61:
        v98 = *(_DWORD **)(v57 + 12);
        v99 = 0;
        if ( v12[27] )
        {
          if ( *v98 )
          {
            v11 = ObReferenceObjectByHandle(*v98, 2, IoCompletionObjectType, v151, &v150, 0);
            v99 = (int)v150;
          }
          if ( v11 >= 0 )
          {
            v11 = IopReplaceCompletionPort(v12, v99, v98[1]);
            if ( v99 )
            {
              ObfDereferenceObject(v99);
              *(_DWORD *)(v57 + 24) = v11;
              *(_DWORD *)(v57 + 28) = 0;
              goto LABEL_337;
            }
          }
LABEL_228:
          *(_DWORD *)(v57 + 24) = v11;
          *(_DWORD *)(v57 + 28) = 0;
LABEL_337:
          v75 = v152;
          goto LABEL_338;
        }
        break;
      case 41:
        v100 = *(_DWORD **)(v57 + 12);
        v101 = v12[11];
        if ( (v101 & 2) != 0 )
        {
          v11 = -1073741811;
        }
        else
        {
          v11 = 0;
          if ( (*v100 & 1) != 0 )
            v12[11] = v101 | 0x2000000;
          if ( (*v100 & 2) != 0 )
            v12[11] |= 0x4000000u;
          if ( (*v100 & 4) != 0 )
            v12[11] |= 0x8000000u;
        }
        *(_DWORD *)(v57 + 24) = v11;
        *(_DWORD *)(v57 + 28) = 0;
        goto LABEL_337;
      case 42:
        v102 = v151;
        if ( SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, v151) )
        {
          if ( (v12[11] & 2) != 0 )
            v11 = -1073741811;
          else
            v11 = IopSetFileObjectIosbRange(v12, v57);
        }
        else
        {
          v11 = -1073741727;
        }
        *(_DWORD *)(v57 + 24) = v11;
        *(_DWORD *)(v57 + 28) = 0;
        v75 = v152;
LABEL_339:
        if ( v11 == 259 )
        {
          if ( !v75 )
          {
            v141 = KeWaitForSingleObject(v175, 0, v102);
            if ( v141 == 257 || v141 == 192 )
              IopCancelAlertedRequest(v175, v57);
            v11 = v173;
            v142 = v165;
            *v165 = v173;
            v142[1] = v174;
            v143 = v158;
LABEL_377:
            if ( v143 )
              KeSetKernelStackSwapEnable(1);
            if ( v166 )
            {
              ObCloseHandle(v166, 0);
              return v11;
            }
            return v11;
          }
          v132 = (v12[11] & 4) != 0;
          while ( 1 )
          {
            v133 = v132 ? (_BYTE)v151 : 0;
            v134 = KeWaitForSingleObject(v12 + 23, 0, v133);
            if ( v134 != 257 && v134 != 192 )
              break;
            if ( !v132 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 )
            {
              v170 = 0;
              v135 = KfRaiseIrql(1);
              if ( !v12[24] )
                v170 = *(unsigned __int8 *)(v57 + 36) == 1;
              KfLowerIrql(v135);
              if ( !v170 )
                continue;
            }
            IopCancelAlertedRequest(v12 + 23, v57);
            break;
          }
          v11 = v12[7];
          __dmb(0xBu);
          v136 = v12 + 17;
          do
            v137 = __ldrex(v136);
          while ( __strex(0, v136) );
          __dmb(0xBu);
          if ( v12[16] )
            KeSetEvent(v12 + 19, 0, 0);
          v138 = ObfDereferenceObject(v12);
          v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v140 = (__int16)(*(_WORD *)(v139 + 0x134) + 1);
          *(_WORD *)(v139 + 308) = v140;
          if ( v140 || *(_DWORD *)(v139 + 100) == v139 + 100 || *(_WORD *)(v139 + 310) )
          {
LABEL_376:
            v143 = v158;
            goto LABEL_377;
          }
        }
        else
        {
          if ( !v75 )
            *(_DWORD *)(v57 + 44) = 0;
          *(_DWORD *)(v57 + 40) = v165;
          v144 = KfRaiseIrql(1);
          IopCompleteRequest(v57 + 64, &v157, &v150, v172, &v150);
          KfLowerIrql(v144);
          if ( !v75 )
            goto LABEL_376;
          __dmb(0xBu);
          v145 = v12 + 17;
          do
            v146 = __ldrex(v145);
          while ( __strex(0, v145) );
          __dmb(0xBu);
          if ( v12[16] )
            KeSetEvent(v12 + 19, 0, 0);
          v138 = ObfDereferenceObject(v12);
          v147 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v148 = *(_WORD *)(v147 + 0x134) + 1;
          *(_WORD *)(v147 + 308) = v148;
          if ( v148 || *(_DWORD *)(v147 + 100) == v147 + 100 || *(_WORD *)(v147 + 310) )
            goto LABEL_376;
        }
        KiCheckForKernelApcDelivery(v138);
        goto LABEL_376;
      case 43:
        v103 = *(int **)(v57 + 12);
        if ( *v103 >= 3 || *v103 < 0 )
        {
          v11 = -1073741811;
        }
        else
        {
          v11 = IopAllocateFileObjectExtension(v12, &v150);
          if ( v11 >= 0 )
            v150[8] = *v103 + 1;
        }
        *(_DWORD *)(v57 + 24) = v11;
        *(_DWORD *)(v57 + 28) = 0;
        goto LABEL_337;
      default:
        v75 = v152;
        if ( !v152 )
          ObfReferenceObjectWithTag(v12, 1953261124);
        v104 = v12[31];
        if ( v104 && *(_DWORD *)(v104 + 32) )
        {
          v105 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF;
          *(_DWORD *)(v57 + 8) = v105;
          v106 = v105 | (*(_DWORD *)(v104 + 32) << 17);
        }
        else
        {
          v107 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          v108 = (v107[240] >> 9) & 7;
          if ( (*(_DWORD *)(v107[84] + 192) & 0x100000) != 0 )
            v108 = 0;
          if ( v108 < 2 && v107 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v107[250] )
            v108 = 2;
          v106 = *(_DWORD *)(v57 + 8) & 0xFFF1FFFF | ((v108 + 1) << 17);
        }
        *(_DWORD *)(v57 + 8) = v106;
        v109 = IoGetIoPriorityHint(v57);
        if ( !*(_BYTE *)(v57 + 32) && v109 < 2 )
        {
          v110 = *(_DWORD *)(v57 + 80);
          if ( !v110 || (*(_DWORD *)(v110 + 76) & 0x400) == 0 && (*(_DWORD *)(v110 + 964) & 0x20) == 0 )
            goto LABEL_174;
        }
        goto LABEL_175;
    }
    v11 = -1073741811;
    goto LABEL_228;
  }
  v48 = v152;
  if ( v162 >= 0xC )
  {
    v49 = IopTrackLink(v12, &v173, a3);
    v10 = v49;
    v168 = v49;
    if ( v49 >= 0 )
    {
      v50 = v165;
      v165[1] = 0;
      *v50 = v49;
    }
  }
  else
  {
    v10 = -1073741820;
  }
  if ( v48 )
  {
    __dmb(0xBu);
    v51 = v12 + 17;
    do
      v52 = __ldrex(v51);
    while ( __strex(0, v51) );
    __dmb(0xBu);
    if ( v12[16] )
      KeSetEvent(v12 + 19, 0, 0);
    v53 = ObfDereferenceObject(v12);
    v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v55 = *(_WORD *)(v54 + 0x134) + 1;
    *(_WORD *)(v54 + 308) = v55;
    if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
      KiCheckForKernelApcDelivery(v53);
  }
  ObfDereferenceObject(v12);
  return v10;
}
