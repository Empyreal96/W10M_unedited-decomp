// -SmFeEvictComplete@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAT_SM_PAGE_KEY@@KK@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictComplete(int a1, int *a2, unsigned __int16 *a3, int a4)
{
  char v4; // r7
  int v7; // r9
  int v8; // r10
  unsigned int v9; // r4
  unsigned __int8 *v10; // r8
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r3
  unsigned __int16 *v15; // r8
  int v16; // r0
  unsigned int v17; // r4
  unsigned __int16 *v18; // r5
  int v19; // r3
  unsigned __int16 *v20; // r3
  unsigned int v21; // r7
  int v22; // r0
  int *v23; // r2
  int *v24; // r3
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned __int16 *v30; // [sp+0h] [bp-88h] BYREF
  unsigned int v31; // [sp+4h] [bp-84h]
  int v32; // [sp+8h] [bp-80h]
  int v33[6]; // [sp+10h] [bp-78h] BYREF
  char v34; // [sp+28h] [bp-60h] BYREF

  v4 = a4;
  v30 = a3;
  v32 = a4;
  memset(v33, 0, sizeof(v33));
  v33[3] = 0;
  v7 = *a2;
  v33[4] = 8;
  v33[0] = (int)&v34;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 310);
  v10 = (unsigned __int8 *)(a1 + 3192);
  v11 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( __strex(v13 | 1, v10) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), v11, a1 + 3192);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v14 = *(_DWORD *)(a1 + 3204);
  if ( ((1 << v4) & v14) == 0 )
  {
    v15 = v30;
    while ( 1 )
    {
      v16 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
              (unsigned __int16 **)(a1 + 3196),
              v7,
              (int)v33,
              v14);
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
        v16,
        &v30,
        v33);
      v18 = v30;
      v17 = v31;
      if ( v30 )
      {
        v19 = *v30;
        v17 = v31 + 8;
        v31 = v17;
        if ( v17 < (unsigned int)&v30[4 * v19 + 4] )
          goto LABEL_14;
        v20 = (unsigned __int16 *)*((_DWORD *)v30 + 1);
        if ( v20 )
          break;
      }
      v21 = 0;
LABEL_15:
      v22 = *(_DWORD *)(a1 + 5788);
      if ( v22 && *(_DWORD *)(a1 + 5784) == *(_DWORD *)v21 )
        v22 = KeSetEvent(v22, 0, 0);
      *(_BYTE *)(v21 + 6) = 0;
      if ( v33[3] == -1 || !v33[3] )
        v23 = &v33[1];
      else
        v23 = (int *)(v33[0] + 8 * v33[3] - 8);
      v24 = (int *)*v23;
      if ( (unsigned __int16 *)*v23 == v18 )
        goto LABEL_25;
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(
        v22,
        (int)v33);
      v24 = (int *)v33[3];
      if ( v33[3] == -1 )
      {
        *v23 = (int)v18;
LABEL_25:
        v23[1] = v17;
        goto LABEL_31;
      }
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
        (unsigned __int16 **)(a1 + 3196),
        *((_DWORD *)v18 + 2),
        (int)v33,
        v33[3]);
      v23 = (int *)v33[3];
      if ( v33[3] == -1 || !v33[3] )
        v24 = &v33[1];
      else
        v24 = (int *)(v33[0] + 8 * v33[3] - 8);
      v24[1] = v17;
LABEL_31:
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(
        (unsigned __int16 **)(a1 + 3196),
        v33,
        (int)v23,
        v24);
      if ( (unsigned __int16 *)++v8 == v15 )
      {
        v4 = v32;
        v10 = (unsigned __int8 *)(a1 + 3192);
        goto LABEL_34;
      }
      ++v7;
    }
    v17 = (unsigned int)(v20 + 4);
    v30 = (unsigned __int16 *)*((_DWORD *)v30 + 1);
    v31 = (unsigned int)(v20 + 4);
    v18 = v20;
LABEL_14:
    v21 = v17;
    goto LABEL_15;
  }
LABEL_34:
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)v10);
  while ( __strex(v25 - 1, (unsigned int *)v10) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v10);
  v26 = KeAbPostRelease((unsigned int)v10);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x136) + 1;
  *(_WORD *)(v27 + 310) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 )
    KiCheckForKernelApcDelivery(v26);
  return SmKmStoreDeleteWhenEmpty(a1, *(_DWORD **)(96 * (v4 & 0x1F) + a1), 0, 96 * (v4 & 0x1F));
}
