// RtlpVerGetConditionMask 
 
int __fastcall RtlpVerGetConditionMask(unsigned __int64 a1, unsigned int a2)
{
  char v2; // r3

  v2 = 0;
  do
  {
    a2 >>= 1;
    ++v2;
  }
  while ( a2 );
  return (a1 >> (3 * (v2 - 1))) & 7;
}
