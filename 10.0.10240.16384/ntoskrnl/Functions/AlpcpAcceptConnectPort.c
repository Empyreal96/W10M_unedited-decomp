// AlpcpAcceptConnectPort 
 
int __fastcall AlpcpAcceptConnectPort(_DWORD *a1, int a2, int a3, int a4, unsigned int a5, int a6, _DWORD *a7, int a8, unsigned __int8 a9, unsigned int a10, unsigned int a11, unsigned __int8 a12)
{
  _DWORD *v13; // r2
  int v14; // r1
  int v15; // r0
  int v16; // r1
  int v17; // r1
  int v18; // r4
  _DWORD *v19; // r3
  int v20; // r1
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r6
  _DWORD *v27; // r10
  int v28; // r2
  int v29; // r0
  int v30; // r6
  int v31; // r8
  unsigned int *v32; // r5
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r0
  int v36; // r0
  int v37; // r1
  int v38; // r10
  unsigned int *v39; // r8
  unsigned int v40; // r1
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v43; // r0
  _DWORD *v44; // r5
  int v45; // r8
  unsigned int *v46; // r5
  unsigned int v47; // r1
  unsigned int *v48; // r2
  unsigned int v49; // r0
  int v50; // r0
  unsigned __int8 *v51; // r4
  int v52; // r0
  int v53; // r8
  unsigned int v54; // r2
  int v55; // r3
  unsigned int v56; // r1
  _DWORD *v57; // r8
  int v58; // r10
  unsigned int *v59; // r8
  unsigned int v60; // r1
  unsigned int *v61; // r2
  unsigned int v62; // r0
  int v63; // r0
  int v64; // r10
  unsigned int *v65; // r9
  unsigned int v66; // r1
  unsigned int *v67; // r2
  unsigned int v68; // r0
  int v69; // r0
  _DWORD *v70; // r1
  int v71; // r10
  unsigned int *v72; // r9
  unsigned int v73; // r1
  unsigned int *v74; // r2
  unsigned int v75; // r0
  int v76; // r0
  _DWORD *v77; // r1
  int v78; // lr
  int v79; // r4
  int v80; // r0
  unsigned int *v81; // lr
  unsigned int v82; // r1
  int v83; // r4
  unsigned __int8 *v84; // r0
  unsigned int v85; // r2
  int v86; // r2
  int v87; // r0
  unsigned int *v88; // r4
  unsigned int v89; // r1
  int v90; // r10
  unsigned int *v91; // r9
  unsigned int v92; // r1
  unsigned int *v93; // r2
  unsigned int v94; // r0
  int v95; // r0
  int v96; // r10
  unsigned int *v97; // r9
  unsigned int v98; // r1
  unsigned int *v99; // r2
  unsigned int v100; // r0
  int v101; // r0
  int v102; // r10
  unsigned int *v103; // r9
  unsigned int v104; // r1
  unsigned int *v105; // r2
  unsigned int v106; // r0
  int v107; // r0
  int v108; // r10
  unsigned int *v109; // r9
  unsigned int v110; // r1
  unsigned int *v111; // r2
  unsigned int v112; // r0
  int v113; // r0
  int v114; // r1
  int v115; // r2
  int v116; // r3
  int v117; // r1
  int v118; // r2
  int v119; // r3
  int v120; // r4
  int v121; // r2
  char v122; // r3
  int v123; // r3
  _DWORD *v124; // r5
  int v125; // r1
  int v126; // r2
  int v127; // r3
  _DWORD *v128; // r5
  int v129; // r3
  _DWORD *v130; // r4
  int v131; // r2
  int v132; // r3
  int v133; // r0
  int v135; // [sp+18h] [bp-120h] BYREF
  int v136; // [sp+1Ch] [bp-11Ch]
  _BYTE *v137; // [sp+20h] [bp-118h] BYREF
  _DWORD *v138; // [sp+24h] [bp-114h] BYREF
  char v139; // [sp+28h] [bp-110h]
  _DWORD *v140; // [sp+2Ch] [bp-10Ch]
  int v141; // [sp+30h] [bp-108h]
  int v142; // [sp+34h] [bp-104h]
  int v143; // [sp+38h] [bp-100h]
  _DWORD *v144; // [sp+3Ch] [bp-FCh]
  unsigned int v145; // [sp+40h] [bp-F8h]
  _DWORD *v146; // [sp+44h] [bp-F4h]
  int v147; // [sp+48h] [bp-F0h]
  _DWORD *v148; // [sp+4Ch] [bp-ECh]
  int v149; // [sp+50h] [bp-E8h]
  int v150; // [sp+54h] [bp-E4h] BYREF
  _DWORD *v151; // [sp+58h] [bp-E0h]
  int v152; // [sp+5Ch] [bp-DCh]
  _DWORD *v153; // [sp+60h] [bp-D8h]
  int v154; // [sp+64h] [bp-D4h]
  unsigned int v155; // [sp+68h] [bp-D0h]
  unsigned int v156; // [sp+6Ch] [bp-CCh]
  int v157; // [sp+70h] [bp-C8h]
  int v158; // [sp+74h] [bp-C4h]
  int v159; // [sp+78h] [bp-C0h]
  int v160; // [sp+80h] [bp-B8h] BYREF
  int v161; // [sp+84h] [bp-B4h]
  int v162; // [sp+88h] [bp-B0h]
  _DWORD v163[2]; // [sp+90h] [bp-A8h] BYREF
  int v164; // [sp+98h] [bp-A0h]
  int v165; // [sp+9Ch] [bp-9Ch]
  int v166; // [sp+A0h] [bp-98h]
  int v167; // [sp+A4h] [bp-94h]
  int v168; // [sp+A8h] [bp-90h] BYREF
  _DWORD v169[5]; // [sp+ACh] [bp-8Ch] BYREF
  _DWORD v170[7]; // [sp+C0h] [bp-78h] BYREF
  __int16 v171; // [sp+DCh] [bp-5Ch]
  __int16 v172; // [sp+DEh] [bp-5Ah]
  __int16 v173; // [sp+E0h] [bp-58h]
  _DWORD v174[20]; // [sp+E8h] [bp-50h] BYREF

  v147 = a4;
  v135 = a3;
  v146 = a1;
  v140 = a1;
  v159 = a3;
  v157 = a4;
  v145 = a5;
  v155 = a5;
  v151 = a7;
  v153 = a7;
  v152 = a8;
  v158 = a8;
  v144 = (_DWORD *)a10;
  v156 = a10;
  v148 = (_DWORD *)a11;
  v138 = (_DWORD *)a11;
  v149 = 0;
  v141 = 0;
  v174[0] = 0;
  memset(&v174[1], 0, 40);
  v168 = 0;
  memset(v169, 0, sizeof(v169));
  v160 = 0;
  v161 = 0;
  v162 = 0;
  v143 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v139 = v143;
  if ( !v143 )
  {
    if ( a5 )
      memmove((int)v174, a5, 0x2Cu);
    v22 = a7[1];
    v23 = a7[2];
    v24 = a7[3];
    v163[0] = *a7;
    v163[1] = v22;
    v164 = v23;
    v165 = v24;
    v25 = a7[5];
    v166 = a7[4];
    v167 = v25;
    v20 = a12;
    v136 = a12;
    v137 = (_BYTE *)a9;
    v21 = v135;
    goto LABEL_39;
  }
  v136 = a12;
  if ( a12 )
  {
    v137 = (_BYTE *)a9;
    goto LABEL_6;
  }
  v137 = (_BYTE *)a9;
  if ( a9 )
  {
LABEL_6:
    v13 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v13 = (_DWORD *)MmUserProbeAddress;
    *v13 = *v13;
  }
  v14 = (int)a7;
  if ( (unsigned int)a7 >= MmUserProbeAddress )
    v14 = MmUserProbeAddress;
  v15 = memmove((int)v163, v14, 0x18u);
  if ( a5 )
  {
    v16 = a5;
    if ( a5 >= MmUserProbeAddress )
      v16 = MmUserProbeAddress;
    v15 = memmove((int)v174, v16, 0x2Cu);
  }
  if ( a10 )
  {
    v17 = a10;
    if ( a10 >= MmUserProbeAddress )
      v17 = MmUserProbeAddress;
    v15 = memmove((int)&v168, v17, 0x18u);
    if ( v168 != 24 )
    {
      v18 = -1073741811;
      v142 = -1073741811;
      return v18;
    }
    if ( (a10 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v15);
    if ( a10 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a10 = *(_BYTE *)a10;
    *(_BYTE *)(a10 + 20) = *(_BYTE *)(a10 + 20);
  }
  if ( a11 )
  {
    v19 = (_DWORD *)a11;
    if ( a11 >= MmUserProbeAddress )
      v19 = (_DWORD *)MmUserProbeAddress;
    if ( *v19 != 12 )
    {
      v18 = -1073741811;
      v142 = -1073741811;
      return v18;
    }
    if ( (a11 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v15);
    if ( a11 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a11 = *(_BYTE *)a11;
    *(_BYTE *)(a11 + 8) = *(_BYTE *)(a11 + 8);
  }
  v20 = v136;
  v21 = v135;
LABEL_39:
  v26 = v166;
  if ( !v166 )
    return -1073741281;
  v27 = 0;
  if ( v21 )
  {
    v18 = ObReferenceObjectByHandle(v21, 1, AlpcPortObjectType, v143, &v138);
    v27 = v138;
    if ( v18 < 0 )
      return v18;
    v28 = v167;
  }
  else
  {
    if ( !v20 )
      return -1073741504;
    v28 = 0;
  }
  v18 = AlpcpLookupMessage(v27, v26, v28, &v135);
  if ( v18 < 0 )
  {
    if ( !v27 )
      return v18;
    v29 = (int)v27;
LABEL_49:
    ObfDereferenceObject(v29);
    return v18;
  }
  if ( v27 )
  {
    ObfDereferenceObject((int)v27);
    v30 = v135;
  }
  else
  {
    v30 = v135;
    v27 = *(_DWORD **)(v135 + 8);
  }
  if ( (*(_DWORD *)(v30 + 20) & 0x80) != 0 )
  {
    v18 = -1073740029;
LABEL_131:
    AlpcpCancelMessage(v27, v30, 0x10000);
    return v18;
  }
  if ( (*(unsigned __int16 *)(v30 + 124) & 0xFFFF00FF) != 10 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v30);
    v31 = 0;
    if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
    {
      v31 = 0x10000 - *(__int16 *)(v30 - 14);
      *(_BYTE *)(v30 - 16) &= 0xFEu;
      *(_WORD *)(v30 - 14) = 0;
    }
    v32 = (unsigned int *)(v30 - 4);
    __dmb(0xBu);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 - 1, v32) );
    if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v30 - 4));
    KeAbPostRelease(v30 - 4);
    if ( v31 <= 0 )
      return -1073741281;
    __dmb(0xBu);
    v34 = (unsigned int *)(v30 - 12);
    do
    {
      v35 = __ldrex(v34);
      v36 = v35 - v31;
    }
    while ( __strex(v36, v34) );
    __dmb(0xBu);
    if ( v36 > 0 )
      return -1073741281;
    if ( v36 )
      KeBugCheckEx(24, 0, v30, 40, v36);
    goto LABEL_71;
  }
  v141 = SLOWORD(v163[0]);
  if ( v136 )
  {
    v37 = v27[42];
    if ( LOWORD(v163[0]) > (unsigned int)(v37 - 24) )
      v141 = (__int16)(v37 - 24);
  }
  else if ( LOWORD(v163[0]) >= (unsigned int)(unsigned __int16)(LOWORD(v163[0]) + 24)
         || LOWORD(v163[0]) + 24 != HIWORD(v163[0]) )
  {
    v18 = -1073741811;
    goto LABEL_80;
  }
  v18 = 0;
