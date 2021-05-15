// SmKmKeyGenKeyFind 
 
int *__fastcall SmKmKeyGenKeyFind(int a1, char *a2)
{
  int *v2; // r5
  int *i; // r4

  v2 = (int *)(a1 + 4);
  for ( i = *(int **)(a1 + 4); i != v2; i = (int *)*i )
  {
    if ( !wcscmp(a2, (char *)i[2]) )
      return i;
  }
  return 0;
}
