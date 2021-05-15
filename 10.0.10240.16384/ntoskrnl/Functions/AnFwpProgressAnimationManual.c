// AnFwpProgressAnimationManual 
 
int __fastcall AnFwpProgressAnimationManual(int a1, int a2, int a3, int a4)
{
  __int64 v4; // r0
  unsigned int v5; // r8
  unsigned int v6; // r9
  unsigned int v7; // lr
  __int64 v8; // r0
  unsigned int v9; // r10
  int v10; // r2
  unsigned int v11; // r4
  __int64 v12; // r0
  int v13; // r3
  unsigned int v14; // r6
  __int64 v16; // [sp+18h] [bp-38h] BYREF
  __int64 v17; // [sp+20h] [bp-30h] BYREF
  __int64 v18[5]; // [sp+28h] [bp-28h] BYREF

  BgpFwQueryPerformanceCounter(&v17, (int)v18, a3, a4);
  LODWORD(v4) = _rt_sdiv64(33i64, v18[0]);
  v5 = HIDWORD(v4);
  v6 = v4;
  LODWORD(v8) = _rt_sdiv64(100i64, 10 * v4);
  v7 = HIDWORD(v8);
  HIDWORD(v8) = HIDWORD(v17);
  v9 = v17;
  v10 = (qword_653560 + __PAIR64__(v5, v6)) >> 32;
  LODWORD(v16) = HIDWORD(qword_653560);
  if ( (__int64)(__PAIR64__(v7, v17) + v8) < (__int64)(qword_653560 + __PAIR64__(v5, v6)) )
    return v8;
  v11 = (unsigned __int16)word_618D0C;
  if ( (unsigned __int16)word_618D0C != 57547 )
  {
    if ( !v6 && !v5 )
      __brkdiv0();
    LODWORD(v12) = _rt_sdiv64(__SPAIR64__(v5, v6), __PAIR64__(v16, qword_653560) - v17 - __PAIR64__(v7, v8));
    if ( v12 >= 2 )
    {
      v11 = (unsigned __int16)(v11 + 1);
      word_618D0C = v11;
    }
  }
  if ( v11 >= 0xE052 )
  {
    if ( v11 > 0xE0CB )
      goto LABEL_13;
    LogFwStat(&v16, 1, 1i64);
    BgpTxtDisplayCharacter((__int64 *)dword_619094, (unsigned __int16)word_618D0C, 0, 0, 0, 0, 0);
    LogFwStat(&v16, 0, 1i64);
    v11 = (unsigned __int16)word_618D0C;
  }
  if ( v11 == 57547 )
  {
    v13 = 57418;
    goto LABEL_14;
  }
LABEL_13:
  v13 = v11 + 1;
LABEL_14:
  v14 = HIDWORD(v17);
  LODWORD(qword_653560) = v9;
  HIDWORD(qword_653560) = HIDWORD(v17);
  word_618D0C = v13;
  LODWORD(v8) = BgpFwQueryPerformanceCounter(&v17, 0, v10, v13);
  LODWORD(v16) = v6;
  if ( (__int64)(v17 - __PAIR64__(v14, v9)) > __SPAIR64__(v5, v6) / 2 )
  {
    LODWORD(v8) = BgpFwQueryPerformanceCounter(&v17, 0, SHIDWORD(v17), (v17 - __PAIR64__(v14, v9)) >> 32);
    qword_653560 = v17 - __SPAIR64__(v5, v6) / 2;
  }
  return v8;
}
