// RtlMergeBitMaps 
 
unsigned int *__fastcall RtlMergeBitMaps(unsigned int *result, unsigned int *a2)
{
  unsigned int *v2; // r7
  unsigned int v3; // r4
  unsigned int v4; // r5

  v2 = result;
  v3 = *result;
  if ( *result >= *a2 )
    v3 = *a2;
  if ( v3 )
  {
    v4 = 0;
    do
    {
      if ( v3 < 0x20 )
      {
        result = (unsigned int *)v2[1];
        result[v4 / 4] |= ((1 << v3) - 1) & *(_DWORD *)(v4 + a2[1]);
        v3 = 0;
      }
      else
      {
        v3 -= 32;
        *(_DWORD *)(v2[1] + v4) |= *(_DWORD *)(v4 + a2[1]);
        v4 += 4;
      }
    }
    while ( v3 );
  }
  return result;
}
