// sub_521B88 
 
void __fastcall sub_521B88(unsigned int a1)
{
  if ( HIBYTE(a1) != 192 && HIBYTE(a1) != 128 )
    JUMPOUT(0x45607E);
  JUMPOUT(0x456060);
}
