// -SmStOutSwapStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStOutSwapStore(_DWORD *a1)
{
  int v1; // r10
  int v3; // r7
  unsigned int *v4; // r1
  _DWORD *v5; // r5
  unsigned int v6; // r2
  int v7; // r4
  int v8; // r6
  unsigned int v9; // r2
  unsigned int *v10; // r9
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r0
  unsigned int *v16; // r1
  unsigned int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r3
  int v20; // r9
  unsigned int v21; // r2
  unsigned int *v22; // r9
  int v23; // r0
  int v24; // r5
  unsigned int v25; // r2
  int *v26; // r5
  int v27; // t1
  unsigned int *v28; // r5
  unsigned int v29; // r2
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  unsigned int *v33; // r1
  unsigned int v34; // r2
  unsigned int v36; // r2
  int v37; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  int v40; // [sp+8h] [bp-50h] BYREF
  int v41; // [sp+Ch] [bp-4Ch]
  int v42; // [sp+10h] [bp-48h]
  unsigned int v43; // [sp+14h] [bp-44h] BYREF
  _DWORD *v44; // [sp+18h] [bp-40h]
  unsigned int *v45; // [sp+1Ch] [bp-3Ch]
  int v46; // [sp+20h] [bp-38h]
  int v47; // [sp+24h] [bp-34h] BYREF
  unsigned int v48; // [sp+28h] [bp-30h]
  unsigned int *v49; // [sp+2Ch] [bp-2Ch]
  int v50; // [sp+30h] [bp-28h]
  int v51; // [sp+34h] [bp-24h]
  int v52; // [sp+38h] [bp-20h]

  v40 = 0;
  v41 = -1;
  v44 = 0;
  v1 = 0;
  v46 = 0;
  v3 = 0;
  ST_STORE<SM_TRAITS>::StDrainReadContextList((int)a1);
  v4 = a1 + 965;
  v5 = (_DWORD *)a1[965];
  v49 = a1 + 965;
  __dmb(0xBu);
  if ( !v5 || v5 == (_DWORD *)-1 )
  {
    v7 = -1073700861;
    v8 = v40;
    v20 = 0;
    goto LABEL_29;
  }
  __dmb(0xBu);
  do
    v6 = __ldrex(v4);
  while ( (_DWORD *)v6 == v5 && __strex(0xFFFFFFFF, v4) );
  __dmb(0xBu);
  if ( (_DWORD *)v6 != v5 )
    return -1073700861;
  if ( *v5 )
  {
    v7 = -1073741791;
    v8 = v40;
    goto LABEL_51;
  }
  v41 = 0;
  v42 = 1;
  v44 = v5;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 310);
  v10 = a1 + 880;
  v11 = KeAbPreAcquire((unsigned int)(a1 + 880), 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( !v13 && __strex(0x11u, v10) );
  __dmb(0xBu);
  if ( v13 )
    ExfAcquirePushLockSharedEx(v10, v11, (unsigned int)v10);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v8 = v40;
  v1 = ExAllocatePoolWithTag(512, 4 * a1[914]);
  v46 = v1;
  if ( v1 )
  {
    v14 = 0;
    v43 = 0;
    v47 = 0;
LABEL_20:
    while ( 1 )
    {
      v15 = RtlFindNextForwardRunClearCapped(v5 + 1, v14, 0xFFFFFFFF, &v43);
      if ( !v15 )
        break;
      v14 = v43;
      v48 = v15 + v43;
      if ( v43 < v15 + v43 )
      {
        v45 = (unsigned int *)(v1 + 4 * v3);
        while ( 1 )
        {
          if ( (*(_DWORD *)(a1[915] + 4 * v14) & 0x7FFF0000) != 0 )
          {
            v43 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion((int)a1, v14, 0, 4, 4u);
            if ( !SmArrayGrow(v3, 8, &v47, &v40) )
            {
              SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion(a1, v14);
              v7 = -1073741670;
              v8 = v40;
              v20 = v42;
              goto LABEL_29;
            }
            v8 = v40;
            v16 = v45;
            v17 = v43;
            v18 = (unsigned int *)(v40 + 8 * v3);
            *v45 = v14;
            *v18 = v17;
            v19 = a1[913];
            ++v3;
            v45 = v16 + 1;
            v18[1] = v19;
          }
          v43 = ++v14;
          if ( v14 >= v48 )
            goto LABEL_20;
        }
      }
    }
    __dmb(0xBu);
    do
      v36 = __ldrex(v10);
    while ( v36 == 17 && __strex(0, v10) );
    if ( v36 != 17 )
      ExfReleasePushLockShared(v10);
    v37 = KeAbPostRelease((unsigned int)v10);
    v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v39 = *(_WORD *)(v38 + 0x136) + 1;
    *(_WORD *)(v38 + 310) = v39;
    if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 )
      KiCheckForKernelApcDelivery(v37);
    v20 = 0;
    if ( !v3 )
    {
      v7 = -1073741607;
      v5 = (_DWORD *)v41;
LABEL_52:
      __dmb(0xBu);
      v33 = v49;
      do
        v34 = __ldrex(v33);
      while ( __strex((unsigned int)v5, v33) );
      __dmb(0xBu);
      goto LABEL_55;
    }
    v50 = 0;
    v51 = v8;
    v52 = v3;
    v7 = SmPerformStoreSwapOperation(1);
    if ( v7 >= 0 )
    {
      v41 = (int)v5;
      *v5 = v50;
      v44 = 0;
      v7 = 0;
    }
LABEL_29:
    if ( v3 )
    {
      if ( !v20 )
      {
        v42 = 1;
        v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v21 + 310);
        v22 = a1 + 880;
        v23 = KeAbPreAcquire((unsigned int)(a1 + 880), 0, 0);
        v24 = v23;
        do
          v25 = __ldrex(v22);
        while ( !v25 && __strex(0x11u, v22) );
        __dmb(0xBu);
        if ( v25 )
          ExfAcquirePushLockSharedEx(v22, v23, (unsigned int)v22);
        v20 = v42;
        if ( v24 )
          *(_BYTE *)(v24 + 14) |= 1u;
      }
      v26 = (int *)v1;
      do
      {
        v27 = *v26++;
        SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion(a1, v27);
        --v3;
      }
      while ( v3 );
      v1 = v46;
    }
    if ( !v20 )
      goto LABEL_50;
    goto LABEL_42;
  }
  v7 = -1073741670;
LABEL_42:
  v28 = a1 + 880;
  __dmb(0xBu);
  do
    v29 = __ldrex(v28);
  while ( v29 == 17 && __strex(0, v28) );
  if ( v29 != 17 )
    ExfReleasePushLockShared(a1 + 880);
  v30 = KeAbPostRelease((unsigned int)(a1 + 880));
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x136) + 1;
  *(_WORD *)(v31 + 310) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 )
    KiCheckForKernelApcDelivery(v30);
LABEL_50:
  v5 = (_DWORD *)v41;
LABEL_51:
  if ( v5 != (_DWORD *)-1 )
    goto LABEL_52;
LABEL_55:
  if ( v44 )
    ExFreePoolWithTag(v44);
  if ( v8 )
    ExFreePoolWithTag(v8);
  if ( v1 )
    ExFreePoolWithTag(v1);
  return v7;
}
