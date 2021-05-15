// KdpSanitizeContextFlags 
 
_DWORD *__fastcall KdpSanitizeContextFlags(_DWORD *result, int a2, int *a3)
{
  *a3 = *result & 0x20000F;
  return result;
}
