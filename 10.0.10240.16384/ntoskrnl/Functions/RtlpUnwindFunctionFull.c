// RtlpUnwindFunctionFull 
 
int __fastcall RtlpUnwindFunctionFull(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, int *a7, int a8)
{
  int v8; // r4
  unsigned int v9; // r5
  unsigned int *v10; // r8
  int result; // r0
  unsigned int v12; // r7
  unsigned int v13; // r10
  unsigned int v14; // r6
  unsigned int v15; // r9
  int v16; // r3
  char *v17; // r4
  unsigned __int8 *v18; // r1
  unsigned int v19; // r3
  _DWORD *v20; // r7
  int v21; // r8
  int v22; // lr
  int v23; // r2
  unsigned __int8 *v24; // r5
  unsigned __int8 *v25; // r6
  int v26; // r9
  unsigned int v27; // r1
  unsigned int v28; // t1
  int v29; // r2
  int v30; // r3
  char v31; // r3
  int v32; // r2
  int v33; // r3
  int v34; // r5
  unsigned int v35; // r3
  unsigned int v36; // t1
  int v37; // r2
  unsigned int v38; // r0
  unsigned int v39; // r3
  int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r3
  char v43; // r3
  unsigned int v44; // r3
  unsigned int v45; // r3
  unsigned int v46; // r3
  int v47; // r0
  unsigned int v48; // r3
  char v49; // r8
  unsigned int v50; // r1
  int v51; // r2
  int v52; // r3
  int v53; // r2
  int v54; // r2
  int v55; // r3
  int v56; // [sp+0h] [bp-38h]
  int v57; // [sp+4h] [bp-34h]
  unsigned int v59; // [sp+8h] [bp-30h]
  unsigned int v60; // [sp+Ch] [bp-2Ch]
  int v61; // [sp+10h] [bp-28h]
  unsigned int v62; // [sp+14h] [bp-24h]
  unsigned int v63; // [sp+14h] [bp-24h]

  *a4 |= 0x20000000u;
  v8 = a3[1];
  v10 = (unsigned int *)(v8 + a2 + 4);
  v9 = *(_DWORD *)(v8 + a2);
  if ( (v9 & 0xC0000) != 0 )
    return sub_547ED4();
  v12 = v9 & 0x3FFFF;
  v13 = (a1 - (*a3 & 0xFFFFFFFE)) >> 1;
  if ( v13 >= (v9 & 0x3FFFF) )
    return sub_547ED4();
  v14 = (v9 >> 23) & 0x1F;
  v15 = v9 >> 28;
  if ( !v14 && !v15 )
  {
    v48 = *v10;
    v10 = (unsigned int *)(v8 + a2 + 8);
    v15 = BYTE2(v48);
    v14 = (unsigned __int16)v48;
  }
  v16 = v9 & 0x200000;
  if ( (v9 & 0x200000) != 0 )
  {
    v62 = v14;
    v14 = 0;
  }
  else
  {
    v62 = 0;
  }
  v56 = 0;
  v57 = 0;
  if ( (v9 & 0x100000) != 0 )
  {
    v57 = v10[v14 + v15] + a2;
    v56 = (int)&v10[v14 + 1 + v15];
    v16 = v9 & 0x200000;
  }
  v17 = (char *)&v10[v14];
  v18 = (unsigned __int8 *)&v17[4 * v15];
  v60 = (unsigned int)v18;
  if ( v13 < 8 * v15 && (v9 & 0x400000) == 0 )
  {
    v41 = RtlpComputeScopeSize(&v10[v14], v18, 0, v16);
    if ( v13 < v41 )
    {
      v21 = 0;
      v20 = a4;
      v56 = 0;
      v57 = 0;
      v22 = 0;
      v23 = v41 - v13;
      goto LABEL_14;
    }
    v16 = v9 & 0x200000;
  }
  if ( !v16 )
  {
    v20 = a4;
    v34 = 0;
    if ( v14 )
    {
      while ( 1 )
      {
        v36 = *v10++;
        v35 = v36;
        v37 = v36 & 0x3FFFF;
        v61 = v36 & 0x3FFFF;
        v63 = v36;
        if ( v13 < (v36 & 0x3FFFF) )
          break;
        v38 = HIBYTE(v35);
        v39 = v37 + 2 * (4 * v15 - HIBYTE(v35));
        v59 = v38;
        if ( v13 < v39 )
        {
          v47 = RtlpComputeScopeSize(&v17[v38], v18, 1, v39);
          if ( ((*((unsigned __int16 *)dword_4150E0 + ((v63 >> 20) & 0xF)) >> (v20[17] >> 28)) & 1) != 0
            && v13 < v47 + v61 )
          {
            v21 = 0;
            v23 = v13 - v61;
            v17 += v59;
            v56 = 0;
            v57 = 0;
            v22 = 0;
            goto LABEL_14;
          }
          v18 = (unsigned __int8 *)&v17[4 * v15];
        }
        if ( ++v34 >= v14 )
          goto LABEL_13;
      }
    }
    goto LABEL_13;
  }
  v19 = v13 + 2 * (4 * v15 - v62);
  if ( v19 < v12 )
  {
    v20 = a4;
LABEL_13:
    v22 = v56;
    v21 = v57;
    v23 = 0;
    goto LABEL_14;
  }
  v42 = v12 - RtlpComputeScopeSize(&v17[v62], v18, 1, v19);
  v20 = a4;
  if ( v13 < v42 )
    goto LABEL_13;
  v21 = 0;
  v56 = 0;
  v57 = 0;
  v22 = 0;
  v17 += v62;
  v23 = v13 - v42;
LABEL_14:
  while ( (unsigned int)v17 < v60 )
  {
    if ( v23 <= 0 )
      break;
    v45 = (unsigned __int8)*v17;
    if ( v45 >= 0xFD )
      break;
    v46 = *((unsigned __int8 *)dword_40A180 + v45);
    v23 -= v46 >> 4;
    v17 += v46 & 0xF;
  }
  result = 0;
  if ( (unsigned int)v17 >= v60 )
  {
LABEL_24:
    v20[16] = v20[15];
LABEL_25:
    *a5 = v20[14];
    if ( a6 )
      *a6 = v21;
    *a7 = v22;
  }
  else
  {
    v24 = (unsigned __int8 *)(v17 + 3);
    v25 = (unsigned __int8 *)(v17 + 2);
    v26 = 1;
    while ( !result )
    {
      v28 = (unsigned __int8)*v17++;
      v27 = v28;
      ++v25;
      ++v24;
      if ( v28 < 0x80 )
      {
        v20[14] += 4 * (v27 & 0x7F);
      }
      else if ( v27 < 0xC0 )
      {
        if ( (unsigned int)v17 >= v60 )
        {
LABEL_77:
          result = -1073741569;
        }
        else
        {
          v40 = (unsigned __int8)*v17++ | ((v27 & 0x1F | (2 * (v27 & 0x20))) << 8);
          ++v25;
          ++v24;
          result = RtlpPopRegisterMask(v20, v40, a8);
        }
      }
      else if ( v27 < 0xD0 )
      {
        v20[14] = v20[(v27 & 0xF) + 1];
      }
      else
      {
        switch ( v27 )
        {
          case 0xD0u:
          case 0xD1u:
          case 0xD2u:
          case 0xD3u:
          case 0xD4u:
          case 0xD5u:
          case 0xD6u:
          case 0xD7u:
            v31 = (v27 & 3) + 5;
            goto LABEL_35;
          case 0xD8u:
          case 0xD9u:
          case 0xDAu:
          case 0xDBu:
          case 0xDCu:
          case 0xDDu:
          case 0xDEu:
          case 0xDFu:
            v31 = (v27 & 3) + 9;
LABEL_35:
            v32 = (unsigned __int16)((1 << v31) - 16);
            if ( (v27 & 4) != 0 )
              v33 = 0x4000;
            else
              v33 = 0;
            result = RtlpPopRegisterMask(v20, v32 | v33, a8);
            break;
          case 0xE0u:
          case 0xE1u:
          case 0xE2u:
          case 0xE3u:
          case 0xE4u:
          case 0xE5u:
          case 0xE6u:
          case 0xE7u:
            result = RtlpPopVfpRegisterRange(v20, 8, (v27 & 7) + 8, a8);
            break;
          case 0xE8u:
          case 0xE9u:
          case 0xEAu:
          case 0xEBu:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            ++v25;
            v29 = v20[14] + ((v27 & 3) << 10);
            v20[14] = v29;
            v30 = (unsigned __int8)*v17++;
            ++v24;
            v20[14] = v29 + 4 * v30;
            break;
          case 0xECu:
          case 0xEDu:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            result = RtlpPopRegisterMask(v20, (unsigned __int8)*v17++ | ((v27 & 1) << 14), a8);
            ++v25;
            ++v24;
            break;
          case 0xEEu:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            v43 = *v17++;
            ++v25;
            ++v24;
            if ( (v43 & 0xF0) != 0 )
              goto LABEL_77;
            result = RtlpUnwindCustom(v20, v43 & 0xF, a8);
            v26 = 0;
            break;
          case 0xEFu:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            v49 = *v17++;
            ++v25;
            ++v24;
            if ( (v49 & 0xF0) != 0 )
              goto LABEL_77;
            result = RtlpPopRegisterMask(v20, 0x4000, a8);
            v20[14] += 4 * ((v49 & 0xF) - 1);
            break;
          case 0xF5u:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            v44 = (unsigned __int8)*v17++;
            ++v25;
            ++v24;
            result = RtlpPopVfpRegisterRange(v20, v44 >> 4, v44 & 0xF, a8);
            break;
          case 0xF6u:
            if ( (unsigned int)v17 >= v60 )
              goto LABEL_77;
            v50 = (unsigned __int8)*v17++;
            ++v25;
            ++v24;
            result = RtlpPopVfpRegisterRange(v20, (v50 >> 4) + 16, (v50 & 0xF) + 16, a8);
            break;
          case 0xF7u:
          case 0xF9u:
            if ( (unsigned int)v25 > v60 )
              goto LABEL_77;
            v25 += 2;
            v51 = v20[14] + ((unsigned __int8)*v17 << 10);
            v20[14] = v51;
            v52 = (unsigned __int8)v17[1];
            v17 += 2;
            v24 += 2;
            v20[14] = v51 + 4 * v52;
            break;
          case 0xF8u:
          case 0xFAu:
            if ( (unsigned int)v24 > v60 )
              goto LABEL_77;
            v25 += 3;
            v53 = v20[14] + ((unsigned __int8)*v17 << 18);
            v20[14] = v53;
            v54 = v53 + ((unsigned __int8)v17[1] << 10);
            v20[14] = v54;
            v55 = (unsigned __int8)v17[2];
            v17 += 3;
            v24 += 3;
            v20[14] = v54 + 4 * v55;
            break;
          case 0xFBu:
          case 0xFCu:
            break;
          case 0xFDu:
          case 0xFEu:
          case 0xFFu:
            goto LABEL_23;
          default:
            goto LABEL_77;
        }
      }
      if ( (unsigned int)v17 >= v60 )
      {
        if ( result )
          return result;
LABEL_23:
        v22 = v56;
        v21 = v57;
        if ( !v26 )
          goto LABEL_25;
        goto LABEL_24;
      }
    }
  }
  return result;
}
