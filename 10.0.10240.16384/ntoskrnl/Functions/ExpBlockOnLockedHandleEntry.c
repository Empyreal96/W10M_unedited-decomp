// ExpBlockOnLockedHandleEntry 
 
int ExpBlockOnLockedHandleEntry(int a1, unsigned __int64 *a2, ...)
{
  va_list varg_r2; // [sp+18h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  return ExBlockOnAddressPushLock(a1 + 32, a2, (unsigned int *)varg_r2, 4, 0);
}
