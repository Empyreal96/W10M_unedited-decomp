// ObpCreateHandle 
 
// local variable allocation has failed, the output may be wrong!
int ObpCreateHandle(int a1, _DWORD *a2, ...)
{
  int *v2; // r5
  int v3; // r7
  unsigned int v4; // r4
  int *v5; // r2
  int v6; // r1
  int v7; // r3
  int v9; // r6
  char v10; // r7
  int v11; // r3
  __int64 v12; // kr00_8
  int v13; // r2
  unsigned int *v14; // r7
  unsigned int v15; // r0
  bool v16; // zf
  int v17; // r6
  unsigned int *v18; // r3
  int v19; // r4
  int v20; // lr
  int v21; // r9
  int v22; // r3
  _DWORD *v23; // r4
  int v24; // r3
  int v25; // r0
  unsigned int *v26; // r7
  unsigned int v27; // r1
  bool v28; // zf
  int v29; // r6
  int v30; // r4
  int v31; // r3
  unsigned int v32; // r0
  _DWORD *v33; // r7
  _DWORD *v34; // r6
  unsigned int i; // r2
  unsigned int v36; // r1
  unsigned int v37; // r1
  unsigned int *v38; // r2
  int v39; // r0
  unsigned int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r2
  unsigned int *v43; // r8
  int v44; // r0
  int v45; // r4
  unsigned int v46; // r2
  unsigned int *v47; // r2
  int v48; // r4
  unsigned int v49; // r2
  int v50; // r0
  unsigned int v51; // r1
  int v52; // r3
  unsigned int v53; // r8
  int *v54; // r0
  int v55; // r6
  unsigned int v56; // r7
  unsigned int v57; // r1
  unsigned int v58; // r9
  unsigned int v59; // r1
  unsigned int v60; // r4
  int v61; // r0
  int v62; // r7
  unsigned int v63; // r2
  int v64; // r7
  int v65; // r3
  int v66; // r2
  int v67; // r3
  unsigned int v68; // r1
  int v69; // r1
  int v70; // r3
  int *v71; // r4
  __int16 v72; // r3
  void *v73; // r8
  int v74; // r1
  int *v75; // r5
  _DWORD *v76; // r6
  int v77; // r9
  unsigned int v78; // r1
  unsigned int v79; // r1
  unsigned __int8 *v80; // r4
  int v81; // r0
  int v82; // r7
  unsigned int v83; // r2
  unsigned int v84; // r1
  unsigned int **v85; // r3
  int *v86; // r8
  int v87; // r4
  char v88; // r9
  int v89; // r4
  unsigned int v90; // r7
  unsigned int v91; // r5
  int v92; // r3
  int v93; // r3
  int v94; // r0
  int v95; // r0
  unsigned int v96; // r1
  __int16 v97; // r3
  int v98; // r0
  unsigned int v99; // r1
  __int16 v100; // r3
  unsigned int *v101; // r7
  int v102; // r3
  int v103; // r1
  _DWORD *v104; // r3
  unsigned int v105; // r0
  unsigned int v106; // r2
  unsigned int *v107; // r4
  int v108; // r0
  int v109; // r6
  unsigned int v110; // r2
  unsigned int *v111; // r2
  int v112; // r4
  unsigned int v113; // r2
  int v114; // r0
  unsigned int v115; // r1
  __int16 v116; // r3
  unsigned int v117; // r1
  unsigned int v118; // r0
  unsigned int *v119; // r2
  int v120; // r0
  unsigned __int8 *v121; // r9
  unsigned int v122; // r8
  int v123; // r0
  int v124; // r10
  unsigned int v125; // r2
  unsigned int v126; // r1
  int v127; // r1 OVERLAPPED
  _DWORD *v128; // r2 OVERLAPPED
  unsigned int v129; // r1
  int v130; // r0
  __int16 v131; // r3
  unsigned int v132; // r1
  int v133; // r0
  __int16 v134; // r3
  int v135; // r6
  unsigned int v136; // r0
  int v137; // r2
  int v138; // r2
  int v139; // r3
  unsigned int v140; // r0
  char v141; // r3
  unsigned int *v142; // r3
  int v143; // r3
  int v144; // r9
  int v145; // r0
  int v146; // r0
  int v147; // r1
  int v149; // [sp+44h] [bp-8Ch] BYREF
  _DWORD *v150; // [sp+48h] [bp-88h]
  unsigned int *v151; // [sp+4Ch] [bp-84h]
  int *j; // [sp+50h] [bp-80h] BYREF
  int *v153; // [sp+54h] [bp-7Ch]
  _DWORD *v154; // [sp+58h] [bp-78h] BYREF
  unsigned int *v155; // [sp+5Ch] [bp-74h] BYREF
  unsigned int *v156; // [sp+60h] [bp-70h] BYREF
  int v157; // [sp+64h] [bp-6Ch]
  int v158; // [sp+68h] [bp-68h] BYREF
  int v159; // [sp+6Ch] [bp-64h]
  int v160; // [sp+70h] [bp-60h]
  int v161[2]; // [sp+78h] [bp-58h] BYREF
  int v162; // [sp+80h] [bp-50h]
  int *v163; // [sp+84h] [bp-4Ch]
  _DWORD *v164; // [sp+88h] [bp-48h]
  int v165; // [sp+8Ch] [bp-44h]
  unsigned int v166; // [sp+90h] [bp-40h]
  int v167[2]; // [sp+98h] [bp-38h] BYREF
  __int64 v168; // [sp+A0h] [bp-30h]
  int v169; // [sp+A8h] [bp-28h]
  unsigned int varg_r2; // [sp+E0h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+E0h] [bp+10h]
  int *varg_r3; // [sp+E4h] [bp+14h]
  unsigned int v173; // [sp+E8h] [bp+18h]
  int v174; // [sp+ECh] [bp+1Ch]
  int v175; // [sp+F0h] [bp+20h]
  _DWORD *v176; // [sp+F4h] [bp+24h]
  _DWORD *v177; // [sp+F8h] [bp+28h]
  int *v178; // [sp+FCh] [bp+2Ch]
  va_list va1; // [sp+100h] [bp+30h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, int *);
  v173 = va_arg(va1, _DWORD);
  v174 = va_arg(va1, _DWORD);
  v175 = va_arg(va1, _DWORD);
  v176 = va_arg(va1, _DWORD *);
  v177 = va_arg(va1, _DWORD *);
  v178 = va_arg(va1, int *);
  v2 = varg_r3;
  v3 = v174;
  v164 = v177;
  v4 = varg_r2;
  v162 = 0;
  v163 = v178;
  v157 = 0;
  v154 = 0;
  v155 = 0;
  v160 = a1;
  j = (int *)v174;
  if ( (v174 & 0x200) != 0 )
  {
    v7 = ObpKernelHandleTable;
    v6 = PsInitialSystemProcess;
    v5 = (int *)ObpKernelHandleTable;
    v153 = (int *)ObpKernelHandleTable;
  }
  else
  {
    v5 = *(int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 336);
    v153 = v5;
    v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v7 = ObpKernelHandleTable;
  }
  v151 = (unsigned int *)v6;
  if ( v5 != (int *)v7 )
    return sub_800708();
  v159 = 1;
  if ( !varg_r3 || !varg_r3[6] )
  {
    if ( (varg_r2 & 0x2000000) != 0 )
    {
      v4 = varg_r2 & 0xFDFFFFFF | 0x10000000;
      varg_r2 = v4;
    }
    if ( (v4 & 0xF0000000) != 0 )
    {
      RtlMapGenericMask(
        (int *)varg_r2a,
        (_DWORD *)(ObTypeIndexTable[(unsigned __int8)(ObHeaderCookie ^ *((_BYTE *)a2 - 12) ^ ((unsigned __int16)((_WORD)a2 - 24) >> 8))]
                 + 52));
      v4 = varg_r2;
    }
    v149 = v4;
    goto LABEL_25;
  }
  v9 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)((_WORD)a2 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *((unsigned __int8 *)a2 - 12)];
  if ( (v174 & 0x400) != 0 )
    v10 = 1;
  else
    v10 = v175;
  if ( v160 != 1 && v160 != 2 )
  {
    v11 = varg_r3[4];
    if ( (v11 & 0x2000000) != 0 )
      varg_r3[4] = v11 & 0xFDFFFFFF | 0x10000000;
    if ( (v2[4] & 0xF0000000) != 0 )
      RtlMapGenericMask(v2 + 4, (_DWORD *)(v9 + 52));
    if ( (v2[4] & 0x1000000) != 0 )
    {
      v167[0] = 1;
      v167[1] = 1;
      v168 = SeSecurityPrivilege;
      v169 = 0;
      if ( !SePrivilegeCheck(v167, v2 + 7, v10) )
      {
        SePrivilegedServiceAuditAlarm(0, v2 + 7, (int)v167, 0);
        return -1073741727;
      }
      v2[4] &= 0xFEFFFFFF;
      v2[5] |= 0x1000000u;
      SeAppendPrivileges((int)v2, v167);
    }
    v12 = *((_QWORD *)v2 + 2);
    v2[4] = 0;
    v2[5] = HIDWORD(v12) | v12;
    v13 = *(_DWORD *)(v9 + 68);
    v14 = a2 - 1;
    __pld(a2 - 1);
    v2[5] = (HIDWORD(v12) | v12) & (v13 | 0x1000000);
    v15 = *(a2 - 1);
    if ( (v15 & 7) != 0 )
    {
      do
      {
        do
          v37 = __ldrex(v14);
        while ( v37 == v15 && __strex(v15 - 1, v14) );
        __dmb(0xBu);
        if ( v37 == v15 )
          break;
        v15 = v37;
      }
      while ( (v37 & 7) != 0 );
    }
    v16 = (v15 & 7) == 1;
    v17 = v15 & 0xFFFFFFF8;
    if ( (v15 & 7) == 0 )
    {
      if ( v17 )
      {
        v106 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v106 + 308);
        v107 = a2 - 4;
        v156 = a2 - 4;
        v108 = KeAbPreAcquire((unsigned int)(a2 - 4), 0, 0);
        v109 = v108;
        do
          v110 = __ldrex(v107);
        while ( !v110 && __strex(0x11u, v107) );
        __dmb(0xBu);
        if ( v110 )
          ExfAcquirePushLockSharedEx(v107, v108, (unsigned int)v107);
        if ( v109 )
          *(_BYTE *)(v109 + 14) |= 1u;
        v17 = *v14 & 0xFFFFFFF8;
        v111 = (unsigned int *)(v17 - 8);
        do
          v112 = __ldrex(v111);
        while ( __strex(v112 + 8, v111) );
        if ( v112 <= 0 )
          __fastfail(0xEu);
        __dmb(0xBu);
        do
          v113 = __ldrex(v156);
        while ( v113 == 17 && __strex(0, v156) );
        if ( v113 != 17 )
          ExfReleasePushLockShared(v156);
        v114 = KeAbPostRelease((unsigned int)v156);
        v115 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v116 = *(_WORD *)(v115 + 0x134) + 1;
        *(_WORD *)(v115 + 308) = v116;
        if ( !v116 && *(_DWORD *)(v115 + 100) != v115 + 100 && !*(_WORD *)(v115 + 310) )
          KiCheckForKernelApcDelivery(v114);
        goto LABEL_236;
      }
      v16 = 0;
    }
    if ( !v16 )
    {
LABEL_21:
      v2[5] &= ~SeComputeCreatorDeniedRights(v2 + 7, (int)v2, v2[5], v17);
      if ( v17 )
        ObDereferenceSecurityDescriptor(v17, 1);
      goto LABEL_23;
    }
    v119 = (unsigned int *)(v17 - 8);
    do
      v120 = __ldrex(v119);
    while ( __strex(v120 + 7, v119) );
    if ( v120 <= 0 )
      __fastfail(0xEu);
