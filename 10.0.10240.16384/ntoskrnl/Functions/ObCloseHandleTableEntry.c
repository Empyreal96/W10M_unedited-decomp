// ObCloseHandleTableEntry 
 
int __fastcall ObCloseHandleTableEntry(int a1, unsigned int *a2, int a3, int a4, char a5, char a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, char a32)
{
  int v32; // lr
  int v33; // r6
  int v34; // r5
  int v38; // r1
  char v39; // r10
  unsigned int v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r1
  unsigned int v43; // r4
  int v44; // r0
  int v45; // r5
  unsigned int v46; // r2
  unsigned int v47; // r3
  int v48; // r3
  unsigned int v49; // r0
  int v50; // r0
  unsigned int v51; // r5
  unsigned int v52; // r1
  __int16 v53; // r3
  int v54; // r8
  int v55; // r7
  unsigned int *v56; // r2
  unsigned int v57; // r1
  unsigned int v58; // r1
  unsigned int v59; // r4
  int v60; // r10
  unsigned int *v61; // r2
  unsigned int v62; // r1
  unsigned int v63; // r0
  int v64; // r3
  unsigned __int8 *v65; // r10
  int v66; // r0
  int v67; // r4
  unsigned int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r1
  unsigned int v71; // r1
  int v72; // r1
  unsigned int v73; // r0
  unsigned int v74; // r2
  int v75; // r0
  unsigned int v76; // r1
  int v77; // r3
  int v78; // r3
  int v79; // r10
  unsigned __int8 *v80; // r4
  int v81; // r3
  int v82; // r0
  int v83; // r8
  unsigned int v84; // r2
  int v85; // r8
  int v87; // r1
  unsigned int v88; // r0
  unsigned int v89; // r2
  int v90; // r0
  unsigned int v91; // r1
  int v92; // r3
  unsigned int v93; // r4
  int v94; // r1
  unsigned int v95; // r0
  unsigned int v96; // r2
  int v97; // r0
  unsigned int v98; // r1
  __int16 v99; // r3
  int v100; // r3
  int v101; // r1
  unsigned __int8 *v102; // r0
  unsigned int v103; // r2
  int v104; // r3
  int v105; // r1
  unsigned int v106; // r2
  int v108; // r3
  unsigned int *v109; // r9
  int v110; // r1
  unsigned int v111; // r0
  unsigned int v112; // r2
  int v113; // r0
  unsigned int v114; // lr
  __int16 v115; // r2
  int v116; // r1
  unsigned int v117; // r0
  unsigned int v118; // r2
  int v119; // r0
  unsigned int v120; // r1
  __int16 v121; // r3
  int v122; // r1
  unsigned int v123; // r0
  unsigned int v124; // r2
  unsigned int v125; // r1
  int v126; // r3
  unsigned int *v127; // lr
  int v128; // r1
  unsigned int v129; // r0
  unsigned int v130; // r2
  int v131; // r0
  unsigned int v132; // r1
  __int16 v133; // r3
  int v134; // r1
  unsigned int v135; // r0
  unsigned int v136; // r2
  int v137; // r0
  unsigned int v138; // r1
  __int16 v139; // r3
  _DWORD *v140; // r0
  unsigned int v141; // r2
  char v142; // r3
  unsigned int v143; // r1
  int v144; // r1
  __int16 v145; // r3
  unsigned int v146; // r1
  int v147; // r0
  int v148; // r5
  unsigned int v149; // r2
  int v150; // r3
  int v151; // r3
  unsigned int v152; // r1
  unsigned int v155; // [sp+10h] [bp-78h]
  int v156; // [sp+14h] [bp-74h]
  char v157[24]; // [sp+38h] [bp-50h] BYREF
  int v158; // [sp+74h] [bp-14h] BYREF
  int v159; // [sp+78h] [bp-10h]
  int v160; // [sp+7Ch] [bp-Ch]
  int v161; // [sp+80h] [bp-8h]
  int v162; // [sp+84h] [bp-4h]
  __int64 savedregs; // [sp+88h] [bp+0h] BYREF

  v32 = a4;
  v33 = *a2 & 0xFFFFFFF8;
  v34 = ObTypeIndexTable[*(unsigned __int8 *)(v33 + 12) ^ (unsigned __int8)ObHeaderCookie ^ BYTE1(v33)];
  v156 = 0;
  if ( *(_DWORD *)(v34 + 116) )
  {
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a3 )
    {
      KiStackAttachProcess(a3, 0, (int)v157);
      v32 = a4;
      v156 = 1;
    }
    if ( !(*(int (__fastcall **)(int, int, int, _DWORD))(v34 + 116))(a3, v33 + 24, v32, a5) )
      return sub_80011C();
    v32 = a4;
    v38 = a5;
  }
  else
  {
    v38 = a32;
  }
  v141 = a2[1];
  v142 = *(_QWORD *)a2 & 6;
  if ( (v141 & 0x4000000) != 0 )
    v142 |= 8u;
  v50 = 1;
  if ( (v141 & 0x2000000) != 0 )
    v142 |= 1u;
  v39 = v142 & 5;
  if ( (v142 & 1) != 0 && !a6 )
  {
    if ( !v38 )
      KeBugCheckEx(147, v32, 0, 0, 0);
    __dmb(0xBu);
    do
      v143 = __ldrex(a2);
    while ( __strex(v143 + 1, a2) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(a1 + 32) )
      v50 = ExfUnblockPushLock(a1 + 32, 0);
    v144 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v145 = *(_WORD *)(v144 + 0x134) + 1;
    *(_WORD *)(v144 + 308) = v145;
    if ( !v145 && *(_DWORD *)(v144 + 100) != v144 + 100 && !*(_WORD *)(v144 + 310) )
      KiCheckForKernelApcDelivery(v50);
    if ( v161 )
      KiUnstackDetachProcess((unsigned int)&a10, 0);
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1
      || (NtGlobalFlag & 0x400000) == 0
      && !*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 340)
      && !*(_DWORD *)(a1 + 60) )
    {
      JUMPOUT(0x80017A);
    }
    return KeRaiseUserException(-1073741259, v144);
  }
  if ( (dword_682610 & 0x40) != 0 )
  {
    v146 = v32;
    if ( v159 == PsInitialSystemProcess )
      v146 = v32 | 0x80000000;
    EtwpTraceHandle(4385, v146, v33 + 24, v34);
    v32 = v158;
    v50 = 1;
  }
  if ( a6 )
  {
    v93 = a2[1];
    *a2 = 0;
    __dmb(0xFu);
    if ( *(_DWORD *)(a1 + 32) )
      v50 = ExfUnblockPushLock(a1 + 32, 0);
    v51 = v93 >> 27;
    goto LABEL_32;
  }
  if ( *(_DWORD *)(a1 + 60) )
  {
    ExpUpdateDebugInfo(a1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v32, 2);
    v32 = v158;
  }
  v40 = a2[1];
  *a2 = 0;
  v155 = v40;
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
  {
    ExfUnblockPushLock(a1 + 32, 0);
    v32 = v158;
  }
  if ( *(_DWORD *)(a1 + 4) )
  {
    v140 = (_DWORD *)ExpGetHandleExtraInfo(a1, v32 & 0xFFFFFFFC);
    if ( v140 )
      *v140 = 0;
  }
  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v42 = 0;
  }
  else
  {
    v41 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    if ( !dword_92038C )
      __brkdiv0();
    v42 = v41 % dword_92038C;
  }
  a2[1] = 0;
  v43 = a1 + 52 * v42 + 40;
  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v147 = KeAbPreAcquire(v43, 0, 0);
    v148 = v147;
    do
      v149 = __ldrex((unsigned __int8 *)v43);
    while ( __strex(v149 | 1, (unsigned __int8 *)v43) );
    __dmb(0xBu);
    if ( (v149 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v43, v147, v43);
    if ( v148 )
      *(_BYTE *)(v148 + 14) |= 1u;
    v150 = *(_DWORD *)(v43 + 8);
    if ( v150 )
      *(_DWORD *)(v150 + 4) = a2;
    else
      *(_DWORD *)(v43 + 4) = a2;
    v151 = *(_DWORD *)(v43 + 12);
    *(_DWORD *)(v43 + 8) = a2;
    *(_DWORD *)(v43 + 12) = v151 - 1;
    __dmb(0xBu);
    do
      v152 = __ldrex((unsigned int *)v43);
    while ( __strex(v152 - 1, (unsigned int *)v43) );
    if ( (v152 & 2) == 0 || (v152 & 4) != 0 )
      goto LABEL_31;
  }
  else
  {
    v44 = KeAbPreAcquire(v43, 0, 0);
    v45 = v44;
    do
      v46 = __ldrex((unsigned __int8 *)v43);
    while ( __strex(v46 | 1, (unsigned __int8 *)v43) );
    __dmb(0xBu);
    if ( (v46 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v43, v44, v43);
    if ( v45 )
      *(_BYTE *)(v45 + 14) |= 1u;
    v47 = *(_DWORD *)(v43 + 4);
    a2[1] = v47;
    if ( !v47 )
      *(_DWORD *)(v43 + 8) = a2;
    v48 = *(_DWORD *)(v43 + 12);
    *(_DWORD *)(v43 + 4) = a2;
    *(_DWORD *)(v43 + 12) = v48 - 1;
    __dmb(0xBu);
    do
      v49 = __ldrex((unsigned int *)v43);
    while ( __strex(v49 - 1, (unsigned int *)v43) );
    if ( (v49 & 2) == 0 || (v49 & 4) != 0 )
      goto LABEL_31;
  }
  ExfTryToWakePushLock((unsigned int *)v43);
LABEL_31:
  v50 = KeAbPostRelease(v43);
  v51 = v155 >> 27;
LABEL_32:
  v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v53 = *(_WORD *)(v52 + 0x134) + 1;
  *(_WORD *)(v52 + 308) = v53;
  if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
    KiCheckForKernelApcDelivery(v50);
  if ( (v39 & 4) != 0 )
    SeCloseObjectAuditAlarm(v33 + 24, v158 & 0xFFFFFFFC, 1);
  v54 = 0;
  v55 = ObTypeIndexTable[(unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v33 + 12) ^ BYTE1(v33)];
  if ( (*(_BYTE *)(v55 + 42) & 0x10) != 0 || (*(_BYTE *)(v33 + 15) & 8) != 0 )
  {
    v64 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v64 & 0xFFFFFFC0) + 0x134);
    v65 = (unsigned __int8 *)(v33 + 8);
    v66 = KeAbPreAcquire(v33 + 8, 0, 0);
    v67 = v66;
    do
      v68 = __ldrex(v65);
    while ( __strex(v68 | 1, v65) );
    __dmb(0xBu);
    if ( (v68 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v33 + 8), v66, v33 + 8);
    if ( v67 )
      *(_BYTE *)(v67 + 14) |= 1u;
    v59 = *(_DWORD *)(v33 + 4);
    __dmb(0xBu);
    v69 = (unsigned int *)(v33 + 4);
    do
    {
      v70 = __ldrex(v69);
      v71 = v70 - 1;
    }
    while ( __strex(v71, v69) );
    __dmb(0xBu);
    if ( !v71 && (*(_BYTE *)(v33 + 15) & 8) != 0 )
      *(_DWORD *)(v33 - ObpInfoMaskToOffset[*(_BYTE *)(v33 + 14) & 0x1F]) = 0;
    if ( (*(_BYTE *)(v55 + 42) & 0x10) != 0 )
    {
      ObpReleaseHandleInfo(v33, v159, &v158);
      v54 = v158;
    }
    __pld(v65);
    v72 = *(_DWORD *)v65;
    if ( (*(_DWORD *)v65 & 0xFFFFFFF0) > 0x10 )
      v73 = v72 - 16;
    else
      v73 = 0;
    if ( (v72 & 2) != 0 )
      goto LABEL_203;
    __dmb(0xBu);
    do
      v74 = __ldrex((unsigned int *)v65);
    while ( v74 == v72 && __strex(v73, (unsigned int *)v65) );
    if ( v74 != v72 )
