// -StDmLazyRegionsWorker@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmLazyRegionsWorker(int a1, char a2)
{
  int v3; // r9
  int v4; // r8
  unsigned __int16 *v5; // r2
  unsigned int v6; // r5
  bool v7; // r10
  unsigned int v8; // r6
  unsigned int v9; // r0
  unsigned int v10; // r5
  _DWORD *v11; // r3
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r2
  int v15; // r0
  int v16; // r0
  int v17; // r5
  int v18; // r4
  int v19; // r4
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r5
  int v23; // r2
  unsigned int v24; // r3
  int v25; // r3
  __int16 v26; // r2
  unsigned int v28; // [sp+8h] [bp-28h] BYREF
  int v29; // [sp+Ch] [bp-24h]
  unsigned int v30; // [sp+10h] [bp-20h]

  v29 = 0;
  v3 = 0;
  v4 = a1 + 136;
  __dmb(0xBu);
  v5 = (unsigned __int16 *)(a1 + 144);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 & 0xFFFE, v5) );
  __dmb(0xBu);
  *(_WORD *)(a1 + 146) &= 0xFFFEu;
  v7 = (a2 & 1) != 0;
  v8 = 0;
  v28 = 0;
  do
  {
LABEL_4:
    v9 = RtlFindNextForwardRunClearCapped((unsigned int *)(a1 + 120), v8, 0xFFFFFFFF, &v28);
    if ( !v9 )
    {
      v25 = 0;
      goto LABEL_36;
    }
    v8 = v28;
    v10 = v9 + v28;
    v30 = v9 + v28;
  }
  while ( v28 >= v9 + v28 );
  while ( 1 )
  {
    if ( (++v29 & 0xF) != 0 )
      goto LABEL_9;
    v11 = *(_DWORD **)(a1 + 92);
    v12 = v11[892];
    __dmb(0xBu);
    v13 = v11[893];
    __dmb(0xBu);
    if ( v11[967] + (v13 >> 8) + v12 )
      break;
    v8 = v28;
LABEL_9:
    if ( *(_BYTE *)(a1 + 72) )
      v14 = 0;
    else
      v14 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * v8) >> 13;
    if ( v8 != *(_DWORD *)(a1 + 12 * v14 + 392) )
      v14 = 8;
    if ( v14 != 8 )
    {
LABEL_31:
      *(_BYTE *)((v8 >> 3) + *(_DWORD *)(a1 + 124)) |= 1 << (v8 & 7);
      goto LABEL_32;
    }
    if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v8) & 0x1FFF) != 0 )
    {
      v19 = *(_DWORD *)(a1 + 92);
      if ( !SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(v19, v8) )
        goto LABEL_31;
      if ( (*(_BYTE *)(v19 + 3517) & 4) != 0 )
      {
        v21 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(v19, v20, 0, 8, 8u);
        goto LABEL_30;
      }
      v22 = *(_DWORD *)(v19 + 3660);
      v23 = *(_DWORD *)(v22 + 4 * v8);
      v24 = v23 & 0xFFFFFFF8;
      if ( (v23 & 3) != 0 )
      {
        v21 = *(_DWORD *)(v24 + 12);
      }
      else
      {
        v21 = SmFpAllocate(v19 + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v24);
        if ( !v21 )
          goto LABEL_29;
      }
      *(_DWORD *)(v22 + 4 * v8) |= 1u;
LABEL_29:
      v10 = v30;
LABEL_30:
      if ( v21 != 3 )
        goto LABEL_31;
      goto LABEL_20;
    }
    v15 = *(_DWORD *)(a1 + 92);
    if ( (*(_BYTE *)(v15 + 3517) & 4) != 0 )
    {
      v16 = SMKM_STORE<SM_TRAITS>::SmStReleaseVirtualRegion(v15, v8, v7 | 2);
    }
    else
    {
      v17 = *(_DWORD *)(v15 + 3660);
      v18 = *(_DWORD *)(v17 + 4 * v8);
      MiFreePagesFromMdl(MiSystemPartition, v18 & 0xFFFFFFF8, 0);
      ExFreePoolWithTag(v18 & 0xFFFFFFF8);
      *(_DWORD *)(v17 + 4 * v8) = 0;
      v10 = v30;
      v16 = 0;
    }
    if ( v16 >= 0 )
      goto LABEL_31;
LABEL_20:
    v3 = 1;
LABEL_32:
    v28 = ++v8;
    if ( v8 >= v10 )
      goto LABEL_4;
  }
  v25 = 1;
  v3 = 1;
LABEL_36:
  v26 = *(_WORD *)(v4 + 8);
  if ( (v26 & 1) != 0 || v3 )
  {
    if ( v25 )
      *(_WORD *)(v4 + 10) |= 1u;
    if ( (v26 & 1) == 0 )
      ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(a1, v4);
  }
  return 0;
}
