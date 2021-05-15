// AlpcpSendMessage 
 
int __fastcall AlpcpSendMessage(int a1, int *a2, int a3, int a4)
{
  _DWORD *v6; // r6
  unsigned int v7; // r10
  int v8; // r4
  int v9; // r4
  int v10; // r1
  BOOL v11; // r1
  unsigned __int16 v12; // lr
  __int16 v13; // r5
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r3
  BOOL v19; // r1
  BOOL v20; // r1
  int v21; // r2
  __int16 v22; // r5
  int v23; // r6
  int v24; // r0
  int v25; // r1
  int v26; // r9
  int v27; // r0
  int v28; // r5
  unsigned __int8 *v29; // r9
  int v30; // r0
  int v31; // r4
  unsigned int v32; // r2
  unsigned int *v33; // r1
  unsigned int v34; // r2
  int v35; // r2
  int v36; // r4
  unsigned int v37; // r2
  unsigned int v38; // r2
  int v39; // r2
  int v40; // r3
  int v41; // r1
  int v42; // r1
  unsigned int *v43; // r0
  unsigned int v44; // r2
  int v45; // r3
  int v46; // r9
  unsigned int v47; // r2
  _DWORD *v48; // r3
  int v49; // r6
  unsigned int *v50; // r4
  unsigned int v51; // r1
  unsigned int *v52; // r2
  unsigned int v53; // r0
  int v54; // r0
  unsigned int v55; // r0
  int v56; // r6
  unsigned int *v57; // r5
  unsigned int v58; // r4
  unsigned int v59; // r1
  int v60; // r8
  unsigned int *v61; // r6
  unsigned int v62; // r1
  unsigned int *v63; // r2
  unsigned int v64; // r0
  int v65; // r0
  int v66; // r3
  int *v67; // r9
  int v68; // r2
  unsigned int v69; // r1
  _DWORD *v70; // r10
  int v71; // r3
  int v72; // r8
  unsigned int *v73; // r6
  unsigned int v74; // r1
  unsigned int *v75; // r2
  unsigned int v76; // r0
  int v77; // r0
  int v78; // r4
  int v79; // r2
  int v80; // r3
  int v81; // r9
  int v82; // r0
  unsigned int *v83; // r2
  unsigned int v84; // r1
  int v85; // r1
  int v86; // r4
  int v87; // r6
  unsigned __int8 *v88; // r0
  unsigned int v89; // r2
  int v90; // r2
  unsigned int *v91; // r1
  unsigned int v92; // r0
  int v93; // r0
  int v94; // r6
  char v95; // r2
  unsigned int *v96; // r0
  unsigned int v97; // r1
  _DWORD *v98; // r3
  unsigned int *v99; // r2
  unsigned int v100; // r0
  int v101; // r0
  unsigned int *v102; // r2
  unsigned int v103; // r1
  int v104; // r1
  int v105; // r0
  unsigned int *v106; // r2
  unsigned int v107; // r1
  int v108; // r1
  int v109; // r3
  unsigned int v110; // r1
  unsigned int v111; // r2
  unsigned int v112; // r3
  _DWORD *v113; // r6
  int v114; // r1
  int v115; // r2
  int v116; // r3
  unsigned int v117; // r1
  int *v118; // r0
  int v119; // r8
  unsigned int *v120; // r6
  unsigned int v121; // r1
  unsigned int *v122; // r2
  unsigned int v123; // r0
  int v124; // r0
  int v126; // [sp+18h] [bp-90h] BYREF
  int v127; // [sp+1Ch] [bp-8Ch]
  _DWORD *v128; // [sp+20h] [bp-88h]
  int v129; // [sp+24h] [bp-84h]
  int v130; // [sp+28h] [bp-80h]
  int v131; // [sp+30h] [bp-78h] BYREF
  int v132; // [sp+34h] [bp-74h]
  int v133; // [sp+38h] [bp-70h]
  int v134; // [sp+3Ch] [bp-6Ch]
  int v135; // [sp+40h] [bp-68h]
  int v136; // [sp+44h] [bp-64h]
  int v137; // [sp+48h] [bp-60h]
  _DWORD *v138; // [sp+4Ch] [bp-5Ch]
  int *v139; // [sp+50h] [bp-58h]
  int v140; // [sp+54h] [bp-54h]
  int v141; // [sp+58h] [bp-50h]
  int v142; // [sp+5Ch] [bp-4Ch]
  int v143; // [sp+60h] [bp-48h]
  int v144; // [sp+64h] [bp-44h]
  int v145; // [sp+68h] [bp-40h] BYREF
  _BYTE v146[28]; // [sp+6Ch] [bp-3Ch] BYREF
  int varg_r0; // [sp+B0h] [bp+8h]
  int *varg_r1; // [sp+B4h] [bp+Ch]
  int varg_r2; // [sp+B8h] [bp+10h]
  int varg_r3; // [sp+BCh] [bp+14h]

  varg_r3 = a4;
  v130 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v141 = a3;
  varg_r2 = a3;
  v139 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v145 = 0;
  memset(v146, 0, sizeof(v146));
  v138 = *(_DWORD **)a1;
  v6 = v138;
  v140 = (int)v138;
  v7 = *(_DWORD *)(a1 + 24);
  v128 = (_DWORD *)v7;
  v8 = v138[61];
  if ( (v8 & 0x10) != 0 )
    return -1073741759;
  if ( (v8 & 8) != 0 )
    return -1073740025;
  if ( (v8 & 0x20) != 0 && (v138[38] & 0x1000) == 0 )
    return -1073741769;
  if ( !v130 )
  {
    v15 = v139[1];
    v16 = v139[2];
    v17 = v139[3];
    v131 = *v139;
    v132 = v15;
    v133 = v16;
    v134 = v17;
    v18 = v139[5];
    v135 = v139[4];
    v136 = v18;
    v19 = (v138[38] & 0x1000) != 0 || (v7 & 2) != 0;
    v137 = (__int16)v131;
    if ( (unsigned __int16)v131 < (unsigned int)(unsigned __int16)(v131 + 24) )
    {
      if ( v19 )
      {
        if ( (unsigned int)(unsigned __int16)v131 + 24 <= HIWORD(v131) )
        {
          v12 = v131 + 24;
          v129 = SHIWORD(v132);
LABEL_36:
          v13 = v132;
          goto LABEL_37;
        }
      }
      else
      {
        v12 = HIWORD(v131);
        if ( (unsigned __int16)v131 + 24 == HIWORD(v131) )
        {
          v129 = SHIWORD(v132);
          goto LABEL_36;
        }
      }
    }
    return -1073741811;
  }
  v10 = (int)a2;
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    v10 = MmUserProbeAddress;
  memmove((int)&v131, v10, 0x18u);
  v11 = (v6[38] & 0x1000) != 0 || (v7 & 2) != 0;
  v137 = (__int16)v131;
  v12 = HIWORD(v131);
  if ( (unsigned __int16)v131 >= (unsigned int)(unsigned __int16)(v131 + 24) )
    goto LABEL_20;
  if ( v11 )
  {
    if ( (unsigned int)(unsigned __int16)v131 + 24 <= HIWORD(v131) )
    {
      v12 = v131 + 24;
      v126 = (__int16)(v131 + 24);
      HIWORD(v131) = v131 + 24;
      goto LABEL_21;
    }
LABEL_20:
    v9 = -1073741811;
    v127 = -1073741811;
    v129 = SHIWORD(v132);
    return v9;
  }
  v126 = SHIWORD(v131);
  if ( (unsigned __int16)v131 + 24 != HIWORD(v131) )
    goto LABEL_20;
LABEL_21:
  v13 = v132 & 0x7FFF;
  LOWORD(v132) = v132 & 0x7FFF;
  v129 = SHIWORD(v132);
  if ( HIWORD(v132) )
  {
    v14 = AlpcpValidateDataInformation(v139, &v131);
    v9 = v14;
    if ( v14 < 0 )
    {
      v127 = v14;
      return v9;
    }
    v12 = v126;
  }
LABEL_37:
  v9 = -1073741811;
  v20 = (v6[38] & 0x1000) != 0 || (v7 & 2) != 0;
  v21 = (unsigned __int8)v13;
  v22 = v13 & 0xFF00;
  v23 = v135;
  v24 = v135;
  __mrc(15, 0, 13, 0, 3);
  if ( !v20 )
  {
    if ( v21 != 7 || v130 )
    {
      if ( v23 && v23 >= 0 )
      {
        if ( (v7 & 0x10000) != 0 )
        {
          LOWORD(v21) = 2;
          goto LABEL_68;
        }
      }
      else if ( (v7 & 0x10000) != 0 )
      {
        LOWORD(v21) = 3;
        goto LABEL_68;
      }
      LOWORD(v21) = 1;
    }
LABEL_68:
    if ( !v23 && (v133 || v134) )
      return -1073740030;
    goto LABEL_72;
  }
  if ( (v7 & 1) != 0 )
  {
    if ( !v23 )
      return v9;
    v22 = 0;
    LOWORD(v21) = 2;
  }
  else
  {
    if ( (v7 & 0x10000) != 0 )
    {
      if ( v21 != 6 )
      {
        switch ( v21 )
        {
          case 0:
            LOWORD(v21) = 3;
            goto LABEL_53;
          case 3:
          case 4:
          case 5:
          case 13:
            goto LABEL_52;
          default:
            return v9;
        }
        return v9;
      }
    }
    else
    {
      if ( !v21 )
      {
        v24 = 0;
        LOWORD(v21) = 1;
        goto LABEL_57;
      }
      if ( v21 == 1 )
      {
        if ( !v23 )
          return v9;
        goto LABEL_57;
      }
      if ( (unsigned int)(v21 - 7) > 2 )
        return v9;
    }
LABEL_52:
    if ( (v7 & 2) == 0 )
      return v9;
LABEL_53:
    v24 = 0;
  }
LABEL_57:
  v23 = v24;
  v135 = v24;
  if ( !v130 )
  {
    v25 = 0;
    goto LABEL_73;
  }
LABEL_72:
  v25 = v136;
LABEL_73:
  v140 = (__int16)(v22 & 0xEFFF | v21);
  LOWORD(v132) = v22 & 0xEFFF | v21;
  v144 = v12;
  v26 = (int)v138;
  if ( (unsigned int)v12 > v138[42] )
    return -1073741777;
  if ( (v7 & 0x20000) != 0 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 8) != 0 )
    return -1073741823;
  if ( v23 )
  {
    v7 |= 0x10u;
    v9 = AlpcpLookupMessage(v26, v23, v25, &v126);
    if ( v9 < 0 )
      goto LABEL_178;
    v28 = v126;
    v39 = *(_DWORD *)(v126 + 20);
    if ( (v39 & 0x80) != 0 )
      goto LABEL_179;
    v40 = *(_DWORD *)(v126 + 12);
    v143 = v40;
    if ( !v40 )
      goto LABEL_146;
    v41 = *(_DWORD *)(v126 + 8);
    if ( v41 == v26 )
      goto LABEL_128;
    if ( !v41 )
    {
      v128 = *(_DWORD **)(v40 + 8);
      v127 = (int)(v128 - 1);
      v42 = KeAbPreAcquire((unsigned int)(v128 - 1), 0, 0);
      v142 = v42;
      v43 = (unsigned int *)v127;
      do
        v44 = __ldrex(v43);
      while ( !v44 && __strex(0x11u, v43) );
      __dmb(0xBu);
      if ( v44 )
      {
        ExfAcquirePushLockSharedEx(v43, v42, (unsigned int)v43);
        v42 = v142;
        v43 = (unsigned int *)v127;
      }
      if ( v42 )
        *(_BYTE *)(v42 + 14) |= 1u;
      v45 = (*(_DWORD *)(v143 + 244) >> 1) & 3;
      if ( v45 == 1 || v45 != 2 )
      {
        if ( v128[2] == v26 )
        {
          v46 = 1;
          goto LABEL_118;
        }
      }
      else if ( *v128 == v26 || v128[1] == v26 )
      {
        v46 = 1;
LABEL_118:
        __dmb(0xBu);
        do
          v47 = __ldrex(v43);
        while ( v47 == 17 && __strex(0, v43) );
        if ( v47 != 17 )
        {
          ExfReleasePushLockShared(v43);
          v43 = (unsigned int *)v127;
        }
        KeAbPostRelease((unsigned int)v43);
        if ( !v46 )
          goto LABEL_129;
LABEL_146:
        if ( *(_DWORD *)(v28 + 16) && !*(_DWORD *)(v28 + 28) && (v7 & 0x30000) == 0 )
        {
          v55 = 400;
          if ( *(_DWORD *)(v28 + 108) )
            v55 = *(_DWORD *)(v28 + 112) + 400;
          v56 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v57 = (unsigned int *)(v56 + 668);
          __pld((void *)(v56 + 668));
          v58 = *(_DWORD *)(v56 + 668);
          __dmb(0xBu);
          if ( v58 < v55 )
          {
LABEL_159:
            v9 = PsChargeProcessPagedPoolQuota(v56, v55);
          }
          else
          {
            while ( 1 )
            {
              __dmb(0xBu);
              do
                v59 = __ldrex(v57);
              while ( v59 == v58 && __strex(v58 - v55, v57) );
              __dmb(0xBu);
              if ( v59 == v58 )
                break;
              v58 = *v57;
              __dmb(0xBu);
              if ( v58 < v55 )
                goto LABEL_159;
            }
            v9 = 0;
          }
          if ( v9 < 0 )
          {
            v28 = v126;
            if ( AlpcpMessageLogEnabled )
              AlpcpEnterStateChangeEventMessageLog(v126);
            v60 = 0;
            if ( (*(_BYTE *)(v28 - 16) & 1) != 0 )
            {
              v60 = 0x10000 - *(__int16 *)(v28 - 14);
              *(_BYTE *)(v28 - 16) &= 0xFEu;
              *(_WORD *)(v28 - 14) = 0;
            }
            v61 = (unsigned int *)(v28 - 4);
            __dmb(0xBu);
            do
              v62 = __ldrex(v61);
            while ( __strex(v62 - 1, v61) );
            if ( (v62 & 2) != 0 && (v62 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)(v28 - 4));
            KeAbPostRelease(v28 - 4);
            if ( v60 > 0 )
            {
              __dmb(0xBu);
              v63 = (unsigned int *)(v28 - 12);
              do
              {
                v64 = __ldrex(v63);
                v65 = v64 - v60;
              }
              while ( __strex(v65, v63) );
              __dmb(0xBu);
              if ( v65 <= 0 )
              {
                if ( v65 )
                  KeBugCheckEx(24, 0, v28, 40, v65);
                goto LABEL_176;
              }
            }
            return v9;
          }
          v66 = __mrc(15, 0, 13, 0, 3);
          v28 = v126;
          *(_DWORD *)(v126 + 28) = *(_DWORD *)((v66 & 0xFFFFFFC0) + 0x74);
          ObfReferenceObjectWithTag(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
          v23 = v135;
          v129 = SHIWORD(v132);
          v140 = (__int16)v132;
          v137 = (__int16)v131;
        }
        goto LABEL_179;
      }
      v46 = 0;
      goto LABEL_118;
    }
    if ( (*(_DWORD *)(v26 + 244) & 6) == 6 )
    {
      v48 = *(_DWORD **)(v26 + 8);
      if ( v48 )
      {
        if ( *v48 == v41 )
        {
LABEL_128:
          if ( (v39 & 7) == 3 )
            goto LABEL_146;
        }
      }
    }
LABEL_129:
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v28);
    v49 = 0;
    if ( (*(_BYTE *)(v28 - 16) & 1) != 0 )
    {
      v49 = 0x10000 - *(__int16 *)(v28 - 14);
      *(_BYTE *)(v28 - 16) &= 0xFEu;
      *(_WORD *)(v28 - 14) = 0;
    }
    v50 = (unsigned int *)(v28 - 4);
    __dmb(0xBu);
    do
      v51 = __ldrex(v50);
    while ( __strex(v51 - 1, v50) );
    if ( (v51 & 2) != 0 && (v51 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v28 - 4));
    KeAbPostRelease(v28 - 4);
    if ( v49 > 0 )
    {
      __dmb(0xBu);
      v52 = (unsigned int *)(v28 - 12);
      do
      {
        v53 = __ldrex(v52);
        v54 = v53 - v49;
      }
      while ( __strex(v54, v52) );
      __dmb(0xBu);
      if ( v54 <= 0 )
      {
        if ( v54 )
          KeBugCheckEx(24, 0, v28, 40, v54);
        AlpcpDestroyBlob(v28);
      }
    }
    return -1073741790;
  }
  v27 = AlpcpAllocateBlob(AlpcMessageType, 400, 0);
  v28 = v27;
  if ( !v27 )
  {
    v9 = -1073741670;
LABEL_178:
    v28 = v126;
    goto LABEL_179;
  }
  v29 = (unsigned __int8 *)(v27 - 4);
  v30 = KeAbPreAcquire(v27 - 4, 0, 0);
  v31 = v30;
  do
    v32 = __ldrex(v29);
  while ( __strex(v32 | 1, v29) );
  __dmb(0xBu);
  if ( (v32 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v28 - 4), v30, v28 - 4);
  if ( v31 )
    *(_BYTE *)(v31 + 14) |= 1u;
  *(_BYTE *)(v28 - 16) |= 1u;
  __dmb(0xBu);
  v33 = (unsigned int *)(v28 - 12);
  do
  {
    v34 = __ldrex(v33);
    v35 = v34 + 0x10000;
  }
  while ( __strex(v35, v33) );
  __dmb(0xBu);
  if ( v35 <= 0 )
    KeBugCheckEx(24, 0, v28, 38, v35);
  v36 = *(_DWORD *)(v28 + 136);
  memset((_BYTE *)v28, 0, 144);
  *(_WORD *)(v28 + 122) = 24;
  --*(_WORD *)(v28 - 14);
  *(_DWORD *)(v28 + 136) = v36 & 0x7FFFFFFF;
  do
  {
    __dmb(0xBu);
    do
    {
      v37 = __ldrex(AlpcpNextCallbackId);
      v38 = v37 + 1;
    }
    while ( __strex(v38, AlpcpNextCallbackId) );
    __dmb(0xBu);
  }
  while ( !v38 );
  *(_DWORD *)(v28 + 140) = v38;
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterAllocationEventMessageLog(v28);
  *(_WORD *)(v28 + 122) = 24;
  v9 = 0;
