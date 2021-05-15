// RaspInitializeGlyphData 
 
int __fastcall RaspInitializeGlyphData(int a1, int a2, int *a3, int a4)
{
  int v6; // r0
  int v7; // r4
  int v8; // r10
  int v9; // r4
  int v10; // r0
  int v11; // r7
  int v13; // r4
  int v14; // r9
  int v15; // r8
  _BYTE *v16; // r0
  _BYTE *v17; // r4
  int v18; // r3
  int v19; // r2
  int v20; // r3
  int v21; // r3
  int v22; // r2
  _BYTE *v23; // r5
  _WORD *v24; // r4
  int v25; // r6
  int v26; // r8
  int v27; // r6
  int v28; // r3
  int v29; // r4
  int v30; // r8
  int v31; // r0
  _BYTE *v32; // r6
  int v33; // r0
  int v34; // r4
  _BYTE *v35; // r1
  int v36; // r6
  int v37; // r7
  int i; // r4
  int v39; // r7
  int j; // r4
  int v41; // r0
  int v42; // r1
  int v43; // r7
  int v44; // r6
  int v45; // r0
  int v46; // r2
  int v47; // r3
  int v48; // r3
  unsigned __int16 v49; // [sp+0h] [bp-40h] BYREF
  int v50; // [sp+4h] [bp-3Ch] BYREF
  int v51; // [sp+8h] [bp-38h]
  int v52; // [sp+Ch] [bp-34h]
  int *v53; // [sp+10h] [bp-30h]
  __int16 v54; // [sp+18h] [bp-28h] BYREF
  __int16 v55; // [sp+1Ah] [bp-26h] BYREF
  __int16 v56; // [sp+1Ch] [bp-24h] BYREF
  __int16 v57; // [sp+1Eh] [bp-22h] BYREF
  __int16 v58[16]; // [sp+20h] [bp-20h] BYREF

  v53 = a3;
  v51 = a4;
  v52 = a2;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v58[0] = 0;
  v49 = 0;
  LOWORD(v50) = 0;
  if ( !a1 )
    return -1073741823;
  v6 = *(_DWORD *)(a1 + 40);
  if ( !v6 )
    return -1073741823;
  v7 = v6 + a2;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
  FioFwReadUshortAtOffset(v8, v6 + a2, &v54);
  FioFwReadUshortAtOffset(v8, v7 + 2, &v55);
  FioFwReadUshortAtOffset(v8, v7 + 4, &v56);
  FioFwReadUshortAtOffset(v8, v7 + 6, &v57);
  v9 = v7 + 8;
  v10 = FioFwReadUshortAtOffset(v8, v9, v58);
  v11 = v54;
  if ( v54 < 0 )
    return sub_54DAE4(v10);
  if ( v54 )
  {
    v13 = v9 + 2 * v54;
    FioFwReadUshortAtOffset(v8, v13, &v50);
    v14 = (unsigned __int16)(v50 + 1);
    FioFwReadUshortAtOffset(v8, v13 + 2, &v49);
    v15 = v49;
    v50 = 9 * v14 + 2 * (v11 + 31);
    v16 = (_BYTE *)RaspAllocateMemory(v50 + v49);
    v17 = v16;
    if ( v16 )
    {
      memset(v16, 0, v50 + v15);
      v18 = v56;
      v19 = v55;
      *(_WORD *)v17 = v11;
      *(_DWORD *)(v17 + 6) = v18;
      v20 = v57;
      *(_DWORD *)(v17 + 2) = v19;
      *(_DWORD *)(v17 + 18) = v19;
      *(_DWORD *)(v17 + 10) = v20;
      v21 = v58[0];
      v22 = v52;
      *((_WORD *)v17 + 11) = v15;
      *(_DWORD *)(v17 + 14) = v21;
      *((_WORD *)v17 + 12) = v14;
      v23 = v17;
      v24 = v17 + 46;
      v25 = *(_DWORD *)(a1 + 40) + v22 + 10;
      *(_DWORD *)(v23 + 26) = v24;
      if ( v11 > 0 )
      {
        LOWORD(v26) = 0;
        do
        {
          FioFwReadUshortAtOffset(v8, v25, v24);
          v26 = (__int16)(v26 + 1);
          v25 += 2;
          ++v24;
        }
        while ( v26 < v11 );
        v15 = v49;
      }
      v27 = v25 + 2;
      *(_DWORD *)(v23 + 30) = v24;
      FioFwReadBytesAtOffset(v8, v27, v15, v24);
      v28 = (int)v24 + v15;
      v29 = v51;
      v52 = v28;
      v30 = v15 + v27;
      *(_DWORD *)(v23 + 34) = v28;
      v31 = RaspAllocateMemory(v14);
      v32 = (_BYTE *)v31;
      v50 = v31;
      if ( v31 )
      {
        FioFwReadBytesAtOffset(v8, v30, v14, v31);
        v33 = 0;
        v34 = 0;
        if ( v14 )
        {
          v35 = v32;
          do
          {
            *(_BYTE *)(*(_DWORD *)(v23 + 34) + v34) = *v35;
            v34 = (__int16)(v34 + 1);
            if ( (*v35 & 8) != 0 )
            {
              v43 = (unsigned __int8)v35[1];
              if ( v35[1] )
              {
                LOWORD(v44) = 0;
                do
                {
                  *(_BYTE *)(*(_DWORD *)(v23 + 34) + v34) = *v35;
                  v34 = (__int16)(v34 + 1);
                  v44 = (__int16)(v44 + 1);
                }
                while ( v44 < v43 );
              }
              ++v33;
              ++v35;
            }
            ++v33;
            ++v35;
          }
          while ( v34 < v14 );
        }
        v36 = v33 + v30;
        v37 = v14 + v52;
        *(_DWORD *)(v23 + 38) = v14 + v52;
        if ( v14 )
        {
          for ( i = 0; i < v14; i = (__int16)(i + 1) )
          {
            *(_DWORD *)(v37 + 4 * i) = 0;
            if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + i) & 2) != 0 )
            {
              FioFwReadBytesAtOffset(v8, v36++, 1, v37 + 4 * i);
              if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + i) & 0x10) == 0 )
                *(_DWORD *)(v37 + 4 * i) = -*(_DWORD *)(v37 + 4 * i);
            }
            else if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + i) & 0x10) != 0 )
            {
              *(_DWORD *)(v37 + 4 * i) = 0;
            }
            else
            {
              FioFwReadUshortAtOffset(v8, v36, (_WORD *)(v37 + 4 * i));
              v36 += 2;
            }
          }
        }
        v39 = *(_DWORD *)(v23 + 38) + 4 * (v14 + 2);
        *(_DWORD *)(v23 + 42) = v39;
        if ( v14 )
        {
          for ( j = 0; j < v14; j = (__int16)(j + 1) )
          {
            *(_DWORD *)(v39 + 4 * j) = 0;
            if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + j) & 4) != 0 )
            {
              FioFwReadBytesAtOffset(v8, v36++, 1, v39 + 4 * j);
              if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + j) & 0x20) == 0 )
                *(_DWORD *)(v39 + 4 * j) = -*(_DWORD *)(v39 + 4 * j);
            }
            else if ( (*(_BYTE *)(*(_DWORD *)(v23 + 34) + j) & 0x20) != 0 )
            {
              *(_DWORD *)(v39 + 4 * j) = 0;
            }
            else
            {
              FioFwReadUshortAtOffset(v8, v36, (_WORD *)(v39 + 4 * j));
              v36 += 2;
            }
          }
        }
        v41 = v50;
        v42 = v51;
        *v53 = (int)v23;
        RaspFreeMemory(v41, v42);
        return 0;
      }
      RaspFreeMemory(v23, v29);
    }
  }
  else
  {
    v45 = RaspAllocateMemory(46);
    if ( v45 )
    {
      v46 = v55;
      *(_DWORD *)(v45 + 6) = v56;
      v47 = v57;
      *(_WORD *)v45 = v11;
      *(_DWORD *)(v45 + 2) = v46;
      *(_DWORD *)(v45 + 10) = v47;
      v48 = v58[0];
      *(_DWORD *)(v45 + 18) = v46;
      *(_WORD *)(v45 + 22) = 0;
      *(_DWORD *)(v45 + 14) = v48;
      *(_WORD *)(v45 + 24) = 0;
      *a3 = v45;
      return 0;
    }
  }
  return -1073741670;
}
