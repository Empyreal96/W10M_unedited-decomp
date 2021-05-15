// sub_5299B4 
 
void sub_5299B4()
{
  if ( PopDeepSleepPhaseEngaged() )
  {
    if ( !PopPendingSetPowerDeviceIrps )
      JUMPOUT(0x46740A);
  }
  JUMPOUT(0x467408);
}
