// HvViewMapPinFile 
 
int __fastcall HvViewMapPinFile(int *a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r4
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 1);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 1), 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = HvpViewMapPinForFileOffset((int)a1, 0, *a1);
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v3);
  while ( __strex(v8 - 1, (unsigned int *)v3) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  v9 = KeAbPostRelease((unsigned int)v3);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v7;
}
