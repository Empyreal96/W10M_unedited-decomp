// ExpFindHost 
 
void **__fastcall ExpFindHost(int a1, int a2)
{
  void **result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1

  for ( result = (void **)ExpHostList; ; result = (void **)*result )
  {
    if ( result == &ExpHostList )
      return 0;
    if ( *((unsigned __int16 *)result + 6) == a1 && *((unsigned __int16 *)result + 7) == a2 )
      break;
  }
  __dmb(0xBu);
  v4 = (unsigned int *)(result + 2);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + 1, v4) );
  __dmb(0xBu);
  return result;
}
