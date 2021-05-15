// sub_814648 
 
void sub_814648()
{
  if ( ZwOpenThreadTokenEx() < 0 )
    JUMPOUT(0x7A7878);
  JUMPOUT(0x7A7824);
}
