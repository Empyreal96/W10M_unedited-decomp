// strcpy_s 
 
int __fastcall strcpy_s(_BYTE *a1, int a2, char *a3)
{
  int v4; // r4
  int v5; // r0
  int v6; // r3

  if ( !a1 || !a2 )
  {
    PopPoCoalescinCallback();
    return 22;
  }
  if ( a3 )
  {
    v5 = a1 - a3;
    do
    {
      v6 = *a3;
      (a3++)[v5] = v6;
      if ( !v6 )
        break;
      --a2;
    }
    while ( a2 );
    if ( a2 )
      return 0;
    v4 = 34;
  }
  else
  {
    v4 = 22;
  }
  *a1 = 0;
  PopPoCoalescinCallback();
  return v4;
}
