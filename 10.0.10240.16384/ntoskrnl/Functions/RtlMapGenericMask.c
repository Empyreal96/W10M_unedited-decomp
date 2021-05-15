// RtlMapGenericMask 
 
int *__fastcall RtlMapGenericMask(int *result, _DWORD *a2)
{
  if ( *result < 0 )
    *result |= *a2;
  if ( (*result & 0x40000000) != 0 )
    *result |= a2[1];
  if ( (*result & 0x20000000) != 0 )
    *result |= a2[2];
  if ( (*result & 0x10000000) != 0 )
    *result |= a2[3];
  *result &= 0xFFFFFFFu;
  return result;
}
