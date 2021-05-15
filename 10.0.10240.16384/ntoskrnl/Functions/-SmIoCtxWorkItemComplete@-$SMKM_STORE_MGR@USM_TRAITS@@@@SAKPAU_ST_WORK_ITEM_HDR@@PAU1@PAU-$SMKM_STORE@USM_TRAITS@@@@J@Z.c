// -SmIoCtxWorkItemComplete@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU_ST_WORK_ITEM_HDR@@PAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@J@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxWorkItemComplete(_DWORD *a1, int a2, int a3, int a4)
{
  int *v5; // r4
  int v8; // r7
  int v9; // r0
  int v10; // r2
  int v11; // r1
  unsigned int v12; // r8
  int v13; // r3
  int v14; // r5
  int v15; // r10
  int v16; // r7
  int v18; // [sp+8h] [bp-28h]
  int v19; // [sp+Ch] [bp-24h]

  v5 = (int *)a1[6];
  if ( (unsigned int)v5 <= 1 )
    v19 = 0;
  else
    v19 = *v5;
  v8 = *(_DWORD *)(a3 + 3512);
  v9 = 7;
  v10 = *a1 & 7;
  if ( !v10 || v10 == 2 )
  {
    v12 = a1[2];
    v11 = *(_DWORD *)(v12 + 20) >> 12;
    v18 = v11;
    if ( v10 == 2 )
      v5[1] = 0;
  }
  else
  {
    v11 = 0;
    v18 = 0;
    v12 = 0;
  }
  v13 = *a1 & 7;
  switch ( v13 )
  {
    case 0:
      v9 = SMKM_STORE_MGR<SM_TRAITS>::SmProcessAddCompletion(SmGlobals, a1, v11, a3, a4);
      break;
    case 1:
      if ( (a1[3] & 1) == 0 )
      {
        v9 = SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictComplete((int)SmGlobals, a1 + 1, (unsigned __int16 *)a1[2], v8 & 0x1F);
        *v5 = 0;
        break;
      }
      return 0;
    case 2:
      v15 = a1[6];
      v16 = *((unsigned __int8 *)a1 + 4);
      if ( *(_BYTE *)(a3 + 3516) )
        v9 = SMKM_STORE<SM_TRAITS>::SmStStatsUpdate(a3, a1, a4);
      if ( v16 )
      {
        *(_WORD *)(v15 + 4) = v16;
        if ( (dword_636C80 & 8) != 0 )
          a4 = 0;
      }
      *(_DWORD *)v15 = a4;
      if ( (dword_636C80 & 0x10) != 0 )
        v9 = SmAcquireReleaseResAvailForRead(v5, v18, 1);
      break;
    case 3:
      *v5 = a4;
      v5[1] = a1[2];
      break;
    case 4:
      if ( (a1[1] & 7) != 0 )
        goto LABEL_15;
      SMKM_STORE_MGR<SM_TRAITS>::SmFeEmptyComplete((int)SmGlobals, v8 & 0x1F);
      return 0;
    case 5:
LABEL_15:
      *v5 = a4;
      v5[1] = 0;
      break;
  }
  v14 = 1;
  if ( v12 )
  {
    if ( (*(_WORD *)(v12 + 6) & 5) == 0 )
      v9 = MmMapLockedPagesSpecifyCache(v12, 0, 1, 0, 0, 1073741840);
    if ( (dword_636C80 & 2) != 0 )
      v9 = SmFpFree((int)&unk_636BD8, 4, (int)v5, v12);
  }
  if ( v19 )
    SmIoRequestComplete(v9, a1, v19, v5);
  return v14;
}
