// CmSetLastWriteTimeKey 
 
int __fastcall CmSetLastWriteTimeKey(unsigned __int8 *a1, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v3; // r6
  int v4; // r3
  unsigned __int8 *v5; // r7
  int v6; // r9
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // r3
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1
  _DWORD *v15; // r4
  int v16; // r10
  int v17; // r0
  _DWORD *v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned __int8 *v21; // r0
  unsigned int v22; // r4
  unsigned int v23; // r1
  unsigned int v24; // r1
  __int16 v25; // r3
  __int64 v27; // kr00_8
  int v28; // r0
  int v29; // r10
  _DWORD *v30; // r9
  _DWORD *v31; // r0
  _DWORD *v32; // r1
  int v33; // r0
  int v34; // r0
  _DWORD *v35; // r1
  _DWORD *v36; // r2
  int v37; // [sp+10h] [bp-38h] BYREF
  int v38; // [sp+14h] [bp-34h] BYREF
  int v39; // [sp+18h] [bp-30h] BYREF
  int v40; // [sp+1Ch] [bp-2Ch] BYREF
  int v41; // [sp+20h] [bp-28h]
  int v42; // [sp+24h] [bp-24h] BYREF
  _DWORD *v43; // [sp+28h] [bp-20h]

  v42 = -1;
  v43 = a2;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v39 = 0;
  v40 = 0;
  v5 = a1;
  v6 = 0;
  while ( 1 )
  {
    if ( v4 )
    {
      __pld(&CmpShutdownRundown);
      v7 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v8 == v7 && __strex(v7 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v8 != v7 )
        a1 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = *(_WORD *)(v9 + 0x134) + 1;
      *(_WORD *)(v9 + 308) = v10;
      if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
        KiCheckForKernelApcDelivery((int)a1);
    }
    v11 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v11 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v12 = CmpShutdownRundown & 0xFFFFFFFE;
    v13 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v14 == v12 && __strex(v13, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v14 != v12 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
      break;
    v41 = 1;
    CmpLockRegistry();
    v15 = (_DWORD *)*((_DWORD *)v5 + 1);
    CmpLockKcbExclusive(v15);
    v16 = *((_DWORD *)v5 + 7);
    if ( v16 || *((_DWORD *)v5 + 8) )
    {
      if ( CmRmIsKCBDeleted((int)v15, 0) == 1 )
        goto LABEL_70;
      v2 = CmpSearchAddTrans((int)v5, 0, 0, v16, *((_DWORD *)v5 + 8), 0, &v39);
      if ( v2 < 0 )
        goto LABEL_38;
      if ( (*(_DWORD *)(v15[5] + 92) & 2) != 0 )
      {
        v2 = -1072103423;
        goto LABEL_38;
      }
      v6 = v39;
    }
    v17 = CmRmIsKCBDeleted((int)v15, v6);
    if ( v17 == 1 )
    {
LABEL_70:
      if ( (*((_DWORD *)v5 + 6) & 1) != 0 )
        v2 = -1073740763;
      else
        v2 = -1073741444;
LABEL_38:
      CmpUnlockKcb(v15);
      CmpUnlockRegistry();
      __pld(&CmpShutdownRundown);
      v22 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v23 == v22 && __strex(v22 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v23 != v22 )
        v21 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery((int)v21);
      return v2;
    }
    if ( v6 )
    {
      v3 = (_DWORD *)CmpAllocateUnitOfWork(v17);
      if ( !v3 )
      {
        v2 = -1073741670;
        goto LABEL_38;
      }
      v31 = (_DWORD *)v15[28];
      v32 = v3 + 4;
      v3[4] = v15 + 27;
      v3[5] = v31;
      if ( (_DWORD *)*v31 != v15 + 27 )
        __fastfail(3u);
      *v31 = v32;
      v15[28] = v32;
      v33 = CmpReferenceKeyControlBlock(v15);
      v3[6] = v15;
      v34 = LOCK_TRANSACTION_LIST(v33);
      v35 = *(_DWORD **)(v6 + 12);
      *v3 = v6 + 8;
      v3[1] = v35;
      if ( *v35 != v6 + 8 )
        __fastfail(3u);
      *v35 = v3;
      *(_DWORD *)(v6 + 12) = v3;
      UNLOCK_TRANSACTION_LIST(v34);
      v3[7] = v6;
      if ( CmpLockIXLockIntent(v15 + 32, v3) && CmpLockIXLockExclusive(v15 + 34, v3, 1) )
      {
        v36 = v43;
        v3[9] = 8;
        v3[12] = *v36;
        v3[13] = v36[1];
        v2 = CmAddLogForAction(v3);
LABEL_63:
        if ( v2 >= 0 )
          goto LABEL_38;
      }
      else
      {
        v2 = -1072103423;
      }
      if ( v3 )
      {
        CmpRundownUnitOfWork(v3);
        CmpFreeUnitOfWork(v3);
      }
      goto LABEL_38;
    }
    if ( CmpTryAcquireIXLockIntent(v15 + 32) )
    {
      if ( CmpTryAcquireIXLockExclusive(v15 + 34) )
      {
        v27 = *(_QWORD *)(v15 + 5);
        CmpLockHiveFlusherShared(v15[5]);
        if ( HvpMarkCellDirty(v27, SHIDWORD(v27), 0, 0) )
        {
          v28 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v27 + 4))(v27, HIDWORD(v27), &v42);
          v29 = v28;
          if ( v28 )
          {
            CmpUpdateKeyNodeAccessBits(v27, v28, SHIDWORD(v27));
            v30 = v43;
            *(_DWORD *)(v29 + 4) = *v43;
            *(_DWORD *)(v29 + 8) = v30[1];
            (*(void (__fastcall **)(_DWORD, int *))(v27 + 8))(v27, &v42);
            v15[22] = *v30;
            v15[23] = v30[1];
          }
          else
          {
            v2 = -1073741670;
          }
        }
        else
        {
          v2 = -1073741443;
        }
        CmpUnlockHiveFlusher(v27);
        goto LABEL_63;
      }
      v18 = v15 + 34;
    }
    else
    {
      v18 = v15 + 32;
    }
    v2 = CmpSnapshotTxOwnerArray(v18, &v38, &v37);
    if ( v2 < 0 )
      goto LABEL_38;
    CmpUnlockKcb(v15);
    CmpUnlockRegistry();
    a1 = (unsigned __int8 *)CmpRollbackTransactionArray(v38, v37, 0, &v40);
    v2 = (int)a1;
    if ( (int)a1 < 0 )
    {
      CmpLockRegistry();
      CmpLockKcbExclusive(v15);
      goto LABEL_38;
    }
    v4 = v41;
  }
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(0);
  return -1073741431;
}
