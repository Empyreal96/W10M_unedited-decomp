// ExpWaitForSpinLockExclusiveAndAcquire 
 
int __fastcall ExpWaitForSpinLockExclusiveAndAcquire(unsigned int *a1)
{
  int result; // r0
  unsigned __int8 *v3; // r7
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1

  result = 0;
  v3 = (unsigned __int8 *)a1 + 3;
  do
  {
    while ( 1 )
    {
      v4 = *a1;
      if ( (*a1 & 0x80000000) == 0 )
        break;
      if ( (v4 & 0x40000000) == 0 )
      {
        do
          v6 = __ldrex(a1);
        while ( v6 == v4 && __strex(v4 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      ++result;
      __dmb(0xAu);
      __yield();
    }
    do
      v5 = __ldrex(v3);
    while ( __strex(v5 | 0x80, v3) );
    __dmb(0xBu);
  }
  while ( v5 >> 7 );
  return result;
}
