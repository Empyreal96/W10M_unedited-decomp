// sub_80BFEC 
 
void sub_80BFEC()
{
  _DWORD *v0; // r7
  _DWORD *v1; // r8

  if ( !*v0 )
  {
    *v1 = 0;
    JUMPOUT(0x791F30);
  }
  JUMPOUT(0x791F00);
}
