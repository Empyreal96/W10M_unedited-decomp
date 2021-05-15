// HvViewMapPinForFileOffset 
 
int __fastcall HvViewMapPinForFileOffset(int a1, int a2, int a3)
{
  unsigned int v6; // r4
  unsigned __int8 *v7; // r6
  int v8; // r0
  unsigned int v9; // r4
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned __int8 *)(a1 + 4);
  v8 = KeAbPreAcquire(a1 + 4, 0, 0);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 | 1, v7) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_803BA4(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v11 = HvpViewMapPinForFileOffset(a1, a2, a3);
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v7);
  while ( __strex(v12 - 1, (unsigned int *)v7) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  v13 = KeAbPostRelease((unsigned int)v7);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v11;
}
