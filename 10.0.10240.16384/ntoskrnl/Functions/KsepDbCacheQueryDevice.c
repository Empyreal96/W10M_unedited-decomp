// KsepDbCacheQueryDevice 
 
int __fastcall KsepDbCacheQueryDevice(unsigned __int16 *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r7
  unsigned __int8 *v8; // r6
  unsigned int v9; // r4
  int v10; // r5
  unsigned int v11; // r4
  _DWORD *v13; // r0
  unsigned int *v14; // r4
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  char v20[20]; // [sp+10h] [bp-40h] BYREF
  char v21[44]; // [sp+24h] [bp-2Ch] BYREF

  v5 = -1073741275;
  RtlInitUnicodeString((unsigned int)v21, a1);
  v8 = (unsigned __int8 *)dword_6416F8;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = KeAbPreAcquire((unsigned int)v8, 0, 0);
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    return sub_7CE4FC();
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v13 = KsepCacheLookup(dword_6416F8, (int)v20);
  if ( v13 )
    v5 = KsepDbCacheQueryDeviceData(v13, a2, a3, a4, a5);
  v14 = (unsigned int *)dword_6416F8;
  __dmb(0xBu);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 - 1, v14) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(v14);
  v16 = KeAbPostRelease((unsigned int)v14);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return v5;
}
