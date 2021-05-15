// RtlSparseBitmapCtxPrepareBits 
 
int __fastcall RtlSparseBitmapCtxPrepareBits(int a1, __int64 a2)
{
  unsigned int v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // r6
  unsigned __int64 v6; // r2
  int v8; // r5
  int v9; // r0
  int v10; // r4
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = HIDWORD(a2);
  v3 = *(_DWORD *)(a1 + 32);
  v4 = HIDWORD(a2);
  v5 = a2;
  v6 = a2 + v3;
  if ( !v3 )
    __brkdiv0();
  v8 = _rt_udiv64(v3, v6);
  v9 = _rt_udiv64(v3, __PAIR64__(v4, v5));
  v10 = RtlpSparseBitmapCtxPrepareRanges(a1, v12, v9, v8);
  if ( v10 >= 0 )
    v10 = 0;
  RtlpSparseBitmapCtxUnlockShared(a1, a1, v12[0]);
  return v10;
}
