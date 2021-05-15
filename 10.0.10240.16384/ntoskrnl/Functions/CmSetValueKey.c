// CmSetValueKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmSetValueKey(_DWORD *a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, int a6, char a7)
{
  int v7; // r6
  int v8; // r7
  _BYTE *v9; // r0
  int v10; // r8
  unsigned int v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  _DWORD *v16; // r0
  int v17; // r1
  int v18; // r4
  _DWORD *v19; // r0
  int v20; // r5
  int v21; // r5
  int v22; // r0
  int v23; // r7 OVERLAPPED
  unsigned int v24; // r8 OVERLAPPED
  int v25; // r0
  int v26; // r5
  int v27; // r3
  int v28; // r9
  int v29; // r10
  int v30; // r8
  int v31; // r0
  int v32; // r6
  int v33; // r8
  unsigned __int16 *v34; // r1
  unsigned int v35; // r2
  __int64 v36; // r2
  int v37; // r0
  unsigned int v38; // r4
  unsigned int v39; // r1
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r3
  int v43; // r0
  int v44; // r0
  int *v45; // r5
  int v46; // r1
  int v47; // r0
  _DWORD *v48; // r5
  int v49; // r0
  int v50; // r2
  _DWORD *v51; // r1
  int v52; // r8
  unsigned int v53; // r1
  int v54; // r1
  unsigned int v55; // r1
  __int16 v56; // r3
  int v57; // r0
  int v58; // r9
  _DWORD *v59; // r6
  unsigned int v60; // r5
  int v61; // r3
  unsigned int v62; // r4
  int v63; // [sp+10h] [bp-A0h]
  char v65[4]; // [sp+18h] [bp-98h] BYREF
  int v66; // [sp+1Ch] [bp-94h] BYREF
  unsigned __int16 *v67; // [sp+20h] [bp-90h]
  int v68; // [sp+24h] [bp-8Ch] BYREF
  int v69; // [sp+28h] [bp-88h]
  int v70; // [sp+2Ch] [bp-84h]
  int v71; // [sp+30h] [bp-80h]
  int v72; // [sp+34h] [bp-7Ch]
  unsigned int v73; // [sp+38h] [bp-78h]
  _DWORD *v74; // [sp+3Ch] [bp-74h]
  int v75; // [sp+40h] [bp-70h] BYREF
  unsigned int v76; // [sp+44h] [bp-6Ch] BYREF
  int v77; // [sp+48h] [bp-68h]
  int v78; // [sp+4Ch] [bp-64h]
  int v79; // [sp+50h] [bp-60h] BYREF
  int v80; // [sp+54h] [bp-5Ch] BYREF
  int v81; // [sp+58h] [bp-58h] BYREF
  _DWORD v82[2]; // [sp+60h] [bp-50h] BYREF
  int v83; // [sp+68h] [bp-48h]
  int v84; // [sp+6Ch] [bp-44h]
  __int64 v85; // [sp+70h] [bp-40h] BYREF
  int v86; // [sp+78h] [bp-38h] BYREF
  int v87[5]; // [sp+7Ch] [bp-34h] BYREF

  v69 = a3;
  v79 = -1;
  v80 = -1;
  v71 = a4;
  v67 = a2;
  v65[0] = 0;
  v7 = 0;
  v72 = 0;
  v83 = 0;
  v77 = 0;
  v8 = 0;
  v70 = 0;
  v81 = 0;
  v74 = 0;
  v63 = 0;
  v86 = 0;
  v9 = memset(v87, 0, sizeof(v87));
  v73 = 0;
  v75 = 0;
  v76 = 0;
  v78 = 0;
  v84 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v82[0] = v82;
  v82[1] = v82;
  v10 = 0;
LABEL_2:
  if ( v10 )
    return sub_7BEB9C(v9);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 0x134);
  __pld(&CmpShutdownRundown);
  v13 = CmpShutdownRundown & 0xFFFFFFFE;
  v14 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v15 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v15 == v13 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v10 = 1;
    v16 = KeQuerySystemTime(&v85);
    CmpLockRegistry(v16, v17);
    v18 = a1[1];
    if ( a1[7] || a1[8] )
    {
      CmpLockKcbExclusive(a1[1]);
      v8 = 1;
      CmpLockHiveFlusherShared(*(_DWORD *)(v18 + 20));
      v63 = 1;
    }
    else
    {
      v19 = (_DWORD *)a1[1];
      if ( v8 == 1 )
        CmpLockKcbExclusive(v19);
      else
        CmpLockKcbShared(v19);
    }
    v20 = a1[7];
    if ( !v20 && !a1[8] )
    {
LABEL_14:
      v21 = v63;
      while ( CmRmIsKCBDeleted(v18, v7) != 1 )
      {
        if ( !v7 )
        {
          if ( !CmpTryAcquireIXLockIntent(v18 + 128) )
          {
            v32 = CmpSnapshotTxOwnerArray(v18 + 128, &v68, &v66);
            if ( v32 < 0 )
              goto LABEL_104;
            if ( v21 )
            {
LABEL_113:
              CmpUnlockHiveFlusher(*(_DWORD *)(v18 + 20));
              v21 = 0;
              v63 = 0;
            }
LABEL_114:
            CmpUnlockKcb((_DWORD *)v18);
            CmpUnlockRegistry();
            v9 = (_BYTE *)CmpRollbackTransactionArray(v68, v66, 0, &v75);
            v32 = (int)v9;
            if ( (int)v9 >= 0 )
            {
              v7 = v70;
              goto LABEL_2;
            }
            CmpLockRegistry(v9, v54);
            CmpLockKcbExclusive(v18);
            goto LABEL_56;
          }
          if ( !CmpTryAcquireIXLockExclusive(v18 + 136) )
          {
            v32 = CmpSnapshotTxOwnerArray(v18 + 136, &v68, &v66);
            if ( v32 < 0 )
              goto LABEL_104;
            if ( v21 )
              goto LABEL_113;
            goto LABEL_114;
          }
        }
        if ( (*(_WORD *)(v18 + 106) & 0x10) != 0
          && (v69 != 6
           || (a5 & 1) != 0
           || a5 > 0xFFFF
           || !v67
           || !RtlEqualUnicodeString(CmSymbolicLinkValueName, v67, 1)
           || RtlIsSandboxedToken(0, v84)) )
        {
          v32 = -1073741790;
          goto LABEL_104;
        }
        if ( v8 )
        {
          *(_QWORD *)&v23 = *(_QWORD *)(v18 + 20);
          if ( !v21 )
            CmpLockHiveFlusherShared(v23);
          v25 = (*(int (__fastcall **)(int, unsigned int, int *))(v23 + 4))(v23, v24, &v80);
          v26 = v25;
          if ( !v25 )
          {
            v21 = v63;
            if ( !v63 )
              CmpUnlockHiveFlusher(v23);
            v32 = -1073741670;
            goto LABEL_104;
          }
          CmpUpdateKeyNodeAccessBits(v23, v25, v24);
          if ( !v63 )
            CmpUnlockHiveFlusher(v23);
          if ( v7 )
            v27 = *(_DWORD *)(v18 + 144);
          else
            v27 = *(_DWORD *)(v26 + 36);
          v28 = 0;
          v68 = 0;
          if ( !v27 )
          {
            v29 = 0;
            goto LABEL_37;
          }
          if ( !CmpFindNameInList() )
          {
            v32 = -1073741670;
            goto LABEL_53;
          }
          v72 = v83;
          if ( v83 == -1 )
            goto LABEL_36;
          if ( !v7 )
          {
            v77 = (*(int (__fastcall **)(int, int, int *))(v23 + 4))(v23, v83, &v79);
            if ( !v77 )
            {
              v32 = -1073741670;
              goto LABEL_53;
            }
          }
          v28 = 1;
          v68 = 1;
LABEL_36:
          v29 = v75;
LABEL_37:
          v66 = v29;
          if ( !v7 && !HvpMarkCellDirty(v23, v24, 0, 0) )
          {
            v32 = -1073741443;
            goto LABEL_53;
          }
          if ( a7 != 1 )
            goto LABEL_40;
          v32 = CmpSnapshotKCBSecurity(v18, v7, 859917635, &v76);
          if ( v32 < 0 )
            goto LABEL_138;
          if ( !v28 )
          {
            v78 = 0;
            goto LABEL_136;
          }
          v32 = CmpGetValueForAudit(v23, v72, &v86, 876694851);
          if ( v32 < 0 )
          {
LABEL_138:
            v73 = v76;
            goto LABEL_53;
          }
          v78 = 1;
LABEL_136:
          v7 = v70;
          v73 = v76;
LABEL_40:
          v30 = v24 >> 31;
          if ( v7 )
          {
            v57 = CmpAddValueKeyNew(v23, v67, v69, v71, a5, 1);
            v58 = v57;
            if ( v57 == -1 )
            {
              v32 = -1073741670;
              goto LABEL_53;
            }
            v32 = CmpAddValueToListEx(v23, v57, *(_DWORD *)(v18 + 144), 1);
            if ( v32 < 0 )
            {
              CmpFreeValue(v23, v58);
              goto LABEL_53;
            }
            if ( v68 )
            {
              v29 = v66;
              CmpRemoveValueFromList(v23, v66, (unsigned int *)(v18 + 144), v68);
              v59 = v74;
              v74[9] = 5;
              v59[12] = v72;
            }
            else
            {
              v59 = v74;
              v29 = v66;
              v74[9] = 4;
            }
            v59[10] = v30;
            v59[13] = v58;
            CmpUnlockHiveFlusher(*(_DWORD *)(v18 + 20));
            v63 = 0;
            v31 = CmAddLogForAction(v59);
            v28 = v68;
          }
          else if ( v28 )
          {
            v31 = CmpSetValueKeyExisting(v23, v72, v77, v69, v71, a5, v30);
          }
          else
          {
            if ( v69 == 6 && (*(_DWORD *)(v18 + 4) & 0x7FE00000) == 6291456 )
            {
              v32 = CmpParseCacheAddSymbolicLink(v18);
              if ( v32 < 0 )
                goto LABEL_53;
            }
            v31 = CmpSetValueKeyNew(v23, v26, (int)v67, v29, v69, v71, a5, v30);
          }
          v32 = v31;
          if ( v31 >= 0 )
          {
            v33 = v70;
            if ( !v70 )
            {
              v34 = v67;
              v35 = *v67;
              if ( *(_DWORD *)(v26 + 60) < v35 )
              {
                *(_DWORD *)(v26 + 60) = v35;
                *(_WORD *)(v18 + 98) = *v34;
              }
              if ( *(_DWORD *)(v26 + 64) < a5 )
              {
                *(_DWORD *)(v26 + 64) = a5;
                *(_DWORD *)(v18 + 100) = a5;
              }
              v36 = v85;
              *(_QWORD *)(v26 + 4) = v85;
              *(_QWORD *)(v18 + 88) = v36;
              if ( v28 && (v42 = *(_DWORD *)(v18 + 56), (v42 & 1) != 0) && v42 != -1 )
              {
                v60 = (v42 & 0xFFFFFFFE) + 4;
                v61 = *(_DWORD *)(v60 + 4 * v29);
                if ( (v61 & 1) != 0 && v61 != -1 )
                  ExFreePoolWithTag(v61 & 0xFFFFFFFE);
                *(_DWORD *)(v60 + 4 * v29) = v72;
              }
              else
              {
                CmpCleanUpKcbValueCache(v18);
                *(_DWORD *)(v18 + 52) = *(_DWORD *)(v26 + 36);
                *(_DWORD *)(v18 + 56) = *(_DWORD *)(v26 + 40);
              }
            }
            CmpReportNotify(v18, *(_DWORD *)(v18 + 20), *(_DWORD *)(v18 + 24), v33, 4, v82);
          }
LABEL_53:
          (*(void (__fastcall **)(int, int *))(v23 + 8))(v23, &v80);
          if ( v77 )
            (*(void (__fastcall **)(int, int *))(v23 + 8))(v23, &v79);
          v21 = v63;
LABEL_56:
          if ( v32 < 0 )
            goto LABEL_104;
          goto LABEL_57;
        }
        v22 = CmpCompareNewValueDataAgainstKCBCache(v18, v67, v69, v71, a5);
        if ( v22 == 1 )
          goto LABEL_90;
        if ( !v22 )
        {
          v32 = 0;
          goto LABEL_57;
        }
        if ( CmpIsKcbLockedExclusive(v18) || CmpTryConvertKcbLockSharedToExclusive(v18) )
        {
          v8 = 1;
          CmpLockHiveFlusherShared(*(_DWORD *)(v18 + 20));
          v21 = 1;
          v63 = 1;
        }
        else
        {
LABEL_90:
          CmpUpgradeKcbLockToExclusive(v18);
        }
      }
      if ( (a1[6] & 1) == 0 )
        goto LABEL_154;
      v32 = -1073740763;
      goto LABEL_104;
    }
    if ( CmRmIsKCBDeleted(v18, 0) == 1 )
    {
      v21 = v63;
      if ( (a1[6] & 1) != 0 )
        v32 = -1073740763;
      else
LABEL_154:
        v32 = -1073741444;
    }
    else
    {
      v43 = CmpSearchAddTrans((int)a1, 0, 0, v20, a1[8], 0, &v81);
      v32 = v43;
      if ( v43 >= 0 )
      {
        if ( (*(_DWORD *)(*(_DWORD *)(v18 + 20) + 92) & 2) != 0 )
          goto LABEL_155;
        v44 = CmpAllocateUnitOfWork(v43);
        v74 = (_DWORD *)v44;
        if ( !v44 )
        {
          v32 = -1073741670;
          v21 = v63;
          goto LABEL_106;
        }
        v45 = *(int **)(v18 + 112);
        v46 = v44 + 16;
        *(_DWORD *)(v44 + 16) = v18 + 108;
        *(_DWORD *)(v44 + 20) = v45;
        if ( *v45 != v18 + 108 )
          __fastfail(3u);
        *v45 = v46;
        *(_DWORD *)(v18 + 112) = v46;
        v47 = CmpReferenceKeyControlBlock((unsigned int *)v18);
        v48 = v74;
        v74[6] = v18;
        v49 = LOCK_TRANSACTION_LIST(v47);
        v7 = v81;
        v50 = v81 + 8;
        v51 = *(_DWORD **)(v81 + 12);
        *v48 = v81 + 8;
        v48[1] = v51;
        v70 = v7;
        if ( *v51 != v50 )
          __fastfail(3u);
        *v51 = v48;
        *(_DWORD *)(v50 + 4) = v48;
        UNLOCK_TRANSACTION_LIST(v49);
        v48[7] = v7;
        if ( CmpLockIXLockIntent(v18 + 128, v48) && CmpLockIXLockExclusive(v18 + 136, v48, 1) )
        {
          if ( CmpCloneKCBValueListForTrans(v18, v7, v65) )
            goto LABEL_14;
          v32 = -1073741670;
        }
        else
        {
LABEL_155:
          v32 = -1072103423;
        }
      }
      v21 = v63;
    }
