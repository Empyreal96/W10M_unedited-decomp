// RtlDecompressBufferXpressHuffProgress 
 
int __fastcall RtlDecompressBufferXpressHuffProgress(_BYTE *a1, unsigned int a2, _BYTE *a3, int a4, _DWORD *a5, int a6, int a7, int a8)
{
  _BYTE *v8; // r6
  int v9; // lr
  int result; // r0
  unsigned int v11; // r7
  _BYTE *v12; // r5
  _BYTE *v13; // r0
  _WORD *v14; // r4
  unsigned __int16 *v15; // r6
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r9
  _BYTE *v19; // r3
  int v20; // r8
  unsigned int v21; // r10
  unsigned int v22; // lr
  int v23; // r2
  __int16 v24; // r3
  int v25; // r4
  int v26; // r2
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r4
  unsigned int v30; // r4
  unsigned int v31; // r4
  unsigned int v32; // r1
  int v33; // r2
  _BYTE *v34; // r7
  char *v35; // r7
  _BYTE *v36; // r2
  int v37; // r1
  int v38; // r2
  int v39; // t1
  int v40; // r3
  int v41; // r0
  int v42; // r4
  unsigned int v43; // r4
  unsigned int v44; // r4
  int v45; // t1
  int v46; // r3
  int v47; // r1
  unsigned int v48; // [sp+4h] [bp-3Ch]
  unsigned int v49; // [sp+8h] [bp-38h]
  _BYTE *v50; // [sp+Ch] [bp-34h]
  unsigned int v51; // [sp+10h] [bp-30h]
  int v52; // [sp+14h] [bp-2Ch]
  int v53[10]; // [sp+18h] [bp-28h] BYREF

  v8 = a3;
  v9 = 4096;
  v51 = (unsigned int)a1;
  v52 = 4096;
  if ( !a6 )
    return -1073741592;
  v11 = (unsigned int)&a3[a4];
  v49 = (unsigned int)&a3[a4];
  v12 = a1;
  v13 = &a1[a2];
  v48 = (unsigned int)v13;
  if ( !a7 || a2 < 0x1000 )
  {
    v9 = a2;
    v52 = a2;
  }
  v53[0] = a7;
  v53[1] = a8;
  v53[2] = v9;
LABEL_7:
  if ( (int)(v11 - (_DWORD)v8) < 260 )
  {
    if ( v12 != v13 )
      return -1073741246;
  }
  else
  {
    v14 = (_WORD *)((a6 + 3) & 0xFFFFFFFC);
    if ( XpressBuildHuffmanDecodingTable(v14, v8) )
      return -1073741246;
    v15 = (unsigned __int16 *)(v8 + 256);
    v16 = *v15;
    v17 = v15[1];
    v13 = (_BYTE *)v48;
    v8 = v15 + 2;
    v18 = v17 + (v16 << 16);
    v19 = v12 + 0x10000;
    v50 = v12 + 0x10000;
    v20 = 16;
    if ( (unsigned int)(v12 + 0x10000) > v48 )
    {
      v19 = (_BYTE *)v48;
      v50 = (_BYTE *)v48;
    }
    v21 = (unsigned int)(v19 - 188);
    if ( v12 < v19 - 188 )
    {
      v22 = (unsigned int)&v12[v52];
      if ( v21 < (unsigned int)&v12[v52] )
        v22 = (unsigned int)(v19 - 188);
      while ( 1 )
      {
        v23 = (__int16)v14[(v18 >> 22) + 528];
        v24 = v14[(v18 >> 22) + 528];
        if ( v23 > 0 )
        {
          v18 <<= v23 & 0xF;
          v20 -= v23 & 0xF;
        }
        else
        {
          v18 <<= 10;
          v20 -= 10;
          do
          {
            v23 = (__int16)v14[(__int16)((v18 >> 31) - v24) + 1552];
            v18 *= 2;
            --v20;
            v24 = v23;
          }
          while ( v23 <= 0 );
        }
        v25 = (__int16)((v23 >> 4) - 256);
        if ( v20 < 0 )
        {
          if ( (unsigned int)v12 >= v22 )
          {
            if ( (unsigned int)v12 >= v21 )
            {
              v13 = (_BYTE *)v48;
LABEL_81:
              if ( (unsigned int)(v8 + 1) >= v11 )
                return -1073741246;
              v39 = *(unsigned __int16 *)v8;
              v8 += 2;
              v40 = -v20;
              v20 += 16;
              v18 += v39 << v40;
              goto LABEL_83;
            }
            v22 = RtlpMakeXpressCallback(v53, v21, v12);
          }
          if ( (unsigned int)(v8 + 1) >= v11 )
            return -1073741246;
          __pld(v8 + 12);
          v26 = *(unsigned __int16 *)v8;
          v8 += 2;
          v18 += v26 << -(char)v20;
          v20 += 16;
        }
        if ( v25 >= 0 )
        {
          if ( !v25 && (unsigned int)v8 >= v11 && v12 == (_BYTE *)v48 )
            goto LABEL_110;
          v27 = v25 / 16;
          v28 = v25 % 16;
          if ( v28 == 15 )
          {
            if ( (unsigned int)v8 >= v11 )
              return -1073741246;
            v29 = (unsigned __int8)*v8++;
            if ( v29 == 255 )
            {
              if ( (unsigned int)(v8 + 1) >= v11 )
                return -1073741246;
              v30 = *(unsigned __int16 *)v8;
              v8 += 2;
              if ( !v30 )
              {
                if ( (unsigned int)(v8 + 3) >= v11 )
                  return -1073741246;
                v30 = *(_DWORD *)v8;
                v8 += 4;
              }
              if ( v30 < 0xF || &v12[v30 + 3] < v12 )
                return -1073741246;
              v29 = v30 - 15;
            }
            v28 = v29 + 15;
          }
          v20 -= v27;
          v31 = v28 + 3;
          v32 = (1 << v27) + (v18 >> (31 - v27) >> 1);
          v18 <<= v27;
          if ( v20 < 0 )
          {
            if ( (unsigned int)v12 >= v21 )
              goto LABEL_100;
            if ( (unsigned int)(v8 + 1) >= v11 )
              return -1073741246;
            __pld(v8 + 12);
            v33 = *(unsigned __int16 *)v8;
            v8 += 2;
            v18 += v33 << -(char)v20;
            v20 += 16;
          }
          v34 = &v12[-v32];
          if ( (unsigned int)&v12[-v32] < v51 )
            return -1073741246;
          if ( v32 >= 4 )
            goto LABEL_55;
          *v12 = *v34;
          if ( v32 == 1 )
          {
            v31 -= 3;
            v12[1] = *v34;
            v12[2] = *v34;
            v12 += 3;
          }
          else
          {
            v12[1] = v34[1];
            if ( v32 == 2 )
            {
              v31 -= 2;
              v12 += 2;
            }
            else
            {
              v12[2] = v34[2];
              v12 += 3;
              v31 -= 3;
            }
          }
          if ( v31 )
          {
LABEL_55:
            *(_DWORD *)v12 = *(_DWORD *)v34;
            *((_DWORD *)v12 + 1) = *((_DWORD *)v34 + 1);
            if ( v31 >= 9 )
            {
              v12 += 8;
              v35 = v34 + 8;
              for ( v31 -= 8; ; v31 -= 16 )
              {
                if ( (unsigned int)v12 >= v22 )
                {
                  if ( (unsigned int)v12 >= v21 )
                  {
                    v13 = (_BYTE *)v48;
                    v36 = &v12[v31];
                    if ( (unsigned int)&v12[v31] <= v48 )
                    {
                      if ( v31 )
                      {
                        v37 = v35 - v12;
                        do
                        {
                          --v31;
                          *v12 = v12[v37];
                          ++v12;
                        }
                        while ( v31 );
                      }
                      v11 = v49;
                      goto LABEL_70;
                    }
                    return -1073741246;
                  }
                  v22 = RtlpMakeXpressCallback(v53, v21, v12);
                }
                if ( v31 > 0x20 )
                  __pld(v35 + 32);
                *(_DWORD *)v12 = *(_DWORD *)v35;
                *((_DWORD *)v12 + 1) = *((_DWORD *)v35 + 1);
                *((_DWORD *)v12 + 2) = *((_DWORD *)v35 + 2);
                *((_DWORD *)v12 + 3) = *((_DWORD *)v35 + 3);
                if ( v31 < 0x11 )
                  break;
                v12 += 16;
                v35 += 16;
              }
            }
            v12 += v31;
          }
          v11 = v49;
        }
        else
        {
          *v12++ = v25;
        }
        v14 = (_WORD *)((a6 + 3) & 0xFFFFFFFC);
      }
    }
    while ( 1 )
    {
      if ( v12 >= v19 )
        goto LABEL_7;
      v38 = (__int16)v14[(v18 >> 22) + 528];
      if ( v38 > 0 )
      {
        v18 <<= v38 & 0xF;
        v20 -= v38 & 0xF;
      }
      else
      {
        v18 <<= 10;
        v20 -= 10;
        do
        {
          v38 = (__int16)v14[(__int16)((v18 >> 31) - v38) + 1552];
          v18 *= 2;
          --v20;
        }
        while ( v38 <= 0 );
      }
      v25 = (__int16)((v38 >> 4) - 256);
      if ( v20 < 0 )
        goto LABEL_81;
LABEL_83:
      if ( v25 >= 0 )
        break;
      *v12++ = v25;
LABEL_71:
      v19 = v50;
      v14 = (_WORD *)((a6 + 3) & 0xFFFFFFFC);
    }
    if ( v25 || (unsigned int)v8 < v11 || v12 != v13 )
    {
      v41 = v25 / 16;
      v42 = v25 % 16;
      if ( v42 == 15 )
      {
        if ( (unsigned int)v8 >= v11 )
          return -1073741246;
        v43 = (unsigned __int8)*v8++;
        if ( v43 == 255 )
        {
          if ( (unsigned int)(v8 + 1) >= v11 )
            return -1073741246;
          v44 = *(unsigned __int16 *)v8;
          v8 += 2;
          if ( !v44 )
          {
            if ( (unsigned int)(v8 + 3) >= v11 )
              return -1073741246;
            v44 = *(_DWORD *)v8;
            v8 += 4;
          }
          if ( v44 < 0xF || &v12[v44 + 3] < v12 )
            return -1073741246;
          v43 = v44 - 15;
        }
        v42 = v43 + 15;
      }
      v20 -= v41;
      v31 = v42 + 3;
      v32 = (1 << v41) + (v18 >> (31 - v41) >> 1);
      v18 <<= v41;
      if ( v20 < 0 )
      {
LABEL_100:
        if ( (unsigned int)(v8 + 1) >= v11 )
          return -1073741246;
        v45 = *(unsigned __int16 *)v8;
        v8 += 2;
        v46 = -v20;
        v20 += 16;
        v18 += v45 << v46;
      }
      if ( (unsigned int)&v12[-v32] >= v51 )
      {
        v13 = (_BYTE *)v48;
        v36 = &v12[v31];
        if ( (unsigned int)&v12[v31] <= v48 )
        {
          if ( v31 )
          {
            v47 = -v32;
            do
            {
              --v31;
              *v12 = v12[v47];
              ++v12;
            }
            while ( v31 );
          }
LABEL_70:
          v12 = v36;
          goto LABEL_71;
        }
      }
      return -1073741246;
    }
  }
LABEL_110:
  result = 0;
  *a5 = &v12[-v51];
  return result;
}
