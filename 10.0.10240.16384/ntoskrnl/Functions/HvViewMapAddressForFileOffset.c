// HvViewMapAddressForFileOffset 
 
int __fastcall HvViewMapAddressForFileOffset(int a1, unsigned int a2)
{
  unsigned int v4; // r2
  unsigned int *v5; // r5
  int v6; // r0
  unsigned int v7; // r2
  int v9; // r2
  int v10; // r3
  int v11; // r6
  unsigned int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = (unsigned int *)(a1 + 4);
  v6 = KeAbPreAcquire(a1 + 4, 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v7 )
    return sub_8044BC(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = 3 * ((a2 >> 18) & 0x3F);
  v10 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * (HIBYTE(a2) & 0x7F));
  v11 = a2 & 0x3FFFF;
  v12 = *(_DWORD *)(v10 + 8 * v9) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v13 = __ldrex(v5);
  while ( v13 == 17 && __strex(0, v5) );
  if ( v13 != 17 )
    ExfReleasePushLockShared(v5);
  v14 = KeAbPostRelease((unsigned int)v5);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v12 + v11;
}
