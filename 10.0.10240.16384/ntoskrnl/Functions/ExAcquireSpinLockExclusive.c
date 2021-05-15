// ExAcquireSpinLockExclusive 
 
int __fastcall ExAcquireSpinLockExclusive(unsigned int *a1)
{
  int v2; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50DF3C();
  v4 = (unsigned __int8 *)a1 + 3;
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1);
  while ( 1 )
  {
    v6 = *a1;
    if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v6 & 0x40000000) == 0 )
    {
      do
        v7 = __ldrex(a1);
      while ( v7 == v6 && __strex(v6 | 0x40000000, a1) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  return v2;
}
