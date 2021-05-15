// ExReleaseSpinLockSharedFromDpcLevel 
 
unsigned int *__fastcall ExReleaseSpinLockSharedFromDpcLevel(unsigned int *result)
{
  unsigned int v1; // r1
  unsigned int v2; // r2

  if ( (dword_682604 & 0x10000) != 0 )
    return (unsigned int *)sub_50AB54();
  __dmb(0xBu);
  do
    v1 = __ldrex(result);
  while ( __strex(v1 & 0xBFFFFFFF, result) );
  __dmb(0xBu);
  do
    v2 = __ldrex(result);
  while ( __strex(v2 - 1, result) );
  return result;
}
