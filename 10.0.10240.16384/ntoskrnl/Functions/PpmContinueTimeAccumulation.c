// PpmContinueTimeAccumulation 
 
int __fastcall PpmContinueTimeAccumulation(int a1)
{
  int result; // r0
  unsigned __int64 *v2; // r6
  unsigned __int64 v3; // kr00_8
  unsigned __int64 v4; // kr08_8

  if ( ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 == a1 )
  {
    PpmContinueActiveTimeAccumulation(a1);
    return 1;
  }
  __dmb(0xBu);
  v2 = (unsigned __int64 *)(a1 + 2968);
  do
    v3 = __ldrexd(v2);
  while ( __strexd(v3, v2) );
  __dmb(0xBu);
  if ( !v3 )
    return 0;
  result = PpmUpdatePerformanceFeedback(a1, 0, 1, 0);
  if ( result )
  {
    __dmb(0xBu);
    do
      v4 = __ldrexd(v2);
    while ( __strexd(v4, v2) );
    __dmb(0xBu);
    return __PAIR64__(v3, HIDWORD(v3)) == __PAIR64__(v4, HIDWORD(v4));
  }
  return result;
}
