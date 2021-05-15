// ExpWnfSubscribeNameInstance 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpWnfSubscribeNameInstance(int a1, int a2, int a3, int a4, int a5, int a6, char a7, unsigned __int64 *a8, unsigned int *a9, unsigned int *a10, _DWORD *a11)
{
  int v11; // r4
  int v13; // r10
  _BYTE *v14; // r0
  unsigned int v15; // r5
  int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r4 OVERLAPPED
  int v22; // r3
  unsigned int *v23; // r8
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r1
  unsigned __int64 v29; // r8
  unsigned __int64 v30; // r8
  unsigned __int8 *v31; // r7
  int v32; // r0
  int v33; // r4
  unsigned int v34; // r2
  unsigned __int8 *v35; // r6
  int v36; // r0
  int v37; // r4
  unsigned int v38; // r2
  unsigned int v39; // r1
  unsigned int v40; // r0
  unsigned int v41; // r1
  unsigned int v42; // r1
  int v43; // r3
  unsigned int v44; // r4
  unsigned int v45; // r1
  unsigned int v46; // r1
  int v47; // r2
  unsigned int *v48; // r0
  int v49; // r4
  unsigned int *v50; // r0
  unsigned int v51; // r2
  unsigned int v52; // r1
  unsigned int v53; // r1
  int v54; // r6
  int v55; // [sp+18h] [bp-48h] BYREF
  int v56; // [sp+1Ch] [bp-44h] BYREF
  int v57; // [sp+20h] [bp-40h]
  int v58; // [sp+24h] [bp-3Ch]
  int v59; // [sp+28h] [bp-38h]
  int v60; // [sp+2Ch] [bp-34h]
  unsigned int v61; // [sp+30h] [bp-30h] BYREF
  unsigned __int64 v62; // [sp+34h] [bp-2Ch]
  int v63; // [sp+3Ch] [bp-24h]
  int v64; // [sp+40h] [bp-20h]

  v11 = *(_DWORD *)(a2 + 724);
  v59 = a4;
  v60 = a3;
  v57 = v11;
  v58 = a1;
  v64 = a2;
  __dmb(0xBu);
  v13 = 0;
  v63 = 0;
  v55 = 0;
  v56 = 0;
  *a11 = 0;
  if ( a7 == 1 )
    return sub_7C4058();
  if ( PsInitialSystemProcess == v64 )
    v14 = (_BYTE *)ExAllocatePoolWithTag(1, 88, 543583831);
  else
    v14 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, 0x58u, 543583831);
  v15 = (unsigned int)v14;
  if ( !v14 )
    return -1073741670;
  memset(v14, 0, 88);
  *(_WORD *)v15 = 2309;
  *(_WORD *)(v15 + 2) = 88;
  *(_DWORD *)(v15 + 48) = v60;
  *(_DWORD *)(v15 + 52) = v59;
  *(_DWORD *)(v15 + 56) = a5;
  *(_DWORD *)(v15 + 60) = a6;
  *(_DWORD *)(v15 + 4) = 0;
  *(_DWORD *)(v15 + 32) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(v15 + 36) = *(_DWORD *)(a1 + 28);
  if ( a7 )
  {
    do
    {
      __dmb(0xBu);
      do
      {
        v29 = __ldrexd(&ExpWnfSubcriptionIdCounter);
        v30 = v29 + 1;
      }
      while ( __strexd(v30, &ExpWnfSubcriptionIdCounter) );
      v62 = v30;
      __dmb(0xBu);
    }
    while ( !v30 );
    if ( a8 )
      *a8 = v62;
  }
  else
  {
    v62 = v15;
    if ( a9 )
      *a9 = v15;
  }
  v31 = (unsigned __int8 *)(v11 + 40);
  v32 = KeAbPreAcquire(v11 + 40, 0, 0);
  v33 = v32;
  do
    v34 = __ldrex(v31);
  while ( __strex(v34 | 1, v31) );
  __dmb(0xBu);
  if ( (v34 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v31, v32, (unsigned int)v31);
  if ( v33 )
    *(_BYTE *)(v33 + 14) |= 1u;
  v35 = (unsigned __int8 *)(a1 + 64);
  v36 = KeAbPreAcquire((unsigned int)v35, 0, 0);
  v37 = v36;
  do
    v38 = __ldrex(v35);
  while ( __strex(v38 | 1, v35) );
  __dmb(0xBu);
  if ( (v38 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v35, v36, (unsigned int)v35);
  if ( v37 )
    *(_BYTE *)(v37 + 14) |= 1u;
  v21 = v58;
  if ( *(_DWORD *)(v58 + 32) )
  {
    if ( a7 == 1 )
    {
      if ( ExpWnfUpdateSubscription(v58, v57, v60, v59, a6, &v61, &v55, &v56, a8) >= 0 )
      {
        __dmb(0xBu);
        do
          v41 = __ldrex((unsigned int *)v35);
        while ( __strex(v41 - 1, (unsigned int *)v35) );
        if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v35);
        KeAbPostRelease((unsigned int)v35);
        __dmb(0xBu);
        do
          v42 = __ldrex((unsigned int *)v31);
        while ( __strex(v42 - 1, (unsigned int *)v31) );
        if ( (v42 & 2) != 0 && (v42 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v31);
        KeAbPostRelease((unsigned int)v31);
        ExFreePoolWithTag(v15);
        v13 = v55;
        *a10 = v61;
        v43 = v56;
        goto LABEL_100;
      }
      v13 = v55;
      v63 = v56;
    }
    v22 = v64;
    v23 = (unsigned int *)(v15 + 4);
    __pld((void *)(v15 + 4));
    *(_QWORD *)(v15 + 24) = *(_QWORD *)(&v21 - 1);
    *(_QWORD *)(v15 + 8) = v62;
    v24 = *(_DWORD *)(v15 + 4) & 0xFFFFFFFE;
    do
      v25 = __ldrex(v23);
    while ( v25 == v24 && __strex(v24 + 2, v23) );
    __dmb(0xBu);
    if ( v25 != v24 )
      ExfAcquireRundownProtection((_DWORD *)(v15 + 4));
    if ( a9 )
    {
      __pld(v23);
      v44 = *v23 & 0xFFFFFFFE;
      do
        v45 = __ldrex(v23);
      while ( v45 == v44 && __strex(v44 + 2, v23) );
      __dmb(0xBu);
      if ( v45 != v44 )
        ExfAcquireRundownProtection((_DWORD *)(v15 + 4));
    }
    v46 = v15 + 16;
    v47 = v57 + 44;
    v48 = *(unsigned int **)(v57 + 48);
    *(_DWORD *)(v15 + 16) = v57 + 44;
    *(_DWORD *)(v15 + 20) = v48;
    if ( *v48 != v47 )
      __fastfail(3u);
    v49 = v58;
    *v48 = v46;
    *(_DWORD *)(v47 + 4) = v46;
    v50 = *(unsigned int **)(v49 + 72);
    v51 = v15 + 40;
    *(_DWORD *)(v15 + 40) = v49 + 68;
    *(_DWORD *)(v15 + 44) = v50;
    if ( *v50 != v49 + 68 )
      __fastfail(3u);
    *v50 = v51;
    *(_DWORD *)(v49 + 72) = v51;
    if ( (*(_DWORD *)(v15 + 60) & 1) != 0 )
    {
      __dmb(0xBu);
      v26 = (unsigned int *)(v49 + 88);
      do
      {
        v27 = __ldrex(v26);
        v28 = v27 + 1;
      }
      while ( __strex(v28, v26) );
      __dmb(0xBu);
      if ( v28 == 1 )
        v13 = 1;
    }
    __dmb(0xBu);
    do
      v52 = __ldrex((unsigned int *)v35);
    while ( __strex(v52 - 1, (unsigned int *)v35) );
    if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v35);
    KeAbPostRelease((unsigned int)v35);
    __dmb(0xBu);
    do
      v53 = __ldrex((unsigned int *)v31);
    while ( __strex(v53 - 1, (unsigned int *)v31) );
    if ( (v53 & 2) != 0 && (v53 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v31);
    KeAbPostRelease((unsigned int)v31);
    *a10 = v15;
    v43 = v63;
LABEL_100:
    v54 = v58;
    v17 = 0;
    if ( v43 < 0 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(v54 + 92);
      do
      {
        v19 = __ldrex(v18);
        v20 = v19 - 1;
      }
      while ( __strex(v20, v18) );
      __dmb(0xBu);
      if ( !v20 )
        v17 = 8;
    }
    if ( v13 > 0 )
    {
      v17 |= 2u;
    }
    else if ( v13 < 0 )
    {
      v17 |= 4u;
    }
    if ( v17 )
    {
      ExpWnfNotifyNameSubscribers(v54, v17, 1, a7 != 0);
      *a11 = 1;
    }
    return 0;
  }
  __dmb(0xBu);
  do
    v39 = __ldrex((unsigned int *)v35);
  while ( __strex(v39 - 1, (unsigned int *)v35) );
  if ( (v39 & 2) != 0 && (v39 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v35);
  KeAbPostRelease((unsigned int)v35);
  __dmb(0xBu);
  do
    v40 = __ldrex((unsigned int *)v31);
  while ( __strex(v40 - 1, (unsigned int *)v31) );
  if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v31);
  KeAbPostRelease((unsigned int)v31);
  ExFreePoolWithTag(v15);
  return -1073741772;
}