LABEL_179:
  if ( v9 < 0 )
    return v9;
  v67 = 0;
  v127 = 0;
  v68 = v141;
  if ( v141 )
  {
    v67 = &v145;
    v127 = (int)&v145;
    v69 = v7;
    v70 = v138;
    v9 = AlpcpCaptureAttributes(v138, v69, v141, v28, &v145);
    v68 = v141;
  }
  else
  {
    v70 = v138;
  }
  if ( v23 )
  {
    v71 = *(_DWORD *)(v28 + 20);
    if ( (v71 & 0x280) != 0 )
    {
      if ( (v71 & 0x80) != 0 )
        v9 = -1073740029;
      else
        v9 = 0;
      if ( v68 )
        AlpcpReleaseAttributes(v67);
      AlpcpReleaseAttributes((_DWORD *)(v28 + 56));
      AlpcpCancelMessage(v70, v28, 0x10000);
      return v9;
    }
  }
  if ( v9 >= 0 )
  {
    if ( v23 )
    {
      v78 = *(_DWORD *)(v28 + 104);
      if ( v78 )
      {
        v79 = *(_DWORD *)(v28 + 104) & 7;
        v80 = 1;
        if ( v79 == 5 )
        {
          v80 = 5;
          v79 = 0;
        }
        PspChargeJobWakeCounter(
          (_DWORD *)(v78 & 0xFFFFFFF8),
          0,
          v79,
          v80,
          0xFFFFFFFF,
          0xFFFFFFFF,
          v80,
          0,
          *(_DWORD *)(v28 + 136));
        ObDereferenceObjectDeferDeleteWithTag(v78 & 0xFFFFFFF8);
        *(_DWORD *)(v28 + 104) = 0;
      }
    }
    v81 = 0;
    if ( v23 && v23 >= 0 )
    {
      v81 = *(_DWORD *)(v28 + 84);
      *(_DWORD *)(v28 + 84) = 0;
      v82 = *(_DWORD *)(v28 + 72);
      if ( v82 )
      {
        __dmb(0xBu);
        v83 = (unsigned int *)(v82 - 12);
        do
        {
          v84 = __ldrex(v83);
          v85 = v84 - 1;
        }
        while ( __strex(v85, v83) );
        __dmb(0xBu);
        if ( v85 <= 0 )
        {
          if ( v85 )
            KeBugCheckEx(24, 0, v82, 33, v85);
          AlpcpDestroyBlob(v82);
        }
        *(_DWORD *)(v28 + 72) = 0;
      }
      v86 = *(_DWORD *)(v28 + 76);
      if ( v86 )
      {
        v142 = *(_DWORD *)(v86 + 8);
        v143 = v142 - 4;
        v87 = KeAbPreAcquire(v142 - 4, 0, 0);
        v88 = (unsigned __int8 *)v143;
        do
          v89 = __ldrex(v88);
        while ( __strex(v89 | 1, v88) );
        __dmb(0xBu);
        if ( (v89 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v88, v87, (unsigned int)v88);
        if ( v87 )
          *(_BYTE *)(v87 + 14) |= 1u;
        v90 = v142;
        *(_BYTE *)(v142 - 16) |= 1u;
        __dmb(0xBu);
        v91 = (unsigned int *)(v90 - 12);
        do
        {
          v92 = __ldrex(v91);
          v93 = v92 + 0x10000;
        }
        while ( __strex(v93, v91) );
        __dmb(0xBu);
        if ( v93 <= 0 )
          KeBugCheckEx(24, 0, v90, 38, v93);
        --*(_DWORD *)(v86 + 40);
        v94 = *(_DWORD *)(v86 + 8);
        v128 = 0;
        v95 = *(_BYTE *)(v94 - 16);
        if ( (v95 & 1) != 0 )
        {
          v128 = (_DWORD *)(0x10000 - *(__int16 *)(v94 - 14));
          *(_BYTE *)(v94 - 16) = v95 & 0xFE;
          *(_WORD *)(v94 - 14) = 0;
        }
        v96 = (unsigned int *)(v94 - 4);
        __dmb(0xBu);
        do
          v97 = __ldrex(v96);
        while ( __strex(v97 - 1, v96) );
        if ( (v97 & 2) != 0 && (v97 & 4) == 0 )
        {
          ExfTryToWakePushLock(v96);
          v96 = (unsigned int *)(v94 - 4);
        }
        KeAbPostRelease((unsigned int)v96);
        v98 = v128;
        if ( (int)v128 > 0 )
        {
          __dmb(0xBu);
          v99 = (unsigned int *)(v94 - 12);
          do
          {
            v100 = __ldrex(v99);
            v101 = v100 - (_DWORD)v98;
          }
          while ( __strex(v101, v99) );
          __dmb(0xBu);
          if ( v101 <= 0 )
          {
            if ( v101 )
              KeBugCheckEx(24, 0, v94, 40, v101);
            AlpcpDestroyBlob(v94);
          }
        }
        __dmb(0xBu);
        v102 = (unsigned int *)(v86 - 12);
        do
        {
          v103 = __ldrex(v102);
          v104 = v103 - 1;
        }
        while ( __strex(v104, v102) );
        __dmb(0xBu);
        if ( v104 <= 0 )
        {
          if ( v104 )
            KeBugCheckEx(24, 0, v86, 33, v104);
          AlpcpDestroyBlob(v86);
        }
        *(_DWORD *)(v28 + 76) = 0;
      }
      v105 = *(_DWORD *)(v28 + 80);
      if ( v105 )
      {
        __dmb(0xBu);
        v106 = (unsigned int *)(v105 - 12);
        do
        {
          v107 = __ldrex(v106);
          v108 = v107 - 1;
        }
        while ( __strex(v108, v106) );
        __dmb(0xBu);
        if ( v108 <= 0 )
        {
          if ( v108 )
            KeBugCheckEx(24, 0, v105, 33, v108);
          AlpcpDestroyBlob(v105);
        }
        *(_DWORD *)(v28 + 80) = 0;
      }
      v109 = *(_DWORD *)(v28 + 84);
      if ( v109 )
      {
        if ( (v109 & 1) != 0 )
          ObfDereferenceObject(v109 & 0xFFFFFFFE);
        *(_DWORD *)(v28 + 84) = 0;
      }
    }
    if ( v127 )
    {
      v110 = *(_DWORD *)(v127 + 4);
      v111 = *(_DWORD *)(v127 + 8);
      v112 = *(_DWORD *)(v127 + 12);
      v113 = (_DWORD *)(v127 + 16);
      *(_DWORD *)(v28 + 56) = *(_DWORD *)v127;
      *(_DWORD *)(v28 + 60) = v110;
      *(_DWORD *)(v28 + 64) = v111;
      *(_DWORD *)(v28 + 68) = v112;
      v114 = v113[1];
      v115 = v113[2];
      v116 = v113[3];
      *(_DWORD *)(v28 + 72) = *v113;
      *(_DWORD *)(v28 + 76) = v114;
      *(_DWORD *)(v28 + 80) = v115;
      *(_DWORD *)(v28 + 84) = v116;
    }
    if ( v81 )
      *(_DWORD *)(v28 + 84) = v81;
    v117 = (unsigned __int16)v137;
    v9 = 0;
    v118 = v139 + 6;
    if ( v130 && (unsigned int)v118 + (unsigned __int16)v137 > MmUserProbeAddress )
    {
      v9 = -1073741819;
    }
    else
    {
      *(_DWORD *)(v28 + 88) = v118;
      if ( v117 > 0x100 )
        v9 = AlpcpCaptureMessageData((_DWORD *)v28, v117, 0);
      if ( v9 >= 0 )
      {
        *(_DWORD *)(a1 + 4) = v28;
        *(_WORD *)(a1 + 28) = v144;
        *(_WORD *)(a1 + 30) = v140;
        *(_WORD *)(a1 + 32) = v129;
        if ( !*(_DWORD *)(v28 + 12) )
          return AlpcpDispatchNewMessage(a1);
        if ( *(_DWORD *)(v28 + 16) )
          return AlpcpDispatchReplyToWaitingThread((__int64 *)a1);
        return AlpcpDispatchReplyToPort((__int64 *)a1);
      }
    }
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v28);
    v119 = 0;
    if ( (*(_BYTE *)(v28 - 16) & 1) != 0 )
    {
      v119 = 0x10000 - *(__int16 *)(v28 - 14);
      *(_BYTE *)(v28 - 16) &= 0xFEu;
      *(_WORD *)(v28 - 14) = 0;
    }
    v120 = (unsigned int *)(v28 - 4);
    __dmb(0xBu);
    do
      v121 = __ldrex(v120);
    while ( __strex(v121 - 1, v120) );
    if ( (v121 & 2) != 0 && (v121 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v28 - 4));
    KeAbPostRelease(v28 - 4);
    if ( v119 > 0 )
    {
      __dmb(0xBu);
      v122 = (unsigned int *)(v28 - 12);
      do
      {
        v123 = __ldrex(v122);
        v124 = v123 - v119;
      }
      while ( __strex(v124, v122) );
      __dmb(0xBu);
      if ( v124 <= 0 )
      {
        if ( v124 )
          KeBugCheckEx(24, 0, v28, 40, v124);
        goto LABEL_176;
      }
    }
  }
  else
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v28);
    v72 = 0;
    if ( (*(_BYTE *)(v28 - 16) & 1) != 0 )
    {
      v72 = 0x10000 - *(__int16 *)(v28 - 14);
      *(_BYTE *)(v28 - 16) &= 0xFEu;
      *(_WORD *)(v28 - 14) = 0;
    }
    v73 = (unsigned int *)(v28 - 4);
    __dmb(0xBu);
    do
      v74 = __ldrex(v73);
    while ( __strex(v74 - 1, v73) );
    if ( (v74 & 2) != 0 && (v74 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v28 - 4));
    KeAbPostRelease(v28 - 4);
    if ( v72 > 0 )
    {
      __dmb(0xBu);
      v75 = (unsigned int *)(v28 - 12);
      do
      {
        v76 = __ldrex(v75);
        v77 = v76 - v72;
      }
      while ( __strex(v77, v75) );
      __dmb(0xBu);
      if ( v77 <= 0 )
      {
        if ( v77 )
          KeBugCheckEx(24, 0, v28, 40, v77);
LABEL_176:
        AlpcpDestroyBlob(v28);
        return v9;
      }
    }
  }
  return v9;
}
