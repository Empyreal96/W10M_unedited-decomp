// ExpAcquireFastMutexContended 
 
int __fastcall ExpAcquireFastMutexContended(int result, int a2)
{
  unsigned int *v2; // r5
  int v4; // r8
  int v5; // r7
  unsigned int i; // r4
  unsigned int v7; // r1
  unsigned int v8; // r2

  v2 = (unsigned int *)result;
  v4 = 4;
  ++*(_DWORD *)(result + 8);
  v5 = 1;
LABEL_2:
  for ( i = *v2; ; i = v7 )
  {
    __dmb(0xBu);
    if ( (i & 1) != 0 )
      break;
    v8 = i + v4;
    do
      v7 = __ldrex(v2);
    while ( v7 == i && __strex(v8, v2) );
    __dmb(0xBu);
    if ( v7 == i )
    {
      if ( a2 )
        KeAbPreWait(a2, v7, v8);
      result = KeWaitForSingleObject((unsigned int)(v2 + 3), 34, 0, 0, 0);
      __pld(v2);
      v5 = 3;
      v4 = 2;
      if ( a2 )
      {
        result = KeAbPreAcquire((unsigned int)v2, a2, 0);
        a2 = result;
      }
      goto LABEL_2;
    }
LABEL_16:
    ;
  }
  do
    v7 = __ldrex(v2);
  while ( v7 == i && __strex(i ^ v5, v2) );
  __dmb(0xBu);
  if ( v7 != i )
    goto LABEL_16;
  return result;
}
