// -SmStHelperSendCommand@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@W4_SMKM_STORE_HELPER_COMMAND@@PAU_SMKM_STORE_HELPER_PARAMS@@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStHelperSendCommand(int a1, int a2, int a3, char a4)
{
  int v7; // r8
  int v8; // r7
  int *v9; // r7
  __int64 v10; // kr00_8
  int v11; // r1
  int v12; // r3
  unsigned int *v13; // r6
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r5
  unsigned int v19; // r2
  unsigned __int8 *v20; // r6
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  int v24; // r3
  int v26[2]; // [sp+0h] [bp-30h] BYREF
  unsigned int v27[10]; // [sp+8h] [bp-28h] BYREF

  if ( a2 == 4 )
    v7 = a1 + 3740;
  else
    v7 = a1 + 3668;
  v8 = SmKmStoreHelperSendCommand(v7, a2, a3, (a4 & 1) != 0);
  if ( v8 != -1073741650 )
  {
    if ( (a4 & 2) != 0 )
    {
      v9 = 0;
    }
    else
    {
      v10 = SmStHelperTimeout;
      __dmb(0xBu);
      if ( *(unsigned __int8 *)(a1 + 3518) > 1u )
      {
        v11 = 1000;
        v12 = 1000 * v10;
      }
      else
      {
        v11 = 100;
        v12 = 100 * v10;
      }
      v26[0] = v12;
      v9 = v26;
      v26[1] = v10 + HIDWORD(v10) * v11;
    }
    if ( (*(_BYTE *)(a1 + 3517) & 4) != 0 )
    {
      v13 = (unsigned int *)(a1 + 3520);
      __dmb(0xBu);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 - 1, v13) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(a1 + 3520));
      v15 = KeAbPostRelease(a1 + 3520);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = *(_WORD *)(v16 + 0x136) + 1;
      *(_WORD *)(v16 + 310) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 )
        KiCheckForKernelApcDelivery(v15);
    }
    v8 = SmKmStoreHelperWaitForCommand(v7, a3, v9, (a4 & 4) != 0);
    if ( (*(_BYTE *)(a1 + 3517) & 4) != 0 )
    {
      v18 = 20;
      v27[0] = -150000;
      v27[1] = -1;
      while ( *(_DWORD *)(a1 + 3868) && v18 && *(unsigned __int8 *)(a1 + 3518) >= 3u )
      {
        KeDelayExecutionThread(0, 0, v27);
        --v18;
      }
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v19 + 310);
      v20 = (unsigned __int8 *)(a1 + 3520);
      v21 = KeAbPreAcquire(a1 + 3520, 0, 0);
      v22 = v21;
      do
        v23 = __ldrex(v20);
      while ( __strex(v23 | 1, v20) );
      __dmb(0xBu);
      if ( (v23 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3520), v21, a1 + 3520);
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      v24 = *(_DWORD *)(a1 + 3528);
      *(_DWORD *)(a1 + 3524) = 1;
      *(_DWORD *)(a1 + 3528) = v24 + 1;
    }
  }
  return v8;
}
