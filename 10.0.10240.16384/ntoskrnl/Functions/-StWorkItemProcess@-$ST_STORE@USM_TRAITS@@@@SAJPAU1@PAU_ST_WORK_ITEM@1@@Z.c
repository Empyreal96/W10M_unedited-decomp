// -StWorkItemProcess@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StWorkItemProcess(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r2
  int v7; // r7
  int v8; // r9
  int v9; // r6
  int v10; // r3
  int v11; // r8
  int v12; // r0
  int v13; // r6
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int v18; // r0
  unsigned int v19; // r3
  unsigned int v20; // r2
  int v21; // r1
  unsigned __int16 *v22; // r2
  unsigned int v23; // r0
  unsigned __int16 *v24; // r2
  unsigned int v25; // r0
  __int64 v26; // kr00_8
  unsigned int v27; // r1
  unsigned int v28; // lr
  __int64 v29; // kr08_8
  unsigned int v30; // r1
  unsigned int v31; // lr
  _DWORD *v32; // r0
  unsigned int v33; // r4
  unsigned int v34; // r1
  int v36; // r0
  _DWORD *v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r4
  char v43; // r3
  int v44; // r0
  char v45; // r3
  char v46; // r4
  int v47; // r0
  int v48; // r0
  int v49[9]; // [sp+4h] [bp-24h] BYREF

  v49[0] = a3;
  v49[1] = a4;
  v4 = a2;
  v5 = a1;
  if ( (a2 & 1) != 0 )
  {
    v6 = 1;
    v4 = a2 & 0xFFFFFFFE;
  }
  else
  {
    v6 = 0;
  }
  v7 = 0;
  v8 = 0;
  v9 = *(_DWORD *)v4 & 7;
  v10 = -1;
  v11 = -1;
  v49[0] = -1;
  if ( !v6 )
    a1 = ST_STORE<SM_TRAITS>::StLazyWorkMgrResetIdle(a1 + 3280);
  switch ( v9 )
  {
    case 0:
      v12 = ST_STORE<SM_TRAITS>::StDmPageAdd(v5 + 56, (_DWORD *)v4);
      goto LABEL_8;
    case 1:
      v12 = ST_STORE<SM_TRAITS>::StDmPageRemove(v5 + 56, v4);
      goto LABEL_8;
    case 2:
      v12 = ST_STORE<SM_TRAITS>::StDmPageRetrieve(v5 + 56, v5 + 300, v4);
      goto LABEL_8;
    case 3:
      v12 = ST_STORE<SM_TRAITS>::StGetStats(v5, v4, v6, v10);
      goto LABEL_8;
    case 4:
      v48 = ST_STORE<SM_TRAITS>::StChangeState(v5, (_DWORD *)v4, v49);
      v11 = v49[0];
      v13 = v48;
      goto LABEL_64;
    case 5:
      v37 = (_DWORD *)(v5 + 56);
      v38 = *(_DWORD *)(v4 + 4) & 7;
      if ( v38 )
      {
        if ( v38 == 1 )
        {
          ST_STORE<SM_TRAITS>::StDmInvalidateCurrentRegions((int)v37);
        }
        else if ( v38 == 3 )
        {
          v39 = ST_STORE<SM_TRAITS>::StDmCheckForCompaction((int)v37, 0);
          if ( v39 )
          {
            v40 = (*(_DWORD *)(v5 + 172) & 2) != 0;
            if ( v39 == 1 )
            {
              if ( *(_BYTE *)(v5 + 128) )
                v41 = 400;
              else
                v41 = 30;
              v42 = -2;
              v43 = *(_BYTE *)(v5 + 812) & 0xFC | 1;
            }
            else
            {
              v43 = *(_BYTE *)(v5 + 812) & 0xFC | 2;
              v41 = 0;
              v42 = 0;
            }
            v44 = *(_DWORD *)(v5 + 816);
            *(_BYTE *)(v5 + 812) = v43;
            ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(v44, v40, v41, v42);
          }
        }
        else
        {
          while ( ST_STORE<SM_TRAITS>::StDmCheckForCompaction((int)v37, 1) )
          {
            v45 = *(_BYTE *)(v5 + 812);
            v46 = v45 & 3;
            *(_BYTE *)(v5 + 812) = v45 | 3;
            v47 = ST_STORE<SM_TRAITS>::StCompactionPerformInMem((_DWORD *)(v5 + 56), 0);
            *(_BYTE *)(v5 + 812) ^= (*(_BYTE *)(v5 + 812) ^ v46) & 3;
            if ( v47 < 0 )
              break;
            v37 = (_DWORD *)(v5 + 56);
          }
        }
      }
      else
      {
        ST_STORE<SM_TRAITS>::StDmEtaRefresh(v37, a2, v6, 0);
      }
      return 0;
    case 6:
      v11 = 259;
      if ( *(_DWORD *)(v4 + 4) != 1 )
        v7 = v4;
      v13 = SMKM_STORE_MGR<SM_TRAITS>::SmStoreActionNotify(a1, *(_DWORD *)(v5 + 20), 1);
      if ( v13 < 0 )
        goto LABEL_64;
      v16 = *(_DWORD *)(v4 + 4);
      v8 = 1;
      v49[0] = 1;
      if ( v16 != 1 )
      {
        if ( v16 == 2 )
        {
          v12 = ST_STORE<SM_TRAITS>::StDmEtaRefresh((_DWORD *)(v5 + 56), v14, v15, 2);
          goto LABEL_8;
        }
        if ( v16 == 3 )
        {
          v13 = ST_STORE<SM_TRAITS>::StMetaRegionsUpdate(v5, v4, v15, 3);
        }
        else
        {
          if ( v16 == 4 )
          {
            v19 = 10000;
            v20 = 1000;
            v21 = 3;
          }
          else
          {
            if ( v16 != 5 )
            {
              if ( v16 != 6 )
              {
                if ( v16 == 7 )
                {
                  __dmb(0xBu);
                  v24 = (unsigned __int16 *)(v4 + 8);
                  do
                    v25 = __ldrex(v24);
                  while ( __strex(v25 & 0xFFFE, v24) );
                  __dmb(0xBu);
                  v7 = 0;
                  do
                  {
                    v26 = MEMORY[0xFFFF93B0];
                    while ( 1 )
                    {
                      v27 = MEMORY[0xFFFF900C];
                      __dmb(0xBu);
                      v28 = MEMORY[0xFFFF9008];
                      __dmb(0xBu);
                      if ( v27 == MEMORY[0xFFFF9010] )
                        break;
                      __dmb(0xAu);
                      __yield();
                    }
                  }
                  while ( v26 != MEMORY[0xFFFF93B0] );
                  if ( __PAIR64__(v27, v28) - *(_QWORD *)(v5 + 3504) - v26 >= (unsigned int)dword_989680
                    && ST_STORE<SM_TRAITS>::StDmCheckForCompaction(v5 + 56, 2) == 2 )
                  {
                    ST_STORE<SM_TRAITS>::StCompactionPerformEmergency(v5 + 56);
                    do
                    {
                      v29 = MEMORY[0xFFFF93B0];
                      while ( 1 )
                      {
                        v30 = MEMORY[0xFFFF900C];
                        __dmb(0xBu);
                        v31 = MEMORY[0xFFFF9008];
                        __dmb(0xBu);
                        if ( v30 == MEMORY[0xFFFF9010] )
                          break;
                        __dmb(0xAu);
                        __yield();
                      }
                    }
                    while ( v29 != MEMORY[0xFFFF93B0] );
                    *(_QWORD *)(v5 + 3504) = __PAIR64__(v30, v31) - v29;
                  }
                  v11 = 259;
                  v8 = v49[0];
                }
                else
                {
                  v13 = -1073741811;
                }
                goto LABEL_64;
              }
              __dmb(0xBu);
              v22 = (unsigned __int16 *)(v4 + 8);
              do
                v23 = __ldrex(v22);
              while ( __strex(v23 & 0xFFFE, v22) );
              __dmb(0xBu);
              goto LABEL_46;
            }
            if ( (*(_WORD *)(v4 + 10) & 1) != 0 )
            {
              v20 = 200;
              v19 = 2000;
            }
            else
            {
              v19 = 30000;
              v20 = 2000;
            }
            v21 = 2;
          }
          ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(*(_DWORD *)(v5 + 816), v21, v20, v19);
        }
LABEL_46:
        v7 = 0;
        goto LABEL_64;
      }
      v17 = *(_DWORD *)(v4 + 12);
      if ( v17 < 0 )
        goto LABEL_64;
      if ( v17 <= 1 )
      {
        if ( v17 )
          v18 = v5 + 824;
        else
          v18 = v5 + 56;
        v12 = ST_STORE<SM_TRAITS>::StCompactionWorker(v18);
        goto LABEL_8;
      }
      switch ( v17 )
      {
        case 2:
          v12 = ST_STORE<SM_TRAITS>::StDmLazyRegionsWorker(v5 + 56, 0);
          goto LABEL_8;
        case 3:
          v12 = ST_STORE<SM_TRAITS>::StDmLazyRemoveKeysWorker(v5 + 56);
LABEL_8:
          v13 = v12;
          break;
        case 4:
          ST_STORE<SM_TRAITS>::StDmInvalidateCurrentRegions(v5 + 56);
          v13 = 0;
          goto LABEL_68;
        case 5:
          v13 = -1073741811;
          goto LABEL_68;
      }
LABEL_64:
      if ( v13 == -1073741818 )
      {
        if ( *(_DWORD *)(v5 + 3272) != 2 )
          SMKM_STORE_MGR<SM_TRAITS>::SmEmptyStore(
            (unsigned __int8 *)SmGlobals,
            *(_DWORD *)(*(_DWORD *)(v5 + 148) + 3512) & 0x1F,
            1);
        ST_STORE<SM_TRAITS>::StEmptyStore(v5, 0);
      }
LABEL_68:
      if ( v7 )
        ST_STORE<SM_TRAITS>::StStoreWorkItemCleanup(v5, v7);
      if ( v8 )
      {
        v32 = &SmGlobals[24 * (*(_DWORD *)(*(_DWORD *)(v5 + 20) + 3512) & 0x1F) + 1];
        __pld(v32);
        v33 = *v32 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v34 = __ldrex(v32);
        while ( v34 == v33 && __strex(v33 - 2, v32) );
        if ( v34 != v33 )
          ExfReleaseRundownProtection((unsigned __int8 *)v32);
      }
      if ( v11 != -1 )
        v13 = v11;
      return v13;
    case 7:
      if ( (*(_DWORD *)(v4 + 16) & 2) != 0 )
        v36 = v5 + 824;
      else
        v36 = v5 + 56;
      ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion(v36, (_DWORD *)v4);
      return 259;
    default:
      v13 = -1073741822;
      goto LABEL_64;
  }
}
