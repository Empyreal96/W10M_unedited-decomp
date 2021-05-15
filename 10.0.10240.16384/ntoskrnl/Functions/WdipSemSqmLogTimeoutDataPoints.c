// WdipSemSqmLogTimeoutDataPoints 
 
int __fastcall WdipSemSqmLogTimeoutDataPoints(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v7 = a3;
  v8 = a4;
  v6 = 0;
  if ( !a1 )
    return -1073741811;
  result = WdipSemGetGuidKey(a1, &v6);
  if ( result >= 0 )
  {
    v7 = a2;
    result = WdipSemSqmAddToStream(1054, 2u, (int)&v6, v6);
  }
  return result;
}
