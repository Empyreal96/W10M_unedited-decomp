// AlpcpReceiveDirectMessagePort 
 
int __fastcall AlpcpReceiveDirectMessagePort(_DWORD *a1, int a2, int a3, int *a4, int a5)
{
  _DWORD *v6; // r8
  int result; // r0
  int v8; // r4
  unsigned int *v9; // r5
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r3
  unsigned __int8 *v14; // r7
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r2
  __int16 v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r2
  int v22; // r6
  unsigned int *v23; // r7
  unsigned int v24; // r1
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r0
  int v28; // r8
  unsigned int *v29; // r7
  unsigned int v30; // r1
  unsigned int *v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  unsigned int v34; // r2
  int v35; // r8
  unsigned int *v36; // r7
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int v40; // r0
  unsigned int v41; // r2
  unsigned __int8 *v42; // r6
  int v43; // r0
  int v44; // r9
  unsigned int v45; // r2
  __int64 v46; // r2
  unsigned int v47; // r1
  int *v48; // [sp+8h] [bp-20h] BYREF

  v48 = a4;
  if ( !a2 )
    goto LABEL_113;
  v6 = (_DWORD *)*a1;
  result = AlpcpLookupMessage(*a1, a2, a3, &v48);
  if ( result < 0 )
    return result;
  v8 = (int)v48;
  if ( (v48[5] & 7) == 4 )
  {
    v9 = v6 + 52;
    v10 = KeAbPreAcquire((unsigned int)(v6 + 52), 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v6 + 52, v10, (unsigned int)(v6 + 52));
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = v6[61];
    if ( (v13 & 0x40) != 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v8);
      v28 = 0;
      if ( (*(_BYTE *)(v8 - 16) & 1) != 0 )
      {
        v28 = 0x10000 - *(__int16 *)(v8 - 14);
        *(_BYTE *)(v8 - 16) &= 0xFEu;
        *(_WORD *)(v8 - 14) = 0;
      }
      v29 = (unsigned int *)(v8 - 4);
      __dmb(0xBu);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 - 1, v29) );
      if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v8 - 4));
      KeAbPostRelease(v8 - 4);
      if ( v28 > 0 )
      {
        __dmb(0xBu);
        v31 = (unsigned int *)(v8 - 12);
        do
        {
          v32 = __ldrex(v31);
          v33 = v32 - v28;
        }
        while ( __strex(v33, v31) );
        __dmb(0xBu);
        if ( v33 <= 0 )
        {
          if ( v33 )
            KeBugCheckEx(24, 0, v8, 40, v33);
          AlpcpDestroyBlob(v8);
        }
      }
      __dmb(0xBu);
      do
        v34 = __ldrex(v9);
      while ( v34 == 17 && __strex(0, v9) );
      if ( v34 != 17 )
        ExfReleasePushLockShared(v9);
      KeAbPostRelease((unsigned int)v9);
      result = -1073740032;
    }
    else if ( (v13 & 0x10) != 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v8);
      v35 = 0;
      if ( (*(_BYTE *)(v8 - 16) & 1) != 0 )
      {
        v35 = 0x10000 - *(__int16 *)(v8 - 14);
        *(_BYTE *)(v8 - 16) &= 0xFEu;
        *(_WORD *)(v8 - 14) = 0;
      }
      v36 = (unsigned int *)(v8 - 4);
      __dmb(0xBu);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 - 1, v36) );
      if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v8 - 4));
      KeAbPostRelease(v8 - 4);
      if ( v35 > 0 )
      {
        __dmb(0xBu);
        v38 = (unsigned int *)(v8 - 12);
        do
        {
          v39 = __ldrex(v38);
          v40 = v39 - v35;
        }
        while ( __strex(v40, v38) );
        __dmb(0xBu);
        if ( v40 <= 0 )
        {
          if ( v40 )
            KeBugCheckEx(24, 0, v8, 40, v40);
          AlpcpDestroyBlob(v8);
        }
      }
      __dmb(0xBu);
      do
        v41 = __ldrex(v9);
      while ( v41 == 17 && __strex(0, v9) );
      if ( v41 != 17 )
        ExfReleasePushLockShared(v9);
      KeAbPostRelease((unsigned int)v9);
      result = -1073741759;
    }
    else
    {
      v14 = (unsigned __int8 *)(v6 + 31);
      v15 = KeAbPreAcquire((unsigned int)(v6 + 31), 0, 0);
      v16 = v15;
      do
        v17 = __ldrex(v14);
      while ( __strex(v17 | 1, v14) );
      __dmb(0xBu);
      if ( (v17 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v6 + 31, v15, (unsigned int)(v6 + 31));
      if ( v16 )
        *(_BYTE *)(v16 + 14) |= 1u;
      --v6[68];
      *(_DWORD *)(v8 + 20) &= 0xFFFFFFF8;
      *(_DWORD *)(v8 + 8) = 0;
      **(_DWORD **)(v8 + 4) = *(_DWORD *)v8;
      *(_DWORD *)(*(_DWORD *)v8 + 4) = *(_DWORD *)(v8 + 4);
      v18 = 0;
      if ( *(_DWORD *)(v8 + 72) )
        v18 = 0x80000000;
      if ( *(_DWORD *)(v8 + 76) )
        v18 |= 0x40000000u;
      if ( *(_DWORD *)(v8 + 80) )
        v18 |= 0x10000000u;
      v19 = *(_WORD *)(v8 + 124);
      if ( (v18 & a5) != 0 )
      {
        v42 = (unsigned __int8 *)(v6 + 28);
        *(_WORD *)(v8 + 124) = v19 | 0x2000;
        v43 = KeAbPreAcquire((unsigned int)(v6 + 28), 0, 0);
        v44 = v43;
        do
          v45 = __ldrex(v42);
        while ( __strex(v45 | 1, v42) );
        __dmb(0xBu);
        if ( (v45 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v6 + 28, v43, (unsigned int)(v6 + 28));
        if ( v44 )
          *(_BYTE *)(v44 + 14) |= 1u;
        *(_DWORD *)(v8 + 8) = v6;
        LODWORD(v46) = v6 + 29;
        *(_DWORD *)(v8 + 20) = *(_DWORD *)(v8 + 20) & 0xFFFFFF83 | (4 * (v6[61] & 6)) | 3;
        HIDWORD(v46) = v6[30];
        *(_QWORD *)v8 = v46;
        *(_DWORD *)v6[30] = v8;
        v6[30] = v8;
        ++v6[67];
        __dmb(0xBu);
        do
          v47 = __ldrex((unsigned int *)v42);
        while ( __strex(v47 - 1, (unsigned int *)v42) );
        if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v42);
        KeAbPostRelease((unsigned int)v42);
      }
      else
      {
        *(_WORD *)(v8 + 124) = v19 & 0xDFFF;
        --*(_WORD *)(v8 - 14);
      }
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)v14);
      while ( __strex(v20 - 1, (unsigned int *)v14) );
      if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v14);
      KeAbPostRelease((unsigned int)v14);
      __dmb(0xBu);
      do
        v21 = __ldrex(v9);
      while ( v21 == 17 && __strex(0, v9) );
      if ( v21 != 17 )
        ExfReleasePushLockShared(v9);
      KeAbPostRelease((unsigned int)v9);
      if ( AlpcpLogEnabled )
        AlpcpLogReceiveMessage(v8);
      *a4 = v8;
      result = 0;
    }
    return result;
  }
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v48);
  v22 = 0;
  if ( (*(_BYTE *)(v8 - 16) & 1) != 0 )
  {
    v22 = 0x10000 - *(__int16 *)(v8 - 14);
    *(_BYTE *)(v8 - 16) &= 0xFEu;
    *(_WORD *)(v8 - 14) = 0;
  }
  v23 = (unsigned int *)(v8 - 4);
  __dmb(0xBu);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 - 1, v23) );
  if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v8 - 4));
  KeAbPostRelease(v8 - 4);
  if ( v22 <= 0 )
    goto LABEL_113;
  __dmb(0xBu);
  v25 = (unsigned int *)(v8 - 12);
  do
  {
    v26 = __ldrex(v25);
    v27 = v26 - v22;
  }
  while ( __strex(v27, v25) );
  __dmb(0xBu);
  if ( v27 > 0 )
LABEL_113:
    JUMPOUT(0x7E661A);
  if ( v27 )
    KeBugCheckEx(24, 0, v8, 40, v27);
  return sub_7E6614(0, -v22);
}
