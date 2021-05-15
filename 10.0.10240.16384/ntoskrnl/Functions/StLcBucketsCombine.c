// StLcBucketsCombine 
 
_DWORD *__fastcall StLcBucketsCombine(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r4
  int v3; // r2

  v2 = result + 16;
  while ( result < v2 )
  {
    v3 = result[1];
    *result = *a2;
    result[1] = a2[1] + v3;
    result += 2;
    a2 += 2;
  }
  return result;
}
