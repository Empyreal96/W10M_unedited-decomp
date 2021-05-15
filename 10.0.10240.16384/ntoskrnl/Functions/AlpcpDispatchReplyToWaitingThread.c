// AlpcpDispatchReplyToWaitingThread 
 
int __fastcall AlpcpDispatchReplyToWaitingThread(__int64 *a1)
{
  __int64 v2; // kr00_8
  int v3; // r9
  __int64 v4; // kr08_8
  unsigned int v6; // r3
  int v7; // r8
  unsigned __int8 *v8; // r9
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r1
  unsigned int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r1
  unsigned int v19; // r3
  int v20; // r2
  int v21; // r3
  char v22; // r2
  int v23; // r6
  int v24; // r3
  unsigned int *v25; // r8
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // r0
  unsigned int *v30; // r8
  int v31; // r0
  int v32; // r6
  unsigned int v33; // r2
  int v34; // r3
  int v35; // r3
  unsigned int v36; // r2
  int v37; // r3
  unsigned __int8 *v38; // r8
  int v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r1
  unsigned int v42; // lr
  __int16 v43; // r1
  int v44; // r3
  __int16 v45; // r3
  unsigned int *v46; // r2
  unsigned int v47; // r1
  char v48; // r2
  int v49; // r6
  int v50; // r3
  unsigned int *v51; // r5
  unsigned int v52; // r1
  unsigned int *v53; // r2
  unsigned int v54; // r0
  int v55; // r0
  int v56; // [sp+8h] [bp-38h]
  int v57; // [sp+Ch] [bp-34h]
  char v58; // [sp+10h] [bp-30h]
  int v59; // [sp+14h] [bp-2Ch]
  int v60; // [sp+14h] [bp-2Ch]
  int v61; // [sp+18h] [bp-28h]
  int v62; // [sp+1Ch] [bp-24h]

  v2 = *a1;
  v3 = *((_DWORD *)a1 + 6);
  *((_DWORD *)a1 + 3) = 0;
  *((_DWORD *)a1 + 4) = 0;
  *((_DWORD *)a1 + 5) = 0;
  v4 = *(_QWORD *)(HIDWORD(v2) + 12);
  v58 = v3;
  v56 = *(_DWORD *)(HIDWORD(v2) + 16);
  v62 = (*(_DWORD *)(HIDWORD(v2) + 20) >> 12) & 1;
  v59 = (*(_DWORD *)(v4 + 244) >> 1) & 3;
  if ( (unsigned int)*((unsigned __int16 *)a1 + 14) <= *(_DWORD *)(v4 + 168) )
  {
    *(_DWORD *)(HIDWORD(v2) + 12) = 0;
    *(_DWORD *)(HIDWORD(v2) + 100) = 0;
    if ( *((_WORD *)a1 + 15) == 11 )
    {
      v38 = (unsigned __int8 *)(v4 + 208);
      v39 = KeAbPreAcquire(v4 + 208, 0, 0);
      v57 = v39;
      do
        v40 = __ldrex(v38);
      while ( __strex(v40 | 1, v38) );
      __dmb(0xBu);
      if ( (v40 & 1) != 0 )
      {
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v4 + 208), v39, v4 + 208);
        v39 = v57;
      }
      if ( v39 )
        *(_BYTE *)(v39 + 14) |= 1u;
      *(_DWORD *)(v4 + 244) &= 0xFFFFFFF7;
      __dmb(0xBu);
      do
        v41 = __ldrex((unsigned int *)v38);
      while ( __strex(v41 - 1, (unsigned int *)v38) );
      if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v4 + 208));
      KeAbPostRelease(v4 + 208);
    }
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_WORD *)(HIDWORD(v2) + 122) = *((_WORD *)a1 + 14);
    *(_WORD *)(HIDWORD(v2) + 120) = *((_WORD *)a1 + 14) - 24;
    v43 = *((_WORD *)a1 + 15);
    *(_WORD *)(HIDWORD(v2) + 124) = v43;
    *(_WORD *)(HIDWORD(v2) + 126) = *((_WORD *)a1 + 16);
    *(_QWORD *)(HIDWORD(v2) + 128) = *(_QWORD *)(v42 + 876);
    v44 = *(_DWORD *)(HIDWORD(v2) + 20);
    if ( (v3 & 0x10000) != 0 )
    {
      *(_DWORD *)(HIDWORD(v2) + 20) = v44 | 0x200;
      v45 = v43 & 0xDFFF;
    }
    else
    {
      *(_DWORD *)(HIDWORD(v2) + 20) = v44 & 0xFFFFFDFF;
      v45 = v43 | 0x2000;
    }
    *(_WORD *)(HIDWORD(v2) + 124) = v45;
    if ( (*(_DWORD *)(v2 + 244) & 0x2000) != 0 && (v37 = *(_DWORD *)(HIDWORD(v2) + 20), (v37 & 0x200) != 0) )
    {
      v6 = v37 & 0xFFFFEFFF;
    }
    else
    {
      ObfReferenceObject(v2);
      v6 = *(_DWORD *)(HIDWORD(v2) + 20) | 0x1000;
    }
    *(_DWORD *)(HIDWORD(v2) + 20) = v6;
    v61 = v3 & 0x20000;
    *(_DWORD *)(HIDWORD(v2) + 12) = v2;
    if ( (v3 & 0x20000) != 0 )
    {
      __dmb(0xBu);
      v46 = (unsigned int *)(v42 + 976);
      do
        v47 = __ldrex(v46);
      while ( __strex(HIDWORD(v2), v46) );
      __dmb(0xBu);
      *(_DWORD *)(HIDWORD(v2) + 20) |= 0x800u;
      ++*(_WORD *)(HIDWORD(v2) - 14);
    }
    v7 = *(_DWORD *)(HIDWORD(v2) + 8);
    *(_DWORD *)(HIDWORD(v2) + 20) |= 0x100u;
    if ( v7 )
    {
      v8 = (unsigned __int8 *)(v7 + 112);
      v9 = KeAbPreAcquire(v7 + 112, 0, 0);
      v10 = v9;
      do
        v11 = __ldrex(v8);
      while ( __strex(v11 | 1, v8) );
      __dmb(0xBu);
      if ( (v11 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v7 + 112), v9, v7 + 112);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      --*(_DWORD *)(v7 + 268);
      v12 = *(_DWORD *)(HIDWORD(v2) + 20);
      *(_DWORD *)(HIDWORD(v2) + 8) = 0;
      *(_DWORD *)(HIDWORD(v2) + 20) = v12 & 0xFFFFFFF8;
      **(_DWORD **)(HIDWORD(v2) + 4) = *(_DWORD *)HIDWORD(v2);
      *(_DWORD *)(*(_DWORD *)HIDWORD(v2) + 4) = *(_DWORD *)(HIDWORD(v2) + 4);
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v8);
      while ( __strex(v13 - 1, (unsigned int *)v8) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v7 + 112));
      KeAbPostRelease(v7 + 112);
      LOBYTE(v3) = v58;
      --*(_WORD *)(HIDWORD(v2) - 14);
    }
    __dmb(0xBu);
    v14 = (unsigned int *)(v4 + 232);
    do
    {
      v15 = __ldrex(v14);
      v16 = v15 + 1;
    }
    while ( __strex(v16, v14) );
    __dmb(0xBu);
    v17 = *(_DWORD *)(HIDWORD(v2) + 20);
    *(_DWORD *)(HIDWORD(v2) + 24) = v16;
    v18 = v17;
    v19 = v17 ^ ((unsigned __int8)v17 ^ (unsigned __int8)(8 * v59)) & 0x78;
    v20 = (v19 >> 3) & 0xF;
    *(_DWORD *)(HIDWORD(v2) + 20) = v19;
    if ( v20 == 2 || v20 != 1 )
    {
      *(_DWORD *)(HIDWORD(v2) + 64) = *(_DWORD *)(v4 + 28);
    }
    else
    {
      v30 = (unsigned int *)(*(_DWORD *)(v4 + 8) - 4);
      v60 = *(_DWORD *)(v4 + 8);
      v31 = KeAbPreAcquire((unsigned int)v30, 0, 0);
      v32 = v31;
      do
        v33 = __ldrex(v30);
      while ( !v33 && __strex(0x11u, v30) );
      __dmb(0xBu);
      if ( v33 )
        ExfAcquirePushLockSharedEx(v30, v31, (unsigned int)v30);
      if ( v32 )
        *(_BYTE *)(v32 + 14) |= 1u;
      v34 = *(_DWORD *)(v60 + 4);
      if ( v34 )
        v35 = *(_DWORD *)(v34 + 28);
      else
        v35 = 0;
      *(_DWORD *)(HIDWORD(v2) + 64) = v35;
      __dmb(0xBu);
      do
        v36 = __ldrex(v30);
      while ( v36 == 17 && __strex(0, v30) );
      if ( v36 != 17 )
        ExfReleasePushLockShared(v30);
      KeAbPostRelease((unsigned int)v30);
    }
    if ( *(_DWORD *)(HIDWORD(v2) + 88) )
    {
      AlpcpCaptureMessageDataSafe(HIDWORD(v2), v18);
      *(_DWORD *)(HIDWORD(v2) + 88) = 0;
    }
    v21 = (unsigned __int8)AlpcpLogEnabled;
    if ( AlpcpLogEnabled )
    {
      AlpcpLogSendMessage(HIDWORD(v2), 0);
      v21 = (unsigned __int8)AlpcpLogEnabled;
    }
    if ( v61 )
    {
      *(_DWORD *)(HIDWORD(v2) + 16) = v42;
      *((_DWORD *)a1 + 3) = v56;
      if ( v21 )
        AlpcpLogWaitForReply(HIDWORD(v2));
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
      v48 = *(_BYTE *)(HIDWORD(v2) - 16);
      v49 = 0;
      if ( (v48 & 1) != 0 )
      {
        v50 = *(__int16 *)(HIDWORD(v2) - 14);
        *(_WORD *)(HIDWORD(v2) - 14) = 0;
        v49 = 0x10000 - v50;
        *(_BYTE *)(HIDWORD(v2) - 16) = v48 & 0xFE;
      }
      v51 = (unsigned int *)(HIDWORD(v2) - 4);
      __dmb(0xBu);
      do
        v52 = __ldrex(v51);
      while ( __strex(v52 - 1, v51) );
      if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
      KeAbPostRelease(HIDWORD(v2) - 4);
      if ( (int)v2 > 0 )
      {
        __dmb(0xBu);
        v53 = (unsigned int *)(HIDWORD(v2) - 12);
        do
        {
          v54 = __ldrex(v53);
          v55 = v54 - v49;
        }
        while ( __strex(v55, v53) );
        __dmb(0xBu);
        if ( v55 <= 0 )
        {
          if ( v55 )
            KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v55);
          AlpcpDestroyBlob(HIDWORD(v2));
        }
      }
    }
    else
    {
      *(_DWORD *)(HIDWORD(v2) + 16) = 0;
      --*(_WORD *)(HIDWORD(v2) - 14);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
      v22 = *(_BYTE *)(HIDWORD(v2) - 16);
      v23 = 0;
      if ( (v22 & 1) != 0 )
      {
        v24 = *(__int16 *)(HIDWORD(v2) - 14);
        *(_WORD *)(HIDWORD(v2) - 14) = 0;
        v23 = 0x10000 - v24;
        *(_BYTE *)(HIDWORD(v2) - 16) = v22 & 0xFE;
      }
      v25 = (unsigned int *)(HIDWORD(v2) - 4);
      __dmb(0xBu);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - 1, v25) );
      if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
      KeAbPostRelease(HIDWORD(v2) - 4);
      if ( (int)v2 > 0 )
      {
        __dmb(0xBu);
        v27 = (unsigned int *)(HIDWORD(v2) - 12);
        do
        {
          v28 = __ldrex(v27);
          v29 = v28 - v23;
        }
        while ( __strex(v29, v27) );
        __dmb(0xBu);
        if ( v29 <= 0 )
        {
          if ( v29 )
            KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v29);
          AlpcpDestroyBlob(HIDWORD(v2));
        }
      }
      if ( (v3 & 4) != 0 )
        *((_DWORD *)a1 + 3) = v56;
      else
        KeReleaseSemaphoreEx(v56 + 884, 1, 1, 2, 2);
    }
    if ( v62 )
      ObfDereferenceObject(v4);
    JUMPOUT(0x7238B8);
  }
  return sub_7BE108();
}
