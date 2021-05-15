// XpressBuildHuffmanDecodingTable 
 
int __fastcall XpressBuildHuffmanDecodingTable(_WORD *a1, _BYTE *a2)
{
  _WORD *v2; // r3
  _WORD *v3; // r10
  unsigned int v4; // r4
  _WORD *v5; // r5
  _WORD *v6; // r2
  unsigned int v7; // t1
  unsigned int v8; // r3
  _WORD *v9; // r2
  int v10; // r0
  int v11; // r5
  _WORD *v12; // r6
  int v13; // r2
  unsigned int i; // r4
  __int16 v15; // r3
  bool v16; // zf
  int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  bool v20; // zf
  _WORD *v21; // r4
  int v22; // r6
  int v23; // r4
  _WORD *v24; // r8
  int v25; // r5
  int v26; // r2
  __int16 v27; // lr
  unsigned int v28; // r0
  _WORD *v29; // r3
  int result; // r0
  _WORD *v31; // r3
  _WORD *v32; // r3
  int v33; // r0
  _WORD *v34; // r3
  int v35; // r0
  _WORD *v36; // r3
  int v37; // r0
  _WORD *v38; // r0
  _WORD *v39; // r3
  int v40; // r0
  _WORD *v41; // r1
  _WORD *v42; // r3
  int v43; // r0
  _WORD *v44; // r3
  int v45; // r0

  v2 = a1 + 512;
  v3 = a1;
  do
    *v2++ = 512;
  while ( v2 != a1 + 528 );
  v4 = 0;
  v5 = a1;
  do
  {
    if ( (*a2 & 0xF) != 0 )
    {
      v6 = &a1[*a2 & 0xF];
      *v5 = v6[512];
      v6[512] = v4;
    }
    v7 = (unsigned __int8)*a2++;
    v8 = v7 >> 4;
    if ( v7 >> 4 )
    {
      v9 = &a1[v8];
      v5[1] = v9[512];
      v9[512] = v4 + 1;
    }
    v4 += 2;
    v5 += 2;
  }
  while ( v4 < 0x200 );
  v10 = -1024;
  v11 = 1024;
  v12 = v3 + 15;
  v13 = -1023;
  for ( i = 15; i > 0xA; --i )
  {
    v15 = v13;
    v16 = v13 == v10;
    if ( v13 < v10 )
    {
      v41 = &v3[v11];
      do
      {
        v41[1552] = v13;
        --v11;
        --v41;
        v15 += 2;
        LOWORD(v13) = v15;
      }
      while ( v15 < v10 );
      v16 = v15 == v10;
    }
    if ( v16 )
      goto LABEL_60;
    v17 = (unsigned __int16)v12[512];
    v13 = (__int16)(v10 + 1);
    if ( v17 != 512 )
    {
      v38 = &v3[v11];
      do
      {
        v38[1552] = i + 16 * v17;
        v17 = (unsigned __int16)v3[v17];
        --v11;
        --v38;
      }
      while ( v17 != 512 );
    }
    --v12;
    v10 = (__int16)-(__int16)v11;
  }
  v18 = 1023;
  v19 = v13;
  v20 = v13 == v10;
  if ( v13 < v10 )
  {
    v21 = v3 + 1023;
    do
    {
      v21[528] = v13;
      --v18;
      --v21;
      v19 += 2;
      LOWORD(v13) = v19;
    }
    while ( v19 < v10 );
    v20 = v19 == v10;
  }
  if ( v20 )
LABEL_60:
    JUMPOUT(0x510F0E);
  v22 = 0;
  v23 = 10;
  v24 = v3 + 10;
  do
  {
    v25 = (unsigned __int16)v24[512];
    if ( v25 != 512 )
    {
      v26 = 10 - v23;
      do
      {
        v27 = v23 + 16 * v25;
        if ( v22 || (v18 + 1) << v26 > 0x400 )
          goto LABEL_60;
        v28 = v18 << v26;
        switch ( v26 )
        {
          case 0:
            goto LABEL_27;
          case 1:
            goto LABEL_26;
          case 2:
            goto LABEL_25;
          case 3:
            v31 = &v3[v28];
            v31[535] = v27;
            v31[534] = v27;
            v31[533] = v27;
            v31[532] = v27;
LABEL_25:
            v29 = &v3[v28];
            v29[531] = v27;
            v29[530] = v27;
LABEL_26:
            v3[v28 + 529] = v27;
LABEL_27:
            v3[v28 + 528] = v27;
            break;
          case 4:
            v32 = &v3[v28];
            v33 = 4;
            do
            {
              v32[528] = v27;
              v32[529] = v27;
              v32[530] = v27;
              v32[531] = v27;
              v32 += 4;
              --v33;
            }
            while ( v33 );
            break;
          case 5:
            v34 = &v3[v28];
            v35 = 8;
            do
            {
              v34[528] = v27;
              v34[529] = v27;
              v34[530] = v27;
              v34[531] = v27;
              v34 += 4;
              --v35;
            }
            while ( v35 );
            break;
          case 6:
            v36 = &v3[v28];
            v37 = 16;
            do
            {
              v36[528] = v27;
              v36[529] = v27;
              v36[530] = v27;
              v36[531] = v27;
              v36 += 4;
              --v37;
            }
            while ( v37 );
            break;
          case 7:
            v39 = &v3[v28];
            v40 = 32;
            do
            {
              v39[528] = v27;
              v39[529] = v27;
              v39[530] = v27;
              v39[531] = v27;
              v39 += 4;
              --v40;
            }
            while ( v40 );
            break;
          case 8:
            v42 = &v3[v28];
            v43 = 64;
            do
            {
              v42[528] = v27;
              v42[529] = v27;
              v42[530] = v27;
              v42[531] = v27;
              v42 += 4;
              --v43;
            }
            while ( v43 );
            break;
          case 9:
            v44 = &v3[v28];
            v45 = 128;
            do
            {
              v44[528] = v27;
              v44[529] = v27;
              v44[530] = v27;
              v44[531] = v27;
              v44 += 4;
              --v45;
            }
            while ( v45 );
            break;
        }
        if ( !v18 )
          v22 = 1;
        v25 = (unsigned __int16)v3[v25];
        --v18;
      }
      while ( v25 != 512 );
    }
    --v23;
    v18 >>= 1;
    --v24;
  }
  while ( v23 );
  if ( v22 )
    result = 0;
  else
    result = sub_510EDC();
  return result;
}
