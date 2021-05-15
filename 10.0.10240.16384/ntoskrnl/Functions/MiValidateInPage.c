// MiValidateInPage 
 
int __fastcall MiValidateInPage(int a1)
{
  int v2; // r6
  int v3; // r10
  int v4; // r4
  unsigned int v5; // r8
  int *v6; // r9
  unsigned int v7; // r2
  int result; // r0
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r4
  int v12; // r6
  int v13; // r1
  int v14; // r1
  int v15; // r2
  unsigned int v16; // r6
  int v17; // r0
  int v18; // r7
  int v19; // r1
  int v20; // t1
  int v21; // r4
  unsigned int v22; // r4
  int v23; // r1
  int v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // kr08_4
  int v27; // r3
  char v28; // r1
  int v29; // r0
  __int16 v30; // r3
  int v31; // r1
  bool v32; // nf
  int v33; // r0
  unsigned int v34; // r2
  int v35; // r3
  unsigned int v36; // r2
  int v37; // r6
  int v38; // r0
  unsigned int v39; // [sp+10h] [bp-50h]
  int v40; // [sp+14h] [bp-4Ch]
  int v41; // [sp+18h] [bp-48h]
  int v42; // [sp+1Ch] [bp-44h]
  int v43; // [sp+20h] [bp-40h]
  int v44; // [sp+24h] [bp-3Ch]
  unsigned int v45; // [sp+28h] [bp-38h]
  int v46; // [sp+2Ch] [bp-34h]
  int v47; // [sp+30h] [bp-30h] BYREF
  unsigned int v48; // [sp+34h] [bp-2Ch]
  unsigned int v49; // [sp+38h] [bp-28h]
  int v50; // [sp+3Ch] [bp-24h]

  v39 = 0;
  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 120) + 56);
  v42 = *(_DWORD *)(a1 + 120);
  v43 = v2;
  v46 = 0;
  MiGetSessionIdForVa(*(_DWORD *)(a1 + 128));
  v3 = a1 + 152;
  if ( *(_DWORD *)(a1 + 144) )
    v3 = *(_DWORD *)(a1 + 144);
  v4 = *(_DWORD *)(a1 + 104);
  v5 = ((((unsigned __int16)*(_DWORD *)(v3 + 24) + (unsigned __int16)*(_DWORD *)(v3 + 16)) & 0xFFFu)
      + *(_DWORD *)(v3 + 20)
      + 4095) >> 12;
  v6 = (int *)(v3 + 28);
  v44 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v45 = v3 + 28 + 4 * v5;
  *(_QWORD *)(a1 + 56) += (unsigned int)(v4 - *(_DWORD *)(v3 + 24) - *(_DWORD *)(v3 + 20));
  v7 = v4 - *(_DWORD *)(v3 + 24) - *(_DWORD *)(v3 + 20);
  if ( (v7 & 0xFFF) != 0 )
    return sub_5449CC();
  *(_DWORD *)(a1 + 108) += v7 >> 12;
  v9 = *(_DWORD *)(v2 + 4);
  __dmb(0xBu);
  v10 = MmPfnDatabase + 24 * *v6;
  v11 = *(_DWORD *)(v10 + 8);
  if ( (v11 & 0x400) != 0 )
    v12 = (*(unsigned __int16 *)((*(_DWORD *)(v10 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v10 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v12 = (v11 >> 5) & 0x1F;
  if ( (v12 & 2) == 0 && !MiCanPageMove(v10) )
    LOBYTE(v12) = 2;
  if ( (*(_DWORD *)(v42 + 52) & 0xC000000) != 0 && (v9 & 0xFFFFFFF8) > 8 )
  {
    v13 = 1;
    v39 = 1;
  }
  else
  {
    v13 = 0;
  }
  if ( (MiFlags & 0x80000) != 0 && (v13 & 1) != 0 )
  {
    v13 |= 4u;
    v39 = v13;
    if ( (*(_DWORD *)(v42 + 28) & 0x4000000) != 0
      && (*(_WORD *)((v11 & 0xFFFFF800 | (2 * (v11 & 0x3FC))) + 0x12) & 2) != 0 )
    {
      v13 &= 0xFFFFFFFB;
      v39 = v13;
    }
  }
  if ( (*(_BYTE *)(a1 + 114) & 8) != 0 )
  {
    v14 = v13 | 2;
    v39 = v14;
    if ( (MiFlags & 0x100000) != 0 && (v14 & 4) == 0 && (v14 & 1) != 0 )
      v39 = v14 & 0xFFFFFFFD;
  }
  v15 = v12 & 2;
  v16 = v39;
  v41 = v15;
  if ( v15 && (BYTE2(MiFlags) & 3u) > 1 && (v39 & 4) == 0 )
  {
    if ( (*(_WORD *)(v3 + 6) & 1) != 0 )
      MmUnmapLockedPages(*(_DWORD *)(v3 + 12), v3, v15);
    ++dword_63381C;
    KeFlushTb(3, 2);
    v15 = v41;
  }
  v17 = (v39 >> 2) & 1;
  v40 = 0;
  if ( !v17 && (v9 & 0xFFFFFFF8) > 8 && v5 > 1 )
  {
    v30 = *(_WORD *)(v3 + 6);
    if ( (v30 & 0x4000) != 0 )
    {
      if ( (v30 & 5) != 0 )
      {
        v31 = *(_DWORD *)(v3 + 12);
      }
      else
      {
        v33 = MmMapLockedPagesSpecifyCache(v3, 0, 1, 0, 0, -1073741808);
        v15 = v41;
        v31 = v33;
        v17 = (v39 >> 2) & 1;
      }
      v40 = v31;
      if ( v31 )
      {
        if ( (*(_DWORD *)(v42 + 52) & 0xC000000) != 0 && !*(_DWORD *)(v43 + 8) )
        {
          result = SeGetStrongImageReference(v9 & 0xFFFFFFF8, &v47, v15);
          if ( result < 0 )
            return result;
          v15 = v41;
          *(_DWORD *)(v43 + 8) = v47;
          v17 = (v39 >> 2) & 1;
        }
        if ( (BYTE2(MiFlags) & 3u) <= 1 || v15 )
        {
          v32 = SeValidateImageData(v9 & 0xFFFFFFF8) < 0;
          v17 = (v39 >> 2) & 1;
          if ( v32 )
            v40 = 0;
        }
      }
    }
  }
  if ( (unsigned int)v6 >= v45 )
    return v46;
  v18 = 0;
  v48 = 4194300;
  v49 = 0x3FFFFF;
  v50 = 1070596096;
  while ( 1 )
  {
    v20 = *v6++;
    v19 = v20;
    v21 = MmPfnDatabase + 24 * v20;
    if ( v21 == dword_6348F8 )
      goto LABEL_30;
    if ( v40 )
    {
      if ( (BYTE2(MiFlags) & 3u) > 1 && !v41 )
        goto LABEL_25;
      v28 = 0;
LABEL_38:
      MiMarkPfnVerified(v21, v28);
      goto LABEL_25;
    }
    if ( v17 || (*(_DWORD *)(v43 + 4) & 0xFFFFFFF8) <= 8 )
    {
      if ( !v41 || (BYTE2(MiFlags) & 3) != 3 || (*(_DWORD *)(v43 + 4) & 0xFFFFFFF8) != 8 )
        goto LABEL_25;
      v28 = 2;
      goto LABEL_38;
    }
    if ( (BYTE2(MiFlags) & 3u) <= 1 || v41 )
    {
      v29 = MiValidateImagePfn(v42, v19, *(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 60), v44, -1);
      if ( v29 < 0 )
      {
        if ( v29 == -1073741670 )
          break;
        v46 = -1073740748;
      }
    }
LABEL_25:
    if ( (v16 & 2) != 0 )
    {
      if ( (BYTE2(MiFlags) & 3) == 3 && (*(_BYTE *)(v21 + 23) & 7) == 3 )
      {
        v34 = *(_DWORD *)(v21 + 8);
        v35 = (v34 & 0x400) != 0 ? (*(unsigned __int16 *)((*(_DWORD *)(v21 + 8) & 0xFFFFF800 | (2
                                                                                              * (*(_DWORD *)(v21 + 8) & 0x3FC)))
                                                        + 0x10) >> 1) & 0x1F : (v34 >> 5) & 0x1F;
        if ( (v35 & 2) != 0 )
          MiMarkPfnVerified(v21, 1);
      }
      if ( (*(_WORD *)(v3 + 6) & 1) != 0 )
      {
        v22 = *(_DWORD *)(v3 + 12) + (v18 >> 2 << 12);
        v23 = (v48 & (v22 >> 10)) - 0x40000000;
        v24 = *(_DWORD *)v23;
        if ( (*(_DWORD *)v23 & 0x200) != 0 )
        {
          v36 = v24 & 0xFFFFFDFF | 0x80;
          if ( (v48 & (v22 >> 10)) > v49 )
          {
            *(_DWORD *)v23 = v36;
          }
          else
          {
            v37 = 0;
            __dmb(0xBu);
            *(_DWORD *)v23 = v36;
            if ( (v24 & 2) == 0 && (((unsigned __int8)v24 | 0x80) & 2) != 0 )
              v37 = 1;
            if ( (unsigned int)(v50 + v23) <= 0xFFF )
            {
              v38 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v38, (_DWORD *)(v38 + 4 * (v23 & 0xFFF)), v36);
            }
            if ( v37 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
            v16 = v39;
          }
          if ( (MiFlags & 0x300) == 0 )
            KeFlushSingleTb(v22, 1);
        }
      }
      else
      {
        v22 = 0;
      }
      if ( MiRelocateImagePfn(v42, v22, *(_DWORD *)(a1 + 108), *(v6 - 1), 0) < 0 )
        break;
    }
LABEL_30:
    v25 = *(_DWORD *)(a1 + 60);
    v18 += 4;
    v26 = *(_DWORD *)(a1 + 56);
    *(_DWORD *)(a1 + 56) = v26 + 4096;
    v27 = *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 60) = (__PAIR64__(v25, v26) + 4096) >> 32;
    *(_DWORD *)(a1 + 108) = v27 + 1;
    if ( (unsigned int)v6 >= v45 )
      return v46;
    v17 = (v16 >> 2) & 1;
  }
  *(_DWORD *)(a1 + 48) = -1073741670;
  return v46;
}
