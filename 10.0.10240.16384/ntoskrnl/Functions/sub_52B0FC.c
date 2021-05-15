// sub_52B0FC 
 
void sub_52B0FC()
{
  _DWORD *v0; // r7

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x46C660);
}
