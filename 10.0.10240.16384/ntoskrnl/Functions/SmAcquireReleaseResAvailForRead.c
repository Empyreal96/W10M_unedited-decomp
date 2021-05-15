// SmAcquireReleaseResAvailForRead 
 
int __fastcall SmAcquireReleaseResAvailForRead(unsigned int a1, int a2, int a3)
{
  unsigned int v5; // r1
  int result; // r0
  unsigned int v7; // r1

  if ( a3 )
  {
    if ( dword_636CBC == a1 )
    {
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&dword_636CBC);
      while ( __strex(0, (unsigned int *)&dword_636CBC) );
      __dmb(0xBu);
    }
    else
    {
      MmStoreReleaseResidentAvailableForRead(a2);
    }
    return 1;
  }
  result = MmStoreChargeResidentAvailableForRead(a2);
  if ( result )
    return result;
  if ( !dword_636CBC && a2 == 1 )
  {
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&dword_636CBC);
    while ( !v7 && __strex(a1, (unsigned int *)&dword_636CBC) );
    __dmb(0xBu);
    if ( !v7 )
      return 1;
  }
  return 0;
}
