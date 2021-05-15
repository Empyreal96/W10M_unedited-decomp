// VfUtilAddressRangeAdd 
 
unsigned int *__fastcall VfUtilAddressRangeAdd(unsigned int *result, unsigned int a2, int a3)
{
  unsigned int v3; // r2

  if ( *result )
  {
    if ( a2 < *result )
      *result = a2;
    v3 = a3 + a2;
    if ( v3 > result[1] )
      result[1] = v3;
  }
  else
  {
    *result = a2;
    result[1] = a2 + a3;
  }
  return result;
}
