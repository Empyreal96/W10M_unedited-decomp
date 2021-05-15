// SmcStoreSlotReserve 
 
_DWORD *__fastcall SmcStoreSlotReserve(int a1, int a2, unsigned int a3)
{
  unsigned int v4; // r4
  _DWORD *v5; // r9
  _DWORD *v6; // r0
  int v7; // r7
  _DWORD *v8; // r4
  unsigned __int8 *v9; // r6
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // r3

  v4 = (unsigned int)(*(_DWORD *)(a1 + 8) + 31) >> 5;
  v5 = 0;
  v6 = (_DWORD *)SmAlloc(4 * v4, 1917021555);
  v7 = (int)v6;
  if ( v6 )
  {
    RtlFillMemoryUlong(v6, 4 * v4, -1);
    v8 = (_DWORD *)(a1 + 124);
    v9 = (unsigned __int8 *)(a1 + 120);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = KeAbPreAcquire(a1 + 120, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v9);
    while ( __strex(v13 | 1, v9) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 120), v11, a1 + 120);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    while ( (unsigned int)v8 < a1 + 380 )
    {
      if ( *v8 == -1 && (v8[1] & 4) == 0 )
      {
        v19 = v8[1];
        v8[2] = v7;
        v19 |= 4u;
        v8[1] = v19;
        v7 = 0;
        if ( SmcStorePlacementGet(a1, a3, (int)v8, v19) >= 0 )
        {
          v5 = v8;
          v8 = 0;
        }
        if ( v8 )
        {
          SmcStoreSlotAbort(a1, (int)v8, 1);
          return v5;
        }
        break;
      }
      v8 += 4;
    }
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v9);
    while ( __strex(v14 - 1, (unsigned int *)v9) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 120));
    v15 = KeAbPostRelease(a1 + 120);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    if ( v7 )
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v7);
  }
  return v5;
}
