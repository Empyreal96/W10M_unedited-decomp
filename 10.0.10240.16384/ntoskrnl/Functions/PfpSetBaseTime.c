// PfpSetBaseTime 
 
int __fastcall PfpSetBaseTime(int a1, _DWORD *a2)
{
  _DWORD *v4; // r0
  int result; // r0
  __int64 v6; // r0
  int v7; // r2
  int v8[2]; // [sp+8h] [bp-20h] BYREF
  __int64 v9[3]; // [sp+10h] [bp-18h] BYREF

  v4 = KeQuerySystemTime(v9);
  if ( (((unsigned __int64)(v9[0] - 126227808000000000i64) >> 32) & 0x80000000) != 0i64 )
    return sub_8178BC(v4, LODWORD(v9[0]) + 929185792);
  LODWORD(v6) = _rt_sdiv64(10000i64, v9[0] - 126227808000000000i64);
  v8[0] = v6 >> 10;
  result = PfpSetParameter(a1, L"BaseTime", v7, v8, 4);
  if ( result < 0 )
  {
    LODWORD(v9[0]) = 4;
    result = PfpGetParameter(a1, L"BaseTime", 4, v8, v9);
    if ( result < 0 )
      *a2 = 0;
  }
  *a2 = v8[0];
  return result;
}
