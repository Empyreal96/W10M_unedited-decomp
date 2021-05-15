// CmDeleteKey 
 
int __fastcall CmDeleteKey(int a1)
{
  _DWORD *v1; // r8
  int v2; // r10
  _DWORD *v3; // r9
  int *v4; // r7
  _DWORD *v5; // r0
  int v6; // r3
  int v7; // r3
  unsigned int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r1
  int v11; // r0
  _DWORD *v12; // r4
  int v13; // r5
  int v14; // r5
  int v15; // r6
  int v16; // r0
  int v17; // r8
  int v18; // r3
  int v19; // r5
  int v20; // r5
  int v21; // r5
  int v22; // r10
  int v23; // r0
  __int64 v24; // r1
  int v25; // r3
  int v26; // r0
  unsigned __int8 *v27; // r0
  unsigned int v28; // r4
  unsigned int v29; // r1
  unsigned int v30; // r1
  __int16 v31; // r3
  _DWORD *v33; // r0
  int v34; // r0
  int v35; // r1
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r0
  _DWORD *v39; // r1
  int v40; // r2
  _DWORD *v41; // r0
  int v42; // r0
  int v43; // r0
  int v44; // r5
  _DWORD *v45; // r2
  _DWORD *v46; // r0
  _DWORD *v47; // r1
  int v48; // r0
  int v49; // r0
  int **v50; // r2
  int v51; // [sp+10h] [bp-58h] BYREF
  int v52; // [sp+14h] [bp-54h] BYREF
  int v53; // [sp+18h] [bp-50h] BYREF
  _DWORD *v54; // [sp+1Ch] [bp-4Ch]
  int v55; // [sp+20h] [bp-48h] BYREF
  int v56; // [sp+24h] [bp-44h]
  int v57; // [sp+28h] [bp-40h] BYREF
  int v58; // [sp+2Ch] [bp-3Ch]
  int v59; // [sp+30h] [bp-38h]
  int v60; // [sp+34h] [bp-34h]
  int v61[2]; // [sp+38h] [bp-30h] BYREF
  int v62[10]; // [sp+40h] [bp-28h] BYREF

  v51 = -1;
  v58 = 1;
  v54 = (_DWORD *)a1;
  v55 = 0;
  v61[1] = (int)v61;
  v1 = (_DWORD *)a1;
  v2 = 0;
  v61[0] = (int)v61;
  v57 = 0;
  v3 = 0;
  v4 = 0;
  v5 = KeQuerySystemTime(v62);
  v6 = 0;
  while ( !v6 )
  {
    v7 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v8 = CmpShutdownRundown & 0xFFFFFFFE;
    v9 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v10 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v10 != v8 )
    {
      v8 = ExfAcquireRundownProtection(&CmpShutdownRundown);
      if ( !v8 )
      {
        v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v37 = *(_WORD *)(v36 + 0x134) + 1;
        *(_WORD *)(v36 + 308) = v37;
        if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
          KiCheckForKernelApcDelivery(0);
        return -1073741431;
      }
    }
    v56 = 1;
    v11 = CmpLockRegistry(v8, v10);
    v12 = (_DWORD *)v1[1];
    if ( !v12[10] )
    {
      CmpUnlockRegistry(v11);
      return -1073741535;
    }
    CmpLockHashEntryExclusive(v12[5], v12[3]);
    CmpLockTwoKcbsExclusive(v12[10], v12);
    v13 = v1[7];
    if ( v13 || v1[8] )
    {
      if ( CmRmIsKCBDeleted(v12, 0) == 1 )
      {
LABEL_92:
        v21 = 0;
        goto LABEL_33;
      }
      v21 = CmpSearchAddTrans(v1, 0, 0, v13, v1[8], 0, &v57);
      if ( v21 < 0 )
        goto LABEL_33;
      if ( (*(_DWORD *)(v12[5] + 92) & 2) != 0 )
      {
        v21 = -1072103423;
        goto LABEL_33;
      }
      v2 = v57;
    }
    if ( CmRmIsKCBDeleted(v12, v2) == 1 )
      goto LABEL_92;
    v15 = v12[5];
    v59 = v12[6];
    v14 = v59;
    CmpLockHiveFlusherShared(v15);
    v16 = (*(int (__fastcall **)(int, int, int *))(v15 + 4))(v15, v14, &v51);
    v17 = v16;
    if ( !v16 )
    {
      v21 = -1073741670;
      goto LABEL_32;
    }
    CmpUpdateKeyNodeAccessBits(v15, v16, v14);
    v60 = *(_DWORD *)(v17 + 16);
    v18 = v12[31];
    if ( v18 && v18 != v2 || (v19 = v12[10]) == 0 )
    {
      v21 = -1073741535;
      goto LABEL_29;
    }
    if ( v2 )
    {
      v38 = CmpAllocateUnitOfWork();
      v3 = (_DWORD *)v38;
      if ( !v38 || (v4 = (int *)CmpAllocateUnitOfWork()) == 0 )
      {
        v21 = -1073741670;
        goto LABEL_88;
      }
      v39 = v3 + 4;
      v40 = v12[10] + 108;
      v41 = *(_DWORD **)(v12[10] + 112);
      v3[4] = v40;
      v3[5] = v41;
      if ( *v41 != v40 )
        __fastfail(3u);
      *v41 = v39;
      *(_DWORD *)(v40 + 4) = v39;
      v42 = CmpReferenceKeyControlBlock(v12[10]);
      v3[6] = v12[10];
      v43 = LOCK_TRANSACTION_LIST(v42);
      v44 = v2 + 8;
      v45 = *(_DWORD **)(v2 + 12);
      *v3 = v2 + 8;
      v3[1] = v45;
      if ( *v45 != v2 + 8 )
        __fastfail(3u);
      *v45 = v3;
      *(_DWORD *)(v2 + 12) = v3;
      UNLOCK_TRANSACTION_LIST(v43);
      v3[7] = v2;
      v46 = (_DWORD *)v12[28];
      v47 = v4 + 4;
      v4[4] = (int)(v12 + 27);
      v4[5] = (int)v46;
      if ( (_DWORD *)*v46 != v12 + 27 )
        __fastfail(3u);
      *v46 = v47;
      v12[28] = v47;
      v48 = CmpReferenceKeyControlBlock(v12);
      v4[6] = (int)v12;
      v49 = LOCK_TRANSACTION_LIST(v48);
      v50 = *(int ***)(v2 + 12);
      *v4 = v44;
      v4[1] = (int)v50;
      if ( *v50 != (int *)v44 )
        __fastfail(3u);
      *v50 = v4;
      *(_DWORD *)(v2 + 12) = v4;
      UNLOCK_TRANSACTION_LIST(v49);
      v4[7] = v2;
      if ( !CmpLockIXLockIntent(v12[10] + 128, v3)
        || !CmpLockIXLockExclusive(v12 + 32, v4, 0)
        || !CmpLockIXLockExclusive(v12 + 34, v4, 1) )
      {
        v21 = -1072103423;
LABEL_88:
        if ( v3 )
        {
          CmpRundownUnitOfWork(v3);
          CmpFreeUnitOfWork(v3);
        }
        if ( v4 )
        {
          CmpRundownUnitOfWork(v4);
          CmpFreeUnitOfWork(v4);
        }
LABEL_29:
        if ( v17 )
          (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v51);
        if ( v58 )
LABEL_32:
          CmpUnlockHiveFlusher(v12[5]);
LABEL_33:
        CmpUnlockTwoKcbs(v12[10], v12);
        v26 = CmpUnlockHashEntry(v12[5], v12[3]);
        CmpUnlockRegistry(v26);
        v27 = (unsigned __int8 *)CmpSignalDeferredPosts(v61);
        __pld(&CmpShutdownRundown);
        v28 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v29 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v29 == v28 && __strex(v28 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v29 != v28 )
          v27 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v31 = *(_WORD *)(v30 + 0x134) + 1;
        *(_WORD *)(v30 + 308) = v31;
        if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
          KiCheckForKernelApcDelivery((int)v27);
        return v21;
      }
LABEL_21:
      if ( CmGetVisibleSubkeyCount(v12, v17, v2) || (*(_WORD *)(v17 + 2) & 8) != 0 )
      {
        (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v51);
        v21 = -1073741535;
        v17 = 0;
      }
      else
      {
        (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v51);
        v17 = 0;
        if ( v2 )
        {
          v3[9] = 3;
          v3[12] = v12;
          v4[9] = 2;
          CmpUnlockHiveFlusher(v12[5]);
          v58 = 0;
          v21 = CmAddLogForAction(v4);
          CmpReportNotify(v12, v12[5], v12[6], v2, 1, v61);
        }
        else
        {
          v20 = v59;
          CmpReportNotify(v12, v15, v59, 0, 1, v61);
          v21 = CmpFreeKeyByCell(v15, v20, 1);
          if ( v21 < 0 )
            goto LABEL_88;
          CmpFlushNotifiesOnKeyBodyList(v12, 0, 0);
          CmpCleanUpSubKeyInfo(v12[10]);
          v22 = v60;
          v23 = (*(int (__fastcall **)(int, int, int *))(v15 + 4))(v15, v60, &v51);
          v17 = v23;
          if ( v23 )
          {
            CmpUpdateKeyNodeAccessBits(v15, v23, v22);
            LODWORD(v24) = v62[0];
            *(_WORD *)(v12[10] + 96) = *(_DWORD *)(v17 + 52);
            HIDWORD(v24) = v62[1];
            v25 = (int)v54;
            *(_QWORD *)(v17 + 4) = v24;
            *(_QWORD *)(*(_DWORD *)(*(_DWORD *)(v25 + 4) + 40) + 88) = v24;
            (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v51);
            v17 = 0;
          }
          CmpMarkKcbDeletedAndCache(v12);
          v12[6] = -1;
        }
      }
      if ( v21 >= 0 )
        goto LABEL_29;
      goto LABEL_88;
    }
    if ( CmpTryAcquireIXLockIntent(v19 + 128) )
    {
      if ( CmpTryAcquireIXLockExclusive(v12 + 32) )
      {
        if ( CmpTryAcquireIXLockExclusive(v12 + 34) )
        {
          if ( (v12[2] & 1) != 0 )
            CmpRemoveFromDelayedDeref(v12);
          goto LABEL_21;
        }
        v33 = v12 + 34;
      }
      else
      {
        v33 = v12 + 32;
      }
    }
    else
    {
      v33 = (_DWORD *)(v19 + 128);
    }
    v21 = CmpSnapshotTxOwnerArray(v33, &v53, &v52);
    if ( v21 < 0 )
      goto LABEL_29;
    (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v51);
    CmpUnlockHiveFlusher(v12[5]);
    CmpUnlockTwoKcbs(v12[10], v12);
    v34 = CmpUnlockHashEntry(v12[5], v12[3]);
    CmpUnlockRegistry(v34);
    v5 = (_DWORD *)CmpRollbackTransactionArray(v53, v52, 0, &v55);
    v21 = (int)v5;
    if ( (int)v5 < 0 )
    {
      CmpLockRegistry(v5, v35);
      CmpLockHashEntryExclusive(v12[5], v12[3]);
      CmpLockTwoKcbsExclusive(v12[10], v12);
      CmpLockHiveFlusherShared(v12[5]);
      goto LABEL_32;
    }
    v6 = v56;
    v1 = v54;
  }
  return sub_7D2258(v5);
}
