// MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER 
 
_WORD *__fastcall MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(_WORD *result, unsigned int a2)
{
  *result += a2;
  if ( a2 <= 1 && (unsigned int)(result + 534769440) <= 0x5FF )
    result = (_WORD *)MiIsAddressValid((((int)(result + 534769440) >> 1) - 0x40000) << 12, 0);
  return result;
}
