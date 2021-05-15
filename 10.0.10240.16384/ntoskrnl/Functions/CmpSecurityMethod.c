// CmpSecurityMethod 
 
int __fastcall CmpSecurityMethod(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v12; // r5
  _DWORD *v13; // r7
  _BYTE *v14; // r0
  int v16; // r4
  int v17; // r2
  int v18; // r9
  int v19; // r3
  int v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r1
  int v23; // r1
  unsigned int *v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // r0
  int v28; // r0
  unsigned __int8 *v29; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int v32; // r4
  unsigned int v33; // r1
  unsigned int v34; // r1
  int v35; // r3
  unsigned int v36; // r3
  int v37; // r3
  int v38; // r0
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r0
  int v43; // r0
  unsigned int v44; // r1
  unsigned int v45; // r1
  int v46; // r3
  int v47; // r0
  int v48; // r0
  int v49; // r1
  unsigned int v50; // r1
  __int16 v51; // r3
  unsigned int v52; // r1
  int v53; // r3
  _DWORD *v54; // r0
  _DWORD *v55; // r1
  int v56; // r0
  int v57; // r0
  _DWORD *v58; // r1
  int v59; // r0
  int v60; // [sp+10h] [bp-90h]
  int v61; // [sp+14h] [bp-8Ch]
  int v62; // [sp+18h] [bp-88h]
  int v63; // [sp+20h] [bp-80h] BYREF
  int v64; // [sp+24h] [bp-7Ch]
  int v65[2]; // [sp+28h] [bp-78h] BYREF
  int v66; // [sp+30h] [bp-70h] BYREF
  int v67; // [sp+34h] [bp-6Ch] BYREF
  int v68; // [sp+38h] [bp-68h] BYREF
  int v69; // [sp+3Ch] [bp-64h]
  int v70[2]; // [sp+40h] [bp-60h] BYREF
  int v71; // [sp+48h] [bp-58h] BYREF
  int v72; // [sp+4Ch] [bp-54h]
  _DWORD *v73; // [sp+50h] [bp-50h] BYREF
  _DWORD v74[6]; // [sp+54h] [bp-4Ch] BYREF
  _DWORD v75[12]; // [sp+70h] [bp-30h] BYREF

  v64 = a4;
  v72 = a3;
  v69 = a5;
  v67 = a8;
  v61 = 0;
  v68 = 0;
  v62 = 1;
  v12 = -1073741823;
  v60 = 0;
  v73 = 0;
  v13 = 0;
  v14 = memset(v74, 0, sizeof(v74));
  v71 = 0;
  v75[0] = 0;
  v75[1] = 0;
  v75[2] = 0;
  v75[3] = 0;
  if ( CmpTraceRoutine )
    return sub_80380C(v14);
  v65[1] = (int)v65;
  v65[0] = (int)v65;
  v70[1] = (int)v70;
  v16 = a1[1];
  v70[0] = (int)v70;
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v17 + 0x134);
  if ( !CmpCallBackCount || ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, 0, v17, CmpCallBackCount) )
    goto LABEL_4;
  if ( a2 == 1 )
  {
    v74[2] = v69;
    v37 = 37;
    v38 = 36;
LABEL_72:
    v73 = a1;
    v74[0] = a3;
    v74[1] = a4;
    v39 = CmpCallCallBacks(v38, &v73, 1, v37, a1, v65);
    v12 = v39;
    if ( v39 < 0 )
    {
      if ( v39 == -1073740541 )
        v12 = 0;
      v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v41 = *(_WORD *)(v40 + 0x134) + 1;
      *(_WORD *)(v40 + 308) = v41;
      if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
        KiCheckForKernelApcDelivery(v39);
LABEL_80:
      if ( CmpTraceRoutine )
      {
        if ( a2 )
          v42 = 29;
        else
          v42 = 28;
        CmpTraceRoutine(v42, v75, v12, 0, 0, 0);
      }
      return v12;
    }
    goto LABEL_4;
  }
  if ( !a2 )
  {
    v37 = 39;
    v38 = 38;
    goto LABEL_72;
  }
