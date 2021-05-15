// _wcsrev 
 
unsigned __int16 *__fastcall wcsrev(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r4
  unsigned __int16 *v2; // r1
  unsigned __int16 *i; // r0
  unsigned __int16 v5; // t1
  unsigned __int16 v6; // r2

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
