// PopBatteryCapacityToRate 
 
int __fastcall PopBatteryCapacityToRate(int result, __int64 a2)
{
  int v3; // r4
  int v4; // r5
  unsigned __int64 v5; // r2
  __int64 v6; // r0

  if ( !a2 )
    result = 0;
  v3 = HIDWORD(a2);
  v4 = a2;
  if ( a2 )
  {
    HIDWORD(v6) = HIDWORD(a2);
    v5 = 3600000000i64 * (unsigned int)result;
    LODWORD(v6) = v4;
    if ( !v4 && !v3 )
      __brkdiv0();
    result = _rt_udiv64(v6, v5);
  }
  return result;
}
