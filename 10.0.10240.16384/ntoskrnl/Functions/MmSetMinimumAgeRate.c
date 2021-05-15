// MmSetMinimumAgeRate 
 
unsigned int __fastcall MmSetMinimumAgeRate(unsigned int a1)
{
  unsigned int result; // r0
  unsigned int v2; // r0

  if ( !a1 )
    return sub_80F3A0();
  v2 = a1 / 6;
  if ( v2 <= 1 )
    v2 = 1;
  result = 0x3E8 / v2;
  if ( result <= 1 )
    result = 1;
  *(_WORD *)(dword_6404B8 + 1220) = result;
  return result;
}
