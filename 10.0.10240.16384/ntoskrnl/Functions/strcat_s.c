// strcat_s 
 
int __fastcall strcat_s(_BYTE *a1, int a2, char *a3)
{
  _BYTE *v3; // r5
  int v4; // r4
  int v5; // r0
  int v6; // r3

  v3 = a1;
  if ( !a1 || !a2 )
    goto LABEL_16;
  if ( !a3 )
  {
    *a1 = 0;
LABEL_16:
    PopPoCoalescinCallback();
    return 22;
  }
  do
  {
    if ( !*a1 )
      break;
    ++a1;
    --a2;
  }
  while ( a2 );
  if ( a2 )
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
  *v3 = 0;
  PopPoCoalescinCallback();
  return v4;
}
