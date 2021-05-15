// strncat 
 
char *__fastcall strncat(char *a1, char *a2, int a3)
{
  char *v3; // r4
  char *v5; // r0
  int v6; // t1

  v3 = a1;
  while ( *a1++ )
    ;
  v5 = a1 - 1;
  while ( a3 )
  {
    v6 = *a2++;
    --a3;
    *v5++ = v6;
    if ( !v6 )
      return v3;
  }
  *v5 = 0;
  return v3;
}