LABEL_104:
    v52 = (int)v74;
    if ( v74 )
    {
      CmpRundownUnitOfWork(v74);
      CmpFreeUnitOfWork(v52);
    }
LABEL_106:
    if ( v65[0] )
    {
      v53 = *(_DWORD *)(v18 + 148);
      if ( v53 != -1 )
        HvFreeCell(*(_DWORD *)(v18 + 20), v53);
      *(_DWORD *)(v18 + 144) = 0;
      *(_DWORD *)(v18 + 148) = -1;
      *(_DWORD *)(v18 + 152) = 0;
    }
LABEL_57:
    if ( v21 )
      CmpUnlockHiveFlusher(*(_DWORD *)(v18 + 20));
    CmpUnlockKcb((_DWORD *)v18);
    CmpUnlockRegistry();
    v37 = CmpSignalDeferredPosts(v82);
    if ( a7 == 1 )
    {
      v62 = v73;
      if ( v32 >= 0 && v73 )
      {
        v87[2] = v69;
        v87[3] = a5;
        v87[4] = v71;
        SeAdtRegistryValueChangedAuditAlarm(v37, v73);
      }
      v37 = v87[1];
      if ( v87[1] )
        v37 = ExFreePoolWithTag(v87[1]);
      if ( v62 )
        v37 = ExFreePoolWithTag(v62);
    }
    __pld(&CmpShutdownRundown);
    v38 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v39 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v39 == v38 && __strex(v38 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v39 != v38 )
      v37 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v41 = *(_WORD *)(v40 + 0x134) + 1;
    *(_WORD *)(v40 + 308) = v41;
    if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
      KiCheckForKernelApcDelivery(v37);
    return v32;
  }
  v55 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v56 = *(_WORD *)(v55 + 0x134) + 1;
  *(_WORD *)(v55 + 308) = v56;
  if ( !v56 && *(_DWORD *)(v55 + 100) != v55 + 100 && !*(_WORD *)(v55 + 310) )
    KiCheckForKernelApcDelivery(0);
  return -1073741431;
}
