// strncat_s 
 
int __fastcall strncat_s(_BYTE *a1, int a2, char *a3, int a4)
{
  int v4; // r4
  char *v5; // r6
  int v6; // r7
  int v7; // r4
  _BYTE *v8; // r2
  int v9; // r2
  int v10; // r3
  int v11; // r6
  int v12; // r3

  v4 = a4;
  v5 = a3;
  v6 = a2;
  if ( a4 )
  {
    if ( !a1 )
      goto LABEL_32;
    goto LABEL_6;
  }
  if ( a1 )
  {
LABEL_6:
    if ( a2 )
    {
      if ( !a4 || a3 )
      {
        v8 = a1;
        do
        {
          if ( !*v8 )
            break;
          ++v8;
          --a2;
        }
        while ( a2 );
        if ( a2 )
        {
          if ( a4 == -1 )
          {
            v9 = v8 - v5;
            do
            {
              v10 = *v5;
              (v5++)[v9] = v10;
              if ( !v10 )
                break;
              --a2;
            }
            while ( a2 );
          }
          else
          {
            if ( !a4 )
              goto LABEL_26;
            v11 = v5 - v8;
            do
            {
              v12 = (char)v8[v11];
              *v8++ = v12;
              if ( !v12 )
                break;
              if ( !--a2 )
                break;
              --v4;
            }
            while ( v4 );
            if ( !v4 )
LABEL_26:
              *v8 = 0;
          }
          if ( a2 )
            return 0;
          if ( v4 == -1 )
          {
            a1[v6 - 1] = 0;
            return 80;
          }
          v7 = 34;
        }
        else
        {
          v7 = 22;
        }
        *a1 = 0;
        PopPoCoalescinCallback();
        return v7;
      }
      *a1 = 0;
    }
LABEL_32:
    PopPoCoalescinCallback();
    return 22;
  }
  if ( a2 )
    goto LABEL_32;
  return 0;
}
