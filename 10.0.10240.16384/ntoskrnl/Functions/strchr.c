// strchr 
 
_BYTE *__fastcall strchr(_BYTE *result, char a2)
{
  int i; // r3

  for ( i = (char)*result; *result; i = (char)*++result )
  {
    if ( i == a2 )
      break;
  }
  if ( (char)*result != a2 )
    result = 0;
  return result;
}
