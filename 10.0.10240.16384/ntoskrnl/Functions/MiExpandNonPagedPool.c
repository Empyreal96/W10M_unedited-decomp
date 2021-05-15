// MiExpandNonPagedPool 
 
void __fastcall MiExpandNonPagedPool(__int16 a1, unsigned int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r5
  unsigned int v7; // lr
  int v8; // r7
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r8
  unsigned int v14; // r10
  int v15; // r9
  unsigned int v16; // r4
  unsigned int v17; // r0
  unsigned int v18; // r10
  unsigned int v19; // r4
  int v20; // r1
  unsigned int v21; // r4
  int v22; // r5
  unsigned int v23; // r7
  _DWORD *v24; // r10
  unsigned int v25; // r8
  unsigned int v26; // r9
  int v27; // r3
  int v28; // r1
  int v29; // r4
  _DWORD *v30; // r2
  unsigned int v31; // r9
  int v32; // r2
  unsigned int *v33; // lr
  unsigned int v34; // r1
  int v35; // r2
  unsigned int v36; // r0
  unsigned int v37; // r4
  int v38; // r3
  int v39; // r9
  int v40; // r0
  unsigned int v41; // r3
  int v42; // r4
  int v43; // r2
  unsigned int v44; // r0
  unsigned int v45; // r3
  unsigned int v46; // r0
  int v47; // r0
  unsigned int v49; // [sp+4h] [bp-74h]
  unsigned int v50; // [sp+8h] [bp-70h]
  unsigned int v51; // [sp+8h] [bp-70h]
  int v52; // [sp+Ch] [bp-6Ch]
  _DWORD *v53; // [sp+10h] [bp-68h]
  unsigned int v55; // [sp+18h] [bp-60h]
  unsigned int v56; // [sp+1Ch] [bp-5Ch]
  unsigned int v57; // [sp+20h] [bp-58h]
  int v59; // [sp+2Ch] [bp-4Ch]
  int v60; // [sp+30h] [bp-48h]
  int v61; // [sp+34h] [bp-44h]
  char v62[12]; // [sp+38h] [bp-40h] BYREF
  unsigned int v63; // [sp+44h] [bp-34h]
  int v64[3]; // [sp+48h] [bp-30h] BYREF
  unsigned int v65; // [sp+54h] [bp-24h]

  v64[0] = 0;
  v64[1] = 0;
  v64[2] = 0;
  v65 = 0;
  *a6 = 3;
  v6 = 0;
  v7 = a2;
  v8 = dword_6337E8 + 176 * a3;
  v9 = 0;
  v59 = v8;
  v52 = 1;
  if ( (a1 & 0x200) != 0 )
  {
    if ( (unsigned int)dword_640508 >= 0x100000 )
    {
      sub_510284();
      return;
    }
    v10 = *(_DWORD *)(dword_63F718 + 104 * a3 + 68) >> 15;
    v11 = -1;
    if ( (unsigned int)dword_640508 < 0x80000 )
      v11 = 2;
    if ( (v7 & 0x3FF) == 0
      || (v12 = *(_DWORD *)(v8 + 116), v12 < v11) && (v12 < v10 || *(_DWORD *)(v8 + 120) >= (v12 << 13) / 0xA) )
    {
      v9 = 1;
      v52 = 0;
      v6 = 2;
    }
  }
  v13 = (v7 + 1023) & 0xFFFFFC00;
  v63 = v13;
  if ( v13 < v7 )
    return;
  v14 = v13 >> 10;
  v53 = 0;
  v15 = 0;
  if ( v9 == 1 )
  {
    if ( a4 != -1 )
      goto LABEL_11;
    if ( MmProtectFreedNonPagedPool != 1 && MiObtainNonPagedPoolCharges(v14 << 10) == 1 )
    {
      v53 = MiGetLargePageChain(a3, v13 >> 10);
      if ( v53 )
        goto LABEL_11;
      v65 = v14 << 10;
      v64[0] = v14 << 10;
      MiReturnNonPagedPoolCharges(v64);
    }
    v52 = 1;
    v6 = 0;
  }
  if ( a5 == 1 )
    return;
LABEL_11:
  v16 = v13 >> 10;
  v17 = MiObtainSystemVa(v13 >> 10, 5);
  v18 = v17;
  v55 = v17;
  if ( !v17 )
  {
LABEL_79:
    if ( v53 )
    {
      MiFreeLargePageChain((int)v53);
      v65 = v16 << 10;
      v64[0] = v16 << 10;
      MiReturnNonPagedPoolCharges(v64);
    }
    if ( v18 )
      MiReturnSystemVa(v18, (v15 + 4) << 10, 5, 0);
    return;
  }
  v19 = ((v17 >> 10) & 0x3FFFFC) - 0x40000000;
  v15 = v19 + 4 * v13 - 4;
  v56 = (v17 - *(_DWORD *)(v8 + 136)) >> 22;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v8 + 128), (unsigned int)v62);
  v60 = v8 + 8 * (v52 + 18);
  if ( !MiSplitBitmapPages(5, *(_DWORD *)(v60 + 4) + (v56 >> 3), (v56 & 7) + (v13 >> 10))
    || !MiSplitBitmapPages(
          5,
          *(_DWORD *)(v8 + 164) + ((v18 - *(_DWORD *)(v8 + 136)) >> 15),
          (((v18 - *(_DWORD *)(v8 + 136)) >> 12) & 7) + (v13 >> 10 << 10)) )
  {
    KeReleaseInStackQueuedSpinLock((int)v62);
LABEL_78:
    v16 = v13 >> 10;
    goto LABEL_79;
  }
  KeReleaseInStackQueuedSpinLock((int)v62);
  v61 = v6 & 2;
  if ( (v6 & 2) == 0 && !MiMakeZeroedPageTables(v19, v19 + 4 * v13 - 4, v6) )
    goto LABEL_78;
  v20 = a4;
  if ( v53 || a4 != -1 )
  {
    if ( a2 != v13 || a4 != -1 )
      ++*(_DWORD *)(v8 + 116);
    *a6 = 1;
  }
  v21 = 0;
  v22 = ((v18 >> 20) & 0xFFC) - 1070596096;
  v50 = -1;
  v57 = 0;
  if ( v13 )
  {
    v23 = (v18 >> 20) & 0xFFC;
    v24 = v53;
    v51 = ((v13 - 1) >> 10) + 1;
    v25 = -1;
    while ( 1 )
    {
      *((_BYTE *)&MiState[29] + ((int)((v22 & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) = a3;
      if ( v24 )
      {
        if ( v20 == -1 )
          break;
      }
LABEL_21:
      v22 += 4;
      v23 += 4;
      if ( !--v51 )
      {
        v8 = v59;
        v18 = v55;
        v50 = v25;
        v13 = v63;
        goto LABEL_23;
      }
    }
    v30 = v24;
    v24 = (_DWORD *)*v24;
    v31 = ((int)v30 - MmPfnDatabase) / 24;
    v49 = v31;
    if ( dword_634C94 )
    {
      v32 = (v31 >> 10) & 0x1F;
      v33 = (unsigned int *)(dword_634C94 + 4 * (v31 >> 15));
      LOBYTE(v34) = 1;
      if ( (unsigned int)(v32 + 1) > 0x20 )
      {
        if ( v32 )
        {
          v42 = 32 - v32;
          __dmb(0xBu);
          v43 = ((1 << (32 - v32)) - 1) << v32;
          do
            v44 = __ldrex(v33);
          while ( __strex(v44 | v43, v33) );
          __dmb(0xBu);
          v34 = 1 - v42;
          ++v33;
          if ( (unsigned int)(1 - v42) >= 0x20 )
          {
            v45 = v34 >> 5;
            do
            {
              v34 -= 32;
              --v45;
              *v33++ = -1;
            }
            while ( v45 );
          }
          if ( !v34 )
            goto LABEL_52;
        }
        __dmb(0xBu);
        do
          v46 = __ldrex(v33);
        while ( __strex(v46 | ((1 << v34) - 1), v33) );
      }
      else
      {
        __dmb(0xBu);
        v35 = 1 << v32;
        do
          v36 = __ldrex(v33);
        while ( __strex(v36 | v35, v33) );
      }
      __dmb(0xBu);
    }
LABEL_52:
    v37 = (MiDetermineUserGlobalPteMask(0) | (v31 << 12)) & 0xFFFFF5FF | dword_681120 & 0x1ED | 0x412;
    if ( v23 + 3145728 > 0x3FFFFF )
    {
      *(_DWORD *)v22 = v37;
    }
    else
    {
      v38 = *(_DWORD *)v22;
      v39 = 0;
      __dmb(0xBu);
      *(_DWORD *)v22 = v37;
      if ( (v38 & 2) == 0 && (v37 & 2) != 0 )
        v39 = 1;
      if ( v23 <= 0xFFF )
      {
        v40 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v40, (_DWORD *)(v40 + 4 * (v22 & 0xFFF)), v37);
      }
      if ( v39 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
      v31 = v49;
    }
    if ( v61 )
      MiReplicatePteChange(v22 << 10, v22 << 10);
    MiInitializeLargeNonPagedPoolLeafFrames(v22 << 10, v31);
    if ( v31 < v25 )
      v25 = v31;
    v21 = v57;
    v20 = a4;
    if ( v31 + 1023 > v57 )
    {
      v21 = v31 | 0x3FF;
      v57 = v31 | 0x3FF;
    }
    goto LABEL_21;
  }
LABEL_23:
  v26 = (v18 - *(_DWORD *)(v8 + 136)) >> 12;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v8 + 128), (unsigned int)v62);
  if ( v21 )
  {
    v41 = *(_DWORD *)(v8 + 104);
    if ( v50 < v41 || !v41 )
      *(_DWORD *)(v8 + 104) = v50;
    if ( v21 > *(_DWORD *)(v8 + 108) )
      *(_DWORD *)(v8 + 108) = v21;
  }
  v27 = a2;
  if ( v13 == a2 )
  {
    v28 = v52;
  }
  else
  {
    RtlClearBits((_BYTE *)(v8 + 160), v26 + a2, v13 - a2);
    v28 = v52;
    *(_BYTE *)(((v56 + (v13 >> 10) - 1) >> 3) + *(_DWORD *)(v60 + 4)) &= ~(unsigned __int8)(1 << ((v56 + (v13 >> 10) - 1) & 7));
    v27 = a2;
    if ( v26 < *(_DWORD *)(v8 + 4 * (v52 + 42)) )
      *(_DWORD *)(v8 + 4 * (v52 + 42)) = v26 + a2;
    v18 = v55;
  }
  if ( a4 != -1 )
    v27 = a4;
  v29 = MiIncreaseNonPagedPoolUsage(v8, v28, v26, v27);
  KeReleaseInStackQueuedSpinLock((int)v62);
  if ( v29 == 1 )
    MiTrimSegmentCache();
  if ( (dword_682604 & 1) != 0 && *a6 == 1 && a4 == -1 )
  {
    v47 = MiInitPerfMemoryFlags(1, 5);
    MiLogPerfMemoryRangeEvent(v18, 0, v47, v13);
  }
}
