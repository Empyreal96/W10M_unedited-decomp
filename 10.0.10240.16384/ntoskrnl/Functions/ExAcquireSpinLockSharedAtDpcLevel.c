// ExAcquireSpinLockSharedAtDpcLevel 
 
int __fastcall ExAcquireSpinLockSharedAtDpcLevel(unsigned int *a1)
{
  int result; // r0
  unsigned int v3; // r1

  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50AA6C();
  result = *a1 & 0x7FFFFFFF;
  do
    v3 = __ldrex(a1);
  while ( v3 == result && __strex(result + 1, a1) );
  __dmb(0xBu);
  if ( v3 != result )
    result = ExpWaitForSpinLockSharedAndAcquire(a1, v3);
  return result;
}
