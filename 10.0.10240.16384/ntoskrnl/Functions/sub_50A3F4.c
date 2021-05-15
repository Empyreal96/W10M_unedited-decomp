// sub_50A3F4 
 
void __fastcall sub_50A3F4(int a1, int a2, int a3)
{
  unsigned int v3; // r5

  if ( MmIsSpecialPoolAddress(v3, a2, a3) )
    JUMPOUT(0x439500);
  JUMPOUT(0x4393E2);
}
