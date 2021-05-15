// ExpTimeZoneWork 
 
int ExpTimeZoneWork()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r2

  do
  {
    result = ZwSetSystemTime();
    __dmb(0xBu);
    do
    {
      v1 = __ldrex(ExpOkToTimeZoneRefresh);
      v2 = v1 - 1;
    }
    while ( __strex(v2, ExpOkToTimeZoneRefresh) );
    __dmb(0xBu);
  }
  while ( v2 );
  return result;
}
