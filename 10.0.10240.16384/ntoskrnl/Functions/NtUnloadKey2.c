// NtUnloadKey2 
 
int __fastcall NtUnloadKey2(int a1, int a2)
{
  int v2; // r10
  int v4; // r8
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned __int8 *v10; // r0
  int v11; // r1
  int v12; // r1
  int v13; // r4
  int v14; // r2
  int v15; // r7
  int v16; // r0
  unsigned int v17; // r2
  unsigned int *v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  int v24; // r5
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r9
  int v30; // r3
  unsigned int v31; // r0
  unsigned int v32; // r2
  unsigned int v33; // r1
  int v34; // r0
  _DWORD *v35; // r4
  int v36; // r3
  _DWORD *v37; // r2
  int v38; // r7
  int v39; // r9
  int v40; // r10
  int v41; // r2
  int v42; // r0
  int v43; // r4
  unsigned int v44; // r2
  unsigned int v45; // r2
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r1
  __int16 v52; // r3
  unsigned int v54; // r4
  unsigned int v55; // r1
  unsigned int v56; // r1
  __int16 v57; // r3
  int v58; // r0
  unsigned int v59; // r1
  int v60; // r3
  unsigned int v61; // r1
  __int16 v62; // r3
  int v63; // r0
  unsigned int *v64; // r2
  unsigned int v65; // r1
  unsigned int v66; // r1
  int v67; // r3
  int v68; // r0
  int v69; // r0
  int v70; // r4
  int v71; // r0
  unsigned int *v72; // r2
  unsigned int v73; // r1
  unsigned int v74; // r1
  int v75; // r7
  int v76; // r3
  int v77; // r3
  int v78; // r3
  unsigned int *v79; // r2
  unsigned int v80; // r1
  unsigned int *v81; // r2
  unsigned int v82; // r1
  unsigned int v83; // r1
  int v84; // [sp+10h] [bp-E0h] BYREF
  int v85; // [sp+14h] [bp-DCh]
  int v86; // [sp+18h] [bp-D8h]
  int v87; // [sp+1Ch] [bp-D4h]
  char v88[4]; // [sp+20h] [bp-D0h] BYREF
  int v89; // [sp+24h] [bp-CCh]
  int v90; // [sp+28h] [bp-C8h]
  _DWORD *v91; // [sp+2Ch] [bp-C4h]
  int v92[2]; // [sp+30h] [bp-C0h] BYREF
  int v93; // [sp+38h] [bp-B8h] BYREF
  int v94; // [sp+3Ch] [bp-B4h]
  int v95[2]; // [sp+40h] [bp-B0h] BYREF
  int v96; // [sp+48h] [bp-A8h]
  int v97; // [sp+50h] [bp-A0h] BYREF
  int v98; // [sp+54h] [bp-9Ch]
  int v99; // [sp+58h] [bp-98h]
  int v100; // [sp+5Ch] [bp-94h] BYREF
  int v101; // [sp+60h] [bp-90h] BYREF
  int v102[6]; // [sp+68h] [bp-88h] BYREF
  int v103; // [sp+80h] [bp-70h] BYREF
  int v104[19]; // [sp+84h] [bp-6Ch] BYREF

  v2 = a2;
  v86 = a2;
  v84 = 0;
  v103 = 0;
  memset(v104, 0, sizeof(v104));
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v102[0] = 0;
  v102[1] = 0;
  v102[2] = 0;
  v102[3] = 0;
  v102[4] = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v4 = 0;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 != v7 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    return sub_7D1614();
  v10 = (unsigned __int8 *)SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v5, (int)&SeRestorePrivilege);
  if ( !v10 )
  {
    __pld(&CmpShutdownRundown);
    v54 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v55 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v55 == v54 && __strex(v54 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v55 != v54 )
      v10 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v57 = *(_WORD *)(v56 + 0x134) + 1;
    *(_WORD *)(v56 + 308) = v57;
    if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
      KiCheckForKernelApcDelivery((int)v10);
    return -1073741727;
  }
  v104[4] = 4;
  v103 = 5;
  v13 = ObReferenceObjectByNameEx(a1, v11, 131078, CmKeyObjectType, v5, &v103, &v84);
  if ( v13 < 0 )
    goto LABEL_68;
  v95[1] = (int)v95;
  v95[0] = (int)v95;
  v92[1] = (int)v92;
  v92[0] = (int)v92;
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 0x134);
  v15 = v84;
  if ( CmpCallBackCount )
  {
    if ( !ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v12, v14, CmpCallBackCount) )
    {
      v102[0] = v15;
      v13 = CmpCallCallBacks(34, v102, 1, 35, v15, v95);
      if ( v13 < 0 )
      {
        v58 = ObfDereferenceObject(v15);
        if ( v13 == -1073740541 )
          v13 = 0;
        v59 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v60 = (__int16)(*(_WORD *)(v59 + 0x134) + 1);
        *(_WORD *)(v59 + 308) = v60;
        if ( !v60 && *(_DWORD *)(v59 + 100) != v59 + 100 && !*(_WORD *)(v59 + 310) )
          KiCheckForKernelApcDelivery(v58);
        goto LABEL_68;
      }
    }
  }
  while ( 1 )
  {
    v24 = 0;
    __pld(&CmpShutdownRundown);
    v85 = 0;
    v25 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v26 == v25 && __strex(v25 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v26 != v25 )
      v25 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = *(_WORD *)(v27 + 0x134) + 1;
    *(_WORD *)(v27 + 308) = v28;
    if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
      KiCheckForKernelApcDelivery(v25);
    v29 = 0;
    v30 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v30 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v31 = CmpShutdownRundown & 0xFFFFFFFE;
    v32 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v33 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v33 == v31 && __strex(v32, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v33 != v31 )
    {
      v31 = ExfAcquireRundownProtection(&CmpShutdownRundown);
      if ( !v31 )
      {
        v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v62 = *(_WORD *)(v61 + 0x134) + 1;
        *(_WORD *)(v61 + 308) = v62;
        if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
          KiCheckForKernelApcDelivery(0);
        v43 = -1073741431;
        goto LABEL_52;
      }
    }
    v29 = 1;
    v24 = 6;
    v87 = 1;
    v85 = 6;
    LOCK_HIVE_LOAD(v31);
    v34 = CmpLockRegistryFreezeAware(1);
    v35 = *(_DWORD **)(v15 + 4);
    v36 = v35[1];
    v4 = v35[5];
    v91 = v35;
    if ( (v36 & 0x80) != 0 )
    {
      v43 = -1073741790;
      goto LABEL_52;
    }
    if ( (v36 & 0x20000) != 0 )
    {
      if ( (*(_DWORD *)(v15 + 24) & 1) != 0 )
        v43 = -1073740763;
      else
        v43 = -1073741444;
      goto LABEL_52;
    }
    if ( (v36 & 0x40000) != 0 && !v89 )
    {
      v43 = -1073740763;
      goto LABEL_61;
    }
    if ( *(_BYTE *)(v4 + 2532) == 1 && ((*(_DWORD *)(v4 + 3228) & 0x20) == 0 || v2 != 1) )
      break;
    CmpReportNotify(v35, v4, v35[6], 0, 4, v92);
    CmpFlushNotify(v15, v2 == 1, v92);
    v37 = (_DWORD *)v35[5];
    v38 = *(_DWORD *)(v4 + 3256);
    v39 = 0;
    v34 = 4;
    v40 = 0;
    if ( (v37[807] & 4) != 0 || v37 == CmpMasterHive || (v41 = *(_DWORD *)(v37[8] + 36), v41 != v35[6]) )
    {
      v29 = v87;
      if ( (*(_DWORD *)(v4 + 3228) & 4) != 0 )
        v43 = -1073741790;
      else
        v43 = -1073741811;
      goto LABEL_53;
    }
    if ( v86 != 1 )
    {
      if ( *v35 == 2 )
        goto LABEL_48;
      v34 = CmpSearchForOpenSubKeys((int)v35, 0, v41, 0);
      if ( !v34 && *v35 == 2 )
        goto LABEL_48;
LABEL_143:
      v43 = -1073741535;
LABEL_51:
      v29 = v87;
LABEL_52:
      v34 = 4;
      goto LABEL_53;
    }
    v97 = 0;
    v98 = 0;
    v99 = 0;
    v34 = CmpSearchForOpenSubKeys((int)v35, 1, v41, &v97);
    if ( v34 )
    {
      if ( v97 != -1073741267 )
        goto LABEL_143;
      v63 = UNLOCK_HIVE_LOAD(v34);
      CmpUnlockRegistry(v63);
      v24 = 0;
      v85 = 0;
      v43 = CmpRollbackTransactionArray(v98, v99, 0, &v93);
      if ( v43 < 0 )
        goto LABEL_51;
LABEL_127:
      v15 = v84;
      v2 = v86;
    }
    else
    {
LABEL_48:
      if ( !v89 )
      {
        v35[1] |= 0x40000u;
        if ( (*(_DWORD *)(v4 + 3228) & 0x20) != 0 )
        {
          __dmb(0xBu);
          v64 = (unsigned int *)(v4 + 3324);
          do
          {
            v65 = __ldrex(v64);
            v66 = v65 + 1;
          }
          while ( __strex(v66, v64) );
          __dmb(0xBu);
          *(_DWORD *)(v4 + 4 * ((v66 - 1) & 0x7F) + 3328) = 32;
          v34 = CmpUnfreezeHive(v4);
          v67 = CmpActiveAppHiveUnloadCount + 1;
          __dmb(0xBu);
          CmpActiveAppHiveUnloadCount = v67;
          v90 = 1;
        }
        v15 = v84;
        v16 = CmpUnlockRegistry(v34);
        UNLOCK_HIVE_LOAD(v16);
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
        while ( __strex(v17 + 1, (unsigned int *)&CmpActiveHiveRundownCount) );
        __dmb(0xBu);
        v18 = (unsigned int *)(v4 + 1832);
        do
          v19 = __ldrex(v18);
        while ( !v19 && __strex(1u, v18) );
        __dmb(0xBu);
        if ( v19 && v19 != 1 )
          ExfWaitForRundownProtectionRelease((unsigned int *)(v4 + 1832), v19);
        __dmb(0xBu);
        do
          v20 = __ldrex(v18);
        while ( __strex(1u, v18) );
        __dmb(0xBu);
        v21 = (unsigned int *)(v4 + 3324);
        do
        {
          v22 = __ldrex(v21);
          v23 = v22 + 1;
        }
        while ( __strex(v23, v21) );
        __dmb(0xBu);
        *(_DWORD *)(v4 + 4 * (((_BYTE)v23 - 1) & 0x7F) + 3328) = 1;
        v89 = 1;
        goto LABEL_22;
      }
      if ( !v38 || v96 )
      {
        v90 = 0;
        v42 = CmUnloadKey(v35);
        v24 = v85;
        v43 = v42;
        goto LABEL_51;
      }
      v68 = CmSnapshotRMTxArray(v38, &v100, &v101);
      v43 = v68;
      if ( v68 < 0 )
        goto LABEL_51;
      v69 = CmpUnlockRegistry(v68);
      v70 = v100;
      if ( v100 )
      {
        UNLOCK_HIVE_LOAD(v69);
        v24 = 0;
        v85 = 0;
        v43 = CmpRollbackTransactionArray(v70, v101, v88, &v93);
        if ( v43 < 0 )
          goto LABEL_51;
        v2 = v86;
        if ( v88[0] == 1 )
        {
          CmObliterateRMTxArray(v38);
          goto LABEL_127;
        }
        v15 = v84;
      }
      else
      {
        if ( v94 )
        {
          v71 = CmShutdownCmRM(v38, 1);
          v96 = 1;
        }
        else
        {
          v39 = CmCloseRmHandle(v38, 0);
          v71 = CmCloseTmHandle(v38);
          v94 = 1;
          v40 = v71;
        }
        UNLOCK_HIVE_LOAD(v71);
        if ( v39 )
          ZwClose();
        v15 = v84;
        if ( v40 )
        {
          ZwClose();
          goto LABEL_127;
        }
LABEL_22:
        v2 = v86;
      }
    }
  }
  v43 = -1073741431;
  v34 = 4;
