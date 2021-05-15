// CmpComputeHashKey 
 
unsigned int __fastcall CmpComputeHashKey(unsigned int result, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r4
  unsigned int v3; // r6
  unsigned int v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // t1

  v2 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v3 = result;
  if ( *a2 )
  {
    v4 = (((unsigned int)*a2 - 1) >> 1) + 1;
    do
    {
      v6 = *v2++;
      v5 = v6;
      if ( v6 >= 0x61 )
      {
        if ( v5 > 0x7A )
          v5 = RtlUpcaseUnicodeChar(v5);
        else
          v5 -= 32;
      }
      v3 = 37 * v3 + v5;
      --v4;
    }
    while ( v4 );
    result = v3;
  }
  return result;
}
