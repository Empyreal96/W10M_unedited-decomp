// -SmFeStoreEvictKeys@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAT_SM_PAGE_KEY@@KK@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeStoreEvictKeys(int a1, int *a2, int a3, char a4)
{
  int v7; // r3
  int v8; // r10
  int v9; // r8
  unsigned int v10; // r4
  unsigned __int8 *v11; // r6
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r4
  unsigned __int16 *v17; // r5
  int i; // r6
  int v19; // r0
  int v20; // r3
  unsigned __int16 *v21; // r3
  unsigned int v22; // r2
  int *v23; // r2
  int *v24; // r3
  unsigned int v25; // r1
  int result; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned __int16 *v29; // [sp+0h] [bp-88h] BYREF
  unsigned int v30; // [sp+4h] [bp-84h]
  int v31; // [sp+8h] [bp-80h]
  unsigned __int8 *v32; // [sp+Ch] [bp-7Ch]
  int v33[6]; // [sp+10h] [bp-78h] BYREF
  char v34; // [sp+28h] [bp-60h] BYREF

  v31 = a3;
  memset(v33, 0, sizeof(v33));
  v33[3] = 0;
  v33[4] = 8;
  v7 = *a2;
  v33[0] = (int)&v34;
  v29 = (unsigned __int16 *)v7;
  v8 = 0;
  v9 = 1;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 310);
  v11 = (unsigned __int8 *)(a1 + 3192);
  v32 = (unsigned __int8 *)(a1 + 3192);
  v12 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( __strex(v14 | 1, v11) );
  __dmb(0xBu);
  if ( (v14 & 1) != 0 )
    v12 = ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), v12, a1 + 3192);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  v15 = *(_DWORD *)(a1 + 3204);
  if ( ((1 << a4) & v15) == 0 )
  {
    v17 = v29;
    v16 = v30;
    for ( i = (int)v29; ; ++i )
    {
      if ( v9 )
      {
        v19 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
                (unsigned __int16 **)(a1 + 3196),
                i,
                (int)v33,
                v15);
        v12 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
                v19,
                &v29,
                v33);
        v17 = v29;
        v16 = v30;
        v9 = 0;
      }
      if ( !v17 )
        break;
      v20 = *v17;
      v16 += 8;
      v30 = v16;
      if ( v16 >= (unsigned int)&v17[4 * v20 + 4] )
      {
        v21 = (unsigned __int16 *)*((_DWORD *)v17 + 1);
        if ( !v21 )
          break;
        v16 = (unsigned int)(v21 + 4);
        v29 = (unsigned __int16 *)*((_DWORD *)v17 + 1);
        v30 = (unsigned int)(v21 + 4);
        v17 = v21;
      }
      v22 = v16;
LABEL_17:
      if ( *(_BYTE *)(v22 + 6) != 3 )
        goto LABEL_32;
      *(_BYTE *)(v22 + 6) = 0;
      if ( v33[3] == -1 || !v33[3] )
        v23 = &v33[1];
      else
        v23 = (int *)(v33[0] + 8 * v33[3] - 8);
      v24 = (int *)*v23;
      if ( (unsigned __int16 *)*v23 != v17 )
      {
        B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(
          v12,
          (int)v33);
        v24 = (int *)v33[3];
        if ( v33[3] != -1 )
        {
          B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
            (unsigned __int16 **)(a1 + 3196),
            *((_DWORD *)v17 + 2),
            (int)v33,
            v33[3]);
          v23 = (int *)v33[3];
          if ( v33[3] == -1 || !v33[3] )
            v24 = &v33[1];
          else
            v24 = (int *)(v33[0] + 8 * v33[3] - 8);
          v24[1] = v16;
          goto LABEL_31;
        }
        *v23 = (int)v17;
      }
      v23[1] = v16;
LABEL_31:
      v12 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(
              (unsigned __int16 **)(a1 + 3196),
              v33,
              (int)v23,
              v24);
      v9 = 1;
LABEL_32:
      v15 = v31;
      if ( ++v8 == v31 )
      {
        v11 = v32;
        goto LABEL_35;
      }
    }
    v22 = 0;
    goto LABEL_17;
  }
LABEL_35:
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)v11);
  while ( __strex(v25 - 1, (unsigned int *)v11) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v11);
  result = KeAbPostRelease((unsigned int)v11);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x136) + 1;
  *(_WORD *)(v27 + 310) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
