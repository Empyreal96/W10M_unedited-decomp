// wcsrchr 
 
unsigned __int16 *__fastcall wcsrchr(unsigned __int16 *result, int a2)
{
  unsigned __int16 *v2; // r2

  v2 = result;
  while ( *result++ )
    ;
  do
    --result;
  while ( result != v2 && *result != a2 );
  if ( *result != a2 )
    result = 0;
  return result;
}
