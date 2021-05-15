// -SmStWorkItemGet@-$SMKM_STORE@USM_TRAITS@@@@SAPAU_ST_WORK_ITEM@-$ST_STORE@USM_TRAITS@@@@PAU1@PAK@Z 
 
_DWORD *__fastcall SMKM_STORE<SM_TRAITS>::SmStWorkItemGet(int a1, _DWORD *a2)
{
  unsigned int *v3; // r7
  int v5; // r9
  unsigned int v6; // r2
  unsigned int *v7; // r2
  int *v8; // r0
  _DWORD *v9; // r5
  bool v10; // zf
  int v11; // r3
  unsigned int *v12; // r2
  int *v13; // r0
  int v14; // r3
  int v15; // r3
  int v16; // r0
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r1
  unsigned int *v21; // r2
  int *v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r6
  int i; // r2
  unsigned __int64 v27; // kr00_8
  unsigned int v28; // r0
  unsigned int v29; // r2
  int vars4; // [sp+24h] [bp+4h]

  v3 = (unsigned int *)(a1 + 3536);
  *a2 = 0;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v6 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  v7 = (unsigned int *)(a1 + 3560);
  v8 = *(int **)(a1 + 3564);
  if ( v8 == (int *)(a1 + 3560) )
  {
    v12 = (unsigned int *)(a1 + 3544);
    v13 = *(int **)(a1 + 3548);
    if ( v13 == (int *)(a1 + 3544) )
    {
      v15 = *(_DWORD *)(a1 + 3576);
      __dmb(0xBu);
      if ( !v15 )
      {
        v16 = KeQueryPriorityThread(*(_DWORD *)(a1 + 3648));
        v17 = *(unsigned __int8 *)(a1 + 3518);
        v18 = v17 == 4 ? *(_DWORD *)(a1 + 3948) : `SMKM_STORE<SM_TRAITS>::SmStGetDesiredStoreWorkerPriority'::`2'::PriorityByMemoryCondition[v17];
        if ( v16 > v18 )
        {
          v19 = *(unsigned __int8 *)(a1 + 3518);
          if ( v19 == 4 )
            v20 = *(_DWORD *)(a1 + 3948);
          else
            v20 = `SMKM_STORE<SM_TRAITS>::SmStGetDesiredStoreWorkerPriority'::`2'::PriorityByMemoryCondition[v19];
          KeSetActualBasePriorityThread(*(_DWORD *)(a1 + 3648), v20);
        }
      }
      v21 = (unsigned int *)(a1 + 3552);
      v22 = *(int **)(a1 + 3556);
      if ( v22 == (int *)(a1 + 3552) )
      {
        v9 = 0;
      }
      else
      {
        v9 = (_DWORD *)*v21;
        v10 = *v21 == (_DWORD)v22;
        *v21 = *(_DWORD *)*v21 & 0xFFFFFFF8;
        if ( v10 )
        {
          *v21 = 0;
          *(_DWORD *)(a1 + 3556) = a1 + 3552;
        }
        else
        {
          *v22 = *v22 & 7 | (8 * ((unsigned int)*v22 >> 3) - 8);
        }
        v23 = *(_DWORD *)(a1 + 3572) - 1;
        __dmb(0xBu);
        *(_DWORD *)(a1 + 3572) = v23;
        v24 = *(_DWORD *)(a1 + 3572);
        __dmb(0xBu);
        if ( !v24 && (*v9 & 7) == 6 )
        {
          v25 = *(_DWORD *)(a1 + 3648);
          if ( KeQueryPriorityThread(v25) > 4 )
            KeSetActualBasePriorityThread(v25, 4);
        }
      }
    }
    else
    {
      v9 = (_DWORD *)*v12;
      v10 = *v12 == (_DWORD)v13;
      *v12 = *(_DWORD *)*v12 & 0xFFFFFFF8;
      if ( v10 )
      {
        *v12 = 0;
        *(_DWORD *)(a1 + 3548) = a1 + 3544;
      }
      else
      {
        *v13 = *v13 & 7 | (8 * ((unsigned int)*v13 >> 3) - 8);
      }
      v14 = *(_DWORD *)(a1 + 3568) - 1;
      __dmb(0xBu);
      *(_DWORD *)(a1 + 3568) = v14;
    }
  }
  else
  {
    v9 = (_DWORD *)*v7;
    v10 = *v7 == (_DWORD)v8;
    *v7 = *(_DWORD *)*v7 & 0xFFFFFFF8;
    if ( v10 )
    {
      *v7 = 0;
      *(_DWORD *)(a1 + 3564) = a1 + 3560;
    }
    else
    {
      *v8 = *v8 & 7 | (8 * ((unsigned int)*v8 >> 3) - 8);
    }
    v11 = *(_DWORD *)(a1 + 3572);
    __dmb(0xBu);
    *(_DWORD *)(a1 + 3572) = v11 - 1;
    *a2 = 1;
  }
  if ( !v9 )
    goto LABEL_42;
  KeQueryTickCount((int *)(a1 + 3584));
  if ( (*v9 & 7) != 2 || !*(_BYTE *)(a1 + 3516) )
    goto LABEL_43;
  for ( i = *(_DWORD *)(*(_DWORD *)(a1 + 1592) + 16); *(_DWORD *)i < *((unsigned __int8 *)v9 + 4) << 12; i += 32 )
    ;
  v27 = *(_QWORD *)(i + 8);
  v28 = *(_DWORD *)(a1 + 3596);
  v29 = *(_DWORD *)(a1 + 3592);
  if ( __PAIR64__(v28, v29) > v27 )
  {
    *(_QWORD *)(a1 + 3592) = __PAIR64__(v28, v29) - v27;
  }
  else
  {
LABEL_42:
    *(_DWORD *)(a1 + 3596) = 0;
    *(_DWORD *)(a1 + 3592) = 0;
  }
LABEL_43:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v5);
  return v9;
}
