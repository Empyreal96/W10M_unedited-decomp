// BvgaAcquireDisplayOwnership 
 
int BvgaAcquireDisplayOwnership()
{
  int result; // r0

  if ( BvgaResetDisplayParameters && BvgaDisplayState == 2 )
    result = BvgaResetDisplayParameters(80, 50);
  BvgaDisplayState = 0;
  return result;
}
