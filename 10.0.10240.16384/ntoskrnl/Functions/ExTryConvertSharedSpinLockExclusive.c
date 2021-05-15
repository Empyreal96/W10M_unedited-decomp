// ExTryConvertSharedSpinLockExclusive 
 
int __fastcall ExTryConvertSharedSpinLockExclusive(unsigned int *a1)
{
  unsigned __int8 *v2; // r3
  unsigned int v3; // r1
  unsigned int v4; // r4
  unsigned int v5; // r1

  if ( (dword_682604 & 0x210000) != 0 )
    return ExpTryConvertSharedSpinLockExclusiveInstrumented(a1);
  v2 = (unsigned __int8 *)a1 + 3;
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    return 0;
  while ( 1 )
  {
    v4 = *a1;
    if ( (*a1 & 0xBFFFFFFF) == -2147483647 )
      break;
    if ( (v4 & 0x40000000) == 0 )
    {
      do
        v5 = __ldrex(a1);
      while ( v5 == v4 && __strex(v4 | 0x40000000, a1) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  return 1;
}
