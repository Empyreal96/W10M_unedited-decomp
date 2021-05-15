// -SmFeStoreDelete@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeStoreDelete(int a1, int a2)
{
  int v4; // r8
  unsigned int v5; // r2
  unsigned __int8 *v6; // r6
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned __int16 *v10; // r4
  int v11; // r3
  unsigned int v12; // r5
  int v13; // r9
  int v14; // r0
  int v15; // r3
  unsigned __int16 *v16; // r3
  unsigned int v17; // r2
  int *v18; // r2
  int *v19; // r3
  unsigned int v20; // r1
  int result; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned __int16 *v24; // [sp+0h] [bp-88h] BYREF
  unsigned __int16 *v25; // [sp+4h] [bp-84h]
  int v26; // [sp+8h] [bp-80h]
  int v27[6]; // [sp+10h] [bp-78h] BYREF
  char v28; // [sp+28h] [bp-60h] BYREF

  memset(v27, 0, sizeof(v27));
  v27[0] = (int)&v28;
  v27[3] = 0;
  v27[4] = 8;
  v26 = 0;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 310);
  v6 = (unsigned __int8 *)(a1 + 3192);
  v7 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    v7 = ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), v7, a1 + 3192);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = *(unsigned __int16 **)(a1 + 3196);
  v11 = 0;
  v24 = 0;
  v25 = 0;
  if ( v10 )
  {
    while ( 1 )
    {
      v11 = *((unsigned __int8 *)v10 + 3);
      if ( *((_BYTE *)v10 + 3) )
        break;
      v10 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
    }
    v24 = v10;
    v25 = v10;
    v12 = (unsigned int)v10;
  }
  else
  {
    v12 = 0;
    v10 = 0;
  }
  v13 = v26;
  while ( 1 )
  {
    if ( v4 )
    {
      v14 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
              (unsigned __int16 **)(a1 + 3196),
              v13,
              (int)v27,
              v11);
      v7 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
             v14,
             &v24,
             v27);
      v10 = v24;
      v12 = (unsigned int)v25;
      v4 = 0;
    }
    if ( !v10 )
      break;
    v15 = *v10;
    v12 += 8;
    v25 = (unsigned __int16 *)v12;
    if ( v12 < (unsigned int)&v10[4 * v15 + 4] )
      goto LABEL_20;
    v16 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
    if ( v16 )
    {
      v12 = (unsigned int)(v16 + 4);
      v24 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
      v25 = v16 + 4;
      v10 = v16;
LABEL_20:
      v17 = v12;
      goto LABEL_21;
    }
    v17 = 0;
LABEL_21:
    if ( !v17 )
      break;
    v11 = *(unsigned __int16 *)(v17 + 4);
    if ( v11 == a2 )
    {
      v13 = *(_DWORD *)v17;
      *(_BYTE *)(v17 + 6) = 0;
      if ( v27[3] == -1 || !v27[3] )
        v18 = &v27[1];
      else
        v18 = (int *)(v27[0] + 8 * v27[3] - 8);
      v19 = (int *)*v18;
      if ( (unsigned __int16 *)*v18 == v10 )
        goto LABEL_30;
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(
        v7,
        (int)v27);
      v19 = (int *)v27[3];
      if ( v27[3] == -1 )
      {
        *v18 = (int)v10;
LABEL_30:
        v18[1] = v12;
        goto LABEL_36;
      }
      B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
        (unsigned __int16 **)(a1 + 3196),
        *((_DWORD *)v10 + 2),
        (int)v27,
        v27[3]);
      v18 = (int *)v27[3];
      if ( v27[3] == -1 || !v27[3] )
        v19 = &v27[1];
      else
        v19 = (int *)(v27[0] + 8 * v27[3] - 8);
      v19[1] = v12;
LABEL_36:
      v7 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(
             (unsigned __int16 **)(a1 + 3196),
             v27,
             (int)v18,
             v19);
      v4 = 1;
    }
  }
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v6);
  while ( __strex(v20 - 1, (unsigned int *)v6) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 3192));
  result = KeAbPostRelease(a1 + 3192);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x136) + 1;
  *(_WORD *)(v22 + 310) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
