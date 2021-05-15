// sub_7EF1E4 
 
void sub_7EF1E4()
{
  unsigned int v0; // r5
  unsigned int v1; // r7
  unsigned int v2; // r8

  if ( v0 >= v2 )
  {
    if ( v0 <= v1 )
    {
      if ( !ultow_s() )
        JUMPOUT(0x781B96);
      JUMPOUT(0x781C16);
    }
    JUMPOUT(0x781C0E);
  }
  JUMPOUT(0x781B80);
}
