// SmKmVirtualLockCtxMemoryUnlocked 
 
unsigned int __fastcall SmKmVirtualLockCtxMemoryUnlocked(unsigned int result, int a2)
{
  unsigned int v2; // r5
  unsigned int *v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r4
  unsigned int v14; // r1
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // [sp+8h] [bp-28h] BYREF
  unsigned int v18; // [sp+Ch] [bp-24h] BYREF
  int v19; // [sp+10h] [bp-20h] BYREF
  int v20; // [sp+14h] [bp-1Ch] BYREF
  int v21; // [sp+18h] [bp-18h] BYREF
  int v22[5]; // [sp+1Ch] [bp-14h] BYREF

  v2 = result;
  __dmb(0xBu);
  v3 = (unsigned int *)(result + 4);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 - a2, v3) );
  __dmb(0xBu);
  v5 = *v3;
  v6 = *(_DWORD *)(result + 8);
  if ( *v3 < v6 && (!v5 || v6 - v5 >= 0x800000) )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(result, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v10 | 1, (unsigned __int8 *)v2) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v8, v2);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v11 = *(_DWORD *)(v2 + 8);
    v12 = v11 - *v3;
    if ( (v12 >= 0x800000 || !*v3 && v11) && MmQueryWorkingSetInformation(v22, &v21, &v20, &v17, &v18, &v19) >= 0 )
    {
      v13 = v12 & 0xFFC00000;
      *(_DWORD *)(v2 + 8) -= v13;
      if ( v17 >= v13 )
        MmAdjustWorkingSetSize(v17 - v13, v18, 0, 0);
    }
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v2);
    while ( __strex(v14 - 1, (unsigned int *)v2) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v2);
    result = KeAbPostRelease(v2);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
