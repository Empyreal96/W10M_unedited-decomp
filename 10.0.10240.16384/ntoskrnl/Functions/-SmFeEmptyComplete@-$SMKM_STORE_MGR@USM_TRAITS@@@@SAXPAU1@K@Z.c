// -SmFeEmptyComplete@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEmptyComplete(int a1, int a2)
{
  unsigned int v4; // r2
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  v5 = (unsigned __int8 *)(a1 + 3192);
  v6 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( __strex(v8 | 1, v5) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v5, v6, (unsigned int)v5);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *(_DWORD *)(a1 + 3204) &= ~(1 << a2);
  __dmb(0xBu);
  v9 = (unsigned int *)(a1 + 4 * (a2 + 802));
  do
    v10 = __ldrex(v9);
  while ( __strex(0, v9) );
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v5);
  while ( __strex(v11 - 1, (unsigned int *)v5) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v5);
  result = KeAbPostRelease((unsigned int)v5);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x136) + 1;
  *(_WORD *)(v13 + 310) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
