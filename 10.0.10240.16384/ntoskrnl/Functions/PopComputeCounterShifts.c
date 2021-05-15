// PopComputeCounterShifts 
 
unsigned int __fastcall PopComputeCounterShifts(unsigned int result, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v6; // r1
  unsigned int v7; // r3
  int v8; // r1
  unsigned int v9; // r3
  unsigned int v10; // r2

  *a3 = 0;
  v6 = __clz(a2);
  *a4 = 0;
  v7 = 31 - v6;
  v8 = (unsigned __int8)(1 - (v6 >> 5));
  if ( v8 )
    return sub_5290C8(result, v8, 1, v7);
  v9 = __clz(result);
  v10 = 31 - v9;
  if ( 1 != (unsigned __int8)(v9 >> 5) )
  {
    if ( v10 > 0xE )
      *a3 = 17 - v9;
    if ( v10 > 0x13 )
      *a4 = 12 - v9;
  }
  return result;
}
