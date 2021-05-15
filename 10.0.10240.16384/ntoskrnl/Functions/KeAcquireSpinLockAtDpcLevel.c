// KeAcquireSpinLockAtDpcLevel 
 
unsigned int *__fastcall KeAcquireSpinLockAtDpcLevel(unsigned int *result)
{
  unsigned int v1; // r2

  if ( (dword_682604 & 0x210000) != 0 )
    return (unsigned int *)KiAcquireSpinLockInstrumented(result);
  do
    v1 = __ldrex(result);
  while ( __strex(1u, result) );
  __dmb(0xBu);
  if ( v1 )
    result = (unsigned int *)KxWaitForSpinLockAndAcquire(result);
  return result;
}
