// sub_5238D0 
 
void sub_5238D0()
{
  _DWORD *v0; // r5

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x45AAF8);
}