LABEL_203:
      ExfReleasePushLock((_DWORD *)(v33 + 8), v72);
    v75 = KeAbPostRelease(v33 + 8);
    v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v77 = (__int16)(*(_WORD *)(v76 + 0x134) + 1);
    *(_WORD *)(v76 + 308) = v77;
    if ( !v77 && *(_DWORD *)(v76 + 100) != v76 + 100 && !*(_WORD *)(v76 + 310) )
      KiCheckForKernelApcDelivery(v75);
  }
  else
  {
    __dmb(0xBu);
    v56 = (unsigned int *)(v33 + 4);
    do
    {
      v57 = __ldrex(v56);
      v58 = v57 - 1;
    }
    while ( __strex(v58, v56) );
    __dmb(0xBu);
    v59 = v58 + 1;
  }
  if ( *(_DWORD *)(v55 + 96) )
  {
    v60 = 0;
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a3 )
    {
      v60 = 1;
      KiStackAttachProcess(a3, 0, (int)&a16);
    }
    (*(void (__fastcall **)(int, int, int, unsigned int))(v55 + 96))(a3, v33 + 24, v54, v59);
    if ( v60 )
      KiUnstackDetachProcess((unsigned int)&a16, 0);
  }
  if ( (*(_BYTE *)(v33 + 14) & 2) != 0 )
  {
    v78 = ObpInfoMaskToOffset[*(_BYTE *)(v33 + 14) & 3];
    v79 = v33 - v78;
    if ( v33 != v78 )
    {
      v80 = (unsigned __int8 *)(v33 + 8);
      while ( 1 )
      {
        v81 = __mrc(15, 0, 13, 0, 3);
        --*(_WORD *)((v81 & 0xFFFFFFC0) + 0x134);
        v82 = KeAbPreAcquire(v33 + 8, 0, 0);
        v83 = v82;
        do
          v84 = __ldrex(v80);
        while ( __strex(v84 | 1, v80) );
        __dmb(0xBu);
        if ( (v84 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v33 + 8), v82, v33 + 8);
        if ( v83 )
          *(_BYTE *)(v83 + 14) |= 1u;
        v85 = *(_DWORD *)v79;
        if ( !*(_DWORD *)v79 )
          break;
        if ( (*(_BYTE *)(v33 + 15) & 0x10) != 0 || *(_DWORD *)(v33 + 4) )
        {
          __pld(v80);
          v87 = *(_DWORD *)v80;
          if ( (*(_DWORD *)v80 & 0xFFFFFFF0) > 0x10 )
            v88 = v87 - 16;
          else
            v88 = 0;
          if ( (v87 & 2) != 0 )
            goto LABEL_206;
          __dmb(0xBu);
          do
            v89 = __ldrex((unsigned int *)v80);
          while ( v89 == v87 && __strex(v88, (unsigned int *)v80) );
          if ( v89 != v87 )
LABEL_206:
            ExfReleasePushLock((_DWORD *)(v33 + 8), v87);
          v90 = KeAbPostRelease(v33 + 8);
          v91 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v92 = (__int16)(*(_WORD *)(v91 + 0x134) + 1);
          *(_WORD *)(v91 + 308) = v92;
          if ( v92 || *(_DWORD *)(v91 + 100) == v91 + 100 || *(_WORD *)(v91 + 310) )
            goto LABEL_47;
LABEL_102:
          KiCheckForKernelApcDelivery(v90);
          goto LABEL_47;
        }
        ObfReferenceObject(*(_DWORD *)v79);
        __pld(v80);
        v94 = *(_DWORD *)v80;
        if ( (*(_DWORD *)v80 & 0xFFFFFFF0) > 0x10 )
          v95 = v94 - 16;
        else
          v95 = 0;
        if ( (v94 & 2) != 0 )
          goto LABEL_255;
        __dmb(0xBu);
        do
          v96 = __ldrex((unsigned int *)v80);
        while ( v96 == v94 && __strex(v95, (unsigned int *)v80) );
        if ( v96 != v94 )
LABEL_255:
          ExfReleasePushLock((_DWORD *)(v33 + 8), v94);
        v97 = KeAbPostRelease(v33 + 8);
        v98 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v99 = *(_WORD *)(v98 + 0x134) + 1;
        *(_WORD *)(v98 + 308) = v99;
        if ( !v99 && *(_DWORD *)(v98 + 100) != v98 + 100 && !*(_WORD *)(v98 + 310) )
          KiCheckForKernelApcDelivery(v97);
        v100 = __mrc(15, 0, 13, 0, 3);
        --*(_WORD *)((v100 & 0xFFFFFFC0) + 0x134);
        v101 = KeAbPreAcquire(v85 + 148, 0, 0);
        v160 = v101;
        v102 = (unsigned __int8 *)(v85 + 148);
        do
          v103 = __ldrex(v102);
        while ( __strex(v103 | 1, v102) );
        __dmb(0xBu);
        if ( (v103 & 1) != 0 )
        {
          ExfAcquirePushLockExclusiveEx(v102, v101, v85 + 148);
          v101 = v160;
        }
        if ( v101 )
          *(_BYTE *)(v101 + 14) |= 1u;
        ObfReferenceObject(v85);
        v159 = v85;
        HIDWORD(savedregs) = v85;
        v104 = __mrc(15, 0, 13, 0, 3);
        --*(_WORD *)((v104 & 0xFFFFFFC0) + 0x134);
        v105 = KeAbPreAcquire(v33 + 8, 0, 0);
        v160 = v105;
        do
          v106 = __ldrex(v80);
        while ( __strex(v106 | 1, v80) );
        __dmb(0xBu);
        if ( (v106 & 1) != 0 )
        {
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v33 + 8), v105, v33 + 8);
          v105 = v160;
        }
        if ( v105 )
          *(_BYTE *)(v105 + 14) |= 1u;
        if ( *(_DWORD *)v79 == v85 && (*(_BYTE *)(v33 + 15) & 0x10) == 0 && !*(_DWORD *)(v33 + 4) )
        {
          if ( *(_DWORD *)(v79 + 12) )
          {
            v108 = v85;
          }
          else
          {
            if ( ObTypeIndexTable[(unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v33 + 12) ^ v162] == ObpSymbolicLinkObjectType )
              ObpDeleteSymbolicLinkName(v33 + 24);
            ObpLookupDirectoryEntry(*(_DWORD *)v79, (unsigned __int16 *)(v79 + 4), 0, 0, (int)&savedregs + 4);
            ObpDeleteDirectoryEntry((int *)&savedregs + 1);
            v108 = HIDWORD(savedregs);
            v159 = HIDWORD(savedregs);
          }
          v109 = (unsigned int *)(v108 + 148);
          __pld((void *)(v108 + 148));
          v110 = *(_DWORD *)(v108 + 148);
          if ( (v110 & 0xFFFFFFF0) > 0x10 )
            v111 = v110 - 16;
          else
            v111 = 0;
          if ( (v110 & 2) != 0 )
            goto LABEL_165;
          __dmb(0xBu);
          do
            v112 = __ldrex(v109);
          while ( v112 == v110 && __strex(v111, v109) );
          if ( v112 != v110 )
LABEL_165:
            ExfReleasePushLock(v109, v110);
          KeAbPostRelease((unsigned int)v109);
          v113 = ObfDereferenceObject(v159);
          v114 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v115 = *(_WORD *)(v114 + 0x134);
          *(_WORD *)(v114 + 308) = v115 + 1;
          if ( v115 == -1 && *(_DWORD *)(v114 + 100) != v114 + 100 && !*(_WORD *)(v114 + 310) )
            KiCheckForKernelApcDelivery(v113);
          __pld(v80);
          v116 = *(_DWORD *)v80;
          if ( (*(_DWORD *)v80 & 0xFFFFFFF0) > 0x10 )
            v117 = v116 - 16;
          else
            v117 = 0;
          if ( (v116 & 2) != 0 )
            goto LABEL_201;
          __dmb(0xBu);
          do
            v118 = __ldrex((unsigned int *)v80);
          while ( v118 == v116 && __strex(v117, (unsigned int *)v80) );
          if ( v118 != v116 )
LABEL_201:
            ExfReleasePushLock((_DWORD *)(v33 + 8), v116);
          v119 = KeAbPostRelease(v33 + 8);
          v120 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v121 = *(_WORD *)(v120 + 0x134) + 1;
          *(_WORD *)(v120 + 308) = v121;
          if ( !v121 && *(_DWORD *)(v120 + 100) != v120 + 100 && !*(_WORD *)(v120 + 310) )
            KiCheckForKernelApcDelivery(v119);
          PspDereferenceSiloObject(v85);
          goto LABEL_47;
        }
        v127 = (unsigned int *)(v85 + 148);
        __pld((void *)(v85 + 148));
        v128 = *(_DWORD *)(v85 + 148);
        if ( (v128 & 0xFFFFFFF0) > 0x10 )
          v129 = v128 - 16;
        else
          v129 = 0;
        if ( (v128 & 2) != 0 )
          goto LABEL_258;
        __dmb(0xBu);
        do
          v130 = __ldrex(v127);
        while ( v130 == v128 && __strex(v129, v127) );
        if ( v130 != v128 )
        {
LABEL_258:
          ExfReleasePushLock((_DWORD *)(v85 + 148), v128);
          v127 = (unsigned int *)(v85 + 148);
        }
        KeAbPostRelease((unsigned int)v127);
        v131 = ObfDereferenceObject(v85);
        HIDWORD(savedregs) = 0;
        v132 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v133 = *(_WORD *)(v132 + 0x134) + 1;
        *(_WORD *)(v132 + 308) = v133;
        if ( !v133 && *(_DWORD *)(v132 + 100) != v132 + 100 && !*(_WORD *)(v132 + 310) )
          KiCheckForKernelApcDelivery(v131);
        __pld(v80);
        v134 = *(_DWORD *)v80;
        if ( (*(_DWORD *)v80 & 0xFFFFFFF0) > 0x10 )
          v135 = v134 - 16;
        else
          v135 = 0;
        if ( (v134 & 2) != 0 )
          goto LABEL_213;
        __dmb(0xBu);
        do
          v136 = __ldrex((unsigned int *)v80);
        while ( v136 == v134 && __strex(v135, (unsigned int *)v80) );
        if ( v136 != v134 )
LABEL_213:
          ExfReleasePushLock((_DWORD *)(v33 + 8), v134);
        v137 = KeAbPostRelease(v33 + 8);
        v138 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v139 = *(_WORD *)(v138 + 0x134) + 1;
        *(_WORD *)(v138 + 308) = v139;
        if ( !v139 && *(_DWORD *)(v138 + 100) != v138 + 100 && !*(_WORD *)(v138 + 310) )
          KiCheckForKernelApcDelivery(v137);
        PspDereferenceSiloObject(v85);
      }
      __pld(v80);
      v122 = *(_DWORD *)v80;
      if ( (*(_DWORD *)v80 & 0xFFFFFFF0) > 0x10 )
        v123 = v122 - 16;
      else
        v123 = 0;
      if ( (v122 & 2) != 0 )
        goto LABEL_262;
      __dmb(0xBu);
      do
        v124 = __ldrex((unsigned int *)v80);
      while ( v124 == v122 && __strex(v123, (unsigned int *)v80) );
      if ( v124 != v122 )
LABEL_262:
        ExfReleasePushLock((_DWORD *)(v33 + 8), v122);
      v90 = KeAbPostRelease(v33 + 8);
      v125 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v126 = (__int16)(*(_WORD *)(v125 + 0x134) + 1);
      *(_WORD *)(v125 + 308) = v126;
      if ( !v126 && *(_DWORD *)(v125 + 100) != v125 + 100 && !*(_WORD *)(v125 + 310) )
        goto LABEL_102;
    }
  }
LABEL_47:
  __dmb(0xBu);
  v61 = (unsigned int *)(v55 + 28);
  do
    v62 = __ldrex(v61);
  while ( __strex(v62 - 1, v61) );
  __dmb(0xBu);
  if ( v156 )
    KiUnstackDetachProcess((unsigned int)&a10, 0);
  if ( v51 )
  {
    __dmb(0xBu);
    do
      v63 = __ldrex((unsigned int *)v33);
    while ( __strex(v63 - v51, (unsigned int *)v33) );
  }
  ObfDereferenceObjectWithTag(v33 + 24);
  return 0;
}
