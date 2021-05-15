// CmDeleteValueKey 
 
int CmDeleteValueKey(_DWORD *a1, ...)
{
  int v1; // r5
  int v2; // r9
  _DWORD *v3; // r10
  _BYTE *v4; // r0
  int v5; // r8
  int v7; // r3
  unsigned int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r1
  _DWORD *v11; // r0
  int v12; // r1
  int v13; // r4
  int v14; // r5
  int v15; // r7
  _DWORD *v16; // r2
  _DWORD *v17; // r8
  int v18; // r0
  int v19; // r5
  _DWORD *v20; // r9
  int v21; // r8
  int v22; // r8
  int v23; // r0
  int v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r1
  bool v27; // zf
  unsigned int v28; // r1
  int v29; // r3
  int v30; // r5
  int v31; // r0
  int v32; // r0
  void (__fastcall *v33)(int, int *); // r3
  __int64 v34; // r2
  _DWORD *v35; // r1
  int v36; // r0
  int v37; // r0
  int v38; // r1
  unsigned int v39; // r1
  __int16 v40; // r3
  _DWORD *v41; // r0
  _DWORD *v42; // r1
  int v43; // r0
  int v44; // r0
  int v45; // r2
  _DWORD *v46; // r1
  int v47; // r3
  int v48; // r1
  unsigned int v49; // r4
  int v50; // r0
  unsigned int v51; // r1
  char v52[4]; // [sp+10h] [bp-88h] BYREF
  _DWORD *v53; // [sp+14h] [bp-84h]
  int v54; // [sp+18h] [bp-80h]
  int v55; // [sp+1Ch] [bp-7Ch]
  int v56; // [sp+20h] [bp-78h] BYREF
  unsigned int v57; // [sp+24h] [bp-74h]
  int v58; // [sp+28h] [bp-70h]
  int v59; // [sp+2Ch] [bp-6Ch] BYREF
  int v60; // [sp+30h] [bp-68h] BYREF
  int v61; // [sp+34h] [bp-64h] BYREF
  int v62; // [sp+38h] [bp-60h] BYREF
  unsigned int v63; // [sp+3Ch] [bp-5Ch] BYREF
  int v64; // [sp+40h] [bp-58h] BYREF
  int v65; // [sp+44h] [bp-54h]
  int v66[2]; // [sp+48h] [bp-50h] BYREF
  int v67; // [sp+50h] [bp-48h]
  int v68; // [sp+54h] [bp-44h]
  __int64 v69; // [sp+58h] [bp-40h] BYREF
  int v70; // [sp+60h] [bp-38h] BYREF
  int v71[5]; // [sp+64h] [bp-34h] BYREF
  int varg_r1; // [sp+A4h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+A4h] [bp+Ch]
  int varg_r2; // [sp+A8h] [bp+10h]
  int varg_r3; // [sp+ACh] [bp+14h]
  int v76; // [sp+B0h] [bp+18h]
  va_list va1; // [sp+B4h] [bp+1Ch] BYREF

  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _DWORD);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v76 = va_arg(va1, _DWORD);
  v68 = varg_r3;
  v55 = 0;
  v64 = -1;
  v60 = -1;
  v54 = 0;
  v52[0] = 0;
  v65 = 1;
  v1 = (int)a1;
  v2 = 0;
  v70 = 0;
  v53 = a1;
  v58 = 0;
  v56 = 0;
  v3 = 0;
  v4 = memset(v71, 0, sizeof(v71));
  v57 = 0;
  v63 = 0;
  v59 = 0;
  v66[1] = (int)v66;
  v66[0] = (int)v66;
  v5 = 0;
  while ( 1 )
  {
    if ( v5 )
      return sub_7E7174(v4);
    v7 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v8 = CmpShutdownRundown & 0xFFFFFFFE;
    v9 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v10 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v10 != v8 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    {
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        KiCheckForKernelApcDelivery(0);
      return -1073741431;
    }
    v5 = 1;
    v11 = KeQuerySystemTime(&v69);
    CmpLockRegistry(v11, v12);
    v13 = *(_DWORD *)(v1 + 4);
    CmpLockKcbExclusive(v13);
    if ( (*(_DWORD *)(v13 + 4) & 0x20000) != 0 )
    {
      if ( (*(_DWORD *)(v1 + 24) & 1) != 0 )
        v19 = -1073740763;
      else
        v19 = -1073741444;
      v50 = CmpUnlockKcb(v13);
      CmpUnlockRegistry(v50);
      __pld(&CmpShutdownRundown);
      v24 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v51 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v51 == v24 && __strex(v24 - 2, (unsigned int *)&CmpShutdownRundown) );
      v27 = v51 == v24;
      goto LABEL_35;
    }
    v14 = *(_DWORD *)(v13 + 24);
    v15 = *(_DWORD *)(v13 + 20);
    v67 = v14;
    CmpLockHiveFlusherShared(v15);
    if ( v53[7] || v53[8] )
      break;
    if ( CmpTryAcquireIXLockIntent(v13 + 128) )
    {
      if ( CmpTryAcquireIXLockExclusive(v13 + 136) )
      {
        v17 = v16;
        goto LABEL_14;
      }
      v36 = v13 + 136;
    }
    else
    {
      v36 = v13 + 128;
    }
    v19 = CmpSnapshotTxOwnerArray(v36, &v61, &v62);
    if ( v19 < 0 )
      goto LABEL_29;
    CmpUnlockHiveFlusher(v15);
    v37 = CmpUnlockKcb(v13);
    CmpUnlockRegistry(v37);
    v4 = (_BYTE *)CmpRollbackTransactionArray(v61, v62, 0, &v59);
    v19 = (int)v4;
    if ( (int)v4 < 0 )
    {
      CmpLockRegistry(v4, v38);
      CmpLockKcbExclusive(v13);
      CmpLockHiveFlusherShared(v15);
LABEL_23:
      if ( v19 >= 0 )
        goto LABEL_28;
LABEL_24:
      v22 = v54;
      goto LABEL_25;
    }
    v1 = (int)v53;
  }
  v17 = v53;
  if ( CmRmIsKCBDeleted(v13, 0) == 1 )
  {
    if ( (v53[6] & 1) != 0 )
      v19 = -1073740763;
    else
      v19 = -1073741444;
    goto LABEL_29;
  }
  v19 = CmpSearchAddTrans(v53, 0, 0, v53[7], v53[8], 0, &v56);
  if ( v19 < 0 )
    goto LABEL_29;
  if ( (*(_DWORD *)(*(_DWORD *)(v13 + 20) + 92) & 2) != 0 )
  {
    v19 = -1072103423;
    goto LABEL_29;
  }
  v3 = (_DWORD *)CmpAllocateUnitOfWork();
  if ( !v3 )
  {
    v19 = -1073741670;
    goto LABEL_29;
  }
  v41 = *(_DWORD **)(v13 + 112);
  v42 = v3 + 4;
  v3[4] = v13 + 108;
  v3[5] = v41;
  if ( *v41 != v13 + 108 )
    __fastfail(3u);
  *v41 = v42;
  *(_DWORD *)(v13 + 112) = v42;
  v43 = CmpReferenceKeyControlBlock(v13);
  v3[6] = v13;
  v44 = LOCK_TRANSACTION_LIST(v43);
  v2 = v56;
  v45 = v56 + 8;
  v46 = *(_DWORD **)(v56 + 12);
  *v3 = v56 + 8;
  v3[1] = v46;
  v58 = v2;
  if ( *v46 != v45 )
    __fastfail(3u);
  *v46 = v3;
  *(_DWORD *)(v45 + 4) = v3;
  UNLOCK_TRANSACTION_LIST(v44);
  v3[7] = v2;
  if ( !CmpLockIXLockIntent(v13 + 128, v3) || !CmpLockIXLockExclusive(v13 + 136, v3, 1) )
  {
    v19 = -1072103423;
    goto LABEL_21;
  }
  if ( CmpCloneKCBValueListForTrans(v13, v2, v52) )
  {
    v14 = v67;
    v54 = (unsigned __int8)v52[0];
LABEL_14:
    if ( CmRmIsKCBDeleted(v13, v2) == 1 )
    {
      v47 = v17[6];
      v22 = v54;
      if ( (v47 & 1) != 0 )
        v19 = -1073740763;
      else
        v19 = -1073741444;
      goto LABEL_25;
    }
    v18 = (*(int (__fastcall **)(int, int, int *))(v15 + 4))(v15, v14, &v64);
    v55 = v18;
    if ( !v18 )
    {
      v19 = -1073741670;
      goto LABEL_24;
    }
    CmpUpdateKeyNodeAccessBits(v15, v18, v14);
    v19 = -1073741772;
    if ( v2 )
      v20 = (_DWORD *)(v13 + 144);
    else
      v20 = (_DWORD *)(v55 + 36);
    v56 = -1;
    if ( !*v20 )
      goto LABEL_21;
    if ( !CmpFindNameInList(v15, v20, (int *)varg_r1a, 0, &v59, &v56) )
    {
LABEL_60:
      v19 = -1073741670;
      goto LABEL_21;
    }
    v21 = v56;
    if ( v56 == -1 )
      goto LABEL_21;
    if ( (unsigned __int8)v76 == 1 )
    {
      v19 = CmpGetValueForAudit(v15, v56, &v70, 826363203);
      if ( v19 < 0 )
        goto LABEL_21;
      v19 = CmpSnapshotKCBSecurity(v13, v58, 843140419, &v63);
      v57 = v63;
      if ( v19 < 0 )
        goto LABEL_21;
    }
    v30 = v58;
    if ( !v58 )
    {
      if ( HvpMarkCellDirty(v15, v67, 0, 0)
        && HvpMarkCellDirty(v15, *(_DWORD *)(v55 + 40), 0, 0)
        && HvpMarkCellDirty(v15, v21, 0, 0) )
      {
        v31 = (*(int (__fastcall **)(int, int, int *))(v15 + 4))(v15, v21, &v60);
        if ( !v31 )
          goto LABEL_60;
        v32 = CmpMarkValueDataDirty(v15, v31);
        v33 = *(void (__fastcall **)(int, int *))(v15 + 8);
        if ( v32 )
        {
          v33(v15, &v60);
          goto LABEL_47;
        }
        v33(v15, &v60);
      }
      v19 = -1073741443;
      goto LABEL_21;
    }
    v3[9] = 6;
    v3[12] = v21;
LABEL_47:
    if ( CmpRemoveValueFromList(v15, v59, v20) >= 0 )
    {
      if ( !v30 )
      {
        if ( CmpFreeValue(v15, v21) )
        {
          v34 = v69;
          v35 = (_DWORD *)v55;
          *(_QWORD *)(v55 + 4) = v69;
          *(_QWORD *)(v13 + 88) = v34;
          if ( !v35[9] )
          {
            v35[15] = 0;
            v35[16] = 0;
            *(_WORD *)(v13 + 98) = 0;
            *(_DWORD *)(v13 + 100) = 0;
          }
          CmpCleanUpKcbValueCache(v13);
          v19 = 0;
          *(_DWORD *)(v13 + 52) = *v20;
          *(_DWORD *)(v13 + 56) = v20[1];
          goto LABEL_53;
        }
        goto LABEL_60;
      }
      CmpUnlockHiveFlusher(v15);
      v65 = 0;
      v19 = CmAddLogForAction(v3);
      if ( v19 >= 0 )
LABEL_53:
        CmpReportNotify(v13, *(_DWORD *)(v13 + 20), *(_DWORD *)(v13 + 24), v58, 4, v66);
LABEL_21:
      if ( v55 )
        (*(void (__fastcall **)(int, int *))(v15 + 8))(v15, &v64);
      goto LABEL_23;
    }
    goto LABEL_60;
  }
  v19 = -1073741670;
  v22 = (unsigned __int8)v52[0];
