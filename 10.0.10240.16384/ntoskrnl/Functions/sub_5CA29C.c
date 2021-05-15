// sub_5CA29C 
 
char **__fastcall sub_5CA29C(char **result)
{
  char *v1; // r4
  unsigned __int8 *v2; // r2
  unsigned __int8 *v3; // lr
  int v4; // r3
  int v5; // t1
  int v6; // r6
  int v7; // t1
  unsigned int v8; // r1
  int v9; // r5
  char *v10; // r5
  unsigned __int8 v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r3
  int v14; // r1
  int v15; // t1
  int v16; // r1
  unsigned int v17; // r3
  char *v18; // r5
  unsigned int v19; // r2
  char v20; // r3
  int v21; // r2
  char v22; // t1
  int v23; // r3
  int v24; // t1
  unsigned int v25; // r5
  int v26; // r3
  unsigned __int8 *v27; // r2
  int v28; // r1
  int v29; // r7
  unsigned __int8 v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r3
  int v33; // r1
  int v34; // t1
  unsigned int v35; // r3
  unsigned int v36; // r2
  char v37; // r3
  char v38; // t1
  char v39; // t1
  int v40; // r2
  unsigned int v41; // r1
  char v42; // r3
  char v43; // t1

  v1 = result[1];
  v2 = (unsigned __int8 *)result[6];
  v3 = 0;
LABEL_2:
  if ( v2 >= (unsigned __int8 *)result[7] || v1 >= result[2] )
    goto LABEL_33;
  v5 = *(_DWORD *)v2;
  v2 += 4;
  v4 = v5;
  if ( v5 >= 0 )
  {
    v6 = 2 * v4 + 1;
LABEL_29:
    v22 = *v2++;
    *v1++ = v22;
    goto LABEL_30;
  }
  v6 = 2 * v4 + 1;
  while ( 1 )
  {
    v7 = *(unsigned __int16 *)v2;
    v2 += 2;
    v8 = v7 & 7;
    v9 = ~(v7 >> 3);
    if ( v8 <= 5 )
    {
      v10 = &v1[v9];
      if ( v10 < result[1] )
        goto LABEL_76;
      *v1 = *v10;
      v1[1] = v10[1];
      v1[2] = v10[2];
      v1[3] = v10[3];
      v1[4] = v10[4];
      v1[5] = v10[5];
      v1[6] = v10[6];
      v1[7] = v10[7];
      v1 += v8 + 3;
      goto LABEL_30;
    }
    if ( v8 != 7 )
      goto LABEL_17;
    if ( v3 )
    {
      v13 = *v3;
      v3 = 0;
      v12 = v13 >> 4;
    }
    else
    {
      v11 = *v2;
      v3 = v2++;
      v12 = v11 & 0xF;
    }
    if ( v12 == 15 )
    {
      v14 = *v2++;
      if ( v14 == 255 )
      {
        v15 = *(unsigned __int16 *)v2;
        v2 += 2;
        v8 = v15;
        if ( v15 < 277 )
          goto LABEL_76;
LABEL_17:
        v16 = v8 + 3;
        goto LABEL_18;
      }
      v12 = v14 + 15;
    }
    v16 = v12 + 10;
LABEL_18:
    v17 = (unsigned int)result[2];
    result[11] = (char *)v2;
    v18 = &v1[v9];
    if ( (unsigned int)&v1[v16] >= v17 )
      break;
    if ( v18 < result[1] )
      goto LABEL_76;
    if ( v16 > 8 )
    {
      v19 = ((unsigned int)(v16 - 9) >> 3) + 1;
      v16 -= 8 * v19;
      do
      {
        *v1 = *v18;
        v1[1] = v18[1];
        v1[2] = v18[2];
        v1[3] = v18[3];
        v1[4] = v18[4];
        v1[5] = v18[5];
        v1[6] = v18[6];
        v20 = v18[7];
        v18 += 8;
        v1[7] = v20;
        v1 += 8;
        --v19;
      }
      while ( v19 );
    }
    v21 = v18 - v1;
    do
    {
      --v16;
      *v1 = v1[v21];
      ++v1;
    }
    while ( v16 );
    v2 = (unsigned __int8 *)result[11];
LABEL_30:
    if ( v6 >= 0 )
    {
      v6 *= 2;
      goto LABEL_29;
    }
    v6 *= 2;
    if ( !v6 )
      goto LABEL_2;
  }
  while ( 2 )
  {
    v35 = (unsigned int)result[1];
    if ( &v1[v16] > result[3] )
    {
      if ( (unsigned int)v18 < v35 )
        goto LABEL_76;
      v40 = result[3] - v1;
      if ( v40 > 8 )
      {
        v41 = ((unsigned int)(v40 - 9) >> 3) + 1;
        v40 -= 8 * v41;
        do
        {
          *v1 = *v18;
          v1[1] = v18[1];
          v1[2] = v18[2];
          v1[3] = v18[3];
          v1[4] = v18[4];
          v1[5] = v18[5];
          v1[6] = v18[6];
          v42 = v18[7];
          v18 += 8;
          v1[7] = v42;
          v1 += 8;
          --v41;
        }
        while ( v41 );
      }
      do
      {
        v43 = *v18++;
        --v40;
        *v1++ = v43;
      }
      while ( v40 );
      v2 = (unsigned __int8 *)result[11];
      goto LABEL_75;
    }
    if ( (unsigned int)v18 < v35 )
      goto LABEL_76;
    if ( v16 > 8 )
    {
      v36 = ((unsigned int)(v16 - 9) >> 3) + 1;
      v16 -= 8 * v36;
      do
      {
        *v1 = *v18;
        v1[1] = v18[1];
        v1[2] = v18[2];
        v1[3] = v18[3];
        v1[4] = v18[4];
        v1[5] = v18[5];
        v1[6] = v18[6];
        v37 = v18[7];
        v18 += 8;
        v1[7] = v37;
        v1 += 8;
        --v36;
      }
      while ( v36 );
    }
    do
    {
      v38 = *v18++;
      --v16;
      *v1++ = v38;
    }
    while ( v16 );
    v2 = (unsigned __int8 *)result[11];
    while ( 2 )
    {
      if ( v6 >= 0 )
      {
        v6 *= 2;
        goto LABEL_61;
      }
      v6 *= 2;
      if ( v6 )
        goto LABEL_37;
LABEL_33:
      if ( v2 >= (unsigned __int8 *)result[9] )
        goto LABEL_76;
      v24 = *(_DWORD *)v2;
      v2 += 4;
      v23 = v24;
      if ( v24 >= 0 )
      {
        v6 = 2 * v23 + 1;
LABEL_61:
        if ( v1 >= result[3] )
          goto LABEL_75;
        if ( v2 >= (unsigned __int8 *)result[5] )
          goto LABEL_76;
        v39 = *v2++;
        *v1++ = v39;
        continue;
      }
      break;
    }
    v6 = 2 * v23 + 1;
LABEL_37:
    if ( v1 >= result[3] )
    {
      if ( v1 == *result )
        result[13] = (char *)1;
LABEL_75:
      result[11] = (char *)v2;
      result[12] = (char *)1;
      result[4] = v1;
      return result;
    }
    v25 = (unsigned int)result[8];
    if ( (unsigned int)v2 >= v25 )
      goto LABEL_76;
    v26 = *(unsigned __int16 *)v2;
    v27 = v2 + 2;
    v28 = v26 & 7;
    v29 = ~(v26 >> 3);
    if ( v28 != 7 )
      goto LABEL_49;
    if ( v3 )
    {
      v32 = *v3;
      v3 = 0;
      v31 = v32 >> 4;
LABEL_44:
      if ( v31 == 15 )
      {
        if ( v27 >= (unsigned __int8 *)result[5] )
          goto LABEL_76;
        v33 = *v27++;
        if ( v33 == 255 )
        {
          if ( (unsigned int)v27 >= v25 )
            goto LABEL_76;
          v34 = *(unsigned __int16 *)v27;
          v27 += 2;
          v28 = v34;
          if ( v34 < 277 )
            goto LABEL_76;
LABEL_49:
          v16 = v28 + 3;
          goto LABEL_50;
        }
        v31 = v33 + 15;
      }
      v16 = v31 + 10;
LABEL_50:
      result[11] = (char *)v27;
      v18 = &v1[v29];
      continue;
    }
    break;
  }
  if ( v27 < (unsigned __int8 *)result[5] )
  {
    v30 = *v27;
    v3 = v27++;
    v31 = v30 & 0xF;
    goto LABEL_44;
  }
LABEL_76:
  result[12] = 0;
  return result;
}
