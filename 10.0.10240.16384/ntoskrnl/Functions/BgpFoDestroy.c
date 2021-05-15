// BgpFoDestroy 
 
int __fastcall BgpFoDestroy(int result)
{
  void **i; // r4

  if ( FontLibraryInitialized )
  {
    for ( i = (void **)FopFontFileListHead; i != &FopFontFileListHead; i = (void **)*i )
    {
      if ( !result || i[2] == (void *)result )
        return sub_8DFAD0();
    }
  }
  return result;
}
