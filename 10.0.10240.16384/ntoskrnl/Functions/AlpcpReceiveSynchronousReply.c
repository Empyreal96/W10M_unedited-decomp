// AlpcpReceiveSynchronousReply 
 
int __fastcall AlpcpReceiveSynchronousReply(_DWORD *a1, char a2, int *a3, int a4)
{
  unsigned int v6; // r10
  int v7; // r5
  unsigned int *v8; // r0
  int v9; // r4
  unsigned __int8 *v10; // r7
  int v11; // r6
  unsigned int v12; // r2
  unsigned int *v13; // r0
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r3
  int v17; // r3
  unsigned int v18; // r2
  __int16 v19; // r3
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r0
  unsigned int v24; // r2
  int v25; // r2
  unsigned __int8 *v26; // r9
  int v27; // r0
  int v28; // r7
  unsigned int v29; // r2
  int v30; // r2
  __int64 v31; // r1
  unsigned int v32; // r0
  char v33; // r2
  int v34; // r8
  int v35; // r3
  unsigned int *v36; // r6
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int v40; // r0
  char v41; // r2
  int v42; // r6
  int v43; // r3
  unsigned int *v44; // r5
  unsigned int v45; // r1
  unsigned int *v46; // r2
  unsigned int v47; // r0
  int v48; // r0
  unsigned int *v49; // r10
  int v50; // r0
  int v51; // r7
  unsigned int v52; // r2
  unsigned int v53; // r2
  unsigned int v54; // r2
  _DWORD *v55; // [sp+8h] [bp-20h]

  v55 = (_DWORD *)*a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = AlpcpSignalAndWait((int)a1, v6 + 884, 17, a2);
  __dmb(0xBu);
  v8 = (unsigned int *)(v6 + 976);
  do
    v9 = __ldrex(v8);
  while ( __strex(0, v8) );
  __dmb(0xBu);
  if ( !v9 )
  {
    if ( v7 )
      return sub_7F8B60();
    return -1073740031;
  }
  v10 = (unsigned __int8 *)(v9 - 4);
  v11 = KeAbPreAcquire(v9 - 4, 0, 0);
  do
    v12 = __ldrex(v10);
  while ( __strex(v12 | 1, v10) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 - 4), v11, v9 - 4);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  *(_BYTE *)(v9 - 16) |= 1u;
  __dmb(0xBu);
  v13 = (unsigned int *)(v9 - 12);
  do
  {
    v14 = __ldrex(v13);
    v15 = v14 + 0x10000;
  }
  while ( __strex(v15, v13) );
  __dmb(0xBu);
  if ( v15 <= 0 )
    KeBugCheckEx(24, 0, v9, 38, v15);
  v16 = *(_DWORD *)(v9 + 20);
  if ( (v16 & 0x800) != 0 )
    *(_DWORD *)(v9 + 20) = v16 & 0xFFFFF7FF;
  --*(_WORD *)(v9 - 14);
  if ( !v7 )
  {
LABEL_16:
    v17 = *(_DWORD *)(v9 + 20);
    if ( (v17 & 0x80) == 0 )
    {
      if ( (v17 & 0x200) != 0 )
      {
        v18 = 0;
        if ( *(_DWORD *)(v9 + 72) )
          v18 = 0x80000000;
        if ( *(_DWORD *)(v9 + 76) )
          v18 |= 0x40000000u;
        if ( *(_DWORD *)(v9 + 80) )
          v18 |= 0x10000000u;
        v19 = *(_WORD *)(v9 + 124);
        if ( (v18 & a4) == 0 )
        {
          *(_WORD *)(v9 + 124) = v19 & 0xDFFF;
          goto LABEL_26;
        }
      }
      else
      {
        v19 = *(_WORD *)(v9 + 124);
      }
      v49 = v55 + 52;
      *(_WORD *)(v9 + 124) = v19 | 0x2000;
      v50 = KeAbPreAcquire((unsigned int)(v55 + 52), 0, 0);
      v51 = v50;
      do
        v52 = __ldrex(v49);
      while ( !v52 && __strex(0x11u, v49) );
      __dmb(0xBu);
      if ( v52 )
        ExfAcquirePushLockSharedEx(v49, v50, (unsigned int)v49);
      if ( v51 )
        *(_BYTE *)(v51 + 14) |= 1u;
      v25 = v55[61];
      if ( (v25 & 0x40) != 0 )
      {
        __dmb(0xBu);
        do
          v53 = __ldrex(v49);
        while ( v53 == 17 && __strex(0, v49) );
        if ( v53 != 17 )
          ExfReleasePushLockShared(v49);
        KeAbPostRelease((unsigned int)v49);
        AlpcpCancelMessage(v55, v9, 0);
        return -1073740032;
      }
      if ( (v55[38] & 0x1000) == 0 || (v25 & 0x20) == 0 || !*(_DWORD *)(v9 + 16) )
      {
        v26 = (unsigned __int8 *)(v55 + 28);
        ++*(_WORD *)(v9 - 14);
        v27 = KeAbPreAcquire((unsigned int)(v55 + 28), 0, 0);
        v28 = v27;
        do
          v29 = __ldrex(v26);
        while ( __strex(v29 | 1, v26) );
        __dmb(0xBu);
        if ( (v29 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v26, v27, (unsigned int)v26);
        if ( v28 )
          *(_BYTE *)(v28 + 14) |= 1u;
        v30 = *(_DWORD *)(v9 + 20);
        *(_DWORD *)(v9 + 8) = v55;
        LODWORD(v31) = v55 + 29;
        *(_DWORD *)(v9 + 20) = v30 & 0xFFFFFF83 | (4 * (v55[61] & 6)) | 3;
        HIDWORD(v31) = v55[30];
        *(_QWORD *)v9 = v31;
        *(_DWORD *)v55[30] = v9;
        v55[30] = v9;
        ++v55[67];
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)v26);
        while ( __strex(v32 - 1, (unsigned int *)v26) );
        if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v26);
        KeAbPostRelease((unsigned int)v26);
      }
      __dmb(0xBu);
      do
        v54 = __ldrex(v49);
      while ( v54 == 17 && __strex(0, v49) );
      if ( v54 != 17 )
        ExfReleasePushLockShared(v49);
      KeAbPostRelease((unsigned int)v49);
