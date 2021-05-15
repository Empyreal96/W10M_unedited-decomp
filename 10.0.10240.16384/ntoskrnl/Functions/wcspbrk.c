// wcspbrk 
 
unsigned __int16 *__fastcall wcspbrk(unsigned __int16 *result, _WORD *a2)
{
  int v2; // r3
  _WORD *v3; // r5
  int v4; // r2
  int v5; // t1
  int v6; // t1

  v2 = *result;
  if ( !*result )
    return 0;
  while ( 1 )
  {
    v3 = a2;
    if ( *a2 )
      break;
LABEL_6:
    v6 = result[1];
    ++result;
    v2 = v6;
    if ( !v6 )
      return 0;
  }
  v4 = (unsigned __int16)*a2;
  while ( v4 != v2 )
  {
    v5 = (unsigned __int16)v3[1];
    ++v3;
    v4 = v5;
    if ( !v5 )
      goto LABEL_6;
  }
  return result;
}
