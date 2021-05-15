// BvgaSolidColorFill 
 
int __fastcall BvgaSolidColorFill(int result)
{
  int v1; // r2
  int v2[8]; // [sp+8h] [bp-20h] BYREF

  if ( !BvgaDisplayState )
  {
    BvgaAcquireLock(result);
    if ( BvgaBootDriverInstalled )
      VidSolidColorFill_0();
    BvgaTerminalBkgdColor = 40;
    v1 = HeadlessGlobals;
    v2[0] = BvgaTerminalTextColor;
    v2[1] = 40;
    if ( HeadlessGlobals )
    {
      if ( *(_DWORD *)(HeadlessGlobals + 4) )
      {
        HdlspDispatch(9, v2, 8, 0);
        v1 = HeadlessGlobals;
      }
      if ( v1 )
      {
        if ( *(_DWORD *)(v1 + 4) )
          HdlspDispatch(4, 0, 0, 0);
      }
    }
    result = BvgaReleaseLock();
  }
  return result;
}
