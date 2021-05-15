// CcAsyncReadWorker 
 
_DWORD *__fastcall CcAsyncReadWorker(_DWORD *result)
{
  unsigned int v1; // r10
  int v2; // r1
  int v3; // r5
  _DWORD *v4; // r3
  int *v5; // r3
  unsigned int v6; // r7
  int v7; // r9
  int v8; // r0
  unsigned int v9; // r5
  int *v10; // r7
  int v11; // r4
  int v12; // r0
  _DWORD *v13; // r9
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r0
  int *v17; // r1
  int *v18; // r2
  int v19; // t1
  int *v20; // r2
  _DWORD *v21; // r1
  int v22; // t1
  unsigned int *v23; // r1
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r4
  unsigned int v27; // r2
  _DWORD *v28; // r0
  int v29; // r0
  int v30; // r4
  int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r2
  int v34; // r1
  _DWORD *v35; // r0
  unsigned int *v36; // r1
  unsigned int v37; // r2
  int v38; // r0
  unsigned int v39; // r2
  _DWORD *v40; // r4
  int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r2
  unsigned int v44; // r3
  int v45; // r6
  unsigned int v46; // r2
  unsigned int v47; // r2
  int v48; // r2
  unsigned int v49; // r3
  unsigned int v50; // r3
  int v51; // r5
  int v52; // r1
  unsigned int v53; // r0
  unsigned int v54; // r2
  int v55; // r0
  int v56; // r4
  unsigned int v57; // r2
  int v58; // [sp+8h] [bp-240h]
  unsigned int v59; // [sp+Ch] [bp-23Ch]
  int v60; // [sp+10h] [bp-238h]
  _DWORD *v61; // [sp+14h] [bp-234h] BYREF
  _DWORD *v62; // [sp+18h] [bp-230h]
  int v63; // [sp+1Ch] [bp-22Ch]
  unsigned int *v64; // [sp+20h] [bp-228h]
  unsigned int *v65; // [sp+24h] [bp-224h]
  _DWORD v66[64]; // [sp+28h] [bp-220h] BYREF
  _DWORD v67[64]; // [sp+128h] [bp-120h] BYREF
  int v68; // [sp+228h] [bp-20h] BYREF

  v61 = 0;
  v62 = 0;
  v1 = 0;
  if ( result )
  {
    v2 = result[6];
    v3 = result[5];
    v4 = v66;
    v60 = v2;
    v58 = v3;
    do
      *v4++ = 0;
    while ( v4 != v67 );
    v5 = v67;
    do
      *v5++ = 0;
    while ( v5 != &v68 );
    v6 = CcNewAsyncReadRequestEvent + 16 * v3;
    v59 = v6;
    v7 = CcReaderThreadsStats + 404 * v3;
    v63 = v7;
    if ( (unsigned int)CcMaxAsyncReadItemsPerThread >= 0x40 )
      return (_DWORD *)sub_551844(0);
    v64 = (unsigned int *)(v7 + 4 * v2);
    v65 = v64;
    result = v66;
    while ( 1 )
    {
      if ( v1 >= CcMaxAsyncReadItemsPerThread
        || *(_DWORD *)(CcAsyncReadWorkQueue + 8 * v3) == CcAsyncReadWorkQueue + 8 * v3 )
      {
        if ( !v1 )
        {
          KeWaitForSingleObject(v6, 0, 0, 0, 0);
          goto LABEL_35;
        }
        v8 = MmWaitMultipleForCacheManagerPrefetch((int)v67, v1, v6);
        v2 = v60;
        v9 = v8;
        result = v66;
      }
      else
      {
        v9 = v1 + 1;
      }
      if ( v9 >= v1 || !v1 )
        break;
      v10 = &v66[v9];
      v11 = *v10;
      if ( *v10 )
      {
        v12 = *(_DWORD *)(v11 + 32);
        if ( !v12 )
        {
          v3 = v58;
          v6 = v59;
          goto LABEL_73;
        }
        ExFreePoolWithTag(v12, 1933665091);
        v13 = &v67[v9];
        *v13 = 0;
        *v10 = 0;
        *(_DWORD *)(v11 + 32) = 0;
        v14 = *(_DWORD *)(v11 + 8);
        *(_BYTE *)(v11 + 64) = 6;
        v15 = *(_DWORD *)(v14 + 368);
        if ( v15 == 1 && (v15 = *(_DWORD *)(v11 + 28), v15 <= 0x20000) )
        {
          CcCompleteAsyncRead((_DWORD *)v11);
          v44 = (unsigned int)KeGetPcr();
          v45 = *(_DWORD *)((v44 & 0xFFFFF000) + 0xB30);
          v46 = *(unsigned __int16 *)(v45 + 8);
          ++*(_DWORD *)(v45 + 20);
          if ( *(unsigned __int16 *)(v45 + 4) < v46
            || (++*(_DWORD *)(v45 + 24),
                v45 = *(_DWORD *)((v44 & 0xFFFFF000) + 0xB34),
                v47 = *(unsigned __int16 *)(v45 + 8),
                ++*(_DWORD *)(v45 + 20),
                *(unsigned __int16 *)(v45 + 4) < v47) )
          {
            RtlpInterlockedPushEntrySList((unsigned __int64 *)v45, (_DWORD *)v11);
          }
          else
          {
            ++*(_DWORD *)(v45 + 24);
            (*(void (__fastcall **)(int))(v45 + 44))(v11);
          }
        }
        else
        {
          CcPostWorkQueueAsyncRead(v11, 0, 6, v15);
        }
        if ( v9 < --v1 )
        {
          v16 = 4 * (v1 - v9);
          v17 = &v66[v9 + 1];
          if ( v16 >> 2 )
          {
            v18 = &v10[v16 >> 2];
            do
            {
              v19 = *v17++;
              *v10++ = v19;
            }
            while ( v10 != v18 );
          }
          v20 = &v67[v9 + 1];
          if ( v16 >> 2 )
          {
            v21 = &v13[v16 >> 2];
            do
            {
              v22 = *v20++;
              *v13++ = v22;
            }
            while ( v13 != v21 );
          }
          v9 = v1;
        }
        v67[v9] = 0;
        v66[v9] = 0;
        __dmb(0xBu);
        v23 = v64;
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 - 1, v23) );
        __dmb(0xBu);
        v3 = v58;
        v6 = v59;
        v2 = v60;
        v7 = v63;
        if ( !v59 )
        {
          v6 = CcNewAsyncReadRequestEvent + 16 * v58;
          v59 = v6;
        }
        result = v66;
      }
      else
      {
        v3 = v58;
        v6 = v59;
      }
LABEL_32:
      if ( v2 && !v1 )
        return result;
    }
    v3 = v58;
