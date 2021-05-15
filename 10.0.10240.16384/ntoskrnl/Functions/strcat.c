// strcat 
 
char *__fastcall strcat(char *result, char *a2)
{
  int v2; // r3
  char *v3; // r2
  int v4; // r2
  int v5; // r3

  v2 = *result;
  v3 = result;
  while ( v2 )
    v2 = *++v3;
  v4 = v3 - a2;
  do
  {
    v5 = *a2;
    (a2++)[v4] = v5;
  }
  while ( v5 );
  return result;
}
