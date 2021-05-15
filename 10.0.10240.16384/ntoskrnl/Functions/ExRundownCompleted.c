// ExRundownCompleted 
 
unsigned int *__fastcall ExRundownCompleted(unsigned int *result)
{
  unsigned int v1; // r2

  __dmb(0xBu);
  do
    v1 = __ldrex(result);
  while ( __strex(1u, result) );
  __dmb(0xBu);
  return result;
}
