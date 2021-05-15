// _strupr 
 
char *__fastcall strupr(char *result)
{
  int v1; // r3
  _BYTE *v2; // r2
  int v3; // r3
  int v4; // t1

  if ( result )
  {
    v1 = *result;
    v2 = result;
    while ( v1 )
    {
      v3 = (char)*v2;
      if ( v3 >= 97 && v3 <= 122 )
        *v2 = v3 - 32;
      v4 = (char)*++v2;
      v1 = v4;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    result = 0;
  }
  return result;
}
