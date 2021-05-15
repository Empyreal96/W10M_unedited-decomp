// AnFwpProgressIndicatorTimer 
 
int __fastcall AnFwpProgressIndicatorTimer(unsigned int a1)
{
  int v1; // r2
  __int64 v2; // r0
  unsigned int v3; // r10
  unsigned int v4; // r4
  __int64 v5; // kr08_8
  __int64 v6; // r0
  __int64 v7; // r0
  __int64 v8; // r2
  __int64 v9; // r2
  __int16 v10; // r3
  unsigned int v12; // [sp+10h] [bp-38h]
  __int64 v13; // [sp+18h] [bp-30h] BYREF
  __int64 v14[5]; // [sp+20h] [bp-28h] BYREF

  BgpFwAcquireLock(a1);
  if ( byte_64A580 )
  {
    BgpFwQueryPerformanceCounter(v14, (int)&v13, v1, (unsigned __int8)byte_64A580);
    LODWORD(v2) = _rt_sdiv64(33i64, v13);
    v3 = HIDWORD(v2);
    v12 = v2;
    v4 = (unsigned __int16)word_618D0C;
    v5 = v14[0];
    if ( (unsigned __int16)word_618D0C != 57547 )
    {
      LODWORD(v6) = _rt_sdiv64(100i64, 10 * v2);
      if ( !v12 && !v3 )
        __brkdiv0();
      LODWORD(v7) = _rt_sdiv64(__SPAIR64__(v3, v12), v6 - v5 + qword_653560);
      if ( v7 >= 2 )
      {
        v4 = (unsigned __int16)(v4 + 1);
        word_618D0C = v4;
      }
    }
    if ( v4 >= 0xE052 )
    {
      if ( v4 > 0xE0CB )
        goto LABEL_13;
      HIDWORD(v8) = &v13;
      LODWORD(v8) = 0;
      LogFwStat(v14, 1, v8);
      BgpTxtDisplayCharacter((__int64 *)dword_619094, (unsigned __int16)word_618D0C, 0, 0, 0, 0, 0);
      HIDWORD(v9) = &v13;
      LODWORD(v9) = 0;
      LogFwStat(v14, 0, v9);
      v4 = (unsigned __int16)word_618D0C;
    }
    if ( v4 == 57547 )
    {
      v10 = -8118;
LABEL_14:
      qword_653560 = v5;
      word_618D0C = v10;
      return BgpFwReleaseLock();
    }
LABEL_13:
    v10 = v4 + 1;
    goto LABEL_14;
  }
  return BgpFwReleaseLock();
}
