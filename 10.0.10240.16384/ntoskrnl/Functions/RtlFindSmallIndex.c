// RtlFindSmallIndex 
 
int __fastcall RtlFindSmallIndex(signed int a1, signed int a2)
{
  unsigned int v2; // r3
  int v3; // r12
  signed int v4; // r0
  signed int v5; // r3
  bool v6; // cc
  int (__fastcall *v7)(_DWORD); // r3
  int result; // r0

  v2 = a1 & 0x80000000;
  if ( a1 < 0 )
    a1 = -a1;
  v3 = v2 ^ (a2 >> 31);
  if ( a2 < 0 )
    a2 = -a2;
  if ( !a1 )
    RtlpxFatalFilter();
  v4 = __clz(a1);
  v5 = __clz(a2);
  v6 = v4 < v5;
  v7 = (int (__fastcall *)(_DWORD))((char *)&loc_5FB3E6 - 2 * (v4 - v5) + -8 * (v4 - v5));
  result = 0;
  if ( !v6 )
    return v7(0);
  if ( __CFSHL__(v3, 1) )
    result = 0;
  return result;
}
