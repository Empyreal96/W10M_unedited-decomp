// -SmFeSetEvictFailed@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAT_SM_PAGE_KEY@@KK@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeSetEvictFailed(int a1, int *a2, int a3, char a4)
{
  int v6; // r10
  int v7; // r8
  int v8; // r1
  int v9; // r6
  unsigned int *v10; // r3
  unsigned int v11; // r4
  int v12; // r0
  unsigned __int16 *v13; // r0
  unsigned int v14; // r1
  int v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r0
  int result; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  _DWORD v22[2]; // [sp+8h] [bp-80h] BYREF
  int v23[6]; // [sp+10h] [bp-78h] BYREF
  char v24; // [sp+28h] [bp-60h] BYREF

  memset(v23, 0, sizeof(v23));
  v23[3] = 0;
  v6 = *a2;
  v23[4] = 8;
  v23[0] = (int)&v24;
  v7 = 0;
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x136);
  v9 = KeAbPreAcquire((unsigned int)dword_6361F8, 0, 0);
  v10 = dword_6361F8;
  do
    v11 = __ldrex((unsigned __int8 *)dword_6361F8);
  while ( __strex(v11 | 1, (unsigned __int8 *)dword_6361F8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6361F8, v9, (unsigned int)dword_6361F8);
  if ( v9 )
  {
    v10 = (unsigned int *)(*(unsigned __int8 *)(v9 + 14) | 1);
    *(_BYTE *)(v9 + 14) = (_BYTE)v10;
  }
  v12 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
          (unsigned __int16 **)&dword_6361F8[1],
          v6,
          (int)v23,
          (int)v10);
  if ( ((1 << a4) & dword_636204) == 0 )
  {
    B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
      v12,
      v22,
      v23);
    v13 = (unsigned __int16 *)v22[0];
    v14 = v22[1];
    while ( 1 )
    {
      if ( v13 )
      {
        v14 += 8;
        if ( v14 < (unsigned int)&v13[4 * *v13 + 4] )
          goto LABEL_14;
        v15 = *((_DWORD *)v13 + 1);
        if ( v15 )
          break;
      }
      v16 = 0;
LABEL_15:
      *(_BYTE *)(v16 + 6) = 3;
      ++v7;
      *(_BYTE *)(v16 + 7) |= 1u;
      if ( v7 == a3 )
        goto LABEL_16;
    }
    v13 = (unsigned __int16 *)*((_DWORD *)v13 + 1);
    v14 = v15 + 8;
LABEL_14:
    v16 = v14;
    goto LABEL_15;
  }
LABEL_16:
  __dmb(0xBu);
  do
    v17 = __ldrex(dword_6361F8);
  while ( __strex(v17 - 1, dword_6361F8) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock(dword_6361F8);
  result = KeAbPostRelease((unsigned int)dword_6361F8);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x136) + 1;
  *(_WORD *)(v19 + 310) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
