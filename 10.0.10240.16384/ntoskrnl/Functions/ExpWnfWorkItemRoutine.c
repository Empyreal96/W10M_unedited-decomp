// ExpWnfWorkItemRoutine 
 
int ExpWnfWorkItemRoutine()
{
  unsigned int v0; // r2
  unsigned int *v1; // r2
  unsigned int v2; // r0
  int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  do
  {
    __dmb(0xBu);
    v1 = (unsigned int *)(ExpWnfDispatcher + 20);
    do
      v2 = __ldrex(v1);
    while ( __strex(v2 & 0xFFFFFFFD, v1) );
    __dmb(0xBu);
    v3 = ExpWnfDispatchKernelSubscription();
    __dmb(0xBu);
    v4 = (unsigned int *)(ExpWnfDispatcher + 20);
    do
      v5 = __ldrex(v4);
    while ( v5 == 1 && __strex(0, v4) );
    __dmb(0xBu);
  }
  while ( v5 != 1 );
  return sub_7F3358(v3);
}
