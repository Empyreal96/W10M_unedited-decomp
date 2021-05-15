// _splitpath_s 
 
int __fastcall splitpath_s(_BYTE *a1, _BYTE *a2, unsigned int a3, _BYTE *a4, unsigned int a5, _BYTE *a6, unsigned int a7, _BYTE *a8, unsigned int a9)
{
  _BYTE *v9; // lr
  unsigned int v10; // r3
  _BYTE *v11; // r5
  unsigned int v12; // r6
  unsigned int v13; // r7
  unsigned int v15; // r1
  int v16; // r2
  int v17; // r2
  _BYTE *v18; // r4
  int v19; // r3
  _BYTE *v20; // r7
  unsigned int v21; // r4
  _BYTE *v22; // r6
  _BYTE *v23; // r3

  v9 = a4;
  v10 = a3;
  v11 = a1;
  v12 = a9;
  v13 = a7;
  v15 = a5;
  if ( !a1 )
    goto LABEL_4;
  if ( a2 )
  {
    if ( !a3 )
      goto LABEL_4;
  }
  else if ( a3 )
  {
LABEL_4:
    v16 = 1;
    goto LABEL_61;
  }
  if ( v9 )
  {
    if ( !a5 )
      goto LABEL_4;
  }
  else if ( a5 )
  {
    goto LABEL_4;
  }
  if ( a6 )
  {
    if ( !a7 )
      goto LABEL_4;
  }
  else if ( a7 )
  {
    goto LABEL_4;
  }
  if ( a8 )
  {
    if ( !a9 )
      goto LABEL_4;
  }
  else if ( a9 )
  {
    goto LABEL_4;
  }
  v17 = 1;
  v18 = a1;
  do
  {
    if ( !*v18 )
      break;
    --v17;
    ++v18;
  }
  while ( v17 );
  if ( *v18 != 58 )
  {
    if ( a2 )
      *a2 = 0;
LABEL_26:
    v19 = (char)*v11;
    v20 = 0;
    v21 = 0;
    v22 = v11;
    if ( !*v11 )
      goto LABEL_40;
    do
    {
      if ( v19 == 47 || v19 == 92 )
      {
        v20 = v22 + 1;
      }
      else if ( v19 == 46 )
      {
        v21 = (unsigned int)v22;
      }
      v19 = (char)*++v22;
    }
    while ( *v22 );
    if ( v20 )
    {
      if ( v9 )
      {
        if ( v15 <= v20 - v11 )
        {
          v13 = a7;
          v12 = a9;
LABEL_59:
          v10 = a3;
          goto LABEL_60;
        }
        strncpy_s(v9, v15, v11, v20 - v11);
      }
      v11 = v20;
    }
    else
    {
LABEL_40:
      if ( v9 )
        *v9 = 0;
    }
    if ( v21 && v21 >= (unsigned int)v11 )
    {
      v13 = a7;
      if ( !a6 )
      {
LABEL_47:
        if ( !a8 )
          return 0;
        v23 = &v22[-v21];
        v12 = a9;
        if ( a9 > (unsigned int)v23 )
        {
          strncpy_s(a8, a9, v21, v23);
          return 0;
        }
        goto LABEL_58;
      }
      if ( a7 > v21 - (unsigned int)v11 )
      {
        strncpy_s(a6, a7, v11, v21 - (_DWORD)v11);
        goto LABEL_47;
      }
LABEL_57:
      v12 = a9;
LABEL_58:
      v15 = a5;
      goto LABEL_59;
    }
    if ( a6 )
    {
      v13 = a7;
      if ( a7 <= v22 - v11 )
        goto LABEL_57;
      strncpy_s(a6, a7, v11, v22 - v11);
    }
    if ( a8 )
      *a8 = 0;
    return 0;
  }
  if ( !a2 )
  {
LABEL_25:
    v11 = v18 + 1;
    goto LABEL_26;
  }
  v10 = a3;
  if ( a3 >= 3 )
  {
    strncpy_s(a2, a3, a1, 2);
    v9 = a4;
    v15 = a5;
    goto LABEL_25;
  }
LABEL_60:
  v16 = 0;
LABEL_61:
  if ( a2 && v10 )
    *a2 = 0;
  if ( a4 && v15 )
    *a4 = 0;
  if ( a6 && v13 )
    *a6 = 0;
  if ( a8 && v12 )
    *a8 = 0;
  if ( v11 && !v16 )
    return 34;
  PopPoCoalescinCallback();
  return 22;
}
