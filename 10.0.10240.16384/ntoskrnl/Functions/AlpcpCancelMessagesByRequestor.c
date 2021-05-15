// AlpcpCancelMessagesByRequestor 
 
int __fastcall AlpcpCancelMessagesByRequestor(int a1, int a2, int *a3, unsigned int a4, int a5)
{
  int v5; // r7
  int v8; // r6
  unsigned __int8 *v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r4
  unsigned int *v14; // r4
  unsigned int v15; // r1
  unsigned __int8 *v17; // r5
  unsigned int v18; // r2
  unsigned __int8 *v19; // r5
  int v20; // r7
  int v21; // r5
  bool v22; // zf
  unsigned int *v23; // r6
  int v24; // r0
  int v25; // r1
  unsigned __int8 *v26; // r5
  int v27; // r0
  unsigned int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r1
  int v32; // r6
  int v33; // r3
  int v34; // r2
  __int16 v35; // r3
  int v36; // r3
  int v37; // r3
  int v38; // r0
  int v39; // r2
  __int16 v40; // r3
  int v41; // r5
  int v42; // r5
  char v43; // r2
  int v44; // r6
  int v45; // r3
  unsigned int *v46; // r5
  unsigned int v47; // r1
  unsigned int *v48; // r2
  unsigned int v49; // r5
  int v50; // r5
  unsigned int *v51; // r5
  unsigned int v52; // r1
  unsigned __int8 *v53; // r6
  int v54; // r0
  int v55; // r5
  unsigned int v56; // r2
  unsigned int *v57; // r2
  unsigned int v58; // r1
  int v59; // r1
  unsigned __int8 *v60; // r6
  int v61; // r0
  int v62; // r5
  unsigned int v63; // r2
  int v64; // r6
  unsigned int *v65; // r5
  unsigned int v66; // r1
  unsigned int *v67; // r2
  unsigned int v68; // r0
  int v69; // r0
  int v70; // r6
  unsigned int *v71; // r5
  unsigned int v72; // r1
  unsigned int *v73; // r2
  unsigned int v74; // r0
  int v75; // r0
  unsigned __int8 *v76; // r6
  unsigned int v77; // r2
  int *i; // r3
  __int16 v79; // r3
  unsigned int *v80; // r2
  unsigned int v81; // r1
  int v82; // r1
  int v83; // r2
  char v84; // r3
  int v87; // [sp+20h] [bp-28h]
  int v88; // [sp+24h] [bp-24h]
  int v89; // [sp+28h] [bp-20h]

  v5 = a1;
  if ( (*(_DWORD *)(a1 + 244) & 6) == 4 )
  {
    if ( (*(_DWORD *)(a2 + 244) & 6) == 4 )
      goto LABEL_4;
  }
  else if ( (*(_DWORD *)(a2 + 244) & 6) == 2 )
  {
    goto LABEL_4;
  }
  if ( a4 == 3 )
  {
    v8 = 0;
    v88 = 0;
    v89 = 1;
    goto LABEL_23;
  }
LABEL_4:
  v8 = 0;
  v88 = 0;
  v89 = 0;
  if ( a4 > 2 )
  {
    if ( a4 != 3 )
    {
      v19 = (unsigned __int8 *)(a2 + 124);
      v11 = KeAbPreAcquire(a2 + 124, 0, 0);
      do
        v18 = __ldrex(v19);
      while ( __strex(v18 | 1, v19) );
      goto LABEL_25;
    }
LABEL_23:
    v17 = (unsigned __int8 *)(a2 + 112);
    v11 = KeAbPreAcquire(a2 + 112, 0, 0);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 1, v17) );
LABEL_25:
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
      return sub_807424();
    if ( !v11 )
      goto LABEL_11;
    goto LABEL_10;
  }
  v9 = (unsigned __int8 *)(a2 + 92);
  v10 = KeAbPreAcquire(a2 + 92, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 92), v10, a2 + 92);
  if ( v11 )
LABEL_10:
    *(_BYTE *)(v11 + 14) |= 1u;
