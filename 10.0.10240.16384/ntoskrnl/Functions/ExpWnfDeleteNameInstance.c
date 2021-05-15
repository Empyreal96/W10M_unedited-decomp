// ExpWnfDeleteNameInstance 
 
int __fastcall ExpWnfDeleteNameInstance(int a1, unsigned int a2, int a3)
{
  unsigned __int8 *v4; // r6
  int v7; // r0
  unsigned int v8; // r4
  unsigned __int8 *v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r3
  unsigned __int8 *v21; // r4
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  __int64 v25; // r0
  unsigned int v26; // r1
  unsigned int *v27; // r5
  unsigned int v28; // r4
  unsigned int v29; // r1
  unsigned int v30; // r1
  int result; // r0
  unsigned int v32; // r1
  int v33; // r9
  _DWORD *v34; // r6
  unsigned int v35; // r0
  unsigned int v36; // r1
  int v37; // r4
  unsigned int v38; // r1
  int v39; // r3
  unsigned __int8 *v40; // r8
  int v41; // r0
  int v42; // r4
  unsigned int v43; // r2
  int v44; // r0
  int v45; // r4
  unsigned int v46; // r2
  __int64 v47; // kr00_8
  unsigned int v48; // r1
  unsigned int v49; // r4
  unsigned int v50; // r1

  v4 = (unsigned __int8 *)(a1 + 28);
  v7 = KeAbPreAcquire(a1 + 28, 0, 0);
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 | 1, v4) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7BFCA8(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( *(_DWORD *)(a2 + 32) )
  {
    v9 = (unsigned __int8 *)(a2 + 64);
    v10 = KeAbPreAcquire(a2 + 64, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( __strex(v12 | 1, v9) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 64), v10, a2 + 64);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( a3 )
      RtlAvlRemoveNode(a1 + 32, a2 + 8);
    *(_DWORD *)(a2 + 32) = 0;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v9);
    while ( __strex(v13 - 1, (unsigned int *)v9) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a2 + 64));
    KeAbPostRelease(a2 + 64);
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v4);
    while ( __strex(v14 - 1, (unsigned int *)v4) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v4);
    KeAbPostRelease((unsigned int)v4);
    v15 = KeAbPreAcquire(a2 + 64, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex(v9);
    while ( __strex(v17 | 1, v9) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 64), v15, a2 + 64);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    while ( *(_DWORD *)(a2 + 68) != a2 + 68 )
    {
      v33 = *(_DWORD *)(a2 + 68) - 40;
      v34 = (_DWORD *)(*(_DWORD *)(a2 + 68) - 36);
      __pld(v34);
      v35 = *v34 & 0xFFFFFFFE;
      do
        v36 = __ldrex(v34);
      while ( v36 == v35 && __strex(v35 + 2, v34) );
      __dmb(0xBu);
      if ( v36 != v35 )
        ExfAcquireRundownProtection(v34);
      v37 = *(_DWORD *)(v33 + 24);
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)v9);
      while ( __strex(v38 - 1, (unsigned int *)v9) );
      if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(a2 + 64));
      KeAbPostRelease(a2 + 64);
      v39 = *(_DWORD *)(v37 + 724);
      __dmb(0xBu);
      v40 = (unsigned __int8 *)(v39 + 40);
      v41 = KeAbPreAcquire(v39 + 40, 0, 0);
      v42 = v41;
      do
        v43 = __ldrex(v40);
      while ( __strex(v43 | 1, v40) );
      __dmb(0xBu);
      if ( (v43 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v40, v41, (unsigned int)v40);
      if ( v42 )
        *(_BYTE *)(v42 + 14) |= 1u;
      v44 = KeAbPreAcquire(a2 + 64, 0, 0);
      v45 = v44;
      do
        v46 = __ldrex(v9);
      while ( __strex(v46 | 1, v9) );
      __dmb(0xBu);
      if ( (v46 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 64), v44, a2 + 64);
      if ( v45 )
        *(_BYTE *)(v45 + 14) |= 1u;
      if ( *(_DWORD *)(v33 + 28) )
      {
        v47 = *(_QWORD *)(v33 + 40);
        if ( *(_DWORD *)(v47 + 4) != v33 + 40 || *(_DWORD *)HIDWORD(v47) != v33 + 40 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v47) = v47;
        *(_DWORD *)(v47 + 4) = HIDWORD(v47);
        *(_DWORD *)(v33 + 28) = 0;
      }
      __dmb(0xBu);
      do
        v48 = __ldrex((unsigned int *)v40);
      while ( __strex(v48 - 1, (unsigned int *)v40) );
      if ( (v48 & 2) != 0 && (v48 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v40);
      KeAbPostRelease((unsigned int)v40);
      __pld(v34);
      v49 = *v34 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v50 = __ldrex(v34);
      while ( v50 == v49 && __strex(v49 - 2, v34) );
      if ( v50 != v49 )
        ExfReleaseRundownProtection((unsigned __int8 *)v34);
    }
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v9);
    while ( __strex(v18 - 1, (unsigned int *)v9) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a2 + 64));
    KeAbPostRelease(a2 + 64);
    v19 = *(_DWORD *)(a2 + 84);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 724);
      __dmb(0xBu);
      v21 = (unsigned __int8 *)(v20 + 28);
      v22 = KeAbPreAcquire(v20 + 28, 0, 0);
      v23 = v22;
      do
        v24 = __ldrex(v21);
      while ( __strex(v24 | 1, v21) );
      __dmb(0xBu);
      if ( (v24 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v21, v22, (unsigned int)v21);
      if ( v23 )
        *(_BYTE *)(v23 + 14) |= 1u;
      v25 = *(_QWORD *)(a2 + 76);
      if ( *(_DWORD *)(v25 + 4) != a2 + 76 || *(_DWORD *)HIDWORD(v25) != a2 + 76 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v25) = v25;
      *(_DWORD *)(v25 + 4) = HIDWORD(v25);
      *(_DWORD *)(a2 + 84) = 0;
      __dmb(0xBu);
      do
        v26 = __ldrex((unsigned int *)v21);
      while ( __strex(v26 - 1, (unsigned int *)v21) );
      if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v21);
      KeAbPostRelease((unsigned int)v21);
    }
    v27 = (unsigned int *)(a2 + 4);
    __pld((void *)(a2 + 4));
    v28 = *(_DWORD *)(a2 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v29 = __ldrex(v27);
    while ( v29 == v28 && __strex(v28 - 2, v27) );
    if ( v29 != v28 )
      ExfReleaseRundownProtection((unsigned __int8 *)(a2 + 4));
    do
      v30 = __ldrex(v27);
    while ( !v30 && __strex(1u, v27) );
    __dmb(0xBu);
    if ( v30 )
    {
      if ( v30 != 1 )
        ExfWaitForRundownProtectionRelease((unsigned int *)(a2 + 4), v30);
    }
    ExpWnfDeleteStateData(a2);
    ObDereferenceSecurityDescriptor(*(_DWORD *)(a2 + 44), 1);
    ExFreePoolWithTag(a2);
    result = 1;
  }
  else
  {
    __dmb(0xBu);
    do
      v32 = __ldrex((unsigned int *)v4);
    while ( __strex(v32 - 1, (unsigned int *)v4) );
    if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v4);
    KeAbPostRelease((unsigned int)v4);
    result = 0;
  }
  return result;
}
