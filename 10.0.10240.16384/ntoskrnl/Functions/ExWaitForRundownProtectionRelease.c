// ExWaitForRundownProtectionRelease 
 
unsigned int *__fastcall ExWaitForRundownProtectionRelease(unsigned int *result)
{
  unsigned int v1; // r1

  do
    v1 = __ldrex(result);
  while ( !v1 && __strex(1u, result) );
  __dmb(0xBu);
  if ( v1 )
  {
    if ( v1 != 1 )
      result = (unsigned int *)ExfWaitForRundownProtectionRelease(result, v1, 1);
  }
  return result;
}
