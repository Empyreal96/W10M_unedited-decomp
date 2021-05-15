// FinalizeBootLogo 
 
int FinalizeBootLogo()
{
  InbvAcquireLock();
  if ( !InbvGetDisplayState() )
    VidSolidColorFill_0();
  PltRotBarStatus = 3;
  return InbvReleaseLock();
}
