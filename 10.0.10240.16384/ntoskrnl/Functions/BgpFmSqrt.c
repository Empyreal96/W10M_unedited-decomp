// BgpFmSqrt 
 
int __fastcall BgpFmSqrt(__int64 a1)
{
  unsigned int v1; // r6
  unsigned int v2; // r4
  __int64 v3; // r0
  __int64 v4; // r2
  unsigned int v5; // r4
  unsigned int v6; // r5
  __int64 v7; // r2
  __int64 v8; // r0
  char v9; // cf
  __int64 v10; // r2
  __int64 v11; // r0
  __int64 v12; // r0
  __int64 v13; // r2
  __int64 v14; // r0
  __int64 v15; // r0
  __int64 v16; // r2
  __int64 v17; // r0
  __int64 v18; // r0
  __int64 v19; // r2
  __int64 v20; // r0
  __int64 v21; // r0
  __int64 v22; // r2
  __int64 v23; // r0
  __int64 v24; // r0
  __int64 v25; // r2
  __int64 v26; // r0

  v1 = a1;
  if ( a1 <= 0 )
    return 0;
  LODWORD(a1) = 0;
  v2 = 0;
  HIDWORD(v3) = __CFADD__(v1, 1) + HIDWORD(a1);
  HIDWORD(v4) = (HIDWORD(v3) << 31) | ((v1 + 1) >> 1);
  LODWORD(v4) = SHIDWORD(v3) >> 1;
  if ( SHIDWORD(v3) >> 1 >= 0 && (SHIDWORD(v3) >> 1 > 0 || HIDWORD(v4)) )
  {
    do
    {
      LODWORD(v4) = (__PAIR64__(v4, HIDWORD(v4)) - __PAIR64__(v2, v3)) >> 32;
      HIDWORD(v4) -= v3;
      v2 = (__PAIR64__(v2, v3) + 1) >> 32;
      LODWORD(v3) = v3 + 1;
    }
    while ( __SPAIR64__(v4, HIDWORD(v4)) > __SPAIR64__(v2, v3) );
  }
  v5 = WORD1(v3) | (v2 << 16);
  v6 = (_DWORD)v3 << 16;
  if ( !(((_DWORD)v3 << 16) | v5) )
    return 0;
  LODWORD(v4) = (v6 * (unsigned __int64)v6) >> 32;
  __SET_PAIR__(HIDWORD(v7), HIDWORD(v7), __PAIR64__(v1, 2 * v6 * v5) + v4);
  HIDWORD(v3) = (v6 >> 31) | (2 * v5);
  if ( !((_DWORD)v3 << 17) && !HIDWORD(v3) )
    __brkdiv0();
  LODWORD(v3) = (_DWORD)v3 << 17;
  LODWORD(v7) = v6 * v6;
  LODWORD(v8) = _rt_sdiv64(v3, v7);
  LODWORD(v10) = v8 * v8;
  HIDWORD(v10) = v1 + v9 + 2 * v8 * HIDWORD(v8) + (((unsigned int)v8 * (unsigned __int64)(unsigned int)v8) >> 32);
  v11 = 2 * v8;
  if ( !v11 )
    __brkdiv0();
  LODWORD(v12) = _rt_sdiv64(v11, v10);
  LODWORD(v13) = v12 * v12;
  HIDWORD(v13) = v1 + v9 + 2 * v12 * HIDWORD(v12) + (((unsigned int)v12 * (unsigned __int64)(unsigned int)v12) >> 32);
  v14 = 2 * v12;
  if ( !v14 )
    __brkdiv0();
  LODWORD(v15) = _rt_sdiv64(v14, v13);
  LODWORD(v16) = v15 * v15;
  HIDWORD(v16) = v1 + v9 + 2 * v15 * HIDWORD(v15) + (((unsigned int)v15 * (unsigned __int64)(unsigned int)v15) >> 32);
  v17 = 2 * v15;
  if ( !v17 )
    __brkdiv0();
  LODWORD(v18) = _rt_sdiv64(v17, v16);
  LODWORD(v19) = v18 * v18;
  HIDWORD(v19) = v1 + v9 + 2 * v18 * HIDWORD(v18) + (((unsigned int)v18 * (unsigned __int64)(unsigned int)v18) >> 32);
  v20 = 2 * v18;
  if ( !v20 )
    __brkdiv0();
  LODWORD(v21) = _rt_sdiv64(v20, v19);
  LODWORD(v22) = v21 * v21;
  HIDWORD(v22) = v1 + v9 + 2 * v21 * HIDWORD(v21) + (((unsigned int)v21 * (unsigned __int64)(unsigned int)v21) >> 32);
  v23 = 2 * v21;
  if ( !v23 )
    __brkdiv0();
  LODWORD(v24) = _rt_sdiv64(v23, v22);
  LODWORD(v25) = v24 * v24;
  HIDWORD(v25) = v1 + v9 + 2 * v24 * HIDWORD(v24) + (((unsigned int)v24 * (unsigned __int64)(unsigned int)v24) >> 32);
  v26 = 2 * v24;
  if ( !v26 )
    __brkdiv0();
  return _rt_sdiv64(v26, v25);
}