LABEL_4:
  v18 = 0;
  do
  {
    if ( v18 )
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
      v46 = (__int16)(*(_WORD *)(v45 + 0x134) + 1);
      *(_WORD *)(v45 + 308) = v46;
      if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
        KiCheckForKernelApcDelivery(v43);
    }
    v19 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v19 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v20 = CmpShutdownRundown & 0xFFFFFFFE;
    v21 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v22 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v22 == v20 && __strex(v21, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v22 != v20 )
    {
      v20 = ExfAcquireRundownProtection(&CmpShutdownRundown);
      if ( !v20 )
      {
        v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v51 = *(_WORD *)(v50 + 0x134) + 1;
        *(_WORD *)(v50 + 308) = v51;
        if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
          v20 = KiCheckForKernelApcDelivery(0);
        v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v53 = (__int16)(*(_WORD *)(v52 + 0x134) + 1);
        *(_WORD *)(v52 + 308) = v53;
        if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
          KiCheckForKernelApcDelivery(v20);
        v12 = -1073741431;
        goto LABEL_80;
      }
    }
    v18 = 1;
    CmpLockRegistry(v20, v22);
    if ( a2 == 1 )
    {
      if ( (v16 & 1) != 0 )
      {
        v16 ^= 1u;
        v62 = 0;
      }
      else
      {
        CmpLockKcbShared((_DWORD *)v16);
      }
    }
    else
    {
      v36 = *(unsigned __int16 *)(v16 + 106);
      if ( (v36 & 0x200) != 0 && !CmpIsSystemEntity(0, v23, v24, v36) )
      {
        CmpUnlockRegistry();
        v12 = 0;
        goto LABEL_28;
      }
      CmpLockKcbExclusive(v16);
    }
    v25 = a1[7];
    if ( (v25 || a1[8]) && (*(_DWORD *)(v16 + 4) & 0x20000) == 0 )
    {
      v12 = CmpSearchAddTrans((int)a1, 0, 0, v25, a1[8], 0, &v68);
      if ( v12 < 0 )
      {
        if ( v62 )
          CmpUnlockKcb((_DWORD *)v16);
        goto LABEL_136;
      }
      v26 = v68;
      v61 = v68;
    }
    else
    {
      v26 = 0;
    }
    v27 = CmRmIsKCBDeleted(v16, v26);
    if ( v27 == 1 )
    {
      if ( (a1[6] & 1) != 0 )
        v12 = -1073740763;
      else
        v12 = -1073741444;
      if ( v62 )
        CmpUnlockKcb((_DWORD *)v16);
LABEL_136:
      CmpUnlockRegistry();
      goto LABEL_28;
    }
    if ( a2 != 1 )
    {
      CmpLockHiveFlusherShared(*(_DWORD *)(v16 + 20));
      v27 = CmLockHiveSecurityExclusive(*(_DWORD *)(v16 + 20));
      v60 = 1;
    }
    if ( a2 )
    {
      switch ( a2 )
      {
        case 1:
          v67 = CmGetKCBCacheSecurity(v16, v61) + 24;
          v28 = SeQuerySecurityDescriptorInfo(v72, v64, v69, &v67);
          break;
        case 3:
          v28 = CmpAssignSecurityDescriptorWrapper(a1, v64, v61);
          break;
        case 2:
LABEL_23:
          if ( v12 < 0 )
            goto LABEL_57;
          goto LABEL_24;
        default:
          KeBugCheckEx(81, 5, 1, v16, a2);
      }
      v12 = v28;
      goto LABEL_23;
    }
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
      && (*(_DWORD *)(*(_DWORD *)(v16 + 20) + 3228) & 0x20) != 0 )
    {
      v12 = -1073741790;
      goto LABEL_43;
    }
    if ( v61 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(v16 + 20) + 92) & 2) != 0 )
      {
        v12 = -1072103423;
        goto LABEL_43;
      }
      v13 = (_DWORD *)CmpAllocateUnitOfWork(v27);
      if ( !v13 )
      {
        v12 = -1073741670;
        goto LABEL_43;
      }
      v54 = *(_DWORD **)(v16 + 112);
      v55 = v13 + 4;
      v13[4] = v16 + 108;
      v13[5] = v54;
      if ( *v54 != v16 + 108 )
        __fastfail(3u);
      *v54 = v55;
      *(_DWORD *)(v16 + 112) = v55;
      v56 = CmpReferenceKeyControlBlock((unsigned int *)v16);
      v13[6] = v16;
      v57 = LOCK_TRANSACTION_LIST(v56);
      v58 = *(_DWORD **)(v61 + 12);
      *v13 = v61 + 8;
      v13[1] = v58;
      if ( *v58 != v61 + 8 )
        __fastfail(3u);
      *v58 = v13;
      *(_DWORD *)(v61 + 12) = v13;
      UNLOCK_TRANSACTION_LIST(v57);
      v13[7] = v61;
      if ( !CmpLockIXLockExclusive(v16 + 128, v13, 0) || !CmpLockIXLockExclusive(v16 + 136, v13, 1) )
      {
        v12 = -1072103423;
        goto LABEL_57;
      }
