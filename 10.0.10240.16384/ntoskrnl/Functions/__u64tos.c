// __u64tos 
 
__int64 __fastcall _u64tos(__int64 a1)
{
  char v1; // r2
  unsigned int v2; // r1
  int v3; // r0
  char v4; // r2
  int v5; // r12
  int v6; // r1
  unsigned int v13; // r3
  __int64 v14; // [sp+0h] [bp-8h]

  v14 = a1;
  if ( HIDWORD(a1) )
  {
    v4 = __clz(HIDWORD(a1));
    HIDWORD(a1) = (HIDWORD(a1) << v4) | ((unsigned int)a1 >> (32 - v4));
    v3 = (_DWORD)a1 << v4;
  }
  else
  {
    v1 = __clz(a1);
    v2 = (_DWORD)a1 << v1;
    if ( !((_DWORD)a1 << v1) )
      return v14;
    v3 = 0;
    v4 = v1 + 32;
  }
  v5 = v2 << 23;
  v6 = (v2 >> 8) & 0x807FFFFF | ((unsigned __int8)(-66 - v4) << 23);
  if ( (v5 & 0x40000000) != 0 )
  {
    v5 &= 0xBFFFFFFF;
    if ( v5 )
      ++v6;
  }
  if ( (2 * v5) | v3 )
  {
    __asm { VMRS            R3, FPSCR }
    v13 = _R3 | 1;
    if ( (v13 & (v13 >> 8)) << 27 )
      _i64tofp_exception_helper(v3, v6, 591873, v13);
  }
  return v14;
}