LABEL_80:
  if ( v18 < 0 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v30);
    v38 = 0;
    if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
    {
      v38 = 0x10000 - *(__int16 *)(v30 - 14);
      *(_BYTE *)(v30 - 16) &= 0xFEu;
      *(_WORD *)(v30 - 14) = 0;
    }
    v39 = (unsigned int *)(v30 - 4);
    __dmb(0xBu);
    do
      v40 = __ldrex(v39);
    while ( __strex(v40 - 1, v39) );
    if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v30 - 4));
    KeAbPostRelease(v30 - 4);
    if ( v38 > 0 )
    {
      __dmb(0xBu);
      v41 = (unsigned int *)(v30 - 12);
      do
      {
        v42 = __ldrex(v41);
        v43 = v42 - v38;
      }
      while ( __strex(v43, v41) );
      __dmb(0xBu);
      if ( v43 <= 0 )
      {
        if ( v43 )
          KeBugCheckEx(24, 0, v30, 40, v43);
LABEL_96:
        AlpcpDestroyBlob(v30);
        return v18;
      }
    }
    return v18;
  }
  v44 = *(_DWORD **)(v30 + 12);
  v140 = (_DWORD *)v44[2];
  if ( (v44[61] & 0x20) != 0 )
  {
    v18 = -1073741769;
    goto LABEL_131;
  }
  if ( (v27[38] & 0x100000) == 0 && *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != v27[3] )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v30);
    v45 = 0;
    if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
    {
      v45 = 0x10000 - *(__int16 *)(v30 - 14);
      *(_BYTE *)(v30 - 16) &= 0xFEu;
      *(_WORD *)(v30 - 14) = 0;
    }
    v46 = (unsigned int *)(v30 - 4);
    __dmb(0xBu);
    do
      v47 = __ldrex(v46);
    while ( __strex(v47 - 1, v46) );
    if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v30 - 4));
    KeAbPostRelease(v30 - 4);
    if ( v45 <= 0 )
      return -1073741281;
    __dmb(0xBu);
    v48 = (unsigned int *)(v30 - 12);
    do
    {
      v49 = __ldrex(v48);
      v50 = v49 - v45;
    }
    while ( __strex(v50, v48) );
    __dmb(0xBu);
    if ( v50 > 0 )
      return -1073741281;
    if ( v50 )
      KeBugCheckEx(24, 0, v30, 40, v50);
