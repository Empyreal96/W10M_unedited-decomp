// GetBootSystemTime 
 
int __fastcall GetBootSystemTime(int a1, __int64 *a2)
{
  unsigned int v2; // r9
  int v3; // r10
  int v4; // r3
  __int64 *v5; // r6
  int result; // r0
  __int64 v8; // kr08_8
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r4
  __int64 v12; // r0
  unsigned __int64 v13; // r2
  int v14; // r3
  __int64 v15; // r4
  unsigned int v16; // r4
  __int64 v17; // r0
  unsigned int v18; // r6
  unsigned int v19; // r5
  __int64 v20; // r0
  __int64 *v21; // r0
  __int64 v22; // [sp+8h] [bp-58h] BYREF
  unsigned int v23; // [sp+10h] [bp-50h]
  int v24; // [sp+14h] [bp-4Ch]
  __int64 v25; // [sp+18h] [bp-48h] BYREF
  unsigned int v26; // [sp+20h] [bp-40h]
  unsigned __int64 v27; // [sp+28h] [bp-38h] BYREF
  __int16 v28[24]; // [sp+30h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 2144);
  v3 = *(_DWORD *)(a1 + 2148);
  v4 = *(_DWORD *)(a1 + 2168);
  v5 = a2;
  v23 = v2;
  v24 = v3;
  LODWORD(v22) = a2;
  if ( (v4 & 1) == 0 )
    return sub_96F79C();
  v8 = off_617AA0(&v25) - *(_QWORD *)(a1 + 2152);
  v23 = HIDWORD(v8);
  v26 = v8;
  v9 = RtlULongLongMult(v8, HIDWORD(v8), (unsigned int)dword_989680, 0, &v27);
  v10 = v25;
  v11 = v9;
  if ( !v25 )
    __brkdiv0();
  LODWORD(v12) = _rt_udiv64(v25, v27);
  if ( v11 < 0 )
  {
    v16 = HIDWORD(v25);
    if ( !__PAIR64__(v10, HIDWORD(v25)) )
      __brkdiv0();
    LODWORD(v17) = _rt_udiv64(__SPAIR64__(HIDWORD(v25), v10), __PAIR64__(v23, v26));
    v18 = HIDWORD(v17);
    v19 = v17;
    if ( !v25 )
      __brkdiv0();
    LODWORD(v20) = _rt_udiv64(v25, (__PAIR64__(v23, v26) - v17 * __PAIR64__(v16, v25)) * (unsigned int)dword_989680);
    v13 = __PAIR64__(v18, v19) * (unsigned int)dword_989680;
    v5 = (__int64 *)v22;
    v12 = v20 + v13;
  }
  v14 = *(_DWORD *)(a1 + 2168);
  v15 = __PAIR64__(v3, v2) + v12;
  v22 = __PAIR64__(v3, v2) + v12;
  if ( (v14 & 2) != 0 )
  {
    result = HalQueryRealTimeClock(v28);
    if ( result )
    {
      result = RtlTimeFieldsToTime(v28, &v22);
      if ( result )
      {
        if ( !ExpRealTimeIsUniversal )
          result = ExLocalTimeToSystemTime(&v22, &v22);
      }
      v15 = v22;
    }
  }
  else
  {
    HIDWORD(v13) = ExpRealTimeIsUniversal;
    if ( ExpRealTimeIsUniversal )
    {
      v21 = &v22;
    }
    else
    {
      ExSystemTimeToLocalTime(&v22, (int *)&v27);
      v21 = (__int64 *)&v27;
    }
    RtlTimeToTimeFields((int)v21, v28, v13, SHIDWORD(v13));
    result = HalSetRealTimeClock(v28);
  }
  *v5 = v15;
  return result;
}
