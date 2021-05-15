// sub_54EA2C 
 
void sub_54EA2C()
{
  _DWORD *v0; // r9

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x4E76B6);
}
