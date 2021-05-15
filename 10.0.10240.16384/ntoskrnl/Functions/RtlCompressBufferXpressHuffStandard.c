// RtlCompressBufferXpressHuffStandard 
 
int __fastcall RtlCompressBufferXpressHuffStandard(unsigned __int8 *a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7, int a8, unsigned int a9)
{
  int v9; // r6
  unsigned int v10; // r4
  unsigned __int8 **v11; // r3
  unsigned __int8 **v12; // r2
  unsigned __int8 *v13; // r5
  int v14; // r8
  int v15; // r6
  unsigned __int8 *v16; // lr
  _DWORD *v17; // r1
  _BYTE *v18; // r7
  int v19; // r8
  char v20; // r3
  int v21; // r1
  int v22; // r0
  unsigned __int8 *v23; // r6
  int v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r0
  unsigned __int8 *v28; // r1
  int v29; // r4
  int v30; // lr
  unsigned __int8 v31; // r3
  char v32; // t2
  int v33; // r2
  char v34; // t2
  int v35; // r0
  unsigned __int8 *v36; // r1
  int v37; // r2
  int v38; // lr
  int v39; // r10
  unsigned __int8 v40; // r4
  char v41; // t2
  unsigned __int8 v42; // r1
  char v43; // t2
  int v44; // r0
  unsigned __int8 *v45; // r1
  int v46; // r2
  unsigned int v47; // r1
  char v48; // t1
  int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r2
  char v52; // r3
  int v53; // r3
  unsigned int v54; // r2
  _WORD *v55; // r7
  unsigned int v56; // r2
  int v57; // r3
  _DWORD *v58; // r2
  unsigned __int8 *v59; // r4
  _DWORD *v60; // r2
  char v61; // t1
  int v62; // r3
  int v63; // r4
  int v64; // r0
  bool v65; // zf
  int v66; // r2
  int result; // r0
  int v68; // [sp+8h] [bp-60h]
  unsigned int v69; // [sp+Ch] [bp-5Ch]
  _DWORD *v70; // [sp+10h] [bp-58h]
  unsigned __int8 *v71; // [sp+14h] [bp-54h]
  int v72; // [sp+18h] [bp-50h]
  unsigned int v73; // [sp+1Ch] [bp-4Ch]
  int v74; // [sp+20h] [bp-48h]
  int v75; // [sp+24h] [bp-44h]
  unsigned __int8 *v76; // [sp+28h] [bp-40h]
  unsigned int v77; // [sp+2Ch] [bp-3Ch]
  unsigned __int8 *v78; // [sp+30h] [bp-38h]
  unsigned int v79; // [sp+34h] [bp-34h]
  int v81[10]; // [sp+40h] [bp-28h] BYREF

  v9 = a3;
  v10 = (unsigned int)&a1[a2];
  v79 = a3 + a4;
  v76 = a1;
  v73 = (unsigned int)&a1[a2];
  if ( a4 < 0x12C )
    return -1073741789;
  v11 = (unsigned __int8 **)a6;
  do
    *v11++ = a1;
  while ( v11 != (unsigned __int8 **)(a6 + 11224) );
  v12 = (unsigned __int8 **)(a6 + 11224);
  do
    *v12++ = a1;
  while ( v12 != (unsigned __int8 **)(a6 + 30608) );
  v77 = v10 - 40;
  v13 = a1;
  v74 = v9;
  if ( !a7 || (v14 = a9, v75 = a9, a9 > a2) )
  {
    v14 = a2;
    v75 = a2;
  }
  v81[0] = a7;
  v81[1] = a8;
  v81[2] = v14;
  do
  {
    v72 = 0;
    v15 = 0;
    v68 = 0;
    memset((_BYTE *)(a6 + 47520), 0, 2048);
    v16 = v13 + 0x10000;
    v71 = v13 + 0x10000;
    if ( (unsigned int)(v13 + 0x10000) > v10 )
    {
      v16 = (unsigned __int8 *)v10;
      v71 = (unsigned __int8 *)v10;
    }
    v69 = (unsigned int)&v13[v14];
    if ( v16 - 40 < &v13[v14] )
      v69 = (unsigned int)(v16 - 40);
    v17 = (_DWORD *)(a6 + 49824);
    v18 = (_BYTE *)(a6 + 49828);
    v19 = 1;
    v70 = (_DWORD *)(a6 + 49824);
    if ( v13 == v76 )
    {
      v19 = 2;
      ++*(_DWORD *)(a6 + 4 * *v13 + 47520);
      v20 = *v13++;
      *v18 = v20;
      v18 = (_BYTE *)(a6 + 49829);
    }
    if ( v13 < v16 - 40 )
    {
      while ( 1 )
      {
        v21 = a6 + 4 * *v13;
        v22 = v13[2] + 4 * v13[1];
        v23 = *(unsigned __int8 **)(v21 + 8 * v22);
        *(_DWORD *)(v21 + 8 * v22) = v13;
        v24 = *v13;
        if ( *v23 != v24 || v23[1] != v13[1] || v23[2] != v13[2] || v13 - v23 >= 0x10000 )
          goto LABEL_71;
        v25 = v13[3];
        v26 = v23[3];
        v78 = v13;
        if ( v25 != v26 )
        {
          v27 = v24 + 2 * v22;
          v28 = *(unsigned __int8 **)(a6 + 4 * (v25 + v27) + 11224);
          *(_DWORD *)(a6 + 4 * (v26 + v27) + 11224) = v23;
          if ( v13 - v28 >= 0x10000 || *(_DWORD *)v13 != *(_DWORD *)v28 )
            goto LABEL_31;
          v23 = v28;
          *(_DWORD *)(a6 + 4 * (v13[3] + v27) + 11224) = v13;
        }
        v29 = v13[4];
        v30 = v23[4];
        if ( v29 != v30 )
        {
          v31 = v13[2] + v13[1] + 97;
          v32 = __ROR4__((unsigned __int16)(v31 | (v31 << 8)), 1);
          v33 = (unsigned __int8)__ROR4__(
                                   (unsigned __int16)((unsigned __int8)(*v13 ^ v32) | ((unsigned __int8)(*v13 ^ v32) << 8)),
                                   5);
          v34 = __ROR4__(
                  (unsigned __int16)((unsigned __int8)(v13[3] + *v13) | ((unsigned __int8)(v13[3] + *v13) << 8)),
                  5);
          v35 = (unsigned __int8)__ROR4__(
                                   (unsigned __int16)((unsigned __int8)(v13[1] ^ v34) | ((unsigned __int8)(v13[1] ^ v34) << 8)),
                                   1)
              + 4 * v33;
          v36 = *(unsigned __int8 **)(a6 + 4 * (v29 + 2 * v35) + 11224);
          *(_DWORD *)(a6 + 4 * (v30 + 2 * v35) + 11224) = v23;
          if ( v13 - v36 >= 0x10000 || *(_DWORD *)v13 != *(_DWORD *)v36 || (v37 = v13[4], v37 != v36[4]) || v13 == v36 )
          {
            v13 += 4;
            v23 += 4;
            goto LABEL_68;
          }
          *(_DWORD *)(a6 + 4 * (v37 + 2 * v35) + 11224) = v13;
          v23 = v36;
        }
        v38 = v13[5];
        v39 = v23[5];
        if ( v38 == v39 )
          goto LABEL_41;
        v40 = v13[4];
        v41 = __ROR4__((unsigned __int16)(*v13 | (*v13 << 8)), 1);
        v42 = __ROR4__(
                (unsigned __int16)((unsigned __int8)((v41 + 69) ^ v40) | ((unsigned __int8)((v41 + 69) ^ v40) << 8)),
                5);
        v43 = __ROR4__((unsigned __int16)(v13[3] | (v13[3] << 8)), 5);
        v44 = (v13[2] ^ (unsigned __int8)__ROR4__((unsigned __int16)(*v13 | (*v13 << 8)), -v40))
            + 4
            * ((unsigned __int8)__ROR4__(
                                  (unsigned __int16)((unsigned __int8)(v13[1] ^ v43) | ((unsigned __int8)(v13[1] ^ v43) << 8)),
                                  1)
             + v42);
        v45 = *(unsigned __int8 **)(a6 + 4 * (v38 + 2 * v44) + 11224);
        *(_DWORD *)(a6 + 4 * (v39 + 2 * v44) + 11224) = v23;
        if ( v13 - v45 < 0x10000 && *(_DWORD *)v13 == *(_DWORD *)v45 && v13[4] == v45[4] )
        {
          v46 = v13[5];
          if ( v46 == v45[5] && v13 != v45 )
          {
            *(_DWORD *)(a6 + 4 * (v46 + 2 * v44) + 11224) = v13;
            v23 = v45;
LABEL_41:
            v13 += 6;
            for ( v23 += 6; ; v23 += 32 )
            {
              if ( (unsigned int)v13 >= v77 )
              {
                while ( (unsigned int)v13 < v73 && *v13 == *v23 )
                {
                  ++v13;
                  ++v23;
                }
                goto LABEL_68;
              }
              if ( *(_DWORD *)v13 != *(_DWORD *)v23 )
                break;
              if ( *((_DWORD *)v13 + 1) != *((_DWORD *)v23 + 1) )
              {
                v13 += 4;
                v23 += 4;
                break;
              }
              if ( *((_DWORD *)v13 + 2) != *((_DWORD *)v23 + 2) )
              {
                v13 += 8;
                v23 += 8;
                break;
              }
              if ( *((_DWORD *)v13 + 3) != *((_DWORD *)v23 + 3) )
              {
                v13 += 12;
                v23 += 12;
                break;
              }
              if ( *((_DWORD *)v13 + 4) != *((_DWORD *)v23 + 4) )
              {
                v13 += 16;
                v23 += 16;
                break;
              }
              if ( *((_DWORD *)v13 + 5) != *((_DWORD *)v23 + 5) )
              {
                v13 += 20;
                v23 += 20;
                break;
              }
              if ( *((_DWORD *)v13 + 6) != *((_DWORD *)v23 + 6) )
              {
                v13 += 24;
                v23 += 24;
                break;
              }
              if ( *((_DWORD *)v13 + 7) != *((_DWORD *)v23 + 7) )
              {
                v13 += 28;
                v23 += 28;
                break;
              }
              v13 += 32;
            }
            if ( *v13 != *v23 )
              goto LABEL_68;
            if ( v13[1] != v23[1] )
            {
              ++v13;
              ++v23;
              goto LABEL_68;
            }
            if ( v13[2] != v23[2] )
            {
              v13 += 2;
              v23 += 2;
              goto LABEL_68;
            }
LABEL_31:
            v13 += 3;
            v23 += 3;
            goto LABEL_68;
          }
        }
        v13 += 5;
        v23 += 5;
LABEL_68:
        v47 = v13 - v23;
        if ( v13 - v78 == 3 && v47 > 0x1000 )
        {
          v13 = v78;
LABEL_71:
          ++*(_DWORD *)(a6 + 4 * *v13 + 47520);
          v48 = *v13++;
          *v18++ = v48;
          if ( v19 <= 0 )
          {
            v60 = v70;
            v70 = v18;
            *v60 = 2 * v19;
            v18 += 4;
            v19 = 1;
            if ( (unsigned int)v13 >= v69 )
            {
              v16 = v71;
              v59 = v71 - 40;
              if ( v13 >= v71 - 40 )
              {
LABEL_91:
                v17 = v70;
                v15 = v68;
                break;
              }
LABEL_88:
              v69 = RtlpMakeXpressCallback(v81, v59, v13);
            }
          }
          else
          {
            v19 *= 2;
          }
        }
        else
        {
          if ( v47 < 0x100 )
            v49 = *((unsigned __int8 *)XpressHighBitIndexTable + v47);
          else
            v49 = *((unsigned __int8 *)XpressHighBitIndexTable + (v47 >> 8)) + 8;
          v50 = v47 - (1 << v49);
          v51 = v13 - v78 - 3;
          v72 += v49;
          v52 = 16 * v49;
          if ( v51 < 0xF )
          {
            v53 = (unsigned __int8)(v52 + v51);
            *v18 = v53;
            v55 = v18 + 1;
          }
          else
          {
            v53 = (unsigned __int8)(v52 + 15);
            v54 = v13 - v78 - 18;
            *v18 = v53;
            if ( v54 >= 0xFF )
            {
              v56 = v13 - v78 - 3;
              v18[1] = -1;
              if ( v56 >= 0x10000 )
              {
                *((_WORD *)v18 + 1) = 0;
                *((_DWORD *)v18 + 1) = v56;
                v55 = v18 + 8;
                v68 += 7;
              }
              else
              {
                *((_WORD *)v18 + 1) = v56;
                v55 = v18 + 4;
                v68 += 3;
              }
            }
            else
            {
              v18[1] = v54;
              v55 = v18 + 2;
              ++v68;
            }
          }
          ++*(_DWORD *)(a6 + 4 * v53 + 48544);
          *v55 = v50;
          v18 = v55 + 1;
          v57 = 2 * v19;
          if ( v19 <= 0 )
          {
            v58 = v70;
            v70 = v18;
            *v58 = v57 + 1;
            v19 = 1;
            v18 += 4;
          }
          else
          {
            v19 = v57 + 1;
          }
          if ( (unsigned int)v13 >= v69 )
          {
            v16 = v71;
            v59 = v71 - 40;
            if ( v13 >= v71 - 40 )
              goto LABEL_91;
            goto LABEL_88;
          }
        }
      }
    }
    while ( v13 < v16 )
    {
      ++*(_DWORD *)(a6 + 4 * *v13 + 47520);
      v61 = *v13++;
      *v18++ = v61;
      if ( v19 <= 0 )
      {
        *v17 = 2 * v19;
        v17 = v18;
        v18 += 4;
        v19 = 1;
      }
      else
      {
        v19 *= 2;
      }
    }
    while ( 1 )
    {
      v62 = 2 * v19;
      if ( v19 <= 0 )
        break;
      v19 = v62 + 1;
    }
    *v17 = v62 + 1;
    if ( (unsigned int)v13 < v73 )
    {
      v63 = 0;
    }
    else
    {
      v63 = 1;
      ++*(_DWORD *)(a6 + 48544);
    }
    if ( v15 + 4 * ((unsigned int)(XpressBuildHuffmanEncodings(a6 + 30608) + v72 + 31) >> 5) + v74 + 258 >= v79 )
      return -1073741789;
    v64 = XpressDoHuffmanPass(a6 + 30608, a6 + 49824, v18);
    v14 = v75;
    v65 = v63 == 0;
    v10 = v73;
    v74 = v64;
  }
  while ( v65 );
  v66 = v64 - a3;
  result = 0;
  *a5 = v66;
  return result;
}
