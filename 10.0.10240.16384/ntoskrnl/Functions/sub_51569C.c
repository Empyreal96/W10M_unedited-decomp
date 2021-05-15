// sub_51569C 
 
void sub_51569C()
{
  _DWORD *v0; // r9

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x433AF4);
}
