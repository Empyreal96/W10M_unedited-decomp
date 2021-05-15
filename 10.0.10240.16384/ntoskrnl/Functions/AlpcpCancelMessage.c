// AlpcpCancelMessage 
 
int __fastcall AlpcpCancelMessage(_DWORD *a1, int a2, int a3)
{
  int v4; // r1
  char v5; // lr
  _DWORD *v6; // r8
  int v7; // r2
  int v8; // r3
  _DWORD *v9; // r5
  int v10; // r9
  BOOL v11; // r10
  int v12; // r7
  unsigned int *v13; // r6
  int v14; // r0
  int v15; // r8
  unsigned int v16; // r2
  unsigned int v17; // r2
  BOOL v18; // r1
  int v19; // r3
  int v20; // r0
  int v21; // r6
  int v22; // r6
  int v23; // r0
  int v24; // r3
  int v25; // r8
  unsigned __int8 *v26; // r6
  int v27; // r0
  int v28; // r7
  unsigned int v29; // r2
  unsigned int v30; // r1
  char v31; // r2
  int v32; // r8
  int v33; // r3
  unsigned int *v34; // r7
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r0
  bool v40; // zf
  int v41; // r3
  BOOL v42; // r10
  int v43; // r8
  int v44; // r0
  int v45; // r7
  unsigned int v46; // r2
  int v47; // r0
  int v48; // r7
  unsigned int v49; // r2
  unsigned int *v50; // r2
  unsigned int v51; // r1
  int v52; // r3
  int v53; // r1
  int v54; // r6
  unsigned int *v55; // r2
  unsigned int v56; // r1
  unsigned int v57; // r1
  unsigned __int8 *v58; // r8
  int v59; // r0
  int v60; // r7
  unsigned int v61; // r2
  __int64 v62; // r2
  unsigned int v63; // r1
  unsigned int v64; // r2
  int v65; // r8
  int v66; // r0
  int v67; // r7
  unsigned int v68; // r2
  int v69; // r1
  unsigned int *v70; // r6
  int v71; // r0
  int v72; // r7
  unsigned int v73; // r2
  unsigned int v74; // r2
  unsigned __int8 *v75; // r8
  int v76; // r0
  int v77; // r7
  unsigned int v78; // r2
  int v79; // r7
  __int64 *v80; // r2
  __int64 v81; // r0
  unsigned int v82; // r1
  unsigned int v83; // r2
  int v84; // r3
  unsigned int v85; // r2
  int v86; // r0
  int v87; // r7
  unsigned int v88; // r2
  int v89; // r8
  unsigned __int8 *v90; // r6
  int v91; // r0
  int v92; // r7
  unsigned int v93; // r2
  int v94; // r3
  unsigned int v95; // r1
  _DWORD *v96; // [sp+18h] [bp-30h]
  int v97; // [sp+1Ch] [bp-2Ch]
  int v99; // [sp+24h] [bp-24h]
  int v100; // [sp+24h] [bp-24h]

  v4 = *(_DWORD *)(a2 + 20);
  v5 = a3;
  v6 = *(_DWORD **)(a2 + 8);
  v7 = v4 & 7;
  v8 = (a1[61] >> 1) & 3;
  v9 = 0;
  v96 = v6;
  v99 = v7;
  v10 = 0;
  if ( v8 == 1 )
  {
    v11 = (v4 & 0x78) == 8;
    v97 = v11;
    if ( (v4 & 0x80) != 0 )
      goto LABEL_18;
    v12 = *(_DWORD *)(a2 + 92);
    if ( !v12 )
      goto LABEL_18;
    v13 = (unsigned int *)(v12 - 4);
    v14 = KeAbPreAcquire(v12 - 4, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex(v13);
    while ( !v16 && __strex(0x11u, v13) );
    __dmb(0xBu);
    if ( v16 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v12 - 4), v14, v12 - 4);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    if ( (*(_DWORD *)(a2 + 20) & 0x200) == 0 )
    {
      if ( v11 )
      {
        v9 = *(_DWORD **)(v12 + 8);
        v10 = (int)v9;
      }
      else
      {
        v10 = *(_DWORD *)(v12 + 4);
        v9 = *(_DWORD **)v12;
      }
      if ( v9 && !ObReferenceObjectSafe((int)v9) )
        v9 = 0;
      if ( v10 && !ObReferenceObjectSafe(v10) )
        v10 = 0;
    }
    __dmb(0xBu);
    do
      v17 = __ldrex(v13);
    while ( v17 == 17 && __strex(0, v13) );
    goto LABEL_15;
  }
  v40 = v8 == 2;
  v41 = v4 & 0x78;
  if ( v40 )
  {
    v42 = v41 == 16;
    v97 = v42;
    if ( (v4 & 0x80) != 0 )
      goto LABEL_18;
    v43 = a1[2];
    v13 = (unsigned int *)(v43 - 4);
    v44 = KeAbPreAcquire(v43 - 4, 0, 0);
    v45 = v44;
    do
      v46 = __ldrex(v13);
    while ( !v46 && __strex(0x11u, v13) );
    __dmb(0xBu);
    if ( v46 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v43 - 4), v44, v43 - 4);
    if ( v45 )
      *(_BYTE *)(v45 + 14) |= 1u;
    if ( (*(_DWORD *)(a2 + 20) & 0x200) != 0 )
      goto LABEL_79;
    if ( v42 )
    {
      v10 = *(_DWORD *)(v43 + 4);
      v9 = *(_DWORD **)v43;
    }
    else
    {
      v10 = (int)a1;
      v9 = a1;
    }
    goto LABEL_85;
  }
  if ( v41 != 8 )
    return sub_7E5D1C();
  v97 = 1;
  if ( (v4 & 0x80) == 0 )
  {
    v65 = a1[2];
    v13 = (unsigned int *)(v65 - 4);
    v66 = KeAbPreAcquire(v65 - 4, 0, 0);
    v67 = v66;
    do
      v68 = __ldrex(v13);
    while ( !v68 && __strex(0x11u, v13) );
    __dmb(0xBu);
    if ( v68 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v65 - 4), v66, v65 - 4);
    if ( v67 )
      *(_BYTE *)(v67 + 14) |= 1u;
    if ( (*(_DWORD *)(a2 + 20) & 0x200) != 0 )
      goto LABEL_79;
    v9 = *(_DWORD **)(v65 + 8);
    v10 = (int)v9;
