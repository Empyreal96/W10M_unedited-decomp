// MiSetNonPagedPoolNoSteal 
 
unsigned int *__fastcall MiSetNonPagedPoolNoSteal(unsigned int *result)
{
  unsigned int v1; // r1
  unsigned int v2; // r4

  v1 = *result;
  if ( (*result & 0x100) == 0 )
  {
    __dmb(0xBu);
    do
      v2 = __ldrex(result);
    while ( v2 == v1 && __strex(v1 | 0x110, result) );
    __dmb(0xBu);
    if ( v2 != v1 )
      result = (unsigned int *)sub_51AA58();
  }
  return result;
}
