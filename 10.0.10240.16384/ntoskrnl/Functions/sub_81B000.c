// sub_81B000 
 
void sub_81B000()
{
  int v0; // r6

  if ( (PsEmbeddedNTMask & v0) != 0 )
    JUMPOUT(0x7B96AC);
  JUMPOUT(0x7B9692);
}
