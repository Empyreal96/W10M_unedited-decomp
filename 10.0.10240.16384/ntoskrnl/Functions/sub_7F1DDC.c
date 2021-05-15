// sub_7F1DDC 
 
void sub_7F1DDC()
{
  if ( (PopSimulate & 0x1000000) != 0 )
    JUMPOUT(0x78DD4A);
  JUMPOUT(0x78DD64);
}
