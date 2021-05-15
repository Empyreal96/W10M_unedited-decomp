// IopDestroyPassiveInterruptBlock 
 
unsigned int *__fastcall IopDestroyPassiveInterruptBlock(int a1)
{
  unsigned int *result; // r0
  unsigned int *v2; // r2
  unsigned int v3; // r1

  result = (unsigned int *)IopFindPassiveInterruptBlock(a1);
  if ( result )
  {
    __dmb(0xBu);
    v2 = result + 27;
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 - 1, v2) );
    __dmb(0xBu);
    result = (unsigned int *)IopDereferencePassiveInterruptBlock(result);
  }
  return result;
}
