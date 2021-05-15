// Normalization__IsNormalized 
 
int __fastcall Normalization__IsNormalized(int a1, unsigned __int16 *a2, int a3, char *a4)
{
  unsigned __int16 *v5; // r10
  int result; // r0
  int v8; // r1
  int v9; // r3
  int v10; // r5
  int v11; // r3
  int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // t1
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r9
  int v18; // r8
  unsigned int v19; // r7
  unsigned int v20; // r7
  int v21; // r8
  int v22; // r3
  int v23; // r0
  int v24; // r0
  int v25; // r0
  char v26; // r3
  unsigned __int8 v27; // [sp+8h] [bp-48h] BYREF
  char v28[3]; // [sp+9h] [bp-47h] BYREF
  int v29; // [sp+Ch] [bp-44h] BYREF
  int v30; // [sp+10h] [bp-40h] BYREF
  int v31; // [sp+14h] [bp-3Ch]
  unsigned __int16 *v32; // [sp+18h] [bp-38h] BYREF
  int v33; // [sp+1Ch] [bp-34h]
  int v34; // [sp+20h] [bp-30h]
  int v35; // [sp+24h] [bp-2Ch] BYREF
  unsigned int v36; // [sp+28h] [bp-28h]
  int v37; // [sp+2Ch] [bp-24h]
  int v38; // [sp+30h] [bp-20h]

  v34 = a3;
  v5 = a2;
  if ( !a2 )
    return -1073741811;
  v29 = 0;
  v28[0] = 0;
  v27 = 0;
  v8 = v34;
  v32 = v5 - 1;
  v30 = 0;
  v31 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  if ( v34 <= 0 )
    goto LABEL_104;
  v9 = *(_DWORD *)(a1 + 16);
  v33 = v9;
  while ( 1 )
  {
    v10 = *v5;
    if ( v10 >= v9 )
      break;
LABEL_103:
    v34 = --v8;
    ++v5;
    if ( v8 <= 0 )
      goto LABEL_104;
  }
  v11 = *(_DWORD *)(a1 + 20);
  v12 = *(unsigned __int8 *)((v10 >> 7) + v11);
  if ( !*(_BYTE *)((v10 >> 7) + v11) || v12 == 251 && *(_BYTE *)(a1 + 61) )
  {
LABEL_102:
    v9 = v33;
    goto LABEL_103;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      switch ( v12 )
      {
        case 0:
          goto LABEL_100;
        case 251:
          goto LABEL_99;
        case 252:
          return -1073740009;
        case 253:
          goto LABEL_92;
      }
      if ( v12 != 254 )
        break;
      if ( v8 <= 1 )
        return -1073740009;
      v14 = v5[1];
      ++v5;
      v13 = v14;
      v34 = --v8;
      if ( v14 < 0xDC00 || v13 > 0xDFFF )
        return -1073740009;
      v10 = v13 + ((v10 - 55287) << 10);
      v12 = *(unsigned __int8 *)((v10 >> 7) + *(_DWORD *)(a1 + 20));
    }
    if ( v12 != 255 )
      break;
    if ( v10 < 44032 )
    {
      if ( v8 > 1 )
      {
        if ( CanComposeHangul(v10, v5[1]) )
          goto LABEL_92;
        v8 = v34;
      }
      if ( (*(_DWORD *)a1 == 269 || *(_DWORD *)a1 == 13) && (unsigned int)(v10 - 4447) <= 1 )
        goto LABEL_20;
LABEL_27:
      v12 = 0;
    }
    else
    {
      if ( IsHangulS(v10) )
      {
        if ( *(_BYTE *)(a1 + 60) != 1 )
        {
          if ( v8 <= 1 )
            goto LABEL_100;
          if ( !CanComposeHangul(v10, v5[1]) )
          {
            v8 = v34;
            goto LABEL_100;
          }
        }
LABEL_92:
        v26 = 0;
        goto LABEL_105;
      }
      if ( v10 >= 55216 && v10 <= 55238 || (unsigned int)(v10 - 55243) <= 0x30 )
        goto LABEL_27;
LABEL_20:
      v12 = 251;
    }
  }
  v15 = (v10 & 0x7F) + (v12 << 7);
  v16 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 24) + v15 - 128);
  if ( !*(_BYTE *)(*(_DWORD *)(a1 + 24) + v15 - 128) )
    goto LABEL_100;
  v17 = v16 & 0x3F;
  v18 = v16 & 0xC0;
  v38 = v18;
  if ( (v16 & 0x3F) != 0 && v17 != 63 )
  {
LABEL_45:
    if ( (v16 & 0xC0) == 0 || v18 == 64 )
    {
      v30 = 0;
LABEL_96:
      v31 = v10;
      v36 = v17;
      goto LABEL_97;
    }
    Normalization__GetLastChar(a1, (int)v5, &v32, &v29, v28, &v27);
    v19 = (unsigned __int8)v28[0];
    if ( !v28[0] || v28[0] == 63 )
    {
      v36 = (unsigned __int8)v28[0];
      v37 = v27;
      v31 = v29;
      if ( v27 != 64 && v27 != 128 || v18 != 192 )
        goto LABEL_98;
      v23 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v29, v10, v27);
      goto LABEL_91;
    }
    v18 = v27;
    if ( v27 && v27 != 64 )
    {
      if ( (unsigned __int8)v28[0] > v17 )
        goto LABEL_92;
      if ( v38 != 192 || (unsigned __int8)v28[0] == v17 )
        goto LABEL_98;
      v20 = v36;
      v21 = v37;
      v22 = (unsigned __int8)v37 | (unsigned __int8)v36;
      if ( (v22 == 64 || v22 == 128 || v37 == 64 && (!v36 || v36 == 63))
        && Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v31, v10, v22) )
      {
        goto LABEL_92;
      }
      if ( v17 >= v20 || v21 != 64 && v21 || !v20 || v20 >= 0x3F )
        goto LABEL_98;
      if ( v20 == *(unsigned __int8 *)(a1 + 64) )
      {
        if ( v17 >= *(unsigned __int8 *)(a1 + 62) )
        {
          if ( v17 != *(unsigned __int8 *)(a1 + 63) )
          {
LABEL_98:
            v29 = v10;
            v8 = v34;
            v28[0] = v17;
            v27 = v38;
LABEL_101:
            v32 = v5;
            goto LABEL_102;
          }
          goto LABEL_71;
        }
      }
      else if ( v20 == *(unsigned __int8 *)(a1 + 66) && v17 == *(unsigned __int8 *)(a1 + 65) )
      {
LABEL_71:
        v23 = Normalization__CanCombineWithStartFirstPair((_DWORD *)a1, &v35, &v30, v31, v10);
        goto LABEL_91;
      }
      v23 = Normalization__CanCombineWithStartBase((_DWORD *)a1, &v30, v31, v10);
