// PopGetDisplayTimeout 
 
int __fastcall PopGetDisplayTimeout(int a1)
{
  int result; // r0

  if ( PopConsoleContext != a1 || a1 == -1 )
    return 0;
  result = PopGetLockConsoleTimeout();
  if ( !result )
    result = PopDisplayTimeout;
  return result;
}
