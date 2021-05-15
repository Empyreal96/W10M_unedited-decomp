// PopGetLockConsoleTimeoutUnsafe 
 
int PopGetLockConsoleTimeoutUnsafe()
{
  int result; // r0

  result = PopAdaptiveLockConsoleTimeout;
  if ( PopAdaptiveLockConsoleTimeout > (unsigned int)PopDisplayTimeout )
    result = PopDisplayTimeout;
  return result;
}