LABEL_236:
    __pld(v14);
    v117 = *v14;
    if ( (*v14 & 7) == 0 )
    {
      while ( v17 == (v117 & 0xFFFFFFF8) )
      {
        do
          v118 = __ldrex(v14);
        while ( v118 == v117 && __strex(v117 + 7, v14) );
        __dmb(0xBu);
        if ( v118 == v117 )
          goto LABEL_21;
        v117 = v118;
        if ( (v118 & 7) != 0 )
          break;
      }
    }
    ObDereferenceSecurityDescriptor(v17, 7);
    goto LABEL_21;
  }
  if ( !ObCheckObjectAccess((int)a2, varg_r3, 1, v10, (int *)&v156) )
  {
    v19 = (int)v156;
    if ( (int)v156 < 0 )
      return v19;
    goto LABEL_24;
  }
LABEL_23:
  v149 = v2[5];
LABEL_24:
  v3 = v174;
LABEL_25:
  v18 = 0;
  v156 = 0;
  if ( v176 )
  {
    v18 = (unsigned int *)v176[6];
    v156 = v18;
  }
  v19 = ObpIncrementHandleCountEx(v160, (int)&v149, (int)v151, (int)a2, v175, v3, (int)v18);
  if ( v19 < 0 )
    return v19;
  if ( !v2 )
  {
LABEL_32:
    v20 = (int)a2;
    v21 = (int)(a2 - 6);
    v22 = *((unsigned __int8 *)a2 - 12);
    v158 = (unsigned __int8)((unsigned __int16)((_WORD)a2 - 24) >> 8);
    v150 = a2 - 6;
    v23 = (_DWORD *)ObTypeIndexTable[v158 ^ (unsigned __int8)ObHeaderCookie ^ v22];
    v24 = v23[17];
    v154 = v23;
    v25 = (v24 | 0x1000000) & v149;
    v149 = v25;
    if ( !v2 )
      goto LABEL_40;
    v26 = a2 - 1;
    __pld(a2 - 1);
    v27 = *(a2 - 1);
    if ( (v27 & 7) != 0 )
    {
      do
      {
        do
          v32 = __ldrex(v26);
        while ( v32 == v27 && __strex(v27 - 1, v26) );
        __dmb(0xBu);
        if ( v32 == v27 )
          break;
        v27 = v32;
      }
      while ( (v32 & 7) != 0 );
    }
    v28 = (v27 & 7) == 1;
    v29 = v27 & 0xFFFFFFF8;
    if ( (v27 & 7) == 0 )
    {
      if ( v29 )
      {
        v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v42 + 308);
        v43 = a2 - 4;
        v44 = KeAbPreAcquire((unsigned int)(a2 - 4), 0, 0);
        v45 = v44;
        do
          v46 = __ldrex(v43);
        while ( !v46 && __strex(0x11u, v43) );
        __dmb(0xBu);
        if ( v46 )
          ExfAcquirePushLockSharedEx(a2 - 4, v44, (unsigned int)(a2 - 4));
        if ( v45 )
          *(_BYTE *)(v45 + 14) |= 1u;
        v29 = *v26 & 0xFFFFFFF8;
        v47 = (unsigned int *)(v29 - 8);
        do
          v48 = __ldrex(v47);
        while ( __strex(v48 + 8, v47) );
        if ( v48 <= 0 )
          __fastfail(0xEu);
        __dmb(0xBu);
        do
          v49 = __ldrex(v43);
        while ( v49 == 17 && __strex(0, v43) );
        if ( v49 != 17 )
          ExfReleasePushLockShared(a2 - 4);
        v50 = KeAbPostRelease((unsigned int)(a2 - 4));
        v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v52 = (__int16)(*(_WORD *)(v51 + 0x134) + 1);
        *(_WORD *)(v51 + 308) = v52;
        if ( !v52 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
          KiCheckForKernelApcDelivery(v50);
        goto LABEL_72;
      }
      v28 = 0;
    }
    if ( !v28 )
    {
LABEL_38:
      v30 = SeComputeCreatorDeniedRights(v2 + 7, (int)v2, v149, v29);
      if ( v29 )
      {
        v33 = (_DWORD *)(v29 - 16);
        v34 = (_DWORD *)(v29 - 8);
        __pld(v34);
        for ( i = *v34; (int)(i - 1) > 0; i = v36 )
        {
          __dmb(0xBu);
          do
            v36 = __ldrex(v34);
          while ( v36 == i && __strex(i - 1, v34) );
          if ( v36 == i )
            goto LABEL_39;
        }
        if ( i != 1 )
          __fastfail(0xEu);
        v121 = (unsigned __int8 *)&ObsSecurityDescriptorCache[3 * (v33[3] % 0x101u)];
        v122 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v122 + 308);
        v123 = KeAbPreAcquire((unsigned int)v121, 0, 0);
        v124 = v123;
        do
          v125 = __ldrex(v121);
        while ( __strex(v125 | 1, v121) );
        __dmb(0xBu);
        if ( (v125 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v121, v123, (unsigned int)v121);
        if ( v124 )
          *(_BYTE *)(v124 + 14) |= 1u;
        __dmb(0xBu);
        do
          v126 = __ldrex(v34);
        while ( __strex(v126 - 1, v34) );
        if ( (int)(v126 - 1) > 0 )
        {
          __dmb(0xBu);
          do
            v132 = __ldrex((unsigned int *)v121);
          while ( __strex(v132 - 1, (unsigned int *)v121) );
          if ( (v132 & 2) != 0 && (v132 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v121);
          v133 = KeAbPostRelease((unsigned int)v121);
          v134 = *(_WORD *)(v122 + 308) + 1;
          *(_WORD *)(v122 + 308) = v134;
          if ( !v134 && *(_DWORD *)(v122 + 100) != v122 + 100 && !*(_WORD *)(v122 + 310) )
            KiCheckForKernelApcDelivery(v133);
        }
        else
        {
          if ( v126 != 1 )
            __fastfail(0xEu);
          __dmb(0xBu);
          *(_QWORD *)&v127 = *(_QWORD *)v33;
          if ( *(_DWORD **)(*v33 + 4) != v33 || (_DWORD *)*v128 != v33 )
            __fastfail(3u);
          *v128 = v127;
          *(_DWORD *)(v127 + 4) = v128;
          __dmb(0xBu);
          do
            v129 = __ldrex((unsigned int *)v121);
          while ( __strex(v129 - 1, (unsigned int *)v121) );
          if ( (v129 & 2) != 0 && (v129 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v121);
          v130 = KeAbPostRelease((unsigned int)v121);
          v131 = *(_WORD *)(v122 + 308) + 1;
          *(_WORD *)(v122 + 308) = v131;
          if ( !v131 && *(_DWORD *)(v122 + 100) != v122 + 100 && !*(_WORD *)(v122 + 310) )
            KiCheckForKernelApcDelivery(v130);
          ExFreePoolWithTag((unsigned int)v33);
        }
        v21 = (int)v150;
      }
LABEL_39:
      v20 = (int)a2;
      LOBYTE(v3) = (_BYTE)j;
      v25 = v149 & ~v30;
      v31 = v2[12];
      v149 = v25;
      v2[5] = v25;
      v23 = v154;
      v155 = *(unsigned int **)(v31 + 24);
LABEL_40:
      if ( v173 )
      {
        ObReferenceObjectExWithTag(v20, v173);
        v25 = v149;
      }
      if ( v157 )
      {
        ObfDereferenceObject(v157);
        v25 = v149;
      }
      v161[1] = (int)v161;
      v161[0] = (int)v161;
      if ( (*((_BYTE *)v23 + 42) & 0x40) != 0 && (_DWORD *)v23[34] != v23 + 34 )
      {
        v135 = v159;
        j = (int *)v25;
        v19 = ObpPreInterceptHandleCreate(a2, v159, &j, v161);
        if ( v19 < 0 )
        {
          ObpDecrementHandleCount((int)v151, v21);
          if ( v173 )
          {
            if ( v173 > 1 )
            {
              __dmb(0xBu);
              do
                v136 = __ldrex((unsigned int *)v21);
              while ( __strex(v136 + 1 - v173, (unsigned int *)v21) );
            }
            ObfDereferenceObject((int)a2);
          }
          return v19;
        }
        if ( v135 )
        {
          v25 = v149;
        }
        else
        {
          v25 = (int)j;
          v149 = (int)j;
          if ( v2 )
            v2[5] = (int)j;
        }
      }
      if ( (v3 & 8) != 0 )
        v137 = v25 & 0x1FFFFFF | 0x4000000;
      else
        v137 = v25 & 0x1FFFFFF;
      if ( (v3 & 1) != 0 )
        v138 = v137 | 0x2000000;
      else
        v138 = v137 & 0xFDFFFFFF;
      v166 = v3 & 6 | v21 & 0xFFFFFFF9 | 1;
      v157 = v138;
      v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v53 + 308);
      v54 = v153;
      v55 = 0;
      if ( (v153[7] & 4) == 0 )
      {
        while ( 1 )
        {
          v165 = *v54;
          if ( (v54[7] & 1) != 0 )
          {
            v56 = dword_92038C;
            v58 = 0;
          }
          else
          {
            v56 = dword_92038C;
            v57 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            if ( !dword_92038C )
              __brkdiv0();
            v58 = v57 % dword_92038C;
            v54 = v153;
          }
          v59 = 0;
          for ( j = 0; v59 < v56; j = (int *)++v59 )
          {
            v60 = (unsigned int)&v54[13 * v58 + 10];
            if ( v54[13 * v58 + 11] )
            {
              v61 = KeAbPreAcquire((unsigned int)&v54[13 * v58 + 10], 0, 0);
              v62 = v61;
              do
                v63 = __ldrex((unsigned __int8 *)v60);
              while ( __strex(v63 | 1, (unsigned __int8 *)v60) );
              __dmb(0xBu);
              if ( (v63 & 1) != 0 )
                ExfAcquirePushLockExclusiveEx((_DWORD *)v60, v61, v60);
              if ( v62 )
                *(_BYTE *)(v62 + 14) |= 1u;
              v64 = *(_DWORD *)(v60 + 4);
              if ( v64 )
              {
                v65 = *(_DWORD *)(v64 + 4);
                *(_DWORD *)(v60 + 4) = v65;
                if ( !v65 )
                  *(_DWORD *)(v60 + 8) = 0;
                v66 = *(_DWORD *)(v60 + 12) + 1;
                v67 = *(_DWORD *)(v60 + 16);
                *(_DWORD *)(v60 + 12) = v66;
                if ( v66 > v67 )
                  *(_DWORD *)(v60 + 16) = v66;
              }
              __dmb(0xBu);
              do
                v68 = __ldrex((unsigned int *)v60);
              while ( __strex(v68 - 1, (unsigned int *)v60) );
              if ( (v68 & 2) != 0 && (v68 & 4) == 0 )
                ExfTryToWakePushLock((unsigned int *)v60);
              v54 = (int *)KeAbPostRelease(v60);
              if ( v64 )
              {
                v69 = (int)(v64 - (v64 & 0xFFFFF000)) >> 3;
                v70 = *(_DWORD *)((v64 & 0xFFFFF000) + 4);
                v71 = v153;
                v55 = v70 + 4 * v69;
                if ( v155 && (v54 = (int *)ExpSetHandleExtraInfo(v153, v70 + 4 * v69)) != 0 )
                {
                  v54 = (int *)ExpFreeHandleTableEntry((int)v71, v55, v64, v139);
                  v55 = 0;
                }
                else
                {
                  if ( v71[15] )
                    v54 = (int *)ExpUpdateDebugInfo(v71, v53, v55, 1);
                  *(_DWORD *)(v64 + 4) = v157;
                  __dmb(0xBu);
                  *(_DWORD *)v64 = v166;
                }
                goto LABEL_134;
              }
              v59 = (unsigned int)j;
              v54 = v153;
              v56 = dword_92038C;
            }
            if ( ++v58 >= v56 )
              v58 = 0;
          }
          v77 = 1;
          if ( (v54[7] & 1) != 0 )
          {
            v79 = 0;
          }
          else
          {
            v78 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            if ( !dword_92038C )
              __brkdiv0();
            v79 = v78 % dword_92038C;
            v54 = v153;
          }
          v80 = (unsigned __int8 *)(v54 + 9);
          j = &v54[13 * v79];
          v81 = KeAbPreAcquire((unsigned int)(v54 + 9), 0, 0);
          v82 = v81;
          do
            v83 = __ldrex(v80);
          while ( __strex(v83 | 1, v80) );
          __dmb(0xBu);
          if ( (v83 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v80, v81, (unsigned int)v80);
          if ( v82 )
            *(_BYTE *)(v82 + 14) |= 1u;
          if ( v165 == *v153 )
            v77 = ExpAllocateHandleTableEntrySlow(v153, (int)(j + 10), v165, (int)j);
          __dmb(0xBu);
          do
            v84 = __ldrex((unsigned int *)v80);
          while ( __strex(v84 - 1, (unsigned int *)v80) );
          if ( (v84 & 2) != 0 && (v84 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v80);
          v54 = (int *)KeAbPostRelease((unsigned int)v80);
          if ( !v77 )
            break;
          v54 = v153;
        }
LABEL_134:
        v21 = (int)v150;
      }
      v72 = *(_WORD *)(v53 + 308) + 1;
      *(_WORD *)(v53 + 308) = v72;
      if ( !v72 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
        KiCheckForKernelApcDelivery((int)v54);
      if ( !v55 )
      {
        ObpDecrementHandleCount((int)v151, v21);
        if ( v173 )
        {
          if ( v173 > 1 )
          {
            __dmb(0xBu);
            do
              v140 = __ldrex((unsigned int *)v21);
            while ( __strex(v140 + 1 - v173, (unsigned int *)v21) );
          }
          v76 = a2;
          ObfDereferenceObject((int)a2);
        }
        else
        {
          v76 = a2;
        }
        v19 = -1073741670;
        v74 = v159;
        v75 = v163;
        v73 = v154;
        goto LABEL_315;
      }
      if ( !v2 )
      {
        v73 = v154;
LABEL_140:
        if ( v173 && v164 )
          *v164 = a2;
        if ( v162 )
          v19 = 0x40000000;
        else
          v19 = 0;
        v74 = v159;
        if ( v159 )
          v55 |= 0x80000000;
        v75 = v163;
        *v163 = v55;
        v76 = a2;
LABEL_315:
        if ( (int *)v161[0] != v161 )
          ObpPostInterceptHandleCreate(v76, v74, v19, v149, v161);
        if ( (dword_682610 & 0x40) != 0 && v19 >= 0 )
          EtwpTraceHandle(4384, *v75, v76, v73);
        return v19;
      }
      v141 = *(_BYTE *)(v21 + 14);
      v105 = 0;
      v101 = 0;
      v151 = 0;
      v155 = 0;
      if ( (v141 & 0x20) != 0 && (v85 = (unsigned int **)(v21 - ObpInfoMaskToOffset[v141 & 0x3F])) != 0 )
      {
        v142 = *v85;
        if ( v142 )
        {
          v101 = v142;
        }
        else if ( v156 )
        {
          ObpSetObjectAuditInfo(v21, v156);
          v105 = 0;
        }
        else if ( (void *)ObTypeIndexTable[*(unsigned __int8 *)(v21 + 12) ^ (unsigned __int8)ObHeaderCookie ^ v158] != IoFileObjectType
               || (*(_DWORD *)(a2[1] + 32) & 0x10) == 0 )
        {
          v143 = ObpAllocateAndQuerySecurityDescriptorInfo((int)a2, 32, &v155);
          v105 = (unsigned int)v155;
          v151 = v155;
          if ( v155 )
          {
            if ( v143 >= 0 )
            {
              v101 = v155;
              ObpSetObjectAuditInfo(v21, v155);
              v105 = (unsigned int)v101;
            }
          }
        }
      }
      else if ( v156 )
      {
        v101 = v156;
      }
      v86 = (int *)v2[12];
      v87 = 0;
      v150 = 0;
      v155 = (unsigned int *)v55;
      v88 = 0;
      if ( !v101 )
      {
        v101 = (unsigned int *)v86[12];
        if ( !v101 )
          v101 = (unsigned int *)v2[11];
      }
      if ( *((_BYTE *)v2 + 9) )
      {
        if ( *((_BYTE *)v2 + 96) )
        {
          SepAdtPrivilegeObjectAuditAlarm(
            (int)&SeSubsystemName,
            (int)(v2 + 27),
            (int)(v2 + 25),
            v55,
            v2[7],
            v2[9],
            v2[10],
            v2[5],
            *v86,
            1u);
          v105 = (unsigned int)v151;
          goto LABEL_184;
        }
        if ( *((_BYTE *)v2 + 9) )
          goto LABEL_334;
      }
      if ( *((_BYTE *)v86 + 192) )
      {
LABEL_334:
        if ( ZwDuplicateObject() >= 0 )
        {
          ObReferenceObjectByHandle((int)v150, 0, 0, 0, (int)&v158, 0);
          v87 = v158;
        }
        v144 = SepAdtClassifyObjectIntoSubCategory(v87, v2 + 27, 1, 0);
        v158 = v144;
        if ( v87 )
          ObfDereferenceObject(v87);
        if ( v150 )
        {
          ZwClose();
          v150 = 0;
        }
        v145 = PsGetCurrentThreadProcessId();
        v88 = SepAdtOpenObjectAuditAlarm(
                v144,
                &SeSubsystemName,
                &v155,
                v2 + 27,
                v2 + 25,
                v101,
                v2[7],
                v2[9],
                v2[6],
                v2[5],
                *v86,
                1,
                v145,
                2,
                0,
                0,
                0,
                v86 + 7,
                v2);
        v146 = PsGetCurrentThreadProcessId();
        SepAdtStagingEvent(v158, v147, &v155, v2 + 27, v2 + 25, v2[7], v2[9], v2[6], v2[5], 1, v146, v2);
        v105 = (unsigned int)v151;
      }
LABEL_184:
      v89 = v160;
      *((_BYTE *)v2 + 10) = v88;
      if ( !v89 )
      {
        v103 = __mrc(15, 0, 13, 0, 3);
        v104 = *(_DWORD **)v2[12];
        if ( v104 )
        {
          if ( *v104 )
          {
            SePrivilegeObjectAuditAlarm(v55, v2 + 7, v2[5], (int)v104, 1u, *(_BYTE *)((v103 & 0xFFFFFFC0) + 0x15A));
            v105 = (unsigned int)v151;
          }
        }
      }
      if ( v105 )
        ExFreePoolWithTag(v105);
      v73 = v154;
      if ( !v89 )
      {
        v19 = 0;
        if ( v154 == CmKeyObjectType || v154 == IoFileObjectType )
        {
          v90 = v2[7];
          if ( v90 )
          {
            v91 = v2[9];
            v92 = __mrc(15, 0, 13, 0, 3);
            --*(_WORD *)((v92 & 0xFFFFFFC0) + 0x134);
            if ( v91 >= v90 )
            {
              ExAcquireResourceSharedLite(*(_DWORD *)(v90 + 48), 1);
              v102 = __mrc(15, 0, 13, 0, 3);
              --*(_WORD *)((v102 & 0xFFFFFFC0) + 0x134);
              v94 = *(_DWORD *)(v91 + 48);
            }
            else
            {
              ExAcquireResourceSharedLite(*(_DWORD *)(v91 + 48), 1);
              v93 = __mrc(15, 0, 13, 0, 3);
              --*(_WORD *)((v93 & 0xFFFFFFC0) + 0x134);
              v94 = *(_DWORD *)(v90 + 48);
            }
            ExAcquireResourceSharedLite(v94, 1);
            if ( (*(_DWORD *)(v90 + 176) & 0x4000) != 0
              && *(int *)(v90 + 172) >= 2
              && !RtlEqualSid(**(unsigned __int16 ***)(v91 + 148), **(unsigned __int16 ***)(v90 + 148))
              && SepSidInTokenSidHash(
                   v91 + 492,
                   0,
                   (unsigned __int16 *)SeConstrainedImpersonationCapabilitySid,
                   0,
                   1,
                   0) )
            {
              v19 = ObHandleRevocationBlockAddObject(*(_DWORD *)(v90 + 192) + 72, a2);
            }
            v95 = ExReleaseResourceLite(*(_DWORD *)(v91 + 48));
            v96 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v97 = *(_WORD *)(v96 + 0x134) + 1;
            *(_WORD *)(v96 + 308) = v97;
            if ( !v97 && *(_DWORD *)(v96 + 100) != v96 + 100 && !*(_WORD *)(v96 + 310) )
              KiCheckForKernelApcDelivery(v95);
            v98 = ExReleaseResourceLite(*(_DWORD *)(v90 + 48));
            v99 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v100 = *(_WORD *)(v99 + 0x134) + 1;
            *(_WORD *)(v99 + 308) = v100;
            if ( !v100 && *(_DWORD *)(v99 + 100) != v99 + 100 && !*(_WORD *)(v99 + 310) )
              KiCheckForKernelApcDelivery(v98);
            if ( v19 < 0 )
              return v19;
          }
        }
      }
      goto LABEL_140;
    }
    v38 = (unsigned int *)(v29 - 8);
    do
      v39 = __ldrex(v38);
    while ( __strex(v39 + 7, v38) );
    if ( v39 <= 0 )
      __fastfail(0xEu);
LABEL_72:
    __pld(v26);
    v40 = *v26;
    if ( (*v26 & 7) == 0 )
    {
      while ( v29 == (v40 & 0xFFFFFFF8) )
      {
        do
          v41 = __ldrex(v26);
        while ( v41 == v40 && __strex(v40 + 7, v26) );
        __dmb(0xBu);
        if ( v41 == v40 )
          goto LABEL_38;
        v40 = v41;
        if ( (v41 & 7) != 0 )
          break;
      }
    }
    ObDereferenceSecurityDescriptor(v29, 7);
    goto LABEL_38;
  }
  if ( !v176 )
  {
LABEL_30:
    if ( *((_BYTE *)v2 + 10) )
    {
      v3 |= 4u;
      j = (int *)v3;
    }
    goto LABEL_32;
  }
  v19 = ObpInsertOrLocateNamedObject((int)v151, a2, &v149, v2, v175, v176, (int *)&v154);
  if ( v19 >= 0 )
  {
    v157 = (int)v154;
    if ( v154 == a2 )
    {
      v157 = 0;
    }
    else
    {
      a2 = v154;
      v162 = 1;
    }
    goto LABEL_30;
  }
  return v19;
}
