// MiClaimPhysicalRun 
 
int __fastcall MiClaimPhysicalRun(__int16 *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // r5
  int v9; // r4
  int v10; // r10
  int v11; // r6
  unsigned int *v12; // r9
  int v13; // r7
  unsigned __int8 *v14; // r1
  unsigned int v15; // r2
  char v16; // r0
  int v17; // r2
  unsigned int v18; // r1
  int i; // r4
  int v20; // r1
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r1
  int v24; // r1
  int v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  unsigned int v29; // r1
  int v30; // r5
  int v31; // r4
  unsigned int v32; // r1
  int v33; // r4
  unsigned __int8 *v34; // r1
  unsigned int v35; // r2
  unsigned int v36; // r1
  unsigned __int8 *v37; // r1
  unsigned int v38; // r3
  unsigned int v39; // r2
  unsigned __int8 *v40; // r1
  unsigned int v41; // r3
  unsigned int v42; // r2
  unsigned int *v43; // r2
  unsigned int v44; // r0
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // [sp+8h] [bp-40h] BYREF
  int v48; // [sp+Ch] [bp-3Ch]
  int v49; // [sp+10h] [bp-38h]
  int v50; // [sp+14h] [bp-34h]
  int v51; // [sp+18h] [bp-30h]
  __int16 *v52; // [sp+1Ch] [bp-2Ch]
  int v53; // [sp+20h] [bp-28h]
  int v54[9]; // [sp+24h] [bp-24h] BYREF

  v48 = a4;
  v7 = a2;
  v50 = a2;
  v51 = a3;
  v52 = a1;
  v47 = -1;
  if ( a7 )
    return sub_53BB08();
  v9 = a5;
  v10 = 0;
  v53 = -1;
  v49 = a5 & 0x800000;
  if ( (a5 & 0x800000) != 0 )
    v53 = a6;
  v11 = MmPfnDatabase + 24 * a2;
  v12 = (unsigned int *)(v11 + 12);
  while ( MI_IS_PFN(v7) )
  {
    v13 = KfRaiseIrql(2);
    v14 = (unsigned __int8 *)(v11 + 15);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    __dmb(0xBu);
    if ( v15 >> 7 )
    {
      v37 = (unsigned __int8 *)v12 + 3;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v38 = *v12;
          __dmb(0xBu);
        }
        while ( (v38 & 0x80000000) != 0 );
        do
          v39 = __ldrex(v37);
        while ( __strex(v39 | 0x80, v37) );
        __dmb(0xBu);
      }
      while ( v39 >> 7 );
    }
    if ( MiSystemPartition != v52 )
    {
      __dmb(0xBu);
      v45 = (unsigned int *)(v11 + 12);
      do
        v46 = __ldrex(v45);
      while ( __strex(v46 & 0x7FFFFFFF, v45) );
      goto LABEL_50;
    }
    v16 = *(_BYTE *)(v11 + 18);
    v17 = v16 & 7;
    if ( v17 == 5 )
    {
      if ( (*(_DWORD *)(v11 + 4) | 0x80000000) == -4 )
        goto LABEL_48;
      v30 = *(_DWORD *)(v11 + 20) >> 28 << byte_6337F5;
      v31 = dword_633814 & v50;
      __dmb(0xBu);
      do
        v32 = __ldrex(v12);
      while ( __strex(v32 & 0x7FFFFFFF, v12) );
      KfLowerIrql(v13);
      MiDrainZeroLookasides((int)v52, v11, v51 - v10, v30 | v31);
      v33 = KfRaiseIrql(2);
      v34 = (unsigned __int8 *)(v11 + 15);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 | 0x80, v34) );
      __dmb(0xBu);
      if ( v35 >> 7 )
      {
        v40 = (unsigned __int8 *)v12 + 3;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v41 = *v12;
            __dmb(0xBu);
          }
          while ( (v41 & 0x80000000) != 0 );
          do
            v42 = __ldrex(v40);
          while ( __strex(v42 | 0x80, v40) );
          __dmb(0xBu);
        }
        while ( v42 >> 7 );
      }
      v16 = *(_BYTE *)(v11 + 18);
      v13 = v33;
      v17 = v16 & 7;
      if ( v17 == 5 )
      {
        __dmb(0xBu);
        v43 = (unsigned int *)(v11 + 12);
        do
          v44 = __ldrex(v43);
        while ( __strex(v44 & 0x7FFFFFFF, v43) );
        v28 = v33;
        goto LABEL_51;
      }
      v9 = a5;
      v7 = v50;
    }
    if ( v17 > 1 )
    {
      if ( !*(_DWORD *)(v48 + 12) || (v20 = *(unsigned __int8 *)(v11 + 19), (v20 & 0xFFFFFF80) == 128) )
      {
        if ( v17 == 2 )
        {
          if ( *(_WORD *)(v11 + 16) )
            goto LABEL_48;
          MiReuseStandbyPage(v11);
          goto LABEL_16;
        }
        if ( v17 != 6 )
          goto LABEL_48;
        if ( (v16 & 0x10) != 0 )
          goto LABEL_48;
        if ( *(_WORD *)(v11 + 16) != 1 )
          goto LABEL_48;
        if ( (*(_BYTE *)(v11 + 23) & 7) == 2 )
          goto LABEL_48;
        if ( !*(_DWORD *)v11 )
          goto LABEL_48;
        LOBYTE(v20) = *(_BYTE *)(v11 + 19);
        if ( (v20 & 8) != 0 )
          goto LABEL_48;
      }
      if ( v17 <= 4 )
      {
        if ( (v9 & 0x4000000) == 0 && (*(_DWORD *)(v11 + 4) & 0x80000000) == 0
          || (v9 & 0x400000) != 0 && (v20 & 0x40) != 0 )
        {
LABEL_48:
          __dmb(0xBu);
          v26 = (unsigned int *)(v11 + 12);
          do
            v27 = __ldrex(v26);
          while ( __strex(v27 & 0x7FFFFFFF, v26) );
LABEL_50:
          v28 = v13;
LABEL_51:
          KfLowerIrql(v28);
          break;
        }
        v25 = MiObtainTransitionPage(v11, v13, v48, v53, &v47);
        if ( v25 == 3 )
        {
          if ( !v49 )
            goto LABEL_19;
LABEL_101:
          MiLockAndInsertPageInFreeList(v11);
LABEL_19:
          v11 += 24;
          v50 = ++v7;
          v12 += 6;
          ++v10;
          goto LABEL_20;
        }
        if ( v25 != 2 )
          break;
      }
      else
      {
        if ( v13 == 2 || (v9 & 8) != 0 || v17 != 6 || (v9 & 0x400000) != 0 && (v20 & 0x40) != 0 )
          goto LABEL_48;
        if ( (*(_BYTE *)(v11 + 23) & 7) == 2 )
        {
          __dmb(0xBu);
          do
            v29 = __ldrex(v12);
          while ( __strex(v29 & 0x7FFFFFFF, v12) );
          KfLowerIrql(v13);
          if ( MiSwapStackPage(v11, v48, a6, (int)&v47, v54) )
            goto LABEL_39;
          if ( (*(_BYTE *)(v11 + 23) & 7) == 2 )
            break;
        }
        else
        {
          if ( MiActivePageClaimCandidate(v11, 1) )
            goto LABEL_48;
          if ( (*(_DWORD *)(v11 + 20) & 0x8000000) != 0 )
            v21 = MiTrimSharedPage(v11, v13, v9);
          else
            v21 = MiStealPage(v11, v13, v48, a6, &v47);
          v22 = v21;
          __dmb(0xBu);
          do
            v23 = __ldrex(v12);
          while ( __strex(v23 & 0x7FFFFFFF, v12) );
          KfLowerIrql(v13);
          if ( v22 != 2 )
          {
            if ( !v22 )
              break;
LABEL_39:
            *(_DWORD *)(v11 + 8) = 128;
            if ( v49 )
              goto LABEL_101;
            __dmb(0xFu);
            v24 = KiTbFlushTimeStamp;
            __dmb(0xBu);
            MiSetPfnTbFlushStamp(v11, v24, 0);
            goto LABEL_19;
          }
        }
      }
    }
    else
    {
      if ( (*(_DWORD *)(v11 + 20) & 0xFFFFF) != 1048574 )
      {
        if ( !v49 )
          MiUnlinkFreeOrZeroedPage(v7, 0);
LABEL_16:
        __dmb(0xBu);
        do
          v18 = __ldrex(v12);
        while ( __strex(v18 & 0x7FFFFFFF, v12) );
        KfLowerIrql(v13);
        goto LABEL_19;
      }
      __dmb(0xBu);
      do
        v36 = __ldrex(v12);
      while ( __strex(v36 & 0x7FFFFFFF, v12) );
      KfLowerIrql(v13);
      if ( (v9 & 0x2000000) != 0 || MiDemoteLargeFreePage(v7) != 1 )
        break;
    }
LABEL_20:
    if ( v10 == v51 )
      return 0;
    v9 = a5;
  }
  for ( i = v51 - v10; v10; --v10 )
  {
    v11 -= 24;
    MiLockAndInsertPageInFreeList(v11);
  }
  return i;
}
