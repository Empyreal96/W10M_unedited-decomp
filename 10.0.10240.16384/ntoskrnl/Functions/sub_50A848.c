// sub_50A848 
 
void sub_50A848()
{
  _DWORD *v0; // r10

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x445710);
}
