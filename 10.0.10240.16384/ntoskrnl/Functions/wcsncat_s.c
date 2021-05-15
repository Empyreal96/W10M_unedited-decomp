// wcsncat_s 
 
int __fastcall wcsncat_s(char *a1, int a2, char *a3, int a4)
{
  int v4; // r4
  char *v5; // r6
  int v6; // r7
  int v7; // r4
  char *v8; // r2
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
          if ( !*(_WORD *)v8 )
            break;
          v8 += 2;
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
              v10 = *(unsigned __int16 *)v5;
              *(_WORD *)&v5[v9] = v10;
              v5 += 2;
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
              v12 = *(unsigned __int16 *)&v8[v11];
              *(_WORD *)v8 = v12;
              v8 += 2;
              if ( !v12 )
                break;
              if ( !--a2 )
                break;
              --v4;
            }
            while ( v4 );
            if ( !v4 )
LABEL_26:
              *(_WORD *)v8 = 0;
          }
          if ( a2 )
            return 0;
          if ( v4 == -1 )
          {
            *(_WORD *)&a1[2 * v6 - 2] = 0;
            return 80;
          }
          v7 = 34;
        }
        else
        {
          v7 = 22;
        }
        *(_WORD *)a1 = 0;
        PopPoCoalescinCallback();
        return v7;
      }
      *(_WORD *)a1 = 0;
    }
LABEL_32:
    PopPoCoalescinCallback();
    return 22;
  }
  if ( a2 )
    goto LABEL_32;
  return 0;
}
