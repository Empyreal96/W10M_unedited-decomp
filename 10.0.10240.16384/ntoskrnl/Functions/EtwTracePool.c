// EtwTracePool 
 
int __fastcall EtwTracePool(int result, __int16 a2, int a3, unsigned int a4, unsigned int a5)
{
  int v5; // r4
  unsigned int v6; // r1
  int v9; // r9
  int v10; // r10
  unsigned int v11; // r6
  unsigned int v12; // r5
  _DWORD *v13; // r4
  int v14; // [sp+Ch] [bp-5Ch] BYREF
  int v15; // [sp+10h] [bp-58h]
  _DWORD v16[4]; // [sp+18h] [bp-50h] BYREF
  int v17[16]; // [sp+28h] [bp-40h] BYREF

  v5 = a2 & 0x26D;
  v6 = a5;
  v15 = a3;
  v9 = result;
  if ( a5 <= 0xFF0 )
  {
    if ( (dword_682604 & 0x40) == 0 )
      return result;
  }
  else
  {
    v5 |= 0x10000000u;
  }
  if ( result == 3618 && (v5 & 1) == 0 )
  {
    result = MmIsNonPagedPoolNx(a4);
    if ( result )
      v5 |= 0x200u;
  }
  v10 = 1;
  if ( (v5 & 0x20) != 0 )
  {
    result = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v17[4] = (int)&v14;
    v17[5] = 0;
    v17[6] = 4;
    v17[7] = 0;
    v6 = a5;
    v9 = (unsigned __int16)(v9 + 1);
    v14 = result;
    v10 = 2;
  }
  v16[3] = a4;
  v17[0] = (int)v16;
  v17[1] = 0;
  v17[2] = 16;
  v17[3] = 0;
  v16[0] = v5;
  v16[1] = a3;
  v16[2] = v6;
  v11 = EtwpActiveSystemLoggers;
  v12 = __clz(__rbit(EtwpActiveSystemLoggers));
  if ( 1 != (unsigned __int8)(v12 >> 5) )
  {
    while ( 1 )
    {
      v11 &= v11 - 1;
      v13 = &EtwpGroupMasks[8 * v12];
      if ( !v13 || (v13[1] & 0x40) == 0 )
        goto LABEL_15;
      result = EtwpCheckPoolTagFilters(v12, v15);
      if ( !result )
        break;
LABEL_18:
      result = EtwpLogKernelEvent(v17, (unsigned __int16)EtwpSystemLogger[2 * v12], v10, v9, 20978434);
LABEL_19:
      v12 = __clz(__rbit(v11));
      v6 = a5;
      if ( 1 == (unsigned __int8)(v12 >> 5) )
        return result;
    }
    v6 = a5;
LABEL_15:
    if ( !v13 || (v13[1] & 1) == 0 || v6 <= 0xFF0 )
      goto LABEL_19;
    goto LABEL_18;
  }
  return result;
}
