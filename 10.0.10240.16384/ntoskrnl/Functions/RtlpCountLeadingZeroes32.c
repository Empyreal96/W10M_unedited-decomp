// RtlpCountLeadingZeroes32 
 
int __fastcall RtlpCountLeadingZeroes32(unsigned int a1)
{
  unsigned int v1; // r3
  int result; // r0

  v1 = __clz(a1);
  if ( 1 == (unsigned __int8)(v1 >> 5) )
    result = 32;
  else
    result = (unsigned __int8)v1;
  return result;
}
