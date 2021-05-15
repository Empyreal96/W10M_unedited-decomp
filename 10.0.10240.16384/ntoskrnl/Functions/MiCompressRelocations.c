// MiCompressRelocations 
 
_DWORD *__fastcall MiCompressRelocations(_DWORD *a1, int a2)
{
  unsigned int v4; // r3
  int v5; // r0
  int v6; // lr
  int v7; // r9
  int v8; // r8
  int v9; // r3
  unsigned __int16 *v10; // r1
  unsigned int v11; // r0
  int v12; // r6
  unsigned int v13; // r7
  unsigned int v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // t1
  unsigned int v17; // r4
  __int16 v18; // r4
  __int16 v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r3
  __int16 v23; // r8
  unsigned int v24; // r7
  _DWORD *v25; // r0
  int v26; // r6
  unsigned int v27; // r10
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  char *v34; // r9
  _DWORD *v35; // r5
  char *v36; // r0
  int v37; // r3
  int v38; // r3
  unsigned int v39; // r8
  int v40; // lr
  int v41; // r2
  int v42; // r1
  unsigned int v43; // r3
  int v44; // r3
  unsigned __int16 *v45; // r5
  __int16 v46; // r0
  int v47; // r6
  unsigned int v48; // r7
  unsigned int v49; // r4
  int v50; // r10
  unsigned int v51; // r2
  unsigned int v52; // t1
  __int16 v53; // r1
  unsigned int v54; // r2
  _DWORD *v55; // [sp+0h] [bp-40h]
  int v56; // [sp+4h] [bp-3Ch] BYREF
  int v57; // [sp+8h] [bp-38h]
  unsigned int v58; // [sp+Ch] [bp-34h]
  unsigned int v59; // [sp+10h] [bp-30h]
  char *v60; // [sp+14h] [bp-2Ch]
  unsigned int v61; // [sp+18h] [bp-28h]
  _DWORD *v62; // [sp+1Ch] [bp-24h]

  v4 = 0;
  v5 = 0;
  v55 = a1;
  v6 = 0;
  v58 = 0;
  do
    *((_BYTE *)&v56 + v4++) = 0;
  while ( v4 < 2 );
  v7 = a1[4];
  v8 = (unsigned __int8)v56;
  v57 = BYTE1(v56);
  while ( 2 )
  {
    v9 = *(_DWORD *)(v7 + 4);
    v10 = (unsigned __int16 *)(v7 + 8);
    v60 = (char *)(v5 + v9);
    a2 -= v9;
    v7 += v9;
    v11 = 0;
    v12 = 4;
    v13 = 0;
    v14 = (unsigned int)(v9 - 8) >> 1;
    if ( !v14 )
      goto LABEL_15;
    do
    {
      v16 = *v10++;
      v15 = v16;
      if ( (v16 & 0xFFFFF000) == 0 )
        goto LABEL_13;
      v17 = v15 >> 12;
      if ( v8 == v15 >> 12 )
      {
        v18 = 0;
      }
      else if ( v57 == v17 )
      {
        v18 = 1;
      }
      else
      {
        v23 = v58;
        if ( v58 >= 2 )
          return v55;
        *((_BYTE *)&v56 + v58) = v17;
        v58 = (unsigned __int8)(v23 + 1);
        v18 = v23;
        v8 = (unsigned __int8)v56;
        v57 = BYTE1(v56);
      }
      v19 = v15 & 0xFFF;
      if ( (v19 & 1) != 0 )
        return v55;
      v20 = (unsigned __int16)(v18 + v19);
      if ( v20 <= v11 )
      {
        if ( v11 )
          return v55;
      }
      v21 = (unsigned __int16)(v20 - v11);
      if ( v21 == v12 )
      {
        if ( ++v13 == 255 )
        {
          v13 = 0;
LABEL_28:
          v6 += 2;
          goto LABEL_12;
        }
      }
      else
      {
        if ( v13 )
        {
          if ( v13 > 4 )
            v6 += 2;
          else
            ++v6;
          v13 = 0;
        }
        v12 = v21;
        if ( v21 >= 0xEB )
          goto LABEL_28;
        ++v6;
      }
LABEL_12:
      v11 = (unsigned __int16)(v21 + v11);
LABEL_13:
      --v14;
    }
    while ( v14 );
    if ( v13 )
    {
      if ( v13 > 4 )
        v6 += 2;
      else
        ++v6;
    }
LABEL_15:
    v6 += 2;
    if ( (v6 & 1) != 0 )
      ++v6;
    if ( a2 )
    {
      v5 = (int)v60;
      continue;
    }
    break;
  }
  v24 = (unsigned int)v55;
  if ( v58 )
  {
    v25 = (_DWORD *)ExAllocatePoolWithTag(1, v6 + 4 * (v55[6] + 10), 1699900749);
    v26 = (int)v25;
    v62 = v25;
    if ( v25 )
    {
      v27 = (unsigned int)(v55[4] - *v55) >> 2;
      v28 = v55[1];
      v29 = v55[2];
      v30 = v55[3];
      *v25 = *v55;
      v25[1] = v28;
      v25[2] = v29;
      v25[3] = v30;
      v31 = v55[5];
      v32 = v55[6];
      v33 = v55[7];
      v34 = (char *)(v25 + 10);
      v25[4] = v55[4];
      v25[5] = v31;
      v25[6] = v32;
      v25[7] = v33;
      v35 = v25 + 8;
      v36 = (char *)(v55 + 10);
      v37 = v55[9];
      *v35 = v55[8];
      v35[1] = v37;
      LOBYTE(v37) = v57;
      *(_DWORD *)v26 = v26 + 40;
      v60 = (char *)(v26 + 40);
      v61 = v27;
      *(_BYTE *)(v26 + 32) = v8 | (16 * v37);
      v38 = v55[6];
      v39 = 0;
      v59 = 0;
      v40 = v26 + 40 + 4 * v38;
      *(_DWORD *)(v26 + 16) = v40;
      v41 = v55[4];
      if ( v27 )
      {
        v42 = v36 - v34;
        v56 = v36 - v34;
        do
        {
          if ( v39 < *(_DWORD *)(v24 + 24) )
          {
            v43 = *(_DWORD *)&v34[v42];
            if ( v43 <= 1 )
            {
              *(_DWORD *)v34 = v43;
            }
            else
            {
              *(_DWORD *)v34 = v40;
              if ( (*(_DWORD *)&v34[v42] & 1) != 0 )
                *(_DWORD *)v34 = v40 | 1;
              v44 = *(_DWORD *)(v41 + 4);
              v45 = (unsigned __int16 *)(v41 + 8);
              v46 = 0;
              v41 += v44;
              v47 = 4;
              v48 = 0;
              v49 = (unsigned int)(v44 - 8) >> 1;
              v58 = v41;
              if ( v49 )
              {
                v50 = v57;
                do
                {
                  v52 = *v45++;
                  v51 = v52;
                  if ( (v52 & 0xFFFFF000) != 0 )
                  {
                    v53 = v51 & 0xFFF;
                    if ( v50 == v51 >> 12 )
                      ++v53;
                    v54 = (unsigned __int16)(v53 - v46);
                    if ( v54 == v47 )
                    {
                      if ( ++v48 == 255 )
                      {
                        *(_BYTE *)v40 = -17;
                        *(_BYTE *)(v40 + 1) = -1;
                        v40 += 2;
                        v48 = 0;
                      }
                    }
                    else
                    {
                      if ( v48 )
                      {
                        if ( v48 > 4 )
                        {
                          *(_BYTE *)v40 = -17;
                          *(_BYTE *)(v40 + 1) = v48;
                          v40 += 2;
                        }
                        else
                        {
                          *(_BYTE *)v40++ = -17 - v48;
                        }
                        v48 = 0;
                      }
                      v47 = (unsigned __int16)(v53 - v46);
                      if ( v54 >= 0xEB )
                      {
                        *(_BYTE *)v40 = (v53 - v46) | 0xF0;
                        v40 += 2;
                        *(_BYTE *)(v40 - 1) = v54 >> 4;
                      }
                      else
                      {
                        *(_BYTE *)v40++ = v53 - v46;
                      }
                    }
                    v46 = v53;
                  }
                  --v49;
                }
                while ( v49 );
                v39 = v59;
                v34 = v60;
                v27 = v61;
                v41 = v58;
                v42 = v56;
                if ( v48 )
                {
                  if ( v48 > 4 )
                  {
                    *(_BYTE *)v40 = -17;
                    *(_BYTE *)(v40 + 1) = v48;
                    v40 += 2;
                  }
                  else
                  {
                    *(_BYTE *)v40++ = -17 - v48;
                  }
                }
              }
              *(_BYTE *)v40 = -16;
              v40 += 2;
              v24 = (unsigned int)v55;
              *(_BYTE *)(v40 - 1) = 0;
              if ( (v40 & 1) != 0 )
                ++v40;
            }
          }
          ++v39;
          v34 += 4;
          v59 = v39;
          v60 = v34;
        }
        while ( v39 < v27 );
        v26 = (int)v62;
      }
      ExFreePoolWithTag(v24);
      v24 = v26;
    }
  }
  return (_DWORD *)v24;
}
