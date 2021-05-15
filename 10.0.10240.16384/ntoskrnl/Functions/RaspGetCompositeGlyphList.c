// RaspGetCompositeGlyphList 
 
int __fastcall RaspGetCompositeGlyphList(int a1, int a2, _WORD *a3, _WORD *a4, _WORD *a5, _DWORD *a6, int *a7, int a8)
{
  int v9; // r7
  int v10; // r3
  int v11; // r5
  int v12; // r8
  int v13; // r5
  int i; // r9
  _BYTE *v15; // r0
  _BYTE *v16; // r4
  int **v17; // r2
  __int16 v18; // r9
  int v19; // r3
  char v20; // r2
  _WORD *v21; // r2
  _WORD *v22; // r4
  int v23; // r4
  __int64 v24; // r2
  unsigned __int16 v26; // [sp+8h] [bp-38h] BYREF
  unsigned __int16 v27; // [sp+Ah] [bp-36h] BYREF
  unsigned __int16 v28; // [sp+Ch] [bp-34h] BYREF
  __int16 v29; // [sp+Eh] [bp-32h] BYREF
  _WORD *v30; // [sp+10h] [bp-30h] BYREF
  int v31; // [sp+14h] [bp-2Ch] BYREF
  _WORD *v32; // [sp+18h] [bp-28h]
  _WORD *v33; // [sp+1Ch] [bp-24h]
  int v34; // [sp+20h] [bp-20h]

  *a6 = 0;
  v32 = a3;
  v33 = a4;
  *a4 = 0;
  *a5 = 0;
  *a3 = 0;
  if ( a2 == -1 )
    return -1073741811;
  if ( !a1 )
    return -1073741823;
  v10 = *(_DWORD *)(a1 + 40);
  if ( !v10 )
    return -1073741823;
  v11 = v10 + a2;
  v12 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
  v27 = 0;
  FioFwReadUshortAtOffset(v12, v10 + a2, &v27);
  if ( (v27 & 0x8000u) == 0 )
    return -1073741811;
  v13 = v11 + 10;
  v34 = v13;
  *a7 = (int)a7;
  a7[1] = (int)a7;
  while ( 1 )
  {
    i = a8;
    v15 = (_BYTE *)RaspAllocateMemory(30, a8);
    v16 = v15;
    if ( !v15 )
    {
      v9 = -1073741670;
      break;
    }
    memset(v15, 0, 30);
    v17 = (int **)a7[1];
    *(_DWORD *)v16 = a7;
    *((_DWORD *)v16 + 1) = v17;
    if ( *v17 != a7 )
      __fastfail(3u);
    *v17 = (int *)v16;
    a7[1] = (int)v16;
    FioFwReadUshortAtOffset(v12, v13, &v29);
    v18 = v29;
    *((_WORD *)v16 + 6) = v29;
    FioFwReadUshortAtOffset(v12, v13 + 2, &v28);
    *((_WORD *)v16 + 7) = v28;
    FioFwReadUshortAtOffset(v12, v13 + 4, &v27);
    if ( (v18 & 1) != 0 )
    {
      *((_WORD *)v16 + 8) = v27;
      FioFwReadUshortAtOffset(v12, v13 + 6, &v27);
      v19 = v27;
      v13 += 8;
      *((_WORD *)v16 + 9) = v27;
    }
    else
    {
      v20 = v27;
      v13 += 6;
      v19 = (int)v27 >> 8;
      v16[16] = HIBYTE(v27);
      v16[17] = v20;
    }
    if ( (v18 & 8) != 0 )
    {
      FioFwReadUshortAtOffset(v12, v13, &v26);
      v19 = v26;
      v13 += 2;
      *((_WORD *)v16 + 10) = v26;
    }
    else if ( (v18 & 0x40) != 0 )
    {
      FioFwReadUshortAtOffset(v12, v13, &v26);
      *((_WORD *)v16 + 10) = v26;
      FioFwReadUshortAtOffset(v12, v13 + 2, &v26);
      v19 = v26;
      v13 += 4;
      *((_WORD *)v16 + 11) = v26;
    }
    else if ( (v18 & 0x80) != 0 )
    {
      FioFwReadUshortAtOffset(v12, v13, &v26);
      *((_WORD *)v16 + 10) = v26;
      FioFwReadUshortAtOffset(v12, v13 + 2, &v26);
      *((_WORD *)v16 + 11) = v26;
      FioFwReadUshortAtOffset(v12, v13 + 4, &v26);
      *((_WORD *)v16 + 12) = v26;
      FioFwReadUshortAtOffset(v12, v13 + 6, &v26);
      v19 = (__int16)v26;
      v13 += 8;
      *(_DWORD *)(v16 + 26) = (__int16)v26;
    }
    v9 = RaspMapGlyphIndexToLocation(a1, v28, &v31, v19);
    if ( v9 < 0 )
      break;
    v9 = RaspLoadGlyphData(a1, v31, (int)&v28, (int *)&v30, a8);
    if ( v9 < 0 )
      break;
    v21 = v32;
    *((_DWORD *)v16 + 2) = v30;
    v22 = v30;
    *v21 += v30[12];
    *v33 += *v22;
    if ( (v18 & 0x20) == 0 )
    {
      if ( (v18 & 0x100) != 0 )
      {
        FioFwReadUshortAtOffset(v12, v13, a5);
        v13 += 2;
      }
      *a6 = v13 - v34;
      return v9;
    }
  }
  for ( i = a8; ; RaspFreeMemory(v23, i) )
  {
    v23 = *a7;
    if ( (int *)*a7 == a7 )
      break;
    v24 = *(_QWORD *)v23;
    if ( *(int **)(v23 + 4) != a7 || *(_DWORD *)(v24 + 4) != v23 )
      __fastfail(3u);
    *a7 = v24;
    *(_DWORD *)(v24 + 4) = a7;
    RaspFreeMemory(*(_DWORD *)(v23 + 8), i);
  }
  return v9;
}
