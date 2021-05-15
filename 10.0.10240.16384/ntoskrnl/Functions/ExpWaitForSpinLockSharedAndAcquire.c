// ExpWaitForSpinLockSharedAndAcquire 
 
int __fastcall ExpWaitForSpinLockSharedAndAcquire(unsigned int *a1)
{
  int result; // r0
  int v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r1

  result = 0;
  do
  {
    while ( 1 )
    {
      v3 = *a1;
      if ( (*a1 & 0x80000000) == 0 )
        break;
      if ( (v3 & 0x40000000) == 0 )
      {
        do
          v5 = __ldrex(a1);
        while ( v5 == v3 && __strex(v3 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      ++result;
      __dmb(0xAu);
      __yield();
    }
    do
      v4 = __ldrex(a1);
    while ( v4 == v3 && __strex((v3 + 1) & 0xBFFFFFFF, a1) );
    __dmb(0xBu);
  }
  while ( v4 != v3 );
  return result;
}
