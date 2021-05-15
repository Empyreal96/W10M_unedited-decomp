// ExAcquireSpinLockShared 
 
int __fastcall ExAcquireSpinLockShared(unsigned int *a1)
{
  int v2; // r5
  int v4; // r0
  unsigned int v5; // r1

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50AA60();
  v4 = *a1 & 0x7FFFFFFF;
  do
    v5 = __ldrex(a1);
  while ( v5 == v4 && __strex(v4 + 1, a1) );
  __dmb(0xBu);
  if ( v5 != v4 )
    ExpWaitForSpinLockSharedAndAcquire(a1, v5);
  return v2;
}
