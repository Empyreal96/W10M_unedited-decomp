// RtlDecompressBufferXpressHuff 
 
int __fastcall RtlDecompressBufferXpressHuff(_BYTE *a1, int a2, unsigned int *a3, int a4, int a5, _DWORD *a6, int a7)
{
  unsigned int *v7; // r8
  int result; // r0
  unsigned int v9; // r6
  unsigned int v10; // r5
  unsigned int v11; // r9
  _BYTE *v12; // r7
  unsigned __int16 *v13; // r8
  int v14; // t1
  int v15; // r1
  unsigned int v16; // r0
  _BYTE *v17; // r3
  unsigned int v18; // lr
  int v19; // r2
  __int16 v20; // r3
  int v21; // r4
  int v22; // r2
  int v23; // r5
  int v24; // r4
  unsigned int v25; // r2
  unsigned int v26; // r4
  unsigned int v27; // r6
  _BYTE *v28; // r2
  char *v29; // r2
  int v30; // t1
  int v31; // r2
  int v32; // t1
  unsigned int v33; // r4
  int v34; // t1
  int v35; // r2
  int v36; // r5
  int v37; // r4
  unsigned int v38; // r2
  _BYTE *v39; // r5
  int v40; // t1
  unsigned int v41; // r4
  int v42; // r2
  unsigned int v43; // r4
  unsigned int v44; // r4
  unsigned int v45; // [sp+0h] [bp-30h]
  unsigned int v46; // [sp+4h] [bp-2Ch]
  _BYTE *v47; // [sp+8h] [bp-28h]
  unsigned int v48; // [sp+Ch] [bp-24h]

  v7 = a3;
  v48 = (unsigned int)a1;
  if ( !a7 )
    return sub_510E6C();
  v9 = (unsigned int)a3 + a4;
  v10 = (unsigned int)&a1[a2];
  v45 = (unsigned int)a3 + a4;
  v46 = (unsigned int)&a1[a2];
  v11 = (a7 + 3) & 0xFFFFFFFC;
  v12 = a1;
LABEL_4:
  if ( (int)(v9 - (_DWORD)v7) < 260 )
  {
    if ( v12 == (_BYTE *)v10 )
    {
LABEL_46:
      result = 0;
      *a6 = &v12[-v48];
      return result;
    }
  }
  else if ( !XpressBuildHuffmanDecodingTable(v11, v7) )
  {
    v13 = (unsigned __int16 *)(v7 + 64);
    v14 = *v13;
    v7 = (unsigned int *)(v13 + 2);
    v15 = 16;
    v16 = *((unsigned __int16 *)v7 - 1) + (v14 << 16);
    v17 = v12 + 0x10000;
    v47 = v12 + 0x10000;
    if ( (unsigned int)(v12 + 0x10000) > v10 )
    {
      v17 = (_BYTE *)v10;
      v47 = (_BYTE *)v10;
    }
    v18 = (unsigned int)(v17 - 188);
    if ( v12 >= v17 - 188 )
    {
      while ( 1 )
      {
        if ( v12 >= v17 )
          goto LABEL_4;
        v35 = *(__int16 *)(v11 + 2 * (v16 >> 22) + 1056);
        if ( v35 <= 0 )
        {
          v16 <<= 10;
          v15 -= 10;
          do
          {
            v35 = *(__int16 *)(v11 + 2 * (__int16)((v16 >> 31) - v35) + 3104);
            v16 *= 2;
            --v15;
          }
          while ( v35 <= 0 );
        }
        else
        {
          v16 <<= v35 & 0xF;
          v15 -= v35 & 0xF;
        }
        v21 = (__int16)((v35 >> 4) - 256);
        if ( v15 < 0 )
        {
LABEL_47:
          if ( (unsigned int)v7 + 1 < v9 )
          {
            v34 = *(unsigned __int16 *)v7;
            v7 = (unsigned int *)((char *)v7 + 2);
            v16 += v34 << -(char)v15;
            v15 += 16;
            goto LABEL_55;
          }
          return -1073741246;
        }
LABEL_55:
        if ( v21 >= 0 )
          break;
        *v12++ = v21;
LABEL_50:
        v17 = v47;
      }
      if ( !v21 && (unsigned int)v7 >= v9 && v12 == (_BYTE *)v10 )
        goto LABEL_46;
      v36 = v21 / 16;
      v37 = v21 % 16;
      if ( v37 != 15 )
        goto LABEL_59;
      if ( (unsigned int)v7 < v9 )
      {
        v41 = *(unsigned __int8 *)v7;
        v7 = (unsigned int *)((char *)v7 + 1);
        if ( v41 == 255 )
        {
          if ( (unsigned int)v7 + 1 >= v9 )
            return -1073741246;
          v44 = *(unsigned __int16 *)v7;
          v7 = (unsigned int *)((char *)v7 + 2);
          if ( !v44 )
          {
            if ( (unsigned int)v7 + 3 >= v9 )
              return -1073741246;
            v44 = *v7++;
          }
          if ( v44 >= 0xF && &v12[v44 + 3] >= v12 )
          {
            v41 = v44 - 15;
            goto LABEL_72;
          }
        }
        else
        {
LABEL_72:
          v37 = v41 + 15;
LABEL_59:
          v38 = v16 >> (31 - v36);
          v15 -= v36;
          v26 = v37 + 3;
          v16 <<= v36;
          v27 = (1 << v36) + (v38 >> 1);
          if ( v15 < 0 )
          {
LABEL_65:
            if ( (unsigned int)v7 + 1 < v45 )
            {
              v40 = *(unsigned __int16 *)v7;
              v7 = (unsigned int *)((char *)v7 + 2);
              v16 += v40 << -(char)v15;
              v15 += 16;
              goto LABEL_60;
            }
          }
          else
          {
LABEL_60:
            if ( (unsigned int)&v12[-v27] >= v48 )
            {
              v39 = &v12[v26];
              if ( (unsigned int)&v12[v26] <= v46 )
              {
                for ( ; v26; ++v12 )
                {
                  --v26;
                  *v12 = v12[-v27];
                }
LABEL_49:
                v9 = v45;
                v12 = v39;
                v10 = v46;
                goto LABEL_50;
              }
            }
          }
        }
      }
    }
    else
    {
      while ( 1 )
      {
        do
        {
          while ( 1 )
          {
            v19 = *(__int16 *)(v11 + 2 * (v16 >> 22) + 1056);
            v20 = *(_WORD *)(v11 + 2 * (v16 >> 22) + 1056);
            if ( v19 <= 0 )
            {
              v16 <<= 10;
              v15 -= 10;
              do
              {
                v19 = *(__int16 *)(v11 + 2 * (__int16)((v16 >> 31) - v20) + 3104);
                v16 *= 2;
                --v15;
                v20 = v19;
              }
              while ( v19 <= 0 );
            }
            else
            {
              v16 <<= v19 & 0xF;
              v15 -= v19 & 0xF;
            }
            v21 = (__int16)((v19 >> 4) - 256);
            if ( v15 < 0 )
            {
              if ( (unsigned int)v12 >= v18 )
                goto LABEL_47;
              if ( (unsigned int)v7 + 1 >= v9 )
                return -1073741246;
              __pld(v7 + 3);
              v22 = *(unsigned __int16 *)v7;
              v7 = (unsigned int *)((char *)v7 + 2);
              v16 += v22 << -(char)v15;
              v15 += 16;
            }
            if ( v21 >= 0 )
              break;
            *v12++ = v21;
          }
          if ( !v21 && (unsigned int)v7 >= v9 && v12 == (_BYTE *)v10 )
            goto LABEL_46;
          v23 = v21 / 16;
          v24 = v21 % 16;
          if ( v24 == 15 )
          {
            if ( (unsigned int)v7 >= v9 )
              return -1073741246;
            v33 = *(unsigned __int8 *)v7;
            v7 = (unsigned int *)((char *)v7 + 1);
            if ( v33 == 255 )
            {
              if ( (unsigned int)v7 + 1 >= v9 )
                return -1073741246;
              v43 = *(unsigned __int16 *)v7;
              v7 = (unsigned int *)((char *)v7 + 2);
              if ( !v43 )
              {
                if ( (unsigned int)v7 + 3 >= v9 )
                  return -1073741246;
                v43 = *v7++;
              }
              if ( v43 < 0xF || &v12[v43 + 3] < v12 )
                return -1073741246;
              v33 = v43 - 15;
            }
            v24 = v33 + 15;
          }
          v25 = v16 >> (31 - v23);
          v15 -= v23;
          v26 = v24 + 3;
          v16 <<= v23;
          v27 = (1 << v23) + (v25 >> 1);
          if ( v15 < 0 )
          {
            if ( (unsigned int)v12 >= v18 )
              goto LABEL_65;
            if ( (unsigned int)v7 + 1 >= v45 )
              return -1073741246;
            __pld(v7 + 3);
            v31 = *(unsigned __int16 *)v7;
            v7 = (unsigned int *)((char *)v7 + 2);
            v16 += v31 << -(char)v15;
            v15 += 16;
          }
          v28 = &v12[-v27];
          if ( (unsigned int)&v12[-v27] < v48 )
            return -1073741246;
          if ( v27 >= 4 )
            break;
          *v12 = *v28;
          if ( v27 == 1 )
          {
            v26 -= 3;
            v12[1] = *v28;
            v12[2] = *v28;
            v12 += 3;
          }
          else
          {
            v12[1] = v28[1];
            if ( v27 == 2 )
            {
              v26 -= 2;
              v12 += 2;
            }
            else
            {
              v12[2] = v28[2];
              v12 += 3;
              v26 -= 3;
            }
          }
          v9 = v45;
          v10 = v46;
        }
        while ( !v26 );
        v30 = *(_DWORD *)v28;
        v29 = v28 + 8;
        *(_DWORD *)v12 = v30;
        *((_DWORD *)v12 + 1) = *((_DWORD *)v29 - 1);
        if ( v26 >= 9 )
          break;
LABEL_23:
        v9 = v45;
        v10 = v46;
        v12 += v26;
      }
      v12 += 8;
      v26 -= 8;
      while ( (unsigned int)v12 < v18 )
      {
        if ( v26 > 0x20 )
          __pld(v29 + 32);
        v32 = *(_DWORD *)v29;
        v29 += 16;
        *(_DWORD *)v12 = v32;
        *((_DWORD *)v12 + 1) = *((_DWORD *)v29 - 3);
        *((_DWORD *)v12 + 2) = *((_DWORD *)v29 - 2);
        *((_DWORD *)v12 + 3) = *((_DWORD *)v29 - 1);
        if ( v26 < 0x11 )
          goto LABEL_23;
        v12 += 16;
        v26 -= 16;
      }
      v39 = &v12[v26];
      if ( (unsigned int)&v12[v26] <= v46 )
      {
        if ( v26 )
        {
          v42 = v29 - v12;
          do
          {
            --v26;
            *v12 = v12[v42];
            ++v12;
          }
          while ( v26 );
        }
        goto LABEL_49;
      }
    }
  }
  return -1073741246;
}
