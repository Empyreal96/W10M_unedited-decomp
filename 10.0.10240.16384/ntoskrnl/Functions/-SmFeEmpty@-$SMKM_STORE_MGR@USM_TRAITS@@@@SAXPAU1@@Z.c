// -SmFeEmpty@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEmpty(int a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  unsigned __int16 *v7; // r1
  unsigned int v8; // r1
  int result; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = (unsigned __int8 *)(a1 + 3192);
  v4 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *(unsigned __int16 **)(a1 + 3196);
  if ( v7 )
    B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNodeFree(
      a1 + 3196,
      v7);
  *(_DWORD *)(a1 + 3196) = 0;
  *(_DWORD *)(a1 + 3200) = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v3);
  while ( __strex(v8 - 1, (unsigned int *)v3) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  result = KeAbPostRelease((unsigned int)v3);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x136) + 1;
  *(_WORD *)(v10 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
