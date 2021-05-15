// wcscat_s 
 
int __fastcall wcscat_s(_WORD *a1, int a2, char *a3)
{
  _WORD *v3; // r5
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
    v5 = (char *)a1 - a3;
    do
    {
      v6 = *(unsigned __int16 *)a3;
      *(_WORD *)&a3[v5] = v6;
      a3 += 2;
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