LABEL_71:
    AlpcpDestroyBlob(v30);
    return -1073741281;
  }
  if ( !v137 )
  {
    v51 = (unsigned __int8 *)(v44 + 52);
    v52 = KeAbPreAcquire((unsigned int)(v44 + 52), 0, 0);
    v53 = v52;
    do
      v54 = __ldrex(v51);
    while ( __strex(v54 | 1, v51) );
    __dmb(0xBu);
    if ( (v54 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v44 + 52, v52, (unsigned int)(v44 + 52));
    if ( v53 )
      *(_BYTE *)(v53 + 14) |= 1u;
    v55 = v44[61] | 0x10;
    v44[61] = v55;
    if ( (v55 & 0x100) != 0 )
      v44[7] = a6;
    __dmb(0xBu);
    do
      v56 = __ldrex((unsigned int *)v51);
    while ( __strex(v56 - 1, (unsigned int *)v51) );
    if ( (v56 & 2) != 0 && (v56 & 4) == 0 )
      ExfTryToWakePushLock(v44 + 52);
    KeAbPostRelease((unsigned int)(v44 + 52));
    v18 = 0;
    goto LABEL_131;
  }
  v18 = ObCreateObject(v143, AlpcPortObjectType, v147, v143, 0, 284, 0, 0, &v137);
  v57 = v137;
  if ( v18 >= 0 )
  {
    memset(v137, 0, 284);
    v18 = AlpcpInitializePort(v57, 3, 0);
    if ( v18 < 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v30);
      v64 = 0;
      if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
      {
        v64 = 0x10000 - *(__int16 *)(v30 - 14);
        *(_BYTE *)(v30 - 16) &= 0xFEu;
        *(_WORD *)(v30 - 14) = 0;
      }
      v65 = (unsigned int *)(v30 - 4);
      __dmb(0xBu);
      do
        v66 = __ldrex(v65);
      while ( __strex(v66 - 1, v65) );
      if ( (v66 & 2) != 0 && (v66 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v30 - 4));
      KeAbPostRelease(v30 - 4);
      if ( v64 <= 0 )
        goto LABEL_166;
      __dmb(0xBu);
      v67 = (unsigned int *)(v30 - 12);
      do
      {
        v68 = __ldrex(v67);
        v69 = v68 - v64;
      }
      while ( __strex(v69, v67) );
      __dmb(0xBu);
      if ( v69 > 0 )
        goto LABEL_166;
      if ( v69 )
        KeBugCheckEx(24, 0, v30, 40, v69);
      goto LABEL_165;
    }
    if ( v145 )
      v70 = v174;
    else
      v70 = 0;
    v18 = AlpcpValidateAndSetPortAttributes(v57, v70, v27, 0, 0, 0, v136);
    if ( v18 < 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v30);
      v71 = 0;
      if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
      {
        v71 = 0x10000 - *(__int16 *)(v30 - 14);
        *(_BYTE *)(v30 - 16) &= 0xFEu;
        *(_WORD *)(v30 - 14) = 0;
      }
      v72 = (unsigned int *)(v30 - 4);
      __dmb(0xBu);
      do
        v73 = __ldrex(v72);
      while ( __strex(v73 - 1, v72) );
      if ( (v73 & 2) != 0 && (v73 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v30 - 4));
      KeAbPostRelease(v30 - 4);
      if ( v71 <= 0 )
        goto LABEL_166;
      __dmb(0xBu);
      v74 = (unsigned int *)(v30 - 12);
      do
      {
        v75 = __ldrex(v74);
        v76 = v75 - v71;
      }
      while ( __strex(v76, v74) );
      __dmb(0xBu);
      if ( v76 > 0 )
        goto LABEL_166;
      if ( v76 )
        KeBugCheckEx(24, 0, v30, 40, v76);
      goto LABEL_165;
    }
    if ( v145 )
      v77 = v174;
    else
      v77 = 0;
    AlpcpSetOwnerProcessPort(v57, v77);
    if ( v136 )
      v57[61] |= 0x1000u;
    v78 = (int)v140;
    v79 = *(v140 - 3);
    v138 = v140 - 3;
    while ( v79 > 0 )
    {
      v80 = v79;
      __dmb(0xBu);
      v81 = v138;
      do
        v82 = __ldrex(v81);
      while ( v82 == v79 && __strex(v79 + 1, v81) );
      v79 = v82;
      __dmb(0xBu);
      v78 = (int)v140;
      if ( v82 == v80 )
        goto LABEL_200;
    }
    if ( v79 )
      KeBugCheckEx(24, 0, v78, 32, v79);
