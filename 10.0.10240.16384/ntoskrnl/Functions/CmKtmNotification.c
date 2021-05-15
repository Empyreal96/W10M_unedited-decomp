// CmKtmNotification 
 
int __fastcall CmKtmNotification(int a1, int a2, int a3, int a4)
{
  int v5; // r9
  int v7; // r4
  int v9; // r0
  int v10; // r3
  _DWORD *v11; // r2
  __int64 v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r5
  int v18; // r0
  _DWORD *v19; // r1
  int v20; // r10
  int v21; // r0
  int v22; // r0
  _DWORD *v24; // [sp+8h] [bp-68h]
  int v25; // [sp+10h] [bp-60h] BYREF
  int v26; // [sp+14h] [bp-5Ch]
  int v27; // [sp+18h] [bp-58h]
  unsigned __int16 v28; // [sp+20h] [bp-50h] BYREF
  _BYTE v29[6]; // [sp+22h] [bp-4Eh]
  int v30; // [sp+28h] [bp-48h]
  int v31; // [sp+2Ch] [bp-44h]
  _DWORD v32[4]; // [sp+30h] [bp-40h] BYREF
  _DWORD v33[12]; // [sp+40h] [bp-30h] BYREF

  v30 = 1;
  v31 = 0;
  v32[0] = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v28 = 0;
  *(_DWORD *)v29 = 0;
  *(_WORD *)&v29[4] = 0;
  v5 = 0;
  v32[1] = 0;
  v32[2] = 0;
  v32[3] = 0;
  if ( !CmpIsCmRm(a2) )
    return -1073741811;
  if ( (*(_DWORD *)(a2 + 60) & 8) != 0 )
    return 0;
  if ( a4 == 256 )
    return CmpRecoverEnlistment(a2);
  if ( (a4 & 0xE) == 0 )
    return 0;
  v7 = TmReferenceEnlistmentKey();
  if ( v7 )
    return v7;
  v9 = LOCK_TRANSACTION_LIST(0);
  v10 = v24[16];
  if ( (v10 & 8) == 0 )
  {
    UNLOCK_TRANSACTION_LIST(v9);
    if ( CmRmSystem == a2 )
      v11 = off_60E8A4;
    else
      v11 = *(_DWORD **)(a2 + 48);
    if ( CmpTraceTxrRoutine && CmpQueryNameString(v11[444], &v28) >= 0 )
    {
      LODWORD(v12) = v32;
      HIDWORD(v12) = 0x20000;
      EtwGetKernelTraceTimestamp(v12);
      v13 = v24[11];
      v14 = v24[12];
      v15 = v24[13];
      v33[0] = v24[10];
      v33[1] = v13;
      v33[2] = v14;
      v33[3] = v15;
    }
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( CmpLoadHiveLockOwner == v16 )
    {
      v17 = 0;
    }
    else
    {
      LOCK_HIVE_LOAD();
      v17 = 1;
    }
    if ( !CmpIsCmRm(a2) )
    {
      if ( v17 )
        UNLOCK_HIVE_LOAD();
      TmDereferenceEnlistmentKey();
      v7 = -1073741811;
LABEL_84:
      CmpEtwReleaseHivePath(&v28);
      return v7;
    }
    if ( a4 == 2 )
    {
      v18 = CmpTransMgrPrepare(a2, v24, &v25);
      v27 = 0;
      v26 = v25;
    }
    else
    {
      if ( a4 == 4 )
      {
        v18 = CmpTransMgrCommit(a2, v24);
      }
      else
      {
        if ( a4 != 8 )
        {
          v7 = -1073741811;
LABEL_39:
          v25 = v7;
          if ( v7 >= 0 || a4 == 4 )
          {
            v19 = v24;
            if ( (_DWORD *)v24[2] == v24 + 2 || v7 < 0 )
            {
              v30 = 0;
            }
            else
            {
              v21 = CmLogTmRmAction(a2, v24);
              v19 = v24;
              v7 = v21;
              if ( a4 != 2 )
                v7 = 0;
            }
            v20 = 1;
            if ( a4 == 4 )
            {
LABEL_50:
              if ( v19[8] )
                v31 = v19[9];
              if ( (v19[16] & 0x20) != 0 )
              {
                if ( CmpAccountForLogReservation(a2) >= 0 )
                  v24[16] &= 0xFFFFFFDF;
                v19 = v24;
              }
              if ( v7 < 0 && a4 == 4 )
              {
                CmpQueueLazyCommitWorker(v19);
                v7 = 0;
              }
              else
              {
                CmpCleanupTransactionState(a2, v19, a4, v30);
              }
LABEL_60:
              TmDereferenceEnlistmentKey();
              if ( v17 )
                UNLOCK_HIVE_LOAD();
              if ( v20 != 1 )
                goto LABEL_72;
              if ( a4 != 2 )
              {
                if ( a4 == 4 )
                {
                  TmCommitComplete();
                }
                else if ( a4 == 8 )
                {
                  v22 = TmRollbackComplete();
LABEL_71:
                  v7 = v22;
                  goto LABEL_72;
                }
LABEL_72:
                if ( v31 )
                  ZwClose();
                switch ( a4 )
                {
                  case 2:
                    v5 = 31;
                    break;
                  case 4:
                    v5 = 30;
                    break;
                  case 8:
                    v5 = 32;
                    break;
                }
                if ( CmpTraceTxrRoutine && v5 && *(_DWORD *)&v29[2] )
                  CmpTraceTxrRoutine(v5, v32, v33, v25, v26, &v28);
                goto LABEL_84;
              }
              if ( v27 == 1 )
                v22 = TmReadOnlyEnlistment();
              else
                v22 = TmPrepareComplete();
              goto LABEL_71;
            }
          }
          else
          {
            v19 = v24;
            v20 = 0;
          }
          if ( a4 != 8 && v27 != 1 )
            goto LABEL_60;
          goto LABEL_50;
        }
        v18 = CmpTransMgrRollback(v24);
      }
      v26 = v25;
    }
    v7 = v18;
    goto LABEL_39;
  }
  switch ( a4 )
  {
    case 2:
      v24[16] = v10 | 1;
      UNLOCK_TRANSACTION_LIST(v9);
      return TmPrepareComplete();
    case 4:
      v24[16] = v10 | 4;
      UNLOCK_TRANSACTION_LIST(v9);
      TmCommitComplete();
      return v7;
    case 8:
      v24[16] = v10 | 2;
      UNLOCK_TRANSACTION_LIST(v9);
      return TmRollbackComplete();
  }
  return v7;
}
