// NtUnloadKeyEx 
 
int __fastcall NtUnloadKeyEx(int a1, int a2)
{
  int v4; // r8
  int v5; // r3
  unsigned int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v10; // r9
  int v11; // r6
  unsigned __int8 *v12; // r0
  int v13; // r0
  int v14; // r1
  int v15; // r4
  int v16; // r0
  int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r3
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r0
  char v27; // r8
  int *v28; // r0
  _DWORD *v29; // r6
  int v30; // r3
  int v31; // r9
  _DWORD *v32; // r2
  int v33; // r7
  int v34; // r10
  int v35; // r2
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int v38; // r1
  int v39; // r0
  unsigned int v40; // r1
  unsigned int v41; // r1
  int v42; // r3
  int v43; // r10
  int v44; // r4
  unsigned int v45; // r1
  __int16 v46; // r3
  unsigned int v47; // r4
  unsigned int v48; // r1
  unsigned int v49; // r1
  __int16 v50; // r3
  unsigned int v51; // r2
  unsigned int *v52; // r4
  unsigned int v53; // r1
  unsigned int v54; // r2
  unsigned int *v55; // r2
  unsigned int v56; // r1
  unsigned int v57; // r1
  int v58; // r4
  int v59; // r0
  int v60; // r4
  unsigned int v61; // r1
  __int16 v62; // r3
  unsigned int *v63; // r2
  unsigned int v64; // r1
  unsigned int *v65; // r2
  unsigned int v66; // r1
  unsigned int v67; // r1
  unsigned int v68; // r2
  unsigned int v69; // r2
  unsigned int v70; // r1
  unsigned int v71; // r1
  int v72; // r3
  int v73; // [sp+14h] [bp-CCh]
  char v74[8]; // [sp+18h] [bp-C8h] BYREF
  int v75[2]; // [sp+20h] [bp-C0h] BYREF
  int v76; // [sp+28h] [bp-B8h] BYREF
  int v77; // [sp+2Ch] [bp-B4h]
  int v78[2]; // [sp+30h] [bp-B0h] BYREF
  int v79; // [sp+38h] [bp-A8h]
  int v80; // [sp+3Ch] [bp-A4h] BYREF
  int v81; // [sp+40h] [bp-A0h]
  int v82; // [sp+44h] [bp-9Ch] BYREF
  int v83; // [sp+48h] [bp-98h] BYREF
  int v84; // [sp+4Ch] [bp-94h]
  int v85; // [sp+50h] [bp-90h] BYREF
  int v86; // [sp+58h] [bp-88h] BYREF
  int v87; // [sp+5Ch] [bp-84h]
  int v88; // [sp+60h] [bp-80h]
  int v89; // [sp+64h] [bp-7Ch]
  int v90; // [sp+68h] [bp-78h]
  int v91; // [sp+70h] [bp-70h]
  int v92[19]; // [sp+74h] [bp-6Ch] BYREF

  v91 = 0;
  memset(v92, 0, sizeof(v92));
  v4 = 0;
  v73 = 0;
  v79 = 0;
  v81 = 0;
  v86 = 0;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  v90 = 0;
  v85 = 0;
  v77 = 0;
  v5 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v6 = CmpShutdownRundown & 0xFFFFFFFE;
  v7 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v8 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v8 != v6 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    return sub_7F081C();
  v10 = 1;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v12 = (unsigned __int8 *)SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v11, (int)&SeRestorePrivilege);
  if ( !v12 )
  {
    __pld(&CmpShutdownRundown);
    v47 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v48 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v48 == v47 && __strex(v47 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v48 != v47 )
      v12 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v50 = *(_WORD *)(v49 + 0x134) + 1;
    *(_WORD *)(v49 + 308) = v50;
    if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
      KiCheckForKernelApcDelivery((int)v12);
    return -1073741727;
  }
  v92[4] = 4;
  v91 = 5;
  v13 = ObReferenceObjectByNameEx(a1);
  v15 = v13;
  if ( v13 < 0 )
    goto LABEL_135;
  if ( a2 )
  {
    v16 = ObReferenceObjectByHandle(a2, 2, ExEventObjectType, v11, (int)&v76, 0);
    v4 = v76;
    v15 = v16;
    v73 = v76;
    if ( v16 < 0 )
    {
      ObfDereferenceObject(0);
      goto LABEL_135;
    }
    v13 = KeResetEvent(v76);
  }
  v78[1] = (int)v78;
  v78[0] = (int)v78;
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v17 + 0x134);
  if ( CmpCallBackCount )
  {
    v13 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v14, v17, CmpCallBackCount);
    if ( !v13 )
    {
      v86 = 0;
      v87 = v4;
      v13 = CmpCallCallBacks(34, &v86, 1, 35, 0, v78);
      v15 = v13;
    }
  }
  if ( v15 >= 0 )
  {
    v75[1] = (int)v75;
    v75[0] = (int)v75;
    CmpLockRegistry();
    CmpRunDownDelayDerefKCBEngine(0);
    CmpUnlockRegistry();
    CmpDelayCloseWorker(1);
    v76 = 1;
    while ( 1 )
    {
      __pld(&CmpShutdownRundown);
      v18 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v19 == v18 && __strex(v18 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v19 != v18 )
        v18 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
      *(_WORD *)(v20 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
        KiCheckForKernelApcDelivery(v18);
      v22 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v22 & 0xFFFFFFC0) + 0x134);
      __pld(&CmpShutdownRundown);
      v23 = CmpShutdownRundown & 0xFFFFFFFE;
      v24 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
      do
        v25 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v25 == v23 && __strex(v24, (unsigned int *)&CmpShutdownRundown) );
      __dmb(0xBu);
      if ( v25 != v23 )
      {
        v26 = ExfAcquireRundownProtection(&CmpShutdownRundown);
        if ( !v26 )
          break;
      }
      v27 = 6;
      v80 = 6;
      LOCK_HIVE_LOAD();
      v28 = (int *)CmpLockRegistryFreezeAware(1);
      v29 = (_DWORD *)MEMORY[4];
      v30 = *(_DWORD *)(MEMORY[4] + 4);
      v31 = *(_DWORD *)(MEMORY[4] + 20);
      if ( (v30 & 0x80) != 0 )
      {
        v44 = -1073741790;
        v43 = v73;
        goto LABEL_44;
      }
      if ( (v30 & 0x20000) != 0 )
      {
        v43 = v73;
        if ( (MEMORY[0x18] & 1) != 0 )
          v44 = -1073740763;
        else
          v44 = -1073741444;
LABEL_44:
        if ( v77 )
        {
          if ( v44 < 0 )
          {
            v29[1] &= 0xFFFBFFFF;
            __dmb(0xBu);
            v63 = (unsigned int *)(v31 + 1832);
            v28 = 0;
            do
              v64 = __ldrex(v63);
            while ( __strex(0, v63) );
            __dmb(0xBu);
            v65 = (unsigned int *)(v31 + 3324);
            do
            {
              v66 = __ldrex(v65);
              v67 = v66 + 1;
            }
            while ( __strex(v67, v65) );
            __dmb(0xBu);
            *(_DWORD *)(v31 + 4 * ((v67 - 1) & 0x7F) + 3328) = 4;
          }
          __dmb(0xBu);
          do
          {
            v68 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
            v69 = v68 - 1;
          }
          while ( __strex(v69, (unsigned int *)&CmpActiveHiveRundownCount) );
          __dmb(0xBu);
          if ( !v69 )
          {
            __dmb(0xFu);
            v28 = &CmpActiveHiveRundownEvent;
            if ( CmpActiveHiveRundownEvent )
              v28 = (int *)ExfUnblockPushLock((int)&CmpActiveHiveRundownEvent, 0);
          }
        }
        goto LABEL_45;
      }
      if ( (v30 & 0x40000) != 0 && !v77 )
      {
        v44 = -1073740763;
        v43 = v73;
LABEL_45:
        if ( (v27 & 2) != 0 )
          CmpUnlockRegistry();
        if ( (v27 & 4) != 0 )
          v28 = (int *)UNLOCK_HIVE_LOAD();
        CmpCancelBootDisabledFlush(v28);
        CmpSignalDeferredPosts((unsigned int)v75);
        v13 = CmPostCallbackNotification(35, 0, v44);
        v10 = v76;
        v15 = v13;
        goto LABEL_50;
      }
      CmpReportNotify(MEMORY[4], (void (__fastcall **)(void *, int *))v31, *(_DWORD *)(MEMORY[4] + 24), 0, 4, (int)v75);
      v28 = (int *)CmpFlushNotify(0, 1, (int)v75);
      v32 = (_DWORD *)v29[5];
      v84 = 0;
      v33 = *(_DWORD *)(v31 + 3256);
      v34 = 0;
      if ( (v32[807] & 4) != 0 || v32 == CmpMasterHive || (v35 = *(_DWORD *)(v32[8] + 36), v35 != v29[6]) )
      {
        v43 = v73;
        if ( (*(_DWORD *)(v31 + 3228) & 4) != 0 )
          v44 = -1073741790;
        else
          v44 = -1073741811;
        goto LABEL_44;
      }
      if ( *v29 == 2 )
        goto LABEL_93;
      if ( CmpSearchForOpenSubKeys((int)v29, 0, v35, 0) || *v29 != 2 )
      {
        __dmb(0xBu);
        v36 = (unsigned int *)(v31 + 3324);
        do
        {
          v37 = __ldrex(v36);
          v38 = v37 + 1;
        }
        while ( __strex(v38, v36) );
        __dmb(0xBu);
        *(_DWORD *)(v31 + 4 * (((_BYTE)v38 - 1) & 0x7F) + 3328) = 5;
LABEL_37:
        __pld(&CmpShutdownRundown);
        v39 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v40 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v40 == v39 && __strex(v39 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v40 != v39 )
          v39 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v42 = (__int16)(*(_WORD *)(v41 + 0x134) + 1);
        *(_WORD *)(v41 + 308) = v42;
        if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
          KiCheckForKernelApcDelivery(v39);
        v43 = v73;
        v76 = 0;
        v28 = (int *)CmUnloadKeyEx(v29, v73, &v80);
        v27 = v80;
        v44 = (int)v28;
        goto LABEL_44;
      }
      if ( v77 )
      {
LABEL_93:
        if ( !v33 || v79 )
          goto LABEL_37;
        v28 = (int *)CmSnapshotRMTxArray(v33, &v83, &v82);
        v44 = (int)v28;
        if ( (int)v28 < 0 )
          goto LABEL_121;
        CmpUnlockRegistry();
        v58 = v83;
        if ( v83 )
        {
          UNLOCK_HIVE_LOAD();
          v27 = 0;
          v28 = (int *)CmpRollbackTransactionArray(v58, v82, v74, &v85);
          v44 = (int)v28;
          if ( (int)v28 < 0 )
          {
LABEL_121:
            v43 = v73;
            goto LABEL_44;
          }
          if ( v74[0] == 1 )
            CmObliterateRMTxArray(v33);
        }
        else
        {
          if ( v81 )
          {
            CmShutdownCmRM(v33, 1);
            v60 = v84;
            v79 = 1;
          }
          else
          {
            v34 = CmCloseRmHandle(v33, 0);
            v59 = CmCloseTmHandle(v33);
            v81 = 1;
            v60 = v59;
          }
          UNLOCK_HIVE_LOAD();
          if ( v34 )
            ZwClose();
          if ( v60 )
            ZwClose();
        }
      }
      else
      {
        v29[1] |= 0x40000u;
        CmpUnlockRegistry();
        UNLOCK_HIVE_LOAD();
        __dmb(0xBu);
        do
          v51 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
        while ( __strex(v51 + 1, (unsigned int *)&CmpActiveHiveRundownCount) );
        __dmb(0xBu);
        v52 = (unsigned int *)(v31 + 1832);
        do
          v53 = __ldrex(v52);
        while ( !v53 && __strex(1u, v52) );
        __dmb(0xBu);
        if ( v53 && v53 != 1 )
          ExfWaitForRundownProtectionRelease((unsigned int *)(v31 + 1832), v53);
        __dmb(0xBu);
        do
          v54 = __ldrex(v52);
        while ( __strex(1u, v52) );
        __dmb(0xBu);
        v55 = (unsigned int *)(v31 + 3324);
        do
        {
          v56 = __ldrex(v55);
          v57 = v56 + 1;
        }
        while ( __strex(v57, v55) );
        __dmb(0xBu);
        *(_DWORD *)(v31 + 4 * (((_BYTE)v57 - 1) & 0x7F) + 3328) = 3;
        v77 = 1;
      }
    }
    v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v62 = *(_WORD *)(v61 + 0x134) + 1;
    *(_WORD *)(v61 + 308) = v62;
    if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
      v26 = KiCheckForKernelApcDelivery(0);
    v15 = -1073741431;
    goto LABEL_140;
  }
  v43 = v73;
  if ( v15 == -1073740541 )
    v15 = 0;
LABEL_50:
  v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v46 = *(_WORD *)(v45 + 0x134) + 1;
  *(_WORD *)(v45 + 308) = v46;
  if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
    KiCheckForKernelApcDelivery(v13);
  ObfDereferenceObject(0);
  if ( v43 )
    ObfDereferenceObject(v43);
  if ( !v10 )
    return v15;
LABEL_135:
  __pld(&CmpShutdownRundown);
  v26 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v70 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v70 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v70 != v26 )
    v26 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
LABEL_140:
  v71 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v72 = (__int16)(*(_WORD *)(v71 + 0x134) + 1);
  *(_WORD *)(v71 + 308) = v72;
  if ( !v72 && *(_DWORD *)(v71 + 100) != v71 + 100 && !*(_WORD *)(v71 + 310) )
    KiCheckForKernelApcDelivery(v26);
  return v15;
}
