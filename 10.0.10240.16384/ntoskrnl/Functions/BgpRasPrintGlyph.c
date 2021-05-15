// BgpRasPrintGlyph 
 
int __fastcall BgpRasPrintGlyph(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4, int a5, char a6, _DWORD *a7, int a8, _DWORD *a9)
{
  _DWORD *v10; // r9
  char *v12; // r7
  int v13; // r8
  int *v14; // r10
  int v15; // r4
  int v16; // r2
  int v17; // r1
  int v18; // r5
  BOOL v19; // r6
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r6
  unsigned __int64 v28; // r4
  unsigned int v29; // r2
  unsigned int v30; // r1
  __int64 v31; // r2
  __int64 v32; // r0
  int v33; // r0
  unsigned int v34; // r2
  int v35; // r3
  int v36; // r5
  int v37; // r4
  int v38; // r0
  int v39; // r4
  int v40; // r0
  int *v41; // r0
  int v43; // [sp+18h] [bp-F0h] BYREF
  char *v44; // [sp+1Ch] [bp-ECh] BYREF
  int v45; // [sp+20h] [bp-E8h]
  BOOL v46; // [sp+24h] [bp-E4h]
  int v47; // [sp+28h] [bp-E0h]
  int v48; // [sp+30h] [bp-D8h] BYREF
  int v49; // [sp+34h] [bp-D4h]
  int v50; // [sp+38h] [bp-D0h]
  int *v51; // [sp+3Ch] [bp-CCh] BYREF
  _DWORD *v52; // [sp+40h] [bp-C8h]
  int v53; // [sp+44h] [bp-C4h]
  _DWORD *v54; // [sp+48h] [bp-C0h]
  int v55[2]; // [sp+50h] [bp-B8h] BYREF
  int v56; // [sp+58h] [bp-B0h]
  _DWORD *v57; // [sp+5Ch] [bp-ACh]
  _DWORD v58[4]; // [sp+60h] [bp-A8h] BYREF
  char v59; // [sp+70h] [bp-98h] BYREF
  int v60; // [sp+A8h] [bp-60h] BYREF
  int v61; // [sp+ACh] [bp-5Ch]
  unsigned int v62; // [sp+B0h] [bp-58h]
  int v63; // [sp+BCh] [bp-4Ch]

  v55[0] = a4;
  v10 = a9;
  v57 = a7;
  *a7 = 0;
  v12 = 0;
  v44 = 0;
  v45 = 0;
  v48 = 0;
  v47 = 0;
  v43 = 0;
  v52 = a2;
  v53 = 0;
  v54 = a1;
  v56 = a8;
  v13 = 0;
  v14 = 0;
  v51 = 0;
  v46 = (a6 & 1) != 0;
  if ( !a9 )
  {
    v10 = v58;
    v58[0] = 0;
    v58[1] = 0;
    v58[2] = 0;
  }
  if ( a3 < 0x20 )
  {
    v19 = v46;
    v37 = 0;
    goto LABEL_57;
  }
  v15 = a2[2];
  if ( !a8
    || !*(_BYTE *)(a8 + 49)
    || (RaspGetCacheEntry((_DWORD *)(a8 + 12), a3, a2[3], *(_DWORD *)(v15 + 20), v15, &v44), (v12 = v44) == 0) )
  {
    RaspGetCacheEntry(&RaspBitmapCache, a3, a2[3], *(_DWORD *)(v15 + 20), v15, &v44);
    v12 = v44;
    if ( !v44 )
    {
      if ( (dword_619018 & 4) != 0 )
      {
        v16 = 1;
        v53 = 1;
      }
      else
      {
        v16 = 0;
      }
      if ( (v16 & 1) == 0 && !RaspProvidesWorkspace(v10) && (a2[4] & v17) == 0 )
        v45 = 1;
      v13 = RaspRasterize((int)a2, a3, v16, (int)&v43, v16, &v43, &v48, (int *)&v44, (int)v10);
      if ( v13 < 0 )
      {
        v37 = v43;
        v18 = v45;
        v19 = v46;
LABEL_50:
        if ( !v18 )
          goto LABEL_57;
        if ( v12 )
          RaspDestroyCachedBitmap(v12);
        goto LABEL_54;
      }
      if ( v45 )
      {
        v12 = (char *)BgpFwAllocateMemory(0x32u);
        if ( !v12 )
        {
          v13 = -1073741801;
          v18 = v45;
          v19 = v46;
          v47 = v43;
LABEL_49:
          v37 = v47;
          goto LABEL_50;
        }
      }
      else
      {
        v12 = &v59;
      }
      v20 = v10[2];
      v21 = *(_DWORD *)(v15 + 20);
      *((_DWORD *)v12 + 6) = a2[3];
      v22 = v48;
      *((_WORD *)v12 + 22) = a3;
      *((_DWORD *)v12 + 5) = v21;
      *((_DWORD *)v12 + 7) = v22;
      v23 = (int)v44;
      *((_DWORD *)v12 + 3) = v15;
      *(_DWORD *)(v12 + 46) = v20;
      *((_DWORD *)v12 + 8) = v23;
      *((_DWORD *)v12 + 9) = 4;
      *((_DWORD *)v12 + 10) = 4;
      v47 = v43;
      *((_DWORD *)v12 + 2) = v43;
    }
  }
  v24 = *((_DWORD *)v12 + 10);
  v25 = **((_DWORD **)v12 + 2);
  v44 = (char *)*((_DWORD *)v12 + 2);
  if ( !v24 )
    __brkdiv0();
  v26 = *((_DWORD *)v12 + 7);
  v27 = a2[2];
  v48 = v25 / v24;
  v43 = v26;
  v28 = *(__int16 *)(v15 + 66) * (unsigned __int64)*(unsigned int *)(v27 + 76);
  v29 = v52[3];
  v30 = v28 * v29;
  LODWORD(v28) = (v28 * v29) >> 32;
  LODWORD(v31) = v30 << 6;
  HIDWORD(v31) = (v30 >> 26) | ((_DWORD)v28 << 6);
  v32 = 72i64 * *(unsigned __int16 *)(v27 + 88);
  if ( !v32 )
    __brkdiv0();
  v33 = _rt_sdiv64(v32, v31);
  v34 = BgpFmRoundUp(v33) + a5;
  v35 = *((_DWORD *)v12 + 8);
  if ( v35 < 0 || v35 <= v34 )
  {
    v36 = v34 - v35;
  }
  else
  {
    v36 = 0;
    DbgPrintEx(101, 0, (int)"BGFX internal font error char %x!\n", *((unsigned __int16 *)v12 + 22));
  }
  v38 = v48;
  if ( *v54 < (unsigned int)(v36 + v48) || (v39 = v43, v54[1] < (unsigned int)(v43 + v55[0])) )
  {
    v18 = v45;
    v19 = v46;
    v13 = -2147483643;
  }
  else
  {
    v19 = v46;
    if ( v46 )
    {
      v14 = &v60;
      memmove((int)&v60, (int)v54, 0x40u);
      if ( (v52[4] & 1) != 0 )
        v39 = v61;
      else
        v61 = v39;
      v43 = v39;
      v60 = v48;
      v63 += (v62 >> 3) * v39 * v36;
    }
    else
    {
      v48 = v43;
      v49 = v38;
      v50 = v43;
      v40 = RaspRectangleCreate(&v48, 32, &v51);
      v14 = v51;
      v13 = v40;
      if ( v40 < 0 )
      {
        v18 = v45;
        goto LABEL_49;
      }
    }
    RaspAntiAlias(v44, v14, *((_DWORD *)v12 + 9), *((_DWORD *)v12 + 10), v52);
    if ( !v19 )
    {
      v48 = 0;
      v49 = 0;
      v55[1] = v36;
      BgpGxCopyRectangle(v54, v14, v55, &v48);
    }
    v18 = v45;
    *v57 = v43;
    if ( v18 )
    {
      if ( v56 && *(_BYTE *)(v56 + 49) )
        v41 = (int *)(v56 + 12);
      else
        v41 = &RaspBitmapCache;
      RaspAddCacheEntry(v41, v12);
    }
  }
  if ( v13 < 0 )
    goto LABEL_49;
  v37 = v47;
LABEL_54:
  if ( v18 )
  {
LABEL_58:
    if ( v13 >= 0 || v12 )
      goto LABEL_62;
    goto LABEL_60;
  }
LABEL_57:
  if ( (v53 & 1) != 0 )
    goto LABEL_58;
LABEL_60:
  if ( v37 )
    RaspFreeMemory(v37, (int)v10);
LABEL_62:
  if ( !v19 && v14 )
    RaspFreeMemory((int)v14, (int)v10);
  v10[2] = 0;
  return v13;
}
