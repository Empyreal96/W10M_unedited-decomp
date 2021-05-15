// sub_903A50 
 
void sub_903A50()
{
  if ( (KiBugCheckActive & 3) != 0 )
    JUMPOUT(0x90234C);
  JUMPOUT(0x90232E);
}
