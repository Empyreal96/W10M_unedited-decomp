// RtlCompressBufferXpressHuffMax 
 
int __fastcall RtlCompressBufferXpressHuffMax(unsigned int a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7, int a8, unsigned int a9)
{
  int v9; // r9
  unsigned int v10; // r6
  int result; // r0
  unsigned __int8 *v14; // r4
  int v15; // r2
  unsigned __int8 *v16; // r0
  unsigned int v17; // r7
  _DWORD *v18; // r1
  _BYTE *v19; // r5
  int v20; // r6
  char v21; // r3
  int v22; // r0
  unsigned __int8 *v23; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r3
  unsigned __int8 *v27; // r1
  int v28; // r9
  int v29; // r3
  unsigned int v30; // r7
  unsigned __int8 *v31; // lr
  int v32; // r3
  int v33; // r3
  unsigned __int8 *v34; // r4
  unsigned __int8 *v35; // r0
  unsigned __int8 *i; // r1
  unsigned __int8 *v37; // r3
  unsigned __int8 *v38; // r0
  unsigned int v39; // r2
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  unsigned int v43; // r2
  char v44; // r3
  int v45; // r3
  unsigned int v46; // r2
  _WORD *v47; // r5
  int v48; // r0
  unsigned int v49; // r2
  int *v50; // r2
  int v51; // r3
  int *v52; // r2
  int v53; // r3
  char v54; // t1
  int v55; // r6
  int v56; // r0
  bool v57; // zf
  int v58; // r2
  unsigned int v59; // [sp+8h] [bp-60h]
  int v60; // [sp+Ch] [bp-5Ch]
  unsigned int v61; // [sp+10h] [bp-58h]
  _DWORD *v62; // [sp+14h] [bp-54h]
  unsigned int v63; // [sp+18h] [bp-50h]
  unsigned __int8 *v64; // [sp+1Ch] [bp-4Ch]
  unsigned int v65; // [sp+20h] [bp-48h]
  unsigned __int8 *v66; // [sp+24h] [bp-44h]
  int v67; // [sp+28h] [bp-40h]
  unsigned int v68; // [sp+2Ch] [bp-3Ch]
  unsigned __int8 *v69; // [sp+30h] [bp-38h]
  int v70; // [sp+34h] [bp-34h]
  unsigned int v71; // [sp+38h] [bp-30h]
  int v73[10]; // [sp+40h] [bp-28h] BYREF

  v9 = a3;
  v10 = a1 + a2;
  v71 = a3 + a4;
  v63 = a1 + a2;
  if ( a4 >= 0x12C )
  {
    if ( a1 <= 0x10001 )
      return -1073741637;
    memset((_BYTE *)a6, 0, 0x20000);
    *(_DWORD *)(a6 + 0x20000) = 0;
    v14 = (unsigned __int8 *)a1;
    v70 = v9;
    if ( !a7 || (v15 = a9, v68 = a9, a9 > a2) )
    {
      v15 = a2;
      v68 = a2;
    }
    v73[0] = a7;
    v73[1] = a8;
    v73[2] = v15;
    v61 = 0;
    v65 = 3;
    v64 = 0;
LABEL_8:
    v67 = 0;
    v60 = 0;
    memset((_BYTE *)(a6 + 672272), 0, 2048);
    v16 = v14 + 0x10000;
    v69 = v14 + 0x10000;
    if ( (unsigned int)(v14 + 0x10000) > v10 )
    {
      v16 = (unsigned __int8 *)v10;
      v69 = (unsigned __int8 *)v10;
    }
    v17 = (unsigned int)(v16 - 5);
    v66 = v16 - 5;
    v59 = (unsigned int)&v14[v68];
    if ( v16 - 5 < &v14[v68] )
      v59 = (unsigned int)(v16 - 5);
    v18 = (_DWORD *)(a6 + 674576);
    v19 = (_BYTE *)(a6 + 674580);
    v20 = 1;
    v62 = (_DWORD *)(a6 + 674576);
    if ( v14 == (unsigned __int8 *)a1 )
    {
      ++*(_DWORD *)(a6 + 4 * *v14 + 672272);
      v21 = *v14++;
      *v19 = v21;
      v19 = (_BYTE *)(a6 + 674581);
      v20 = 2;
    }
    if ( (unsigned int)v14 >= v17 )
      goto LABEL_90;
    v22 = (int)&v14[-a1] % 0x20000;
    v23 = v14;
    do
    {
      v24 = *((unsigned __int16 *)XpressHashFunction + *v23) ^ *((unsigned __int16 *)&XpressHashFunction[256] + v23[2]) ^ *((unsigned __int16 *)&XpressHashFunction[128] + v23[1]);
      v25 = *(_DWORD *)(a6 + 4 * v24);
      *(_DWORD *)(a6 + 4 * v24) = v23;
      v26 = a6 + 4 * v22;
      ++v23;
      v22 = (v22 + 1) & 0x1FFFF;
      *(_DWORD *)(v26 + 0x20000) = v25;
    }
    while ( (unsigned int)v23 < v17 );
    while ( 1 )
    {
      while ( 1 )
      {
        if ( (unsigned int)v14 >= v59 )
        {
          if ( (unsigned int)v14 >= v17 )
          {
            v18 = v62;
            v16 = v69;
LABEL_90:
            while ( v14 < v16 )
            {
              ++*(_DWORD *)(a6 + 4 * *v14 + 672272);
              v54 = *v14++;
              *v19++ = v54;
              if ( v20 <= 0 )
              {
                *v18 = 2 * v20;
                v18 = v19;
                v20 = 1;
                v19 += 4;
              }
              else
              {
                v20 *= 2;
              }
            }
            while ( v20 > 0 )
              v20 = 2 * v20 + 1;
            *v18 = 2 * v20 + 1;
            if ( (unsigned int)v14 < v63 )
            {
              v55 = 0;
            }
            else
            {
              v55 = 1;
              ++*(_DWORD *)(a6 + 673296);
            }
            if ( v60 + 4 * ((unsigned int)(XpressBuildHuffmanEncodings(a6 + 655360) + v67 + 31) >> 5) + v70 + 258 >= v71 )
              return -1073741789;
            v56 = XpressDoHuffmanPass(a6 + 655360, a6 + 674576, v19);
            v57 = v55 == 0;
            v10 = v63;
            v70 = v56;
            if ( !v57 )
            {
              v58 = v56 - a3;
              result = 0;
              *a5 = v58;
              return result;
            }
            goto LABEL_8;
          }
          v59 = RtlpMakeXpressCallback(v73, v17, v14);
        }
        v27 = *(unsigned __int8 **)(a6 + 4 * ((int)&v14[-a1] % 0x20000) + 0x20000);
        v28 = *(_DWORD *)v14;
        if ( v27 + 0x10000 > v14 )
        {
          v29 = *(_DWORD *)v27 ^ v28;
          if ( !v29 )
            goto LABEL_22;
          if ( (v29 & 0xFFFFFF) == 0 )
            break;
          v27 = *(unsigned __int8 **)(a6 + 4 * ((int)&v27[-a1] % 0x20000) + 0x20000);
          if ( v27 + 0x10000 > v14 )
          {
            v32 = *(_DWORD *)v27 ^ v28;
            if ( !v32 )
              goto LABEL_22;
            if ( (v32 & 0xFFFFFF) == 0 )
              break;
            v27 = *(unsigned __int8 **)(a6 + 4 * ((int)&v27[-a1] % 0x20000) + 0x20000);
            if ( v27 + 0x10000 > v14 )
            {
              v33 = *(_DWORD *)v27 ^ v28;
              if ( !v33 )
              {
LABEL_22:
                v30 = (unsigned int)v14;
                v31 = v14 - 0x10000;
                goto LABEL_34;
              }
              if ( (v33 & 0xFFFFFF) == 0 )
                break;
            }
          }
        }
LABEL_71:
        ++v14;
        ++*(_DWORD *)(a6 + 4 * (unsigned __int8)v28 + 672272);
        *v19++ = v28;
        if ( v20 <= 0 )
        {
          v52 = v62;
          v53 = 2 * v20;
          v20 = 1;
          v62 = v19;
          *v52 = v53;
          v19 += 4;
        }
        else
        {
          v20 *= 2;
        }
      }
      v30 = (unsigned int)v14;
      v31 = v14 - 0x10000;
      v64 = v27;
      do
      {
        v27 = *(unsigned __int8 **)(a6 + 4 * ((int)&v27[-a1] % 0x20000) + 0x20000);
        if ( v27 <= v31 )
          break;
        if ( v28 == *(_DWORD *)v27 )
        {
          v14 = (unsigned __int8 *)v30;
LABEL_34:
          v34 = v14 + 4;
          v35 = v34 + 32;
          for ( i = v27 + 4; ; i += 32 )
          {
            if ( (unsigned int)v35 >= v63 )
            {
              while ( (unsigned int)v34 < v63 && *v34 == *i )
              {
                ++v34;
                ++i;
              }
              goto LABEL_62;
            }
            if ( *(_DWORD *)v34 != *(_DWORD *)i )
              goto LABEL_53;
            if ( *((_DWORD *)v34 + 1) != *((_DWORD *)i + 1) )
            {
              v34 += 4;
              i += 4;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 2) != *((_DWORD *)i + 2) )
            {
              v34 += 8;
              i += 8;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 3) != *((_DWORD *)i + 3) )
            {
              v34 += 12;
              i += 12;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 4) != *((_DWORD *)i + 4) )
            {
              v34 += 16;
              i += 16;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 5) != *((_DWORD *)i + 5) )
            {
              v34 += 20;
              i += 20;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 6) != *((_DWORD *)i + 6) )
            {
              v34 += 24;
              i += 24;
              goto LABEL_53;
            }
            if ( *((_DWORD *)v34 + 7) != *((_DWORD *)i + 7) )
              break;
            v34 += 32;
            v35 += 32;
          }
          v34 += 28;
          i += 28;