LABEL_200:
    v138 = (_DWORD *)(v78 - 4);
    v83 = KeAbPreAcquire(v78 - 4, 0, 0);
    v84 = (unsigned __int8 *)v138;
    do
      v85 = __ldrex(v84);
    while ( __strex(v85 | 1, v84) );
    __dmb(0xBu);
    if ( (v85 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v84, v83, (unsigned int)v84);
    if ( v83 )
      *(_BYTE *)(v83 + 14) |= 1u;
    v86 = (int)v140;
    v57[2] = v140;
    *(_DWORD *)(v86 + 4) = v57;
    v44[62] = v27;
    v44[63] = v57;
    v57[62] = v44;
    v57[63] = v44;
    v87 = v44[61];
    if ( (v87 & 0x1000) != 0 && (v57[61] & 0x1000) != 0 )
    {
      v44[61] = v87 | 0x2000;
      v57[61] |= 0x2000u;
    }
    v88 = (unsigned int *)(v86 - 4);
    __dmb(0xBu);
    do
      v89 = __ldrex(v88);
    while ( __strex(v89 - 1, v88) );
    if ( (v89 & 2) != 0 && (v89 & 4) == 0 )
      ExfTryToWakePushLock(v88);
    KeAbPostRelease((unsigned int)v88);
    v171 = v141 + 24;
    v172 = 11;
    v173 = 0;
    v18 = AlpcpSetupMessageDataForDeferredCopy(v30, v151, v141, (unsigned __int16)v141, 0, v143);
    if ( v18 < 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v30);
      if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
      {
        v90 = 0x10000 - *(__int16 *)(v30 - 14);
        *(_BYTE *)(v30 - 16) &= 0xFEu;
        *(_WORD *)(v30 - 14) = 0;
      }
      else
      {
        v90 = 0;
      }
      v91 = (unsigned int *)(v30 - 4);
      __dmb(0xBu);
      do
        v92 = __ldrex(v91);
      while ( __strex(v92 - 1, v91) );
      if ( (v92 & 2) != 0 && (v92 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v30 - 4));
      KeAbPostRelease(v30 - 4);
      if ( v90 <= 0 )
        goto LABEL_166;
      __dmb(0xBu);
      v93 = (unsigned int *)(v30 - 12);
      do
      {
        v94 = __ldrex(v93);
        v95 = v94 - v90;
      }
      while ( __strex(v95, v93) );
      __dmb(0xBu);
      if ( v95 > 0 )
        goto LABEL_166;
      if ( v95 )
        KeBugCheckEx(24, 0, v30, 40, v95);
      goto LABEL_165;
    }
    if ( v136 )
    {
      if ( *(_DWORD *)(v30 + 76) )
      {
        v18 = AlpcpMapLegacyPortRemoteView(v57, v30 + 56, &v160);
        if ( v18 < 0 )
        {
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v30);
          if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
          {
            v96 = 0x10000 - *(__int16 *)(v30 - 14);
            *(_BYTE *)(v30 - 16) &= 0xFEu;
            *(_WORD *)(v30 - 14) = 0;
          }
          else
          {
            v96 = 0;
          }
          v97 = (unsigned int *)(v30 - 4);
          __dmb(0xBu);
          do
            v98 = __ldrex(v97);
          while ( __strex(v98 - 1, v97) );
          if ( (v98 & 2) != 0 && (v98 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v30 - 4));
          KeAbPostRelease(v30 - 4);
          if ( v96 <= 0 )
            goto LABEL_166;
          __dmb(0xBu);
          v99 = (unsigned int *)(v30 - 12);
          do
          {
            v100 = __ldrex(v99);
            v101 = v100 - v96;
          }
          while ( __strex(v101, v99) );
          __dmb(0xBu);
          if ( v101 > 0 )
            goto LABEL_166;
          if ( v101 )
            KeBugCheckEx(24, 0, v30, 40, v101);
LABEL_165:
          AlpcpDestroyBlob(v30);
LABEL_166:
          v29 = (int)v57;
          goto LABEL_49;
        }
      }
    }
    if ( v144 )
    {
      memset(v174, 0, 32);
      v18 = AlpcpMapLegacyPortView((int)v57, &v168, (int)v174);
      if ( v18 < 0 )
        goto LABEL_256;
      v18 = AlpcpMapLegacyPortRemoteView(v44, v174, v163);
      if ( v18 < 0 )
        goto LABEL_256;
      v169[4] = v164;
    }
    else
    {
      v18 = AlpcpCaptureAttributes(v27, v149, v152, v30, v174);
    }
    if ( v18 >= 0 )
    {
      ObfReferenceObject((int)v57);
      v18 = ObInsertObject(v57, 0, 2031617, 0, 0, &v150);
      if ( v18 >= 0 )
      {
        AlpcpReleaseAttributes(v30 + 56);
        v114 = v174[1];
        v115 = v174[2];
        v116 = v174[3];
        *(_DWORD *)(v30 + 56) = v174[0];
        *(_DWORD *)(v30 + 60) = v114;
        *(_DWORD *)(v30 + 64) = v115;
        *(_DWORD *)(v30 + 68) = v116;
        v117 = v174[5];
        v118 = v174[6];
        v119 = v174[7];
        *(_DWORD *)(v30 + 72) = v174[4];
        *(_DWORD *)(v30 + 76) = v117;
        *(_DWORD *)(v30 + 80) = v118;
        *(_DWORD *)(v30 + 84) = v119;
        v120 = *(_DWORD *)(v30 + 104);
        if ( v120 )
        {
          v121 = *(_DWORD *)(v30 + 104) & 7;
          v122 = 1;
          if ( v121 == 5 )
          {
            v122 = 5;
            v121 = 0;
          }
          PspChargeJobWakeCounter(
            (_DWORD *)(v120 & 0xFFFFFFF8),
            0,
            v121,
            -1,
            0xFFFFFFFF,
            0xFFFFFFFF,
            v122,
            0,
            *(_DWORD *)(v30 + 136));
          ObDereferenceObjectDeferDeleteWithTag(v120 & 0xFFFFFFF8);
          *(_DWORD *)(v30 + 104) = 0;
        }
        v123 = v150;
        *v146 = v150;
        if ( a6 )
          v57[7] = a6;
        else
          v57[7] = v123;
        v124 = v144;
        if ( v144 )
        {
          v125 = v169[0];
          v126 = v169[1];
          v127 = v169[2];
          *v144 = v168;
          v124[1] = v125;
          v124[2] = v126;
          v124[3] = v127;
          v128 = v124 + 4;
          v129 = v169[4];
          *v128 = v169[3];
          v128[1] = v129;
        }
        v130 = v148;
        if ( v148 )
        {
          v131 = v161;
          v132 = v162;
          *v148 = v160;
          v130[1] = v131;
          v130[2] = v132;
        }
        v170[0] = v57;
        v170[1] = v30;
        v170[6] = 0x10000;
        if ( *(_DWORD *)(v30 + 12) )
        {
          if ( *(_DWORD *)(v30 + 16) )
            v133 = AlpcpDispatchReplyToWaitingThread(v170);
          else
            v133 = AlpcpDispatchReplyToPort(v170);
        }
        else
        {
          v133 = AlpcpDispatchNewMessage(v170);
        }
        v18 = v133;
        v154 = v133;
        v135 = 0;
        ObfDereferenceObject((int)v57);
        if ( v18 < 0 )
          NtClose();
        return v18;
      }
      AlpcpReleaseAttributes(v174);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v30);
      if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
      {
        v108 = 0x10000 - *(__int16 *)(v30 - 14);
        *(_BYTE *)(v30 - 16) &= 0xFEu;
        *(_WORD *)(v30 - 14) = 0;
      }
      else
      {
        v108 = 0;
      }
      v109 = (unsigned int *)(v30 - 4);
      __dmb(0xBu);
      do
        v110 = __ldrex(v109);
      while ( __strex(v110 - 1, v109) );
      if ( (v110 & 2) != 0 && (v110 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v30 - 4));
      KeAbPostRelease(v30 - 4);
      if ( v108 <= 0 )
        goto LABEL_273;
      __dmb(0xBu);
      v111 = (unsigned int *)(v30 - 12);
      do
      {
        v112 = __ldrex(v111);
        v113 = v112 - v108;
      }
      while ( __strex(v113, v111) );
      __dmb(0xBu);
      if ( v113 > 0 )
        goto LABEL_273;
      if ( v113 )
        KeBugCheckEx(24, 0, v30, 40, v113);
      goto LABEL_272;
    }
