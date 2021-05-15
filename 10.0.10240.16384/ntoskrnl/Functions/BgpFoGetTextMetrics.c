// BgpFoGetTextMetrics 
 
int __fastcall BgpFoGetTextMetrics(int a1, int a2)
{
  if ( !a1 || !a2 )
    return -1073741811;
  BgpRasGetGlyphTextCellDimensions();
  return 0;
}
