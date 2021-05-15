// sub_563FE8 
 
unsigned int __fastcall sub_563FE8(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int i; // r4

  for ( i = 0; i < a2; ++i )
  {
    if ( !MiIsAddressValid(i + a1, 0, a3, a4) )
      break;
  }
  return i;
}
