// AlpcpFlushQueue 
 
unsigned int __fastcall AlpcpFlushQueue(unsigned __int8 *a1, int *a2, unsigned int a3)
{
  int *v3; // r7
  unsigned __int8 *v6; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r5
  unsigned int *v11; // r4
  unsigned int v12; // r1
  unsigned __int8 *v14; // r5
  int v15; // r0
  unsigned int v16; // r2
  unsigned __int8 *v17; // r7
  int v18; // r0
  unsigned int v19; // r4
  int v20; // r4
  bool v21; // zf
  unsigned int *v22; // lr
  int v23; // r0
  int v24; // r1
  unsigned int *v25; // r4
  unsigned int v26; // r1
  unsigned __int8 *v27; // r10
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r2
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r1
  unsigned __int8 *v34; // r5
  unsigned int v35; // r2
  int v36; // r10
  unsigned int *v37; // r4
  unsigned int v38; // r1
  unsigned int *v39; // r2
  unsigned int v40; // r0
  int v41; // r0

  v3 = a2;
  if ( a3 <= 2 )
  {
    v6 = a1 + 92;
    v7 = KeAbPreAcquire((unsigned int)(a1 + 92), 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v6);
    while ( __strex(v9 | 1, v6) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
    if ( !v8 )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( a3 == 3 )
  {
    v14 = a1 + 112;
    v15 = KeAbPreAcquire((unsigned int)(a1 + 112), 0, 0);
    v8 = v15;
    do
      v16 = __ldrex(v14);
    while ( __strex(v16 | 1, v14) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a1 + 28, v15, (unsigned int)(a1 + 112));
    if ( !v8 )
      goto LABEL_8;
LABEL_7:
    *(_BYTE *)(v8 + 14) |= 1u;
    goto LABEL_8;
  }
  v17 = a1 + 124;
  v18 = KeAbPreAcquire((unsigned int)(a1 + 124), 0, 0);
  do
    v19 = __ldrex(v17);
  while ( __strex(v19 | 1, v17) );
  __dmb(0xBu);
  if ( (v19 & 1) != 0 )
    return sub_806FA4(v18);
  v3 = a2;
  if ( v18 )
    *(_BYTE *)(v18 + 14) |= 1u;
LABEL_8:
  while ( 1 )
  {
    v10 = *v3;
    if ( (int *)*v3 == v3 )
      break;
    v20 = *(_DWORD *)(v10 - 12);
    v21 = v20 == 0;
    if ( v20 <= 0 )
    {
LABEL_75:
      if ( !v21 )
        KeBugCheckEx(24, 0, v10, 32, v20);
    }
    else
    {
      v22 = (unsigned int *)(v10 - 12);
      while ( 1 )
      {
        v23 = v20;
        __dmb(0xBu);
        do
          v24 = __ldrex(v22);
        while ( v24 == v20 && __strex(v20 + 1, v22) );
        v20 = v24;
        __dmb(0xBu);
        if ( v24 == v23 )
          break;
        if ( v24 <= 0 )
        {
          v21 = v24 == 0;
          goto LABEL_75;
        }
      }
    }
    if ( a3 > 2 )
    {
      if ( a3 == 3 )
        v25 = (unsigned int *)(a1 + 112);
      else
        v25 = (unsigned int *)(a1 + 124);
      __dmb(0xBu);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - 1, v25) );
    }
    else
    {
      v25 = (unsigned int *)(a1 + 92);
      __dmb(0xBu);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - 1, v25) );
    }
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock(v25);
    KeAbPostRelease((unsigned int)v25);
    v27 = (unsigned __int8 *)(v10 - 4);
    v28 = KeAbPreAcquire(v10 - 4, 0, 0);
    v29 = v28;
    do
      v30 = __ldrex(v27);
    while ( __strex(v30 | 1, v27) );
    __dmb(0xBu);
    if ( (v30 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v10 - 4), v28, v10 - 4);
    if ( v29 )
      *(_BYTE *)(v29 + 14) |= 1u;
    *(_BYTE *)(v10 - 16) |= 1u;
    __dmb(0xBu);
    v31 = (unsigned int *)(v10 - 12);
    do
    {
      v32 = __ldrex(v31);
      v33 = v32 + 0x10000;
    }
    while ( __strex(v33, v31) );
    __dmb(0xBu);
    if ( v33 <= 0 )
      KeBugCheckEx(24, 0, v10, 38, v33);
    --*(_WORD *)(v10 - 14);
    if ( *(unsigned __int8 **)(v10 + 8) == a1 )
    {
      AlpcpCancelMessage(a1, v10, 0x10000);
    }
    else
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v10);
      v36 = 0;
      if ( (*(_BYTE *)(v10 - 16) & 1) != 0 )
      {
        v36 = 0x10000 - *(__int16 *)(v10 - 14);
        *(_BYTE *)(v10 - 16) &= 0xFEu;
        *(_WORD *)(v10 - 14) = 0;
      }
      v37 = (unsigned int *)(v10 - 4);
      __dmb(0xBu);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 - 1, v37) );
      if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v10 - 4));
      KeAbPostRelease(v10 - 4);
      if ( v36 > 0 )
      {
        __dmb(0xBu);
        v39 = (unsigned int *)(v10 - 12);
        do
        {
          v40 = __ldrex(v39);
          v41 = v40 - v36;
        }
        while ( __strex(v41, v39) );
        __dmb(0xBu);
        if ( v41 <= 0 )
        {
          if ( v41 )
            KeBugCheckEx(24, 0, v10, 40, v41);
          AlpcpDestroyBlob(v10);
        }
      }
    }
    if ( a3 > 2 )
    {
      if ( a3 == 3 )
        v34 = a1 + 112;
      else
        v34 = a1 + 124;
      v8 = KeAbPreAcquire((unsigned int)v34, 0, 0);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 | 1, v34) );
    }
    else
    {
      v34 = a1 + 92;
      v8 = KeAbPreAcquire((unsigned int)(a1 + 92), 0, 0);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 | 1, v34) );
    }
    __dmb(0xBu);
    if ( (v35 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v34, v8, (unsigned int)v34);
    v3 = a2;
    if ( v8 )
      goto LABEL_7;
  }
  if ( a3 <= 2 )
  {
    v11 = (unsigned int *)(a1 + 92);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
  }
  else
  {
    if ( a3 == 3 )
      v11 = (unsigned int *)(a1 + 112);
    else
      v11 = (unsigned int *)(a1 + 124);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
  }
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock(v11);
  return KeAbPostRelease((unsigned int)v11);
}
