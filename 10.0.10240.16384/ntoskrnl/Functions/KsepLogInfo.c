// KsepLogInfo 
 
int KsepLogInfo(int a1, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp-8h] BYREF

  va_start(varg_r2, a2);
  return KsepLogEtwMessage(a1, 2, a2, (int *)varg_r2);
}
