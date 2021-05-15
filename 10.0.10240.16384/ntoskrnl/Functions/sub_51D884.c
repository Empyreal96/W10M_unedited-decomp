// sub_51D884 
 
void __fastcall sub_51D884(int a1)
{
  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 1) & 8) == 0 )
      JUMPOUT(0x44B054);
  }
  JUMPOUT(0x44B04E);
}
