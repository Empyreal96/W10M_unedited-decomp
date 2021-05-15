// PspAdjustKeepAliveCountProcess 
 
unsigned int __fastcall PspAdjustKeepAliveCountProcess(int a1, signed int a2, int a3, int a4)
{
  unsigned int *v7; // r6
  unsigned int v8; // r8
  unsigned int *v9; // r7
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r2
  _DWORD *v17; // r6
  unsigned int v18; // r2
  int v19; // r0
  __int16 v20; // r3
  int v22; // [sp+18h] [bp-28h]

  if ( a4 )
    v7 = (unsigned int *)(a1 + 784);
  else
    v7 = (unsigned int *)(a1 + 788);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = (unsigned int *)(a1 + 168);
  v10 = KeAbPreAcquire(a1 + 168, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx((_DWORD *)(a1 + 168), v10, a1 + 168);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = *v7;
  do
  {
    v14 = v13;
    v22 = v13;
    v15 = v13 + a2;
    __dmb(0xBu);
    do
      v16 = __ldrex(v7);
    while ( v16 == v13 && __strex(v15, v7) );
    v13 = v16;
    __dmb(0xBu);
  }
  while ( v16 != v14 );
  v17 = *(_DWORD **)(a1 + 288);
  __dmb(0xBu);
  do
    v18 = __ldrex(v9);
  while ( v18 == 17 && __strex(0, v9) );
  if ( v18 != 17 )
    ExfReleasePushLockShared((_DWORD *)(a1 + 168));
  v19 = KeAbPostRelease(a1 + 168);
  v20 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v19);
  if ( a4 )
  {
    if ( v22 < 0 )
      PspChargeJobWakeCounter(v17, 0, 1, a2 >> 31, a2, a2 >> 31, 1, a1, a3);
    v15 &= 0x7FFFFFFFu;
  }
  return v15;
}
