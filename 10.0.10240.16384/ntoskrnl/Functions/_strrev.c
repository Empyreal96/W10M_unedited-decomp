// _strrev 
 
char *__fastcall strrev(char *a1)
{
  char *v1; // r4
  char *v2; // r1
  char *i; // r0
  char v5; // t1
  char v6; // r2

  v1 = a1;
  v2 = a1;
  while ( *a1++ )
    ;
  for ( i = a1 - 2; v2 < i; i[1] = v6 )
  {
    v5 = *i--;
    v6 = *v2;
    *v2++ = v5;
  }
  return v1;
}
