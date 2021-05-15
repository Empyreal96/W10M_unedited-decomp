// BvgaUpdateProgressBar 
 
int __fastcall BvgaUpdateProgressBar(int result)
{
  int v1; // r7
  int v2; // r4

  if ( ShowProgressBar )
  {
    if ( BvgaBootDriverInstalled )
    {
      if ( !BvgaDisplayState )
      {
        v1 = 18 * (BvgaProgressState + dword_631C08 * result) / 10000;
        if ( v1 > 0 )
        {
          v2 = 0;
          do
          {
            BvgaAcquireLock(result);
            VidSolidColorFill_0();
            result = BvgaReleaseLock();
            v2 += 9;
            --v1;
          }
          while ( v1 );
        }
      }
    }
  }
  return result;
}
