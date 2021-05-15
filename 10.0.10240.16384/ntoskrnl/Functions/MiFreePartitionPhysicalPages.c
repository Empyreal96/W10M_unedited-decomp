// MiFreePartitionPhysicalPages 
 
_DWORD *__fastcall MiFreePartitionPhysicalPages(_DWORD *a1)
{
  _DWORD *result; // r0
  _DWORD *i; // r1
  int v4; // r4
  unsigned int v5; // r2

  do
    result = (_DWORD *)MiReturnPartitionPagesToParent(a1);
  while ( a1[898] );
  for ( i = (_DWORD *)a1[7]; i; i = (_DWORD *)*i )
  {
    result = i + 7;
    v4 = 0;
    if ( i + 7 > &i[(i[5] >> 12) + 7] )
      v5 = 0;
    else
      v5 = (unsigned int)(4 * (i[5] >> 12) + 3) >> 2;
    if ( v5 )
    {
      do
      {
        if ( (*result & 0x40000000) != 0 )
          *result &= 0xBFFFFFFF;
        ++v4;
        ++result;
      }
      while ( v4 != v5 );
    }
  }
  return result;
}
