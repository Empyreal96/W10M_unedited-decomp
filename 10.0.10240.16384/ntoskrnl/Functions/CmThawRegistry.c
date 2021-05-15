// CmThawRegistry 
 
int CmThawRegistry()
{
  int v0; // r10
  int v1; // r3
  unsigned int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r1
  int v5; // r8
  _DWORD *v6; // r6
  _DWORD *v7; // r2
  _DWORD *v8; // r4
  _DWORD *v9; // r5
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r3
  _DWORD *v15; // r5
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  _DWORD *v20; // r3
  _DWORD *v21; // r5
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r5
  unsigned int v28; // r10
  int v29; // r0
  int v30; // r4
  unsigned __int64 v31; // r2
  unsigned int *v32; // r4
  unsigned int v33; // r1
  int v34; // r0
  int v35; // r6
  unsigned int v36; // r2
  int v37; // r6
  __int64 v38; // r2
  int v39; // r1
  unsigned int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  int v43; // r0
  unsigned int v44; // r1
  unsigned int v45; // r1
  __int16 v46; // r3
  unsigned int v48; // r2

  v0 = 0;
  KeCancelTimer((int)CmpFreezeThawTimer);
  CmpLockRegistryExclusive();
  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v2 = CmpShutdownRundown & 0xFFFFFFFE;
  v3 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v4 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v4 == v2 && __strex(v3, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v4 == v2 )
  {
    v5 = 1;
  }
  else
  {
    v5 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v5 )
    {
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v42 = *(_WORD *)(v41 + 0x134) + 1;
      *(_WORD *)(v41 + 308) = v42;
      if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
        KiCheckForKernelApcDelivery(0);
      goto LABEL_42;
    }
  }
  if ( CmpFreezeThawState != 1 )
  {
LABEL_42:
    v0 = -1073741431;
    goto LABEL_43;
  }
  v6 = (_DWORD *)CmpGetNextActiveHive(0);
  if ( v6 )
  {
    do
    {
      v7 = (_DWORD *)v6[8];
      if ( !v7[41] )
      {
        v8 = v7 + 1014;
        v9 = v7 + 28;
        v10 = v7[1014];
        v11 = v7[1015];
        v12 = v7[1016];
        v13 = v8[3];
        *v9 = v10;
        v9[1] = v11;
        v9[2] = v12;
        v9[3] = v13;
        v14 = (_DWORD *)v6[8];
        v15 = v14 + 37;
        v16 = v14[1010];
        v17 = v14[1011];
        v18 = v14[1012];
        v19 = v14[1013];
        *v15 = v16;
        v15[1] = v17;
        v15[2] = v18;
        v15[3] = v19;
        v20 = (_DWORD *)v6[8];
        v21 = v20 + 32;
        v22 = v20[1018];
        v23 = v20[1019];
        v24 = v20[1020];
        v25 = v20[1021];
        *v21 = v22;
        v21[1] = v23;
        v21[2] = v24;
        v21[3] = v25;
        *(_DWORD *)(v6[8] + 164) = 1836346738;
        v26 = v6[807];
        if ( ((v26 & 0x200) != 0 || (v26 & 0x100) == 0) && !v6[11] )
        {
          v27 = v6[467];
          v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v29 = KeAbPreAcquire(v27, 0, 0);
          v30 = v29;
          do
          {
            LODWORD(v31) = __ldrex((unsigned __int8 *)v27);
            HIDWORD(v31) = __strex(v31 & 0xFE, (unsigned __int8 *)v27);
          }
          while ( HIDWORD(v31) );
          __dmb(0xBu);
          if ( (v31 & 1) == 0 )
            ExpAcquireFastMutexContended(v27, v29);
          if ( v30 )
          {
            HIDWORD(v31) = *(unsigned __int8 *)(v30 + 14) | 1;
            *(_BYTE *)(v30 + 14) = BYTE4(v31);
          }
          *(_DWORD *)(v27 + 4) = v28;
          HvMarkBaseBlockDirty((int)v6, v31);
          v32 = (unsigned int *)v6[467];
          v32[1] = 0;
          __dmb(0xBu);
          do
            v33 = __ldrex(v32);
          while ( !v33 && __strex(1u, v32) );
          if ( v33 )
            ExpReleaseFastMutexContended(v32, v33);
          KeAbPostRelease((unsigned int)v32);
        }
      }
      v6 = (_DWORD *)CmpGetNextActiveHive((int)v6);
    }
    while ( v6 );
    v0 = 0;
  }
  while ( (int *)CmpFreezeThawWaitListHead != &CmpFreezeThawWaitListHead )
  {
    v34 = KeAbPreAcquire((unsigned int)&CmpFreezeListLock, 0, 0);
    v35 = v34;
    do
      v36 = __ldrex((unsigned __int8 *)&CmpFreezeListLock);
    while ( __strex(v36 | 1, (unsigned __int8 *)&CmpFreezeListLock) );
    __dmb(0xBu);
    if ( (v36 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CmpFreezeListLock, v34, (unsigned int)&CmpFreezeListLock);
    if ( v35 )
      *(_BYTE *)(v35 + 14) |= 1u;
    v37 = CmpFreezeThawWaitListHead;
    v38 = *(_QWORD *)CmpFreezeThawWaitListHead;
    if ( *(int **)(CmpFreezeThawWaitListHead + 4) != &CmpFreezeThawWaitListHead
      || *(_DWORD *)(v38 + 4) != CmpFreezeThawWaitListHead )
    {
      __fastfail(3u);
    }
    CmpFreezeThawWaitListHead = *(_DWORD *)CmpFreezeThawWaitListHead;
    *(_DWORD *)(v38 + 4) = &CmpFreezeThawWaitListHead;
    __pld(&CmpFreezeListLock);
    v39 = CmpFreezeListLock;
    if ( (CmpFreezeListLock & 0xFFFFFFF0) <= 0x10 )
      v40 = 0;
    else
      v40 = CmpFreezeListLock - 16;
    if ( (CmpFreezeListLock & 2) != 0 )
      goto LABEL_60;
    __dmb(0xBu);
    do
      v48 = __ldrex((unsigned int *)&CmpFreezeListLock);
    while ( v48 == v39 && __strex(v40, (unsigned int *)&CmpFreezeListLock) );
    if ( v48 != v39 )
LABEL_60:
      ExfReleasePushLock(&CmpFreezeListLock, v39);
    KeAbPostRelease((unsigned int)&CmpFreezeListLock);
    KeSetEvent(v37 + 8, 0, 0);
  }
  CmpFreezeThawState = 0;
  CmpEnableLazyFlush(2);
LABEL_43:
  CmpUnlockRegistry();
  if ( v5 )
  {
    __pld(&CmpShutdownRundown);
    v43 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v44 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v44 == v43 && __strex(v43 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v44 != v43 )
      v43 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v46 = *(_WORD *)(v45 + 0x134) + 1;
    *(_WORD *)(v45 + 308) = v46;
    if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
      KiCheckForKernelApcDelivery(v43);
  }
  return v0;
}