LABEL_53:
          if ( *v34 == *i )
          {
            if ( v34[1] == i[1] )
            {
              if ( v34[2] == i[2] )
              {
                v34 += 3;
                i += 3;
              }
              else
              {
                v34 += 2;
                i += 2;
              }
            }
            else
            {
              ++v34;
              ++i;
            }
          }
LABEL_62:
          v37 = &v34[-v30];
          v27 = (unsigned __int8 *)(i - &v34[-v30]);
          if ( (unsigned int)&v34[-v30] <= v65 )
          {
            v61 += (unsigned int)v37;
            goto LABEL_66;
          }
          v65 = (unsigned int)&v34[-v30];
          v38 = v27;
          v64 = v27;
          if ( &v27[(int)v37] > (unsigned __int8 *)v30 )
            goto LABEL_68;
        }
LABEL_66:
        ++v61;
      }
      while ( v61 < 0xC );
      v38 = v64;
LABEL_68:
      v39 = v65;
      v61 = 0;
      v14 = (unsigned __int8 *)(v65 + v30);
      v40 = v30 - (_DWORD)v38;
      v65 = 3;
      if ( v39 == 3 && v40 > 0x1000 )
      {
        v14 = (unsigned __int8 *)v30;
        v17 = (unsigned int)v66;
        goto LABEL_71;
      }
      if ( v40 < 0x100 )
        v41 = *((unsigned __int8 *)XpressHighBitIndexTable + v40);
      else
        v41 = *((unsigned __int8 *)XpressHighBitIndexTable + (v40 >> 8)) + 8;
      v42 = v40 - (1 << v41);
      v43 = v39 - 3;
      v67 += v41;
      v44 = 16 * v41;
      if ( v43 < 0xF )
      {
        v45 = (unsigned __int8)(v44 + v43);
        *v19 = v45;
        v47 = v19 + 1;
      }
      else
      {
        v45 = (unsigned __int8)(v44 + 15);
        v46 = v43 - 15;
        *v19 = v45;
        if ( v46 < 0xFF )
        {
          v19[1] = v46;
          v47 = v19 + 2;
          v48 = v60 + 1;
LABEL_81:
          v60 = v48;
          goto LABEL_84;
        }
        v49 = v46 + 15;
        v19[1] = -1;
        if ( v49 < 0x10000 )
        {
          *((_WORD *)v19 + 1) = v49;
          v47 = v19 + 4;
          v48 = v60 + 3;
          goto LABEL_81;
        }
        *((_WORD *)v19 + 1) = 0;
        *((_DWORD *)v19 + 1) = v49;
        v47 = v19 + 8;
        v60 += 7;
      }
LABEL_84:
      ++*(_DWORD *)(a6 + 4 * v45 + 673296);
      *v47 = v42;
      v19 = v47 + 1;
      if ( v20 <= 0 )
      {
        v50 = v62;
        v51 = 2 * v20 + 1;
        v20 = 1;
        v62 = v19;
        *v50 = v51;
        v19 += 4;
      }
      else
      {
        v20 = 2 * v20 + 1;
      }
      v17 = (unsigned int)v66;
    }
  }
  return -1073741789;
}
