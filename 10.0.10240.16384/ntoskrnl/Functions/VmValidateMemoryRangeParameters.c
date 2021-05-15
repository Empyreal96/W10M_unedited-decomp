// VmValidateMemoryRangeParameters 
 
int __fastcall VmValidateMemoryRangeParameters(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v7; // r1

  if ( a5 == -1 )
    return 10;
  if ( !a4 )
    return 20;
  if ( a4 > 0xFFFFF )
    return 30;
  if ( (a1 & 0xFFF) != 0 || (a3 & 0xFFF) != 0 )
    return 40;
  v7 = a3 + (a4 << 12);
  if ( v7 <= a3 )
    return 50;
  if ( __PAIR64__(a2, a1) + (a4 << 12) <= __PAIR64__(a2, a1) )
    return 60;
  if ( v7 - 1 <= MmHighestUserAddress )
    return 0;
  return 70;
}
