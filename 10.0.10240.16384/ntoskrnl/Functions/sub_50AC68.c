// sub_50AC68 
 
void sub_50AC68()
{
  _DWORD *v0; // r5

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x4564B2);
}
