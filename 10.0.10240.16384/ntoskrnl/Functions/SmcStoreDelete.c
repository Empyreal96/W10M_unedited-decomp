// SmcStoreDelete 
 
int __fastcall SmcStoreDelete(int a1, unsigned int a2, int a3, int a4)
{
  char v6; // r10
  int v7; // r6
  int v8; // r0
  int v9; // r7
  int v10; // r5
  unsigned __int8 *v11; // r4
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  _DWORD *v16; // r0
  _DWORD *v17; // r5
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int *v22; // r6
  unsigned int v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r6
  unsigned int v28; // r2
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  _DWORD *v33; // r0
  unsigned int v34; // r4
  unsigned int v35; // r1

  v6 = a2;
  v7 = 0;
  v8 = SmcCacheReference(a1, a2);
  v9 = v8;
  if ( !v8 )
    return -1073741672;
  v11 = (unsigned __int8 *)(v8 + 120);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = KeAbPreAcquire(v8 + 120, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex(v11);
  while ( __strex(v15 | 1, v11) );
  __dmb(0xBu);
  if ( (v15 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 120), v13, v9 + 120);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = (_DWORD *)SmcStoreEntryFind(v9, a3, a4);
  v17 = v16;
  if ( v16 )
  {
    v16[1] |= 4u;
    *v16 = -1;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v11);
    while ( __strex(v18 - 1, (unsigned int *)v11) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v11);
    v19 = KeAbPostRelease((unsigned int)v11);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
    v22 = v17 + 3;
    do
      v23 = __ldrex(v22);
    while ( !v23 && __strex(1u, v22) );
    __dmb(0xBu);
    if ( v23 && v23 != 1 )
      ExfWaitForRundownProtectionRelease(v17 + 3, v23);
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( __strex(1u, v22) );
    __dmb(0xBu);
    SmStoreDelete(a4, a3);
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v25 + 308);
    v26 = KeAbPreAcquire((unsigned int)v11, 0, 0);
    v27 = v26;
    do
      v28 = __ldrex(v11);
    while ( __strex(v28 | 1, v11) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v11, v26, (unsigned int)v11);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    v7 = v17[2];
    v17[2] = 0;
    v17[1] &= 0xFFFFFFFB;
    v10 = 0;
  }
  else
  {
    v10 = -1073741672;
  }
  __dmb(0xBu);
  do
    v29 = __ldrex((unsigned int *)v11);
  while ( __strex(v29 - 1, (unsigned int *)v11) );
  if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v11);
  v30 = KeAbPostRelease((unsigned int)v11);
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(v30);
  v33 = (_DWORD *)(a1 + 16 * (v6 & 0xF) + 4);
  __pld(v33);
  v34 = *v33 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v35 = __ldrex(v33);
  while ( v35 == v34 && __strex(v34 - 2, v33) );
  if ( v35 != v34 )
    ExfReleaseRundownProtection((unsigned __int8 *)v33);
  if ( v7 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v7);
  return v10;
}
