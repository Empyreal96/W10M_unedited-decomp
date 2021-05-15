// sub_4FAE24 
 
unsigned int __fastcall sub_4FAE24(int a1, char *a2, char **a3, int a4, int a5, int a6)
{
  int v6; // r7
  char *v8; // r10
  int v9; // r6
  unsigned int v10; // r4
  char *v11; // r5
  int v12; // t1
  int v13; // r8
  int v14; // r3
  int v15; // r3
  unsigned int v16; // r10
  unsigned int v17; // r2
  int v18; // r0
  int v19; // t1
  char *v20; // r5

  v6 = a4;
  v8 = a2;
  if ( a3 )
    *a3 = a2;
  if ( !a2 || a4 && (a4 < 2 || a4 > 36) )
  {
    PopPoCoalescinCallback();
    return 0;
  }
  v9 = *a2;
  v10 = 0;
  v11 = a2 + 1;
  while ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v9) & 8) != 0 )
  {
    v12 = *v11++;
    v9 = v12;
  }
  if ( v9 == 45 )
  {
    v13 = a5 | 2;
LABEL_14:
    v9 = *v11++;
    goto LABEL_15;
  }
  v13 = a5;
  if ( v9 == 43 )
    goto LABEL_14;
LABEL_15:
  if ( v6 < 0 || v6 == 1 || v6 > 36 )
  {
    if ( a3 )
      *a3 = v8;
    return 0;
  }
  if ( v6 )
  {
    if ( v6 != 16 )
      goto LABEL_30;
    goto LABEL_26;
  }
  if ( v9 == 48 )
  {
    v14 = *v11;
    if ( v14 != 120 && v14 != 88 )
    {
      v6 = 8;
      goto LABEL_30;
    }
    v6 = 16;
LABEL_26:
    if ( v9 == 48 )
    {
      v15 = *v11;
      if ( v15 == 120 || v15 == 88 )
      {
        v9 = v11[1];
        v11 += 2;
      }
    }
    goto LABEL_30;
  }
  v6 = 10;
LABEL_30:
  v16 = 0xFFFFFFFF / v6;
  while ( 1 )
  {
    if ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v9) & 4) != 0 )
    {
      v17 = v9 - 48;
      goto LABEL_38;
    }
    if ( (*(_WORD *)(_pctype_func() + 2 * (unsigned __int8)v9) & 0x103) == 0 )
      break;
    if ( v9 >= 97 && v9 <= 122 )
      v9 -= 32;
    v17 = v9 - 55;
LABEL_38:
    v18 = a6;
    if ( v17 >= v6 )
      goto LABEL_48;
    v13 |= 8u;
    if ( a6 || v10 < v16 || v10 == v16 && v17 <= 0xFFFFFFFF % v6 )
    {
      v10 = v10 * v6 + v17;
    }
    else
    {
      v13 |= 4u;
      if ( !a3 )
        goto LABEL_48;
    }
    v19 = *v11++;
    v9 = v19;
  }
  v18 = a6;
LABEL_48:
  v20 = v11 - 1;
  if ( (v13 & 8) != 0 )
  {
    if ( ((v13 & 4) != 0 || (v13 & 1) == 0 && ((v13 & 2) != 0 && v10 > 0x80000000 || (v13 & 2) == 0 && v10 > 0x7FFFFFFF))
      && !v18 )
    {
      gbl_errno = 34;
      if ( (v13 & 1) != 0 )
      {
        v10 = -1;
      }
      else if ( (v13 & 2) != 0 )
      {
        v10 = 0x80000000;
      }
      else
      {
        v10 = 0x7FFFFFFF;
      }
    }
  }
  else
  {
    if ( a3 )
      v20 = a2;
    v10 = 0;
  }
  if ( a3 )
    *a3 = v20;
  if ( (v13 & 2) != 0 )
    v10 = -v10;
  return v10;
}
