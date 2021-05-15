// HvViewMapCopyFromFileOffset 
 
int __fastcall HvViewMapCopyFromFileOffset(int a1, int a2, int a3, unsigned int a4)
{
  int v7; // r4
  unsigned int *v8; // r6
  int v9; // r0
  unsigned int v10; // r5
  int result; // r0
  int v12; // r5
  unsigned int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r3

  v7 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
  v8 = (unsigned int *)(a1 + 4);
  v9 = KeAbPreAcquire(a1 + 4, 0, 0);
  do
    v10 = __ldrex(v8);
  while ( !v10 && __strex(0x11u, v8) );
  __dmb(0xBu);
  if ( v10 )
    return sub_554B70(v9);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  for ( ; a4; a4 -= v13 )
  {
    v12 = HvpViewMapAddressForFileOffset(a1, a3);
    v13 = HvpViewMapContiguousBytesAfterFileOffset(a1, a3);
    if ( v13 > a4 )
      v13 = a4;
    memmove(a2, v12, v13);
    a3 += v13;
    a2 += v13;
  }
  __dmb(0xBu);
  do
    v14 = __ldrex(v8);
  while ( v14 == 17 && __strex(0, v8) );
  if ( v14 != 17 )
    ExfReleasePushLockShared(v8);
  result = KeAbPostRelease((unsigned int)v8);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
