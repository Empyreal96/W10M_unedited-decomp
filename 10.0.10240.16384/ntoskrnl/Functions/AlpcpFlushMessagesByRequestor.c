// AlpcpFlushMessagesByRequestor 
 
unsigned int __fastcall AlpcpFlushMessagesByRequestor(int a1, unsigned __int8 *a2, int *a3, unsigned int a4)
{
  int v4; // r6
  unsigned __int8 *v7; // r5
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r4
  unsigned int *v11; // r4
  unsigned int v12; // r1
  unsigned __int8 *v14; // r8
  int v15; // r0
  unsigned int v16; // r5
  int *v17; // r3
  int v18; // r5
  bool v19; // zf
  unsigned int *v20; // lr
  int v21; // r0
  int v22; // r1
  unsigned int *v23; // r5
  unsigned int v24; // r1
  unsigned __int8 *v25; // r8
  int v26; // r0
  int v27; // r5
  unsigned int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r1
  int v32; // r8
  unsigned int *v33; // r5
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r0
  unsigned __int8 *v38; // r5
  int v39; // r4
  unsigned int v40; // r2
  unsigned __int8 *v41; // r5
  int v42; // r0
  unsigned int v43; // r2

  v4 = a1;
  if ( a4 <= 2 )
  {
    v7 = a2 + 92;
    v8 = KeAbPreAcquire((unsigned int)(a2 + 92), 0, 0);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 | 1, v7) );
LABEL_4:
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    goto LABEL_8;
  }
  if ( a4 == 3 )
  {
    v7 = a2 + 112;
    v8 = KeAbPreAcquire((unsigned int)(a2 + 112), 0, 0);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 | 1, v7) );
    goto LABEL_4;
  }
  v14 = a2 + 124;
  v15 = KeAbPreAcquire((unsigned int)(a2 + 124), 0, 0);
  do
    v16 = __ldrex(v14);
  while ( __strex(v16 | 1, v14) );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    return sub_807768(v15);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  v4 = a1;
LABEL_8:
  v10 = *a3;
  if ( (int *)*a3 != a3 )
  {
    while ( *(_DWORD *)(v10 + 12) != v4 && (*(_WORD *)(v10 + 22) & 1) == 0 )
    {
      v10 = *(_DWORD *)v10;
      v17 = a3;
LABEL_34:
      if ( (int *)v10 == v17 )
        goto LABEL_9;
    }
    v18 = *(_DWORD *)(v10 - 12);
    v19 = v18 == 0;
    if ( v18 <= 0 )
    {
LABEL_44:
      if ( !v19 )
        KeBugCheckEx(24, 0, v10, 32, v18);
    }
    else
    {
      v20 = (unsigned int *)(v10 - 12);
      while ( 1 )
      {
        v21 = v18;
        __dmb(0xBu);
        do
          v22 = __ldrex(v20);
        while ( v22 == v18 && __strex(v18 + 1, v20) );
        v18 = v22;
        __dmb(0xBu);
        if ( v22 == v21 )
          break;
        if ( v22 <= 0 )
        {
          v19 = v22 == 0;
          goto LABEL_44;
        }
      }
    }
    if ( a4 <= 2 )
    {
      v23 = (unsigned int *)(a2 + 92);
      __dmb(0xBu);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 - 1, v23) );
    }
    else
    {
      if ( a4 == 3 )
        v23 = (unsigned int *)(a2 + 112);
      else
        v23 = (unsigned int *)(a2 + 124);
      __dmb(0xBu);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 - 1, v23) );
    }
    if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
      ExfTryToWakePushLock(v23);
    KeAbPostRelease((unsigned int)v23);
    v25 = (unsigned __int8 *)(v10 - 4);
    v26 = KeAbPreAcquire(v10 - 4, 0, 0);
    v27 = v26;
    do
      v28 = __ldrex(v25);
    while ( __strex(v28 | 1, v25) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v10 - 4), v26, v10 - 4);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    *(_BYTE *)(v10 - 16) |= 1u;
    __dmb(0xBu);
    v29 = (unsigned int *)(v10 - 12);
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 + 0x10000;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( v31 <= 0 )
      KeBugCheckEx(24, 0, v10, 38, v31);
    --*(_WORD *)(v10 - 14);
    if ( *(_DWORD *)(v10 + 12) == a1 )
    {
      AlpcpCancelMessage(a2, v10, 0x10000);
    }
    else
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v10);
      v32 = 0;
      if ( (*(_BYTE *)(v10 - 16) & 1) != 0 )
      {
        v32 = 0x10000 - *(__int16 *)(v10 - 14);
        *(_BYTE *)(v10 - 16) &= 0xFEu;
        *(_WORD *)(v10 - 14) = 0;
      }
      v33 = (unsigned int *)(v10 - 4);
      __dmb(0xBu);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 - 1, v33) );
      if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v10 - 4));
      KeAbPostRelease(v10 - 4);
      if ( v32 > 0 )
      {
        __dmb(0xBu);
        v35 = (unsigned int *)(v10 - 12);
        do
        {
          v36 = __ldrex(v35);
          v37 = v36 - v32;
        }
        while ( __strex(v37, v35) );
        __dmb(0xBu);
        if ( v37 <= 0 )
        {
          if ( v37 )
            KeBugCheckEx(24, 0, v10, 40, v37);
          AlpcpDestroyBlob(v10);
        }
      }
    }
    if ( a4 <= 2 )
    {
      v41 = a2 + 92;
      v42 = KeAbPreAcquire((unsigned int)(a2 + 92), 0, 0);
      v39 = v42;
      do
        v43 = __ldrex(v41);
      while ( __strex(v43 | 1, v41) );
      __dmb(0xBu);
      if ( (v43 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)a2 + 23, v42, (unsigned int)(a2 + 92));
      if ( !v39 )
        goto LABEL_102;
    }
    else
    {
      if ( a4 == 3 )
      {
        v38 = a2 + 112;
        v39 = KeAbPreAcquire((unsigned int)(a2 + 112), 0, 0);
        do
          v40 = __ldrex(v38);
        while ( __strex(v40 | 1, v38) );
      }
      else
      {
        v38 = a2 + 124;
        v39 = KeAbPreAcquire((unsigned int)(a2 + 124), 0, 0);
        do
          v40 = __ldrex(v38);
        while ( __strex(v40 | 1, v38) );
      }
      __dmb(0xBu);
      if ( (v40 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v38, v39, (unsigned int)v38);
      if ( !v39 )
        goto LABEL_102;
    }
    *(_BYTE *)(v39 + 14) |= 1u;
LABEL_102:
    v4 = a1;
    v17 = a3;
    v10 = *a3;
    goto LABEL_34;
  }
LABEL_9:
  if ( a4 <= 2 )
  {
    v11 = (unsigned int *)(a2 + 92);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
  }
  else
  {
    if ( a4 == 3 )
      v11 = (unsigned int *)(a2 + 112);
    else
      v11 = (unsigned int *)(a2 + 124);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
  }
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock(v11);
  return KeAbPostRelease((unsigned int)v11);
}
