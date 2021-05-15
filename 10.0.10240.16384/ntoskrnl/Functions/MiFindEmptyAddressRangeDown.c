// MiFindEmptyAddressRangeDown 
 
int __fastcall MiFindEmptyAddressRangeDown(int a1, int a2, int a3)
{
  int result; // r0

  result = MiFindEmptyAddressRangeDownTree(a1, a2, a3, MEMORY[0xC0402130]);
  if ( result < 0 )
    result = sub_7E69B0();
  return result;
}
