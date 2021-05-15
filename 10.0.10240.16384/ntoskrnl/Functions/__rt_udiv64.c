// __rt_udiv64 
 
int __fastcall _rt_udiv64(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // kr00_8
  signed int v3; // r1
  signed int v4; // r0
  bool v5; // cc
  unsigned int v6; // r0
  __int64 v7; // r4
  char v8; // r0
  unsigned int v9; // r1
  unsigned __int64 v10; // r4
  int v11; // off

  if ( !a1 )
    __brkdiv0();
  if ( HIDWORD(a1) | HIDWORD(a2) )
  {
    v2 = a1;
    v3 = __clz(HIDWORD(a2));
    if ( !HIDWORD(a2) )
      v3 = __clz(a2) + 32;
    v4 = __clz(HIDWORD(v2));
    if ( !HIDWORD(v2) )
      v4 = __clz(v2) + 32;
    v5 = v4 < v3;
    v6 = v4 - v3;
    if ( v5 )
    {
      LODWORD(a1) = 0;
    }
    else
    {
      v7 = v2;
      if ( v6 >= 0x20 )
      {
        HIDWORD(v7) = v2;
        LODWORD(v7) = 0;
      }
      v8 = v6 & 0x1F;
      v9 = (unsigned int)v7 >> (32 - v8);
      LODWORD(v7) = (_DWORD)v7 << v8;
      HIDWORD(v10) = (HIDWORD(v7) << v8) | v9;
      a1 = 0i64;
      while ( 1 )
      {
        if ( v10 <= a2 )
        {
          a2 -= v10;
          ++a1;
        }
        if ( v10 == v2 )
          break;
        v11 = (a1 + (unsigned __int64)(unsigned int)a1) >> 32;
        LODWORD(a1) = 2 * a1;
        HIDWORD(a1) += v11;
        v10 >>= 1;
      }
    }
  }
  else
  {
    LODWORD(a1) = (unsigned int)a2 / (unsigned int)a1;
  }
  return a1;
}
