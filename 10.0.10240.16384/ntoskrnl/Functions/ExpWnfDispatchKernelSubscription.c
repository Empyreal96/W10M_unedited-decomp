// ExpWnfDispatchKernelSubscription 
 
unsigned int ExpWnfDispatchKernelSubscription()
{
  int v0; // r5
  unsigned __int8 *v1; // r6
  int v2; // r0
  unsigned int v3; // r2
  _DWORD *v5; // r2
  unsigned int *v6; // r10
  int v7; // r8
  _DWORD *v8; // r9
  unsigned int v9; // r0
  unsigned int v10; // r1
  __int64 v11; // r0
  int v12; // r7
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  _DWORD *v17; // r5
  unsigned int *v18; // r4
  unsigned int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r2
  int v23; // r1
  int v24; // r3
  unsigned int *v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r1
  unsigned int *v28; // r4
  unsigned int v29; // r0
  unsigned int v30; // r1
  int v31; // r4
  unsigned int v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r1
  unsigned int v36; // r2
  unsigned int *v37; // r4
  unsigned int v38; // r0
  unsigned int v39; // r1
  int v40; // [sp+8h] [bp-30h]
  _DWORD *v41; // [sp+Ch] [bp-2Ch]
  __int64 v42[5]; // [sp+10h] [bp-28h] BYREF

  v0 = *(_DWORD *)(PsInitialSystemProcess + 724);
  v40 = v0;
  __dmb(0xBu);
  v1 = (unsigned __int8 *)(v0 + 52);
  v2 = KeAbPreAcquire(v0 + 52, 0, 0);
  do
    v3 = __ldrex(v1);
  while ( __strex(v3 | 1, v1) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    return sub_7F3490(v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v5 = (_DWORD *)(v0 + 56);
  v41 = (_DWORD *)(v0 + 56);
  v6 = (unsigned int *)(v0 + 40);
  while ( (_DWORD *)*v5 != v5 )
  {
    v7 = *(_DWORD *)(v0 + 56) - 64;
    v8 = (_DWORD *)(*(_DWORD *)(v0 + 56) - 60);
    __pld(v8);
    v9 = *v8 & 0xFFFFFFFE;
    do
      v10 = __ldrex(v8);
    while ( v10 == v9 && __strex(v9 + 2, v8) );
    __dmb(0xBu);
    if ( v10 != v9 )
      ExfAcquireRundownProtection(v8);
    *(_DWORD *)(v7 + 72) = 2;
    v11 = *(_QWORD *)(v7 + 64);
    if ( *(_DWORD *)(v11 + 4) != v7 + 64 || *(_DWORD *)HIDWORD(v11) != v7 + 64 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v11) = v11;
    *(_DWORD *)(v11 + 4) = HIDWORD(v11);
    do
    {
      v12 = *(_DWORD *)(v7 + 76);
      *(_DWORD *)(v7 + 76) = 0;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v1);
      while ( __strex(v13 - 1, (unsigned int *)v1) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v1);
      KeAbPostRelease((unsigned int)v1);
      v14 = KeAbPreAcquire((unsigned int)v6, 0, 0);
      v15 = v14;
      do
        v16 = __ldrex(v6);
      while ( !v16 && __strex(0x11u, v6) );
      __dmb(0xBu);
      if ( v16 )
        ExfAcquirePushLockSharedEx(v6, v14, (unsigned int)v6);
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      v17 = *(_DWORD **)(v7 + 28);
      if ( !v17 )
        goto LABEL_77;
      v18 = v17 + 1;
      __pld(v17 + 1);
      v19 = v17[1] & 0xFFFFFFFE;
      do
        v20 = __ldrex(v18);
      while ( v20 == v19 && __strex(v19 + 2, v18) );
      __dmb(0xBu);
      if ( v20 != v19 && !ExfAcquireRundownProtection(v17 + 1) )
        v17 = 0;
      if ( !v17 )
LABEL_77:
        v12 &= 0xFFFFFFFE;
      if ( (v12 & 1) != 0 )
      {
        v21 = v17[14];
        if ( v21 <= *(_DWORD *)(v7 + 56) )
          v12 &= 0xFFFFFFFE;
        else
          *(_DWORD *)(v7 + 56) = v21;
      }
      __dmb(0xBu);
      if ( v12 )
      {
        do
          v22 = __ldrex(v6);
        while ( v22 == 17 && __strex(0, v6) );
        if ( v22 != 17 )
          ExfReleasePushLockShared(v6);
        KeAbPostRelease((unsigned int)v6);
        v42[0] = *(_QWORD *)(v7 + 32) ^ 0x41C64E6DA3BC0074i64;
        if ( v17 )
          v23 = v17[10];
        else
          v23 = 0;
        if ( v17 && (v12 & 1) != 0 )
          v24 = v17[14];
        else
          v24 = 0;
        (*(void (__fastcall **)(int, __int64 *, int, int, int, _DWORD))(v7 + 48))(
          v7,
          v42,
          v12,
          v24,
          v23,
          *(_DWORD *)(v7 + 52));
        if ( (v12 & 1) != 0 )
        {
          __dmb(0xBu);
          v25 = v17 + 23;
          do
          {
            v26 = __ldrex(v25);
            v27 = v26 - 1;
          }
          while ( __strex(v27, v25) );
          __dmb(0xBu);
          if ( !v27 )
            ExpWnfNotifyNameSubscribers((int)v17, 8, 0, 0);
        }
        if ( v17 )
        {
          v28 = v17 + 1;
          __pld(v17 + 1);
          v29 = v17[1] & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v30 = __ldrex(v28);
          while ( v30 == v29 && __strex(v29 - 2, v28) );
          if ( v30 != v29 )
            ExfReleaseRundownProtection((unsigned __int8 *)v17 + 4);
        }
        v31 = KeAbPreAcquire((unsigned int)v1, 0, 0);
        do
          v32 = __ldrex(v1);
        while ( __strex(v32 | 1, v1) );
      }
      else
      {
        do
          v36 = __ldrex(v6);
        while ( v36 == 17 && __strex(0, v6) );
        if ( v36 != 17 )
          ExfReleasePushLockShared(v6);
        KeAbPostRelease((unsigned int)v6);
        if ( v17 )
        {
          v37 = v17 + 1;
          __pld(v17 + 1);
          v38 = v17[1] & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v39 = __ldrex(v37);
          while ( v39 == v38 && __strex(v38 - 2, v37) );
          if ( v39 != v38 )
            ExfReleaseRundownProtection((unsigned __int8 *)v17 + 4);
        }
        v31 = KeAbPreAcquire((unsigned int)v1, 0, 0);
        do
          v32 = __ldrex(v1);
        while ( __strex(v32 | 1, v1) );
      }
      __dmb(0xBu);
      if ( (v32 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v1, v31, (unsigned int)v1);
      if ( v31 )
        *(_BYTE *)(v31 + 14) |= 1u;
    }
    while ( *(_DWORD *)(v7 + 76) );
    __pld(v8);
    *(_DWORD *)(v7 + 72) = 0;
    v33 = *v8 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v34 = __ldrex(v8);
    while ( v34 == v33 && __strex(v33 - 2, v8) );
    v0 = v40;
    v5 = (_DWORD *)(v40 + 56);
    if ( v34 != v33 )
    {
      ExfReleaseRundownProtection((unsigned __int8 *)v8);
      v0 = v40;
      v5 = v41;
    }
  }
  __dmb(0xBu);
  do
    v35 = __ldrex((unsigned int *)v1);
  while ( __strex(v35 - 1, (unsigned int *)v1) );
  if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v1);
  return KeAbPostRelease((unsigned int)v1);
}