LABEL_52:
      v12 = CmpSetSecurityDescriptorInfo(v16, v72, v64);
      if ( v12 >= 0 )
      {
        CmUnlockHiveSecurity(*(_DWORD *)(v16 + 20));
        v60 = 0;
        CmpReportNotify(v16, *(_DWORD *)(v16 + 20), *(_DWORD *)(v16 + 24), v61, 10, v70);
        goto LABEL_23;
      }
LABEL_57:
      if ( v13 )
      {
        CmpRundownUnitOfWork(v13);
        CmpFreeUnitOfWork(v13);
      }
LABEL_24:
      if ( a2 == 1 )
        goto LABEL_25;
LABEL_43:
      if ( v60 )
        goto LABEL_65;
      goto LABEL_44;
    }
    if ( CmpTryAcquireIXLockExclusive(v16 + 128) )
    {
      if ( CmpTryAcquireIXLockExclusive(v16 + 136) )
        goto LABEL_52;
      v47 = v16 + 136;
    }
    else
    {
      v47 = v16 + 128;
    }
    v12 = CmpSnapshotTxOwnerArray(v47, &v66, &v63);
    if ( v12 < 0 )
      goto LABEL_43;
    CmpUnlockKcb((_DWORD *)v16);
    if ( v60 )
    {
      CmUnlockHiveSecurity(*(_DWORD *)(v16 + 20));
      v60 = 0;
    }
    CmpUnlockHiveFlusher(*(_DWORD *)(v16 + 20));
    CmpUnlockRegistry();
    v48 = CmpRollbackTransactionArray(v66, v63, 0, &v71);
    v12 = v48;
  }
  while ( v48 >= 0 );
  CmpLockRegistry(v48, v49);
  CmpLockKcbExclusive(v16);
  CmpLockHiveFlusherShared(*(_DWORD *)(v16 + 20));
  CmLockHiveSecurityExclusive(*(_DWORD *)(v16 + 20));
LABEL_65:
  CmUnlockHiveSecurity(*(_DWORD *)(v16 + 20));
LABEL_44:
  CmpUnlockHiveFlusher(*(_DWORD *)(v16 + 20));
LABEL_25:
  if ( v62 )
    CmpUnlockKcb((_DWORD *)v16);
  CmpUnlockRegistry();
  v29 = (unsigned __int8 *)CmpSignalDeferredPosts(v70);
LABEL_28:
  if ( a2 == 1 )
  {
    v29 = (unsigned __int8 *)CmPostCallbackNotification(37, a1, v12, &v73, v65);
    goto LABEL_30;
  }
  if ( !a2 )
  {
    v29 = (unsigned __int8 *)CmPostCallbackNotification(39, a1, v12, &v73, v65);
LABEL_30:
    v12 = (int)v29;
  }
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = *(_WORD *)(v30 + 0x134) + 1;
  *(_WORD *)(v30 + 308) = v31;
  if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
    v29 = (unsigned __int8 *)KiCheckForKernelApcDelivery((int)v29);
  if ( CmpTraceRoutine )
  {
    if ( a2 )
      v59 = 29;
    else
      v59 = 28;
    v29 = (unsigned __int8 *)CmpTraceRoutine(v59, v75, v12, 0, 0, 0);
  }
  __pld(&CmpShutdownRundown);
  v32 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v33 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v33 == v32 && __strex(v32 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v33 != v32 )
    v29 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v35 = (__int16)(*(_WORD *)(v34 + 0x134) + 1);
  *(_WORD *)(v34 + 308) = v35;
  if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
    KiCheckForKernelApcDelivery((int)v29);
  return v12;
}