LABEL_91:
      if ( v23 )
        goto LABEL_92;
      goto LABEL_98;
    }
    v24 = v29;
    v30 = 0;
    v31 = v29;
    v35 = 0;
    if ( v38 != 192 )
      goto LABEL_86;
    if ( v27 == 64 )
    {
      if ( Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v29, v10, 192) )
        goto LABEL_92;
      v24 = v31;
    }
    if ( v19 <= v17 )
      goto LABEL_86;
    if ( v19 == *(unsigned __int8 *)(a1 + 64) )
    {
      if ( v17 >= *(unsigned __int8 *)(a1 + 62) )
      {
        if ( v17 == *(unsigned __int8 *)(a1 + 63) )
        {
LABEL_81:
          v25 = Normalization__CanCombineWithStartFirstPair((_DWORD *)a1, &v35, &v30, v24, v10);
          goto LABEL_85;
        }
LABEL_86:
        v36 = v19;
LABEL_97:
        v37 = v18;
        goto LABEL_98;
      }
    }
    else if ( v19 == *(unsigned __int8 *)(a1 + 66) && v17 == *(unsigned __int8 *)(a1 + 65) )
    {
      goto LABEL_81;
    }
    v25 = Normalization__CanCombineWithStartBase((_DWORD *)a1, &v30, v24, v10);
LABEL_85:
    if ( v25 )
      goto LABEL_92;
    goto LABEL_86;
  }
  switch ( v16 )
  {
    case 64:
      goto LABEL_96;
    case 127:
LABEL_99:
      if ( !*(_BYTE *)(a1 + 61) )
        return -1073740009;
LABEL_100:
      v28[0] = 0;
      v27 = 0;
      v29 = v10;
      goto LABEL_101;
    case 128:
      goto LABEL_96;
    case 191:
      goto LABEL_92;
    case 192:
      Normalization__GetLastChar(a1, (int)v5, &v32, &v29, v28, &v27);
      if ( (v27 | (unsigned __int8)v28[0]) == 128
        && Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v29, v10, 128) )
      {
        goto LABEL_92;
      }
      goto LABEL_96;
  }
  if ( v16 != 255 )
    goto LABEL_45;
  if ( v10 || v8 > 1 )
    return -1073740009;
LABEL_104:
  v26 = 1;
LABEL_105:
  result = 0;
  *a4 = v26;
  return result;
}