LABEL_35:
    v25 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
    v26 = v25;
    do
      v27 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
    while ( __strex(v27 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
    __dmb(0xBu);
    if ( (v27 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v25, (unsigned int)&CcAsyncReadWorkQueueLock);
    if ( v26 )
    {
LABEL_40:
      *(_BYTE *)(v26 + 14) |= 1u;
      goto LABEL_41;
    }
    while ( 1 )
    {
LABEL_41:
      v28 = (_DWORD *)(CcAsyncReadWorkQueue + 8 * v3);
      if ( (_DWORD *)*v28 == v28 )
      {
        v40 = v62;
        goto LABEL_63;
      }
      if ( v1 >= CcMaxAsyncReadItemsPerThread )
      {
        __pld(&CcAsyncReadWorkQueueLock);
        v52 = CcAsyncReadWorkQueueLock;
        v53 = CcAsyncReadWorkQueueLock - 16;
        if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) <= 0x10 )
          v53 = 0;
        if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
          goto LABEL_99;
        __dmb(0xBu);
        do
          v54 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
        while ( v54 == v52 && __strex(v53, (unsigned int *)&CcAsyncReadWorkQueueLock) );
        if ( v54 != v52 )
LABEL_99:
          ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v52);
        KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
        CcShouldSpinAsyncReadWorkerThread((int)&v61, v3);
        v55 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
        v56 = v55;
        do
          v57 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
        while ( __strex(v57 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
        __dmb(0xBu);
        if ( (v57 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v55, (unsigned int)&CcAsyncReadWorkQueueLock);
        if ( v56 )
          *(_BYTE *)(v56 + 14) |= 1u;
        v40 = v61;
        v62 = v61;
LABEL_63:
        __pld(&CcAsyncReadWorkQueueLock);
        v41 = CcAsyncReadWorkQueueLock;
        if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) > 0x10 )
          v42 = CcAsyncReadWorkQueueLock - 16;
        else
          v42 = 0;
        if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
          goto LABEL_81;
        __dmb(0xBu);
        do
          v43 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
        while ( v43 == v41 && __strex(v42, (unsigned int *)&CcAsyncReadWorkQueueLock) );
        if ( v43 != v41 )
LABEL_81:
          ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v41);
        KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
        if ( v40 )
        {
          *(_DWORD *)(v7 + 4 * v40[6]) = 0;
          *v40 = 0;
          ExQueueWorkItem(v40, 0);
          v61 = 0;
          v62 = 0;
        }
        v2 = v60;
LABEL_73:
        result = v66;
        goto LABEL_32;
      }
      v29 = CcFindNextWorkQueueEntry(v28);
      __pld(&CcAsyncReadWorkQueueLock);
      v30 = v29;
      v31 = CcAsyncReadWorkQueueLock;
      if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) > 0x10 )
        v32 = CcAsyncReadWorkQueueLock - 16;
      else
        v32 = 0;
      if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
        goto LABEL_83;
      __dmb(0xBu);
      do
        v33 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
      while ( v33 == v31 && __strex(v32, (unsigned int *)&CcAsyncReadWorkQueueLock) );
      if ( v33 != v31 )
