// BvgaIndicateProgress 
 
int BvgaIndicateProgress()
{
  unsigned int v0; // r1
  int result; // r0

  ++BvgaProgressIndicator;
  v0 = 100 * BvgaProgressIndicator;
  if ( !dword_982120 )
    __brkdiv0();
  result = v0 / dword_982120;
  if ( v0 / dword_982120 > 0x63 )
    result = 99;
  if ( result != dword_982124 )
  {
    dword_982124 = result;
    result = BvgaUpdateProgressBar(result);
  }
  return result;
}