LABEL_26:
      if ( AlpcpLogEnabled )
        AlpcpLogReceiveMessage(v9);
      *a3 = v9;
      return v7;
    }
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v9);
    v41 = *(_BYTE *)(v9 - 16);
    v42 = 0;
    if ( (v41 & 1) != 0 )
    {
      v43 = *(__int16 *)(v9 - 14);
      *(_WORD *)(v9 - 14) = 0;
      v42 = 0x10000 - v43;
      *(_BYTE *)(v9 - 16) = v41 & 0xFE;
    }
    v44 = (unsigned int *)(v9 - 4);
    __dmb(0xBu);
    do
      v45 = __ldrex(v44);
    while ( __strex(v45 - 1, v44) );
    if ( (v45 & 2) != 0 && (v45 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v9 - 4));
    KeAbPostRelease(v9 - 4);
    if ( v42 > 0 )
    {
      __dmb(0xBu);
      v46 = (unsigned int *)(v9 - 12);
      do
      {
        v47 = __ldrex(v46);
        v48 = v47 - v42;
      }
      while ( __strex(v48, v46) );
      __dmb(0xBu);
      if ( v48 <= 0 )
      {
        if ( v48 )
          KeBugCheckEx(24, 0, v9, 40, v48);
        AlpcpDestroyBlob(v9);
      }
    }
    return -1073740031;
  }
  if ( *(_DWORD *)(v9 + 16) != v6 )
  {
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery((int)v13);
    v23 = KeWaitForSingleObject(v6 + 884, 17, 0, 0, 0);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v24 + 0x134);
    if ( AlpcpLogEnabled )
      AlpcpLogUnwait(v23);
    v7 = 0;
    goto LABEL_16;
  }
  *(_DWORD *)(v9 + 16) = 0;
  --*(_WORD *)(v9 - 14);
  if ( (*(_DWORD *)(v9 + 20) & 0x80) != 0 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v9);
    v33 = *(_BYTE *)(v9 - 16);
    v34 = 0;
    if ( (v33 & 1) != 0 )
    {
      v35 = *(__int16 *)(v9 - 14);
      *(_WORD *)(v9 - 14) = 0;
      v34 = 0x10000 - v35;
      *(_BYTE *)(v9 - 16) = v33 & 0xFE;
    }
    v36 = (unsigned int *)(v9 - 4);
    __dmb(0xBu);
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 - 1, v36) );
    if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v9 - 4));
    KeAbPostRelease(v9 - 4);
    if ( v34 > 0 )
    {
      __dmb(0xBu);
      v38 = (unsigned int *)(v9 - 12);
      do
      {
        v39 = __ldrex(v38);
        v40 = v39 - v34;
      }
      while ( __strex(v40, v38) );
      __dmb(0xBu);
      if ( v40 <= 0 )
      {
        if ( v40 )
          KeBugCheckEx(24, 0, v9, 40, v40);
        AlpcpDestroyBlob(v9);
      }
    }
    return v7;
  }
  AlpcpCancelMessage(v55, v9, 0);
  return v7;
}
