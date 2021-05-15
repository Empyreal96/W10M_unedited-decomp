// sub_80711C 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_80711C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r3
  int *v14; // r8
  int *v15; // r7
  unsigned int v16; // r1
  int v17; // r6
  int v18; // r5
  int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r1
  unsigned int v24; // r1
  int v25; // r3
  unsigned __int8 *v26; // r6
  int v27; // r0
  int v28; // r8
  unsigned int v29; // r2
  __int64 v30; // r2
  unsigned int v31; // r1
  char v32; // r2
  int v33; // r3
  unsigned int *v34; // r6
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r4
  int v38; // r4
  _DWORD *v39; // r8
  int v40; // r5
  unsigned __int8 *v41; // r6
  int v42; // r0
  int v43; // r4
  unsigned int v44; // r2
  unsigned int *v45; // r2
  unsigned int v46; // r1
  int v47; // r1
  unsigned int *v48; // r5
  int **v49; // r7
  int v50; // r8
  _DWORD *v51; // r9
  int v52; // r10
  unsigned __int8 *v53; // r4
  int v54; // r0
  int v55; // r6
  unsigned int v56; // r2
  int v57; // r3
  unsigned int v58; // r1
  int v59; // r1
  unsigned int *v60; // r4
  int v61; // r0
  int v62; // r6
  unsigned int v63; // r2
  unsigned int v64; // r2
  unsigned int v65; // r2
  int v66; // r3
  unsigned __int8 *v67; // r6
  int v68; // r0
  int v69; // r8
  unsigned int v70; // r2
  int v71; // r8
  int v72; // r2
  __int64 v73; // r0
  unsigned int v74; // r1
  unsigned int v75; // r2
  int v76; // r3
  int *v77; // [sp-14h] [bp-14h]
  int v78; // [sp-14h] [bp-14h]
  _DWORD *v79; // [sp-14h] [bp-14h]
  _DWORD v80[3]; // [sp-Ch] [bp-Ch] BYREF

  v53 = (unsigned __int8 *)(v51 + 52);
  v54 = KeAbPreAcquire((unsigned int)(v51 + 52), 0, 0);
  v55 = v54;
  do
    v56 = __ldrex(v53);
  while ( __strex(v56 | 1, v53) );
  __dmb(0xBu);
  if ( (v56 & v52) != 0 )
    ExfAcquirePushLockExclusiveEx(v51 + 52, v54, (unsigned int)(v51 + 52));
  if ( v55 )
    *(_BYTE *)(v55 + 14) |= v52;
  if ( (v50 & v52) != 0 )
    v51[61] |= 0x80u;
  v57 = v51[61];
  if ( (v57 & 0x20) != 0 )
  {
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v53);
    while ( __strex(v20 - 1, (unsigned int *)v53) );
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock(v51 + 52);
    KeAbPostRelease((unsigned int)(v51 + 52));
    __dmb(0xBu);
    do
      v21 = __ldrex(v48);
    while ( __strex(v21 - 1, v48) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock(v48);
    KeAbPostRelease((unsigned int)v48);
  }
  else
  {
    v51[61] = v57 | 0x20;
    __dmb(0xBu);
    do
      v58 = __ldrex((unsigned int *)v53);
    while ( __strex(v58 - 1, (unsigned int *)v53) );
    if ( (v58 & 2) != 0 && (v58 & 4) == 0 )
      ExfTryToWakePushLock(v51 + 52);
    KeAbPostRelease((unsigned int)(v51 + 52));
    if ( (v51[61] & 6) == 2 )
      AlpcpWalkConnectionList((unsigned int)v51);
    v13 = (v51[61] >> 1) & 3;
    if ( v13 == 2 )
    {
      v14 = *v49;
      v15 = v51;
    }
    else if ( v13 == 1 )
    {
      v14 = 0;
      v15 = 0;
    }
    else
    {
      v14 = v49[2];
      v15 = *v49;
    }
    v77 = v15;
    if ( v14 && !ObReferenceObjectSafe((int)v14) )
      v14 = 0;
    if ( v15 && !ObReferenceObjectSafe((int)v15) )
    {
      v15 = 0;
      v77 = 0;
    }
    __dmb(0xBu);
    do
      v16 = __ldrex(v48);
    while ( __strex(v16 - 1, v48) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock(v48);
    KeAbPostRelease((unsigned int)v48);
    if ( v14 )
    {
      v80[1] = v80;
      v80[0] = v80;
      do
      {
        v17 = AlpcpCancelMessagesByRequestor((int)v51, (int)v14, v14 + 24, 1u, (int)v80);
        v18 = AlpcpCancelMessagesByRequestor((int)v51, (int)v14, v14 + 26, 2u, (int)v80);
        v19 = AlpcpCancelMessagesByRequestor((int)v51, (int)v14, v14 + 29, 3u, (int)v80);
      }
      while ( AlpcpCancelMessagesByRequestor((int)v51, (int)v14, v14 + 32, 4u, (int)v80) | v19 | v18 | v17 );
      ObfDereferenceObject((int)v14);
      v15 = v77;
      while ( 1 )
      {
        v59 = v80[0];
        if ( (_DWORD *)v80[0] == v80 )
          break;
        v39 = (_DWORD *)(v80[0] - 44);
        v40 = v80[0] - 68;
        v80[0] = *(_DWORD *)v80[0];
        *(_DWORD *)(v80[0] + 4) = v80;
        v41 = (unsigned __int8 *)(v59 - 48);
        v79 = v39;
        v42 = KeAbPreAcquire(v59 - 48, 0, 0);
        v43 = v42;
        do
          v44 = __ldrex(v41);
        while ( __strex(v44 | 1, v41) );
        __dmb(0xBu);
        if ( (v44 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v41, v42, (unsigned int)v41);
        if ( v43 )
          *(_BYTE *)(v43 + 14) |= 1u;
        *(_BYTE *)(v40 + 8) |= 1u;
        __dmb(0xBu);
        v45 = (unsigned int *)(v40 + 12);
        do
        {
          v46 = __ldrex(v45);
          v47 = v46 + 0x10000;
        }
        while ( __strex(v47, v45) );
        __dmb(0xBu);
        if ( v47 <= 0 )
          KeBugCheckEx(24, 0, (int)v39, 38, v47);
        if ( !v15 )
        {
          --*(_WORD *)(v40 + 10);
          goto LABEL_125;
        }
        v60 = (unsigned int *)(v15 + 52);
        v61 = KeAbPreAcquire((unsigned int)(v15 + 52), 0, 0);
        v62 = v61;
        do
          v63 = __ldrex(v60);
        while ( !v63 && __strex(0x11u, v60) );
        __dmb(0xBu);
        if ( v63 )
          ExfAcquirePushLockSharedEx(v15 + 52, v61, (unsigned int)(v15 + 52));
        if ( v62 )
          *(_BYTE *)(v62 + 14) |= 1u;
        if ( (v15[61] & 0x40) != 0 )
        {
          --*(_WORD *)(v40 + 10);
          __dmb(0xBu);
          do
            v64 = __ldrex(v60);
          while ( v64 == 17 && __strex(0, v60) );
        }
        else
        {
          __dmb(0xBu);
          v22 = v51 + 58;
          do
          {
            v23 = __ldrex(v22);
            v24 = v23 + 1;
          }
          while ( __strex(v24, v22) );
          __dmb(0xBu);
          v39[10] = v24;
          v25 = v51[7];
          v26 = (unsigned __int8 *)(v15 + 23);
          v39[8] = v51;
          v39[9] = v15;
          v39[17] = v25;
          v27 = KeAbPreAcquire((unsigned int)(v15 + 23), 0, 0);
          v28 = v27;
          do
            v29 = __ldrex(v26);
          while ( __strex(v29 | 1, v26) );
          __dmb(0xBu);
          if ( (v29 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v15 + 23, v27, (unsigned int)(v15 + 23));
          if ( v28 )
            *(_BYTE *)(v28 + 14) |= 1u;
          v39 = v79;
          LODWORD(v30) = v15 + 56;
          HIDWORD(v30) = v15[57];
          *(_QWORD *)(v79 + 11) = v30;
          *(_DWORD *)v15[57] = v79 + 11;
          v15[57] = (int)(v79 + 11);
          ++v15[69];
          __dmb(0xBu);
          do
            v31 = __ldrex((unsigned int *)v26);
          while ( __strex(v31 - 1, (unsigned int *)v26) );
          if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v15 + 23);
          KeAbPostRelease((unsigned int)(v15 + 23));
          if ( v15[4] )
          {
            AlpcpQueueIoCompletionPort(v15, 0, 1);
            goto LABEL_125;
          }
          if ( (v15[61] & 0x200) != 0 )
          {
            __dmb(0xBu);
            do
              v65 = __ldrex(v60);
            while ( v65 == 17 && __strex(0, v60) );
            if ( v65 != 17 )
              ExfReleasePushLockShared(v15 + 52);
            KeAbPostRelease((unsigned int)(v15 + 52));
            KeReleaseSemaphoreEx(v15[37], 1, 1, v66, 0);
            goto LABEL_125;
          }
          if ( (int *)v15[35] != v15 + 35 )
          {
            v67 = (unsigned __int8 *)(v15 + 34);
            v68 = KeAbPreAcquire((unsigned int)(v15 + 34), 0, 0);
            v69 = v68;
            do
              v70 = __ldrex(v67);
            while ( __strex(v70 | 1, v67) );
            __dmb(0xBu);
            if ( (v70 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v15 + 34, v68, (unsigned int)(v15 + 34));
            if ( v69 )
              *(_BYTE *)(v69 + 14) |= 1u;
            if ( (int *)v15[35] == v15 + 35 )
            {
              v71 = 0;
            }
            else
            {
              v71 = v15[35] - 988;
              v72 = v15[35];
              *(_DWORD *)(v72 - 8) = 0;
              v73 = *(_QWORD *)v72;
              if ( *(_DWORD *)(*(_DWORD *)v72 + 4) != v72 || *(_DWORD *)HIDWORD(v73) != v72 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v73) = v73;
              *(_DWORD *)(v73 + 4) = HIDWORD(v73);
              *(_DWORD *)(v71 + 988) = 0;
            }
            __dmb(0xBu);
            do
              v74 = __ldrex((unsigned int *)v67);
            while ( __strex(v74 - 1, (unsigned int *)v67) );
            if ( (v74 & 2) != 0 && (v74 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)v15 + 34);
            KeAbPostRelease((unsigned int)(v15 + 34));
            if ( v71 )
            {
              __dmb(0xBu);
              do
                v75 = __ldrex(v60);
              while ( v75 == 17 && __strex(0, v60) );
              if ( v75 != 17 )
                ExfReleasePushLockShared(v15 + 52);
              KeAbPostRelease((unsigned int)(v15 + 52));
              KeReleaseSemaphoreEx(v71 + 884, 1, 1, v76, 2);
              v39 = v79;
              goto LABEL_125;
            }
            v39 = v79;
          }
          __dmb(0xBu);
          do
            v64 = __ldrex(v60);
          while ( v64 == 17 && __strex(0, v60) );
        }
        if ( v64 != 17 )
          ExfReleasePushLockShared(v15 + 52);
        KeAbPostRelease((unsigned int)(v15 + 52));
LABEL_125:
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v39);
        v32 = *(_BYTE *)(v40 + 8);
        v78 = 0;
        if ( (v32 & 1) != 0 )
        {
          v33 = *(__int16 *)(v40 + 10);
          *(_WORD *)(v40 + 10) = 0;
          v78 = 0x10000 - v33;
          *(_BYTE *)(v40 + 8) = v32 & 0xFE;
        }
        v34 = (unsigned int *)(v40 + 20);
        __dmb(0xBu);
        do
          v35 = __ldrex(v34);
        while ( __strex(v35 - 1, v34) );
        if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v40 + 20));
        KeAbPostRelease(v40 + 20);
        if ( v78 > 0 )
        {
          __dmb(0xBu);
          v36 = (unsigned int *)(v40 + 12);
          do
          {
            v37 = __ldrex(v36);
            v38 = v37 - v78;
          }
          while ( __strex(v38, v36) );
          __dmb(0xBu);
          if ( v38 <= 0 )
          {
            if ( v38 )
              KeBugCheckEx(24, 0, (int)v39, 40, v38);
            AlpcpDestroyBlob((int)v39);
          }
        }
      }
    }
    if ( v15 )
      ObfDereferenceObject((int)v15);
  }
  __asm { POP.W           {R4-R11,PC} }
}
