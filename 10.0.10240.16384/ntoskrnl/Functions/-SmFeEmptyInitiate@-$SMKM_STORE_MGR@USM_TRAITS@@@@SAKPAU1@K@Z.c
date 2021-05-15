// -SmFeEmptyInitiate@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEmptyInitiate(int a1, int a2)
{
  char v2; // r9
  int v4; // r8
  unsigned int v5; // r2
  unsigned __int8 *v6; // r7
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned __int16 *v10; // r4
  unsigned int v11; // r5
  int v12; // r9
  int v13; // r3
  int v14; // r4
  int v15; // r7
  int v16; // r10
  int v17; // r0
  int v18; // r3
  unsigned __int16 *v19; // r3
  unsigned int v20; // r2
  int *v21; // r2
  int *v22; // r3
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  unsigned __int16 *v28; // [sp+0h] [bp-90h] BYREF
  unsigned __int16 *v29; // [sp+4h] [bp-8Ch]
  unsigned __int8 *v30; // [sp+8h] [bp-88h]
  int v31; // [sp+Ch] [bp-84h]
  int v32; // [sp+10h] [bp-80h]
  int v33[6]; // [sp+18h] [bp-78h] BYREF
  char v34; // [sp+30h] [bp-60h] BYREF

  v2 = a2;
  v31 = a2;
  memset(v33, 0, sizeof(v33));
  v33[0] = (int)&v34;
  v33[3] = 0;
  v33[4] = 8;
  v32 = 0;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 310);
  v6 = (unsigned __int8 *)(a1 + 3192);
  v30 = (unsigned __int8 *)(a1 + 3192);
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
  v28 = 0;
  v29 = 0;
  if ( v10 )
  {
    while ( !*((_BYTE *)v10 + 3) )
      v10 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
    v28 = v10;
    v29 = v10;
    v11 = (unsigned int)v10;
  }
  else
  {
    v11 = 0;
    v10 = 0;
  }
  v12 = 1 << v2;
  v13 = *(_DWORD *)(a1 + 3204);
  if ( (v12 & v13) == 0 )
  {
    v15 = v31;
    v16 = v32;
    while ( 1 )
    {
      if ( v4 )
      {
        v17 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
                (unsigned __int16 **)(a1 + 3196),
                v16,
                (int)v33,
                v13);
        v7 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
               v17,
               &v28,
               v33);
        v10 = v28;
        v11 = (unsigned int)v29;
        v4 = 0;
      }
      if ( !v10 )
      {
LABEL_39:
        v6 = v30;
        v14 = 1;
        *(_DWORD *)(a1 + 3204) |= v12;
        goto LABEL_40;
      }
      v18 = *v10;
      v11 += 8;
      v29 = (unsigned __int16 *)v11;
      if ( v11 < (unsigned int)&v10[4 * v18 + 4] )
        goto LABEL_22;
      v19 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
      if ( v19 )
        break;
      v20 = 0;
LABEL_23:
      if ( !v20 )
        goto LABEL_39;
      v13 = *(unsigned __int16 *)(v20 + 4);
      if ( v13 == v15 )
      {
        v16 = *(_DWORD *)v20;
        *(_BYTE *)(v20 + 6) = 0;
        if ( v33[3] == -1 || !v33[3] )
          v21 = &v33[1];
        else
          v21 = (int *)(v33[0] + 8 * v33[3] - 8);
        v22 = (int *)*v21;
        if ( (unsigned __int16 *)*v21 == v10 )
          goto LABEL_32;
        B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(
          v7,
          (int)v33);
        v22 = (int *)v33[3];
        if ( v33[3] == -1 )
        {
          *v21 = (int)v10;
LABEL_32:
          v21[1] = v11;
          goto LABEL_38;
        }
        B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
          (unsigned __int16 **)(a1 + 3196),
          *((_DWORD *)v10 + 2),
          (int)v33,
          v33[3]);
        v21 = (int *)v33[3];
        if ( v33[3] == -1 || !v33[3] )
          v22 = &v33[1];
        else
          v22 = (int *)(v33[0] + 8 * v33[3] - 8);
        v22[1] = v11;
LABEL_38:
        v7 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(
               (unsigned __int16 **)(a1 + 3196),
               v33,
               (int)v21,
               v22);
        v4 = 1;
      }
    }
    v11 = (unsigned int)(v19 + 4);
    v28 = (unsigned __int16 *)*((_DWORD *)v10 + 1);
    v29 = v19 + 4;
    v10 = v19;
LABEL_22:
    v20 = v11;
    goto LABEL_23;
  }
  v14 = 0;
LABEL_40:
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)v6);
  while ( __strex(v23 - 1, (unsigned int *)v6) );
  if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  v24 = KeAbPostRelease((unsigned int)v6);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x136) + 1;
  *(_WORD *)(v25 + 310) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 )
    KiCheckForKernelApcDelivery(v24);
  return v14;
}
