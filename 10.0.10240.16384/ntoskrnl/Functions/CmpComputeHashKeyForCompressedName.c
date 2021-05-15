// CmpComputeHashKeyForCompressedName 
 
unsigned int __fastcall CmpComputeHashKeyForCompressedName(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int i; // r5
  unsigned int v7; // r0

  for ( i = 0; i < a3; a1 = 37 * a1 + v7 )
  {
    v7 = *(unsigned __int8 *)(i + a2);
    if ( v7 >= 0x61 )
    {
      if ( v7 > 0x7A )
        v7 = RtlUpcaseUnicodeChar(v7);
      else
        v7 -= 32;
    }
    ++i;
  }
  return a1;
}
