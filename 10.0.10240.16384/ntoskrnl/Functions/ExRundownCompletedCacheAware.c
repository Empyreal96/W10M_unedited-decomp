// ExRundownCompletedCacheAware 
 
unsigned int __fastcall ExRundownCompletedCacheAware(_DWORD *a1)
{
  unsigned int result; // r0
  unsigned int i; // r5
  unsigned int *v4; // r2
  unsigned int v5; // r1

  result = a1[3];
  for ( i = 0; i < result; ++i )
  {
    if ( !result )
      __brkdiv0();
    v4 = (unsigned int *)(*a1 + i % result * a1[2]);
    __dmb(0xBu);
    do
      v5 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    result = a1[3];
  }
  return result;
}
