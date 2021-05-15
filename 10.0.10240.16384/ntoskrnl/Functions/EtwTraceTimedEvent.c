// EtwTraceTimedEvent 
 
int __fastcall EtwTraceTimedEvent(int result, unsigned int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v7; // r4
  int v8; // lr
  unsigned int v9; // r5
  int v10; // r1
  int v11; // [sp+Ch] [bp-44h]
  int v12[16]; // [sp+10h] [bp-40h] BYREF

  v12[6] = a4;
  v12[4] = a3;
  v12[5] = 0;
  v12[7] = 0;
  v7 = EtwpActiveSystemLoggers;
  v8 = result;
  v9 = __clz(__rbit(EtwpActiveSystemLoggers));
  v11 = result;
  if ( 1 != (unsigned __int8)(v9 >> 5) )
  {
    result = a5;
    do
    {
      v7 &= v7 - 1;
      if ( &EtwpGroupMasks[8 * v9] )
      {
        if ( (EtwpGroupMasks[8 * v9 + (a2 >> 29)] & a2 & 0x1FFFFFFF) != 0 )
        {
          v12[0] = a6 + 8 * (unsigned __int16)EtwpSystemLogger[2 * v9 + 1];
          v12[1] = 0;
          v12[2] = 8;
          v10 = (unsigned __int16)EtwpSystemLogger[2 * v9];
          v12[3] = 0;
          EtwpLogKernelEvent(v12, v10, 2, v8, result);
          v8 = v11;
          result = a5;
        }
      }
      v9 = __clz(__rbit(v7));
    }
    while ( 1 != (unsigned __int8)(v9 >> 5) );
  }
  return result;
}
