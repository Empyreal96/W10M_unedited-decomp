// RtlUnicodeToMultiByteSize 
 
int __fastcall RtlUnicodeToMultiByteSize(unsigned int *a1, unsigned __int16 *a2, unsigned int a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r2
  int v5; // t1

  v3 = 0;
  v4 = a3 >> 1;
  if ( NlsMbCodePageTag )
  {
    while ( v4 )
    {
      v5 = *a2++;
      --v4;
      if ( HIBYTE(*(unsigned __int16 *)(NlsUnicodeToMbAnsiData + 2 * v5)) )
        v3 += 2;
      else
        ++v3;
    }
    *a1 = v3;
  }
  else
  {
    *a1 = v4;
  }
  return 0;
}
