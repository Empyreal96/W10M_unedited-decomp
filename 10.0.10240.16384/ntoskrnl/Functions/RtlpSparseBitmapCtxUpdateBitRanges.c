// RtlpSparseBitmapCtxUpdateBitRanges 
 
int __fastcall RtlpSparseBitmapCtxUpdateBitRanges(unsigned int *a1, unsigned __int64 a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v9; // r4
  unsigned int v10; // r6
  unsigned int v11; // r8
  int v12; // r7
  int v13; // r0
  int v14; // r4
  __int64 v15; // r0
  int v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r6
  int v19; // r8
  unsigned int v20; // r7
  unsigned int v21; // r3
  int v23; // [sp+0h] [bp-38h]
  int v24[3]; // [sp+10h] [bp-28h] BYREF
  int v25; // [sp+1Ch] [bp-1Ch]

  v9 = a1[8];
  v10 = HIDWORD(a2);
  v11 = a2;
  if ( !v9 )
    __brkdiv0();
  v12 = _rt_udiv64(v9, a2);
  v13 = _rt_udiv64(v9, __PAIR64__(v10, v9) + v11);
  v14 = RtlpSparseBitmapCtxPrepareRanges((int)a1, v24, v12, v13, v23, a7 != 0);
  if ( v14 >= 0 )
  {
    v15 = a1[8];
    if ( !(_DWORD)v15 )
      __brkdiv0();
    _rt_udiv64((unsigned int)v15, __PAIR64__(v10, v11));
    v17 = 1;
    v18 = 0;
    v19 = 4 * v12;
    do
    {
      v20 = a1[8] - v16;
      if ( v18 || v17 >= v20 )
      {
        v25 = 0;
      }
      else
      {
        v20 = v17;
        v25 = 0;
      }
      v21 = a1[1];
      if ( v21 && *(_DWORD *)(v19 + v21) )
        RtlpSparseBitmapCtxUpdateBits(a1);
      v16 = 0;
      v18 = (__PAIR64__(v18, v17) - v20) >> 32;
      v17 -= v20;
      v19 += 4;
    }
    while ( __PAIR64__(v18, v17) );
    v14 = 0;
  }
  RtlpSparseBitmapCtxUnlockShared((int)a1, a1, v24[0]);
  return v14;
}
