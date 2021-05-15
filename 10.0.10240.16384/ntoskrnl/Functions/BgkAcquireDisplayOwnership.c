// BgkAcquireDisplayOwnership 
 
void BgkAcquireDisplayOwnership()
{
  int v0; // [sp+0h] [bp-30h] BYREF
  char v1[40]; // [sp+8h] [bp-28h] BYREF

  if ( byte_63761D )
  {
    BgLibraryEnable(0, 1);
  }
  else if ( dword_637610 )
  {
    v0 = 0;
    if ( dword_637610(1, v1, &v0) >= 0 )
    {
      if ( BgLibraryEnable(v1, 1) >= 0 )
        byte_63761D = 1;
      dword_637614 = 0;
    }
  }
}
