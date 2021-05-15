// RtlFindRange 
 
int __fastcall RtlFindRange(int a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4, __int64 a5, char a6, unsigned __int8 a7, int a8, int a9, unsigned __int64 *a10)
{
  __int64 v12; // r2
  unsigned __int64 v13; // r4
  int result; // r0
  char v16[8]; // [sp+38h] [bp-38h] BYREF
  char v17[48]; // [sp+40h] [bp-30h] BYREF

  if ( !a5 )
    __brkdiv0();
  _rt_udiv64(a5, a3 - a4 + 1);
  v13 = a3 - a4 + 1 - v12;
  if ( a2 > a3 || a3 - a2 < a4 - 1 || a2 + a5 < a2 || v13 < a2 || !a4 )
    return -1073741811;
  RtlGetLastRange(a1, v17, v16);
  if ( !RtlpIsRangeAvailable(
          v17,
          a8,
          v13,
          HIDWORD(v13),
          v13 + a4 - 1,
          (v13 + a4 - 1) >> 32,
          a7,
          a6 & 1,
          a6 & 2,
          0,
          a8,
          a9) )
    return sub_80E5A4();
  result = 0;
  *a10 = v13;
  return result;
}
