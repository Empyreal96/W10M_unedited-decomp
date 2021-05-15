// BvgaResetDisplay 
 
int BvgaResetDisplay()
{
  if ( !BvgaBootDriverInstalled || BvgaDisplayState )
    return 0;
  VidResetDisplay_0();
  return 1;
}
