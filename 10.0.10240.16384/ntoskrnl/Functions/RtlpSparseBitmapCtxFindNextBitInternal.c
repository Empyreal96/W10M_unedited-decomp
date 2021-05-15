// RtlpSparseBitmapCtxFindNextBitInternal 
 
__int64 __fastcall RtlpSparseBitmapCtxFindNextBitInternal(int a1, int a2, int a3, int a4)
{
  __int64 v5; // r8
  int v8; // r5
  int v9; // r4
  __int64 v11; // [sp+18h] [bp-28h] BYREF
  int v12; // [sp+20h] [bp-20h]
  int v13; // [sp+24h] [bp-1Ch]

  v5 = -1i64;
  v11 = 0i64;
  v12 = 0;
  v13 = 0;
  v8 = RtlpSparseBitmapCtxLockShared(a1, a1);
  v9 = RtlpSparseBitmapCtxFindRunsInternal(a1, &v11, a3, a4);
  RtlpSparseBitmapCtxUnlockShared(a1, a1, v8);
  if ( v9 )
    v5 = v11;
  return v5;
}
