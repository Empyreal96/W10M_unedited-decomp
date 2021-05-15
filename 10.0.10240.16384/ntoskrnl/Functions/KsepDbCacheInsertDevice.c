// KsepDbCacheInsertDevice 
 
int __fastcall KsepDbCacheInsertDevice(unsigned __int16 *a1, unsigned int *a2)
{
  int v2; // r7
  unsigned __int8 *v4; // r6
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned int *v10; // r4
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v16; // [sp+0h] [bp-40h] BYREF
  char v17[44]; // [sp+14h] [bp-2Ch] BYREF

  v2 = -1073741811;
  v4 = (unsigned __int8 *)dword_6416F8;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)v4, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v4);
  while ( __strex(v9 | 1, v4) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v4, v7, (unsigned int)v4);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  RtlInitUnicodeString((unsigned int)v17, a1);
  if ( !KsepCacheLookup(dword_6416F8, (int)&v16) )
  {
    KsepCacheInsert(dword_6416F8, a2);
    v2 = 0;
  }
  v10 = (unsigned int *)dword_6416F8;
  __dmb(0xBu);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(v10);
  v12 = KeAbPostRelease((unsigned int)v10);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return v2;
}
