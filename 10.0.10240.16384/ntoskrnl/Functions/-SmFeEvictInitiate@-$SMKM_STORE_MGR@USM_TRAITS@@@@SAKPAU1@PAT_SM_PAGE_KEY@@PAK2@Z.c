// -SmFeEvictInitiate@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@PAT_SM_PAGE_KEY@@PAK2@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictInitiate(int a1, int *a2, int a3, int a4)
{
  unsigned int v7; // r4
  int v8; // r4
  unsigned int *v9; // r3
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r7
  _DWORD *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r0
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22[6]; // [sp+8h] [bp-78h] BYREF
  char v23; // [sp+20h] [bp-60h] BYREF

  memset(v22, 0, sizeof(v22));
  v22[3] = 0;
  v22[4] = 8;
  v22[0] = (int)&v23;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 0x136);
  v8 = KeAbPreAcquire((unsigned int)dword_6361F8, 0, 0);
  v9 = dword_6361F8;
  do
    v10 = __ldrex((unsigned __int8 *)dword_6361F8);
  while ( __strex(v10 | 1, (unsigned __int8 *)dword_6361F8) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6361F8, v8, (unsigned int)dword_6361F8);
  if ( v8 )
  {
    v9 = (unsigned int *)(*(unsigned __int8 *)(v8 + 14) | 1);
    *(_BYTE *)(v8 + 14) = (_BYTE)v9;
  }
  v11 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
          (unsigned __int16 **)&dword_6361F8[1],
          *a2,
          (int)v22,
          (int)v9);
  v12 = SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictUpdatePass(v11, a2, a3, a4, v22);
  v13 = v12;
  if ( v12 != 32 )
  {
    v14 = (_DWORD *)((char *)&unk_636208 + 4 * v12);
    __pld(v14);
    v15 = *v14 & 0xFFFFFFFE;
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 + 2, v14) );
    __dmb(0xBu);
    if ( v16 != v15 )
      ExfAcquireRundownProtection(v14);
  }
  __dmb(0xBu);
  do
    v17 = __ldrex(dword_6361F8);
  while ( __strex(v17 - 1, dword_6361F8) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock(dword_6361F8);
  v18 = KeAbPostRelease((unsigned int)dword_6361F8);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x136) + 1;
  *(_WORD *)(v19 + 310) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
    KiCheckForKernelApcDelivery(v18);
  return v13;
}
