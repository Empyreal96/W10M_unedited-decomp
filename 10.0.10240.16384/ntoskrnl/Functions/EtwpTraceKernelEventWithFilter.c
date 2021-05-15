// EtwpTraceKernelEventWithFilter 
 
int __fastcall EtwpTraceKernelEventWithFilter(int result, int a2, int a3, int a4, int a5)
{
  int *v7; // r10
  int v8; // r7
  unsigned int i; // r6

  v7 = (int *)result;
  v8 = EtwpActiveSystemLoggers & a3;
  for ( i = __clz(__rbit(EtwpActiveSystemLoggers & a3)); 1 != (unsigned __int8)(i >> 5); i = __clz(__rbit(v8)) )
  {
    v8 &= v8 - 1;
    result = EtwpLogKernelEvent(v7, (unsigned __int16)EtwpSystemLogger[2 * i], a2, a4, a5);
  }
  return result;
}
