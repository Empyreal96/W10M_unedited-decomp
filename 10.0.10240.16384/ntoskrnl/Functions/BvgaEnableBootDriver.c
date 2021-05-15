// BvgaEnableBootDriver 
 
int __fastcall BvgaEnableBootDriver(int result)
{
  int v1; // r5
  unsigned int v2; // r0

  v1 = result;
  if ( BvgaBootDriverFullyInitialized )
  {
    if ( BvgaDisplayState < 2 )
    {
      v2 = BvgaAcquireLock(result);
      if ( !BvgaDisplayState )
        v2 = VidCleanUp_0();
      BvgaDisplayState = v1 == 0;
      result = BvgaReleaseLock(v2);
    }
  }
  else
  {
    BvgaDisplayState = result == 0;
  }
  return result;
}
