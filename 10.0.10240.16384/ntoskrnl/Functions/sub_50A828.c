// sub_50A828 
 
void sub_50A828()
{
  _DWORD *v0; // r8

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x445624);
}
