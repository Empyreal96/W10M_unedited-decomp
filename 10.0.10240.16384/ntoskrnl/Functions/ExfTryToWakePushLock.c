// ExfTryToWakePushLock 
 
unsigned int *__fastcall ExfTryToWakePushLock(unsigned int *result)
{
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r2

  v1 = *result;
  if ( (*result & 5) == 0 && (v1 & 2) != 0 )
  {
    v2 = v1 + 4;
    __dmb(0xBu);
    do
      v3 = __ldrex(result);
    while ( v3 == v1 && __strex(v2, result) );
    __dmb(0xBu);
    if ( v3 == v1 )
      result = (unsigned int *)ExpWakePushLock(result, v2);
  }
  return result;
}
