// CmpTryToRundownHive 
 
int __fastcall CmpTryToRundownHive(int a1, _DWORD *a2, _BYTE *a3)
{
  int v3; // r6
  int v6; // r8
  int v7; // r10
  unsigned int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r1
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r0
  unsigned int v22; // r2
  unsigned int *v23; // r4
  unsigned int v24; // r1
  unsigned int v25; // r2
  int *v26; // r0
  unsigned int v27; // r4
  unsigned int v28; // r2
  unsigned int v29; // r1
  unsigned int v30; // r1
  int v31; // r3
  unsigned int v32; // r1
  int v33; // r3
  int v34; // r0
  int v35; // r4
  int v36; // r6
  int v37; // r4
  int v38; // r0
  unsigned int *v39; // r2
  unsigned int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r2
  unsigned int v43; // r0
  unsigned int v44; // r2
  unsigned int v45; // r1
  unsigned int v46; // r1
  __int16 v47; // r3
  char v48[4]; // [sp+0h] [bp-30h] BYREF
  int v49; // [sp+4h] [bp-2Ch]
  int v50[2]; // [sp+8h] [bp-28h] BYREF
  int v51; // [sp+10h] [bp-20h]

  v3 = 0;
  v50[0] = 0;
  v51 = (unsigned __int8)*a3;
  v6 = a1;
  v7 = 0;
  while ( 1 )
  {
    if ( *a3 )
    {
      __pld(&CmpShutdownRundown);
      v8 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      v9 = v8 - 2;
      do
        v10 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpShutdownRundown) );
      if ( v10 != v8 )
        return sub_519E9C(a1, v10, v9);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(a1);
    }
    *a3 = 0;
    v14 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v14 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v15 = CmpShutdownRundown & 0xFFFFFFFE;
    v16 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v15 && __strex(v16, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v17 != v15 )
    {
      v26 = (int *)ExfAcquireRundownProtection(&CmpShutdownRundown, v17, v16);
      if ( !v26 )
      {
        v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v33 = (__int16)(*(_WORD *)(v32 + 0x134) + 1);
        *(_WORD *)(v32 + 308) = v33;
        if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
          v26 = (int *)KiCheckForKernelApcDelivery(0);
        goto LABEL_34;
      }
    }
    *a3 = 1;
    if ( *a2 != 2 )
    {
      v26 = (int *)CmpSearchForOpenSubKeys(a2, 0, v16, 0);
      if ( v26 || *a2 != 2 )
        goto LABEL_34;
    }
    if ( !v7 )
    {
      a2[1] |= 0x40000u;
      v20 = CmpUnlockRegistry();
      v21 = UNLOCK_HIVE_LOAD(v20);
      __dmb(0xBu);
      do
        v22 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
      while ( __strex(v22 + 1, (unsigned int *)&CmpActiveHiveRundownCount) );
      __dmb(0xBu);
      v23 = (unsigned int *)(v6 + 1832);
      do
        v24 = __ldrex(v23);
      while ( !v24 && __strex(1u, v23) );
      __dmb(0xBu);
      if ( v24 && v24 != 1 )
        v21 = ExfWaitForRundownProtectionRelease(v6 + 1832, v24, 1);
      __dmb(0xBu);
      do
        v25 = __ldrex(v23);
      while ( __strex(1u, v23) );
      __dmb(0xBu);
      v7 = 1;
      goto LABEL_32;
    }
    if ( !*(_DWORD *)(v6 + 3256) || v3 )
      break;
    v26 = (int *)CmSnapshotRMTxArray();
    if ( (int)v26 < 0 )
      goto LABEL_34;
    v34 = CmpUnlockRegistry();
    v35 = v49;
    if ( v49 )
    {
      UNLOCK_HIVE_LOAD(v34);
      v21 = CmpRollbackTransactionArray(v35, v50[1], v48, v50);
      if ( v21 < 0 )
      {
        LOCK_HIVE_LOAD(v21);
        v26 = (int *)CmpLockRegistryFreezeAware(1);
LABEL_34:
        if ( v7 )
        {
          a2[1] &= 0xFFFBFFFF;
          __dmb(0xBu);
          v39 = (unsigned int *)(v6 + 1832);
          v26 = 0;
          do
            v40 = __ldrex(v39);
          while ( __strex(0, v39) );
          __dmb(0xBu);
          do
          {
            v41 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
            v42 = v41 - 1;
          }
          while ( __strex(v42, (unsigned int *)&CmpActiveHiveRundownCount) );
          __dmb(0xBu);
          if ( !v42 )
          {
            __dmb(0xFu);
            v26 = &CmpActiveHiveRundownEvent;
            if ( CmpActiveHiveRundownEvent )
              v26 = (int *)ExpUnblockPushLock();
          }
        }
        if ( *a3 )
        {
          __pld(&CmpShutdownRundown);
          v27 = CmpShutdownRundown & 0xFFFFFFFE;
          __dmb(0xBu);
          v28 = v27 - 2;
          do
            v29 = __ldrex((unsigned int *)&CmpShutdownRundown);
          while ( v29 == v27 && __strex(v28, (unsigned int *)&CmpShutdownRundown) );
          if ( v29 != v27 )
            v26 = (int *)ExfReleaseRundownProtection(&CmpShutdownRundown, v29, v28);
          v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v31 = (__int16)(*(_WORD *)(v30 + 0x134) + 1);
          *(_WORD *)(v30 + 308) = v31;
          if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
            KiCheckForKernelApcDelivery(v26);
          *a3 = 0;
        }
        return 0;
      }
      if ( v48[0] == 1 )
        v21 = CmObliterateRMTxArray(*(_DWORD *)(v6 + 3256));
LABEL_32:
      LOCK_HIVE_LOAD(v21);
      a1 = CmpLockRegistryFreezeAware(1);
    }
    else
    {
      v36 = CmCloseRmHandle(*(_DWORD *)(v6 + 3256), 0);
      v37 = CmCloseTmHandle(*(_DWORD *)(v6 + 3256));
      v38 = UNLOCK_HIVE_LOAD(v37);
      if ( v36 )
        v38 = ZwClose();
      if ( v37 )
        v38 = ZwClose();
      LOCK_HIVE_LOAD(v38);
      CmShutdownCmRM(*(_DWORD *)(v6 + 3256), 1);
      a1 = CmpLockRegistryFreezeAware(1);
      v3 = 1;
    }
  }
  __dmb(0xBu);
  do
  {
    v18 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
    v19 = v18 - 1;
  }
  while ( __strex(v19, (unsigned int *)&CmpActiveHiveRundownCount) );
  __dmb(0xBu);
  if ( !v19 )
  {
    __dmb(0xFu);
    if ( CmpActiveHiveRundownEvent )
      ExpUnblockPushLock();
  }
  if ( !v51 )
  {
    __pld(&CmpShutdownRundown);
    v43 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    v44 = v43 - 2;
    do
      v45 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v45 == v43 && __strex(v44, (unsigned int *)&CmpShutdownRundown) );
    if ( v45 != v43 )
      v43 = ExfReleaseRundownProtection(&CmpShutdownRundown, v45, v44);
    v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v47 = *(_WORD *)(v46 + 0x134) + 1;
    *(_WORD *)(v46 + 308) = v47;
    if ( !v47 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
      KiCheckForKernelApcDelivery(v43);
    *a3 = 0;
  }
  return 1;
}
