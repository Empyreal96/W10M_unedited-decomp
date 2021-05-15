// __u64tod 
 
__int64 __fastcall _u64tod(__int64 a1)
{
  unsigned int v1; // r2
  unsigned int v2; // r2
  int v3; // r12
  __int64 v4; // r0
  __int64 v11; // [sp+0h] [bp-8h]

  v11 = a1;
  if ( HIDWORD(a1) )
  {
    v2 = __clz(HIDWORD(a1));
    HIDWORD(a1) = (HIDWORD(a1) << v2) | ((unsigned int)a1 >> (32 - v2));
    LODWORD(a1) = (_DWORD)a1 << v2;
  }
  else
  {
    v1 = __clz(a1);
    HIDWORD(a1) = (_DWORD)a1 << v1;
    if ( !((_DWORD)a1 << v1) )
      return v11;
    LODWORD(a1) = 0;
    v2 = v1 + 32;
  }
  v3 = (_DWORD)a1 << 20;
  LODWORD(a1) = a1 >> 11;
  HIDWORD(v4) = (HIDWORD(a1) >> 11) & 0x800FFFFF | (((1086 - v2) & 0x7FF) << 20);
  if ( (v3 & 0x40000000) != 0 )
  {
    v3 &= 0xBFFFFFFF;
    if ( v3 )
      ++v4;
  }
  if ( 2 * v3 )
  {
    __asm { VMRS            R3, FPSCR }
    if ( ((_R3 | 1) & ((_R3 | 1u) >> 8)) << 27 )
      _i64tofp_exception_helper(v4, HIDWORD(v4), 17369089);
  }
  return v11;
}
