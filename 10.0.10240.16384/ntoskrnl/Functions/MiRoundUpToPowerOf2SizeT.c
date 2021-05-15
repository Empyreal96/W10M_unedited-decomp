// MiRoundUpToPowerOf2SizeT 
 
unsigned int __fastcall MiRoundUpToPowerOf2SizeT(unsigned int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2

  v1 = __clz(result);
  v2 = result;
  if ( 1 != (unsigned __int8)(v1 >> 5) )
    result = 1 << (31 - v1);
  if ( result != v2 )
    result *= 2;
  return result;
}
