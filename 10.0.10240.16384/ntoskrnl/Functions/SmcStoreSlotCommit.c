// SmcStoreSlotCommit 
 
int __fastcall SmcStoreSlotCommit(int a1, _DWORD *a2, int a3, char a4)
{
  unsigned __int8 *v7; // r7
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r5
  int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r1
  int result; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  v7 = (unsigned __int8 *)(a1 + 120);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(a1 + 120, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 1, v7) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v9, (unsigned int)v7);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = a2[1];
  *a2 = a3;
  a2[1] = v12 & 0xFFFFFFFB;
  __dmb(0xBu);
  v13 = a2 + 3;
  do
    v14 = __ldrex(v13);
  while ( __strex(0, v13) );
  __dmb(0xBu);
  a2[1] = a2[1] & 0xFFFFFFFC | a4 & 3;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v7);
  while ( __strex(v15 - 1, (unsigned int *)v7) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  result = KeAbPostRelease((unsigned int)v7);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
