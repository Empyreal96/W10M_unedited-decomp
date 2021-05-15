// HvpShrinkMap 
 
int __fastcall HvpShrinkMap(int result, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // r5
  __int64 v6; // kr00_8
  unsigned int v7; // r2
  unsigned int v8; // r3

  v5 = result;
  if ( !a4 )
  {
    v6 = *(_QWORD *)(result + 412 * a2 + 956);
    result = *(_DWORD *)(result + 412 * a2 + 960);
    if ( result == (_DWORD)v6 )
      return (*(int (**)(void))(v5 + 16))();
  }
  v7 = ((a4 >> 12) + 511) >> 9;
  v8 = ((a3 >> 12) + 511) >> 9;
  if ( v7 < v8 )
    result = HvpFreeMap(v5, *(_DWORD *)(v5 + 412 * a2 + 956), v7, v8 - 1);
  return result;
}
