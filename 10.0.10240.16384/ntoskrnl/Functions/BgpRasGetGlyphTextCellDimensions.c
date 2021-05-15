// BgpRasGetGlyphTextCellDimensions 
 
int __fastcall BgpRasGetGlyphTextCellDimensions(int a1, _DWORD *a2, int *a3)
{
  __int64 v3; // kr10_8
  __int64 v6; // r0
  int v7; // r5
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r2
  __int64 v13; // r2
  __int64 v14; // r0
  int v15; // r0
  int result; // r0

  v3 = *(_QWORD *)(a1 + 8);
  v6 = 72i64 * *(unsigned __int16 *)(v3 + 88);
  if ( !v6 )
    __brkdiv0();
  v7 = _rt_sdiv64(v6, (*(__int16 *)(v3 + 60) * (unsigned __int64)*(unsigned int *)(v3 + 76) * HIDWORD(v3)) << 6);
  v8 = *(__int16 *)(v3 + 62) - *(__int16 *)(v3 + 64);
  v9 = *(_DWORD *)(v3 + 76);
  v10 = v8 * v9;
  v11 = (v8 * (unsigned __int64)v9) >> 32;
  v12 = v8 * v9 * HIDWORD(v3);
  HIDWORD(v13) = (v12 >> 26) | ((__PAIR64__(v11, v10) * HIDWORD(v3)) >> 32 << 6);
  LODWORD(v13) = v12 << 6;
  v14 = 72i64 * *(unsigned __int16 *)(v3 + 88);
  if ( !v14 )
    __brkdiv0();
  v15 = _rt_sdiv64(v14, v13);
  *a2 = BgpFmRoundUp(v15) + 2;
  result = BgpFmRoundDefault(v7);
  *a3 = result;
  return result;
}