LABEL_11:
  v13 = *a3;
  if ( (int *)*a3 == a3 )
    goto LABEL_12;
  do
  {
    v87 = v13;
    if ( *(_DWORD *)(v13 + 12) != v5 && (*(_WORD *)(v13 + 22) & 1) == 0 )
    {
      v13 = *(_DWORD *)v13;
      continue;
    }
    v20 = v13 - 24;
    v21 = *(_DWORD *)(v13 - 12);
    v22 = v21 == 0;
    if ( v21 <= 0 )
    {
LABEL_125:
      if ( !v22 )
        KeBugCheckEx(24, 0, v13, 32, v21);
    }
    else
    {
      v23 = (unsigned int *)(v13 - 12);
      while ( 1 )
      {
        v24 = v21;
        __dmb(0xBu);
        do
          v25 = __ldrex(v23);
        while ( v25 == v21 && __strex(v21 + 1, v23) );
        v21 = v25;
        __dmb(0xBu);
        if ( v25 == v24 )
          break;
        if ( v25 <= 0 )
        {
          v22 = v25 == 0;
          goto LABEL_125;
        }
      }
    }
    v26 = (unsigned __int8 *)(v13 - 4);
    v27 = KeAbPreAcquire(v13 - 4, 0, 1);
    do
      v28 = __ldrex(v26);
    while ( __strex(v28 | 1, v26) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
    {
      if ( v27 )
        KeAbPostReleaseEx(v13 - 4, v27);
      if ( a4 > 2 )
      {
        if ( a4 == 3 )
          v51 = (unsigned int *)(a2 + 112);
        else
          v51 = (unsigned int *)(a2 + 124);
        __dmb(0xBu);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 - 1, v51) );
      }
      else
      {
        v51 = (unsigned int *)(a2 + 92);
        __dmb(0xBu);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 - 1, v51) );
      }
      if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
        ExfTryToWakePushLock(v51);
      KeAbPostRelease((unsigned int)v51);
      v53 = (unsigned __int8 *)(v13 - 4);
      v88 = 1;
      v54 = KeAbPreAcquire(v13 - 4, 0, 0);
      v55 = v54;
      do
        v56 = __ldrex(v53);
      while ( __strex(v56 | 1, v53) );
      __dmb(0xBu);
      if ( (v56 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 - 4), v54, v13 - 4);
      if ( v55 )
        *(_BYTE *)(v55 + 14) |= 1u;
      *(_BYTE *)(v13 - 16) |= 1u;
      __dmb(0xBu);
      v57 = (unsigned int *)(v13 - 12);
      do
      {
        v58 = __ldrex(v57);
        v59 = v58 + 0x10000;
      }
      while ( __strex(v59, v57) );
      __dmb(0xBu);
      if ( v59 <= 0 )
        KeBugCheckEx(24, 0, v13, 38, v59);
      if ( a4 > 2 )
      {
        if ( a4 == 3 )
        {
          v76 = (unsigned __int8 *)(a2 + 112);
          v62 = KeAbPreAcquire(a2 + 112, 0, 0);
          do
            v77 = __ldrex(v76);
          while ( __strex(v77 | 1, v76) );
        }
        else
        {
          v76 = (unsigned __int8 *)(a2 + 124);
          v62 = KeAbPreAcquire(a2 + 124, 0, 0);
          do
            v77 = __ldrex(v76);
          while ( __strex(v77 | 1, v76) );
        }
        __dmb(0xBu);
        if ( (v77 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v76, v62, (unsigned int)v76);
        if ( !v62 )
          goto LABEL_104;
      }
      else
      {
        v60 = (unsigned __int8 *)(a2 + 92);
        v61 = KeAbPreAcquire(a2 + 92, 0, 0);
        v62 = v61;
        do
          v63 = __ldrex(v60);
        while ( __strex(v63 | 1, v60) );
        __dmb(0xBu);
        if ( (v63 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 92), v61, a2 + 92);
        if ( !v62 )
          goto LABEL_104;
      }
      *(_BYTE *)(v62 + 14) |= 1u;
LABEL_104:
      if ( *(_DWORD *)(v13 + 12) == a1 )
      {
        for ( i = (int *)*a3; i != a3; i = (int *)*i )
        {
          if ( i == (int *)v13 )
          {
            v32 = 1;
            goto LABEL_57;
          }
        }
      }
      --*(_WORD *)(v13 - 14);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v13);
      v64 = 0;
      if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
      {
        v64 = 0x10000 - *(__int16 *)(v13 - 14);
        *(_BYTE *)(v13 - 16) &= 0xFEu;
        *(_WORD *)(v13 - 14) = 0;
      }
      v65 = (unsigned int *)(v13 - 4);
      __dmb(0xBu);
      do
        v66 = __ldrex(v65);
      while ( __strex(v66 - 1, v65) );
      if ( (v66 & 2) != 0 && (v66 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v13 - 4));
      KeAbPostRelease(v13 - 4);
      if ( v64 > 0 )
      {
        __dmb(0xBu);
        v67 = (unsigned int *)(v13 - 12);
        do
        {
          v68 = __ldrex(v67);
          v69 = v68 - v64;
        }
        while ( __strex(v69, v67) );
        __dmb(0xBu);
        if ( v69 <= 0 )
        {
          if ( v69 )
            KeBugCheckEx(24, 0, v13, 40, v69);
          AlpcpDestroyBlob(v13);
        }
      }
      v13 = (int)a3;
      goto LABEL_120;
    }
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    *(_BYTE *)(v13 - 16) |= 1u;
    __dmb(0xBu);
    v29 = (unsigned int *)(v13 - 12);
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 + 0x10000;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( v31 <= 0 )
      KeBugCheckEx(24, 0, v13, 39, v31);
    if ( *(_DWORD *)(v13 + 12) == a1 )
    {
      v32 = 0;
LABEL_57:
      if ( *(_DWORD *)(v13 + 36) )
        goto LABEL_62;
      v33 = *(_DWORD *)(v13 + 20);
      if ( (v33 & 0x80) != 0 )
        goto LABEL_62;
      v34 = v33 | 0x80;
      v35 = *(_WORD *)(v13 + 124);
      *(_DWORD *)(v13 + 20) = v34;
      *(_WORD *)(v13 + 124) = v35 & 0xFF0C | 0xC;
      *(_WORD *)(v13 + 122) = 24;
      v36 = *(_DWORD *)(v13 + 16);
      *(_WORD *)(v13 + 120) = 0;
      if ( v36 )
      {
        __dmb(0xBu);
        v80 = (unsigned int *)(v36 + 976);
        do
          v81 = __ldrex(v80);
        while ( __strex(0, v80) );
        __dmb(0xBu);
        if ( v81 == v13 )
        {
          KeReleaseSemaphoreEx(*(_DWORD *)(v13 + 16) + 884, 1, 1, *(_DWORD *)(v13 + 16), 2);
          *(_DWORD *)(v13 + 16) = 0;
          v79 = *(_WORD *)(v13 - 14) - 3;
          goto LABEL_172;
        }
      }
      else if ( (v34 & 0x200) == 0 )
      {
        v37 = *(_DWORD *)(a5 + 4);
        *(_DWORD *)(v13 + 44) = a5;
        *(_DWORD *)(v13 + 48) = v37;
        **(_DWORD **)(a5 + 4) = v13 + 44;
        *(_DWORD *)(a5 + 4) = v13 + 44;
LABEL_62:
        AlpcpReleaseMessageAttributesOnCancel((_DWORD *)v13, v89);
        v38 = *(_DWORD *)(v13 + 12);
        v39 = *(_DWORD *)(v13 + 20) | 0x200;
        v40 = *(_WORD *)(v13 + 124);
        *(_DWORD *)(v13 + 20) = v39;
        *(_WORD *)(v13 + 124) = v40 & 0xDFFF;
        if ( v38 )
        {
          if ( (v39 & 0x1000) != 0 )
            ObfDereferenceObject(v38);
          *(_DWORD *)(v13 + 12) = 0;
        }
        v41 = *(_DWORD *)(v13 + 28);
        if ( v41 && (*(_DWORD *)(v13 + 20) & 0x400) == 0 && !*(_DWORD *)(v13 + 52) )
        {
          v82 = 400;
          if ( *(_DWORD *)(v13 + 108) )
            v82 = *(_DWORD *)(v13 + 112) + 400;
          *(_DWORD *)(v13 + 28) = PsTransferProcessQuotaToSharedQuota(*(_DWORD *)(v13 + 28), v82);
          ObfDereferenceObjectWithTag(v41);
          *(_DWORD *)(v13 + 20) |= 0x400u;
        }
        v42 = *(_DWORD *)(v13 + 104);
        if ( v42 )
        {
          v83 = *(_DWORD *)(v13 + 104) & 7;
          v84 = 1;
          if ( v83 == 5 )
          {
            v84 = 5;
            v83 = 0;
          }
          PspChargeJobWakeCounter(
            (_DWORD *)(v42 & 0xFFFFFFF8),
            0,
            v83,
            -1,
            0xFFFFFFFF,
            0xFFFFFFFF,
            v84,
            0,
            *(_DWORD *)(v13 + 136));
          ObDereferenceObjectDeferDeleteWithTag(v42 & 0xFFFFFFF8);
          *(_DWORD *)(v13 + 104) = 0;
        }
        if ( v32 )
          v13 = *a3;
        else
          v13 = *(_DWORD *)v13;
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v87);
        v43 = *(_BYTE *)(v20 + 8);
        v44 = 0;
        if ( (v43 & 1) != 0 )
        {
          v45 = *(__int16 *)(v20 + 10);
          *(_WORD *)(v20 + 10) = 0;
          v44 = 0x10000 - v45;
          *(_BYTE *)(v20 + 8) = v43 & 0xFE;
        }
        v46 = (unsigned int *)(v20 + 20);
        __dmb(0xBu);
        do
          v47 = __ldrex(v46);
        while ( __strex(v47 - 1, v46) );
        if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v20 + 20));
        KeAbPostRelease(v20 + 20);
        if ( v44 > 0 )
        {
          __dmb(0xBu);
          v48 = (unsigned int *)(v20 + 12);
          do
          {
            v49 = __ldrex(v48);
            v50 = v49 - v44;
          }
          while ( __strex(v50, v48) );
          __dmb(0xBu);
          if ( v50 <= 0 )
          {
            if ( v50 )
              KeBugCheckEx(24, 0, v87, 40, v50);
            AlpcpDestroyBlob(v87);
          }
        }
        goto LABEL_81;
      }
      v79 = *(_WORD *)(v13 - 14) - 1;
