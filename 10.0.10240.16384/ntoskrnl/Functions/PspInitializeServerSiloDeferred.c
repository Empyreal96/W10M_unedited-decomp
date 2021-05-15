// PspInitializeServerSiloDeferred 
 
int __fastcall PspInitializeServerSiloDeferred(int a1)
{
  int *v1; // r10
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  int *v6; // r5
  int *v7; // r9
  int v8; // r8
  int (__fastcall *v9)(void (__fastcall *)(int, int)); // r8
  int v10; // r3
  int v11; // r4
  int v12; // r2
  int v13; // r1
  int v14; // r3
  int v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int v26; // r2
  int v27; // r4
  unsigned int v28; // r2
  _DWORD *v29; // r4
  int *v30; // r5
  int *v31; // r9
  int v32; // r8
  void (__fastcall *v33)(int, int); // r2
  int v34; // r3
  int v35; // r4
  int v36; // r2
  int v37; // r1
  unsigned int v38; // r3
  int v39; // r3
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  int v44; // r10
  unsigned int *v45; // r0
  unsigned int v46; // r4
  unsigned int v47; // r1
  unsigned int v48; // r2
  int v49; // r0
  int v50; // r4
  unsigned int v51; // r2
  unsigned int v52; // r1
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  unsigned int *v56; // r0
  unsigned int v57; // r4
  unsigned int v58; // r1
  int *v60; // [sp+0h] [bp-30h]
  int v61; // [sp+4h] [bp-2Ch]
  int v62; // [sp+8h] [bp-28h] BYREF
  _DWORD *v63; // [sp+Ch] [bp-24h]
  void (__fastcall *v64)(int, int); // [sp+10h] [bp-20h]

  v64 = (void (__fastcall *)(int, int))a1;
  v1 = 0;
  v60 = 0;
  v63 = PsGetServerSiloGlobals(a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&SiloMonitorLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v3, (unsigned int)&SiloMonitorLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = (int *)SiloMonitorList;
  if ( (int *)SiloMonitorList == &SiloMonitorList )
    goto LABEL_53;
  do
  {
    v7 = v6;
    v8 = PspReferenceMonitorServerSilo((int)v6);
    v61 = v8;
    if ( v8 >= 0 )
      break;
    v6 = (int *)*v6;
  }
  while ( v6 != &SiloMonitorList );
  while ( v6 != &SiloMonitorList )
  {
    v9 = (int (__fastcall *)(void (__fastcall *)(int, int)))v7[8];
    v10 = v7[5];
    __dmb(0xBu);
    if ( (v10 & 1) != 0 && v9 )
    {
      v12 = v7[16];
      v13 = v63[8];
      v14 = *(_DWORD *)(v13 + 4 * v12);
      __dmb(0xBu);
      v11 = v14 & 1;
      if ( (v14 & 1) == 0 )
      {
        v15 = *(_DWORD *)(v13 + 4 * v12) | 1;
        __dmb(0xBu);
        *(_DWORD *)(v13 + 4 * v12) = v15;
      }
    }
    else
    {
      v11 = 1;
    }
    do
    {
      v6 = (int *)*v6;
      if ( v6 == &SiloMonitorList )
        break;
      v1 = v6;
      v60 = v6;
    }
    while ( PspReferenceMonitorServerSilo((int)v6) < 0 );
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&SiloMonitorLock);
    while ( __strex(v16 - 1, (unsigned int *)&SiloMonitorLock) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
    v17 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
    v8 = v11 ? 0 : v9(v64);
    v61 = v8;
    if ( v8 < 0 )
    {
      if ( v6 != &SiloMonitorList )
      {
        v23 = (unsigned int *)(v1 + 7);
        __pld(v1 + 7);
        v24 = v1[7] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v25 = __ldrex(v23);
        while ( v25 == v24 && __strex(v24 - 2, v23) );
        if ( v25 != v24 )
          ExfReleaseRundownProtection((unsigned __int8 *)v23);
      }
      v1 = v7;
      v60 = v7;
      v6 = v7;
    }
    else
    {
      v20 = (unsigned int *)(v7 + 7);
      __pld(v7 + 7);
      v21 = v7[7] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v22 = __ldrex(v20);
      while ( v22 == v21 && __strex(v21 - 2, v20) );
      if ( v22 != v21 )
        ExfReleaseRundownProtection((unsigned __int8 *)v20);
      v7 = v1;
    }
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v26 + 308);
    v27 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
    do
      v28 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
    while ( __strex(v28 | 1, (unsigned __int8 *)&SiloMonitorLock) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v27, (unsigned int)&SiloMonitorLock);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    if ( v8 < 0 )
      goto LABEL_54;
  }
  if ( v8 >= 0 )
  {
LABEL_53:
    v8 = PspTestErrorOnServerSiloInitialize;
    v61 = PspTestErrorOnServerSiloInitialize;
    __dmb(0xBu);
    if ( v8 >= 0 )
      goto LABEL_93;
  }
LABEL_54:
  v29 = v63;
  v63[14] = 2;
  v30 = (int *)v6[1];
  if ( v30 != &SiloMonitorList )
  {
    do
    {
      v31 = v30;
      if ( PspReferenceMonitorServerSilo((int)v30) >= 0 )
        break;
      v30 = (int *)v30[1];
    }
    while ( v30 != &SiloMonitorList );
    if ( v30 != &SiloMonitorList )
    {
      v32 = (int)v64;
      do
      {
        v33 = (void (__fastcall *)(int, int))v31[9];
        v34 = v31[5];
        v64 = v33;
        __dmb(0xBu);
        if ( (v34 & 1) != 0 && v33 )
        {
          v36 = v31[16];
          v37 = v29[8];
          v38 = *(_DWORD *)(v37 + 4 * v36);
          __dmb(0xBu);
          v35 = (v38 >> 1) & 1;
          if ( !v35 )
          {
            v39 = *(_DWORD *)(v37 + 4 * v36) | 2;
            __dmb(0xBu);
            *(_DWORD *)(v37 + 4 * v36) = v39;
          }
        }
        else
        {
          v35 = 1;
        }
        __dmb(0xBu);
        do
          v40 = __ldrex((unsigned int *)&SiloMonitorLock);
        while ( __strex(v40 - 1, (unsigned int *)&SiloMonitorLock) );
        if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
        v41 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
        v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v43 = *(_WORD *)(v42 + 0x134) + 1;
        *(_WORD *)(v42 + 308) = v43;
        if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
          KiCheckForKernelApcDelivery(v41);
        v44 = PsGetMonitorContextServerSilo((int)v31, v32, &v62);
        if ( !v35 )
          v64(v32, v62);
        if ( v44 >= 0 )
        {
          PsDeleteMonitorContextServerSilo(v62);
          PsDereferenceMonitorContextServerSilo(v62);
        }
        v45 = (unsigned int *)(v60 + 7);
        __pld(v60 + 7);
        v46 = *v45 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v47 = __ldrex(v45);
        while ( v47 == v46 && __strex(v46 - 2, v45) );
        if ( v47 != v46 )
          ExfReleaseRundownProtection((unsigned __int8 *)v45);
        v1 = v31;
        v60 = v31;
        v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v48 + 308);
        v49 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
        v50 = v49;
        do
          v51 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
        while ( __strex(v51 | 1, (unsigned __int8 *)&SiloMonitorLock) );
        __dmb(0xBu);
        if ( (v51 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v49, (unsigned int)&SiloMonitorLock);
        if ( v50 )
          *(_BYTE *)(v50 + 14) |= 1u;
        v30 = (int *)v30[1];
        if ( v30 == &SiloMonitorList )
          break;
        do
        {
          v31 = v30;
          if ( PspReferenceMonitorServerSilo((int)v30) >= 0 )
            break;
          v30 = (int *)v30[1];
        }
        while ( v30 != &SiloMonitorList );
        v29 = v63;
      }
      while ( v30 != &SiloMonitorList );
      v8 = v61;
    }
  }
LABEL_93:
  __dmb(0xBu);
  do
    v52 = __ldrex((unsigned int *)&SiloMonitorLock);
  while ( __strex(v52 - 1, (unsigned int *)&SiloMonitorLock) );
  if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
  v53 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
  v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v55 = *(_WORD *)(v54 + 0x134) + 1;
  *(_WORD *)(v54 + 308) = v55;
  if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
    KiCheckForKernelApcDelivery(v53);
  if ( v1 )
  {
    v56 = (unsigned int *)(v1 + 7);
    __pld(v1 + 7);
    v57 = v1[7] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v58 = __ldrex(v56);
    while ( v58 == v57 && __strex(v57 - 2, v56) );
    if ( v58 != v57 )
      ExfReleaseRundownProtection((unsigned __int8 *)v56);
  }
  return v8;
}
