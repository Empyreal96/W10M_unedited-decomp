// sub_50EE14 
 
void sub_50EE14()
{
  _DWORD *v0; // r5

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x4D6ECA);
}
