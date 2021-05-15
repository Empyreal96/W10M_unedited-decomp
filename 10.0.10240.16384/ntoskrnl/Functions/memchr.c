// memchr 
 
unsigned __int8 *__fastcall memchr(unsigned __int8 *result, unsigned __int8 a2, int a3)
{
  if ( !a3 )
    return 0;
  do
  {
    if ( *result == a2 )
      break;
    ++result;
    --a3;
  }
  while ( a3 );
  if ( !a3 )
    return 0;
  return result;
}
