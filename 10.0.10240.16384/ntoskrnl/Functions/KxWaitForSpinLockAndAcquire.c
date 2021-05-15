// KxWaitForSpinLockAndAcquire 
 
int __fastcall KxWaitForSpinLockAndAcquire(unsigned int *a1)
{
  int result; // r0
  unsigned int v3; // r2

  result = 0;
  do
  {
    do
    {
      __dmb(0xAu);
      __yield();
      result += 2;
    }
    while ( *a1 );
    do
      v3 = __ldrex(a1);
    while ( __strex(1u, a1) );
    __dmb(0xBu);
  }
  while ( v3 );
  return result;
}
