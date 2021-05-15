// ViHalApplySettings 
 
void ViHalApplySettings()
{
  if ( (MmVerifierData & 0x80) != 0 )
  {
    if ( !ViHalEnabledInThePast )
    {
      ViVerifyDma = 1;
      if ( (unsigned int)HalPrivateDispatchTable >= 0x20 )
      {
        VfRealHalAllocateMapRegisters = (int (*)(void))off_6179A0;
        off_6179A0 = VfHalAllocateMapRegisters;
      }
      ViDoubleBufferDma = 1;
      ViHalEnabledInThePast = 1;
    }
    ViDMADisabledNoRebootNeeded = 0;
  }
  else
  {
    ViDMADisabledNoRebootNeeded = 1;
  }
}
