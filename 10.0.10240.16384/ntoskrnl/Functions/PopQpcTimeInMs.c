// PopQpcTimeInMs 
 
int __fastcall PopQpcTimeInMs(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  int result; // r0
  unsigned __int64 v5; // r4
  __int64 v6; // r0
  unsigned __int64 v7; // r2
  __int64 v8; // [sp+8h] [bp-10h] BYREF

  v8 = a3;
  result = 0;
  if ( *a2 )
  {
    v5 = *a2 - *a1;
    if ( RtlULongLongMult(v5, HIDWORD(v5), 0x3E8u, 0, &v8) >= 0 )
    {
      v7 = v8;
      v6 = PopQpcFrequency;
      if ( !PopQpcFrequency )
        __brkdiv0();
    }
    else
    {
      LODWORD(v6) = _rt_udiv64(1000i64, PopQpcFrequency);
      v7 = v5;
      if ( !v6 )
        __brkdiv0();
    }
    result = _rt_udiv64(v6, v7);
  }
  return result;
}
