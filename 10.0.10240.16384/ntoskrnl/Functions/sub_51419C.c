// sub_51419C 
 
void sub_51419C()
{
  _DWORD *v0; // r5

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x430A34);
}
