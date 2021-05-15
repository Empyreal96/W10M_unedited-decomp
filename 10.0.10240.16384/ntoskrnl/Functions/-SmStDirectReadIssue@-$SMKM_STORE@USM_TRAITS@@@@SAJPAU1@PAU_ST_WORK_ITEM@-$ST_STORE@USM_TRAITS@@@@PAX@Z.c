// -SmStDirectReadIssue@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@-$ST_STORE@USM_TRAITS@@@@PAX@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStDirectReadIssue(int a1, int a2, int a3, int a4)
{
  int v6; // r6
  unsigned int *v7; // r4
  unsigned int v8; // r5
  unsigned int v9; // r4
  unsigned int *v10; // r5
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r4
  unsigned int *v15; // r5
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v6 = a1;
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 3868);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 + 1, v7) );
  __dmb(0xBu);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 310);
  v10 = (unsigned int *)(a1 + 3520);
  v11 = KeAbPreAcquire(a1 + 3520, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( !v13 && __strex(0x11u, v10) );
  __dmb(0xBu);
  if ( v13 )
    ExfAcquirePushLockSharedEx(v10, v11, (unsigned int)v10);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  *(_DWORD *)(a3 + 24) = 2;
  v14 = ST_STORE<SM_TRAITS>::StDmPageRetrieve(v6 + 56, a3, a2);
  ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(v6 + 56, v6 + 3448);
  v15 = (unsigned int *)(v6 + 3520);
  __dmb(0xBu);
  do
    v16 = __ldrex(v15);
  while ( v16 == 17 && __strex(0, v15) );
  if ( v16 != 17 )
    ExfReleasePushLockShared((_DWORD *)(v6 + 3520));
  v17 = KeAbPostRelease(v6 + 3520);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x136) + 1;
  *(_WORD *)(v18 + 310) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 )
    KiCheckForKernelApcDelivery(v17);
  __dmb(0xBu);
  v20 = (unsigned int *)(v6 + 3868);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 - 1, v20) );
  __dmb(0xBu);
  if ( v14 == -2147483634 )
    v14 = -1073741670;
  return v14;
}
