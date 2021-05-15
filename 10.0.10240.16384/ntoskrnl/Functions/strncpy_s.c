// strncpy_s 
 
int __fastcall strncpy_s(_BYTE *a1, int a2, char *a3, int a4)
{
  int v4; // r4
  int v5; // r4
  _BYTE *v6; // r6
  int v7; // r5
  int v8; // r6
  int v9; // r3
  int v10; // r2
  int v11; // r3

  v4 = a4;
  if ( a4 )
  {
    if ( !a1 )
      goto LABEL_27;
  }
  else if ( !a1 )
  {
    if ( !a2 )
      return 0;
LABEL_27:
    PopPoCoalescinCallback();
    return 22;
  }
  if ( !a2 )
    goto LABEL_27;
  if ( a4 )
  {
    if ( a3 )
    {
      v6 = a1;
      v7 = a2;
      if ( a4 == -1 )
      {
        v8 = a1 - a3;
        do
        {
          v9 = *a3;
          (a3++)[v8] = v9;
          if ( !v9 )
            break;
          --v7;
        }
        while ( v7 );
      }
      else
      {
        v10 = a3 - a1;
        do
        {
          v11 = (char)v6[v10];
          *v6++ = v11;
          if ( !v11 )
            break;
          if ( !--v7 )
            break;
          --v4;
        }
        while ( v4 );
        if ( !v4 )
          *v6 = 0;
      }
      if ( v7 )
        return 0;
      if ( v4 == -1 )
      {
        a1[a2 - 1] = 0;
        return 80;
      }
      v5 = 34;
    }
    else
    {
      v5 = 22;
    }
    *a1 = 0;
    PopPoCoalescinCallback();
    return v5;
  }
  *a1 = 0;
  return 0;
}
