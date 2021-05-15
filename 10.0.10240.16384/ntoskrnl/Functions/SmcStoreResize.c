// SmcStoreResize 
 
int __fastcall SmcStoreResize(int a1, int a2)
{
  unsigned int v3; // r6
  int v4; // r0
  int v5; // r4
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  unsigned __int8 *v9; // r8
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  _DWORD *v14; // r0
  _DWORD *v15; // r10
  unsigned int *v16; // r5
  unsigned int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r5
  _DWORD *v20; // r4
  unsigned int v21; // r1
  int *v22; // lr
  int v23; // t1
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned int v28; // r2
  int v29; // r0
  int v30; // r4
  unsigned int v31; // r2
  unsigned int v32; // r4
  _DWORD *v33; // r0
  unsigned int v34; // r1
  int *v35; // r5
  int v36; // t1
  unsigned int v37; // r1
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int *v41; // r0
  unsigned int v42; // r4
  unsigned int v43; // r1
  _DWORD *v44; // r0
  unsigned int v45; // r4
  unsigned int v46; // r1
  int v48; // [sp+8h] [bp-48h]
  unsigned int v49; // [sp+Ch] [bp-44h]
  _DWORD v51[2]; // [sp+18h] [bp-38h] BYREF
  _DWORD v52[12]; // [sp+20h] [bp-30h] BYREF

  v3 = 0;
  v48 = 0;
  v4 = SmcCacheReference(a1, *(_DWORD *)(a2 + 4));
  v5 = v4;
  if ( !v4 )
    return -1073741672;
  v7 = *(_DWORD *)(v4 + 8);
  if ( *(_DWORD *)(a2 + 16) > v7 )
  {
    v6 = -1073741811;
    goto LABEL_70;
  }
  v49 = (v7 + 31) >> 5;
  v8 = SmAlloc(4 * v49, 1917021555);
  v3 = v8;
  if ( v8 )
  {
    v51[0] = *(_DWORD *)(v5 + 8);
    v51[1] = v8;
    if ( (*(_DWORD *)a2 & 0x100) != 0 )
    {
      RtlSetAllBits(v51);
      v52[0] = 0;
      v52[3] = 0;
      v52[1] = 4;
      v52[2] = v3;
    }
    else
    {
      RtlClearAllBits((int)v51);
    }
    v9 = (unsigned __int8 *)(v5 + 120);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = KeAbPreAcquire(v5 + 120, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v9);
    while ( __strex(v13 | 1, v9) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 120), v11, v5 + 120);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    v14 = SmcStoreEntryFind(v5, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12));
    v15 = v14;
    if ( !v14 )
    {
      v6 = -1073741672;
      goto LABEL_55;
    }
    v16 = v14 + 3;
    __pld(v14 + 3);
    v17 = v14[3] & 0xFFFFFFFE;
    do
      v18 = __ldrex(v16);
    while ( v18 == v17 && __strex(v17 + 2, v16) );
    __dmb(0xBu);
    if ( v18 == v17 )
      v48 = 1;
    else
      v48 = ExfAcquireRundownProtection(v15 + 3);
    if ( (*(_DWORD *)a2 & 0x100) != 0 )
    {
      v6 = SmcStorePlacementGet(v5, *(_DWORD *)(a2 + 16), (int)v52, *(_DWORD *)a2);
      if ( v6 < 0 )
        goto LABEL_55;
      v19 = 0;
      v20 = (_DWORD *)v15[2];
      if ( v3 > v3 + 4 * v49 )
        v21 = 0;
      else
        v21 = (4 * v49 + 3) >> 2;
      v22 = (int *)v3;
      if ( v21 )
      {
        do
        {
          v23 = *v22++;
          ++v19;
          *v20++ |= v23;
        }
        while ( v19 < v21 );
      }
    }
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)v9);
    while ( __strex(v24 - 1, (unsigned int *)v9) );
    if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v9);
    v25 = KeAbPostRelease((unsigned int)v9);
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134) + 1;
    *(_WORD *)(v26 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery(v25);
    SmStoreResize(*(_DWORD *)(a2 + 12), *(_DWORD *)(a2 + 8), (int)v51, (int *)(a2 + 16), (*(_DWORD *)a2 >> 8) & 1);
    if ( (*(_DWORD *)a2 & 0x100) != 0 || !*(_DWORD *)(a2 + 16) )
    {
      v6 = 0;
LABEL_64:
      if ( v48 )
      {
        v41 = v15 + 3;
        __pld(v15 + 3);
        v42 = v15[3] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v43 = __ldrex(v41);
        while ( v43 == v42 && __strex(v42 - 2, v41) );
        if ( v43 != v42 )
          ExfReleaseRundownProtection((unsigned __int8 *)v41);
      }
      goto LABEL_70;
    }
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v28 + 308);
    v29 = KeAbPreAcquire((unsigned int)v9, 0, 0);
    v30 = v29;
    do
      v31 = __ldrex(v9);
    while ( __strex(v31 | 1, v9) );
    __dmb(0xBu);
    if ( (v31 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v9, v29, (unsigned int)v9);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    v32 = 0;
    v33 = (_DWORD *)v15[2];
    if ( v3 > v3 + 4 * v49 )
      v34 = 0;
    else
      v34 = (4 * v49 + 3) >> 2;
    v35 = (int *)v3;
    if ( v34 )
    {
      do
      {
        v36 = *v35++;
        ++v32;
        *v33++ ^= v36;
      }
      while ( v32 < v34 );
    }
    v6 = 0;
LABEL_55:
    __dmb(0xBu);
    do
      v37 = __ldrex((unsigned int *)v9);
    while ( __strex(v37 - 1, (unsigned int *)v9) );
    if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v9);
    v38 = KeAbPostRelease((unsigned int)v9);
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v40 = *(_WORD *)(v39 + 0x134) + 1;
    *(_WORD *)(v39 + 308) = v40;
    if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
      KiCheckForKernelApcDelivery(v38);
    goto LABEL_64;
  }
  v6 = -1073741670;
LABEL_70:
  v44 = (_DWORD *)(a1 + 16 * (*(_DWORD *)(a2 + 4) & 0xF) + 4);
  __pld(v44);
  v45 = *v44 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v46 = __ldrex(v44);
  while ( v46 == v45 && __strex(v45 - 2, v44) );
  if ( v46 != v45 )
    ExfReleaseRundownProtection((unsigned __int8 *)v44);
  if ( v3 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v3);
  return v6;
}
