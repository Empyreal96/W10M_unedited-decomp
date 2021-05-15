// EtwpGetProviderGroupFromTraits 
 
char *__fastcall EtwpGetProviderGroupFromTraits(char *a1)
{
  int v1; // r3
  unsigned __int16 *v2; // r5
  unsigned __int16 *i; // r2
  int v4; // r1

  v1 = *(unsigned __int16 *)a1;
  v2 = (unsigned __int16 *)&a1[v1];
  for ( i = (unsigned __int16 *)&a1[strnlen(a1 + 2, v1 - 3) + 3]; i < v2; i = (unsigned __int16 *)((char *)i + v4) )
  {
    v4 = *i;
    if ( v4 == 19 && *((_BYTE *)i + 2) == 1 )
      return (char *)i + 3;
  }
  return 0;
}
