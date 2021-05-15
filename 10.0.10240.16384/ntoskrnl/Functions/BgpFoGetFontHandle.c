// BgpFoGetFontHandle 
 
int __fastcall BgpFoGetFontHandle(unsigned __int16 *a1, void ***a2)
{
  int v3; // r6
  void **i; // r5
  void **j; // r4

  v3 = -1073741275;
  if ( !a2 || !FontLibraryInitialized )
    return -1073741811;
  *a2 = 0;
  for ( i = (void **)FopFontFileListHead; i != &FopFontFileListHead; i = (void **)*i )
  {
    for ( j = (void **)i[6]; j != i + 6; j = (void **)*j )
    {
      if ( a1 )
      {
        if ( !wcsicmp((int)j[4], a1) )
        {
LABEL_11:
          *a2 = j;
          v3 = 0;
          break;
        }
      }
      else if ( ((unsigned int)i[4] & 1) != 0 )
      {
        goto LABEL_11;
      }
    }
    if ( v3 >= 0 )
      break;
  }
  return v3;
}
