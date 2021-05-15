// ExConvertPushLockExclusiveToShared 
 
unsigned int *__fastcall ExConvertPushLockExclusiveToShared(unsigned int *result)
{
  unsigned int v1; // r2

  __dmb(0xBu);
  do
    v1 = __ldrex(result);
  while ( v1 == 1 && __strex(0x11u, result) );
  __dmb(0xBu);
  return result;
}
