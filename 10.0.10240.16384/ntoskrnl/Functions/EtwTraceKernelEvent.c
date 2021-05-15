// EtwTraceKernelEvent 
 
int *__fastcall EtwTraceKernelEvent(int *result, int a2, unsigned int a3, int a4, int a5)
{
  int v5; // lr
  unsigned int v6; // r5
  unsigned int v8; // r6
  int v9; // r2
  int *i; // [sp+10h] [bp-28h]

  v5 = a4;
  v6 = EtwpActiveSystemLoggers;
  v8 = __clz(__rbit(EtwpActiveSystemLoggers));
  v9 = a2;
  for ( i = result; 1 != (unsigned __int8)(v8 >> 5); v8 = __clz(__rbit(v6)) )
  {
    v6 &= v6 - 1;
    if ( &EtwpGroupMasks[8 * v8] )
    {
      if ( (EtwpGroupMasks[8 * v8 + (a3 >> 29)] & a3 & 0x1FFFFFFF) != 0 )
      {
        EtwpLogKernelEvent(result, (unsigned __int16)EtwpSystemLogger[2 * v8], v9, v5, a5);
        v5 = a4;
        v9 = a2;
        result = i;
      }
    }
  }
  return result;
}
