// sub_4F99C8 
 
unsigned int __fastcall sub_4F99C8(int a1, char *a2, char **a3, int a4, int a5)
{
  int v5; // r9
  unsigned int v6; // r7
  int v7; // r5
  unsigned int v8; // r6
  char *v9; // r4
  int v10; // r3
  int v11; // t1
  int v12; // r8
  int v13; // r3
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r5
  int v20; // t1
  char *v21; // r4
  char **v22; // r3
  unsigned int v25; // [sp+Ch] [bp-34h]
  unsigned int v26; // [sp+14h] [bp-2Ch]
  int v27; // [sp+18h] [bp-28h]
  unsigned int v28; // [sp+1Ch] [bp-24h]

  v5 = a4;
  if ( a3 )
    *a3 = a2;
  if ( !a2 || a4 && (a4 < 2 || a4 > 36) )
  {
    PopPoCoalescinCallback();
    return 0;
  }
  v7 = *a2;
  v6 = 0;
  v8 = 0;
  v9 = a2 + 1;
  while ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v7) & 8) != 0 )
  {
    do
    {
      v11 = *v9++;
      v10 = v11;
    }
    while ( v11 == v7 );
    v7 = v10;
  }
  if ( v7 == 45 )
  {
    v12 = a5 | 2;
  }
  else
  {
    v12 = a5;
    if ( v7 != 43 )
      goto LABEL_16;
  }
  v7 = *v9++;
LABEL_16:
  if ( !v5 )
  {
    if ( v7 != 48 )
    {
      v5 = 10;
      goto LABEL_28;
    }
    v13 = *v9;
    if ( v13 != 120 && v13 != 88 )
    {
      v5 = 8;
      goto LABEL_28;
    }
    v5 = 16;
  }
  if ( v5 == 16 && v7 == 48 )
  {
    v14 = *v9;
    if ( v14 == 120 || v14 == 88 )
    {
      v7 = v9[1];
      v9 += 2;
    }
  }
LABEL_28:
  v15 = _rt_udiv64(v5, 0xFFFFFFFFFFFFFFFFui64);
  v27 = v17;
  v28 = v16;
  v26 = v18;
  v25 = v15;
  while ( 1 )
  {
    if ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v7) & 4) != 0 )
    {
      v19 = v7 - 48;
    }
    else
    {
      if ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v7) & 0x103) == 0 )
        break;
      if ( v7 >= 97 && v7 <= 122 )
        v7 -= 32;
      v19 = v7 - 55;
    }
    if ( v19 >= v5 )
      break;
    v12 |= 8u;
    if ( v8 < v26 || v8 <= v26 && v6 < v25 || v6 == v25 && v8 == v26 && (v27 || v19 <= v28) )
    {
      v8 = (v5 * __PAIR64__(v8, v6) + v19) >> 32;
      v6 = v5 * v6 + v19;
    }
    else
    {
      v12 |= 4u;
      if ( !a3 )
        break;
    }
    v20 = *v9++;
    v7 = v20;
  }
  v21 = v9 - 1;
  if ( (v12 & 8) == 0 )
  {
    v22 = a3;
    if ( a3 )
      v21 = a2;
    v6 = 0;
    goto LABEL_67;
  }
  if ( (v12 & 4) != 0 )
    goto LABEL_60;
  if ( (v12 & 1) != 0 )
  {
    v22 = a3;
    goto LABEL_67;
  }
  if ( (v12 & 2) != 0 && (v8 > 0x80000000 || v8 >= 0x80000000 && v6) || (v12 & 2) == 0 && v8 > 0x7FFFFFFF )
  {
LABEL_60:
    gbl_errno = 34;
    if ( (v12 & 1) == 0 )
    {
      v22 = a3;
      if ( (v12 & 2) != 0 )
        v6 = 0;
      else
        v6 = -1;
      goto LABEL_67;
    }
    v6 = -1;
  }
  v22 = a3;
LABEL_67:
  if ( v22 )
    *v22 = v21;
  if ( (v12 & 2) != 0 )
    v6 = -v6;
  return v6;
}
