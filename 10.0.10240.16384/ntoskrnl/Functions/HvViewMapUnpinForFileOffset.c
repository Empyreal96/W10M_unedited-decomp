// HvViewMapUnpinForFileOffset 
 
int __fastcall HvViewMapUnpinForFileOffset(int a1, int a2, int a3)
{
  unsigned int v6; // r4
  unsigned __int8 *v7; // r6
  int v8; // r0
  unsigned int v9; // r4
  int result; // r0
  unsigned int v11; // r1
  unsigned int v12; // r1
  __int16 v13; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned __int8 *)(a1 + 4);
  v8 = KeAbPreAcquire(a1 + 4, 0, 0);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 | 1, v7) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_806114(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  HvpViewMapUnpinForFileOffset(a1, a2, a3);
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v7);
  while ( __strex(v11 - 1, (unsigned int *)v7) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  result = KeAbPostRelease((unsigned int)v7);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
