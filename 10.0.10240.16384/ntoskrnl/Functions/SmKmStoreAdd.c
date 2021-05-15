// SmKmStoreAdd 
 
int __fastcall SmKmStoreAdd(int a1, int a2, int a3, int *a4)
{
  int v4; // r7
  int v5; // r10
  unsigned int v7; // r9
  int v8; // r5
  unsigned __int8 *v9; // r8
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  unsigned __int8 *v14; // r7
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  __int16 v19; // r3
  int v20; // r3
  char v21; // r3
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  __int16 v26; // r2
  int v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r1
  unsigned int *v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // r4
  unsigned int v33; // r1
  unsigned int v34; // r1
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  unsigned int *v39; // r4
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  unsigned int *v44; // r4
  unsigned int v45; // r1
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  _BYTE *v50; // [sp+14h] [bp-3Ch]
  int v51; // [sp+18h] [bp-38h]

  v4 = a2;
  v5 = 0;
  v50 = *(_BYTE **)a3;
  v51 = a2;
  v7 = 0;
  while ( 1 )
  {
    v8 = v7 + a1;
    if ( *(_DWORD *)(v7 + a1) )
      goto LABEL_56;
    v9 = (unsigned __int8 *)(v8 + 92);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = KeAbPreAcquire(v8 + 92, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v9);
    while ( __strex(v13 | 1, v9) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v8 + 92), v11, v8 + 92);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    if ( !*(_DWORD *)v8 )
      break;
LABEL_46:
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)v9);
    while ( __strex(v34 - 1, (unsigned int *)v9) );
    if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v8 + 92));
    v35 = KeAbPostRelease(v8 + 92);
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v37 = *(_WORD *)(v36 + 0x134) + 1;
    *(_WORD *)(v36 + 308) = v37;
    if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
      KiCheckForKernelApcDelivery(v35);
    if ( !v4 )
      return 0;
LABEL_56:
    v7 += 96;
    ++v5;
    if ( v7 >= 0xC00 )
      return -1073741671;
  }
  v14 = (unsigned __int8 *)(a1 + 3176);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v15 + 308);
  v16 = KeAbPreAcquire(a1 + 3176, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex(v14);
  while ( __strex(v18 | 1, v14) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3176), v16, a1 + 3176);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  if ( (*(_DWORD *)v50 & 0x100) == 0 )
  {
LABEL_19:
    v19 = *(_WORD *)(v8 + 12) ^ (*(_WORD *)(v8 + 12) ^ ((*v50 == 1) << 11)) & 0x800;
    *(_WORD *)(v8 + 12) = v19;
    if ( (v19 & 0x800) != 0 )
    {
      v20 = *(_DWORD *)(a1 + 3184) + 1;
      *(_DWORD *)(a1 + 3184) = v20;
      if ( v20 == 1 )
      {
        SmWdStartMonitoring(a1 + 3080);
        (*(void (__fastcall **)(int, int, int))(a1 + 3072))(a1, 1, 3);
      }
    }
    v21 = *(_BYTE *)(v8 + 14) & 0xFE;
    __dmb(0xBu);
    *(_BYTE *)(v8 + 14) = v21;
    *(_BYTE *)(v8 + 14) &= 0xFDu;
    *(_WORD *)(v8 + 12) ^= (*(_WORD *)(v8 + 12) ^ (*(_DWORD *)v50 >> 6)) & 0x1000;
    *(_DWORD *)(v8 + 36) = *(_DWORD *)(a3 + 8);
    ++*(_DWORD *)(a1 + 3180);
    *(_DWORD *)(v8 + 16) = *(_DWORD *)(a3 + 12);
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v14);
    while ( __strex(v22 - 1, (unsigned int *)v14) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 3176));
    v23 = KeAbPostRelease(a1 + 3176);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    *(_DWORD *)v8 = v51;
    do
    {
      v26 = *(_WORD *)(v8 + 12) & 0xF800 | (*(_WORD *)(v8 + 12) + 1) & 0x7FF;
      *(_WORD *)(v8 + 12) = v26;
      v27 = v5 | (32 * (v26 & 0x7FF));
      *a4 = v27;
    }
    while ( v27 == 65567 );
    v4 = 0;
    v51 = 0;
    if ( (dword_636E9C & 0x10) != 0 )
      SmKmEtwLogStoreChange((int *)&unk_636E90, *(_DWORD *)v8, SmEventStoreCreate);
    if ( (*(_WORD *)(v8 + 12) & 0x800) != 0 )
    {
      KeInitializeApc(v8 + 40, *(_DWORD *)(a3 + 4), 0, (int)SmWdWritesApcRoutine, (int)PopPoCoalescinCallback, 0, 0, 0);
      __dmb(0xBu);
      v28 = (unsigned int *)(v8 + 8);
      do
        v29 = __ldrex(v28);
      while ( __strex(0, v28) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    v30 = (unsigned int *)(v8 + 4);
    do
      v31 = __ldrex(v30);
    while ( __strex(0, v30) );
    __dmb(0xBu);
    __pld(v30);
    v32 = *v30 & 0xFFFFFFFE;
    do
      v33 = __ldrex(v30);
    while ( v33 == v32 && __strex(v32 + 2, v30) );
    __dmb(0xBu);
    if ( v33 != v32 )
      ExfAcquireRundownProtection(v30);
    goto LABEL_46;
  }
  if ( *(_DWORD *)(a1 + 3188) == -1 )
  {
    *(_DWORD *)(a1 + 3188) = v5;
    goto LABEL_19;
  }
  v39 = (unsigned int *)(a1 + 3176);
  __dmb(0xBu);
  do
    v40 = __ldrex(v39);
  while ( __strex(v40 - 1, v39) );
  if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
    ExfTryToWakePushLock(v39);
  v41 = KeAbPostRelease((unsigned int)v39);
  v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v43 = *(_WORD *)(v42 + 0x134) + 1;
  *(_WORD *)(v42 + 308) = v43;
  if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
    KiCheckForKernelApcDelivery(v41);
  v44 = (unsigned int *)(v8 + 92);
  __dmb(0xBu);
  do
    v45 = __ldrex(v44);
  while ( __strex(v45 - 1, v44) );
  if ( (v45 & 2) != 0 && (v45 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v8 + 92));
  v46 = KeAbPostRelease(v8 + 92);
  v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v48 = *(_WORD *)(v47 + 0x134) + 1;
  *(_WORD *)(v47 + 308) = v48;
  if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
    KiCheckForKernelApcDelivery(v46);
  return -1073740757;
}
