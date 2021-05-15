// MiComputeDriverProtection 
 
int __fastcall MiComputeDriverProtection(int a1, int a2)
{
  int result; // r0

  result = 0;
  if ( (a2 & 0x20000000) != 0 )
    result = 2;
  if ( (a2 & 0x40000000) != 0 )
    result |= 1u;
  if ( a2 < 0 )
  {
    if ( a1 == 1 )
      return sub_80EB4C(result);
    if ( (result & 2) != 0 )
      return 6;
    result = 4;
  }
  if ( !result )
    result = 24;
  return result;
}
