// RtlpSparseBitmapCtxAppendNextRangeToRun 
 
int __fastcall RtlpSparseBitmapCtxAppendNextRangeToRun(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r0
  int result; // r0
  _DWORD v9[2]; // [sp+18h] [bp-18h] BYREF
  int v10; // [sp+20h] [bp-10h]
  int v11; // [sp+24h] [bp-Ch]

  v9[0] = 0;
  v9[1] = 0;
  v10 = 0;
  v11 = 0;
  if ( a2 )
  {
    if ( (**(_DWORD **)(a2 + 8) & 1) == 0 )
      return 0;
    v7 = ((int (__fastcall *)(int, int, int, int, _DWORD *, int, _DWORD, int, _DWORD))RtlpSparseBitmapCtxFindRunsFromRange)(
           a1,
           a2,
           a6,
           1,
           v9,
           a3,
           0,
           a2,
           0);
  }
  else
  {
    v7 = RtlpSparseBitmapCtxFindRunsFromNullRange(a1, 0, a6, 1, v9, a3, 0, 0);
  }
  if ( !v7 )
    return 0;
  result = v10;
  *(_DWORD *)(a4 + 8) += v10;
  return result;
}
