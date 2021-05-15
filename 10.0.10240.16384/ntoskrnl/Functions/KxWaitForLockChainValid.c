// KxWaitForLockChainValid 
 
int __fastcall KxWaitForLockChainValid(int *a1)
{
  int result; // r0

  do
  {
    __dmb(0xAu);
    __yield();
    result = *a1;
  }
  while ( !*a1 );
  return result;
}
