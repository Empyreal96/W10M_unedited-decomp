// HvViewMapIsRangePinned 
 
int __fastcall HvViewMapIsRangePinned(int a1, int a2)
{
  unsigned int v4; // r2
  unsigned int *v5; // r5
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = (unsigned int *)(a1 + 4);
  v6 = KeAbPreAcquire(a1 + 4, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( !v8 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(v5, v6, (unsigned int)v5);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = HvpViewMapIsRangePinned(a1, a2);
  __dmb(0xBu);
  do
    v10 = __ldrex(v5);
  while ( v10 == 17 && __strex(0, v5) );
  if ( v10 != 17 )
    ExfReleasePushLockShared(v5);
  v11 = KeAbPostRelease((unsigned int)v5);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return v9;
}
