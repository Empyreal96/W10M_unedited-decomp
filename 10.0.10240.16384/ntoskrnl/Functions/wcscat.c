// wcscat 
 
char *__fastcall wcscat(char *result, char *a2)
{
  int v2; // r3
  char *v3; // r2
  int v4; // r2
  int v5; // r3

  v2 = *(unsigned __int16 *)result;
  v3 = result;
  while ( v2 )
  {
    v3 += 2;
    v2 = *(unsigned __int16 *)v3;
  }
  v4 = v3 - a2;
  do
  {
    v5 = *(unsigned __int16 *)a2;
    *(_WORD *)&a2[v4] = v5;
    a2 += 2;
  }
  while ( v5 );
  return result;
}
