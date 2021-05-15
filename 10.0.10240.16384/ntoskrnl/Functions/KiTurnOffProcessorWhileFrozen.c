// KiTurnOffProcessorWhileFrozen 
 
int KiTurnOffProcessorWhileFrozen()
{
  int result; // r0

  if ( KiPowerOffFrozenProcessors )
  {
    if ( KiProcessorFreezeSupported )
      result = sub_51B3A4();
  }
  return result;
}
