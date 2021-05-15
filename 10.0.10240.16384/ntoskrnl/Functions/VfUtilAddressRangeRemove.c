// VfUtilAddressRangeRemove 
 
_DWORD *__fastcall VfUtilAddressRangeRemove(_DWORD *result, int a2, int a3)
{
  int v3; // r4

  if ( a2 == *result )
    *result += a3;
  v3 = result[1];
  if ( a2 + a3 == v3 )
    result[1] = v3 - a3;
  return result;
}
