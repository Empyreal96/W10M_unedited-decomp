// PspProcessRundownWorkerSingle 
 
__int64 PspProcessRundownWorkerSingle()
{
  unsigned int v0; // r2
  unsigned int *v1; // r5
  __int64 result; // r0
  unsigned int v3; // r2

  do
  {
    __dmb(0xBu);
    do
      v0 = __ldrex(&PspRundownNeededCountCache);
    while ( __strex(1u, &PspRundownNeededCountCache) );
    __dmb(0xBu);
    while ( PspRundownProcessCache )
    {
      __dmb(0xBu);
      do
        v1 = (unsigned int *)__ldrex((unsigned int *)&PspRundownProcessCache);
      while ( __strex(0, (unsigned int *)&PspRundownProcessCache) );
      __dmb(0xBu);
      if ( !v1 )
        break;
      PspRundownSingleProcess(v1, 0);
      LODWORD(result) = ObfDereferenceObjectWithTag((int)v1);
    }
    __dmb(0xBu);
    HIDWORD(result) = 0;
    do
      v3 = __ldrex(&PspRundownNeededCountCache);
    while ( v3 == 1 && __strex(0, &PspRundownNeededCountCache) );
    __dmb(0xBu);
  }
  while ( v3 != 1 );
  return result;
}
