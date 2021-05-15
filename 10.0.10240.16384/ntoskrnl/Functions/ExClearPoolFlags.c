// ExClearPoolFlags 
 
int *ExClearPoolFlags()
{
  int *result; // r0
  unsigned int v1; // r4

  __dmb(0xBu);
  result = &ExpPoolFlags;
  do
    v1 = __ldrex((unsigned int *)&ExpPoolFlags);
  while ( __strex(v1 & 0xFFFFFBF9, (unsigned int *)&ExpPoolFlags) );
  __dmb(0xBu);
  return result;
}
