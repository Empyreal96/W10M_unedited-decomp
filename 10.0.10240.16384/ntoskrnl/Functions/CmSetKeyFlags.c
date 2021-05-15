// CmSetKeyFlags 
 
int __fastcall CmSetKeyFlags(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r6
  int v4; // r7
  int v6; // r8
  _DWORD *v7; // r9
  int v8; // r3
  int i; // r3
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r6
  __int64 v19; // kr00_8
  int v20; // r0
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned __int8 *v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r1
  unsigned int v27; // r1
  __int16 v28; // r3
  _DWORD *v30; // r0
  _DWORD *v31; // r1
  int v32; // r0
  int v33; // r0
  _DWORD *v34; // r1
  int v35; // r8
  int v36; // r0
  int v37; // r8
  __int16 v38; // r3
  __int16 v39; // r3
  __int16 v40; // r3
  unsigned int v41; // r3
  int v42; // r4
  int v43; // r5
  int v45; // [sp+14h] [bp-54h] BYREF
  int v46; // [sp+18h] [bp-50h] BYREF
  int v47; // [sp+1Ch] [bp-4Ch]
  BOOL v48; // [sp+20h] [bp-48h]
  BOOL v49; // [sp+24h] [bp-44h]
  int v50; // [sp+28h] [bp-40h] BYREF
  int v51; // [sp+2Ch] [bp-3Ch] BYREF
  int v52; // [sp+30h] [bp-38h]
  int v53; // [sp+34h] [bp-34h]
  int v54; // [sp+38h] [bp-30h] BYREF
  int v55; // [sp+3Ch] [bp-2Ch]
  _DWORD v56[10]; // [sp+40h] [bp-28h] BYREF

  v54 = -1;
  v3 = a1;
  v4 = 0;
  v50 = 0;
  v51 = 0;
  v6 = 0;
  v7 = 0;
  if ( a2 == 1 )
  {
    if ( (a3 & 0xFFFFFFF0) != 0 )
      return -1073741811;
  }
  else if ( a2 == 2 )
  {
    v8 = 1;
    goto LABEL_7;
  }
  v8 = 0;
LABEL_7:
  v47 = v8;
  v49 = a2 == 3;
  v48 = a2 == 4;
  for ( i = 0; ; i = v52 )
  {
    if ( i )
    {
      __pld(&CmpShutdownRundown);
      v10 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v11 == v10 && __strex(v10 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v11 != v10 )
        v10 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v10);
    }
    v14 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v14 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v15 = CmpShutdownRundown & 0xFFFFFFFE;
    v16 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v15 && __strex(v16, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v17 != v15 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
      break;
    v52 = 1;
    KeQuerySystemTime(v56);
    CmpLockRegistry();
    v18 = v3[1];
    CmpLockKcbExclusive((_DWORD *)v18);
    v19 = *(_QWORD *)(v18 + 20);
    v53 = *(_DWORD *)(v18 + 24);
    v55 = a1[7];
    if ( v55 || a1[8] )
    {
      if ( CmRmIsKCBDeleted(v18, v6) == 1 )
        goto LABEL_93;
      v4 = CmpSearchAddTrans((int)a1, 0, 0, v55, a1[8], 0, &v50);
      if ( v4 < 0 )
        goto LABEL_48;
      if ( (*(_DWORD *)(*(_DWORD *)(v18 + 20) + 92) & 2) != 0 )
      {
        v4 = -1072103423;
        goto LABEL_48;
      }
      v6 = v50;
    }
    v20 = CmRmIsKCBDeleted(v18, v6);
    if ( v20 == 1 )
    {
LABEL_93:
      if ( (a1[6] & 1) != 0 )
        v4 = -1073740763;
      else
        v4 = -1073741444;
LABEL_48:
      CmpUnlockKcb((_DWORD *)v18);
      CmpUnlockRegistry();
      __pld(&CmpShutdownRundown);
      v25 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v26 == v25 && __strex(v25 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v26 != v25 )
        v24 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = *(_WORD *)(v27 + 0x134) + 1;
      *(_WORD *)(v27 + 308) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
        KiCheckForKernelApcDelivery((int)v24);
      return v4;
    }
    if ( v6 && !v47 && !v49 && !v48 )
    {
      v7 = (_DWORD *)CmpAllocateUnitOfWork(v20);
      if ( !v7 )
      {
        v4 = -1073741670;
        goto LABEL_48;
      }
      v30 = *(_DWORD **)(v18 + 112);
      v31 = v7 + 4;
      v7[4] = v18 + 108;
      v7[5] = v30;
      if ( *v30 != v18 + 108 )
        __fastfail(3u);
      *v30 = v31;
      *(_DWORD *)(v18 + 112) = v31;
      v32 = CmpReferenceKeyControlBlock((unsigned int *)v18);
      v7[6] = v18;
      v33 = LOCK_TRANSACTION_LIST(v32);
      v34 = *(_DWORD **)(v6 + 12);
      *v7 = v6 + 8;
      v7[1] = v34;
      if ( *v34 != v6 + 8 )
        __fastfail(3u);
      *v34 = v7;
      *(_DWORD *)(v6 + 12) = v7;
      UNLOCK_TRANSACTION_LIST(v33);
      v7[7] = v6;
      if ( CmpLockIXLockIntent(v18 + 128, v7) && CmpLockIXLockExclusive(v18 + 136, v7, 1) )
      {
        v7[9] = 7;
        v7[12] = a3;
        v4 = CmAddLogForAction(v7);
LABEL_88:
        if ( v4 >= 0 )
          goto LABEL_48;
      }
      else
      {
        v4 = -1072103423;
      }
      if ( v7 )
      {
        CmpRundownUnitOfWork(v7);
        CmpFreeUnitOfWork(v7);
      }
      goto LABEL_48;
    }
    if ( CmpTryAcquireIXLockIntent((_DWORD *)(v18 + 128)) )
    {
      if ( CmpTryAcquireIXLockExclusive((_DWORD *)(v18 + 136)) )
      {
        CmpLockHiveFlusherShared(v19);
        v35 = v53;
        if ( !HvpMarkCellDirty(v19, v53, 0, 0) )
        {
          v4 = -1073741443;
LABEL_87:
          CmpUnlockHiveFlusher(v19);
          goto LABEL_88;
        }
        v36 = (*(int (__fastcall **)(_DWORD, int, int *))(v19 + 4))(v19, v35, &v54);
        v37 = v36;
        if ( !v36 )
        {
          v4 = -1073741670;
          goto LABEL_87;
        }
        CmpUpdateKeyNodeAccessBits(v19, v36, v53);
        if ( v47 )
        {
          *(_DWORD *)(v37 + 52) ^= (*(_DWORD *)(v37 + 52) ^ (a3 << 20)) & 0xF00000;
          *(_DWORD *)(v18 + 104) ^= ((unsigned __int8)*(_DWORD *)(v18 + 104) ^ (unsigned __int8)*(_WORD *)(v37 + 54)) & 0xF0;
          if ( (a3 & 2) != 0 )
          {
            *(_WORD *)(v37 + 2) &= 0xFF7Fu;
            v38 = *(_WORD *)(v18 + 106) & 0xFF7F;
            goto LABEL_84;
          }
        }
        else if ( v48 )
        {
          *(_BYTE *)(v37 + 55) = a3;
          *(_BYTE *)(v18 + 105) = *(_BYTE *)(v37 + 55);
        }
        else if ( v49 )
        {
          v39 = *(_WORD *)(v37 + 2);
          if ( (a3 & 4) != 0 )
          {
            *(_WORD *)(v37 + 2) = v39 | 0x80;
            v38 = *(_WORD *)(v18 + 106) | 0x80;
          }
          else
          {
            if ( (a3 & 1) != 0 )
            {
              *(_WORD *)(v37 + 2) = v39 | 0x300;
              v40 = *(_WORD *)(v18 + 106) | 0x300;
            }
            else
            {
              *(_WORD *)(v37 + 2) = v39 & 0xFEFF;
              v40 = *(_WORD *)(v18 + 106) & 0xFEFF;
            }
            *(_WORD *)(v18 + 106) = v40;
            if ( (a3 & 2) == 0 )
              goto LABEL_86;
            *(_WORD *)(v37 + 2) |= 0x200u;
            v38 = *(_WORD *)(v18 + 106) | 0x200;
          }
LABEL_84:
          *(_WORD *)(v18 + 106) = v38;
        }
        else
        {
          v41 = *(_DWORD *)(v37 + 52) ^ (*(_DWORD *)(v37 + 52) ^ (a3 << 16)) & 0xF0000;
          *(_DWORD *)(v37 + 52) = v41;
          *(_DWORD *)(v18 + 104) = *(_DWORD *)(v18 + 104) & 0xFFFFFFF0 | HIWORD(v41) & 0xF;
        }
LABEL_86:
        v43 = v56[0];
        v42 = v56[1];
        *(_DWORD *)(v37 + 4) = v56[0];
        *(_DWORD *)(v37 + 8) = v42;
        (*(void (__fastcall **)(_DWORD, int *))(v19 + 8))(v19, &v54);
        *(_DWORD *)(v18 + 88) = v43;
        *(_DWORD *)(v18 + 92) = v42;
        goto LABEL_87;
      }
      v21 = v18 + 136;
    }
    else
    {
      v21 = v18 + 128;
    }
    v4 = CmpSnapshotTxOwnerArray(v21, &v46, &v45);
    if ( v4 < 0 )
      goto LABEL_48;
    CmpUnlockKcb((_DWORD *)v18);
    CmpUnlockRegistry();
    v4 = CmpRollbackTransactionArray(v46, v45, 0, &v51);
    if ( v4 < 0 )
    {
      CmpLockRegistry();
      CmpLockKcbExclusive((_DWORD *)v18);
      goto LABEL_48;
    }
    v3 = a1;
  }
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(0);
  return -1073741431;
}
