// strrchr 
 
char *__fastcall strrchr(char *result, char a2)
{
  char *v2; // r4

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
