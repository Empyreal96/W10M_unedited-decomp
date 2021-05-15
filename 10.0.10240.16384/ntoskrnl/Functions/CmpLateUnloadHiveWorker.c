// CmpLateUnloadHiveWorker 
 
int __fastcall CmpLateUnloadHiveWorker(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  unsigned int *v6; // r7
  unsigned int v7; // r2
  unsigned int v8; // r2
  _DWORD *v9; // r8
  int v10; // r3
  unsigned int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r3
  int *v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r1
  int v21; // r0
  int result; // r0
  unsigned int v23; // r1
  bool v24; // zf
  unsigned int v25; // r1
  __int16 v26; // r3
  unsigned int v27; // r1
  int v28; // r3
  unsigned int v29; // r2
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r4
  unsigned int v33; // r1
  int v34; // r3
  int v35; // r3
  int v36; // r0
  unsigned int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r1
  int v40; // r3
  _DWORD v41[8]; // [sp+0h] [bp-20h] BYREF

  v41[0] = a2;
  v41[2] = a4;
  v41[1] = 2;
  LOCK_HIVE_LOAD(a1);
  v5 = CmpLockRegistryFreezeAware(1);
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 3324);
  do
  {
    v7 = __ldrex(v6);
    v8 = v7 + 1;
  }
  while ( __strex(v8, v6) );
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4 * (((_BYTE)v8 - 1) & 0x7F) + 3328) = 22;
  v9 = *(_DWORD **)(a1 + 2528);
  if ( (*(_DWORD *)(a1 + 92) & 0x40) != 0 )
    return sub_7D1D70(v5);
  v10 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v10 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v11 = CmpShutdownRundown & 0xFFFFFFFE;
  v12 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v13 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v13 != v11 )
  {
    v11 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v11 )
    {
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = (__int16)(*(_WORD *)(v27 + 0x134) + 1);
      *(_WORD *)(v27 + 308) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
        JUMPOUT(0x7D1D8C);
      JUMPOUT(0x7D1D90);
    }
  }
  LOBYTE(v41[0]) = 1;
  if ( *(_BYTE *)(a1 + 2532) )
  {
    if ( (*(_DWORD *)(a1 + 3228) & 0x20) != 0 )
    {
      v14 = CmpActiveAppHiveUnloadCount + 1;
      __dmb(0xBu);
      CmpActiveAppHiveUnloadCount = v14;
    }
    v15 = (int *)CmpTryToRundownHive(a1, v9, v41);
    if ( !v15 )
    {
      *(_DWORD *)(a1 + 2536) = 0;
      if ( (*(_DWORD *)(a1 + 3228) & 0x20) != 0 )
      {
        v34 = CmpActiveAppHiveUnloadCount - 1;
        __dmb(0xBu);
        CmpActiveAppHiveUnloadCount = v34;
        v35 = CmpActiveAppHiveUnloadCount;
        __dmb(0xBu);
        if ( !v35 )
        {
          __dmb(0xFu);
          v15 = &CmpActiveAppHiveUnloadEvent;
          if ( CmpActiveAppHiveUnloadEvent )
            v15 = (int *)ExfUnblockPushLock((int)&CmpActiveAppHiveUnloadEvent, 0);
        }
      }
      v36 = CmpUnlockRegistry(v15);
      UNLOCK_HIVE_LOAD(v36);
      if ( LOBYTE(v41[0]) )
      {
        __pld(&CmpShutdownRundown);
        v37 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v38 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v38 == v37 && __strex(v37 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v38 != v37 )
          ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v40 = (__int16)(*(_WORD *)(v39 + 0x134) + 1);
        *(_WORD *)(v39 + 308) = v40;
        if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
          JUMPOUT(0x7D1DC0);
      }
      JUMPOUT(0x7D1DC4);
    }
    v16 = *(_DWORD *)(a1 + 2528);
    *(_DWORD *)(a1 + 2536) = 0;
    __dmb(0xBu);
    do
    {
      v17 = __ldrex(v6);
      v18 = v17 + 1;
    }
    while ( __strex(v18, v6) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 4 * (((_BYTE)v18 - 1) & 0x7F) + 3328) = 30;
    v19 = CmUnloadKey(v16);
    if ( v19 >= 0 )
    {
      CmpLockRegistry(v19, v20);
      v19 = CmpDereferenceKeyControlBlock(v16);
    }
    v21 = CmpUnlockRegistry(v19);
    UNLOCK_HIVE_LOAD(v21);
    CmpDereferenceHive((_DWORD *)a1);
    __pld(&CmpShutdownRundown);
    result = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v23 == result && __strex(result - 2, (unsigned int *)&CmpShutdownRundown) );
    v24 = v23 == result;
  }
  else
  {
    __dmb(0xBu);
    do
    {
      v29 = __ldrex(v6);
      v30 = v29 + 1;
    }
    while ( __strex(v30, v6) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 4 * (((_BYTE)v30 - 1) & 0x7F) + 3328) = 25;
    v31 = CmpUnlockRegistry(v11);
    UNLOCK_HIVE_LOAD(v31);
    result = (int)CmpDereferenceHive((_DWORD *)a1);
    __pld(&CmpShutdownRundown);
    v32 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v33 == v32 && __strex(v32 - 2, (unsigned int *)&CmpShutdownRundown) );
    v24 = v33 == v32;
  }
  if ( !v24 )
    result = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x134) + 1;
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
