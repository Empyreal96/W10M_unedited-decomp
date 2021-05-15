// -SmFeReadInitiate@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@PAT_SM_PAGE_KEY@@PAKPA_K2@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeReadInitiate(int a1, unsigned int *a2, unsigned int *a3, __int64 *a4, int *a5)
{
  int v5; // r10
  unsigned int v8; // r5
  unsigned int *v9; // r7
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r5
  int v13; // r0
  int v14; // r4
  int v15; // r2
  int v16; // r5
  __int64 v17; // r0
  int *v18; // r3
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int *v24; // [sp+0h] [bp-28h] BYREF
  unsigned int *v25; // [sp+4h] [bp-24h]
  unsigned int *v26; // [sp+8h] [bp-20h]

  v24 = a2;
  v25 = a3;
  v26 = (unsigned int *)a4;
  v5 = *a3;
  v25 = a2;
  v26 = a3;
  v24 = (unsigned int *)v5;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 310);
  v9 = (unsigned int *)(a1 + 3192);
  v10 = KeAbPreAcquire(a1 + 3192, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v9, v10, (unsigned int)v9);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = SMKM_STORE_MGR<SM_TRAITS>::SmFeCheckPresent(a1, v25, (int *)&v24, a5);
  v14 = v13;
  if ( v13 != 32 )
  {
    v15 = *(_DWORD *)(a1 + 5888);
    if ( ((v15 & 4) != 0 || !*a5) && ((v16 = (int)v24, v24 == (unsigned int *)v5) || (v15 & 8) != 0) )
    {
      v17 = SMKM_STORE<SM_TRAITS>::SmStEtaQuery(*(_DWORD *)(96 * (v13 & 0x1F) + a1), v24);
      v18 = (int *)v26;
      *a4 = v17;
      *v18 = v16;
    }
    else
    {
      v14 = 32;
    }
  }
  __dmb(0xBu);
  do
    v19 = __ldrex(v9);
  while ( v19 == 17 && __strex(0, v9) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(v9);
  v20 = KeAbPostRelease((unsigned int)v9);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x136) + 1;
  *(_WORD *)(v21 + 310) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 )
    KiCheckForKernelApcDelivery(v20);
  return v14;
}
