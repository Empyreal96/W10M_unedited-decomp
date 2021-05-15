// sub_529354 
 
void sub_529354()
{
  _DWORD *v0; // r6

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x465480);
}
