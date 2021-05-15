// -SmFeAddInitiate@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAT_SM_PAGE_KEY@@KKPAU_SM_QUEUE_CONTEXT@1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeAddInitiate(int a1, unsigned int *a2, unsigned __int16 *a3, int a4, int a5, int a6)
{
  __int16 v6; // r5
  int *v7; // r7
  int v9; // r8
  int v10; // r7
  int v11; // r10
  unsigned int v12; // r2
  unsigned __int8 *v13; // r5
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r3
  int v18; // r0
  int v19; // r3
  int v20; // r4
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r4
  unsigned int v28; // r2
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v38; // [sp+18h] [bp-A0h] BYREF
  __int16 v39; // [sp+1Ch] [bp-9Ch]
  char v40; // [sp+1Eh] [bp-9Ah]
  char v41; // [sp+1Fh] [bp-99h]
  char v42[4]; // [sp+20h] [bp-98h] BYREF
  int v43; // [sp+24h] [bp-94h]
  int v44[2]; // [sp+28h] [bp-90h] BYREF
  int v45; // [sp+30h] [bp-88h]
  int v46; // [sp+34h] [bp-84h]
  int v47[2]; // [sp+38h] [bp-80h] BYREF
  unsigned int *v48[6]; // [sp+40h] [bp-78h] BYREF
  char v49; // [sp+58h] [bp-60h] BYREF

  v6 = a4;
  v7 = (int *)a2;
  v45 = a5;
  memset(v48, 0, sizeof(v48));
  v48[3] = 0;
  v48[4] = (unsigned int *)8;
  v9 = *v7;
  v38 = 0;
  v41 = 0;
  v10 = 0;
  v40 = 1;
  v48[0] = (unsigned int *)&v49;
  v11 = 0;
  v39 = v6;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 310);
  v13 = (unsigned __int8 *)(a1 + 3192);
  v14 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v15 = v14;
  do
  {
    v16 = __ldrex(v13);
    v17 = __strex(v16 | 1, v13);
  }
  while ( v17 );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), v14, a1 + 3192);
  if ( v15 )
  {
    v17 = *(unsigned __int8 *)(v15 + 14) | 1;
    *(_BYTE *)(v15 + 14) = v17;
  }
  while ( 1 )
  {
    B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
      (unsigned __int16 **)(a1 + 3196),
      v9,
      (int)v48,
      v17);
    v18 = SMKM_STORE_MGR<SM_TRAITS>::SmFeAddFirstPass(a1, a2, a3, v48, a4);
    v20 = v18;
    if ( v18 >= 0 )
      break;
    if ( v18 != -1073740682 || v11 || !a6 )
      goto LABEL_38;
    v42[0] = 0;
    v42[1] = 0;
    v42[2] = 4;
    v43 = 0;
    v44[1] = (int)v44;
    v44[0] = (int)v44;
    *(_DWORD *)(a1 + 5788) = v42;
    *(_DWORD *)(a1 + 5784) = v9;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v13);
    while ( __strex(v21 - 1, (unsigned int *)v13) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 3192));
    v22 = KeAbPostRelease(a1 + 3192);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x136) + 1;
    *(_WORD *)(v23 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 )
      KiCheckForKernelApcDelivery(v22);
    v47[0] = -2500000;
    v47[1] = -1;
    v46 = KeWaitForSingleObject((unsigned int)v42, 26, 0, 0, v47);
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v25 + 310);
    v26 = KeAbPreAcquire(a1 + 3192, 0, 0);
    v27 = v26;
    do
      v28 = __ldrex(v13);
    while ( __strex(v28 | 1, v13) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), v26, a1 + 3192);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    *(_DWORD *)(a1 + 5788) = 0;
    v17 = v46;
    if ( v46 )
    {
      v20 = -1073740682;
      goto LABEL_38;
    }
    v11 = 1;
  }
  while ( 1 )
  {
    v38 = v9;
    v29 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
            (unsigned __int16 **)(a1 + 3196),
            v9,
            (int)v48,
            v19);
    v20 = v29;
    if ( v29 == -1073741275 )
    {
      v20 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeInsertEx(
              (unsigned int *)(a1 + 3196),
              v48,
              &v38);
    }
    else
    {
      if ( v29 < 0 )
        break;
      v20 = -1073741484;
    }
    if ( v20 < 0 )
      break;
    v19 = (int)a3;
    if ( (unsigned __int16 *)++v10 == a3 )
    {
      SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxQueueWork(*(_DWORD *)(v45 + 12), a1, a4, v45 | 1);
      v20 = 0;
      goto LABEL_38;
    }
    ++v9;
  }
  if ( v10 )
    SMKM_STORE_MGR<SM_TRAITS>::SmFeAddComplete(a1, (int *)a2, v10, a4, 2);
LABEL_38:
  __dmb(0xBu);
  do
    v30 = __ldrex((unsigned int *)v13);
  while ( __strex(v30 - 1, (unsigned int *)v13) );
  if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 3192));
  v31 = KeAbPostRelease(a1 + 3192);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x136) + 1;
  *(_WORD *)(v32 + 310) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 )
    KiCheckForKernelApcDelivery(v31);
  return v20;
}
