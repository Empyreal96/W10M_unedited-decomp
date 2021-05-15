// sub_525ABC 
 
void sub_525ABC()
{
  unsigned int v0; // r4
  unsigned int v1; // r7

  __dmb(0xAu);
  __yield();
  if ( v0 >= v1 )
  {
    if ( v0 <= v1 )
      JUMPOUT(0x45FCCA);
    JUMPOUT(0x45FD38);
  }
  JUMPOUT(0x45FCCE);
}
