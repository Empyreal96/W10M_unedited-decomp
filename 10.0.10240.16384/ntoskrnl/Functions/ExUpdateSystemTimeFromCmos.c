// ExUpdateSystemTimeFromCmos 
 
_DWORD *__fastcall ExUpdateSystemTimeFromCmos(int a1, int a2)
{
  unsigned __int64 v2; // kr00_8
  _DWORD *result; // r0
  __int64 v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r3
  __int64 v7; // [sp+Ch] [bp-40h] BYREF
  __int64 v8; // [sp+14h] [bp-38h] BYREF
  __int64 v9; // [sp+1Ch] [bp-30h] BYREF
  __int16 v10[20]; // [sp+24h] [bp-28h] BYREF

  if ( !a2 )
    a2 = ExpMaxTimeSeperationBeforeCorrect;
  v2 = (unsigned int)a2 * (unsigned __int64)(unsigned int)dword_989680;
  result = (_DWORD *)HalQueryRealTimeClock(v10);
  if ( result )
  {
    result = (_DWORD *)RtlTimeFieldsToTime(v10, &v8);
    if ( result )
    {
      if ( ExpRealTimeIsUniversal )
      {
        v4 = v8;
      }
      else
      {
        ExLocalTimeToSystemTime(&v8, &v9);
        v4 = v9;
      }
      result = KeQuerySystemTime(&v7);
      if ( v4 <= v7 )
      {
        v5 = (unsigned __int64)(v7 - v4) >> 32;
        v6 = v7 - v4;
      }
      else
      {
        v5 = (unsigned __int64)(v4 - v7) >> 32;
        v6 = v4 - v7;
      }
      if ( __PAIR64__(v5, v6) > v2 )
        result = (_DWORD *)sub_694738(result);
    }
  }
  return result;
}
