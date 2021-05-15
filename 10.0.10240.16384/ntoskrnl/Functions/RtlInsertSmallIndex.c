// RtlInsertSmallIndex 
 
int __fastcall RtlInsertSmallIndex(__int64 a1, unsigned __int64 a2)
{
  signed int v3; // r1
  signed int v4; // r0
  bool v5; // cc
  unsigned int v6; // r0
  __int64 v7; // r4
  char v8; // r0
  unsigned int v9; // r1
  unsigned __int64 v10; // r4
  __int64 v11; // r0
  int v12; // off

  if ( !a1 )
    RtlpxFatalFilter();
  if ( HIDWORD(a1) | HIDWORD(a2) )
  {
    v3 = __clz(HIDWORD(a2));
    if ( !HIDWORD(a2) )
      v3 = __clz(a2) + 32;
    v4 = __clz(HIDWORD(a1));
    if ( !HIDWORD(a1) )
      v4 = __clz(a1) + 32;
    v5 = v4 < v3;
    v6 = v4 - v3;
    if ( v5 )
    {
      LODWORD(v11) = 0;
    }
    else
    {
      v7 = a1;
      if ( v6 >= 0x20 )
      {
        HIDWORD(v7) = a1;
        LODWORD(v7) = 0;
      }
      v8 = v6 & 0x1F;
      v9 = (unsigned int)v7 >> (32 - v8);
      LODWORD(v7) = (_DWORD)v7 << v8;
      HIDWORD(v10) = (HIDWORD(v7) << v8) | v9;
      v11 = 0i64;
      while ( 1 )
      {
        if ( v10 <= a2 )
        {
          a2 -= v10;
          ++v11;
        }
        if ( v10 == a1 )
          break;
        v12 = (v11 + (unsigned __int64)(unsigned int)v11) >> 32;
        LODWORD(v11) = 2 * v11;
        HIDWORD(v11) += v12;
        v10 >>= 1;
      }
    }
  }
  else
  {
    LODWORD(v11) = FsRtlpNotifySharedOplockBatchBreak(a1, a2);
  }
  return v11;
}
