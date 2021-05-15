// ExpBootFinishedDispatch 
 
unsigned int ExpBootFinishedDispatch()
{
  unsigned int result; // r0

  __dmb(0xBu);
  do
    result = __ldrex((unsigned int *)&ExpPoolFlags);
  while ( __strex(result & 0xFFFFFEFF, (unsigned int *)&ExpPoolFlags) );
  __dmb(0xBu);
  return result;
}
