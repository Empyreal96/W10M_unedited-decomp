// _wmakepath_s 
 
int __fastcall wmakepath_s(_WORD *a1, unsigned int a2, _WORD *a3, _WORD *a4, unsigned __int16 *a5, _WORD *a6)
{
  _WORD *v6; // r6
  int v7; // r4
  _WORD *v8; // r5
  int v9; // t1
  int v10; // r3
  _WORD *v11; // r2
  int i; // r3
  int v13; // t1
  _WORD *v14; // r2
  int j; // r3
  int v16; // t1
  int v17; // r4

  v6 = a4;
  if ( !a1 || !a2 )
  {
    v17 = 22;
    goto LABEL_33;
  }
  v7 = 0;
  v8 = a1;
  if ( a3 && *a3 )
  {
    v7 = 2;
    if ( a2 <= 2 )
      goto LABEL_30;
    *a1 = *a3;
    a1[1] = 58;
    v8 = a1 + 2;
  }
  if ( a4 && *a4 )
  {
    while ( ++v7 < a2 )
    {
      *v8++ = *v6;
      v9 = (unsigned __int16)v6[1];
      ++v6;
      if ( !v9 )
      {
        v10 = (unsigned __int16)*(v6 - 1);
        if ( v10 != 47 && v10 != 92 )
        {
          if ( ++v7 >= a2 )
            goto LABEL_30;
          *v8++ = 92;
        }
        goto LABEL_15;
      }
    }
    goto LABEL_30;
  }
LABEL_15:
  v11 = a5;
  if ( a5 )
  {
    for ( i = *a5; i; i = v13 )
    {
      if ( ++v7 >= a2 )
        goto LABEL_30;
      *v8++ = *v11;
      v13 = (unsigned __int16)v11[1];
      ++v11;
    }
  }
  v14 = a6;
  if ( a6 )
  {
    if ( !*a6 || *a6 == 46 )
    {
LABEL_25:
      for ( j = (unsigned __int16)*a6; j; j = v16 )
      {
        if ( ++v7 >= a2 )
          goto LABEL_30;
        *v8++ = *v14;
        v16 = (unsigned __int16)v14[1];
        ++v14;
      }
      goto LABEL_29;
    }
    if ( ++v7 < a2 )
    {
      *v8++ = 46;
      goto LABEL_25;
    }
LABEL_30:
    *a1 = 0;
    v17 = 34;
LABEL_33:
    PopPoCoalescinCallback();
    return v17;
  }
LABEL_29:
  if ( v7 + 1 > a2 )
    goto LABEL_30;
  *v8 = 0;
  return 0;
}
