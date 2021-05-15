// ExAcquireSpinLockExclusiveAtDpcLevel 
 
int __fastcall ExAcquireSpinLockExclusiveAtDpcLevel(unsigned int *a1)
{
  int result; // r0
  unsigned __int8 *v3; // r3
  unsigned int v4; // r1
  unsigned int v5; // r5
  unsigned int v6; // r1

  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50AEA4();
  v3 = (unsigned __int8 *)a1 + 3;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1);
  result = 0x40000000;
  while ( 1 )
  {
    v5 = *a1;
    if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v5 & 0x40000000) == 0 )
    {
      do
        v6 = __ldrex(a1);
      while ( v6 == v5 && __strex(v5 | 0x40000000, a1) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  return result;
}
