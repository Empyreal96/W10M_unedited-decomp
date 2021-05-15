// SmcStoreSlotAbort 
 
int __fastcall SmcStoreSlotAbort(int a1, int a2, int a3)
{
  unsigned __int8 *v5; // r6
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  __int64 v10; // kr00_8
  unsigned int *v11; // r4
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  if ( !a3 )
  {
    v5 = (unsigned __int8 *)(a1 + 120);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire(a1 + 120, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v5);
    while ( __strex(v9 | 1, v5) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v5, v7, (unsigned int)v5);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
  }
  v10 = *(_QWORD *)(a2 + 4);
  v11 = (unsigned int *)(a1 + 120);
  *(_DWORD *)(a2 + 4) = v10 & 0xFFFFFFFB;
  *(_DWORD *)(a2 + 8) = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 - 1, v11) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 120));
  v13 = KeAbPostRelease(a1 + 120);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(SHIDWORD(v10));
}
