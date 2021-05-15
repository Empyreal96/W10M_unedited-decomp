// -SmStPrioritizeRegionsStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStPrioritizeRegionsStore(int a1, int a2)
{
  int v4; // r4
  int v5; // r9
  unsigned int v6; // r2
  unsigned int *v7; // r4
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  unsigned int *v11; // r8
  unsigned int v12; // r2
  unsigned int i; // r6
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r7
  unsigned int v21; // r2
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r2
  int v28[2]; // [sp+8h] [bp-40h] BYREF
  char v29[56]; // [sp+10h] [bp-38h] BYREF

  v28[1] = *(_DWORD *)(a1 + 3652);
  if ( (*(_BYTE *)(a1 + 3517) & 4) == 0 )
    return -1073741637;
  if ( a2 )
    v5 = 6;
  else
    v5 = 5;
  KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v29);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 310);
  v7 = (unsigned int *)(a1 + 3520);
  v8 = KeAbPreAcquire(a1 + 3520, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx((_DWORD *)(a1 + 3520), v8, a1 + 3520);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_BYTE *)(a1 + 3519) = a2 != 0;
  __dmb(0xBu);
  v11 = (unsigned int *)(a1 + 3868);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 + 1, v11) );
  __dmb(0xBu);
  for ( i = 0; i < *(_DWORD *)(a1 + 3656); ++i )
  {
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 3660) + 4 * i) & 0x7FFF0000) != 0 )
    {
      v28[0] = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(a1, i, 0, 2147418112, 0);
      if ( v28[0] > 3u )
      {
        __dmb(0xBu);
        do
          v14 = __ldrex(v7);
        while ( v14 == 17 && __strex(0, v7) );
        if ( v14 != 17 )
          ExfReleasePushLockShared((_DWORD *)(a1 + 3520));
        v15 = KeAbPostRelease(a1 + 3520);
        v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v17 = *(_WORD *)(v16 + 0x136) + 1;
        *(_WORD *)(v16 + 310) = v17;
        if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 )
          v15 = KiCheckForKernelApcDelivery(v15);
        MmSetPriorityVaRanges(v15, v28, v5);
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v18 + 310);
        v19 = KeAbPreAcquire(a1 + 3520, 0, 0);
        v20 = v19;
        do
          v21 = __ldrex(v7);
        while ( !v21 && __strex(0x11u, v7) );
        __dmb(0xBu);
        if ( v21 )
          ExfAcquirePushLockSharedEx((_DWORD *)(a1 + 3520), v19, a1 + 3520);
        if ( v20 )
          *(_BYTE *)(v20 + 14) |= 1u;
        SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion(a1, i);
      }
    }
  }
  __dmb(0xBu);
  do
    v22 = __ldrex(v7);
  while ( v22 == 17 && __strex(0, v7) );
  if ( v22 != 17 )
    ExfReleasePushLockShared((_DWORD *)(a1 + 3520));
  v23 = KeAbPostRelease(a1 + 3520);
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x136) + 1;
  *(_WORD *)(v24 + 310) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 )
    KiCheckForKernelApcDelivery(v23);
  v4 = 0;
  __dmb(0xBu);
  do
    v26 = __ldrex(v11);
  while ( __strex(v26 - 1, v11) );
  __dmb(0xBu);
  KiUnstackDetachProcess((unsigned int)v29, 0);
  return v4;
}
