// sub_515774 
 
void sub_515774()
{
  _DWORD *v0; // r6

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x433CCA);
}
