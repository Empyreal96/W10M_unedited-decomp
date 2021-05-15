// __i64tod 
 
__int64 __fastcall _i64tod(__int64 a1)
{
  __int16 v2; // r2
  __int16 v3; // r2
  int v4; // r12
  __int64 v5; // r0
  unsigned int v11; // r3
  __int64 v12; // [sp+0h] [bp-8h]

  v12 = a1;
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
    HIDWORD(a1) = (_DWORD)a1 << v2;
    if ( !((_DWORD)a1 << v2) )
      return v12;
    LODWORD(a1) = 0;
    v3 = v2 + 32;
  }
  else
  {
    v3 = __clz(HIDWORD(a1));
    HIDWORD(a1) = (HIDWORD(a1) << v3) | ((unsigned int)a1 >> (32 - v3));
    LODWORD(a1) = (_DWORD)a1 << v3;
  }
  v4 = (_DWORD)a1 << 20;
  LODWORD(a1) = a1 >> 11;
  HIDWORD(v5) = ((HIDWORD(a1) >> 11) & 0x800FFFFF | (((1086 - v3) & 0x7FF) << 20)) & 0x7FFFFFFF | ((v12 < 0) << 31);
  if ( (v4 & 0x40000000) != 0 )
  {
    v4 &= 0xBFFFFFFF;
    if ( v4 )
      ++v5;
  }
  if ( 2 * v4 )
  {
    __asm { VMRS            R3, FPSCR }
    v11 = _R3 | 1;
    if ( (v11 & (v11 >> 8)) << 27 )
      _i64tofp_exception_helper(v5, SHIDWORD(v5), 17172481, v11);
  }
  return v12;
}
