// ExfReleasePushLockExclusive 
 
unsigned int *__fastcall ExfReleasePushLockExclusive(unsigned int *result)
{
  unsigned int *v1; // r5
  unsigned int v2; // r2
  int v3; // r1

  v1 = result;
  __dmb(0xBu);
  do
    v2 = __ldrex(result);
  while ( v2 == 1 && __strex(0, result) );
  __dmb(0xBu);
  if ( v2 != 1 )
  {
    while ( 1 )
    {
      v3 = (v2 & 4) != 0 || (v2 & 2) == 0 ? -1 : 3;
      __dmb(0xBu);
      do
        result = (unsigned int *)__ldrex(v1);
      while ( result == (unsigned int *)v2 && __strex(v3 + v2, v1) );
      __dmb(0xBu);
      if ( result == (unsigned int *)v2 )
        break;
      v2 = (unsigned int)result;
    }
    if ( v3 == 3 )
      result = (unsigned int *)ExpWakePushLock(v1, v2 + 3);
  }
  return result;
}