LABEL_85:
    if ( v9 && !ObReferenceObjectSafe((int)v9) )
      v9 = 0;
    if ( v10 && !ObReferenceObjectSafe(v10) )
      v10 = 0;
LABEL_79:
    __dmb(0xBu);
    do
      v17 = __ldrex(v13);
    while ( v17 == 17 && __strex(0, v13) );
LABEL_15:
    if ( v17 != 17 )
      ExfReleasePushLockShared(v13);
    KeAbPostRelease((unsigned int)v13);
    v5 = a3;
    v7 = v99;
    v6 = v96;
  }
LABEL_18:
  if ( v97 )
  {
    v18 = v7 == 3 && v6 && (*(_DWORD *)(a2 + 20) & 0x4000) == 0;
    v100 = 259;
    if ( (v5 & 1) == 0 || v18 )
      goto LABEL_24;
  }
  else
  {
    if ( v6 && (v7 != 3 || (*(_DWORD *)(a2 + 20) & 0x4000) != 0) )
    {
      v53 = 0;
      v54 = 0;
    }
    else
    {
      v53 = 1;
      v54 = 1073741870;
    }
    v100 = v54;
    if ( (v5 & 1) == 0 || !v53 )
    {
LABEL_24:
      v19 = *(_DWORD *)(a2 + 20);
      *(_WORD *)(a2 + 120) = 0;
      *(_DWORD *)(a2 + 20) = v19 | 0x80;
      *(_WORD *)(a2 + 124) = *(_WORD *)(a2 + 124) & 0xFF0C | 0xC;
      *(_WORD *)(a2 + 122) = 24;
      AlpcpReleaseMessageAttributesOnCancel(a2);
      *(_WORD *)(a2 + 124) &= 0xDFFFu;
      *(_DWORD *)(a2 + 20) |= 0x10200u;
      __dmb(0xFu);
      v20 = *(_DWORD *)(a2 + 12);
      if ( v20 )
      {
        if ( (*(_DWORD *)(a2 + 20) & 0x1000) != 0 )
          ObfDereferenceObject(v20);
        *(_DWORD *)(a2 + 12) = 0;
      }
      v21 = *(_DWORD *)(a2 + 28);
      if ( v21 && (*(_DWORD *)(a2 + 20) & 0x400) == 0 && !*(_DWORD *)(a2 + 52) )
      {
        v69 = 400;
        if ( *(_DWORD *)(a2 + 108) )
          v69 = *(_DWORD *)(a2 + 112) + 400;
        *(_DWORD *)(a2 + 28) = PsTransferProcessQuotaToSharedQuota(*(_DWORD *)(a2 + 28), v69);
        ObfDereferenceObjectWithTag(v21);
        *(_DWORD *)(a2 + 20) |= 0x400u;
      }
      v22 = *(_DWORD *)(a2 + 104);
      if ( v22 )
      {
        PspChargeJobWakeCounter(v22 & 0xFFFFFFF8);
        ObDereferenceObjectDeferDeleteWithTag(v22 & 0xFFFFFFF8);
        *(_DWORD *)(a2 + 104) = 0;
      }
      v23 = *(_DWORD *)(a2 + 16);
      if ( v23 )
      {
        __dmb(0xBu);
        v50 = (unsigned int *)(v23 + 976);
        do
          v51 = __ldrex(v50);
        while ( __strex(0, v50) );
        __dmb(0xBu);
        if ( v51 == a2 )
        {
          *(_DWORD *)(a2 + 16) = 0;
          v52 = *(__int16 *)(a2 - 14) - 2;
          *(_WORD *)(a2 - 14) = v52;
          KeReleaseSemaphoreEx(v23 + 884, 1, 1, v52, 2);
        }
      }
      else if ( v9 && v10 )
      {
        if ( !v97 && (a3 & 2) == 0 )
          goto LABEL_48;
        v70 = v9 + 52;
        v71 = KeAbPreAcquire((unsigned int)(v9 + 52), 0, 0);
        v72 = v71;
        do
          v73 = __ldrex(v70);
        while ( !v73 && __strex(0x11u, v70) );
        __dmb(0xBu);
        if ( v73 )
          ExfAcquirePushLockSharedEx(v9 + 52, v71, (unsigned int)(v9 + 52));
        if ( v72 )
          *(_BYTE *)(v72 + 14) |= 1u;
        if ( (v9[61] & 0x40) != 0 )
        {
          __dmb(0xBu);
          do
            v74 = __ldrex(v70);
          while ( v74 == 17 && __strex(0, v70) );
          if ( v74 != 17 )
            ExfReleasePushLockShared(v9 + 52);
          KeAbPostRelease((unsigned int)(v9 + 52));
        }
        else
        {
          *(_DWORD *)(a2 + 32) = v10;
          *(_DWORD *)(a2 + 36) = v9;
          ++*(_WORD *)(a2 - 14);
          __dmb(0xBu);
          v55 = (unsigned int *)(v10 + 232);
          do
          {
            v56 = __ldrex(v55);
            v57 = v56 + 1;
          }
          while ( __strex(v57, v55) );
          __dmb(0xBu);
          *(_DWORD *)(a2 + 40) = v57;
          v58 = (unsigned __int8 *)(v9 + 23);
          *(_DWORD *)(a2 + 68) = *(_DWORD *)(v10 + 28);
          v59 = KeAbPreAcquire((unsigned int)(v9 + 23), 0, 0);
          v60 = v59;
          do
            v61 = __ldrex(v58);
          while ( __strex(v61 | 1, v58) );
          __dmb(0xBu);
          if ( (v61 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v9 + 23, v59, (unsigned int)(v9 + 23));
          if ( v60 )
            *(_BYTE *)(v60 + 14) |= 1u;
          LODWORD(v62) = v9 + 56;
          HIDWORD(v62) = v9[57];
          *(_QWORD *)(a2 + 44) = v62;
          *(_DWORD *)v9[57] = a2 + 44;
          v9[57] = a2 + 44;
          ++v9[69];
          __dmb(0xBu);
          do
            v63 = __ldrex((unsigned int *)v58);
          while ( __strex(v63 - 1, (unsigned int *)v58) );
          if ( (v63 & 2) != 0 && (v63 & 4) == 0 )
            ExfTryToWakePushLock(v9 + 23);
          KeAbPostRelease((unsigned int)(v9 + 23));
          if ( v9[4] )
          {
            AlpcpQueueIoCompletionPort(v9, 0, 1);
          }
          else if ( (v9[61] & 0x200) != 0 )
          {
            __dmb(0xBu);
            do
              v64 = __ldrex(v70);
            while ( v64 == 17 && __strex(0, v70) );
            if ( v64 != 17 )
              ExfReleasePushLockShared(v9 + 52);
            KeAbPostRelease((unsigned int)(v9 + 52));
            KeReleaseSemaphoreEx(v9[37], 1, 1, 0, 0);
          }
          else
          {
            if ( (_DWORD *)v9[35] == v9 + 35 )
              goto LABEL_213;
            v75 = (unsigned __int8 *)(v9 + 34);
            v76 = KeAbPreAcquire((unsigned int)(v9 + 34), 0, 0);
            v77 = v76;
            do
              v78 = __ldrex(v75);
            while ( __strex(v78 | 1, v75) );
            __dmb(0xBu);
            if ( (v78 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v9 + 34, v76, (unsigned int)(v9 + 34));
            if ( v77 )
              *(_BYTE *)(v77 + 14) |= 1u;
            if ( (_DWORD *)v9[35] == v9 + 35 )
            {
              v79 = 0;
            }
            else
            {
              v79 = v9[35] - 988;
              v80 = (__int64 *)v9[35];
              *((_DWORD *)v80 - 2) = 0;
              v81 = *v80;
              if ( *(__int64 **)(*(_DWORD *)v80 + 4) != v80 || *(__int64 **)HIDWORD(v81) != v80 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v81) = v81;
              *(_DWORD *)(v81 + 4) = HIDWORD(v81);
              *(_DWORD *)(v79 + 988) = 0;
            }
            __dmb(0xBu);
            do
              v82 = __ldrex((unsigned int *)v75);
            while ( __strex(v82 - 1, (unsigned int *)v75) );
            if ( (v82 & 2) != 0 && (v82 & 4) == 0 )
              ExfTryToWakePushLock(v9 + 34);
            KeAbPostRelease((unsigned int)(v9 + 34));
            if ( !v79 )
            {
LABEL_213:
              __dmb(0xBu);
              do
                v85 = __ldrex(v70);
              while ( v85 == 17 && __strex(0, v70) );
              if ( v85 != 17 )
                ExfReleasePushLockShared(v9 + 52);
              KeAbPostRelease((unsigned int)(v9 + 52));
            }
            else
            {
              __dmb(0xBu);
              do
                v83 = __ldrex(v70);
              while ( v83 == 17 && __strex(0, v70) );
              if ( v83 != 17 )
                ExfReleasePushLockShared(v9 + 52);
              KeAbPostRelease((unsigned int)(v9 + 52));
              KeReleaseSemaphoreEx(v79 + 884, 1, 1, v84, 2);
            }
          }
          v6 = v96;
        }
      }
      if ( v97 && (a3 & 0x10000) != 0 && v6 )
      {
        v24 = *(_DWORD *)(a2 + 20) & 7;
        if ( v24 == 3 )
        {
          v25 = *(_DWORD *)(a2 + 8);
          v26 = (unsigned __int8 *)(v25 + 112);
          v27 = KeAbPreAcquire(v25 + 112, 0, 0);
          v28 = v27;
          do
            v29 = __ldrex(v26);
          while ( __strex(v29 | 1, v26) );
          __dmb(0xBu);
          if ( (v29 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx((_DWORD *)(v25 + 112), v27, v25 + 112);
          if ( v28 )
            *(_BYTE *)(v28 + 14) |= 1u;
          --*(_DWORD *)(v25 + 268);
        }
        else
        {
          if ( v24 != 4 )
          {
            v26 = (unsigned __int8 *)(v6 + 23);
            v47 = KeAbPreAcquire((unsigned int)(v6 + 23), 0, 0);
            v48 = v47;
            do
              v49 = __ldrex(v26);
            while ( __strex(v49 | 1, v26) );
            __dmb(0xBu);
            if ( (v49 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v6 + 23, v47, (unsigned int)(v6 + 23));
            if ( v48 )
              *(_BYTE *)(v48 + 14) |= 1u;
            if ( (*(_DWORD *)(a2 + 20) & 7) == 1 )
              --v6[65];
            else
              --v6[66];
            *(_DWORD *)(a2 + 20) &= 0xFFFFFFF8;
            *(_DWORD *)(a2 + 8) = 0;
            **(_DWORD **)(a2 + 4) = *(_DWORD *)a2;
            *(_DWORD *)(*(_DWORD *)a2 + 4) = *(_DWORD *)(a2 + 4);
            __dmb(0xBu);
            do
              v30 = __ldrex((unsigned int *)v26);
            while ( __strex(v30 - 1, (unsigned int *)v26) );
            goto LABEL_46;
          }
          v26 = (unsigned __int8 *)(a1 + 31);
          v86 = KeAbPreAcquire((unsigned int)(a1 + 31), 0, 0);
          v87 = v86;
          do
            v88 = __ldrex(v26);
          while ( __strex(v88 | 1, v26) );
          __dmb(0xBu);
          if ( (v88 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v26, v86, (unsigned int)v26);
          if ( v87 )
            *(_BYTE *)(v87 + 14) |= 1u;
          --a1[68];
        }
        *(_DWORD *)(a2 + 20) &= 0xFFFFFFF8;
        *(_DWORD *)(a2 + 8) = 0;
        **(_DWORD **)(a2 + 4) = *(_DWORD *)a2;
        *(_DWORD *)(*(_DWORD *)a2 + 4) = *(_DWORD *)(a2 + 4);
        __dmb(0xBu);
        do
          v30 = __ldrex((unsigned int *)v26);
        while ( __strex(v30 - 1, (unsigned int *)v26) );
LABEL_46:
        if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v26);
        KeAbPostRelease((unsigned int)v26);
        --*(_WORD *)(a2 - 14);
      }
LABEL_48:
      if ( (*(_DWORD *)(a2 + 20) & 0x4000) != 0 && (*(_DWORD *)(a2 + 20) & 7) == 3 )
      {
        v89 = *(_DWORD *)(a2 + 8);
        v90 = (unsigned __int8 *)(v89 + 112);
        v91 = KeAbPreAcquire(v89 + 112, 0, 0);
        v92 = v91;
        do
          v93 = __ldrex(v90);
        while ( __strex(v93 | 1, v90) );
        __dmb(0xBu);
        if ( (v93 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v89 + 112), v91, v89 + 112);
        if ( v92 )
          *(_BYTE *)(v92 + 14) |= 1u;
        --*(_DWORD *)(v89 + 268);
        v94 = *(_DWORD *)(a2 + 20);
        *(_DWORD *)(a2 + 8) = 0;
        *(_DWORD *)(a2 + 20) = v94 & 0xFFFFFFF8;
        **(_DWORD **)(a2 + 4) = *(_DWORD *)a2;
        *(_DWORD *)(*(_DWORD *)a2 + 4) = *(_DWORD *)(a2 + 4);
        __dmb(0xBu);
        do
          v95 = __ldrex((unsigned int *)v90);
        while ( __strex(v95 - 1, (unsigned int *)v90) );
        if ( (v95 & 2) != 0 && (v95 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v89 + 112));
        KeAbPostRelease(v89 + 112);
        --*(_WORD *)(a2 - 14);
      }
      goto LABEL_49;
    }
  }
LABEL_49:
  *(_DWORD *)(a2 + 20) &= 0xFFFEFFFF;
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(a2);
  v31 = *(_BYTE *)(a2 - 16);
  v32 = 0;
  if ( (v31 & 1) != 0 )
  {
    v33 = *(__int16 *)(a2 - 14);
    *(_WORD *)(a2 - 14) = 0;
    v32 = 0x10000 - v33;
    *(_BYTE *)(a2 - 16) = v31 & 0xFE;
  }
  v34 = (unsigned int *)(a2 - 4);
  __dmb(0xBu);
  do
    v35 = __ldrex(v34);
  while ( __strex(v35 - 1, v34) );
  if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a2 - 4));
  KeAbPostRelease(a2 - 4);
  if ( v32 > 0 )
  {
    __dmb(0xBu);
    v36 = (unsigned int *)(a2 - 12);
    do
    {
      v37 = __ldrex(v36);
      v38 = v37 - v32;
    }
    while ( __strex(v38, v36) );
    __dmb(0xBu);
    if ( v38 <= 0 )
    {
      if ( v38 )
        KeBugCheckEx(24, 0, a2, 40, v38);
      AlpcpDestroyBlob(a2);
    }
  }
  if ( v9 )
    ObfDereferenceObject((int)v9);
  if ( v10 )
    ObfDereferenceObject(v10);
  return v100;
}
