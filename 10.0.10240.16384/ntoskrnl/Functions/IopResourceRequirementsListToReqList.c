// IopResourceRequirementsListToReqList 
 
int __fastcall IopResourceRequirementsListToReqList(_DWORD *a1, unsigned int *a2)
{
  _DWORD *v2; // r8
  int v3; // r4
  int v5; // r0
  char *v6; // r1
  char *v7; // r7
  int v8; // r6
  char *v9; // r2
  char *v10; // lr
  int v11; // r5
  int v12; // r3
  unsigned int v13; // r5
  unsigned int v14; // r10
  int v15; // r0
  unsigned int v16; // r3
  unsigned int v17; // r3
  int v18; // r0
  unsigned int v19; // r5
  int v20; // r8
  unsigned int v21; // r3
  int v22; // r9
  int v23; // r7
  _BYTE *v24; // r0
  unsigned int v25; // r6
  int v26; // r7
  _DWORD *v27; // r2
  int v28; // r10
  int v29; // r9
  unsigned int v30; // lr
  int *v31; // r0
  int **v32; // r4
  unsigned int v33; // r5
  int *v34; // r8
  int v35; // r3
  _DWORD *v36; // r1
  int v37; // r3
  int v38; // r2
  _BYTE *v39; // r0
  int v40; // r3
  int v41; // r3
  bool v42; // r3
  _DWORD *v43; // r1
  int v44; // r3
  int v45; // r1
  int v46; // r1
  int v47; // r7
  int v48; // r4
  int v49; // r5
  int *v50; // [sp+0h] [bp-50h]
  int v51; // [sp+4h] [bp-4Ch] BYREF
  _DWORD *v52; // [sp+8h] [bp-48h]
  int v53; // [sp+Ch] [bp-44h]
  _BYTE *v54; // [sp+10h] [bp-40h]
  int v55; // [sp+14h] [bp-3Ch]
  _DWORD *v56; // [sp+18h] [bp-38h]
  _DWORD *v57; // [sp+1Ch] [bp-34h]
  int v58; // [sp+20h] [bp-30h] BYREF
  _DWORD *v59; // [sp+24h] [bp-2Ch] BYREF
  int v60; // [sp+28h] [bp-28h]
  unsigned int *v61; // [sp+2Ch] [bp-24h]

  *a2 = 0;
  v2 = (_DWORD *)a1[5];
  v61 = a2;
  v3 = v2[7];
  v56 = a1;
  v57 = v2;
  v53 = 0;
  if ( !v3 )
    return sub_80DED0();
  v5 = 0;
  v6 = (char *)(v2 + 8);
  v7 = (char *)v2 + *v2;
  v8 = 0;
  while ( --v3 >= 0 )
  {
    v9 = v6 + 8;
    v6 += 32 * *((_DWORD *)v6 + 1) + 8;
    if ( v9 == v6 )
      return sub_80DED0();
    if ( v9 > v6 || v9 > v7 || v6 > v7 )
      return -1073741811;
    if ( (unsigned __int8)v9[1] == 128 )
      v9 += 32;
    v10 = v9;
LABEL_12:
    v11 = 1;
    while ( v9 < v6 )
    {
      v12 = (unsigned __int8)v9[1];
      if ( v12 == 128 )
        return -1073741811;
      if ( v12 == 129 )
      {
        while ( v9 < v6 && (unsigned __int8)v9[1] == 129 )
        {
          if ( v9 == v10 )
            return -1073741811;
          ++v5;
          v9 += 32;
        }
        goto LABEL_12;
      }
      ++v5;
      if ( (v12 & 0x80) != 0 || !v9[1] )
      {
        if ( v12 == 240 )
          --v5;
        *v9 = 1;
        v9 += 32;
        goto LABEL_12;
      }
      if ( (*v9 & 8) != 0 )
      {
        if ( v11 )
          return -1073741811;
        ++v8;
      }
      else
      {
        v11 = 0;
      }
      v9 += 32;
    }
  }
  v13 = v5 - v8;
  v14 = v2[7];
  v60 = -1073741823;
  v52 = v2 + 8;
  if ( RtlULongLongToULong(180 * (v5 - v8), (180 * (unsigned __int64)(unsigned int)(v5 - v8)) >> 32, &v58) < 0 )
    return -2147483643;
  if ( v13 <= 1 )
  {
    v16 = 0;
    v15 = 0;
  }
  else
  {
    v15 = RtlULongLongToULong(4 * (v13 - 1), (v13 - 1) >> 30, &v51);
    v16 = v51;
  }
  if ( v15 < 0 )
    return -2147483643;
  if ( v16 + 24 < v16 )
    return -2147483643;
  v51 = v16 + 24;
  if ( RtlULongLongToULong((v16 + 24) * v14, ((v16 + 24) * (unsigned __int64)v14) >> 32, &v51) < 0 )
    return -2147483643;
  if ( v14 > 1 )
  {
    v18 = RtlULongLongToULong(4 * (v14 - 1), (v14 - 1) >> 30, &v59);
    v17 = (unsigned int)v59;
  }
  else
  {
    v17 = 0;
    v18 = 0;
  }
  if ( v18 < 0 )
    return -2147483643;
  v19 = v17 + 28;
  if ( v17 + 28 < v17 )
    return -2147483643;
  v20 = v51;
  v21 = v19 + v51;
  if ( v19 + v51 < v19 )
    return -2147483643;
  v22 = v58;
  v23 = v21 + v58;
  if ( v21 + v58 < v21 )
    return -2147483643;
  v24 = (_BYTE *)ExAllocatePoolWithTag(257, v21 + v58, 538996816);
  v25 = (unsigned int)v24;
  if ( !v24 )
    return -1073741670;
  memset(v24, 0, v23);
  memset((_BYTE *)(v19 + v25), 0, v20);
  v54 = (_BYTE *)(v19 + v25 + v20);
  memset(v54, 0, v22);
  v26 = v57[1];
  v51 = v26;
  if ( v26 == -1 )
  {
    v26 = PnpDefaultInterfaceType;
    v51 = PnpDefaultInterfaceType;
  }
  v27 = v56;
  v55 = v57[2];
  *(_DWORD *)(v25 + 4) = v55;
  *(_DWORD *)(v25 + 8) = v27;
  *(_DWORD *)(v25 + 12) = 0;
  *(_DWORD *)(v25 + 20) = v14;
  *(_DWORD *)v25 = v26;
  memset((_BYTE *)(v25 + 24), 0, 4 * v14);
  v28 = v14 - 1;
  v29 = 0;
  if ( v28 < 0 )
    goto LABEL_89;
  v30 = (unsigned int)v52;
  v31 = (int *)(v19 + v25);
  v32 = (int **)(v25 + 24);
  do
  {
    v33 = v30 + 8;
    v34 = v31;
    v30 += 8 + 32 * *(_DWORD *)(v30 + 4);
    *v32++ = v31;
    v31[3] = v29;
    v31[4] = 0;
    v31[2] = v25;
    v35 = *(unsigned __int8 *)(v33 + 1);
    v36 = v31 + 5;
    v31 += 5;
    v52 = (_DWORD *)v30;
    v50 = v31;
    ++v29;
    if ( v35 == 128 )
    {
      v37 = *(_DWORD *)(v33 + 8);
      v33 += 32;
    }
    else
    {
      v37 = 12288;
    }
    v38 = 0;
    *v34 = v37;
    if ( v33 >= v30 )
      goto LABEL_54;
    while ( 1 )
    {
      if ( *(unsigned __int8 *)(v33 + 1) == 240 )
      {
        v26 = *(_DWORD *)(v33 + 8);
        v51 = v26;
        if ( v26 == -1 )
        {
          v26 = PnpDefaultInterfaceType;
          v51 = PnpDefaultInterfaceType;
        }
        v55 = *(_DWORD *)(v33 + 12);
        goto LABEL_66;
      }
      v39 = v54;
      v54 += 180;
      ++v34[4];
      *v36 = v39;
      v40 = v55;
      v59 = v36 + 1;
      *((_DWORD *)v39 + 42) = 0;
      *((_DWORD *)v39 + 43) = 0;
      *((_DWORD *)v39 + 3) = v34;
      *((_DWORD *)v39 + 4) = v38;
      *((_DWORD *)v39 + 5) = v39;
      *(_DWORD *)v39 = v26;
      *((_DWORD *)v39 + 1) = v40;
      v41 = *(unsigned __int8 *)(v33 + 1);
      v58 = v38 + 1;
      v42 = (v41 & 0x80) == 0 && v41;
      v39[8] = v42;
      *((_DWORD *)v39 + 6) = v39 + 24;
      *((_DWORD *)v39 + 7) = v39 + 24;
      *((_DWORD *)v39 + 8) = 0;
      *((_DWORD *)v39 + 9) = v33;
      v43 = v56;
      ++v50;
      *((_DWORD *)v39 + 10) = *v56;
      v44 = v43[2];
      v45 = (int)v57;
      *((_DWORD *)v39 + 14) = v26;
      *((_DWORD *)v39 + 11) = v44;
      *((_DWORD *)v39 + 13) = 0;
      *((_DWORD *)v39 + 15) = *(_DWORD *)(v45 + 12);
      *((_DWORD *)v39 + 16) = *(_DWORD *)(v45 + 8);
      *((_DWORD *)v39 + 17) = v39 + 80;
      *((_DWORD *)v39 + 19) = -1;
      *((_DWORD *)v39 + 12) = 0;
      if ( !v39[8] )
      {
        v39[80] = *(_BYTE *)(v33 + 1);
        v39[81] = *(_BYTE *)(v33 + 2);
        *((_WORD *)v39 + 41) = *(_WORD *)(v33 + 4);
        *((_DWORD *)v39 + 21) = *(_DWORD *)(v33 + 8);
        *((_DWORD *)v39 + 22) = *(_DWORD *)(v33 + 12);
        *((_DWORD *)v39 + 23) = *(_DWORD *)(v33 + 16);
        if ( *(unsigned __int8 *)(v33 + 1) == 132 )
          v53 = 1;
        v38 = v58;
        v36 = v59;
LABEL_66:
        v33 += 32;
        goto LABEL_52;
      }
      v53 = 1;
      v39[80] = 8;
      v46 = *((_DWORD *)v39 + 8) + 1;
      for ( *((_DWORD *)v39 + 8) = v46; ; *((_DWORD *)v39 + 8) = v46 )
      {
        v33 += 32;
        if ( v33 >= v30 )
          break;
        if ( *(unsigned __int8 *)(v33 + 1) == 129 )
        {
          *((_DWORD *)v39 + 43) = v33;
          while ( v33 < v30 && *(unsigned __int8 *)(v33 + 1) == 129 )
          {
            ++*((_DWORD *)v39 + 42);
            v33 += 32;
          }
          break;
        }
        if ( (*(_BYTE *)v33 & 8) == 0 )
          break;
        ++v46;
      }
      v47 = IopSetupArbiterAndTranslators();
      if ( v47 < 0 )
        break;
      v26 = v51;
      v30 = (unsigned int)v52;
      v38 = v58;
      v36 = v59;
LABEL_52:
      if ( v33 >= v30 )
        goto LABEL_53;
    }
    --v32;
    --*(_DWORD *)(v25 + 20);
    --v29;
    IopFreeReqAlternative((int)v34);
    v30 = (unsigned int)v52;
    v60 = v47;
LABEL_53:
    v31 = v50;
LABEL_54:
    --v28;
    v26 = v51;
  }
  while ( v28 >= 0 );
  v48 = 0;
  if ( v29 )
  {
LABEL_56:
    if ( v53 )
      *v61 = v25;
    else
      IopFreeReqList(v25);
    return v48;
  }
LABEL_89:
  v49 = v60;
  v48 = v60;
  IopFreeReqList(v25);
  if ( !v49 )
    goto LABEL_56;
  return v48;
}
