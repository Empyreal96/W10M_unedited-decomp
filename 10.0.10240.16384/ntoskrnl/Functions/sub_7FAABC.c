// sub_7FAABC 
 
void sub_7FAABC()
{
  memset(&STACK[0x110], 0, 20);
  LOBYTE(STACK[0x110]) = 1;
  JUMPOUT(0x72D3DA);
}
