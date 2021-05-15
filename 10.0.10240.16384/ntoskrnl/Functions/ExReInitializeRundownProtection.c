// ExReInitializeRundownProtection 
 
__int64 __fastcall ExReInitializeRundownProtection(__int64 result)
{
  unsigned int v1; // r2

  __dmb(0xBu);
  HIDWORD(result) = 0;
  do
    v1 = __ldrex((unsigned int *)result);
  while ( __strex(0, (unsigned int *)result) );
  __dmb(0xBu);
  return result;
}
