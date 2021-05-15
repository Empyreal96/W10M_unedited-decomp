// HvViewMapUnpinFile 
 
int __fastcall HvViewMapUnpinFile(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  unsigned int v7; // r1
  unsigned int v8; // r1
  int v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 1);
  v4 = KeAbPreAcquire(a1 + 1, 0, 0);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_519E5C(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  HvpViewMapUnpinForFileOffset(a1, 0, *a1);
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v3);
  while ( __strex(v7 - 1, (unsigned int *)v3) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock(v3);
  result = KeAbPostRelease(v3);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
