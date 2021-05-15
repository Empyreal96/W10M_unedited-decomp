// RtlEnlargedUnsignedDivide 
 
int __fastcall RtlEnlargedUnsignedDivide(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned __int64 v4; // r2
  int result; // r0
  int v7; // r2
  _DWORD *varg_r3; // [sp+24h] [bp+14h]

  varg_r3 = a4;
  LODWORD(v4) = a1;
  HIDWORD(v4) = a2;
  result = _rt_udiv64((unsigned int)dword_989680, v4);
  if ( a4 )
    *a4 = v7;
  return result;
}