LABEL_172:
      *(_WORD *)(v13 - 14) = v79;
      goto LABEL_62;
    }
    --*(_WORD *)(v13 - 14);
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v13);
    v70 = 0;
    if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
    {
      v70 = 0x10000 - *(__int16 *)(v13 - 14);
      *(_BYTE *)(v13 - 16) &= 0xFEu;
      *(_WORD *)(v13 - 14) = 0;
    }
    v71 = (unsigned int *)(v13 - 4);
    __dmb(0xBu);
    do
      v72 = __ldrex(v71);
    while ( __strex(v72 - 1, v71) );
    if ( (v72 & 2) != 0 && (v72 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v13 - 4));
    KeAbPostRelease(v13 - 4);
    if ( v70 > 0 )
    {
      __dmb(0xBu);
      v73 = (unsigned int *)(v13 - 12);
      do
      {
        v74 = __ldrex(v73);
        v75 = v74 - v70;
      }
      while ( __strex(v75, v73) );
      __dmb(0xBu);
      if ( v75 <= 0 )
      {
        if ( v75 )
          KeBugCheckEx(24, 0, v13, 40, v75);
        AlpcpDestroyBlob(v13);
      }
    }
LABEL_120:
    v13 = *(_DWORD *)v13;
LABEL_81:
    v5 = a1;
  }
  while ( (int *)v13 != a3 );
  v8 = v88;
LABEL_12:
  if ( a4 <= 2 )
  {
    v14 = (unsigned int *)(a2 + 92);
    __dmb(0xBu);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 - 1, v14) );
  }
  else
  {
    if ( a4 == 3 )
      v14 = (unsigned int *)(a2 + 112);
    else
      v14 = (unsigned int *)(a2 + 124);
    __dmb(0xBu);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 - 1, v14) );
  }
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(v14);
  KeAbPostRelease((unsigned int)v14);
  return v8;
}
