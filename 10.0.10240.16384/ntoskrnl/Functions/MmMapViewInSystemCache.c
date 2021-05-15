// MmMapViewInSystemCache 
 
int __fastcall MmMapViewInSystemCache(int a1, unsigned int *a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int *v5; // r10
  int v7; // r0
  int v8; // r4
  int v9; // r0
  int v10; // r1
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int v14; // r7
  int v15; // r6
  _DWORD *v16; // r1
  _DWORD *v17; // r1
  _DWORD *v18; // r1
  int v19; // r2
  unsigned int v20; // r6
  unsigned int v21; // r8
  unsigned int v22; // r7
  _DWORD *v23; // r4
  int v24; // r0
  int v25; // r3
  _DWORD *v26; // r0
  unsigned int v27; // r2
  int v28; // r2
  unsigned int v29; // r0
  unsigned int v30; // r3
  char v31; // r3
  char v32; // r3
  int v33; // r0
  _DWORD *v34; // r1
  int v35; // r0
  _DWORD *v36; // r1
  int v37; // r0
  _DWORD *v38; // r1
  int v39; // r0
  int v40; // r0
  int v41; // r0
  int v42; // r0
  int v43; // r0
  int v44; // r0
  int v45; // [sp+8h] [bp-E0h]
  _DWORD *v47; // [sp+Ch] [bp-DCh]
  int v49; // [sp+14h] [bp-D4h]
  int v50; // [sp+18h] [bp-D0h]
  __int64 v51; // [sp+20h] [bp-C8h]
  int v53; // [sp+30h] [bp-B8h] BYREF
  char v54; // [sp+34h] [bp-B4h]
  char v55; // [sp+35h] [bp-B3h]
  int v56; // [sp+38h] [bp-B0h]
  int v57; // [sp+3Ch] [bp-ACh]
  int v58; // [sp+40h] [bp-A8h]
  int v59; // [sp+44h] [bp-A4h]

  v5 = a2;
  if ( (*(_DWORD *)(a1 + 32) & 0x20) != 0 )
    return sub_53B4DC();
  v7 = MiSectionControlArea(a1);
  v50 = v7;
  v8 = ((*a4 & 0xFFF) != 0) + (*a4 >> 12);
  v49 = v8;
  if ( !v8 )
    KeBugCheckEx(26, 1060999, v7);
  v9 = MiOffsetToProtos(v7);
  v11 = *v5;
  v45 = v9;
  if ( *v5 )
  {
    v13 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
    v14 = 0;
    if ( (*(_DWORD *)(((v11 >> 10) & 0x3FFFFC) - 1073741812) & 0xFFFFF000) == 0x2000 )
    {
      v29 = *(_DWORD *)(((v11 >> 10) & 0x3FFFFC) - 1073741816);
      while ( 1 )
      {
        __dmb(0xFu);
        v10 = KiTbFlushTimeStamp;
        __dmb(0xBu);
        v30 = (v10 - (v29 >> 12)) & 0xFFFFF;
        if ( v30 > 2 || ((v29 >> 12) & 1) == 0 && v30 >= 2 )
          break;
        if ( (v10 & 1) == 0 )
        {
          v57 = 0;
          v58 = 0;
          v53 = 0;
          v54 = 0;
          v55 = 0;
          v56 = 33;
          v59 = 0;
          MiInsertTbFlushEntry(&v53, v13 << 10, 64);
          MiFlushTbList(&v53);
          goto LABEL_7;
        }
        __dmb(0xFu);
        v31 = KiTbFlushTimeStamp;
        __dmb(0xBu);
        if ( (v31 & 1) != 0 )
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v32 = KiTbFlushTimeStamp;
            __dmb(0xBu);
          }
          while ( (v32 & 1) != 0 );
        }
        if ( ((v29 >> 12) & 1) == 0 )
          goto LABEL_7;
      }
    }
    goto LABEL_7;
  }
  v12 = MiObtainSystemCacheView();
  v13 = v12;
  if ( v12 )
  {
    *v5 = v12 << 10;
    v14 = 1;
LABEL_7:
    v15 = MiAddViewsForSection(v45, v10, v51 + v8, (v51 + (unsigned __int64)(unsigned int)v8) >> 32, 1);
    if ( v15 < 0 )
    {
      ++dword_634F80;
      if ( v14 )
      {
        *(_DWORD *)(MiState[((int)(((*v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032]
                  + 24 * ((*v5 >> 18) & 0xF)
                  + 12) = 0;
        if ( v13 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v13 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v13 = 0;
          if ( v13 + 1070596096 <= 0xFFF )
          {
            v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * (v13 & 0xFFF)), 0);
          }
        }
        v34 = (_DWORD *)(v13 + 4);
        if ( v13 + 1073741828 > 0x3FFFFF )
        {
          *v34 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v34 = 0;
          if ( v13 + 1070596100 <= 0xFFF )
          {
            v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v35, (_DWORD *)(v35 + 4 * ((unsigned __int16)v34 & 0xFFF)), 0);
          }
        }
        v36 = (_DWORD *)(v13 + 8);
        if ( v13 + 1073741832 > 0x3FFFFF )
        {
          *v36 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v36 = 0;
          if ( v13 + 1070596104 <= 0xFFF )
          {
            v37 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v37, (_DWORD *)(v37 + 4 * ((unsigned __int16)v36 & 0xFFF)), 0);
          }
        }
        v38 = (_DWORD *)(v13 + 12);
        if ( v13 + 1073741836 > 0x3FFFFF )
        {
          *v38 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v38 = 0;
          if ( v13 + 1070596108 <= 0xFFF )
          {
            v39 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v39, (_DWORD *)(v39 + 4 * ((unsigned __int16)v38 & 0xFFF)), 0);
          }
        }
        MmUnmapViewInSystemCache(v13 << 10, a1, 4);
      }
    }
    else
    {
      if ( v13 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v13 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v13 = 0;
        if ( v13 + 1070596096 <= 0xFFF )
        {
          v40 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v40, (_DWORD *)(v40 + 4 * (v13 & 0xFFF)), 0);
        }
      }
      v16 = (_DWORD *)(v13 + 4);
      if ( v13 + 1073741828 > 0x3FFFFF )
      {
        *v16 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
        if ( v13 + 1070596100 <= 0xFFF )
        {
          v41 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v41, (_DWORD *)(v41 + 4 * ((unsigned __int16)v16 & 0xFFF)), 0);
        }
      }
      v17 = (_DWORD *)(v13 + 8);
      if ( v13 + 1073741832 > 0x3FFFFF )
      {
        *v17 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v17 = 0;
        if ( v13 + 1070596104 <= 0xFFF )
        {
          v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v42, (_DWORD *)(v42 + 4 * ((unsigned __int16)v17 & 0xFFF)), 0);
        }
      }
      v18 = (_DWORD *)(v13 + 12);
      if ( v13 + 1073741836 > 0x3FFFFF )
      {
        *v18 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v18 = 0;
        if ( v13 + 1070596108 <= 0xFFF )
        {
          v43 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v43, (_DWORD *)(v43 + 4 * ((unsigned __int16)v18 & 0xFFF)), 0);
        }
      }
      v19 = *(_DWORD *)(v45 + 4);
      v20 = v19 + 4 * v51;
      v21 = v19 + 4 * *(_DWORD *)(v45 + 28);
      v22 = v13 + 4 * v8;
      v47 = (_DWORD *)(MiState[((int)(((*a2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032]
                     + 24 * ((*a2 >> 18) & 0xF));
      v23 = v47;
      __mrc(15, 0, 13, 0, 3);
      v24 = a3[1];
      v25 = v47[2];
      v47[4] = v49 | *a3;
      v47[5] = v24;
      v26 = (_DWORD *)v45;
      v47[2] = v25 & 0xFFFFFFFC;
      v47[3] = v45;
      if ( !*(_DWORD *)(v50 + 32) )
        v47[3] = v45 | 1;
      if ( v13 < v22 )
      {
        do
        {
          if ( v20 >= v21 )
          {
            v26 = (_DWORD *)v26[2];
            v20 = v26[1];
            v45 = (int)v26;
            v21 = v20 + 4 * v26[7];
            v47[3] |= 1u;
          }
          v27 = v20 & 0x1FC | (4 * (v20 & 0xFFFFFE00 | 0x100));
          if ( v13 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v13 = v27;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v13 = v27;
            if ( v13 + 1070596096 <= 0xFFF )
            {
              v44 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v44, (_DWORD *)(v44 + 4 * (v13 & 0xFFF)), v27);
              v26 = (_DWORD *)v45;
            }
          }
          v13 += 4;
          v20 += 4;
        }
        while ( v13 < v22 );
        v23 = v47;
      }
      __dmb(0xFu);
      v23[2] = *a2;
      if ( (v23[3] & 1) != 0 )
        v28 = 3;
      else
        v28 = 1;
      MiManageSubsectionView(v26, v23, v28);
      v15 = 0;
    }
    return v15;
  }
  v15 = -1073741801;
  ++dword_634F80;
  return v15;
}
