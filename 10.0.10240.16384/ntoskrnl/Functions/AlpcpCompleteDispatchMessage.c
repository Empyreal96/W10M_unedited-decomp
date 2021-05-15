// AlpcpCompleteDispatchMessage 
 
int __fastcall AlpcpCompleteDispatchMessage(int a1)
{
  __int64 v1; // kr00_8
  int v2; // r3
  int v3; // r9
  BOOL v5; // r6
  BOOL v6; // r0
  int v7; // r3
  int result; // r0
  int v9; // r1
  int v10; // r4
  int v11; // r6
  int v12; // r10
  int v13; // r5
  int v14; // r3
  int v15; // r0
  int v16; // r4
  unsigned __int8 *v17; // lr
  unsigned int v18; // r2
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r0
  int v22; // r2
  char v23; // r2
  int v24; // r4
  int v25; // r3
  unsigned int *v26; // r0
  unsigned int v27; // r1
  unsigned int *v28; // r2
  unsigned int v29; // r0
  int v30; // r0
  unsigned int *v31; // r4
  unsigned int v32; // r2
  int v33; // r3
  char v34; // r2
  int v35; // r6
  int v36; // r3
  _DWORD *v37; // r4
  unsigned __int8 *v38; // r5
  int v39; // r0
  int v40; // r4
  unsigned int v41; // r2
  int v42; // r2
  int v43; // r3
  unsigned int v44; // r0
  int v45; // r1
  int v46; // r3
  char v47; // r2
  int v48; // r4
  int v49; // r3
  unsigned int *v50; // r5
  unsigned int v51; // r1
  unsigned int *v52; // r2
  unsigned int v53; // r0
  int v54; // r0
  unsigned int *v55; // r4
  unsigned int v56; // r2
  int v57; // r2
  unsigned int v58; // r1
  int v59; // r0
  int v60; // r4
  unsigned __int8 *v61; // lr
  unsigned int v62; // r2
  int v63; // r2
  int v64; // r3
  unsigned int v65; // r0
  char v66; // r2
  int v67; // r4
  int v68; // r3
  unsigned int *v69; // r0
  unsigned int v70; // r1
  unsigned int *v71; // r2
  unsigned int v72; // r0
  int v73; // r0
  unsigned int *v74; // r4
  unsigned int v75; // r2
  unsigned int *v76; // r4
  unsigned int v77; // r2
  int v78; // r3
  int v79; // r1
  unsigned __int8 *v80; // r0
  unsigned int v81; // r2
  unsigned int v82; // r1
  __int64 v83; // r0
  unsigned int *v84; // r4
  unsigned int v85; // r1
  unsigned int *v86; // r4
  unsigned int v87; // r2
  unsigned int v88; // r2
  int v89; // r0
  int v90; // r5
  int v91; // r0
  _DWORD *v92; // r0
  int v93; // r2
  int v94; // r3
  int v95; // r4
  int v96; // r3
  _DWORD *v97; // r4
  unsigned int v98; // r2
  int v99; // r1
  int v100; // r0
  int v101; // r1
  int *v102; // r3
  int v103; // r2
  int v104; // r3
  int v105; // r2
  int v106; // r3
  __int64 v107; // kr08_8
  __int16 v108; // r3
  unsigned __int8 *v109; // r5
  int v110; // r0
  int v111; // r4
  unsigned int v112; // r2
  __int64 v113; // r2
  unsigned int v114; // r1
  unsigned __int8 *v115; // r5
  int v116; // r0
  int v117; // r4
  unsigned int v118; // r2
  __int64 v119; // r2
  unsigned int v120; // r1
  unsigned int *v121; // r4
  unsigned int v122; // r2
  int v123; // r4
  unsigned int *v124; // r5
  unsigned int v125; // r2
  BOOL v126; // [sp+18h] [bp-50h]
  int v127; // [sp+18h] [bp-50h]
  BOOL v128; // [sp+1Ch] [bp-4Ch]
  int v129; // [sp+20h] [bp-48h]
  int v130; // [sp+24h] [bp-44h]
  int v131; // [sp+28h] [bp-40h]
  int v132; // [sp+2Ch] [bp-3Ch]
  int v133; // [sp+30h] [bp-38h]
  int v134; // [sp+34h] [bp-34h]
  int v135; // [sp+34h] [bp-34h]
  int v136; // [sp+34h] [bp-34h]
  _DWORD *v137; // [sp+38h] [bp-30h]
  _DWORD *v138; // [sp+3Ch] [bp-2Ch]
  unsigned int v139; // [sp+40h] [bp-28h]

  v1 = *(_QWORD *)(a1 + 4);
  v131 = *(_DWORD *)(a1 + 8);
  v132 = 0;
  v2 = *(_DWORD *)(a1 + 24);
  v3 = *(_DWORD *)(a1 + 16);
  v128 = (v2 & 4) != 0;
  v5 = (v2 & 0x20000) != 0;
  v126 = v5;
  v6 = (v2 & 0x800000) != 0;
  v7 = *(_DWORD *)(*(_DWORD *)a1 + 152);
  if ( (v7 & 0x400000) != 0 )
  {
    v9 = 2;
  }
  else
  {
    if ( (v7 & 0x200000) != 0 )
      return sub_7F8E48(v6);
    v9 = 0;
  }
  if ( (v5 || v6 || v9 || (AlpcpWakePolicyDefault & 1) == 0) && (*(_DWORD *)(v1 + 20) & 0x200) == 0 )
  {
    v10 = *(_DWORD *)(v3 + 12);
    if ( (v10 & 1) == 0 )
    {
      if ( v10 )
      {
        v11 = 1;
        if ( !v9 && (AlpcpWakePolicyDefault & 1) != 0 )
        {
          v11 = 3;
          if ( (AlpcpWakePolicyDefault & 2) != 0 )
            v11 = -2147483645;
        }
        v12 = *(_DWORD *)(v1 + 136);
        v13 = *(_DWORD *)(v10 + 288);
        __dmb(0xBu);
        if ( !v13 || (v33 = *(_DWORD *)(v13 + 744), (v33 & 0x1000) == 0) || (v11 & 2) != 0 && (v33 & 0x800000) != 0 )
        {
          v14 = 0;
        }
        else
        {
          v134 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          if ( PspCheckConditionalWakeCharge(v134, v13, 2) )
          {
            v34 = 1;
            if ( (*(_DWORD *)(v134 + 188) & 0x40) != 0 || (v11 & 2) == 0 )
            {
              v35 = 2;
            }
            else
            {
              v34 = 5;
              if ( (v11 & 0x80000000) != 0 )
                v34 = 7;
              v35 = 5;
            }
            PspChargeJobWakeCounter((_DWORD *)v13, 0, 2, 1, 1u, 0, v34, v10, v12);
            ObfReferenceObjectWithTag(v13);
            v14 = v35 | v13;
          }
          else
          {
            v14 = 0;
          }
        }
        v5 = v126;
        *(_DWORD *)(v1 + 104) = v14;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 24) & 8) != 0 )
  {
    if ( *(_DWORD *)(v1 + 88) )
    {
      AlpcpCaptureMessageDataSafe(v1, v9);
      *(_DWORD *)(v1 + 88) = 0;
    }
    ++*(_WORD *)(v1 - 14);
    v15 = KeAbPreAcquire(v3 + 124, 0, 0);
    v16 = v15;
    v17 = (unsigned __int8 *)(v3 + 124);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 1, v17) );
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
    {
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 124), v15, v3 + 124);
      v17 = (unsigned __int8 *)(v3 + 124);
    }
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    v19 = *(_DWORD *)(v1 + 20);
    *(_DWORD *)(v1 + 8) = v3;
    *(_DWORD *)(v1 + 20) = (v19 & 0xFFFFFF87 | (4 * (*(_DWORD *)(v3 + 244) & 6))) & 0xFFFFFFF8 | 4;
    v20 = *(_DWORD *)(v3 + 132);
    *(_DWORD *)v1 = v3 + 128;
    *(_DWORD *)(v1 + 4) = v20;
    **(_DWORD **)(v3 + 132) = v1;
    *(_DWORD *)(v3 + 132) = v1;
    ++*(_DWORD *)(v3 + 272);
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v17);
    while ( __strex(v21 - 1, (unsigned int *)v17) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
    {
      ExfTryToWakePushLock((unsigned int *)v17);
      v17 = (unsigned __int8 *)(v3 + 124);
    }
    KeAbPostRelease((unsigned int)v17);
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(v1 + 84);
    v22 = *(_DWORD *)(v1 + 20);
    *(_DWORD *)(v1 + 84) = 0;
    *(_DWORD *)(v1 + 20) = v22 & 0xFFFEFFFF;
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v1);
    v23 = *(_BYTE *)(v1 - 16);
    v24 = 0;
    if ( (v23 & 1) != 0 )
    {
      v25 = *(__int16 *)(v1 - 14);
      *(_WORD *)(v1 - 14) = 0;
      v24 = 0x10000 - v25;
      *(_BYTE *)(v1 - 16) = BYTE4(v1) & 0xFE;
    }
    v26 = (unsigned int *)(v1 - 4);
    __dmb(0xBu);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 - 1, v26) );
    if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
    {
      ExfTryToWakePushLock(v26);
      v26 = (unsigned int *)(v1 - 4);
    }
    KeAbPostRelease((unsigned int)v26);
    if ( v24 > 0 )
    {
      __dmb(0xBu);
      v28 = (unsigned int *)(v1 - 12);
      do
      {
        v29 = __ldrex(v28);
        v30 = v29 - v24;
      }
      while ( __strex(v30, v28) );
      __dmb(0xBu);
      if ( v30 <= 0 )
      {
        if ( v30 )
          KeBugCheckEx(24, 0, v1, 40, v30);
        AlpcpDestroyBlob(v1);
      }
    }
    v31 = (unsigned int *)(v131 - 4);
    __dmb(0xBu);
    do
      v32 = __ldrex(v31);
    while ( v32 == 17 && __strex(0, v31) );
    if ( v32 != 17 )
      ExfReleasePushLockShared(v31);
    KeAbPostRelease((unsigned int)v31);
    v76 = (unsigned int *)(v3 + 208);
    __dmb(0xBu);
    do
      v77 = __ldrex(v76);
    while ( v77 == 17 && __strex(0, v76) );
    if ( v77 != 17 )
      ExfReleasePushLockShared((_DWORD *)(v3 + 208));
    KeAbPostRelease(v3 + 208);
    result = ObfDereferenceObject(v3);
    *(_DWORD *)(a1 + 16) = 0;
    if ( !v5 && !v128 )
    {
      result = KeSetEvent(*(_DWORD *)(a1 + 20) & 0xFFFFFFFE, 0, 0);
      v78 = *(_DWORD *)(a1 + 20);
      if ( (v78 & 1) != 0 )
        result = ObfDereferenceObject(v78 & 0xFFFFFFFE);
      *(_DWORD *)(a1 + 20) = 0;
    }
    return result;
  }
  if ( *(_DWORD *)(v3 + 140) != v3 + 140 )
  {
    v79 = KeAbPreAcquire(v3 + 136, 0, 0);
    v136 = v79;
    v80 = (unsigned __int8 *)(v3 + 136);
    do
      v81 = __ldrex(v80);
    while ( __strex(v81 | 1, v80) );
    __dmb(0xBu);
    if ( (v81 & 1) != 0 )
    {
      ExfAcquirePushLockExclusiveEx(v80, v79, v3 + 136);
      v79 = v136;
      v80 = (unsigned __int8 *)(v3 + 136);
    }
    if ( v79 )
      *(_BYTE *)(v79 + 14) |= 1u;
    if ( *(_DWORD *)(v3 + 140) != v3 + 140 )
    {
      v57 = *(_DWORD *)(v3 + 140) - 988;
      v127 = v57;
      if ( *(_DWORD *)(v1 + 88) )
      {
        AlpcpCaptureMessageDataSafe(v1, v79);
        v57 = v127;
        *(_DWORD *)(v1 + 88) = 0;
      }
      if ( (*(_DWORD *)(v1 + 20) & 0x200) == 0 )
        goto LABEL_125;
      v58 = 0;
      if ( *(_DWORD *)(v1 + 72) )
        v58 = 0x80000000;
      if ( *(_DWORD *)(v1 + 76) )
        v58 |= 0x40000000u;
      if ( *(_DWORD *)(v1 + 80) )
        v58 |= 0x10000000u;
      if ( (*(_DWORD *)(v57 + 980) & v58) != 0 )
      {
LABEL_125:
        *(_WORD *)(v1 + 124) |= 0x2000u;
        ++*(_WORD *)(v1 - 14);
        v59 = KeAbPreAcquire(v3 + 112, 0, 0);
        v60 = v59;
        v61 = (unsigned __int8 *)(v3 + 112);
        do
          v62 = __ldrex(v61);
        while ( __strex(v62 | 1, v61) );
        __dmb(0xBu);
        if ( (v62 & 1) != 0 )
        {
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 112), v59, v3 + 112);
          v61 = (unsigned __int8 *)(v3 + 112);
        }
        if ( v60 )
          *(_BYTE *)(v60 + 14) |= 1u;
        v63 = *(_DWORD *)(v1 + 20);
        *(_DWORD *)(v1 + 8) = v3;
        *(_DWORD *)(v1 + 20) = (v63 & 0xFFFFFF87 | (4 * (*(_DWORD *)(v3 + 244) & 6))) & 0xFFFFFFF8 | 3;
        v64 = *(_DWORD *)(v3 + 120);
        *(_DWORD *)v1 = v3 + 116;
        *(_DWORD *)(v1 + 4) = v64;
        **(_DWORD **)(v3 + 120) = v1;
        *(_DWORD *)(v3 + 120) = v1;
        ++*(_DWORD *)(v3 + 268);
        __dmb(0xBu);
        do
          v65 = __ldrex((unsigned int *)v61);
        while ( __strex(v65 - 1, (unsigned int *)v61) );
        if ( (v65 & 2) != 0 && (v65 & 4) == 0 )
        {
          ExfTryToWakePushLock((unsigned int *)v61);
          v61 = (unsigned __int8 *)(v3 + 112);
        }
        KeAbPostRelease((unsigned int)v61);
        v57 = v127;
      }
      else
      {
        *(_WORD *)(v1 + 124) &= 0xDFFFu;
      }
      *(_DWORD *)(HIDWORD(v1) + 980) = v1;
      ++*(_WORD *)(v1 - 14);
      *(_DWORD *)(v1 + 20) |= 0x4000u;
      if ( AlpcpLogEnabled )
      {
        AlpcpLogSendMessage(v1, v58);
        v57 = v127;
      }
      v83 = *(_QWORD *)(v57 + 988);
      if ( *(_DWORD *)(v83 + 4) != v57 + 988 || *(_DWORD *)HIDWORD(v83) != v57 + 988 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v83) = v83;
      *(_DWORD *)(v83 + 4) = HIDWORD(v83);
      *(_DWORD *)(HIDWORD(v1) + 988) = 0;
      *(_DWORD *)(v1 + 20) &= 0xFFFEFFFF;
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v1);
      v66 = *(_BYTE *)(v1 - 16);
      v67 = 0;
      if ( (v66 & 1) != 0 )
      {
        v68 = *(__int16 *)(v1 - 14);
        *(_WORD *)(v1 - 14) = 0;
        v67 = 0x10000 - v68;
        *(_BYTE *)(v1 - 16) = BYTE4(v1) & 0xFE;
      }
      v69 = (unsigned int *)(v1 - 4);
      __dmb(0xBu);
      do
        v70 = __ldrex(v69);
      while ( __strex(v70 - 1, v69) );
      if ( (v70 & 2) != 0 && (v70 & 4) == 0 )
      {
        ExfTryToWakePushLock(v69);
        v69 = (unsigned int *)(v1 - 4);
      }
      KeAbPostRelease((unsigned int)v69);
      if ( v67 > 0 )
      {
        __dmb(0xBu);
        v71 = (unsigned int *)(v1 - 12);
        do
        {
          v72 = __ldrex(v71);
          v73 = v72 - v67;
        }
        while ( __strex(v73, v71) );
        __dmb(0xBu);
        if ( v73 <= 0 )
        {
          if ( v73 )
            KeBugCheckEx(24, 0, v1, 40, v73);
          AlpcpDestroyBlob(v1);
        }
      }
      v74 = (unsigned int *)(v131 - 4);
      __dmb(0xBu);
      do
        v75 = __ldrex(v74);
      while ( v75 == 17 && __strex(0, v74) );
      if ( v75 != 17 )
        ExfReleasePushLockShared(v74);
      KeAbPostRelease((unsigned int)v74);
      __dmb(0xBu);
      v84 = (unsigned int *)(v3 + 136);
      do
        v85 = __ldrex(v84);
      while ( __strex(v85 - 1, v84) );
      if ( (v85 & 2) != 0 && (v85 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v3 + 136));
      KeAbPostRelease(v3 + 136);
      v86 = (unsigned int *)(v3 + 208);
      __dmb(0xBu);
      do
        v87 = __ldrex(v86);
      while ( v87 == 17 && __strex(0, v86) );
      if ( v87 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v3 + 208));
      KeAbPostRelease(v3 + 208);
      result = ObfDereferenceObject(v3);
      *(_DWORD *)(a1 + 16) = 0;
      if ( !v5 && !v128 )
        return KeReleaseSemaphoreEx(v127 + 884, 1, 1, v127, 2);
      *(_DWORD *)(a1 + 12) = v127;
      return result;
    }
    __dmb(0xBu);
    do
      v82 = __ldrex((unsigned int *)v80);
    while ( __strex(v82 - 1, (unsigned int *)v80) );
    if ( (v82 & 2) != 0 && (v82 & 4) == 0 )
    {
      ExfTryToWakePushLock((unsigned int *)v80);
      v80 = (unsigned __int8 *)(v3 + 136);
    }
    KeAbPostRelease((unsigned int)v80);
  }
  if ( *(_DWORD *)(v3 + 16) )
  {
    v129 = 1;
    v36 = 0;
  }
  else
  {
    v129 = 0;
    v36 = (*(_DWORD *)(v3 + 244) >> 9) & 1;
  }
  v37 = *(_DWORD **)(v3 + 212);
  v135 = v36;
  v137 = v37;
  if ( !v37 || (*(_WORD *)(v3 + 246) & 1) == 0 )
    goto LABEL_62;
  v88 = 0;
  if ( *(_DWORD *)(v1 + 72) )
    v88 = 0x80000000;
  if ( *(_DWORD *)(v1 + 76) )
    v88 |= 0x40000000u;
  if ( *(_DWORD *)(v1 + 80) )
    v88 |= 0x10000000u;
  v9 = v37[20];
  if ( (v88 & ~v9) != 0 || (*(unsigned __int16 *)(v1 + 124) & 0xFFFF00FF) == 5 && (v9 & 0x20000000) == 0 )
    goto LABEL_62;
  v89 = *(unsigned __int16 *)(v1 + 122);
  v133 = v89;
  if ( v9 )
  {
    v90 = (((unsigned __int8)*(_WORD *)(v1 + 122) + (_BYTE)v1 + 120) & 3) != 0 ? 4
                                                                               - (((unsigned __int8)*(_WORD *)(v1 + 122)
                                                                                 + (_BYTE)v1
                                                                                 + 120) & 3) : 0;
    v130 = v90;
    v89 += v37[21] + v90;
    v133 = v89;
  }
  else
  {
    v130 = 0;
  }
  v91 = AlpcpAllocateCompletionBuffer(v3, v89);
  v139 = v91;
  if ( v91 == -1 )
    goto LABEL_62;
  v92 = (_DWORD *)(v37[15] + v91);
  v93 = *(_DWORD *)(v1 + 124);
  v94 = *(_DWORD *)(v1 + 128);
  v95 = *(_DWORD *)(v1 + 132);
  *v92 = *(_DWORD *)(v1 + 120);
  v92[1] = v93;
  v92[2] = v94;
  v92[3] = v95;
  v96 = *(_DWORD *)(v1 + 140);
  v92[4] = *(_DWORD *)(v1 + 136);
  v92[5] = v96;
  v138 = v92;
  if ( (*(_DWORD *)(v3 + 152) & 0x1000) != 0 )
    *((_WORD *)v92 + 2) &= 0xC00Fu;
  v97 = v92 + 6;
  if ( *(_DWORD *)(v1 + 88) )
  {
    AlpcpGetDataFromUserVaSafe(v1, v92 + 6);
  }
  else
  {
    v98 = *(unsigned __int16 *)(v1 + 120);
    v99 = v1 + 144;
    v100 = (int)(v92 + 6);
    if ( v98 > 0x100 )
    {
      memmove(v100, v99, 0x100u);
      v99 = *(_DWORD *)(v1 + 108);
      v98 = *(unsigned __int16 *)(v1 + 120) - 256;
      v100 = (int)(v97 + 64);
    }
    memmove(v100, v99, v98);
  }
  v101 = v137[20];
  if ( v101 )
  {
    v102 = (_DWORD *)((char *)v138 + *((unsigned __int16 *)v138 + 1) + v130);
    *v102 = v101;
    v102[1] = 0;
    AlpcpExposeAttributes(v3, v101, v1, v102);
  }
  v45 = AlpcpInsertCompletionListEntry(v3, v139);
  if ( !v45 )
  {
    AlpcpFreeBitmap(
      *(_DWORD *)(*(_DWORD *)(v3 + 212) + 52),
      *(_DWORD *)(v3 + 212),
      v139 >> 6,
      (unsigned int)(v133 + 63) >> 6);
    v5 = v126;
LABEL_62:
    if ( *(_DWORD *)(v1 + 88) )
    {
      AlpcpCaptureMessageDataSafe(v1, v9);
      *(_DWORD *)(v1 + 88) = 0;
    }
    v38 = (unsigned __int8 *)(v3 + 92);
    ++*(_WORD *)(v1 - 14);
    v39 = KeAbPreAcquire(v3 + 92, 0, 0);
    v40 = v39;
    do
      v41 = __ldrex(v38);
    while ( __strex(v41 | 1, v38) );
    __dmb(0xBu);
    if ( (v41 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 92), v39, v3 + 92);
    if ( v40 )
      *(_BYTE *)(v40 + 14) |= 1u;
    v42 = *(_DWORD *)(v1 + 20);
    *(_DWORD *)(v1 + 8) = v3;
    *(_DWORD *)(v1 + 20) = (v42 & 0xFFFFFF87 | (4 * (*(_DWORD *)(v3 + 244) & 6))) & 0xFFFFFFF8 | 1;
    v43 = *(_DWORD *)(v3 + 100);
    *(_DWORD *)v1 = v3 + 96;
    *(_DWORD *)(v1 + 4) = v43;
    **(_DWORD **)(v3 + 100) = v1;
    *(_DWORD *)(v3 + 100) = v1;
    ++*(_DWORD *)(v3 + 260);
    __dmb(0xBu);
    do
      v44 = __ldrex((unsigned int *)v38);
    while ( __strex(v44 - 1, (unsigned int *)v38) );
    if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v3 + 92));
    KeAbPostRelease(v3 + 92);
    goto LABEL_74;
  }
  v103 = v137[10];
  v132 = 1;
  v104 = *(_DWORD *)(v1 + 136);
  __dmb(0xBu);
  *(_DWORD *)(v103 + 136) = v104;
  v105 = v137[10];
  v106 = *(_DWORD *)(v1 + 140);
  __dmb(0xBu);
  *(_DWORD *)(v105 + 140) = v106;
  if ( v129 )
  {
    if ( (v45 & 2) == 0 )
    {
      v107 = *(_QWORD *)(v137[10] + 128);
      __dmb(0xBu);
      v45 = v137[19];
      if ( *(unsigned int *)(*(_DWORD *)(v3 + 24) + 8) + (unsigned __int64)HIWORD(HIDWORD(v107)) >= (unsigned int)v45 )
        v129 = 0;
    }
  }
  if ( (*(_DWORD *)(v1 + 20) & 0x200) != 0 )
  {
    v108 = *(_WORD *)(v1 + 124);
    if ( !HIDWORD(v1) )
    {
      v5 = v126;
      *(_WORD *)(v1 + 124) = v108 & 0xDFFF;
      goto LABEL_74;
    }
    *(_WORD *)(v1 + 124) = v108 | 0x2000;
    v109 = (unsigned __int8 *)(v3 + 112);
    ++*(_WORD *)(v1 - 14);
    v110 = KeAbPreAcquire(v3 + 112, 0, 0);
    v111 = v110;
    do
      v112 = __ldrex(v109);
    while ( __strex(v112 | 1, v109) );
    __dmb(0xBu);
    if ( (v112 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 112), v110, v3 + 112);
    if ( v111 )
      *(_BYTE *)(v111 + 14) |= 1u;
    *(_DWORD *)(v1 + 8) = v3;
    LODWORD(v113) = v3 + 116;
    *(_DWORD *)(v1 + 20) = (*(_DWORD *)(v1 + 20) & 0xFFFFFF87 | (4 * (*(_DWORD *)(v3 + 244) & 6))) & 0xFFFFFFF8 | 3;
    HIDWORD(v113) = *(_DWORD *)(v3 + 120);
    *(_QWORD *)v1 = v113;
    **(_DWORD **)(v3 + 120) = v1;
    *(_DWORD *)(v3 + 120) = v1;
    ++*(_DWORD *)(v3 + 268);
    __dmb(0xBu);
    do
      v114 = __ldrex((unsigned int *)v109);
    while ( __strex(v114 - 1, (unsigned int *)v109) );
    if ( (v114 & 2) != 0 && (v114 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v3 + 112));
  }
  else
  {
    v115 = (unsigned __int8 *)(v3 + 112);
    *(_WORD *)(v1 + 124) |= 0x2000u;
    ++*(_WORD *)(v1 - 14);
    v116 = KeAbPreAcquire(v3 + 112, 0, 0);
    v117 = v116;
    do
      v118 = __ldrex(v115);
    while ( __strex(v118 | 1, v115) );
    __dmb(0xBu);
    if ( (v118 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 112), v116, v3 + 112);
    if ( v117 )
      *(_BYTE *)(v117 + 14) |= 1u;
    *(_DWORD *)(v1 + 8) = v3;
    LODWORD(v119) = v3 + 116;
    *(_DWORD *)(v1 + 20) = (*(_DWORD *)(v1 + 20) & 0xFFFFFF87 | (4 * (*(_DWORD *)(v3 + 244) & 6))) & 0xFFFFFFF8 | 3;
    HIDWORD(v119) = *(_DWORD *)(v3 + 120);
    *(_QWORD *)v1 = v119;
    **(_DWORD **)(v3 + 120) = v1;
    *(_DWORD *)(v3 + 120) = v1;
    ++*(_DWORD *)(v3 + 268);
    __dmb(0xBu);
    do
      v120 = __ldrex((unsigned int *)v115);
    while ( __strex(v120 - 1, (unsigned int *)v115) );
    if ( (v120 & 2) != 0 && (v120 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v3 + 112));
  }
  KeAbPostRelease(v3 + 112);
  v5 = v126;
