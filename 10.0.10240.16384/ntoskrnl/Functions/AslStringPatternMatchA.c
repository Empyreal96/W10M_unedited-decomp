// AslStringPatternMatchA 
 
int __fastcall AslStringPatternMatchA(char *a1, int a2)
{
  _BYTE *v2; // r6
  int v4; // r0
  int v5; // r0
  int v6; // r4
  int v7; // r1
  int v8; // r4
  int v9; // r1

  v2 = (_BYTE *)a2;
  while ( 1 )
  {
    v4 = *a1;
    if ( !*a1 && !*v2 )
      return 1;
    if ( v4 != 42 )
    {
      if ( v4 != 63 )
      {
        v8 = toupper(v4, a2);
        if ( v8 != toupper((char)*v2, v9) )
          return 0;
      }
      ++a1;
      goto LABEL_7;
    }
    v5 = a1[1];
    if ( v5 == 42 )
    {
      ++a1;
    }
    else
    {
      if ( !a1[1] )
        return 1;
      v6 = toupper(v5, a2);
      if ( v6 == toupper((char)*v2, v7) )
      {
        if ( AslStringPatternMatchA(a1 + 1, v2) )
          return 1;
      }
LABEL_7:
      if ( !*v2 )
        return 0;
      ++v2;
    }
  }
}