LABEL_25:
  if ( v3 )
  {
    CmpRundownUnitOfWork(v3);
    CmpFreeUnitOfWork(v3);
  }
  if ( v22 )
  {
    v48 = *(_DWORD *)(v13 + 148);
    if ( v48 != -1 )
      HvFreeCell(*(_DWORD *)(v13 + 20), v48);
    *(_DWORD *)(v13 + 144) = 0;
    *(_DWORD *)(v13 + 148) = -1;
    *(_DWORD *)(v13 + 152) = 0;
  }
LABEL_28:
  if ( !v65 )
    goto LABEL_30;
LABEL_29:
  CmpUnlockHiveFlusher(v15);
LABEL_30:
  v23 = CmpUnlockKcb(v13);
  CmpUnlockRegistry(v23);
  v24 = CmpSignalDeferredPosts(v66);
  if ( (unsigned __int8)v76 == 1 )
  {
    v49 = v57;
    if ( v19 >= 0 )
      SeAdtRegistryValueChangedAuditAlarm(v24, v57);
    v24 = v71[1];
    if ( v71[1] )
      v24 = ExFreePoolWithTag(v71[1]);
    if ( v49 )
      v24 = ExFreePoolWithTag(v49);
  }
  __pld(&CmpShutdownRundown);
  v25 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v26 == v25 && __strex(v25 - 2, (unsigned int *)&CmpShutdownRundown) );
  v27 = v26 == v25;
LABEL_35:
  if ( !v27 )
    v24 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
  *(_WORD *)(v28 + 308) = v29;
  if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
    KiCheckForKernelApcDelivery(v24);
  return v19;
}
