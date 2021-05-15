// ExpWnfStartKernelDispatcher 
 
int __fastcall ExpWnfStartKernelDispatcher(int a1)
{
  int result; // r0
  unsigned int *v2; // r2
  unsigned int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1

  if ( a1 )
    return ExpWnfDispatchKernelSubscription();
  __dmb(0xBu);
  v2 = (unsigned int *)(ExpWnfDispatcher + 20);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 2, v2) );
  __dmb(0xBu);
  result = 3;
  v4 = (unsigned int *)(ExpWnfDispatcher + 20);
  do
    v5 = __ldrex(v4);
  while ( v5 == 2 && __strex(3u, v4) );
  __dmb(0xBu);
  if ( v5 == 2 )
    result = ExQueueWorkItem((_DWORD *)(ExpWnfDispatcher + 4), 1);
  return result;
}
