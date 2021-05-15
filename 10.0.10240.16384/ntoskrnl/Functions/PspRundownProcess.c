// PspRundownProcess 
 
unsigned int __fastcall PspRundownProcess(unsigned int a1)
{
  unsigned int result; // r0
  unsigned int v3; // r4
  unsigned __int8 *v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r2
  int *v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r2

  result = ExAcquireRundownProtectionEx((int *)(a1 + 172), 0);
  if ( result )
  {
    result = ObfReferenceObjectWithTag(a1);
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&PspRundownProcessCache);
    while ( !v3 && __strex(a1, (unsigned int *)&PspRundownProcessCache) );
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v3 )
    {
      v4 = (unsigned __int8 *)(a1 + 189);
      do
        result = __ldrex(v4);
      while ( __strex(result | 1, v4) );
      __dmb(0xBu);
      if ( (result & 1) != 0 )
        return ObfDereferenceObjectWithTag(a1);
      __dmb(0xBu);
      do
      {
        v5 = __ldrex((unsigned int *)PspRundownNeededCount);
        v6 = v5 + 1;
      }
      while ( __strex(v6, (unsigned int *)PspRundownNeededCount) );
      __dmb(0xBu);
      if ( v6 == 1 )
      {
        v7 = &PspProcessRundownWorkItem;
        return ExQueueWorkItem(v7, 3);
      }
    }
    else
    {
      do
      {
        v8 = __ldrex(&PspRundownNeededCountCache);
        v9 = v8 + 1;
      }
      while ( __strex(v9, &PspRundownNeededCountCache) );
      __dmb(0xBu);
      if ( v9 == 1 )
      {
        v7 = &PspProcessRundownCacheWorkItem;
        return ExQueueWorkItem(v7, 3);
      }
    }
  }
  return result;
}
