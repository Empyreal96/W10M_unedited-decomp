// -SmStCleanup@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStCleanup(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0
  unsigned int v4; // r2
  int v5; // r5
  unsigned int v6; // r2
  unsigned __int8 *v7; // r6
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r0
  unsigned int *v13; // r5
  unsigned int v14; // r1
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r5
  int v20; // r0
  int v21[2]; // [sp+8h] [bp-38h] BYREF
  char v22[48]; // [sp+10h] [bp-30h] BYREF

  v1 = a1;
  *(_BYTE *)(a1 + 3517) |= 1u;
  if ( *(_DWORD *)(a1 + 3648) )
  {
    KeSetEvent(a1 + 3616, 0, 1);
    KeWaitForSingleObject(*(_DWORD *)(v1 + 3648), 0, 0);
    a1 = *(_DWORD *)(v1 + 3648);
    if ( a1 )
      a1 = ObfDereferenceObject(a1);
  }
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
    a1 = SMKM_STORE<SM_TRAITS>::SmStReadThreadCtxCleanup(v1 + 3812);
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
    a1 = KiStackAttachProcess(PsInitialSystemProcess, 0, v22);
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
  {
    v2 = *(_DWORD *)(v1 + 3860);
    __dmb(0xBu);
    if ( v2 )
      return sub_509CEC(a1);
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
  {
    v5 = 20;
    v21[0] = -150000;
    v21[1] = -1;
    while ( *(_DWORD *)(v1 + 3868) && v5 && *(unsigned __int8 *)(v1 + 3518) >= 3u )
    {
      KeDelayExecutionThread(0, 0, v21);
      --v5;
    }
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 310);
    v7 = (unsigned __int8 *)(v1 + 3520);
    v8 = KeAbPreAcquire(v1 + 3520, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex(v7);
    while ( __strex(v10 | 1, v7) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v1 + 3520, v8, v1 + 3520);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v11 = *(_DWORD *)(v1 + 3528);
    *(_DWORD *)(v1 + 3524) = 1;
    *(_DWORD *)(v1 + 3528) = v11 + 1;
  }
  v12 = ST_STORE<SM_TRAITS>::StCleanup(v1);
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
  {
    v13 = (unsigned int *)(v1 + 3520);
    __dmb(0xBu);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 - 1, v13) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock(v1 + 3520);
    v12 = KeAbPostRelease(v1 + 3520);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x136) + 1;
    *(_WORD *)(v15 + 310) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
      v12 = KiCheckForKernelApcDelivery(v12);
  }
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
    KiUnstackDetachProcess(v22, 0);
  if ( *(_BYTE *)(v1 + 3516) )
  {
    if ( *(_BYTE *)(v1 + 3516) == 1 )
      SmKmFileInfoCleanup(v1 + 3660);
  }
  else
  {
    v19 = *(_DWORD *)(v1 + 3660);
    if ( (*(_BYTE *)(v1 + 3517) & 4) != 0 )
    {
      v20 = *(_DWORD *)(v1 + 3664);
      if ( v20 )
        ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v20);
      SmKmStoreHelperCleanup(v1 + 3668);
      SmKmStoreHelperCleanup(v1 + 3740);
    }
    if ( v19 )
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v19);
  }
  result = SmFpCleanup(v1 + 3880);
  if ( (*(_BYTE *)(v1 + 3517) & 0x10) != 0 )
    result = SmAcquireReleaseCharges(*(_DWORD *)(v1 + 3652), 1, 1);
  return result;
}
