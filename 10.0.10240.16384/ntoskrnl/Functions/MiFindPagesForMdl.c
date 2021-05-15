// MiFindPagesForMdl 
 
int __fastcall MiFindPagesForMdl(int a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int a7, unsigned int a8, unsigned __int16 a9)
{
  int v10; // r7
  unsigned int v13; // r6
  int v14; // r0
  unsigned int v15; // r1
  int v16; // lr
  unsigned int v17; // r10
  unsigned int v18; // r2
  unsigned int v19; // r9
  unsigned int v20; // r4
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // lr
  int v24; // r1
  unsigned int v25; // r2
  unsigned int *v26; // r0
  unsigned int v27; // r4
  int v28; // [sp+Ch] [bp-4Ch]
  unsigned int v29; // [sp+18h] [bp-40h]
  int v30; // [sp+1Ch] [bp-3Ch]
  unsigned int v31; // [sp+20h] [bp-38h] BYREF
  unsigned int *v32; // [sp+24h] [bp-34h]
  int v33; // [sp+28h] [bp-30h]
  int v34; // [sp+2Ch] [bp-2Ch]
  int v35; // [sp+30h] [bp-28h]
  unsigned int v36; // [sp+34h] [bp-24h]

  v35 = a4;
  v36 = dword_640504;
  v33 = a1;
  v34 = 0;
  v10 = 0;
  if ( (unsigned __int16)KeNumberNodes > 1u )
    return sub_511E30();
  v13 = a3 & 0xFFFFFFFD;
  if ( (a3 & 0x100) != 0 )
    v13 |= 0x4000000u;
  v14 = *(_DWORD *)(a2 + 20) >> 12;
  v15 = a5 - v14;
  v29 = a5 - v14;
  if ( (v13 & 0x52) != 0 || a6 )
    goto LABEL_10;
  if ( a7 != dword_633850 )
  {
    v15 = a5 - v14;
LABEL_10:
    v32 = (unsigned int *)(a2 + 4 * (v14 + 7));
    v16 = 0;
    v17 = a6;
    v18 = a8;
    v30 = 0;
    v19 = a7;
    while ( (v13 & 0x20) == 0 )
    {
      v27 = *(_DWORD *)(a2 + 20);
      MiAllocateMostlyContiguous(v33, a2, v15 - v16, v17, v19, v13, 16);
      v16 = v30 + (*(_DWORD *)(a2 + 20) >> 12) - (v27 >> 12);
      v30 = v16;
      if ( *(_DWORD *)(a2 + 12) )
        v10 = 1;
      v15 = v29;
      if ( v16 == v29 )
        return v10;
      v18 = a8;
      if ( !a8 || v17 + a8 <= v17 || v17 + a8 > v36 )
        return v10;
      v17 += a8;
      if ( v19 + a8 <= v19 || v19 + a8 > v36 )
        v19 = v36;
      else
        v19 += a8;
    }
    if ( v18 )
      v20 = v18;
    else
      v20 = v15;
    v21 = v13 | 0x60000000;
    while ( MiFindContiguousPages(v33, v17, v19, v18, v20, v35, 0x80000000, v28, v21, &v31) >= 0 )
    {
      v22 = v31;
      v30 += v20;
      v23 = v31 + v20;
      v24 = MmPfnDatabase + 24 * v31;
      v25 = v31;
      if ( v31 < v31 + v20 )
      {
        v26 = v32;
        do
        {
          *v26++ = v25;
          if ( *(_DWORD *)(v24 + 8) == 128 )
            v10 = 1;
          ++v25;
          v24 += 24;
        }
        while ( v25 < v23 );
        v32 = v26;
        v22 = v31;
      }
      *(_DWORD *)(a2 + 20) += v20 << 12;
      if ( v30 == v29 )
        break;
      v18 = a8;
      v21 = v13 | 0x60000000;
      if ( (v13 & 0x40) == 0 )
      {
        v18 = a8;
        v19 = v22 - 1;
        v21 = v13 | 0x60000000;
        if ( v22 - v17 < v20 )
          break;
      }
    }
    return v10;
  }
  MiAllocateMdlPagesByLists(a1, a2, v29, a9, v13);
  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( (*(_DWORD *)(a2 + 20) & 0xFFFFF000) != 0 )
      v10 = 1;
  }
  return v10;
}
