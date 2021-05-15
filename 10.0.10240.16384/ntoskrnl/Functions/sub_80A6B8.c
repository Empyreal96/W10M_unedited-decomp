// sub_80A6B8 
 
void sub_80A6B8()
{
  char v0; // zf
  unsigned int v1; // r6

  if ( !v0 )
    __fastfail(0xEu);
  __dmb(0xBu);
  SepLogTokenSidManagement(5, v1);
  ExFreePoolWithTag(v1);
  JUMPOUT(0x7600B2);
}
