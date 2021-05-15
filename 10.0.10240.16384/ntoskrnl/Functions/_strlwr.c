// _strlwr 
 
char *__fastcall strlwr(char *result)
{
  int v1; // r3
  _BYTE *v2; // r2
  int v3; // r3
  int v4; // t1

  v1 = *result;
  v2 = result;
  while ( v1 )
  {
    v3 = (char)*v2;
    if ( v3 >= 65 && v3 <= 90 )
      *v2 = v3 + 32;
    v4 = (char)*++v2;
    v1 = v4;
  }
  return result;
}
