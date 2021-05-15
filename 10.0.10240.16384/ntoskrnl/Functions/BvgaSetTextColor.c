// BvgaSetTextColor 
 
int BvgaSetTextColor()
{
  int v1[4]; // [sp+8h] [bp-10h] BYREF

  BvgaTerminalTextColor = 37;
  v1[0] = 37;
  v1[1] = BvgaTerminalBkgdColor;
  if ( HeadlessGlobals && *(_DWORD *)(HeadlessGlobals + 4) )
    HdlspDispatch(9, v1, 8, 0);
  return VidSetTextColor_0();
}
