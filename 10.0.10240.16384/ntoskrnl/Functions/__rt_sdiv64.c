// __rt_sdiv64 
 
int __fastcall _rt_sdiv64(__int64 a1, __int64 a2)
{
  unsigned int v2; // r4
  bool v3; // cf
  int v4; // r7
  __int64 v5; // kr00_8
  signed int v6; // r1
  signed int v7; // r0
  bool v8; // cc
  unsigned int v9; // r0
  __int64 v10; // r4
  char v11; // r0
  unsigned int v12; // r1
  unsigned __int64 v13; // r4
  int v14; // off

  v2 = HIDWORD(a1) & 0x80000000;
  if ( a1 < 0 )
  {
    v3 = (_DWORD)a1 == 0;
    LODWORD(a1) = -(int)a1;
    HIDWORD(a1) -= 2 * HIDWORD(a1) + !v3;
  }
  v4 = v2 ^ (SHIDWORD(a2) >> 31);
  if ( a2 < 0 )
  {
    v3 = (_DWORD)a2 == 0;
    LODWORD(a2) = -(int)a2;
    HIDWORD(a2) -= 2 * HIDWORD(a2) + !v3;
  }
  if ( !a1 )
    __brkdiv0();
  if ( HIDWORD(a1) | HIDWORD(a2) )
  {
    v5 = a1;
    v6 = __clz(HIDWORD(a2));
    if ( !HIDWORD(a2) )
      v6 = __clz(a2) + 32;
    v7 = __clz(HIDWORD(v5));
    if ( !HIDWORD(v5) )
      v7 = __clz(v5) + 32;
    v8 = v7 < v6;
    v9 = v7 - v6;
    if ( v8 )
    {
      LODWORD(a1) = 0;
    }
    else
    {
      v10 = v5;
      if ( v9 >= 0x20 )
      {
        HIDWORD(v10) = v5;
        LODWORD(v10) = 0;
      }
      v11 = v9 & 0x1F;
      v12 = (unsigned int)v10 >> (32 - v11);
      LODWORD(v10) = (_DWORD)v10 << v11;
      HIDWORD(v13) = (HIDWORD(v10) << v11) | v12;
      a1 = 0i64;
      while ( 1 )
      {
        if ( v13 <= a2 )
        {
          a2 -= v13;
          ++a1;
        }
        if ( v13 == v5 )
          break;
        v14 = (a1 + (unsigned __int64)(unsigned int)a1) >> 32;
        LODWORD(a1) = 2 * a1;
        HIDWORD(a1) += v14;
        v13 >>= 1;
      }
    }
  }
  else
  {
    LODWORD(a1) = (unsigned int)a2 / (unsigned int)a1;
  }
  if ( __CFSHL__(v4, 1) )
    LODWORD(a1) = -(int)a1;
  return a1;
}
