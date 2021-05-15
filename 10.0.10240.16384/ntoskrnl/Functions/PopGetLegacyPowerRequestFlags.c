// PopGetLegacyPowerRequestFlags 
 
int __fastcall PopGetLegacyPowerRequestFlags(_DWORD *a1, int a2, unsigned int *a3)
{
  int result; // r0
  unsigned int v5; // r4

  result = 0;
  v5 = 0x80000000;
  if ( a1 )
  {
    if ( a1[6] )
      v5 = -2147483646;
    if ( a1[7] )
      v5 |= 1u;
    if ( a1[8] )
      v5 |= 0x40u;
    result = (v5 ^ a2) & 0x7FFFFFFF;
  }
  if ( a3 )
    *a3 = v5;
  return result;
}