LABEL_74:
  v46 = (unsigned __int8)AlpcpLogEnabled;
  if ( AlpcpLogEnabled )
  {
    AlpcpLogSendMessage(v1, v45);
    v46 = (unsigned __int8)AlpcpLogEnabled;
  }
  if ( v46 && v5 )
    AlpcpLogWaitForReply(v1);
  *(_DWORD *)(v1 + 20) &= 0xFFFEFFFF;
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v1);
  v47 = *(_BYTE *)(v1 - 16);
  v48 = 0;
  if ( (v47 & 1) != 0 )
  {
    v49 = *(__int16 *)(v1 - 14);
    *(_WORD *)(v1 - 14) = 0;
    v48 = 0x10000 - v49;
    *(_BYTE *)(v1 - 16) = BYTE4(v1) & 0xFE;
  }
  v50 = (unsigned int *)(v1 - 4);
  __dmb(0xBu);
  do
    v51 = __ldrex(v50);
  while ( __strex(v51 - 1, v50) );
  if ( (v51 & 2) != 0 && (v51 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v1 - 4));
  KeAbPostRelease(v1 - 4);
  if ( v48 > 0 )
  {
    __dmb(0xBu);
    v52 = (unsigned int *)(v1 - 12);
    do
    {
      v53 = __ldrex(v52);
      v54 = v53 - v48;
    }
    while ( __strex(v54, v52) );
    __dmb(0xBu);
    if ( v54 <= 0 )
    {
      if ( v54 )
        KeBugCheckEx(24, 0, v1, 40, v54);
      AlpcpDestroyBlob(v1);
    }
  }
  v55 = (unsigned int *)(v131 - 4);
  __dmb(0xBu);
  do
    v56 = __ldrex(v55);
  while ( v56 == 17 && __strex(0, v55) );
  if ( v56 != 17 )
    ExfReleasePushLockShared(v55);
  result = KeAbPostRelease((unsigned int)v55);
  if ( !v135 )
  {
    if ( v129 )
    {
      if ( v5 || v128 )
      {
        *(_BYTE *)(a1 + 34) = 1;
        *(_BYTE *)(a1 + 35) = v132;
        return result;
      }
      AlpcpQueueIoCompletionPort((_DWORD *)v3, v132, 1);
    }
    else
    {
      v123 = *(_DWORD *)(v3 + 216);
      v124 = (unsigned int *)(v3 + 208);
      __dmb(0xBu);
      do
        v125 = __ldrex(v124);
      while ( v125 == 17 && __strex(0, v124) );
      if ( v125 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v3 + 208));
      KeAbPostRelease(v3 + 208);
      if ( v123 )
        ExNotifyCallback(v123, *(_DWORD *)(v3 + 220), *(_DWORD *)(a1 + 24));
    }
    result = ObfDereferenceObject(v3);
    *(_DWORD *)(a1 + 16) = 0;
    return result;
  }
  v121 = (unsigned int *)(v3 + 208);
  __dmb(0xBu);
  do
    v122 = __ldrex(v121);
  while ( v122 == 17 && __strex(0, v121) );
  if ( v122 != 17 )
    ExfReleasePushLockShared((_DWORD *)(v3 + 208));
  result = KeAbPostRelease(v3 + 208);
  if ( v5 || v128 )
  {
    *(_BYTE *)(a1 + 34) = 0;
  }
  else
  {
    KeReleaseSemaphoreEx(*(_DWORD *)(v3 + 148), 1, 1, 0, 0);
    result = ObfDereferenceObject(v3);
    *(_DWORD *)(a1 + 16) = 0;
  }
  return result;
}
