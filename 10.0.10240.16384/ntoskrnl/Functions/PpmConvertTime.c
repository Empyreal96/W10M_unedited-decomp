// PpmConvertTime 
 
int __fastcall PpmConvertTime(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // r9
  unsigned int v4; // r10
  int v5; // r8
  unsigned __int64 v7; // [sp+8h] [bp-28h]

  v3 = HIDWORD(a2);
  v4 = a2;
  v5 = a1;
  if ( !a1 || !a2 || a2 == a3 )
    return v5;
  if ( RtlULongLongMult(a1, HIDWORD(a1)) >= 0 )
  {
    if ( !v4 && !v3 )
      __brkdiv0();
    return _rt_udiv64(__SPAIR64__(v3, v4), v7);
  }
  return sub_50BB84(v4, v3);
}
