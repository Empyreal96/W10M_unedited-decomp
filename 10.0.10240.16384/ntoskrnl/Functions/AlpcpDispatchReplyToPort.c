// AlpcpDispatchReplyToPort 
 
int __fastcall AlpcpDispatchReplyToPort(__int64 *a1)
{
  __int64 v2; // kr00_8
  int v3; // r3
  int v4; // r8
  int v5; // r0
  int v7; // r9
  int v8; // r10
  int v9; // r6
  int v10; // r3
  __int16 v11; // r2
  __int16 v12; // r0
  int v13; // r3
  __int16 v14; // r3
  int v15; // r0
  unsigned int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r1
  int v20; // r8
  unsigned __int8 *v21; // r7
  int v22; // r0
  int v23; // r6
  unsigned int v24; // r2
  int v25; // r1
  unsigned int v26; // r0
  unsigned int *v27; // r5
  unsigned int v28; // r2
  char v29; // r2
  int v30; // r6
  int v31; // r3
  unsigned int *v32; // r5
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r0
  int v36; // r0
  unsigned int *v37; // r5
  unsigned int v38; // r2
  unsigned __int8 *v39; // r6
  int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r1
  int v43; // r3
  unsigned int *v44; // r7
  int v45; // r0
  int v46; // r6
  unsigned int v47; // r2
  __int64 v48; // r2
  unsigned int *v49; // r2
  unsigned int v50; // r1
  int v51; // [sp+8h] [bp-30h]
  int v52; // [sp+Ch] [bp-2Ch]
  int v53; // [sp+10h] [bp-28h] BYREF
  int v54[7]; // [sp+14h] [bp-24h] BYREF
  int v55; // [sp+30h] [bp-8h]

  v2 = *a1;
  v3 = *((_DWORD *)a1 + 6);
  *((_DWORD *)a1 + 3) = 0;
  *((_DWORD *)a1 + 4) = 0;
  *((_DWORD *)a1 + 5) = 0;
  v4 = *(_DWORD *)(HIDWORD(v2) + 12);
  v51 = v3;
  v5 = AlpcpLockCommunicationInfoForReply(v4, v2, &v53, v54);
  v52 = v5;
  if ( (*(_DWORD *)(v2 + 244) & 0x20) != 0 )
    return sub_7BDE9C();
  if ( (*(_DWORD *)(v4 + 244) & 0x20) != 0 )
    JUMPOUT(0x7BDEA8);
  v7 = v53;
  if ( (unsigned int)*((unsigned __int16 *)a1 + 14) > *(_DWORD *)(v53 + 168) )
  {
    v27 = (unsigned int *)(v5 - 4);
    __dmb(0xBu);
    do
      v28 = __ldrex(v27);
    while ( v28 == 17 && __strex(0, v27) );
    if ( v28 != 17 )
      ExfReleasePushLockShared(v27);
    KeAbPostRelease((unsigned int)v27);
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
    v29 = *(_BYTE *)(HIDWORD(v2) - 16);
    v30 = 0;
    if ( (v29 & 1) != 0 )
    {
      v31 = *(__int16 *)(HIDWORD(v2) - 14);
      *(_WORD *)(HIDWORD(v2) - 14) = 0;
      v30 = 0x10000 - v31;
      *(_BYTE *)(HIDWORD(v2) - 16) = v29 & 0xFE;
    }
    v32 = (unsigned int *)(HIDWORD(v2) - 4);
    __dmb(0xBu);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 - 1, v32) );
    if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
    KeAbPostRelease(HIDWORD(v2) - 4);
    if ( v30 > 0 )
    {
      __dmb(0xBu);
      v34 = (unsigned int *)(HIDWORD(v2) - 12);
      do
      {
        v35 = __ldrex(v34);
        v36 = v35 - v30;
      }
      while ( __strex(v36, v34) );
      __dmb(0xBu);
      if ( v36 <= 0 )
      {
        if ( v36 )
          KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v36);
        AlpcpDestroyBlob(HIDWORD(v2));
      }
    }
    v9 = -1073741789;
  }
  else
  {
    v8 = v54[0];
    v9 = AlpcpReferenceReplyTargetPorts(v53, v54[0]);
    if ( v9 < 0 )
    {
      v37 = (unsigned int *)(v54[5] - 4);
      __dmb(0xBu);
      do
        v38 = __ldrex(v37);
      while ( v38 == 17 && __strex(0, v37) );
      if ( v38 != 17 )
        ExfReleasePushLockShared(v37);
      KeAbPostRelease((unsigned int)v37);
      AlpcpCancelMessage((_DWORD *)v2, SHIDWORD(v2), 0x10000);
    }
    else
    {
      *(_DWORD *)(HIDWORD(v2) + 100) = 0;
      if ( *((_WORD *)a1 + 15) == 11 )
      {
        v39 = (unsigned __int8 *)(v4 + 208);
        v40 = KeAbPreAcquire(v4 + 208, 0, 0);
        v55 = v40;
        do
          v41 = __ldrex(v39);
        while ( __strex(v41 | 1, v39) );
        __dmb(0xBu);
        if ( (v41 & 1) != 0 )
        {
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v4 + 208), v40, v4 + 208);
          v40 = v55;
        }
        if ( v40 )
          *(_BYTE *)(v40 + 14) |= 1u;
        *(_DWORD *)(v4 + 244) &= 0xFFFFFFF7;
        __dmb(0xBu);
        do
          v42 = __ldrex((unsigned int *)v39);
        while ( __strex(v42 - 1, (unsigned int *)v39) );
        if ( (v42 & 2) != 0 && (v42 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v4 + 208));
        KeAbPostRelease(v4 + 208);
      }
      v10 = __mrc(15, 0, 13, 0, 3);
      v11 = *((_WORD *)a1 + 14);
      v54[0] = v10 & 0xFFFFFFC0;
      *(_WORD *)(HIDWORD(v2) + 122) = v11;
      *(_WORD *)(HIDWORD(v2) + 120) = *((_WORD *)a1 + 14) - 24;
      v12 = *((_WORD *)a1 + 15);
      *(_WORD *)(HIDWORD(v2) + 124) = v12;
      *(_WORD *)(HIDWORD(v2) + 126) = *((_WORD *)a1 + 16);
      *(_DWORD *)(HIDWORD(v2) + 128) = *(_DWORD *)((v10 & 0xFFFFFFC0) + 0x36C);
      *(_DWORD *)(HIDWORD(v2) + 132) = *(_DWORD *)((v10 & 0xFFFFFFC0) + 0x370);
      v13 = *(_DWORD *)(HIDWORD(v2) + 20);
      if ( (v51 & 0x10000) != 0 )
      {
        *(_DWORD *)(HIDWORD(v2) + 20) = v13 | 0x200;
        v14 = v12 & 0xDFFF;
      }
      else
      {
        *(_DWORD *)(HIDWORD(v2) + 20) = v13 & 0xFFFFFDFF;
        v14 = v12 | 0x2000;
      }
      *(_WORD *)(HIDWORD(v2) + 124) = v14;
      *(_DWORD *)(HIDWORD(v2) + 20) |= 0x10000u;
      __dmb(0xFu);
      v15 = *(_DWORD *)(HIDWORD(v2) + 12);
      if ( v15 )
      {
        if ( (*(_DWORD *)(HIDWORD(v2) + 20) & 0x1000) != 0 )
          ObfDereferenceObject(v15);
        *(_DWORD *)(HIDWORD(v2) + 12) = 0;
      }
      if ( (*(_DWORD *)(v2 + 244) & 0x2000) != 0 && (v43 = *(_DWORD *)(HIDWORD(v2) + 20), (v43 & 0x200) != 0) )
      {
        v16 = v43 & 0xFFFFEFFF;
      }
      else
      {
        ObfReferenceObject(v2);
        v16 = *(_DWORD *)(HIDWORD(v2) + 20) | 0x1000;
      }
      *(_DWORD *)(HIDWORD(v2) + 20) = v16;
      *(_DWORD *)(HIDWORD(v2) + 12) = v2;
      __dmb(0xBu);
      v17 = (unsigned int *)(v8 + 232);
      do
      {
        v18 = __ldrex(v17);
        v19 = v18 + 1;
      }
      while ( __strex(v19, v17) );
      __dmb(0xBu);
      *(_DWORD *)(HIDWORD(v2) + 24) = v19;
      *(_DWORD *)(HIDWORD(v2) + 64) = *(_DWORD *)(v8 + 28);
      ObfDereferenceObject(v8);
      v20 = *(_DWORD *)(HIDWORD(v2) + 8);
      if ( v20 )
      {
        v21 = (unsigned __int8 *)(v20 + 112);
        v22 = KeAbPreAcquire(v20 + 112, 0, 0);
        v23 = v22;
        do
          v24 = __ldrex(v21);
        while ( __strex(v24 | 1, v21) );
        __dmb(0xBu);
        if ( (v24 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v20 + 112), v22, v20 + 112);
        if ( v23 )
          *(_BYTE *)(v23 + 14) |= 1u;
        --*(_DWORD *)(v20 + 268);
        v25 = *(_DWORD *)(HIDWORD(v2) + 20);
        *(_DWORD *)(HIDWORD(v2) + 8) = 0;
        *(_DWORD *)(HIDWORD(v2) + 20) = v25 & 0xFFFFFFF8;
        **(_DWORD **)(HIDWORD(v2) + 4) = *(_DWORD *)HIDWORD(v2);
        *(_DWORD *)(*(_DWORD *)HIDWORD(v2) + 4) = *(_DWORD *)(HIDWORD(v2) + 4);
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)v21);
        while ( __strex(v26 - 1, (unsigned int *)v21) );
        if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v20 + 112));
        KeAbPostRelease(v20 + 112);
        --*(_WORD *)(HIDWORD(v2) - 14);
      }
      v44 = (unsigned int *)(v7 + 208);
      v45 = KeAbPreAcquire(v7 + 208, 0, 0);
      v46 = v45;
      do
        v47 = __ldrex(v44);
      while ( !v47 && __strex(0x11u, v44) );
      __dmb(0xBu);
      if ( v47 )
        ExfAcquirePushLockSharedEx((_DWORD *)(v7 + 208), v45, v7 + 208);
      if ( v46 )
        *(_BYTE *)(v46 + 14) |= 1u;
      if ( (v51 & 0x20000) != 0 )
      {
        LODWORD(v48) = v55;
        HIDWORD(v48) = *(_DWORD *)(HIDWORD(v2) + 20) & 0xFFFFFEFF;
        *(_QWORD *)(HIDWORD(v2) + 16) = v48;
        *(_WORD *)(HIDWORD(v2) - 14) += 2;
        __dmb(0xBu);
        v49 = (unsigned int *)(v48 + 976);
        do
          v50 = __ldrex(v49);
        while ( __strex(HIDWORD(v2), v49) );
        __dmb(0xBu);
      }
      *((_DWORD *)a1 + 4) = v7;
      *((_DWORD *)a1 + 2) = v52;
      if ( *(_DWORD *)(HIDWORD(v2) + 84) )
        *((_DWORD *)a1 + 6) |= 8u;
      AlpcpCompleteDispatchMessage(a1);
      v9 = 0;
    }
  }
  return v9;
}
