// PspProcessRundownWorker 
 
int PspProcessRundownWorker()
{
  unsigned int v0; // r2
  int i; // r0
  unsigned __int8 *v2; // r3
  unsigned int v3; // r1
  int *v4; // r0
  int v5; // r4
  unsigned int *v6; // r4
  int result; // r0
  unsigned int v8; // r1

  do
  {
    __dmb(0xBu);
    do
      v0 = __ldrex((unsigned int *)PspRundownNeededCount);
    while ( __strex(1u, (unsigned int *)PspRundownNeededCount) );
    __dmb(0xBu);
    for ( i = 0; ; i = v5 )
    {
      v4 = PsGetNextProcess(i);
      v5 = (int)v4;
      if ( !v4 )
        break;
      __dmb(0xBu);
      v2 = (unsigned __int8 *)v4 + 189;
      do
        v3 = __ldrex(v2);
      while ( __strex(v3 & 0xFE, v2) );
      __dmb(0xBu);
      if ( (v3 & 1) != 0 )
      {
        PspRundownSingleProcess((unsigned int *)v4, 0);
        ObfDereferenceObjectWithTag(v5);
      }
    }
    while ( PspRundownProcessCache )
    {
      __dmb(0xBu);
      do
        v6 = (unsigned int *)__ldrex((unsigned int *)&PspRundownProcessCache);
      while ( __strex(0, (unsigned int *)&PspRundownProcessCache) );
      __dmb(0xBu);
      if ( !v6 )
        break;
      PspRundownSingleProcess(v6, 0);
      ObfDereferenceObjectWithTag((int)v6);
    }
    __dmb(0xBu);
    result = 0;
    do
      v8 = __ldrex((unsigned int *)PspRundownNeededCount);
    while ( v8 == 1 && __strex(0, (unsigned int *)PspRundownNeededCount) );
    __dmb(0xBu);
  }
  while ( v8 != 1 );
  return result;
}
