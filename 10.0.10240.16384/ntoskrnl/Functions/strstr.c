// strstr 
 
_BYTE *__fastcall strstr(_BYTE *result, _BYTE *a2)
{
  int v3; // r3
  int v4; // r1
  _BYTE *i; // r2
  int v6; // t1

  if ( *a2 )
  {
    v3 = (char)*result;
    if ( *result )
    {
      v4 = result - a2;
      while ( 1 )
      {
        for ( i = a2; v3 && *i && i[v4] == *i; v3 = (char)i[v4] )
          ++i;
        if ( !*i )
          break;
        v6 = (char)*++result;
        v3 = v6;
        ++v4;
        if ( !v6 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      result = 0;
    }
  }
  return result;
}
