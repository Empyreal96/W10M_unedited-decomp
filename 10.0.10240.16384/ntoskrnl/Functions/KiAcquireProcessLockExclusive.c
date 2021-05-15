// KiAcquireProcessLockExclusive 
 
int __fastcall KiAcquireProcessLockExclusive(int a1, _BYTE *a2)
{
  unsigned int *v3; // r4
  int result; // r0
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r1

  *a2 = KfRaiseIrql(2);
  v3 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_547870();
  v5 = (unsigned __int8 *)(a1 + 51);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 48));
  while ( 1 )
  {
    result = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (result & 0x40000000) == 0 )
    {
      do
        v7 = __ldrex(v3);
      while ( v7 == result && __strex(result | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  return result;
}
