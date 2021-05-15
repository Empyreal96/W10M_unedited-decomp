// VfUtilAddressRangeRemoveCheckEmpty 
 
_DWORD *__fastcall VfUtilAddressRangeRemoveCheckEmpty(_DWORD *result, int a2)
{
  if ( a2 != *result || a2 + 112 != result[1] )
    return VfUtilAddressRangeRemove(result, a2, 112);
  *result = 0;
  result[1] = 0;
  return result;
}
