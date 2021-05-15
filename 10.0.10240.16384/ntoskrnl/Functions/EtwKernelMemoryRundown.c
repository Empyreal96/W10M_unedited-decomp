// EtwKernelMemoryRundown 
 
_BYTE *EtwKernelMemoryRundown()
{
  _BYTE *result; // r0
  unsigned int v1; // r4
  unsigned int i; // r2
  int v3; // [sp+8h] [bp-30h] BYREF
  int v4[7]; // [sp+Ch] [bp-2Ch] BYREF

  v3 = 0;
  result = memset(v4, 0, sizeof(v4));
  v4[0] |= 8u;
  v1 = EtwpActiveSystemLoggers;
  for ( i = __clz(__rbit(EtwpActiveSystemLoggers)); 1 != (unsigned __int8)(i >> 5); i = __clz(__rbit(v1)) )
  {
    v1 &= v1 - 1;
    if ( &EtwpGroupMasks[8 * i] )
    {
      if ( (EtwpGroupMasks[8 * i + 5] & 1) != 0 )
        result = (_BYTE *)EtwpKernelTraceRundown(&v3, (unsigned __int16)EtwpSystemLogger[2 * i], 0);
    }
  }
  return result;
}
