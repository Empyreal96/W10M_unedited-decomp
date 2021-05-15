// wcsncat 
 
unsigned __int16 *__fastcall wcsncat(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned __int16 *v3; // r4
  unsigned __int16 *v5; // r0
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
