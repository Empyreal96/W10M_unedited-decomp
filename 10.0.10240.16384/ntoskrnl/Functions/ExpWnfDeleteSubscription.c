// ExpWnfDeleteSubscription 
 
int __fastcall ExpWnfDeleteSubscription(unsigned int a1, int a2)
{
  int v2; // r8
  unsigned __int8 *v4; // r5
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int result; // r0
  int v9; // r5
  BOOL v10; // r9
  BOOL v11; // r10
  unsigned __int8 *v12; // r7
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  __int64 v16; // r0
  __int64 v17; // r0
  unsigned __int8 *v18; // r7
  int v19; // r0
  int v20; // r4
  unsigned int v21; // r2
  int v22; // r1
  unsigned int v23; // r1
  int v24; // r7
  unsigned int *v25; // r4
  unsigned int v26; // r1
  unsigned int *v27; // r4
  unsigned int v28; // r1
  int v29; // r7
  unsigned int *v30; // r5
  unsigned int v31; // r4
  unsigned int v32; // r1
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r1
  unsigned int *v37; // r0
  unsigned int v38; // r4
  unsigned int v39; // r1
  unsigned int *v40; // r0
  unsigned int v41; // r4
  unsigned int v42; // r1
  __int64 v43; // r0
  unsigned int *v44; // r2
  unsigned int v45; // r1
  unsigned int v46; // r1
  unsigned int *v47; // r4
  unsigned int v48; // r1

  v2 = *(_DWORD *)(a2 + 724);
  __dmb(0xBu);
  if ( v2 )
  {
    v4 = (unsigned __int8 *)(v2 + 40);
    v5 = KeAbPreAcquire(v2 + 40, 0, 0);
    v6 = v5;
    do
      v7 = __ldrex(v4);
    while ( __strex(v7 | 1, v4) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 40), v5, v2 + 40);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
  }
  result = 4;
  if ( *(_DWORD *)(a1 + 24) )
  {
    v9 = *(_DWORD *)(a1 + 28);
    v10 = 0;
    v11 = 0;
    if ( v9 )
    {
      v12 = (unsigned __int8 *)(v9 + 64);
      v13 = KeAbPreAcquire(v9 + 64, 0, 0);
      v14 = v13;
      do
        v15 = __ldrex(v12);
      while ( __strex(v15 | 1, v12) );
      __dmb(0xBu);
      if ( (v15 & 1) != 0 )
        v13 = ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 64), v13, v9 + 64);
      if ( !v14 )
        return sub_7C06F0(v13);
      *(_BYTE *)(v14 + 14) |= 1u;
      v16 = *(_QWORD *)(a1 + 40);
      if ( *(_DWORD *)(v16 + 4) != a1 + 40 || *(_DWORD *)HIDWORD(v16) != a1 + 40 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v16) = v16;
      *(_DWORD *)(v16 + 4) = HIDWORD(v16);
      *(_DWORD *)(a1 + 28) = 0;
      if ( (*(_DWORD *)(a1 + 60) & 1) != 0 )
      {
        __dmb(0xBu);
        v34 = (unsigned int *)(v9 + 88);
        do
        {
          v35 = __ldrex(v34);
          v36 = v35 - 1;
        }
        while ( __strex(v36, v34) );
        __dmb(0xBu);
        v11 = v36 == 0;
      }
    }
    v17 = *(_QWORD *)(a1 + 16);
    if ( *(_DWORD *)(v17 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v17) != a1 + 16 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v17) = v17;
    v18 = (unsigned __int8 *)(v2 + 52);
    *(_DWORD *)(v17 + 4) = HIDWORD(v17);
    v19 = KeAbPreAcquire(v2 + 52, 0, 0);
    v20 = v19;
    do
      v21 = __ldrex(v18);
    while ( __strex(v21 | 1, v18) );
    __dmb(0xBu);
    if ( (v21 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 52), v19, v2 + 52);
    if ( v20 )
      *(_BYTE *)(v20 + 14) |= 1u;
    v22 = *(_DWORD *)(a1 + 72);
    if ( v22 == 1 || v22 && *(_DWORD *)(a1 + 24) != PsInitialSystemProcess )
    {
      v43 = *(_QWORD *)(a1 + 64);
      if ( *(_DWORD *)(v43 + 4) != a1 + 64 || *(_DWORD *)HIDWORD(v43) != a1 + 64 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v43) = v43;
      *(_DWORD *)(v43 + 4) = HIDWORD(v43);
      if ( v9 && (*(_DWORD *)(a1 + 76) & 1) != 0 )
      {
        __dmb(0xBu);
        v44 = (unsigned int *)(v9 + 92);
        do
        {
          v45 = __ldrex(v44);
          v46 = v45 - 1;
        }
        while ( __strex(v46, v44) );
        __dmb(0xBu);
        v10 = v46 == 0;
      }
    }
    *(_DWORD *)(a1 + 24) = 0;
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)v18);
    while ( __strex(v23 - 1, (unsigned int *)v18) );
    if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v2 + 52));
    KeAbPostRelease(v2 + 52);
    if ( v9 )
    {
      v24 = 0;
      if ( v11 || v10 )
      {
        v37 = (unsigned int *)(v9 + 4);
        __pld((void *)(v9 + 4));
        v38 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
        do
          v39 = __ldrex(v37);
        while ( v39 == v38 && __strex(v38 + 2, v37) );
        __dmb(0xBu);
        if ( v39 == v38 || ExfAcquireRundownProtection(v37) )
        {
          v24 = 1;
        }
        else
        {
          v11 = 0;
          v10 = 0;
        }
      }
      v25 = (unsigned int *)(v9 + 64);
      __dmb(0xBu);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - 1, v25) );
      if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v9 + 64));
      KeAbPostRelease(v9 + 64);
      if ( v2 )
      {
        v27 = (unsigned int *)(v2 + 40);
        __dmb(0xBu);
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 - 1, v27) );
        if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v2 + 40));
        KeAbPostRelease(v2 + 40);
        v2 = 0;
      }
      if ( v10 )
        ExpWnfNotifyNameSubscribers(v9, 8, 1, a2 != PsInitialSystemProcess);
      if ( v11 )
        ExpWnfNotifyNameSubscribers(v9, 4, 1, a2 != PsInitialSystemProcess);
      if ( v24 )
      {
        v40 = (unsigned int *)(v9 + 4);
        __pld((void *)(v9 + 4));
        v41 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v42 = __ldrex(v40);
        while ( v42 == v41 && __strex(v41 - 2, v40) );
        if ( v42 != v41 )
          ExfReleaseRundownProtection((unsigned __int8 *)v40);
      }
    }
    v29 = 1;
    result = 4;
  }
  else
  {
    v29 = 0;
  }
  if ( v2 )
  {
    v47 = (unsigned int *)(v2 + 40);
    __dmb(0xBu);
    do
      v48 = __ldrex(v47);
    while ( __strex(v48 - 1, v47) );
    if ( (v48 & 2) != 0 && (v48 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v2 + 40));
    result = KeAbPostRelease(v2 + 40);
  }
  v30 = (unsigned int *)(a1 + 4);
  __pld((void *)(a1 + 4));
  v31 = *(_DWORD *)(a1 + 4) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v32 = __ldrex(v30);
  while ( v32 == v31 && __strex(v31 - 2, v30) );
  if ( v32 != v31 )
    result = (int)ExfReleaseRundownProtection((unsigned __int8 *)(a1 + 4));
  if ( v29 )
  {
    do
      v33 = __ldrex(v30);
    while ( !v33 && __strex(1u, v30) );
    __dmb(0xBu);
    if ( v33 )
    {
      if ( v33 != 1 )
        ExfWaitForRundownProtectionRelease((unsigned int *)(a1 + 4), v33);
    }
    result = ExFreePoolWithTag(a1);
  }
  return result;
}
