// BvgaBitBlt 
 
int __fastcall BvgaBitBlt(int result)
{
  int v1; // r0

  if ( BvgaBootDriverInstalled )
  {
    if ( !BvgaDisplayState )
    {
      BvgaAcquireLock(result);
      v1 = VidBitBlt_0();
      result = BvgaReleaseLock(v1);
    }
  }
  return result;
}
