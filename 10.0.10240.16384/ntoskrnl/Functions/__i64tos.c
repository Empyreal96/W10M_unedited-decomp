// __i64tos 
 
__int64 __fastcall _i64tos(__int64 a1)
{
  char v2; // r2
  char v3; // r2
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r12
  unsigned int v7; // r1
  __int64 v13; // [sp+0h] [bp-8h]

  v13 = a1;
  _ZF = HIDWORD(a1) == 0;
  if ( a1 < 0 )
  {
    LODWORD(a1) = -(int)a1;
    HIDWORD(a1) -= 2 * HIDWORD(a1) + !__CFSHL__(HIDWORD(a1), 1);
    _ZF = HIDWORD(a1) == 0;
  }
  if ( _ZF )
  {
    v2 = __clz(a1);
    v4 = (_DWORD)a1 << v2;
    if ( !((_DWORD)a1 << v2) )
      return v13;
    v5 = 0;
    v3 = v2 + 32;
  }
  else
  {
    v3 = __clz(HIDWORD(a1));
    HIDWORD(a1) = (HIDWORD(a1) << v3) | ((unsigned int)a1 >> (32 - v3));
    v5 = (_DWORD)a1 << v3;
  }
  v6 = v4 << 23;
  v7 = ((v4 >> 8) & 0x807FFFFF | ((unsigned __int8)(-66 - v3) << 23)) & 0x7FFFFFFF | ((v13 < 0) << 31);
  if ( (v6 & 0x40000000) != 0 )
  {
    v6 &= 0xBFFFFFFF;
    if ( v6 )
      ++v7;
  }
  if ( (2 * v6) | v5 )
  {
    __asm { VMRS            R3, FPSCR }
    if ( ((_R3 | 1) & ((_R3 | 1u) >> 8)) << 27 )
      _i64tofp_exception_helper(v5, v7, 395265);
  }
  return v13;
}
