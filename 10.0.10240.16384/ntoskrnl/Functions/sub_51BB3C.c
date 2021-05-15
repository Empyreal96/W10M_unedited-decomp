// sub_51BB3C 
 
void sub_51BB3C()
{
  _DWORD *v0; // r8

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x4444F4);
}
