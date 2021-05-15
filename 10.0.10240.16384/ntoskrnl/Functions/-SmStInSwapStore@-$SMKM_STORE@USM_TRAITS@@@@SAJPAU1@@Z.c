// -SmStInSwapStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStInSwapStore(int a1)
{
  unsigned int *v1; // r6
  _DWORD *v2; // r4
  unsigned int v4; // r2
  int v5; // r5
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int *v8; // r7
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v1 = (unsigned int *)(a1 + 3860);
  v2 = *(_DWORD **)(a1 + 3860);
  __dmb(0xBu);
  if ( !v2 || v2 == (_DWORD *)-1 )
    return -1073741661;
  __dmb(0xBu);
  do
    v4 = __ldrex(v1);
  while ( (_DWORD *)v4 == v2 && __strex(0xFFFFFFFF, v1) );
  __dmb(0xBu);
  if ( (_DWORD *)v4 != v2 )
    return -1073740682;
  if ( *v2 )
    v5 = SmPerformStoreSwapOperation(2);
  else
    v5 = -1073741661;
  __dmb(0xBu);
  do
    v6 = __ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = (unsigned int *)(a1 + 3520);
  v9 = KeAbPreAcquire((unsigned int)v8, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( !v11 && __strex(0x11u, v8) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(v8, v9, (unsigned int)v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  __dmb(0xBu);
  do
    v12 = __ldrex(v8);
  while ( v12 == 17 && __strex(0, v8) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(v8);
  v13 = KeAbPostRelease((unsigned int)v8);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x136) + 1;
  *(_WORD *)(v14 + 310) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 )
    KiCheckForKernelApcDelivery(v13);
  ExFreePoolWithTag(v2);
  return v5;
}
