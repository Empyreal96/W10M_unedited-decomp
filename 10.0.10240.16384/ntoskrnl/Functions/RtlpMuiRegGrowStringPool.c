// RtlpMuiRegGrowStringPool 
 
unsigned __int16 *__fastcall RtlpMuiRegGrowStringPool(unsigned __int16 *result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r5
  int v7; // r1
  int v8; // r2

  v4 = a3;
  if ( result )
  {
    if ( a3 < 0 )
      v4 = 16;
    v5 = result[3] + 1;
    v6 = result[2];
    v7 = v4 + result[5];
    v8 = result[4];
    if ( v5 < v6 )
      v5 = result[2];
    if ( v7 < v8 )
      v7 = result[4];
    if ( a4 || v5 != v6 || v7 != v8 )
      result = (unsigned __int16 *)RtlpMuiRegResizeStringPool(result, (__int16)v5, (__int16)v7);
  }
  return result;
}
