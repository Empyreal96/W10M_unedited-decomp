// PerfInfoLogInterrupt 
 
unsigned int __fastcall PerfInfoLogInterrupt(int a1, int a2, int a3)
{
  unsigned int result; // r0
  int v5; // r8
  unsigned int v6; // r4
  int v7; // r1
  int v8[3]; // [sp+8h] [bp-50h] BYREF
  unsigned int i; // [sp+14h] [bp-44h]
  int v10[16]; // [sp+18h] [bp-40h] BYREF

  if ( *(_BYTE *)(a1 + 49) )
  {
    if ( *(_DWORD *)(a1 + 16) )
      return sub_53FB74();
    v5 = 3907;
    v8[0] = *(_DWORD *)(a1 + 12);
  }
  else
  {
    v5 = 3935;
    v8[0] = *(_DWORD *)(a1 + 12);
  }
  v10[4] = (int)v8;
  v10[6] = 8;
  v10[7] = 0;
  v8[1] = a2;
  v10[5] = 0;
  v6 = EtwpActiveSystemLoggers;
  result = __clz(__rbit(EtwpActiveSystemLoggers));
  for ( i = result; 1 != (unsigned __int8)(result >> 5); i = result )
  {
    v6 &= v6 - 1;
    if ( &EtwpGroupMasks[8 * result] )
    {
      if ( (EtwpGroupMasks[8 * result + 1] & 0x4000) != 0 )
      {
        v10[0] = a3 + 8 * (unsigned __int16)EtwpSystemLogger[2 * result + 1];
        v10[1] = 0;
        v7 = (unsigned __int16)EtwpSystemLogger[2 * result];
        v10[2] = 8;
        v10[3] = 0;
        EtwpLogKernelEvent(v10, v7, 2, v5, 4196866);
      }
    }
    result = __clz(__rbit(v6));
  }
  return result;
}