LABEL_256:
    AlpcpReleaseAttributes(v174);
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v30);
    if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
    {
      v102 = 0x10000 - *(__int16 *)(v30 - 14);
      *(_BYTE *)(v30 - 16) &= 0xFEu;
      *(_WORD *)(v30 - 14) = 0;
    }
    else
    {
      v102 = 0;
    }
    v103 = (unsigned int *)(v30 - 4);
    __dmb(0xBu);
    do
      v104 = __ldrex(v103);
    while ( __strex(v104 - 1, v103) );
    if ( (v104 & 2) != 0 && (v104 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v30 - 4));
    KeAbPostRelease(v30 - 4);
    if ( v102 <= 0 )
      goto LABEL_273;
    __dmb(0xBu);
    v105 = (unsigned int *)(v30 - 12);
    do
    {
      v106 = __ldrex(v105);
      v107 = v106 - v102;
    }
    while ( __strex(v107, v105) );
    __dmb(0xBu);
    if ( v107 > 0 )
      goto LABEL_273;
    if ( v107 )
      KeBugCheckEx(24, 0, v30, 40, v107);
LABEL_272:
    AlpcpDestroyBlob(v30);
LABEL_273:
    AlpcpFlushResourcesPort(v57);
    goto LABEL_166;
  }
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v30);
  v58 = 0;
  if ( (*(_BYTE *)(v30 - 16) & 1) != 0 )
  {
    v58 = 0x10000 - *(__int16 *)(v30 - 14);
    *(_BYTE *)(v30 - 16) &= 0xFEu;
    *(_WORD *)(v30 - 14) = 0;
  }
  v59 = (unsigned int *)(v30 - 4);
  __dmb(0xBu);
  do
    v60 = __ldrex(v59);
  while ( __strex(v60 - 1, v59) );
  if ( (v60 & 2) != 0 && (v60 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v30 - 4));
  KeAbPostRelease(v30 - 4);
  if ( v58 > 0 )
  {
    __dmb(0xBu);
    v61 = (unsigned int *)(v30 - 12);
    do
    {
      v62 = __ldrex(v61);
      v63 = v62 - v58;
    }
    while ( __strex(v63, v61) );
    __dmb(0xBu);
    if ( v63 <= 0 )
    {
      if ( v63 )
        KeBugCheckEx(24, 0, v30, 40, v63);
      goto LABEL_96;
    }
  }
  return v18;
}
