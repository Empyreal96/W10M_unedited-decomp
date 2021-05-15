// -SmStWorker@-$SMKM_STORE@USM_TRAITS@@@@SAXPAX@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStWorker(int *a1)
{
  int v2; // r4
  int v3; // r10
  int v4; // r2
  int v5; // r1
  int v6; // r5
  int result; // r0
  int v8; // r3
  int v9; // r5
  unsigned int v10; // r2
  unsigned __int8 *v11; // r6
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r3
  unsigned int *v16; // r5
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  _DWORD *v21; // r6
  int i; // r5
  unsigned int v23; // r2
  unsigned __int8 *v24; // r7
  int v25; // r0
  int v26; // r5
  unsigned int v27; // r2
  int v28; // r3
  unsigned int *v29; // r5
  unsigned int v30; // r1
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  unsigned int *v34; // r5
  unsigned int v35; // r1
  int v36; // r0
  unsigned int v37; // r1
  __int16 v38; // r3
  int v39; // [sp+10h] [bp-50h] BYREF
  int v40; // [sp+14h] [bp-4Ch] BYREF
  int v41[2]; // [sp+18h] [bp-48h] BYREF
  int v42; // [sp+20h] [bp-40h] BYREF
  int v43[2]; // [sp+28h] [bp-38h] BYREF
  _DWORD v44[2]; // [sp+30h] [bp-30h] BYREF
  _DWORD v45[10]; // [sp+38h] [bp-28h] BYREF

  v2 = *a1;
  v3 = 0;
  v41[0] = 0;
  IoSetThreadHardErrorMode(0);
  v4 = *(unsigned __int8 *)(v2 + 3518);
  if ( v4 == 4 )
    v5 = *(_DWORD *)(v2 + 3948);
  else
    v5 = `SMKM_STORE<SM_TRAITS>::SmStGetDesiredStoreWorkerPriority'::`2'::PriorityByMemoryCondition[v4];
  KeSetActualBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v5);
  v6 = 0;
  if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
  {
    v42 = 0;
    SmSetThreadPagePriority(&v42, 0);
    v6 = MmSetHardFaultBehavior(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
    if ( v6 >= 0 )
    {
      v3 = 1;
      v41[0] = 1;
    }
  }
  a1[5] = v6;
  result = KeSetEvent(a1 + 1, 0, 0);
  if ( v6 >= 0 )
  {
    v43[0] = v2 + 3600;
    v43[1] = v2 + 3616;
    while ( 1 )
    {
      while ( 1 )
      {
        result = KeWaitForMultipleObjects(2, v43, 1);
        if ( result < 2 )
          break;
        if ( result == 258 )
        {
          if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
          {
            v9 = 20;
            v44[0] = -150000;
            v44[1] = -1;
            while ( *(_DWORD *)(v2 + 3868) && v9 && *(unsigned __int8 *)(v2 + 3518) >= 3u )
            {
              KeDelayExecutionThread(0, 0, v44);
              --v9;
            }
            v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v10 + 310);
            v11 = (unsigned __int8 *)(v2 + 3520);
            v12 = KeAbPreAcquire(v2 + 3520, 0, 0);
            v13 = v12;
            do
              v14 = __ldrex(v11);
            while ( __strex(v14 | 1, v11) );
            __dmb(0xBu);
            if ( (v14 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v2 + 3520, v12, v2 + 3520);
            if ( v13 )
              *(_BYTE *)(v13 + 14) |= 1u;
            v15 = *(_DWORD *)(v2 + 3528);
            *(_DWORD *)(v2 + 3524) = 1;
            *(_DWORD *)(v2 + 3528) = v15 + 1;
          }
          ST_STORE<SM_TRAITS>::StDrainReadContextList(v2);
          ST_STORE<SM_TRAITS>::StLazyWorkMgrIdleTimeoutProcess(v2 + 3280);
          if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
          {
            v16 = (unsigned int *)(v2 + 3520);
            __dmb(0xBu);
            do
              v17 = __ldrex(v16);
            while ( __strex(v17 - 1, v16) );
            if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
              ExfTryToWakePushLock(v2 + 3520);
            v18 = KeAbPostRelease(v2 + 3520);
            v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v20 = *(_WORD *)(v19 + 0x136) + 1;
            *(_WORD *)(v19 + 310) = v20;
            if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
              KiCheckForKernelApcDelivery(v18);
          }
LABEL_41:
          KeResetEvent(v43[0]);
          v21 = (_DWORD *)SMKM_STORE<SM_TRAITS>::SmStWorkItemGet(v2, &v40);
          if ( !v21 )
            return sub_5254EC(0, 0);
LABEL_43:
          if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
          {
            v45[0] = -150000;
            v45[1] = -1;
            for ( i = 20; *(_DWORD *)(v2 + 3868) && i && *(unsigned __int8 *)(v2 + 3518) >= 3u; --i )
              KeDelayExecutionThread(0, 0, v45);
            v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v23 + 310);
            v24 = (unsigned __int8 *)(v2 + 3520);
            v25 = KeAbPreAcquire(v2 + 3520, 0, 0);
            v26 = v25;
            do
              v27 = __ldrex(v24);
            while ( __strex(v27 | 1, v24) );
            __dmb(0xBu);
            if ( (v27 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v2 + 3520, v25, v2 + 3520);
            if ( v26 )
              *(_BYTE *)(v26 + 14) |= 1u;
            v28 = *(_DWORD *)(v2 + 3528);
            *(_DWORD *)(v2 + 3524) = 1;
            *(_DWORD *)(v2 + 3528) = v28 + 1;
          }
          if ( (*(_BYTE *)(v2 + 3517) & 1) == 0 || v40 )
          {
            if ( (*(_BYTE *)(v2 + 3517) & 2) == 0 || (*v21 & 7) != 0 )
            {
              v39 = ST_STORE<SM_TRAITS>::StWorkItemProcess(v2, v21);
              if ( v39 == 259 )
                goto LABEL_59;
            }
            else
            {
              v39 = -1073741058;
            }
            if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
            {
              v34 = (unsigned int *)(v2 + 3520);
              __dmb(0xBu);
              do
                v35 = __ldrex(v34);
              while ( __strex(v35 - 1, v34) );
              if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
                ExfTryToWakePushLock(v2 + 3520);
              v36 = KeAbPostRelease(v2 + 3520);
              v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v38 = *(_WORD *)(v37 + 0x136) + 1;
              *(_WORD *)(v37 + 310) = v38;
              if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 )
                KiCheckForKernelApcDelivery(v36);
            }
            SmWorkItemFree(v2, v21, &v39);
          }
          else
          {
            ST_STORE<SM_TRAITS>::StStoreWorkItemCleanup(v2, v21);
LABEL_59:
            if ( (*(_BYTE *)(v2 + 3517) & 4) != 0 )
            {
              v29 = (unsigned int *)(v2 + 3520);
              __dmb(0xBu);
              do
                v30 = __ldrex(v29);
              while ( __strex(v30 - 1, v29) );
              if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
                ExfTryToWakePushLock(v2 + 3520);
              v31 = KeAbPostRelease(v2 + 3520);
              v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v33 = *(_WORD *)(v32 + 0x136) + 1;
              *(_WORD *)(v32 + 310) = v33;
              if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 )
                KiCheckForKernelApcDelivery(v31);
            }
          }
          v21 = (_DWORD *)SMKM_STORE<SM_TRAITS>::SmStWorkItemGet(v2, &v40);
          if ( !v21 )
            continue;
          goto LABEL_43;
        }
      }
      if ( result == 1 )
        break;
      if ( !result )
        goto LABEL_41;
    }
    v3 = v41[0];
  }
  if ( v3 )
    result = MmSetHardFaultBehavior(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
  v41[0] = -150000;
  v41[1] = -1;
  while ( 1 )
  {
    v8 = *(_DWORD *)(v2 + 3952);
    __dmb(0xBu);
    if ( !v8 )
      break;
    result = KeDelayExecutionThread(0, 0, v41);
  }
  return result;
}
