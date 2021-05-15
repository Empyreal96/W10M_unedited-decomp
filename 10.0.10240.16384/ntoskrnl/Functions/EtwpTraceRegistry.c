// EtwpTraceRegistry 
 
int __fastcall EtwpTraceRegistry(int result, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v7; // r5
  __int16 v8; // lr
  unsigned int v9; // r6
  int v10; // [sp+10h] [bp-30h]
  int v11; // [sp+14h] [bp-2Ch]
  __int16 i; // [sp+18h] [bp-28h]

  v7 = EtwpActiveSystemLoggers;
  v10 = a3;
  v11 = a2;
  v8 = result;
  v9 = __clz(__rbit(EtwpActiveSystemLoggers));
  for ( i = result; 1 != (unsigned __int8)(v9 >> 5); v9 = __clz(__rbit(v7)) )
  {
    v7 &= v7 - 1;
    if ( &EtwpGroupMasks[8 * v9] )
    {
      if ( (EtwpGroupMasks[8 * v9] & 0x20000) != 0 )
      {
        result = EtwpLogRegistryEvent(
                   (unsigned __int16)EtwpSystemLogger[2 * v9],
                   v8,
                   a3,
                   a4,
                   a5,
                   (int *)(a2 + 8 * (unsigned __int16)EtwpSystemLogger[2 * v9 + 1]),
                   a6);
        a2 = v11;
        v8 = i;
        a3 = v10;
      }
    }
  }
  return result;
}