LABEL_53:
  if ( v89 )
  {
    if ( v43 < 0 )
    {
      if ( (*(_DWORD *)(v4 + 3228) & 0x20) != 0 )
      {
        __dmb(0xBu);
        v72 = (unsigned int *)(v4 + 3324);
        do
        {
          v73 = __ldrex(v72);
          v74 = v73 + 1;
        }
        while ( __strex(v74, v72) );
        __dmb(0xBu);
        *(_DWORD *)(v4 + 4 * (((_BYTE)v74 - 1) & 0x7F) + 3328) = 33;
        if ( (v24 & 4) == 0 )
        {
          LOCK_HIVE_LOAD(4);
          v24 |= 4u;
          v85 = v24;
        }
        if ( (v24 & 2) == 0 )
        {
          CmpLockRegistryFreezeAware(1);
          v24 |= 2u;
          v85 = v24;
        }
        v75 = (int)v91;
        *(_BYTE *)(v4 + 2532) = 1;
        CmpReferenceKeyControlBlock(v75);
        v76 = v90;
        *(_DWORD *)(v4 + 2528) = v75;
        if ( v76 )
        {
          v77 = CmpActiveAppHiveUnloadCount - 1;
          __dmb(0xBu);
          CmpActiveAppHiveUnloadCount = v77;
          v78 = CmpActiveAppHiveUnloadCount;
          __dmb(0xBu);
          if ( !v78 )
          {
            __dmb(0xFu);
            if ( CmpActiveAppHiveUnloadEvent )
              ExfUnblockPushLock((int)&CmpActiveAppHiveUnloadEvent, 0);
          }
          LOBYTE(v24) = v85;
        }
      }
      else
      {
        v75 = (int)v91;
      }
      *(_DWORD *)(v75 + 4) &= 0xFFFBFFFF;
      __dmb(0xBu);
      v79 = (unsigned int *)(v4 + 1832);
      v34 = 0;
      do
        v80 = __ldrex(v79);
      while ( __strex(0, v79) );
      __dmb(0xBu);
      v81 = (unsigned int *)(v4 + 3324);
      do
      {
        v82 = __ldrex(v81);
        v83 = v82 + 1;
      }
      while ( __strex(v83, v81) );
      __dmb(0xBu);
      *(_DWORD *)(v4 + 4 * ((v83 - 1) & 0x7F) + 3328) = 2;
    }
    __dmb(0xBu);
    do
    {
      v44 = __ldrex((unsigned int *)&CmpActiveHiveRundownCount);
      v45 = v44 - 1;
    }
    while ( __strex(v45, (unsigned int *)&CmpActiveHiveRundownCount) );
    __dmb(0xBu);
    if ( !v45 )
    {
      __dmb(0xFu);
      v34 = (int)&CmpActiveHiveRundownEvent;
      if ( CmpActiveHiveRundownEvent )
        v34 = ExfUnblockPushLock((int)&CmpActiveHiveRundownEvent, 0);
    }
  }
  v15 = v84;
LABEL_61:
  if ( (v24 & 2) != 0 )
    v34 = CmpUnlockRegistry(v34);
  if ( (v24 & 4) != 0 )
    UNLOCK_HIVE_LOAD(v34);
  CmpSignalDeferredPosts(v92);
  v13 = CmPostCallbackNotification(35, v15, v43, v102, v95);
  v46 = ObfDereferenceObject(v15);
  v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v48 = *(_WORD *)(v47 + 0x134) + 1;
  *(_WORD *)(v47 + 308) = v48;
  if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
    KiCheckForKernelApcDelivery(v46);
  if ( v29 )
  {
LABEL_68:
    __pld(&CmpShutdownRundown);
    v49 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v50 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v50 == v49 && __strex(v49 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v50 != v49 )
      v49 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v52 = *(_WORD *)(v51 + 0x134) + 1;
    *(_WORD *)(v51 + 308) = v52;
    if ( !v52 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
      KiCheckForKernelApcDelivery(v49);
  }
  return v13;
}