LABEL_83:
        ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v31);
      KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
      if ( !CcAsyncReadPrefetch(v30, v34) )
        goto LABEL_86;
      v35 = *(_DWORD **)(v30 + 32);
      if ( *v35 )
      {
        v67[v1] = *v35;
        v66[v1++] = v30;
        __dmb(0xBu);
        v36 = v65;
        do
          v37 = __ldrex(v36);
        while ( __strex(v37 + 1, v36) );
        __dmb(0xBu);
        if ( v1 >= CcMaxAsyncReadItemsPerThread )
        {
          v6 = 0;
          v59 = 0;
        }
        goto LABEL_56;
      }
      ExFreePoolWithTag(v35, 1933665091);
      *(_BYTE *)(v30 + 64) = 6;
      *(_DWORD *)(v30 + 32) = 0;
      v49 = *(_DWORD *)(*(_DWORD *)(v30 + 8) + 368);
      if ( v49 != 1 || (v49 = *(_DWORD *)(v30 + 28), v49 > 0x20000) )
      {
        CcPostWorkQueueAsyncRead(v30, 0, v48, v49);
      }
      else
      {
LABEL_86:
        CcCompleteAsyncRead((_DWORD *)v30);
        v50 = (unsigned int)KeGetPcr();
        v51 = *(_DWORD *)((v50 & 0xFFFFF000) + 0xB30);
        ++*(_DWORD *)(v51 + 20);
        if ( *(unsigned __int16 *)(v51 + 4) < (unsigned int)*(unsigned __int16 *)(v51 + 8)
          || (++*(_DWORD *)(v51 + 24),
              v51 = *(_DWORD *)((v50 & 0xFFFFF000) + 0xB34),
              ++*(_DWORD *)(v51 + 20),
              *(unsigned __int16 *)(v51 + 4) < (unsigned int)*(unsigned __int16 *)(v51 + 8)) )
        {
          RtlpInterlockedPushEntrySList((unsigned __int64 *)v51, (_DWORD *)v30);
        }
        else
        {
          ++*(_DWORD *)(v51 + 24);
          (*(void (__fastcall **)(int))(v51 + 44))(v30);
        }
        v3 = v58;
      }
LABEL_56:
      v38 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
      v26 = v38;
      do
        v39 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
      while ( __strex(v39 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
      __dmb(0xBu);
      if ( (v39 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v38, (unsigned int)&CcAsyncReadWorkQueueLock);
      if ( v26 )
        goto LABEL_40;
    }
  }
  return result;
}
