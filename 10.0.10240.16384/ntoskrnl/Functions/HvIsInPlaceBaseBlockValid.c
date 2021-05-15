// HvIsInPlaceBaseBlockValid 
 
BOOL __fastcall HvIsInPlaceBaseBlockValid(int *a1)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  BOOL result; // r0

  result = 0;
  if ( *a1 == 1718052210 && !a1[7] && (unsigned int)a1[5] <= 1 )
  {
    v1 = a1[6];
    if ( v1 <= 5 && v1 >= 3 && a1[8] == 1 )
    {
      v2 = a1[10];
      if ( v2 )
      {
        if ( (v2 & 0xFFF) == 0 && v2 <= 0x7FFFE000 && HvpHeaderCheckSum(a1) == a1[127] )
          result = 1;
      }
    }
  }
  return result;
}
